#ifndef _PPI_
#define _PPI_


int compare(char *str1, char *str2);
void getpro1(char *line, char *protein);
void getpro2(char *line, char *pro1,char *pro2,char *weight);
int idtonum(char pro[],int npro);
void floyd(float Floyd[][21], int npro);
void getfloyd(float matrix[][21], int npro);
void dij(int n,int origin,float matrix[300][300]);
void getdij(int n,int origin,float matrix[300][300]);
#endif
