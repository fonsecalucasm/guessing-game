#include <stdio.h>

int main() {
	printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numeroSecreto = 42;
    int tentativas = 0;
    int acertou = 0;

    do {
        tentativas++;

        printf("******************************************\n");
        printf("* Tentativa %d                           *\n", tentativas);
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

    int pontos = 101 - tentativas;
    printf("******************************************\n");
    printf("* Você acertou em %d tentativas          *\n", tentativas);
    printf("* Você fez %d pontos!!                   *\n", pontos);
    printf("* Fim de jogo!                           *\n");
    printf("******************************************\n");
}
