#include <stdio.h>

int main() {
	printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numeroSecreto = 42;

    printf("* Qual seu chute?                        *\n");

    int chute;
    scanf("%d", &chute);

    printf("* Seu chute foi: %d                      *\n", chute);

    int acertou = (numeroSecreto == chute);

    if (acertou) {
		printf("* Parabéns!! Você acertou!! =D           *\n");
    } else {
    	int maior = (chute < numeroSecreto);
    	if (maior) {
			printf("* Não foi desta vez. Tente mais uma vez!!*\n");
			printf("* Dica: O número secreto é maior...      *\n");
    	} else {
    		printf("* Não foi desta vez. Tente mais uma vez!!*\n");
			printf("* Dica: O número secreto é menor...      *\n");
    	}
    }
    printf("******************************************\n");
}
