//
// Created by nun on 12/6/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#include "types.h"
#include "codes.h"
#include "cpu.h"

//#define DEBUG

static Instruction instructions[16] = {
        {op_0xxx},
        {op_1xxx},
        {op_2xxx},
        {op_3xxx},
        {op_4xxx},
        {op_5xxx},
        {op_6xxx},
        {op_7xxx},
        {op_8xxx},
        {op_9xxx},
        {op_axxx},
        {op_bxxx},
        {op_cxxx},
        {op_dxxx},
        {op_exxx},
        {op_fxxx}
};

static unsigned char fontset[80] =
        {
                0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
                0x20, 0x60, 0x20, 0x20, 0x70, // 1
                0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
                0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
                0x90, 0x90, 0xF0, 0x10, 0x10, // 4
                0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
                0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
                0xF0, 0x10, 0x20, 0x40, 0x40, // 7
                0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
                0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
                0xF0, 0x90, 0xF0, 0x90, 0x90, // A
                0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
                0xF0, 0x80, 0x80, 0x80, 0xF0, // C
                0xE0, 0x90, 0x90, 0x90, 0xE0, // D
                0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
                0xF0, 0x80, 0xF0, 0x80, 0x80  // F
        };

static uint8_t scancodes[16] = {
        SDLK_1, SDLK_2, SDLK_3, SDLK_4, // 1 2 3 4
        SDLK_q, SDLK_w, SDLK_e, SDLK_r, // q w e r
        SDLK_a, SDLK_s, SDLK_d, SDLK_f, // a s d f
        SDLK_y, SDLK_x, SDLK_c, SDLK_v  // z x c v
};

SDL_Event event;

void
LoadFontset(Chip8 *state)
{
    for(size_t i = 0; i < 80; i++)
        state->memory[i] = fontset[i];
}

int
LoadIntoMemory(char *file, Chip8 *state, uint16_t pos)
{
    uint8_t *buff = &state->memory[pos + 0x200];

    FILE *f = fopen(file, "rb");
    if (f == NULL)
        exit(1);

    //Get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    fread(buff, fsize, 1, f);
    fclose(f);

    return fsize;
}

void
InitChip8 (Chip8 *state)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(64 * 10, 32 * 10, 0, &window, &renderer);

    SDL_RenderClear(state->renderer);
    SDL_RenderPresent(state->renderer);

    state->pc = 0x200;
    state->index = 0;
    state->sp = 16;
    state->draw = 0;
    state->renderer = renderer;


    LoadFontset(state);
    SDL_RenderPresent(renderer);
}

int
RunChip8 (Chip8 *state)
{
    uint16_t code = (state->memory[state->pc] << 8) | state->memory[state->pc + 1];
    uint16_t nibble = (code & 0xf000) >> 12;

#ifdef DEBUG
    printf("%04x\n", code);
#endif

    instructions[nibble].func(state);
    state->pc += 2;

    if(state->delay_timer > 0)
        state->delay_timer--;
    if(state->sound_timer > 0)
        state->sound_timer--;

    return 0;
}

void
ExitChip8 (Chip8 *state)
{
    free(state->renderer);
    free(state);
    exit(0);
}

void
DrawChip8 (Chip8 *state)
{
    uint16_t *graphics = state->gfx;

#ifdef DEBUG
    printf("\n===================================\n\n");
#endif


    SDL_SetRenderDrawColor(state->renderer, 255, 255, 255, 255);
    SDL_RenderClear(state->renderer);

    for (int i = 0; i < 32 * 10; i += 10) {
        for (int j = 0; j < 64 * 10; j += 10) {
            if (graphics[(i / 10) * 64 + (j / 10)] & 1) SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
            else SDL_SetRenderDrawColor(state->renderer, 255, 255, 255, 255);
            SDL_Rect r = {j, i, 10, 10};
            SDL_RenderFillRect(state->renderer, &r);
#ifdef DEBUG
            printf("%d ", graphics[(i / 10) * 64 + (j / 10)]);
        }
        printf("\n");
#else
        }
#endif
    }
    SDL_RenderPresent(state->renderer);

}

SDL_Keycode
GetKeyChip8(Chip8 *state)
{
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                ExitChip8(state);
                break;
            case SDL_KEYUP:
            case SDL_KEYDOWN:
                for(size_t i = 0; i < 16; i++) {
                    if(event.key.keysym.sym == scancodes[i])  {
                        state->key[i] = (event.type == SDL_KEYDOWN) ? 1 : 0;
                        return event.key.keysym.sym;
                    }
                }
                break;
        }
    }

    return 0;
}