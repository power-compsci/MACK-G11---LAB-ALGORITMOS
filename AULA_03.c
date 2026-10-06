// Exercicio 1
# include <stdio.h>

int potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int main(){
    int ba, ex;
    printf("Digite sua base: ");
    scanf("%d", &ba);
    printf("Digite o seu expoente: ");
    scanf("%d", &ex);
    int result = potencia(ba, ex);
    printf("O numero %d elevado a %d = %d", ba, ex, result);

    return 0;
}

// (Função para verificar núumero primo)
# include <stdio.h>

int ehPrimo(int n){
    int divisor = 0;
    int i;

    if (n <= 1) return 0;

    for (i = 1; i <= n; i++) {
        if (n % i == 0){
            divisor++;
        }
    }
    
    if (divisor == 2) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    int verificacao = ehPrimo(numero);
    
    if (verificacao == 1) {
        printf("O numero %d --> primo", numero);
    } else {
        printf("O numero %d --> nao primo", numero);
    }

    return 0;
}

    
// Numeros primos entre 1 e 10000
# include <stdio.h>

int ehPrimo(int n){
    int divisor = 0;
    int i;

    if (n <= 1) return 0;

    for (i = 1; i <= n; i++) {
        if (n % i == 0){
            divisor++;
        }
    }
    
    if (divisor == 2) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int i;
    
    printf("Numeros primos entre 1 e 10000: ");
    
    for (i = 1; i <= 10000; i++) {
        if (ehPrimo(i) == 1) {
            printf("%d ", i);
        }
    }
    
    printf("\n"); 
    return 0;
}