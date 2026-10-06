// VETORES
// EX 1
# include <stdio.h>
# include <stdbool.h>

int main() {
    int vetor[5] = {1,5,2,6,9};
    bool b = true;

    for (int i = 0; i < 4; i++) {
        if (vetor[i]  > vetor[i + 1]) {
            b = false;
            break;
        }
    }
        if (!b) {
            printf("Falso\n");
        } else {
            printf("True\n");
        }
}

// EX 2
# include <stdio.h>

int inverter(int v[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++){
        temp = v[i];
        v[i] = v[n - 1 - i];
        v[n - 1 - i] = temp;
    }
}

int main() {
    int v[] = {20, 30, 40, 50, 60};
    int size = sizeof(v) / sizeof(v[0]);

    inverter(v, size);

    for (int i = 0; i < size; i++) {
        printf("%d\t", v[i]);
    }
    return 0;
}

// EX 3
#include <stdio.h>

int somaPares(int v[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            soma += v[i];
        }
    }
    return soma;
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    int somapar = somaPares(v, n);
    printf("A soma dos numeros pares: %d\n", somapar);

    return 0;
}

// EX 5

#include <stdio.h>

void menorMedia(int v[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    float media = (float)soma / n;

    printf("Media calculada: %.2f\n", media);
    printf("Numeros menores que a media: ");

    for (int i = 0; i < n; i++) {
        if (v[i] < media) {
            printf("%d ", v[i]); // Adicionado espaco para nao colar os numeros
        }
    }
    printf("\n"); // Adicionado o ponto e virgula
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int v[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &v[i]);
    }

    // Apenas chama a funcao, pois ela ja trata toda a impressao
    menorMedia(v, tamanho);

    return 0;
}