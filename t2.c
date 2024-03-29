#include <stdio.h>
#include <stdlib.h>

void fibonacci(int degraus, int formas){
    int * fib = malloc(sizeof(int)*degraus);
    fib[0] = 1;
    fib[1] = 1; 

    int temp = fib[0]+fib[1];    
    /*enquanto não atingir o numero de formas, soma todos os anteriores*/
    for (int i = 2; i < formas; i++){
        for (int j = i-1; j >= 0; j--){
            fib[i] = temp;
            temp += fib[i];
            printf("%d, ", fib[i]);
        }
    }

    temp = 1;
    /*fib[i] recebe fib[i-1]+fib[i-2]+...+fib[i-formas], sendo que a variavel temp incrementa de 1,2...,formas.*/
    for (int i = formas; i < degraus; i++){
        while(temp != formas+1){
            fib[i] += fib[i-temp];
            temp++;
        }
        temp = 1;
        printf("%d, ", fib[i]);
    }
    /*o numero total de formas que se pode subir a escada é o ultimo número da sequencia de fibonacci generalizado*/
    printf("\nPortanto, pode-se subir a escada de %d formas\n", fib[degraus-1]);
    free(fib);
}

int max ( int a, int b){
    if(a>b) return a;
    return b;
}

/* O problema de subir as escadas com peso é semelhante ao da mochila
    Os degraus são como o peso maximo da mochila, e quantos degraus se 
    sobe por passo (forma) é o peso de cada item. O valor dos itens é 
    o peso que cada maneira de subir a escada tem. 
*/
int wssp(int degraus, int formas){
    /*vetor de pesos*/
    int escada[formas];
    int aux;
    printf("Insira o peso de cada forma\n");
    for (int i = 0; i < formas; i++){
        scanf("%d", &aux);
        escada[i] = aux;
    }

    int memo[formas+1][degraus+1]; 
    /*inicializa a matriz de memoização com 0's*/
    for (int i = 0; i <= formas; i++){
        for (int j = 0; j <= degraus; j++){
           memo[i][j] = 0; 
        }        
    }
    /*Percorre a matriz, calculando o maior peso para subir cada degraus*/
    for (int i = 1; i <= formas; i++){
        for(int j = 1; j <= degraus; j++){
            if(i > j){ 
                /*se o peso de subir a escada com mais menos passos(mais degraus por passo) for menor,
                assume-se que se irá subir com menos passos, que já foram calculados*/
                memo[i][j] = memo[i-1][j];
            }
            else{
                /*aux armazena quantos degraus faltam subir dado q ja foram subidos i passos,
                para cada conjunto j de degraus*/
                aux=j-i;
                /*escolhe o maior peso dado o custo de subir da forma i*/
                memo[i][j] = max(escada[i-1] + memo[i][aux], memo[i-1][j]);
            }
        }
    }
    /*mostra a matriz de memoização no terminal*/
    printf(" j   ");
    for (int i = 0; i <= degraus; i++)
    {
        printf("%d ", i);
    }
    printf("\n");  

    for (int i = 0; i <= formas; i++){
        printf("i=%d  ", i);
        for (int j = 0; j <= degraus; j++){
           printf("%d ", memo[i][j]);
        }        
        printf("\n");
    }

    return memo[formas][degraus];
}

int main(){

    int degraus, formas;

    printf("Insira o número de degraus\n");
    scanf("%d", &degraus);
    printf("Insira a quantidade maxima de degraus (formas) que pode-se subir\n");
    scanf("%d", &formas);

    /*caso o numero de formas de subir a escada seja maior que o número de degraus, é impossivel resolver o problema*/
    if(formas > degraus){
        printf("Solução inviável\n");
        return 1;
    }

    /*A resolução é como um fibonacci generalizado, mas ao invés de somar o 2 anteriores, soma n anteriores, sendo que n é o numero de formas*/
    fibonacci(degraus, formas);

    //assumo que o maior peso é a melhor escolha
    int a =  wssp(degraus, formas);
    printf("%d\n",a);   

    return 0;
}

//7 degraus
//1,1,2,3,5,8,13 - 2 formas
//1,1,2,4,7,13,24 - 3 formas
//1,1,2,4,8,15,29 - 4 formas
