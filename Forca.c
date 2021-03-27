#include <stdio.h>
#include <string.h>
#include "forca.h"

void abertura();
void chuta();
int jachutou(char letra);
void escolhepalavra();
int enforcou();
int ganhou();
void desenhaforca();

char palavrasecreta[20];
char chutes[26];
int chutedados = 0;

void abertura(){
    printf(" ****************************** \n");
    printf(" *      Jogo da forca        *  \n");
    printf(" ****************************** \n\n");
}
void chuta(){
    char chute;
        scanf(" %c", &chute);

        chutes[chutedados] = chute;
        chutedados++;
        
}
int jachutou(char letra){
    int achou = 0;
        for (int j = 0; j < chutedados; j++)
        {                
            if(chutes[j] == letra){    
                    achou = 1;
                    break;
                }
            }
    return achou;
}
void escolhepalavra(){

    sprintf(palavrasecreta, "MELANCIA");
}
int enforcou(){
    int erros = 0;
    for (int i = 0; i < chutedados; i++){
        int existe = 0;
        for(int j = 0; j< strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe){
            erros++; 
        } 
    }
    
    return erros >= 5;
}
int ganhou(){
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
        
    }
    return 1;
    
}

void desenhaforca(){
    for(int i = 0; i < strlen(palavrasecreta); i++){
            int achou = jachutou(palavrasecreta[i]);

            if(achou){
                printf("%c ", palavrasecreta[i]);
            }else{
                printf("_ ");
            }
        }

        
        printf("\n");
}

int main(){
    
    int acertou = 0;

    
    escolhepalavra();
    abertura();
    
    do{
        desenhaforca();

        chuta();
        
    } while( !ganhou() && ! enforcou() );
}