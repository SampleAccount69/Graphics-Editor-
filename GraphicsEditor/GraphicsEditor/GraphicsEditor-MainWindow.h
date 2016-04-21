#ifndef HEADER_H
#define HEADER_H

#pragma once
#include "Header.h"
#include <iostream>

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


	private: System::Windows::Forms::Button^  btnTriangle;

	public: GraphicsEditorMainWindow(void)
		{
			InitializeComponent();

			window = functions::newWindow();
			renderer = functions::newRenderer(window);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderPresent(renderer);
			//
			//TODO: Add the constructor code here
			//
		}

	private: ~GraphicsEditorMainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btnDrawLine;

	private: System::Windows::Forms::Button^  btnDraw;

	private: System::Windows::Forms::Button^  btnCircle;

	private: System::Windows::Forms::Button^  btnBlurr;

	private: System::Windows::Forms::Button^  btnNewWindow;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 void InitializeComponent(void)
			 {
				 this->btnCircle = (gcnew System::Windows::Forms::Button());
				 this->btnBlurr = (gcnew System::Windows::Forms::Button());
				 this->btnNewWindow = (gcnew System::Windows::Forms::Button());
				 this->btnDraw = (gcnew System::Windows::Forms::Button());
				 this->btnTriangle = (gcnew System::Windows::Forms::Button());
				 this->btnDrawLine = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // btnCircle
				 // 
				 this->btnCircle->Location = System::Drawing::Point(10, 192);
				 this->btnCircle->Name = L"btnCircle";
				 this->btnCircle->Size = System::Drawing::Size(86, 24);
				 this->btnCircle->TabIndex = 2;
				 this->btnCircle->Text = L"CircleJerk";
				 this->btnCircle->UseVisualStyleBackColor = true;
				 this->btnCircle->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnCircle_Click);
				 // 
				 // btnBlurr
				 // 
				 this->btnBlurr->Location = System::Drawing::Point(638, 26);
				 this->btnBlurr->Name = L"btnBlurr";
				 this->btnBlurr->Size = System::Drawing::Size(64, 24);
				 this->btnBlurr->TabIndex = 7;
				 this->btnBlurr->Text = L"Blurr";
				 this->btnBlurr->UseVisualStyleBackColor = true;
				 // 
				 // btnNewWindow
				 // 
				 this->btnNewWindow->Location = System::Drawing::Point(10, 163);
				 this->btnNewWindow->Name = L"btnNewWindow";
				 this->btnNewWindow->Size = System::Drawing::Size(86, 23);
				 this->btnNewWindow->TabIndex = 12;
				 this->btnNewWindow->Text = L"New Window";
				 this->btnNewWindow->UseVisualStyleBackColor = true;
				 this->btnNewWindow->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnNewWindow_Click);
				 // 
				 // btnDraw
				 // 
				 this->btnDraw->Location = System::Drawing::Point(10, 11);
				 this->btnDraw->Name = L"btnDraw";
				 this->btnDraw->Size = System::Drawing::Size(64, 23);
				 this->btnDraw->TabIndex = 13;
				 this->btnDraw->Text = L"Draw";
				 this->btnDraw->UseVisualStyleBackColor = true;
				 this->btnDraw->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnDraw_Click);
				 // 
				 // btnTriangle
				 // 
				 this->btnTriangle->Location = System::Drawing::Point(10, 223);
				 this->btnTriangle->Name = L"btnTriangle";
				 this->btnTriangle->Size = System::Drawing::Size(86, 23);
				 this->btnTriangle->TabIndex = 14;
				 this->btnTriangle->Text = L"TriangleJerk";
				 this->btnTriangle->UseVisualStyleBackColor = true;
				 this->btnTriangle->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnTriangle_Click);
				 // 
				 // btnDrawLine
				 // 
				 this->btnDrawLine->Location = System::Drawing::Point(13, 252);
				 this->btnDrawLine->Name = L"btnDrawLine";
				 this->btnDrawLine->Size = System::Drawing::Size(83, 23);
				 this->btnDrawLine->TabIndex = 15;
				 this->btnDrawLine->Text = L"Draw Line";
				 this->btnDrawLine->UseVisualStyleBackColor = true;
				 this->btnDrawLine->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnDrawLine_Click);
				 // 
				 // GraphicsEditorMainWindow
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(193, 278);
				 this->Controls->Add(this->btnDrawLine);
				 this->Controls->Add(this->btnTriangle);
				 this->Controls->Add(this->btnDraw);
				 this->Controls->Add(this->btnNewWindow);
				 this->Controls->Add(this->btnBlurr);
				 this->Controls->Add(this->btnCircle);
				 this->Name = L"GraphicsEditorMainWindow";
				 this->Text = L"GraphicsEditorMainWindow";
				 this->ResumeLayout(false);

			 }

#pragma endregion
	private: System::Void btnDraw_Click(System::Object^  sender, System::EventArgs^  e)
	{
		isBtnDrawPressed = true;
		btnDraw->Enabled = false;
		btnCircle->Enabled = true;
		btnDrawLine->Enabled = true;
		draw();
		isBtnDrawPressed = false;
		btnDraw->Enabled = true;
	}

	private: System::Void btnNewWindow_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		isBtnDrawPressed = false;
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

	private: System::Void btnRotateLeft_Click(System::Object^  sender, System::EventArgs^  e) {

	}

	private: System::Void btnCircle_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		isBtnCirclePressed = true;
		btnDraw->Enabled = true;
		btnCircle->Enabled = false;
		btnDrawLine->Enabled = true;
		drawCircle();
		isBtnCirclePressed = false;
		btnCircle->Enabled = true;
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
					isBtnDrawLinePressed = false;
					isBtnDrawPressed = false;
					isBtnTrianglePressed = false;
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
						point1.x = event.button.x;
						point1.y = event.button.y;
						counter++;
					}

					else
					{
						if (isPressed)
						{
							point2.x = event.motion.x;
							point2.y = event.motion.y;
							functions::BresenhamCircleDraw(point1.x, point1.y, point1.distance(point2) ,renderer);
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

	private: System::Void btnDrawLine_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		isBtnDrawLinePressed = true;
		btnDraw->Enabled = true;
		btnCircle->Enabled = true;
		btnDrawLine->Enabled = false;
		drawLine();
		isBtnDrawLinePressed = false;
		btnDrawLine->Enabled = true;
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
					isBtnCirclePressed = false;
					isBtnDrawLinePressed = false;
					isBtnDrawPressed = false;
					isBtnTrianglePressed = false;
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
						point1.x = event.button.x;
						point1.y = event.button.y;
						counter++;
					}

					else
					{
						if (isPressed)
						{
							point2.x = event.motion.x;
							point2.y = event.motion.y;
							functions::bresenhamLine(point1, point2, renderer);
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