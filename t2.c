#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int forma;
    int peso;
} modos;

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

void maximizar (modos * escada, int degraus, int formas){

}

int main(){

    int degraus, formas;
    modos escada[200];

    printf("Insira o número de degraus\n");
    scanf("%d", &degraus);
    printf("Insira a quantidade formas que pode-se subir\n");
    scanf("%d", &formas);

    if(formas > degraus){
        printf("Solução inviável\n");
        return 1;
    }

    fibonacci(degraus, formas);

    printf("Insira o peso de cada forma\n");
    for (int i = 0; i < formas; i++){
        escada[i].forma = i;
        scanf("%d", &escada[i].peso);
    }
    
    //assumo que o maior peso é a melhor escolha
    maximizar(escada, degraus, formas);
    

    return 0;
}
//7 degraus
//1,1,2,3,5,8,13 - 2 formas
//1,1,2,4,7,13,24 - 3 formas
//1,1,2,4,8,15,29 - 4 formas