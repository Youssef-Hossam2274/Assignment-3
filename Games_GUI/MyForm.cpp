#include "MyForm.h"
#include"Connect_four_game.h"
#include"Five_Five_Board.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run GameOptionsForm
    Application::Run(gcnew GamesGUI::GameOptionsForm());

    return 0;
}
