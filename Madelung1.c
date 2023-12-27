#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define N_MAX 5000           /*Número máximo de sumandos*/

#define FILENAME "DATOS1.DAT"       /* Archivo de datos*/

double a(int l, int m, int n){      /*calcula a(l,m,n)*/
    return (pow(-1.,l+m+n+1)/sqrt(l*l+m*m+n*n));
}

double s(int k) {           /*calcula S_k*/
    int m,n;
    double suma_par;
    if(k==1){
        suma_par = 6.*a(1,0,0) + 12.*a(1,1,0) + 8.*a(1,1,1);
        return suma_par;
    }
    suma_par = 6.*a(k,0,0) + 12.*a(k,k,0) + 8.*a(k,k,k);

    for (n = 1 ; n<k; n++)
        suma_par += 24.*(a(k,0,n) + a(k,k,n));
    for(n = 1; n<k ; n++)
        for(m = 1; m<k; m++)
            suma_par += 24.*a(k,m,n);
    return suma_par;
}

void main(void){
    int k;
    double suma,aux;
    FILE * out;
    
   
    out = fopen(FILENAME, "w");
    for(k = 1; k<=N_MAX; k++){
        aux = s(k);
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