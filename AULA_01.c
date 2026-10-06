// EXERCICIO 1
# include <stdio.h>

int main(){
    double fahrenheit, celsius;
    printf("Digite a temperatura em graus celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = celsius * 9/5 + 32;
    printf("A Temperatura em graus Fahrenheit: %.2lf", fahrenheit);

    return 0;
}

// EXERCICIO 2
# include <stdio.h>

int main(){
    float raio, area;
    printf("Digite o valor do raio: ");
    scanf("%f", &raio);
    area = 4 * 3.141592 * (raio * raio);
    printf("A area da esfera: %f", area);

    return 0;
}

// EXERCICIO 3
# include <stdio.h>

int main(){
    int a, b, c;
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero: ");
    scanf("%d", &c);

    if (a < b && a < c) {
        printf("O primeiro numero %d --> menor numero", a);
    } else if (b < a && b < c) {
        printf("O segundo numero %d --> menor numero", b);
    } else {
        printf("O terceiro numero %d --> menor numero", c);
    
    return 0;
    }
}

// EXERCICIO 4
# include <stdio.h>

int main(){
    int d, e, f;
    printf("Digite o primeiro numero: ");
    scanf("%d", &d);
    printf("Digite o segundo numero: ");
    scanf("%d", &e);
    printf("Digite o terceiro numero: ");
    scanf("%d", &f);

    if (d > e && d > f) {
        printf("Entre os numeros digitados; o numero %d --> maior", d);
    } else if (e > d && e > f) {
        printf("Entre os numeros digitados; o numero %d --> maior", e);
    } else {
        printf("Entre os numeros digitados; o numero %d --> maior", f);
    
    return 0;
    }
}