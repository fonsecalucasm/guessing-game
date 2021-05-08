#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage() {
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
}

/*
Get the seconds until now and use it as a seed to rand function.
Then we use return the rest of division for 100 (the number will be between 0 and 99).
*/
int generateSecretNumber() {
    int seconds = time(0);
    srand(seconds);

    return rand() % 100;
}

void printResult(int tentativas, double pontos) {
    printf("******************************************\n");
    printf("* Você acertou em %d tentativas          *\n", tentativas);
    printf("* Você fez %.2f pontos!!                  *\n", pontos);
    printf("* Fim de jogo!                           *\n");
    printf("******************************************\n");
}

int main() {
	
    printWelcomeMessage();

    int numeroSecreto = generateSecretNumber();
    int tentativas = 0;
    int acertou = 0;

    double pontos = 1000;
    double pontosperdidos = 0;

    do {
        tentativas++;

        printf("******************************************\n");
        printf("* Tentativa %d                            *\n", tentativas);
        printf("* Qual seu chute?                        *\n");

        int chute;
        scanf("%d", &chute);
        printf("* Seu chute foi: %d                      *\n", chute);

        if (chute < 0) {
            printf("* Você não pode usar números negativos!   *\n");
            tentativas--;
            continue;
        }

        acertou = (numeroSecreto == chute);
        int maior = (chute < numeroSecreto);

        pontosperdidos = (chute - numeroSecreto) / 2.0;
        if (pontosperdidos < 0) {
            pontosperdidos = abs(pontosperdidos);
        }
        pontos = pontos - pontosperdidos;

        if (acertou) {
            printf("* Parabéns!! Você acertou!! =D           *\n");
            break;
        } else if (maior) {
                printf("* Não foi desta vez. Tente mais uma vez!!*\n");
                printf("* Dica: O número secreto é maior...      *\n");
        } else {
            printf("* Não foi desta vez. Tente mais uma vez!!*\n");
            printf("* Dica: O número secreto é menor...      *\n");
        }

    } while(acertou == 0);
    
    printResult(tentativas, pontos);
}
