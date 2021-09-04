#include<stdio.h>
#include<stdlib.h>
#include <math.h>

//Variables para arreglo de tiempo
#define N 1000
float inicio = 0;
float final = 1000;
float buf;
float t [N]={0};


//Variables para lectura de archivos
FILE *fptr;

//Variables de Fourier
float a0 = 1/4;
double an;
double T = 100;
double f[N]={0};

int main (){

buf = (final-inicio)/N;
t [0] = inicio;

//CICLO PARA GENERAR EL VECTOR DE TAMAÑO N QUE VA DE "inicio" a "final"
for (int i = 1; i < N; i++)
{
    t[i] = t[i-1] + buf;
    
}
fptr = fopen("fourier.txt", "w");

for (int n = 1; n < N ; n++)
{
    an = ((T*(M_PI*n*sin(M_PI*n/2)+2*cos(M_PI*n/2)-2)/(2*(pow(M_PI,2))*(pow(n,2))))   -(T*(M_PI*n*sin(3*M_PI*n/2)-2*cos(3*M_PI*n/2)       +2*cos(2*M_PI*n))/(2*(pow(M_PI,2))*(pow(n,2)))));   
    for (int m = 1; m < N; m++)
    {
        f[m] = f[m]+(2/T)* an *cos(2*M_PI*t[m]*n/T);
    }
}
    for (int k = 0; k < N; k++)
    {
        f[k] = a0 +  f[k];
        fprintf(fptr, "%f\n ",f[k]);
    }
fclose(fptr);
return 0;
}