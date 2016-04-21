
#include "GraphicsEditor-MainWindow.h"

#include <SDL/SDL.h>
//#include "Header.h"

SDL_Window* functions::newWindow()
{

	SDL_Window* firstWindow = SDL_CreateWindow("test window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, 0);
	return firstWindow;
}

SDL_Renderer* functions::newRenderer(SDL_Window* window)
{

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	return renderer;
}

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


void functions::BresenhamCircleDraw(int xx, int yy, int radius, SDL_Renderer* renderer)
{
	float dp;	//initialising the descision parameter.
	int x1, y1;
	x1 = 0; //initialisng the X,Y cordinates.
	y1 = radius;
	dp = 3 - 2 * radius;
	while (x1 <= y1)
	{
		if (dp <= 0) dp += (4 * x1) + 6;
		else
		{
			dp += 4 * (x1 - y1) + 10;
			y1--;
		}
		x1++;
		display(x1, y1, xx, yy, renderer);
	}
}	 
void functions::display(int x1, int y1, int xx, int yy, SDL_Renderer* renderer)
{
	SDL_RenderDrawPoint(renderer, xx, yy); //plotting the pixels. 
	SDL_RenderDrawPoint(renderer, xx + x1, yy - y1);
	SDL_RenderDrawPoint(renderer, xx - x1, yy + y1);
	SDL_RenderDrawPoint(renderer, xx - x1, yy - y1);
	SDL_RenderDrawPoint(renderer, xx + x1, yy + y1);
	SDL_RenderDrawPoint(renderer, xx + y1, yy + x1);
	SDL_RenderDrawPoint(renderer, xx + y1, yy - x1);
	SDL_RenderDrawPoint(renderer, xx - y1, yy + x1);
	SDL_RenderDrawPoint(renderer, xx - y1, yy - x1);
}

void functions::bresenhamLine(Point &first, Point &second, SDL_Renderer* renderer)
{
	int x1 = first.x;
	int	y1 = first.y;
	int	x2 = second.x;
	int	y2 = second.y;
	int	x, y;
	bool axis = abs(y2 - y1) - abs(x2 - x1) > 0;  // slope greater than 45 degrees exchanging x and y coordinates of each  
												//point to use the case where the slope is less than 45 degree( chooses the main axis)
	if (axis)
	{
		x = y1;
		y1 = x1;
		x1 = x;
		x = y2;
		y2 = x2;
		x2 = x;
	}
	
	//make the the point with greater x coordinate point2
	if (x2 - x1 < 0)
	{
		x = x1;
		x1 = x2;
		x2 = x;
		y = y1;
		y1 = y2;
		y2 = y;
	}

	int dx = x2 - x1;  // the difference between x coordinates for 
	int	dy = y2 - y1; //constant to determine if the next point has greater or smaller y coordinate
	int yC = dy < 0 ? -1 : 1; 
	int error = abs(dy) - abs(dx); //error to use when determining the coordinates of the next points

	//main loop where the each point is drawn and the coordinate of the next 
	//are calculated
	for (; x1 <= x2; x1++)
	{
		//std::cout << x1 << ' ' << y1 << '\n';
		//using the 'axis'  
		if (!axis)
			SDL_RenderDrawPoint(renderer, x1, y1);
		else
			SDL_RenderDrawPoint(renderer, y1, x1);
		if (error >= 0)
		{
			error -= dx;
			y1 += yC;
		}
		error += (yC * dy);
	}
	SDL_RenderPresent(renderer);
}