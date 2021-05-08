#include <stdio.h>

void printBanner() {
    printf("*********************\n");
    printf("****** TABUADA ******\n");
    printf("*********************\n");
}

void printFooter() {
    printf("*********************\n");
}

void exibeTabuada(int tabuadadesejada) {
    int index;
    for (index = 1; index <= 10; index++) {
        printf("%d X %d = %d\n", tabuadadesejada, index, (tabuadadesejada * index));
    }
}

int main() {
    
    printBanner();

    printf("Qual tabuada voce deseja saber?\n");
    int tabuadadesejada = 0;
    scanf("%d", &tabuadadesejada);
    printf("Exibindo tabuada do %d\n", tabuadadesejada);
    exibeTabuada(tabuadadesejada);

    printFooter();
}
