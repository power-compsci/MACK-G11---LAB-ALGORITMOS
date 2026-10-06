// EX1
# include <stdio.h>

int buscarMaiorElemento(int a[4][4], int n) {
    int maior = a[0][0];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (a[i][j] > maior) {
                    maior = a[i][j];
            }
        }
    }
    return maior;
}
void leiaMatriz(int a[4][4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite o valor de a[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
        }
    }
}
int main() {
    int a[4][4];
    int maior_elemento;
    leiaMatriz(a, 4);
    maior_elemento = buscarMaiorElemento(a, 4);
    printf("O maior elemento da matriz digitada -> %d", maior_elemento);
    
    return 0;
}

// EX2
# include <stdio.h>
# define TAM 3

void leiaMatriz(int a[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("Digite o valor de a[%d][%d]: ", i, j);
                scanf("%d", &a[i][j]);
        }
    }
}

int contaNumerosPares(int a[TAM][TAM]) {
    int cont = 0;
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                if (a[i][j] % 2 == 0) {
                    cont++;
            }
        }
    }
    return cont;
}

int main() {
    int a[TAM][TAM];
    leiaMatriz(a);
    int contador;
    contador = contaNumerosPares(a);
    printf("A quantidade de numeros pares: %d", contador);
    
    return 0;
}

// EX3
#include <stdio.h>

int main() {
    int matriz[3][3];
    int escalar;

    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nDigite o numero inteiro multiplicador (escalar): ");
    scanf("%d", &escalar);

    printf("\nMatriz Resultante:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = matriz[i][j] * escalar;
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// EX4
#include <stdio.h>

int main() {
    int N = 2;
    int M = 4;

    int A[2][4] = {
        {7, 8, 4, 9},
        {2, 1, 7, 3}
    };

    int B[2][4] = {
        {6, 9, 11, 15},
        {32, 19, 3, 4}
    };

    int C[2][4];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Matriz C (A + B):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
