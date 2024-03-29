#include <stdio.h>

int main() {
	printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numeroSecreto = 42;

    int tentativaAtual = 1;
    int tentativaMaxima = 3;

    for (tentativaAtual; tentativaAtual <= tentativaMaxima; tentativaAtual++) {
        printf("* Tentativa %d de %d                      *\n", tentativaAtual, tentativaMaxima);
        printf("* Qual seu chute?                        *\n");

        int chute;
        scanf("%d", &chute);
        printf("* Seu chute foi: %d                      *\n", chute);

        if (chute < 0) {
            printf("* Você não pode usar números negativos!   *\n");
            tentativaAtual--;
            continue;
        }

        int acertou = (numeroSecreto == chute);
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
    }

    printf("* Fim de jogo!                           *\n");
    printf("******************************************\n");
}
