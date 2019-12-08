//
// Created by nun on 12/6/19.
//

#pragma once

int
RunChip8(Chip8 *);

int
LoadIntoMemory(char *, Chip8 *, uint16_t);

void
InitChip8(Chip8 *);

void
DrawChip8(Chip8 *);

SDL_Keycode
GetKeyChip8(Chip8 *);