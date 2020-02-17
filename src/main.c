#include <genesis.h>
#include "../res/resources.h"

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


    // Escreve texto na tela
    //VDP_drawText ("Ola Mundo do Mega Drive no Windows!", 4, 12);

    // Loop do jogo
    while (1)
    {
        // Espera atualizacao da tela
        VDP_waitVSync ();
    }

    return (0);
}
