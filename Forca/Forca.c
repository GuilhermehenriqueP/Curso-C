#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

void abertura();
void chuta();
int jachutou(char letra);
void escolhepalavra();
int enforcou();
int ganhou();
void desenhaforca();

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutedados = 0;

void abertura()
{
    printf(" ****************************** \n");
    printf(" *      Jogo da forca        *  \n");
    printf(" ****************************** \n\n");
}
void chuta()
{
    char chute;
    scanf(" %c", &chute);

    chutes[chutedados] = chute;
    chutedados++;
}
int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutedados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break;
        }
    }
    return achou;
}
void adicionapalavra()
{
    char quer;

    printf("Voce deseja adicionar uma nova palavra ao jogo?? S/N");
    scanf(" %c", &quer);
    if (quer == 'S')
    {
        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual é a nova palavra? ");
        scanf("%s", novapalavra);

        FILE *f;
        f = fopen("palavras.txt", "r+");
        if (f == 0)
        {
            printf("Desculpe, banco de dados não disponivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}
void escolhepalavra()
{
    FILE *f;

    f = fopen("palavras.txt", "r");
    if (f == 0)
    {
        printf("Desculpe, banco de dados não disponivel\n\n");
        exit(1);
    }

    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);

    srand(time(0));
    int randomico = rand() % qtdpalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}
int chuteserrados()
{
    int erros = 0;
    for (int i = 0; i < chutedados; i++)
    {
        int existe = 0;
        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
        }
        if (!existe)
        {
            erros++;
        }
    }

    return erros;
}
int enforcou()
{

    return chuteserrados() >= 4;
}
int ganhou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
    }
    return 1;
}

void desenhaforca()
{

    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '),
           (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '),
           (erros >= 2 ? '|' : ' '), (erros >= 3 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 4 ? '/' : ' '),
           (erros >= 4 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        int achou = jachutou(palavrasecreta[i]);

        if (achou)
        {
            printf("%c ", palavrasecreta[i]);
        }
        else
        {
            printf("_ ");
        }
    }

    printf("\n");
}

int main()
{

    int acertou = 0;

    escolhepalavra();
    abertura();

    do
    {
        desenhaforca();

        chuta();

    } while (!ganhou() && !enforcou());

    if (ganhou())
    {
        printf("Você Ganhou!! Parabeeens\n");
    }
    else
    {
        printf("Voce perdeu e foi enforcado :S \n");
    }
}