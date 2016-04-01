
#include "GraphicsEditor-MainWindow.h"

#include <SDL/SDL.h>
//#include "Header.h"

SDL_Window* newWindow() 
{

	SDL_Window* firstWindow = SDL_CreateWindow("test window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
	return firstWindow;
}

SDL_Renderer* newRenderer(SDL_Window* window)
{

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	return renderer;
}

//SDL_Surface* newSurface(SDL_Surface* window)
//{
//
//}
/*
void close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Quit();

	renderer = NULL;
	window = NULL;

	SDL_Surface* pScreenShot = SDL_CreateRGBSurface(0, 500, 500, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);

	if (pScreenShot)
	{
		// Read the pixels from the current render target and save them onto the surface 
		SDL_RenderReadPixels(renderer, NULL, SDL_GetWindowPixelFormat(window), pScreenShot->pixels, pScreenShot->pitch);

		Random random;
		char name[1];
		for (int i = 0; i < 1; i++)
		{
			name[i] = (char)random.Next(1000000, 5000000);
		}

		//Create the bmp screenshot file 
		SDL_SaveBMP(pScreenShot, "ght.bmp");

		// Destroy the screenshot surface 
		SDL_FreeSurface(pScreenShot);
	}

}*/