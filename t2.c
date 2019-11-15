#include <stdio.h>
#include <stdlib.h>

//precisa ver como vai fazer pra por o formas

void fibonacci(int degraus, int formas){
    int * fib = malloc(sizeof(int)*degraus);
    fib[0] = 1;
    fib[1] = 1;
    printf("A sequencia de fibonacci é: %d, %d, ", fib[0], fib[1]);
    for (int i = 2; i < formas; i++){
        for (int j = i-1; j >= 0; j--){
            fib[i] += fib[j];
        }
        printf("%d, ", fib[i]);
    }

    for (int i = formas; i < degraus; i++){
        for (int j = i-1; j >= i-formas; j--){
            fib[i] += fib[j];
        }
        printf("%d, ", fib[i]);
    }
    
    printf("\nPortanto, pode-se subir a escada de %d formas\n", fib[degraus-1]);
    free(fib);
}

int main(){

    int degraus, formas;

    printf("Insira o número de degraus\n");
    scanf("%d", &degraus);
    printf("Insira a quantidade formas que pode-se subir\n");
    scanf("%d", &formas);

    fibonacci(degraus, formas);

    return 0;
}
//7 degraus
//1,1,2,3,5,8,13 - 2 formas
//1,1,2,4,7,13,24 - 3 formas
//1,1,2,4,8,15,29 - 4 formas