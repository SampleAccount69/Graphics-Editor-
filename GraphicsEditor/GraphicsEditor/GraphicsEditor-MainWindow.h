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

	struct Point
	{
		int x;
		int y;

		Point(int x1 = 0, int y1 = 0)
		{
			x = x1;
			y = y1;
		}
	};

	public ref class GraphicsEditorMainWindow : public System::Windows::Forms::Form
	{
	private:
		SDL_Window* window = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Surface* surface = NULL;
	
	//System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
		bool isBtnDrawPressed = false;

	public:
		GraphicsEditorMainWindow(void)
		{
			InitializeComponent();

			window = newWindow();
			renderer = newRenderer(window);
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderPresent(renderer);
			//
			//TODO: Add the constructor code here
			//
		}


	private:
		~GraphicsEditorMainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  btnDraw;
	private: System::Windows::Forms::Button^  btnTriangle;
	private: System::Windows::Forms::Button^  btnCircle;
	private: System::Windows::Forms::Button^  btnRotateLeft;
	private: System::Windows::Forms::Button^  btnRotateRight;
	private: System::Windows::Forms::Button^  btnBlurr;
	private: System::Windows::Forms::Button^  btnAnimation;
	private: System::Windows::Forms::Button^  btnRectangle;
	private: System::Windows::Forms::Button^  btnNewWindow;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btnTriangle = (gcnew System::Windows::Forms::Button());
			this->btnCircle = (gcnew System::Windows::Forms::Button());
			this->btnRotateLeft = (gcnew System::Windows::Forms::Button());
			this->btnRotateRight = (gcnew System::Windows::Forms::Button());
			this->btnBlurr = (gcnew System::Windows::Forms::Button());
			this->btnAnimation = (gcnew System::Windows::Forms::Button());
			this->btnRectangle = (gcnew System::Windows::Forms::Button());
			this->btnNewWindow = (gcnew System::Windows::Forms::Button());
			this->btnDraw = (gcnew System::Windows::Forms::Button());
			//this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->SuspendLayout();
			// 
			// btnTriangle
			// 
			this->btnTriangle->Location = System::Drawing::Point(13, 50);
			this->btnTriangle->Margin = System::Windows::Forms::Padding(4);
			this->btnTriangle->Name = L"btnTriangle";
			this->btnTriangle->Size = System::Drawing::Size(67, 30);
			this->btnTriangle->TabIndex = 1;
			this->btnTriangle->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->btnTriangle->UseVisualStyleBackColor = true;
			this->btnTriangle->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnTriangle_Click);
			// 
			// btnCircle
			// 
			this->btnCircle->Location = System::Drawing::Point(93, 50);
			this->btnCircle->Margin = System::Windows::Forms::Padding(4);
			this->btnCircle->Name = L"btnCircle";
			this->btnCircle->Size = System::Drawing::Size(67, 30);
			this->btnCircle->TabIndex = 2;
			this->btnCircle->UseVisualStyleBackColor = true;
			// 
			// btnRotateLeft
			// 
			this->btnRotateLeft->Location = System::Drawing::Point(13, 89);
			this->btnRotateLeft->Margin = System::Windows::Forms::Padding(4);
			this->btnRotateLeft->Name = L"btnRotateLeft";
			this->btnRotateLeft->Size = System::Drawing::Size(103, 30);
			this->btnRotateLeft->TabIndex = 3;
			this->btnRotateLeft->UseVisualStyleBackColor = true;
			// 
			// btnRotateRight
			// 
			this->btnRotateRight->Location = System::Drawing::Point(141, 89);
			this->btnRotateRight->Margin = System::Windows::Forms::Padding(4);
			this->btnRotateRight->Name = L"btnRotateRight";
			this->btnRotateRight->Size = System::Drawing::Size(103, 30);
			this->btnRotateRight->TabIndex = 4;
			this->btnRotateRight->UseVisualStyleBackColor = true;
			// 
			// btnBlurr
			// 
			this->btnBlurr->Location = System::Drawing::Point(851, 32);
			this->btnBlurr->Margin = System::Windows::Forms::Padding(4);
			this->btnBlurr->Name = L"btnBlurr";
			this->btnBlurr->Size = System::Drawing::Size(85, 30);
			this->btnBlurr->TabIndex = 7;
			this->btnBlurr->Text = L"Blurr";
			this->btnBlurr->UseVisualStyleBackColor = true;
			// 
			// btnAnimation
			// 
			this->btnAnimation->Location = System::Drawing::Point(13, 163);
			this->btnAnimation->Margin = System::Windows::Forms::Padding(4);
			this->btnAnimation->Name = L"btnAnimation";
			this->btnAnimation->Size = System::Drawing::Size(85, 30);
			this->btnAnimation->TabIndex = 10;
			this->btnAnimation->UseVisualStyleBackColor = true;
			// 
			// btnRectangle
			// 
			this->btnRectangle->Location = System::Drawing::Point(179, 50);
			this->btnRectangle->Margin = System::Windows::Forms::Padding(4);
			this->btnRectangle->Name = L"btnRectangle";
			this->btnRectangle->Size = System::Drawing::Size(67, 30);
			this->btnRectangle->TabIndex = 11;
			this->btnRectangle->UseVisualStyleBackColor = true;
			// 
			// btnNewWindow
			// 
			this->btnNewWindow->Location = System::Drawing::Point(13, 201);
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
			this->btnDraw->Location = System::Drawing::Point(13, 13);
			this->btnDraw->Margin = System::Windows::Forms::Padding(4);
			this->btnDraw->Name = L"btnDraw";
			this->btnDraw->Size = System::Drawing::Size(85, 28);
			this->btnDraw->TabIndex = 13;
			this->btnDraw->Text = L"Draw";
			this->btnDraw->UseVisualStyleBackColor = true;
			this->btnDraw->Click += gcnew System::EventHandler(this, &GraphicsEditorMainWindow::btnDraw_Click);
			// 
			// GraphicsEditorMainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(257, 342);
			this->Controls->Add(this->btnDraw);
			this->Controls->Add(this->btnNewWindow);
			this->Controls->Add(this->btnRectangle);
			this->Controls->Add(this->btnAnimation);
			this->Controls->Add(this->btnBlurr);
			this->Controls->Add(this->btnRotateRight);
			this->Controls->Add(this->btnRotateLeft);
			this->Controls->Add(this->btnCircle);
			this->Controls->Add(this->btnTriangle);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GraphicsEditorMainWindow";
			this->Text = L"GraphicsEditorMainWindow";
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void btnTriangle_Click(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void btnDraw_Click(System::Object^  sender, System::EventArgs^  e)
	{
		isBtnDrawPressed = true;
		btnDraw->Enabled = false;
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

	private:
		System::Void draw()
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

	};
}
#endif // !HEADER_H
