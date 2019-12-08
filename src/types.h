//
// Created by nun on 12/6/19.
//

#pragma once

#include <stdint.h>
#include <SDL_render.h>

typedef struct {
    uint16_t pc;
    uint16_t index;
    uint8_t sp;
    uint16_t gfx[64*32];
    uint16_t delay_timer;
    uint16_t sound_timer;
    uint16_t draw;
    uint8_t key[16];
    uint8_t registers[16];
    uint16_t stack[16];
    uint8_t memory[4096];
    SDL_Renderer *renderer;
} Chip8;

typedef struct {
    void (*func)(Chip8 *);
} Instruction;