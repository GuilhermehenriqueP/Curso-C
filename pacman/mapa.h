#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORINZONTAL '-'
#define FANTASMA 'F'

typedef struct mapa
{
    char ** matriz;
    int linhas;
    int colunas;
}  MAPA;

typedef struct posicao
{
    int x;
    int y;
} POSICAO;



void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);
void encontramapa(MAPA* m, POSICAO*p, char c);
int ehvazia(MAPA *m, int x, int y);
int ehvalida(MAPA *m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino );
void copiamapa(MAPA* destino, MAPA* origem);




