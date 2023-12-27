#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N_MAX 100           /*Número máximo de sumandos*/

#define FILENAME "DATOS2.DAT"       /* Archivo de datos*/

double a(int l, int m, int n){      /*calcula a(l,m,n)*/
    return (pow(-1.,l+m+n+1)/sqrt(l*l+m*m+n*n));
}

double g(int k) {               /*calcula G_k*/
    int m,n,aux;
    double suma_par;

    if(k == 1){
        suma_par = 3.*a(1,0,0) + 3.*a(1,1,0) + a(1,1,1);
        return suma_par;
    }

    if (k == 2){
        suma_par = 3.*a(1,0,0) + 9.*a(1,1,0) + 7.*a(1,1,1);
        return suma_par;
    }

    if((k/2)*2 == k) {
        aux = k/2;
        suma_par = 3.*a(aux,0,0) + 9.*a(aux,aux,0) + 7.*a(aux,aux,aux);
        for(n = 1; n<aux; n++)
            suma_par += 12.*a(aux,0,n) + 18.*a(aux,aux,n);
        for(n = 1; n<aux; n++)
            for(m = 1;m<aux; m++)
            suma_par += 12.*a(aux,m,n);
    return suma_par;

    } else{
        aux = (k+1)/2;
        suma_par = 3.*a(aux,0,0) + 3.*a(aux,aux,0) + a(aux,aux,aux);
        for(n=1; n<aux; n++)
            suma_par += 12.*a(aux,0,n) + 6.*a(aux,aux,n);
        for (n=1; n<aux; n++)
            for(m=1; m<aux; m++)
                suma_par += 12.*a(aux,m,n);
        return suma_par;
    }
}

void main(void) {
    int k;
    double suma,aux;
    FILE *out;
    out = fopen(FILENAME, "w");
    suma = g(1);
    for(k = 2; k<=N_MAX; k+=2){
        aux = g(k) + g(k+1);
        suma += aux;
        fprintf(out, "%4d   %10.8lf %10.8lf\n" ,k,suma,fabs(aux));
         if (fabs(aux) <0.001)
         {
            printf("%lf\n",fabs(aux));
            break;
         }
         
    }
    fclose(out);
}