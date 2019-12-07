#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL_timer.h>

#include "types.h"
#include "cpu.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"


int main() {
    Chip8 *state = calloc(1, sizeof(Chip8));
    InitChip8(state);

    int size = LoadIntoMemory("/home/nun/Programming/C/Chip8/roms/picture.ch8", state, 0);

    while(1) {
        if (state->draw)
            DrawChip8(state);

        state->draw ^= state->draw;
        RunChip8(state);
    }
}

#pragma clang diagnostic pop