#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 7

struct compu {
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
};


int main()
{

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
int i,j;
int mt[N][M];

for(i = 0;i<N; i++)
{
    for(j = 0;j<M; j++)
    {
        //mt[i][j]=1+rand()%100;
        *(mt+(i*M+j)) = 1+rand()%100;
        printf("%lf ", mt[i][j]);
    }
printf("\n");
}

return 0;
}