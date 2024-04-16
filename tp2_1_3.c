#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 7

int main()
{
int i,j;
double *punteromt;
double mt[N][M];
punteromt = mt;

for(i = 0;i<N; i++)
{
    for(j = 0;j<M; j++)
    {
        //mt[i][j]=1+rand()%100;
        *(punteromt+i*M+j) = 1+rand()%100;
        //printf("%lf ", mt[i][j]);
        printf("%lf ", *(punteromt+i*M+j));
    }
printf("\n");
}

return 0;
}

