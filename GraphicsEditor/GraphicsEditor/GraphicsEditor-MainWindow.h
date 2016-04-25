#ifndef HEADER_H
#define HEADER_H

#pragma once
#include "Header.h"
#include <iostream>
#include <vector>

namespace GraphicsEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	public ref class GraphicsEditorMainWindow : public System::Windows::Forms::Form
	{
	private:
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Surface* surface = NULL;

		//System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
		bool isBtnDrawPressed = false;
		bool isBtnCirclePressed = false;
		bool isBtnTrianglePressed = false;
		bool isBtnDrawLinePressed = false;
		bool isBtnBezierPressed = false;
		bool isBtnRectanglePressed = false;

	private: System::Windows::Forms::Button^  btnBezier;
	private: System::Windows::Forms::Button^  btnTriangle;
	private: System::Windows::Forms::Button^  btnDrawLine;
	private: System::Windows::Forms::Button^  btnDraw;
	private: System::Windows::Forms::Button^  btnCircle;
	private: System::Windows::Forms::Button^  btnNewWindow;
	private: System::Windows::Forms::Button^  btnRectangle;

	private: System::ComponentModel::Container ^components;

	public: GraphicsEditorMainWindow(void)
		{
			InitializeComponent();

			window = functions::newWindow();
			renderer = functions::newRenderer(window);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderPresent(renderer);
		}

	private: ~GraphicsEditorMainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code
			 void InitializeComponent(void)
			 {
				 this->btnCircle = (gcnew System::Windows::Forms::Button());
				 this->btnNewWindow = (gcnew System::Windows::Forms::Button());
				 this->btnDraw = (gcnew System::Windows::Forms::Button());
				 this->btnTriangle = (gcnew System::Windows::Forms::Button());
				 this->btnDrawLine = (gcnew System::Windows::Forms::Button());
				 this->btnBezier = (gcnew System::Windows::Forms::Button());
				 this->btnRectangle = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // btnCircle
				 // 
				 this->btnCircle->Location = System::Drawing::Point(13, 236);
				 this->btnCircle->Margin = System::Windows::Forms::Padding(4);
				 this->btnCircle->Name = L"btnCircle";
				 this->btnCircle->Size = System::Drawing::Size(115, 30);
				 this->btnCircle->TabIndex = 2;
				 this->btnCircle->Text = L"Circle";
				 this->btnCircle->UseVisualStyleBackColor = true;
				 this->btnCircle->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnCircle_Click);
				 // 
				 // btnNewWindow
				 // 
				 this->btnNewWindow->Location = System::Drawing::Point(13, 13);
				 this->btnNewWindow->Margin = System::Windows::Forms::Padding(4);
				 this->btnNewWindow->Name = L"btnNewWindow";
				 this->btnNewWindow->Size = System::Drawing::Size(115, 28);
				 this->btnNewWindow->TabIndex = 12;
				 this->btnNewWindow->Text = L"New Window";
				 this->btnNewWindow->UseVisualStyleBackColor = true;
				 this->btnNewWindow->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnNewWindow_Click);
				 // 
				 // btnDraw
				 // 
				 this->btnDraw->Location = System::Drawing::Point(13, 60);
				 this->btnDraw->Margin = System::Windows::Forms::Padding(4);
				 this->btnDraw->Name = L"btnDraw";
				 this->btnDraw->Size = System::Drawing::Size(115, 28);
				 this->btnDraw->TabIndex = 13;
				 this->btnDraw->Text = L"Draw";
				 this->btnDraw->UseVisualStyleBackColor = true;
				 this->btnDraw->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnDraw_Click);
				 // 
				 // btnTriangle
				 // 
				 this->btnTriangle->Location = System::Drawing::Point(13, 274);
				 this->btnTriangle->Margin = System::Windows::Forms::Padding(4);
				 this->btnTriangle->Name = L"btnTriangle";
				 this->btnTriangle->Size = System::Drawing::Size(115, 28);
				 this->btnTriangle->TabIndex = 14;
				 this->btnTriangle->Text = L"Triangle";
				 this->btnTriangle->UseVisualStyleBackColor = true;
				 this->btnTriangle->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnTriangle_Click);
				 // 
				 // btnDrawLine
				 // 
				 this->btnDrawLine->Location = System::Drawing::Point(13, 96);
				 this->btnDrawLine->Margin = System::Windows::Forms::Padding(4);
				 this->btnDrawLine->Name = L"btnDrawLine";
				 this->btnDrawLine->Size = System::Drawing::Size(115, 28);
				 this->btnDrawLine->TabIndex = 15;
				 this->btnDrawLine->Text = L"Draw Line";
				 this->btnDrawLine->UseVisualStyleBackColor = true;
				 this->btnDrawLine->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnDrawLine_Click);
				 // 
				 // btnBezier
				 // 
				 this->btnBezier->Location = System::Drawing::Point(13, 145);
				 this->btnBezier->Margin = System::Windows::Forms::Padding(4);
				 this->btnBezier->Name = L"btnBezier";
				 this->btnBezier->Size = System::Drawing::Size(115, 28);
				 this->btnBezier->TabIndex = 16;
				 this->btnBezier->Text = L"Bezier";
				 this->btnBezier->UseVisualStyleBackColor = true;
				 this->btnBezier->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnBezier_Click);
				 // 
				 // btnRectangle
				 // 
				 this->btnRectangle->Location = System::Drawing::Point(13, 310);
				 this->btnRectangle->Margin = System::Windows::Forms::Padding(4);
				 this->btnRectangle->Name = L"btnRectangle";
				 this->btnRectangle->Size = System::Drawing::Size(115, 28);
				 this->btnRectangle->TabIndex = 17;
				 this->btnRectangle->Text = L"Rectangle";
				 this->btnRectangle->UseVisualStyleBackColor = true;
				 this->btnRectangle->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnRectangle_Click);
				 // 
				 // GraphicsEditorMainWindow
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(257, 351);
				 this->Controls->Add(this->btnRectangle);
				 this->Controls->Add(this->btnBezier);
				 this->Controls->Add(this->btnDrawLine);
				 this->Controls->Add(this->btnTriangle);
				 this->Controls->Add(this->btnDraw);
				 this->Controls->Add(this->btnNewWindow);
				 this->Controls->Add(this->btnCircle);
				 this->Margin = System::Windows::Forms::Padding(4);
				 this->Name = L"GraphicsEditorMainWindow";
				 this->Text = L"GraphicsEditorMainWindow";
				 this->ResumeLayout(false);

			 }

#pragma endregion
	
	private: System::Void btnNewWindow_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}

	private: System::Void btnDraw_Click(System::Object^  sender, System::EventArgs^  e)
	{
		isBtnDrawPressed = true;
		btnDraw->Enabled = false;
		btnDrawLine->Enabled = true;
		btnBezier->Enabled = true;
		btnCircle->Enabled = true;
		btnRectangle->Enabled = true;
		draw();
	}

	private: System::Void draw()
	{
		SDL_Event event;
		bool isPressed = false;
		while (isBtnDrawPressed == true)
		{
			if (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
				{
					//close();
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderClear(renderer);
					SDL_RenderPresent(renderer);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					isBtnDrawPressed = false;
					btnDraw->Enabled = true;
					break;
				}
				else if (event.type == SDL_MOUSEBUTTONUP)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						isPressed = false;
					}
				}
				else if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						isPressed = true;
					}
				}
				else if (event.type == SDL_MOUSEMOTION)
				{
					if (isPressed)
					{
						SDL_RenderDrawPoint(renderer, event.motion.x, event.motion.y);
						SDL_RenderPresent(renderer);
					}
				}
			}
		};
	}

	private: System::Void btnDrawLine_Click(System::Object^  sender, System::EventArgs^  e)
	{
		isBtnDrawLinePressed = true;
		btnDraw->Enabled = true;
		btnDrawLine->Enabled = false;
		btnBezier->Enabled = true;
		btnCircle->Enabled = true;
		btnRectangle->Enabled = true;
		drawLine();
	}

	private: System::Void drawLine()
	{
		SDL_Event event;
		functions::Point point1;
		functions::Point point2;
		int counter = 0;
		bool isPressed = false;
		while (isBtnDrawLinePressed)
		{
			if (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderClear(renderer);
					SDL_RenderPresent(renderer);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					isBtnDrawLinePressed = false;
					btnDrawLine->Enabled = true;
					break;
				}
				else if (event.type == SDL_MOUSEBUTTONUP)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						isPressed = false;

					}
				}
				else if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						isPressed = true;
						counter = 0;
					}
				}
				else if (event.type == SDL_MOUSEMOTION)
				{
					if (counter == 0)
					{
						point1.setX(event.button.x);
						point1.setY(event.button.y);
						counter++;
					}

					else
					{
						if (isPressed)
						{
							point2.setX(event.motion.x);
							point2.setY(event.motion.y);
							functions::bresenhamLine(point1, point2, renderer);
							SDL_RenderPresent(renderer);
						}
					}
				}
			}
		}
	}

	private: System::Void btnCircle_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		isBtnCirclePressed = true;
		btnDraw->Enabled = true;
		btnDrawLine->Enabled = true;
		btnBezier->Enabled = true;
		btnCircle->Enabled = false;
		btnRectangle->Enabled = true;
		drawCircle();
	}

	private: System::Void drawCircle()
	{
		SDL_Event event;
		functions::Point point1;
		functions::Point point2;
		bool isPressed = false;
		int counter = 0;
		while (isBtnCirclePressed)
		{
			if (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderClear(renderer);
					SDL_RenderPresent(renderer);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					isBtnCirclePressed = false;
					btnCircle->Enabled = true;
					break;
				}
				else if (event.type == SDL_MOUSEBUTTONUP)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						isPressed = false;
					}
				}
				else if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						counter = 0;
						isPressed = true;

					}
				}
				else if (event.type == SDL_MOUSEMOTION)
				{
					if (counter == 0)
					{
						point1.setX(event.button.x);
						point1.setY(event.button.y);
						counter++;
					}

					else
					{
						if (isPressed)
						{
							point2.setX(event.motion.x);
							point2.setY(event.motion.y);
							functions::BresenhamCircleDraw(point1.getX(), point1.getY(), point1.distance(point2) ,renderer);
							SDL_RenderPresent(renderer);
						}
					}
				}
				/*else if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					functions::BresenhamCircleDraw(event.button.x, event.button.y, 50, renderer);
					SDL_RenderPresent(renderer);
				}*/
			}
		}
	}

	private: System::Void btnTriangle_Click(System::Object^  sender, System::EventArgs^  e) {
		isBtnTrianglePressed = true;
		btnCircle->Enabled = false;
		btnBezier->Enabled = true;
		drawTriangle();
		isBtnTrianglePressed = false;
		btnCircle->Enabled = true;
	}

	private: System::Void drawTriangle()
	{
		SDL_Event event;
		int point1;
		int point2;
		int point3;
		int clickCounter = 0;
		while (isBtnTrianglePressed)
		{
			if (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderClear(renderer);
					SDL_RenderPresent(renderer);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					isBtnCirclePressed = false;
					isBtnDrawLinePressed = false;
					isBtnDrawPressed = true;
					isBtnTrianglePressed = false;
					break;
				}
				else if (true)
				{

				}
			}
		}

	}

	private: System::Void btnRotateLeft_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void btnBezier_Click(System::Object^  sender, System::EventArgs^  e)
	{
		isBtnBezierPressed = true;
		btnBezier->Enabled = false;
		btnDraw->Enabled = true;
		btnCircle->Enabled = true;
		btnDrawLine->Enabled = true;
		bezier();
	}

	private: System::Void bezier()
	{
		SDL_Event event;
		std::vector<functions::Point> points;
		int counter = 0;
		
		while (isBtnBezierPressed)
		{
			if (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderClear(renderer);
					SDL_RenderPresent(renderer);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					isBtnCirclePressed = false;
					isBtnDrawLinePressed = false;
					isBtnDrawPressed = false;
					isBtnTrianglePressed = false;
					isBtnBezierPressed = false;
					btnBezier->Enabled = true;
					break;
				}
				
				else if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					functions::Point tempPoint = functions::Point(event.button.x, event.button.y);
					SDL_RenderDrawPoint(renderer, tempPoint.getX(), tempPoint.getY());
					SDL_RenderDrawPoint(renderer, tempPoint.getX(), tempPoint.getY() - 1);
					SDL_RenderDrawPoint(renderer, tempPoint.getX(), tempPoint.getY() - 2);
					SDL_RenderDrawPoint(renderer, tempPoint.getX() - 1, tempPoint.getY());
					SDL_RenderDrawPoint(renderer, tempPoint.getX() - 2, tempPoint.getY());
					SDL_RenderDrawPoint(renderer, tempPoint.getX(), tempPoint.getY() + 1);
					SDL_RenderDrawPoint(renderer, tempPoint.getX(), tempPoint.getY() + 2);
					SDL_RenderDrawPoint(renderer, tempPoint.getX() + 1, tempPoint.getY());
					SDL_RenderDrawPoint(renderer, tempPoint.getX() + 2, tempPoint.getY());
					SDL_RenderDrawPoint(renderer, tempPoint.getX() + 1, tempPoint.getY() + 1);
					SDL_RenderDrawPoint(renderer, tempPoint.getX() + 1, tempPoint.getY()) - 1;
					SDL_RenderDrawPoint(renderer, tempPoint.getX() - 1, tempPoint.getY() + 1);
					SDL_RenderDrawPoint(renderer, tempPoint.getX() - 1, tempPoint.getY() - 1);
					

					if (counter == 0)
					{
						points.push_back(tempPoint);
					}
					else
					{
						if (counter >= 2)
						{
							functions::Point helpPoint = points[counter - 1];
							points.pop_back();
							points.push_back(tempPoint);
							points.push_back(helpPoint);
							functions::bezier(points, renderer);
							SDL_RenderPresent(renderer);
						}
						else
						{
							points.push_back(tempPoint);
							functions::bezier(points, renderer);
							SDL_RenderPresent(renderer);
						}
					}

					counter++;
				}
			}
		}
	}

	private: System::Void btnRectangle_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		isBtnRectanglePressed = true;
		btnBezier->Enabled = true;
		btnDraw->Enabled = true;
		btnBezier->Enabled = true;
		btnCircle->Enabled = true;
		btnDrawLine->Enabled = true;
		btnRectangle->Enabled = false;
		rectangle();
	}

	private: System::Void rectangle()
	{
		SDL_Event event;
		functions::Point point1;
		functions::Point point2;
		int counter = 0;
		bool isPressed = false;
		while (isBtnRectanglePressed)
		{
			if (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderClear(renderer);
					SDL_RenderPresent(renderer);
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					isBtnCirclePressed = false;
					isBtnDrawLinePressed = false;
					isBtnDrawPressed = false;
					isBtnTrianglePressed = false;
					isBtnBezierPressed = false;
					isBtnRectanglePressed = false;
					btnRectangle->Enabled = true;
					break;
				}
				else if (event.type == SDL_MOUSEBUTTONUP)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						isPressed = false;

					}
				}
				else if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if (event.button.button == SDL_BUTTON_LEFT)
					{
						isPressed = true;
						counter = 0;
					}
				}
				else if (event.type == SDL_MOUSEMOTION)
				{
					if (counter == 0)
					{
						point1.setX(event.button.x);
						point1.setY(event.button.y);
						counter++;
					}

					else
					{
						if (isPressed)
						{
							point2.setX(event.motion.x);
							point2.setY(event.motion.y);
							functions::rectangle(point1, point2, renderer);
							SDL_RenderPresent(renderer);
						}
					}
				}
			}
		}
	}
};
}
#endif // !HEADER_H



/*
while (isbtncirclepressed == true)
{
	if (sdl_pollevent(&event) != 0)
	{
		if (event.type == sdl_quit)
		{
			//close();
			sdl_setrenderdrawcolor(renderer, 255, 255, 255, 255);
			sdl_renderclear(renderer);
			sdl_renderpresent(renderer);
			sdl_setrenderdrawcolor(renderer, 0, 0, 0, 255);
			isbtncirclepressed = false;
			break;
		}
		else if (event.type == sdl_mousebuttonup)
		{
			if (event.button.button == sdl_button_left)
			{
				ispressed = false;
			}
		}
		else if (event.type == sdl_mousebuttondown)
		{
			if (event.button.button == sdl_button_left)
			{
				ispressed = true;
				globalx = event.button.x;
				globaly = event.button.y;
				bresenhamcircledraw(globalx, globaly, 50, renderer);

			}
		}
		else if (event.type == sdl_mousemotion)
		{
			if (ispressed)
			{
				bresenhamcircledraw(event.motion.x, event.motion.y, 5, renderer);
			}
		}
	}
};
*/