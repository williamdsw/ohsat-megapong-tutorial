#include <genesis.h>
#include "../res/resources.h"

// CONSTS

// Edges of the play field
const int LEFT_EDGE = 0;
const int RIGHT_EDGE = 320;
const int TOP_EDGE = 0;
const int BOTTOM_EDGE = 224;

// FIELDS

Sprite* ball;
int ballPositionX = 100;
int ballPositionY = 100;
int ballVelocityX = 1;
int ballVelocityY = 1;
int ballWidth = 8;
int ballHeight = 8;

// HELPER FUNCTIONS

void moveBall ()
{
    // Verifica limites horizontais
    if (ballPositionX < LEFT_EDGE)
    {
        ballPositionX = LEFT_EDGE;
        ballVelocityX = - ballVelocityX;
    }
    else if (ballPositionX + ballWidth > RIGHT_EDGE)
    {
        ballPositionX = RIGHT_EDGE - ballWidth;
        ballVelocityX = - ballVelocityX;
    }

    // Verifica limites verticais
    if (ballPositionY < TOP_EDGE)
    {
        ballPositionY = TOP_EDGE;
        ballVelocityY = - ballVelocityY;
    }
    else if (ballPositionY + ballHeight > BOTTOM_EDGE)
    {
        ballPositionY = BOTTOM_EDGE - ballHeight;
        ballVelocityY = - ballVelocityY;
    }

    ballPositionX += ballVelocityX;
    ballPositionY += ballVelocityY;

    // Define nova posicao do sprite baseada nas posicoes x e y
    SPR_setPosition (ball, ballPositionX, ballPositionY);
}


// MAIN

int main ()
{
    // Carrega um tileset baseado na imagem importada
    // 1 = posicao do tile na VRAM
    VDP_loadTileSet (bgtile.tileset, 1, DMA);

    // Extrai paleta de cores do 'bgtile', e adiciona ao 'PAL1'
    VDP_setPalette (PAL1, bgtile.palette -> data);

    // Exibe tileset no PLAN_A na posicao (2,2)
    // TILE_ATTR_FULL (...)
    // - PAL1 = paleta a ser usada pelo tile
    // - prio = permite sobreescrever prioridade de desenhar o tile (PLAN_A, PLAN_2)
    // - flipV = inverte o tile verticalmente
    // - flipX = inverte o tile horizontalmente
    // - index = indice do tile na VRAM
    VDP_setTileMapXY (PLAN_A, TILE_ATTR_FULL (PAL1, 0, FALSE, FALSE, 1), 2, 2);

    // Desenha uma mapa de tiles retangular aonde:
    // x, y = pontos de partida
    // w, h = dimensoes do retangulo
    VDP_fillTileMapRect (PLAN_B, TILE_ATTR_FULL (PAL1, 0, FALSE, FALSE, 1), 0, 0, 40, 30);

    // Inicializa a Sprite Engine com parametros default
    // SPR_init (max_sprites, VRAM_size, unpack_buffer_size)
    SPR_init (0, 0, 0);

    // Adiciona sprite ao objeto
    // spriteDef* = Endereco na memoria do sprite compilado no resources
    // x, y = coordenadas do sprite em pixels
    // TILE_ATRR = atributos do sprite, necessario para setar a paleta
    ball = SPR_addSprite (&ballSprite, 100, 100, TILE_ATTR (PAL1, 0, FALSE, FALSE));


    // Loop do jogo
    while (1)
    {
        // Exibe lista atual de sprites
        SPR_update ();

        moveBall ();

        // Espera atualizacao da tela
        VDP_waitVSync ();
    }

    return (0);
}
