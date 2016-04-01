#include "GraphicsEditor-MainWindow.h"

#include <SDL/SDL.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GraphicsEditor::GraphicsEditorMainWindow form;
	Application::Run(%form);

	return 0;
}

