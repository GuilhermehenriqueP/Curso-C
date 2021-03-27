#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //imprime o cabeçalho do jogo
    printf("************************************\n");
    printf("* Bem vindo ao jogo de adivinhacao *\n");
    printf("************************************\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    
    int acertou = 0;
    
    int  ganhou = 0;
    int nivel;

    printf("Qual o nível de dificuldade em que deseja jogar? \n");
    printf(" (1) Facil (2) Medio (3) Dificil \n\n ");

    printf("Escolha:  ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel){
        case 1:
            numerodetentativas = 20;
            break;
        case 2: 
            numerodetentativas = 15;
            break;
        default:
            numerodetentativas = 6;
            break;
    }
    
    for (int i = 0; i < numerodetentativas; i++){
        /* code */
    
    
        printf("Tentativa %d\n", tentativas);
        printf("Qual eh o seu chute?  ");
        scanf("%d", &chute);

        

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos \n");
            continue;
        }


        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou){
            

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

        double pontosperdidos = abs(chute - numerosecreto) /2.0;
        pontos  = pontos - pontosperdidos;
        
    }

    if(acertou){
        printf("\n\nParabeens acertou! *_* \n\n");
        printf("Voce acertou em %d de tentativas\n", tentativas);
        printf("Sua  pontuacao foi  %.2f  \n", pontos);
    }
    else{
        printf("Voce Perdeu \n");
    }
    printf("Fim de Jogo! \n");
    

}   