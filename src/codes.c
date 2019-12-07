#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
//
// Created by nun on 12/6/19.
//

#include <stdlib.h>
#include "codes.h"

#define UPPER ((state->memory[state->pc]))
#define LOWER ((state->memory[state->pc + 1]))

#define X (state->registers[(UPPER & 0x0f)])
#define Y (state->registers[(LOWER & 0xf0) >> 4])

#define ADDR ((UPPER & 0x0f) << 8 | LOWER)

void pop_stack (Chip8 *state)
{
    state->pc = state->stack[state->sp] << 8 | state->stack[state->sp + 1];
    state->sp += 1;
}

void push_stack (Chip8 *state)
{
    state->stack[state->sp - 1] = state->pc & 0xff;
    state->stack[state->sp - 2] = state->pc & 0xff00 >> 8;
    state->sp -= 2;
}

void get_key (Chip8 *state, uint8_t reg)
{

}

void op_0xxx (Chip8 *state)
{
    if(LOWER == 0xe0) {
        for(size_t i = 0; i < 64*32; i++)
            state->gfx[i] = 0;
    } else if(LOWER == 0xee) {
        pop_stack(state);
    }
}

void op_1xxx (Chip8 *state)
{
    state->pc = ADDR;
}

void op_2xxx (Chip8 *state)
{
    push_stack(state);
    state->pc = ADDR;
}

void op_3xxx (Chip8 *state)
{
    if(X == LOWER)
        state->pc += 2;
}

void op_4xxx (Chip8 *state)
{
    if(X != LOWER)
        state->pc += 2;
}

void op_5xxx (Chip8 *state)
{
    if(X == Y)
        state->pc += 2;
}

void op_6xxx (Chip8 *state)
{
    X = LOWER;
}

void op_7xxx (Chip8 *state)
{
    X = X + LOWER;
}

void op_8xxx (Chip8 *state)
{
    switch (LOWER & 0x0f) {
        case 0x00:
            X = Y;
            break;
        case 0x01:
            X = X | Y;
            break;
        case 0x02:
            X = X & Y;
            break;
        case 0x03:
            X = X ^ Y;
            break;
        case 0x04: {
            uint16_t result = (uint16_t) X + (uint16_t) Y;
            state->registers[0xf] = (result > 0xff);
            X = result & 0xff;
        }
            break;
        case 0x05:
            state->registers[0xf] = Y > X;
            X = X - Y;
            break;
        case 0x06:
            state->registers[0xf] = X & 1;
            X = X >> 1;
            break;
        case 0x07:
            state->registers[0xf] = X > Y;
            X = Y - X;
            break;
        case 0x0e:
            state->registers[0xf] = X & 0x80;
            X = X << 1;
            break;
    }
}

void op_9xxx (Chip8 *state)
{
    if(X != Y)
        state->pc += 2;
}

void op_axxx (Chip8 *state)
{
    state->index = ADDR;
}

void op_bxxx (Chip8 *state)
{
    state->pc = ADDR + state->registers[0];
}

void op_cxxx (Chip8 *state)
{
    X = LOWER & (rand() % 256);
}

void op_dxxx (Chip8 *state)
{
    int height = LOWER & 0x0f;
    state->registers[0xf] = 0;

    for (size_t yLine = 0; yLine < height; ++yLine) {
        uint8_t pixel = state->memory[state->index + yLine];

        for (size_t xLine = 0; xLine < 8; ++xLine) {
            if((pixel & (0x80 >> xLine))) {
                if(state->gfx[X + xLine + (Y + yLine) * 64] == 1)
                    state->registers[0xf] = 1;
                state->gfx[X + xLine + (Y + yLine) * 64] ^= 1;
            }
        }
    }

    state->draw = 1;
}

void op_exxx (Chip8 *state)
{
    if(LOWER == 0x9E) {
        if (state->key[X])
            state->sp += 2;
    } else if(LOWER == 0xA1) {
        if(!state->key[X])
            state->sp += 2;
    }

}

void op_fxxx (Chip8 *state)
{
    switch(LOWER) {
        case 0x07:
            X = state->delay_timer;
            break;
        case 0x0A:
            get_key(state, UPPER & 0x0f);
            break;
        case 0x15:
            state->delay_timer = X;
            break;
        case 0x18:
            state->sound_timer = X;
            break;
        case 0x1E:
            state->registers[0xf] = (state->index + X) > 0xfff;
            state->index = state->index + X;
            break;
        case 0x29:
            state->index = X * 0x5;
            break;
        case 0x33:
            state->memory[state->index] = X / 100;
            state->memory[state->index + 1] = (X / 10) % 10;
            state->memory[state->index + 2] = (X % 100) % 10;
            break;
        case 0x55:
            for(int i = 0; i < 16; i++) {
                state->memory[state->index + i] = state->registers[i];
            }
            break;
        case 0x65:
            for(int i = 0; i < 16; i++) {
                state->registers[i] = state->memory[state->index + i];
            }
            break;
    }
}

#pragma clang diagnostic pop