#pragma once
#include "MyForm.h"
#include "Connect_four_game.h"
#include "Five_Five_Board.h"
#include "Pyramic_Board.h"

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
			this->game1Button->Location = System::Drawing::Point(314, 191);
			this->game1Button->Name = L"game1Button";
			this->game1Button->Size = System::Drawing::Size(155, 75);
			this->game1Button->TabIndex = 0;
			this->game1Button->Text = L"Connect Four";
			this->game1Button->Click += gcnew System::EventHandler(this, &GameOptionsForm::game1Button_Click);
			// 
			// game2Button
			// 
			this->game2Button->Location = System::Drawing::Point(528, 191);
			this->game2Button->Name = L"game2Button";
			this->game2Button->Size = System::Drawing::Size(155, 75);
			this->game2Button->TabIndex = 1;
			this->game2Button->Text = L"5 x 5 Tic Tac Toe";
			this->game2Button->Click += gcnew System::EventHandler(this, &GameOptionsForm::game2Button_Click);
			// 
			// game3Button
			// 
			this->game3Button->Location = System::Drawing::Point(119, 191);
			this->game3Button->Name = L"game3Button";
			this->game3Button->Size = System::Drawing::Size(155, 75);
			this->game3Button->TabIndex = 2;
			this->game3Button->Text = L"Pyramic Tic-Tac-Toe";
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
			this->Load += gcnew System::EventHandler(this, &GameOptionsForm::GameOptionsForm_Load);
			this->ResumeLayout(false);

		}

		void game1Button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Connect_Four_Board^ connect_four_board = gcnew Connect_Four_Board();
			connect_four_board->Show();
		}

		void game2Button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Five_Five_Board^ five_fiveboard = gcnew Five_Five_Board();
			five_fiveboard->Show();
		}
		void game3Button_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Pyramic_Board^ pyramic_board = gcnew Pyramic_Board();
			pyramic_board->Show();
		}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void GameOptionsForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
