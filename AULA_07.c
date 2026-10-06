// Bubble Sort
#include <stdio.h>

void bubble_sort(int a[], int n) {
    // Controla quantas vezes vamos repetir o processo (garante a ordenação total)
    for (int i = 0; i < n; i++) {
        // Percorre o array comparando os elementos vizinhos (j e j+1)
        for (int j = 0; j < n - 1; j++) {
            // Se o elemento da esquerda for maior que o da direita, eles trocam de lugar
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main(void) 
{
    int a[] = {1, 3, 7, 9, 0, 2, 4, 5, 8, 6};
    int n = 10;

    bubble_sort(a, n);

    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");
    
    return 0;
}


// Insert Sort
#include <stdio.h>

void insertion_sort(int a[], int n) {
    // i começa em 1 porque o primeiro elemento (índice 0) já é considerado ordenado
    for (int i = 1; i < n; i++) { 
        int key = a[i]; // Guarda o elemento atual que será inserido na posição correta
        int j = i - 1;  // Começa a comparar com o elemento imediatamente anterior

        // Desloca os elementos maiores que a 'key' uma posição para a direita
        while (j >= 0 && a[j] > key) { 
            a[j + 1] = a[j]; 
            j = j - 1;
        }
        // Insere a 'key' na vaga que abriu
        a[j + 1] = key;
    }
}

int main()
{
    int n = 8;
    int a[] = {8, 4, 9, 5, 7, 6, 3, 2};
    
    insertion_sort(a, n); 
    
    for (int i = 0; i < n; i++) {
        printf("a[%d]: %d\n", i, a[i]);
    }
    printf("\n");

    return 0;
}


// Selection Sort
#include <stdio.h>

void selection_sort(int a[], int n) {
    // i define o início da parte não ordenada do array
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // Assume inicialmente que o primeiro elemento é o menor

        // Varre o restante do array para encontrar o menor elemento real
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j; // Guarda o índice do novo menor valor encontrado
            }
        }

        // Troca o menor elemento encontrado com o elemento da posição i
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

int main(void) 
{
    int a[] = {7, 5, 2, 4, 3, 9, 1, 6, 8, 0};
    int n = 10;

    selection_sort(a, n);

    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");
    
    return 0;
}
