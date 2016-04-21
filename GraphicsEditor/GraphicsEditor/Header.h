//#ifndef HEADER_H
//#define HEADER_H

#pragma once
#include <SDL/SDL.h>
#include <cmath>

namespace functions
{
	struct Point
	{
		int x;
		int y;

		Point(int x1 = 0, int y1 = 0)
		{
			x = x1;
			y = y1;
		}

		int distance(Point secondPoint)
		{
			return sqrt((this->x - secondPoint.x) * (this->x - secondPoint.x) +
						(this->y - secondPoint.y) * (this->y - secondPoint.y));
		}
	};

	SDL_Window* newWindow();

	SDL_Renderer* newRenderer(SDL_Window*);

	void BresenhamCircleDraw(int xx, int yy, int radius, SDL_Renderer* renderer);

	void display(int x1, int y1, int xx, int yy, SDL_Renderer* renderer);

	void bresenhamLine(Point &first, Point &second, SDL_Renderer* renderer);
	//#endif 



}