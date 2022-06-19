# 王苏然 

[toc]







## Floyd 算法介绍

Floyd-Warshall算法是一种在具有正或负边缘权重（但没有负周期）的加权图中找到最短路径的算法。算法的单个执行将找到所有顶点对之间的最短路径的长度（加权）。该算法也称为该算法也称为Floyd算法，Roy-Warshall算法，Roy-Floyd算法或WFI算法，是一个有三个for循环嵌套的动态规划的例子。

核心思路为通过一个图的权值矩阵求出它的每两点间的最短路径矩阵。从图的带权n×n邻接矩阵开始，迭代地进行n次更新，即由矩阵D(0)=A，按一个公式，构造出矩阵D(1)；又用同样地公式由D(1)构造出D(2)；……；最后又用同样的公式由D(n-1)构造出矩阵D(n)。矩阵D(n)的i行j列元素便是i号顶点到j号顶点的最短路径长度，称D(n)为图的距离矩阵，同时还可引入一个后继节点矩阵path来记录两点间的最短路径。采用松弛操作，对在i和j之间的所有其他点进行一次松弛。

<img src="https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fimg.it610.com%2Fimage%2Finfo8%2Fbb9ce030d8814ec0b7cb0f840d4d5f0b.jpg&refer=http%3A%2F%2Fimg.it610.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1658051373&t=47c71d1756502be7f87698999f6338d6" alt="点击查看图片来源" style="zoom:50%;" />



## 优缺点分析

优点：容易理解，代码容易编写；动态规划法，稠密图效果最佳，边权可正可负。

缺点：该方法时间复杂度和空间复杂度都是O(n^3)，数据较大时计算耗时较长不适合。



## 比较Dijkstra与Floyd

1. Dijkstra不能处理负权图，Floyd能处理负权图；

2. Dijkstra处理单源最短路径，Floyd处理多源最短路径；

3. Dijkstra时间复杂度为O（n^2），Flyod时间复杂度为O（n^3） 空间复杂度为O（n ^ 2）

   总结：如果是单源点正权图，就用Dijkstra
   如果是任意两个点之间的最短路径或者是负权图，就用Floyd



## 改进思路

在网上查阅资料总结了现有的改进方法。

1. 利用矩阵对称性进行改进。

   ```c
   int i,j,k,t;
   for(k = 1; k <= N; k++){
       for(i = 1; i <= N; i++){
           t = A[i][k];
           for(j = 1; j <= i; j++){
               A[i][j] = min(A[i][j], t+A[k][j]);
               A[j][i] = A[i][j];
           }
       }
   }
   ```

   

2. 只用矩阵的下三角部分

   ```c
   int i,j,k,t;
   for(k = 1; k <= N; k++){
       for(i = 1; i <= N; i++){
          if(k != i){
               t = (k<i) ? A[i][k] : A[k][i];
               for(j = 1; j <= min(k,i); j++){
                   A[i][j] = min(A[i][j], t+A[k][j]);
               }
               for(j = k+1; j <= i; j++){
                   A[i][j] = min(A[i][j], t+A[j][k]);
               }
           }
       }
   }
   ```

   

3. 跳过不存在的路径

   ```c
       int i,j,k,t;
       for(k = 1; k <= N; k++){
           for(i = 1; i <= N; i++){
               if(k != i){
                   t = (k<i) ? A[i][k] : A[k][i];
                   if(t == Inf)  continue;
                   for(j = 1; j <= min(k,i); j++){
                       A[i][j] = min(A[i][j], t+A[k][j]);
                   }
                   for(j = k+1; j <= i; j++){
                       A[i][j] = min(A[i][j], t+A[j][k]);
                   }
               }
           }
       }
   
   ```

   

4. 避免调用大量函数（min）

   ```c
       int i,j,k,t;
       for(k = 1; k <= N; k++){
           for(i = 1; i <= N; i++){
               if(k != i){
                   t = (k<i) ? A[i][k] : A[k][i];
                   if(t == Inf)  continue;
                   for(j = 1; j <= ((k<i)?k:i); j++){
                       if(t+A[k][j] < A[i][j])  A[i][j] = t + A[k][j];
                   }
                   for(j = k+1; j <= i; j++){
                       if(t+A[j][k] < A[i][j])  A[i][j] = t + A[j][k];
                   }
               }
           }
       }
   ```

   