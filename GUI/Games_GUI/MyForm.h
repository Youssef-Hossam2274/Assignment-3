#pragma once
#include"Connect_four_game.h"
<<<<<<< HEAD
=======
#include"Five_Five_Board.h"
#include""
>>>>>>> 58ba7eba0b8caee9869682f199e358ffa6475b17
#include"MyForm.h"

namespace GamesGUI {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;

    // GameOptionsForm for selecting different games
    public ref class GameOptionsForm : public System::Windows::Forms::Form
    {
    public:
        GameOptionsForm()
        {
            InitializeComponent();
        }

    protected:
        ~GameOptionsForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Button^ game1Button;
        System::Windows::Forms::Button^ game2Button;
        System::Windows::Forms::Button^ game3Button;

        void InitializeComponent(void)
        {
            this->game1Button = (gcnew System::Windows::Forms::Button());
            this->game2Button = (gcnew System::Windows::Forms::Button());
            this->game3Button = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // game1Button
            // 
            this->game1Button->Location = System::Drawing::Point(176, 202);
            this->game1Button->Name = L"game1Button";
            this->game1Button->Size = System::Drawing::Size(100, 50);
            this->game1Button->TabIndex = 0;
            this->game1Button->Text = L"Game 1";
            this->game1Button->Click += gcnew System::EventHandler(this, &GameOptionsForm::game1Button_Click);
            // 
            // game2Button
            // 
            this->game2Button->Location = System::Drawing::Point(386, 202);
            this->game2Button->Name = L"game2Button";
            this->game2Button->Size = System::Drawing::Size(100, 50);
            this->game2Button->TabIndex = 1;
            this->game2Button->Text = L"Game 2";
            this->game2Button->Click += gcnew System::EventHandler(this, &GameOptionsForm::game2Button_Click);
            // 
            // game3Button
            // 
            this->game3Button->Location = System::Drawing::Point(616, 202);
            this->game3Button->Name = L"game3Button";
            this->game3Button->Size = System::Drawing::Size(100, 50);
            this->game3Button->TabIndex = 2;
            this->game3Button->Text = L"Game 3";
            this->game3Button->Click += gcnew System::EventHandler(this, &GameOptionsForm::game3Button_Click);
            // 
            // GameOptionsForm
            // 
            this->ClientSize = System::Drawing::Size(920, 455);
            this->Controls->Add(this->game1Button);
            this->Controls->Add(this->game2Button);
            this->Controls->Add(this->game3Button);
            this->Name = L"GameOptionsForm";
            this->Text = L"Game Options";
            this->ResumeLayout(false);

        }

        void game1Button_Click(System::Object^ sender, System::EventArgs^ e)
        {
            MyForm1^ game1Form = gcnew MyForm1();
            game1Form->Show();
        }

        void game2Button_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Create and show the Game 2 window
<<<<<<< HEAD
            /*Game2Form^ game2Form = gcnew Game2Form();
            game2Form->Show();*/
=======
            Game2Form^ game2Form = gcnew Game2Form();
            game2Form->Show();
>>>>>>> 58ba7eba0b8caee9869682f199e358ffa6475b17
        }

        void game3Button_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Create and show the Game 3 window
            /*Game3Form^ game3Form = gcnew Game3Form();
            game3Form->Show();*/
        }
    };
}
