//需要在主函数中先得到目标蛋白的数字id 函数名 getdij(npro,id,matrix[][],prodic[][])
#include <stdio.h>
#include <stdlib.h>
#define INF 10000000
#define MaxSize 1000
int dis[MaxSize];             //dis[i]为源点到顶点i的最短距离
int visit[MaxSize];         //visit[i]标记顶点i的最短路径是否已求出visit[i] == 1表示已求出
void dij(int n,int origin,int graph[][])
{    
  int count = 0,i,j;          //count是已求出最短路径的顶点数目
    visit[0] = 1;      
    count++;    
    for (i = 1; i < n; i++)    //初始化
    {        
        dis[i] = graph[origin][i];          
    }    
    while (count < n)    
    {        
        int min = INF, target_index;        
        for (i = 1; i < n; i++)        
        {            
            if (visit[i] == 0 && min > dis[i])     //找到距离源点最短的target_index
            {                
                min = dis[i];                
                target_index = i;            
            }        
        }        
        visit[target_index] = 1;        
        count++;        
        for (i = 1; i < n; i++)        
        {            
            if (visit[i] == 0 && dis[target_index] + 
            graph[target_index][i] < dis[i])            //更新
            {                
                dis[i] = dis[target_index] + graph[target_index][i];          
            }        
        }    
    }
}
void getdij(int n,int origin,int graph[][],char prodic[][])
{    
    int i,j;    
    dij(n,origin,graph[1000][1000]);    
    printf("\n\n");    
    for (i = 1; i < n; i++)    
    {        
        if (dis[i] == INF)        
        {            
	      printf("There is no interaction between protein %s and protein %s \n",
          prodic[origin],prodic[i]);        
        }        
        else                   
    	    printf("Shortest path between protein %s and protein %s is %d                   \n",prodic[origin],prodic[i],dis[i]);            
    	      
    }
}
