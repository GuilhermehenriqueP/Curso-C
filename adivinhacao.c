#include <stdio.h>

int main(){

    //imprime o cabeçalho do jogo
    printf("************************************\n");
    printf("* Bem vindo ao jogo de adivinhacao *\n");
    printf("************************************\n");

    int numerosecreto = 42;

    int chute;
    int tentativas = 1;
    
    int  ganhou = 0;
    while (1){

        printf("Tentativa %d\n", tentativas);
        printf("Qual eh o seu chute?  ");
        scanf("%d", &chute);

        

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos \n");
            continue;
        }


        int acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou){
            printf("\n\nParabeens acertou! *_* \n\n");

            //For, pare de executar o código
            break;
        }
        else if(maior){
            printf("Seu chute foi maior que o numero secreto!\n");
        }
        else{
            printf("seu chute foi menor que o numero secreto! \n");
        }

        tentativas++;
        
    }

    printf("Fim de Jogo! \n");
    printf("Voce acertou em %d de tentativas\n", tentativas);

}   