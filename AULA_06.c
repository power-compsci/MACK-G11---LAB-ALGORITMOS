# include <stdio.h>

int busca_linear(int v[], int n, int e) {
    for (int i = 0; i < n; i++) {
        if (v[i] == e) {
            return i;
        }
    }
    return -1;
}

#include <stdio.h>

int busca_binaria(int v[], int n, int e) {
    int inicio = 0;
    int fim = n - 1;
    int resultado = -1; 

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;  

        if (v[meio] == e) {
            resultado = meio; 
            fim = meio - 1;   
        } 
        else if (v[meio] < e) {
            inicio = meio + 1; 
        } 
        else {
            fim = meio - 1; 
        }
    }

    return resultado; 
}

