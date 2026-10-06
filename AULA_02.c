// EXERCICIO 1
# include <stdio.h>

int main(){
    int frequencia;
    float n1, n2, media;
    printf("Digite a sua porcentagem de frequencia de 0 a 100: ");
    scanf("%d", &frequencia);
    printf("Digite a nota da primeira prova: ");
    scanf("%f", &n1);
    printf("Digite a nota da segunda prova: ");
    scanf("%f", &n2);
    media = (n1 + n2) / 2;

    if (frequencia < 75) {
        printf("REPROVADO");
    } else if (frequencia >= 75 && media >= 6) {
        printf("APROVADO");
    } else if (frequencia >= 75 && media < 6) {
        printf("DE EXAME");
    
    return 0;
    }
}

// EXERCICIO 2
# include <stdio.h>

int main(){
    float a, b , c;
    printf("Digite o primeiro lado (a): ");
    scanf("%f", &a);
    printf("Digite o segundo lado (b): ");
    scanf("%f", &b);
    printf("Digite o terceiro lado (c): ");
    scanf("%f", &c);

    if (a < b + c && b < a + c && c < a + b) {
        printf("O triangulo com os lados %f, %f e %f existe!", a, b, c);
    } else {
        printf("O triangulo com os lados %f, %f e %f nao existe!", a, b, c);
    
    return 0;
    }
}

// EXERCICIOS COM FOR E WHILE

// (Soma de numeros positivos)
#include <stdio.h>

int main(){
    int numero;
    int soma = 0;

    printf("Digite numeros inteiros positivos. Ou um numero negativo para parar o programa:\n");

    while (1) {
        printf("Digite um numero: ");
        scanf("%d", &numero);

        if (numero < 0) {
            break;
        }

        soma += numero;
    }

    printf("A soma dos numeros inteiros positivos digitados: %d\n", soma);

    return 0; 
}

// (Adivinhação)
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numSecreto = (rand() % 100) + 1;
    int numTentativa;

    do {
        printf("Digite sua tentativa (1 a 100): ");
        scanf("%d", &numTentativa);

        if (numTentativa < numSecreto) {
            printf("O numero %d e MENOR que o numero secreto!\n", numTentativa);
        } else if (numTentativa > numSecreto) {
            printf("O numero %d e MAIOR que o numero secreto!\n", numTentativa);
        } else {
            printf("\nParabens! Acertou o numero secreto: %d\n", numSecreto);
        }
    } while (numTentativa != numSecreto);

    return 0;
}

// (Fatorial)
# include <stdio.h>

int main(){
    int m, i;
    unsigned long long fatorial = 1;

    printf("Digite um numero positivo: ");
    scanf("%d", &m);
    
    if (m < 0) {
        printf("Fatorial nao possivel!");
    } else {
        
        for (i = 1; i <= m; i++) {
            fatorial *= i;
        }

        printf("O fatorial de %d: %llu\n", m, fatorial);
    
    return 0;
    }
}

// (Numeros primos)
#include <stdio.h>

int main() {
    int n, i, eh_primo = 1; 
    
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    if (n <= 1) {
        eh_primo = 0;
    } else {
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                eh_primo = 0;
                break;
            }
        }
    }
    
    if (eh_primo) {
        printf("%d e um numero primo.\n", n);
    } else {
        printf("%d nao e um numero primo.\n", n);
    }
    
    return 0;
}

// (Programa de numeros primos)
# include <stdio.h>

int main() {
    int n;                   // Quantos numeros primos serao analisados  
    int contador_primos = 0; // Quantos primos ja encontramos
    int candidato = 2;       // Primeiro numero a ser testado

    printf("Digite a quantidade de numeros primos que deseja ver: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Digite um numero maior que zero: ");
        return 0;
    }

    printf("Os primeiros %d numeros primos sao:\n", n);

    // O while roda ate encontrarmos exatamente 'n' primos
    while (contador_primos < n) {
        int i;
        int eh_primo = 1;

        // Testa se 'candidato' e primo
        for (i = 2; i * i <= candidato; i++) {
            if (candidato % i == 0) {
                eh_primo = 0; // Nao e primo
                break;
            }
        }

        // Se for primo, imprime e incrementa o contador de primos achados
        if (eh_primo) {
            printf("%d ", candidato);
            contador_primos++;
        }

        // Passa para o proximo numero inteiro
        candidato++;
    }

    printf("\n");

    return 0;
}

// (Numeros perfeitos)
#include <stdio.h>

int main() {
    int n, i;
    int soma_divisores = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    // Numeros perfeitos precisam ser inteiros e positivos (> 0)
    if (n <= 0) {
        printf("Por favor, digite um numero maior que zero.\n");
        return 0;
    }

    // Procura todos os divisores de 1 ate (n - 1)
    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            soma_divisores += i; // Adiciona o divisor a soma
        }
    }

    // Verifica se a soma dos divisores e igual ao numero original
    if (soma_divisores == n) {
        printf("%d e um numero perfeito!\n", n);
    } else {
        printf("%d nao e um numero perfeito.\n", n);
    }

    return 0;
}