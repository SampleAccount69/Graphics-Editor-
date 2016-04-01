//#ifndef HEADER_H
//#define HEADER_H

#pragma once
#include <SDL/SDL.h>

SDL_Window* newWindow();

SDL_Renderer* newRenderer(SDL_Window*);

void processInput();

//#endif 