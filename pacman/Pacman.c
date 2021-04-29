#include <stdlib.h>
#include <stdio.h>
#include "pacman.h"
#include "mapa.h"

//matriz de 5 por 10
MAPA m;
POSICAO heroi;


int acabou()
{
    return 0;
}
int ehdirecao(char direcao){
    return direcao == 'a' || direcao == 'w' || direcao == 's' || direcao == 'd';
}
void move(char direcao)
{
    if(!ehdirecao(direcao)){
        return;
    }
    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao){
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;     
    }
    
    if (!ehvazia(&m, proximox,proximoy))
        return;
    
    
    if (!ehvalida(&m, proximox,proximoy))
        return;

    

    andanomapa(&m, heroi.x, heroi.y, proximox,proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
    
    
}
void fantasmas(){

    MAPA copia;

    copiamapa(&copia, &m);
    for(int i = 0; i < copia.linhas; i++){
        for(int j = 0; j< copia.colunas; j++){
            if(copia.matriz[i][j] == FANTASMA){
                if(ehvalida(&m, i ,j+1) && ehvazia(&m, i, j+1)){
                    andanomapa(&m, i, j , i, j+1);
                }
            }
        }
    }
    liberamapa(&copia);
}


int main(){

    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);
    do
    {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();

    } while (!acabou());

    liberamapa(&m);
}