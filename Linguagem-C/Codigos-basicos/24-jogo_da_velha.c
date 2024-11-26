
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define tt 3*sizeof(char)

char tabuleiro[tt][tt];
char jogador = '\0';
char computador = '\0';

void inicia_tabuleiro (void);
void define_pecas (void);
bool verifica_peca (char *peca);

void mostra_tabuleiro (void);

void insere_peca (bool chave);
bool verifica_posicao (int valor_pos, bool chave);
bool verifica_ganhador (void);

void limpa_buffer (void);

int main (void)
{
  srand(time(NULL));
  inicia_tabuleiro();
  define_pecas();

  if (jogador == 'x') insere_peca(true);
  else insere_peca(false);

  return (0);
}

void inicia_tabuleiro (void)
{
  memset(tabuleiro, '-', sizeof(tabuleiro));
  return;
}

void define_pecas (void)
{
  char peca[2];
  do
  {
    printf (" jogador, escolha entre x ou y\n : ");
    scanf ("%1[xyXY]", &peca);
  }while (verifica_peca(peca) != true);

  return;
}

bool verifica_peca (char *peca)
{
  if (peca[0] == '\0')
  {
    printf (" entre com a peca corretamente\n");
    limpa_buffer();
    return (false);
  }

  if (peca[0] == 'X' || peca[0] == 'x')
  {
    jogador = 'x';
    computador = 'y';
    printf (" Voce escolheu X\n Voce comeca o jogo\n");
  }
  else if (peca[0] == 'Y' || peca[0] == 'y')
  {
    jogador = 'y';
    computador = 'x';
    printf (" Voce escolheu Y\n Voce comeca o jogo\n");
  }
  else
  {
    printf (" entrada invalida\n");
    return (false);
  }

  limpa_buffer();
  return (true);
}

void mostra_tabuleiro (void)
{
  printf (" tabuleiro atual\n");
  printf (" %c|%c|%c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
  printf (" %c|%c|%c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
  printf (" %c|%c|%c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
  return;
}

void insere_peca (bool chave)
{
  char pos[2];
  int valor_pos;
  if (verifica_ganhador() == true) return;

  if (chave == true)
  {
    mostra_tabuleiro();
    do
    {
      printf (" posicoes (escolher numero)\n 1-2-3\n 4-5-6\n 7-8-9\n");
      scanf ("%1[1-9]", &pos);
      valor_pos = atoi(pos);
    }while (verifica_posicao(valor_pos, chave) != true);
    insere_peca(false);
  }
  else
  {
    do
    {
      valor_pos = rand() % 10;
    }while (verifica_posicao(valor_pos, chave) != true);

    insere_peca(true);
  }
}

bool verifica_posicao (int valor_pos, bool chave)
{
  int linha, coluna;
  if (valor_pos > tt * tt || valor_pos <= 0)
  {
    if (chave == true)
    {
      printf (" entre com um valor valido\n");
      limpa_buffer();
    }
    return (false);
  }
  
  linha = (valor_pos - 1) / tt;
  coluna = (valor_pos - 1) % tt;

  if (tabuleiro[linha][coluna] != '-')
  {
    if (chave == true)
    {
      printf (" local ocupado\n");
      limpa_buffer();
    }
    return (false);
  }

  if (chave == true)
  {
    limpa_buffer();
    tabuleiro[linha][coluna] = jogador;
  }
  else 
  {
    tabuleiro[linha][coluna] = computador;
  }

  return (true);
}

bool verifica_ganhador ()
{
  if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2] && tabuleiro[0][0] != '-')
  {
    printf (" %c ganhou!!!!\n", tabuleiro[0][0]);
    return (true);
  }

  if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0] && tabuleiro[0][2] != '-')
  {
    printf (" %c ganou !!!\n", tabuleiro[0][2]);
    return (true);
  }

  int a;
  for (a = 0; a < tt; a++)
  {
    if (tabuleiro[a][0] == tabuleiro[a][1] && tabuleiro[a][0] == tabuleiro[a][2] && tabuleiro[a][a] != '-')
    {
      printf (" %c ganhou!!!\n", tabuleiro[a][0]);
      return (true);
    }

    if (tabuleiro[0][a] == tabuleiro[1][a] && tabuleiro[0][a] == tabuleiro[2][a] && tabuleiro[a][a] != '-')
    {
      printf ("%c ganhou!!!\n", tabuleiro[0][a]);
      return (true);
    }
  }
  
  return (false);
}

void limpa_buffer (void)
{
  char ch;
  while ((ch = getchar()) != '\n' && ch != EOF);
}
