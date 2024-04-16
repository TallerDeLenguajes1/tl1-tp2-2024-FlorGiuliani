/*4) Declara un tipo de dato estructura:
i) Para representar a una PC; los campos serán: velocidad de procesamiento en GHz, año de fabricación, tipo de procesador, cantidad de núcleos.
ii) Considera valores enteros aleatorios para la velocidad: entre 1 y 3, para el año: entre 2015 y 2024, para la cantidad de núcleos: entre 1 y 8.
iii) Para evitar ingresar por teclado los tipos de procesador, considera que estos se encuentran en un arreglo de cadenas de caracteres:
    char tipos[6][10]={“Intel”, “AMD”, “Celeron”, “Athlon”, “Core”, “Pentium”}
La estructura será la siguiente:
    struct compu {
        int velocidad;//entre 1 y 3 GHz
        int anio;//entre 2015 y 2023
        int cantidad;//entre 1 y 8
        char *tipo_cpu; //valores del arreglo tipos
    };
b) Define una variable del tipo arreglo de estructura para guardar las características de 5 PC que cargará el usuario.
c) Escribe una función que presente la lista de las PC, cada una con sus características.
d) Escribe una función que presente la PC más vieja.
e) Escribe una función que presente la PC que tiene mayor velocidad. */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

struct compu {
    int velocidad;//entre 1 y 3 GHz
    int anio;//entre 2015 y 2023
    int cantidad;//entre 1 y 8
    char *tipo_cpu; //valores del arreglo tipos
};

void mostrarCompus (struct compu *compu);
void mostrarDatos (struct compu compu);
void pcVieja (struct compu *compu);
void pcVeloz (struct compu *compu);


int main()
{

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
int respuesta;

struct compu *computadora = (struct compu *)malloc(N * sizeof(struct compu));

srand(time(NULL));
for (int i = 0; i < N; i++)
{
    computadora[i].velocidad = rand() % 3 + 1;
    computadora[i].anio = rand() % (2023-2015+1) + 2015;
    computadora[i].cantidad = rand() % 8 + 1;

    //respuesta = rand() % 6 + 1;
    printf("\nSeleccione el tipo de procesador de la maquina numero %d \n 1:Intel\n 2:AMD\n 3:Celeron\n 4:Athlon\n 5:Core\n 6:Pentium \n", i+1);
    scanf("%d", &respuesta);
    computadora[i].tipo_cpu = tipos[respuesta-1];
}

mostrarCompus (computadora); 
pcVieja (computadora);
pcVeloz (computadora);

return 0;
}



void mostrarCompus (struct compu *compu)
{
    for (int i = 0; i < N; i++)
    {
        printf("\nInformacion de la computadora numero %d:", i+1);
        mostrarDatos (compu[i]);
    }
}

void mostrarDatos (struct compu compu)
{
    printf("\n Tipo de CPU: %s",compu.tipo_cpu);
    printf("\n Velocidad: %d GHz",compu.velocidad);
    printf("\n Año: %d",compu.anio);
    printf("\n Cantidad de nucleos: %d \n",compu.cantidad);
}

void pcVieja (struct compu *compu)
{
    int anioMenor, masVieja;
    anioMenor = compu[0].anio;
    for (int i = 0; i < N; i++)
    {
        if (compu[i].anio < anioMenor)
        {
            anioMenor = compu[i].anio;
            masVieja = i;
        }
    }
    printf("\nInformacion de la computadora mas vieja:");
    mostrarDatos (compu[masVieja]);
}

void pcVeloz (struct compu *compu)
{
    int mayorVelocidad, masVeloz;
    mayorVelocidad = compu[0].velocidad;
    for (int i = 0; i < N; i++)
    {
        if (compu[i].velocidad > mayorVelocidad)
        {
            mayorVelocidad = compu[i].velocidad;
            masVeloz = i;
        }
    }
    printf("\nInformacion de la computadora mas veloz:");
    mostrarDatos (compu[masVeloz]);
}