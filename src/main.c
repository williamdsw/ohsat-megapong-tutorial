#include <genesis.h>
#include "../res/resources.h"

int main ()
{
    // Carrega um tileset baseado na imagem importada
    // 1 = posicao do tile na VRAM
    VDP_loadTileSet (bgtile.tileset, 1, DMA);

    // PLAN_A = foreground, como chao etc.
    // PLAN_B = background, etc.
    // tile = 8x8 pixels
    // logo (1,1) = 8,8
    VDP_setTileMapXY (PLAN_B, 1, 2, 2);

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
