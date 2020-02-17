#include <genesis.h>

int main ()
{
    // Escreve texto na tela
    VDP_drawText ("Ola Mundo do Mega Drive!", 8, 12);

    // Loop do jogo
    while (1)
    {
        // Espera atualizacao da tela
        VDP_waitVSync ();
    }

    return (0);
}
