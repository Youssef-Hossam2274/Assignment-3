#pragma once

namespace GamesGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class Five_Five_Board : public System::Windows::Forms::Form
	{
	public:
		Five_Five_Board(void)
		{
			InitializeComponent();


			this->SuspendLayout();

			// Connect four window 

			this->ClientSize = System::Drawing::Size(920, 455);
			this->Name = L"5x5 window";
			this->Text = L"5x5!";
			this->ResumeLayout(false);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Five_Five_Board()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Five_Five_Board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1276, 642);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"5 x 5 Tic Tac Toe window";
			this->Text = L"5 x 5 Tic Tac Toe";
			this->Load += gcnew System::EventHandler(this, &Five_Five_Board::Five_Five_Board_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Five_Five_Board_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	};
}
