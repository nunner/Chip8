#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SDL_timer.h>
#include <SDL_events.h>

#include "types.h"
#include "cpu.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

int main() {
    Chip8 *state = calloc(1, sizeof(Chip8));
    InitChip8(state);

    int size = LoadIntoMemory("/home/nun/Programming/C/Chip8/roms/logo.ch8", state, 0);
    printf("Loaded %d bytes.", size);

    while(1) {
        GetKeyChip8(state);

        if (state->draw)
            DrawChip8(state);

        state->draw ^= 1;
        RunChip8(state);
        usleep(1000);
    }

    return 0;
}

#pragma clang diagnostic pop