#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage() {
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
}

void printWinnerBanner() {
    printf("                         \n");
    printf("    |@@@@|     |####|    \n");
    printf("    |@@@@|     |####|    \n");
    printf("    |@@@@|     |####|    \n");
    printf("    \\@@@@|     |####/    \n");
    printf("     \\@@@|     |###/    \n");
    printf("      `@@|_____|##'    \n");
    printf("           (O)    \n");
    printf("        .-'''''-.    \n");
    printf("      .'  * * *  `.    \n");
    printf("     :  *       *  :    \n");
    printf("    : ~ A S C I I ~ :    \n");
    printf("    : ~ A W A R D ~ :    \n");
    printf("     :  *       *  :    \n");
    printf("      `.  * * *  .'    \n");
    printf("        `-.....-'    \n");
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
    int acertou = 0;

    double pontos = 1000;
    double pontosperdidos = 0;

    printf("Selecione o nivel de dificuldade\n");
    printf(" (1) Facil | (2) Medio | (3) Dificil\n");
    printf("Escolha: ");
    int dificuldade;
    scanf("%d", &dificuldade);    

    int rounds = 0;
    switch (dificuldade) {
        case 1:
            rounds = 20;
            break;
        case 2:
            rounds = 15;
            break;
        default:
            rounds = 6;
            break;
    }

    int index;
    for (index = 1; index <= rounds; index++) {

        printf("******************************************\n");
        printf("* Tentativa %d                            *\n", index);
        printf("* Qual seu chute?                        *\n");

        int chute;
        scanf("%d", &chute);
        printf("* Seu chute foi: %d                      *\n", chute);

        if (chute < 0) {
            printf("* Você não pode usar números negativos!   *\n");
            index--;
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
            printResult(index, pontos);
            printWinnerBanner();
            break;
        } else if (maior) {
                printf("* Dica: O número secreto é maior...      *\n");
        } else {
            printf("* Dica: O número secreto é menor...      *\n");
        }

    }
    
    if (acertou == 0) {
        printf("Não foi dessa vez!\n");
    }
}
