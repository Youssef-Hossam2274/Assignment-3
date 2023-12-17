#pragma once

namespace GamesGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Pyramic_Board
	/// </summary>
	public ref class Pyramic_Board : public System::Windows::Forms::Form
	{
	public:
		Pyramic_Board(void)
		{
			InitializeComponent();
			label1->Hide();
			label5->Hide();
			textBox1->Hide();
			checkBox1->Hide();

			x_turn = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Pyramic_Board()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::CheckBox^ checkBox1;


		   System::String^ player1name = "";
		   System::String^ player2name = "";
		   bool is_computer;
		   bool x_turn;
		   array<char>^ charGrid = gcnew array<char>(9);
		   void update_turn()
		   {
		   	x_turn = !x_turn;
		   	label5->Text = "Turn: " + (x_turn ? "X" : "O");
		   }






	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Player 1 enter your name";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(36, 97);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(161, 22);
			this->textBox1->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(530, 97);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 68);
			this->button2->TabIndex = 3;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Pyramic_Board::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(530, 175);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(101, 68);
			this->button3->TabIndex = 4;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Pyramic_Board::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(423, 175);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(101, 68);
			this->button4->TabIndex = 5;
			this->button4->Text = L"2";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Pyramic_Board::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(637, 175);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(101, 68);
			this->button5->TabIndex = 6;
			this->button5->Text = L"4";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Pyramic_Board::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(423, 249);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(101, 68);
			this->button6->TabIndex = 7;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Pyramic_Board::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(530, 249);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(101, 68);
			this->button7->TabIndex = 8;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Pyramic_Board::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(637, 249);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(101, 68);
			this->button8->TabIndex = 9;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Pyramic_Board::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(316, 249);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(101, 68);
			this->button9->TabIndex = 10;
			this->button9->Text = L"5";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Pyramic_Board::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(744, 249);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(101, 68);
			this->button10->TabIndex = 11;
			this->button10->Text = L"9";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Pyramic_Board::button10_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(33, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 16);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Player 1:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(358, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 16);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Player 2:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(33, 137);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 16);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Play with:";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(36, 164);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(127, 50);
			this->button11->TabIndex = 15;
			this->button11->Text = L"Friend";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Pyramic_Board::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(36, 220);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(127, 50);
			this->button12->TabIndex = 16;
			this->button12->Text = L"Computer";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Pyramic_Board::button12_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(203, 102);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(18, 17);
			this->checkBox1->TabIndex = 18;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Pyramic_Board::checkBox1_CheckedChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(699, 8);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(51, 16);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Turn:  X";
			// 
			// Pyramic_Board
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 485);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Pyramic_Board";
			this->Text = L"Pyramic Tic-Tac-Toe";
			this->Load += gcnew System::EventHandler(this, &Pyramic_Board::Pyramic_Board_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Pyramic_Board_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
		is_computer = true;
		player2name = "Computer";
		label3->Text = "Player 2: " + player2name + "    (O)";
		label1->Show();
		textBox1->Show();
		checkBox1->Show();
		button12->Hide();
		button11->Hide();
		label4->Hide();
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (player1name == "" && player2name == "")
		{
			player1name = textBox1->Text;
			label2->Text = "Player 1: " + player1name + "  X";
			textBox1->Clear();
			label1->Text = "Player 2 enter your name";
		}
		else if (is_computer)
		{
			player1name = textBox1->Text;
			label2->Text = "Player 1: " + player1name + "  X";
			label1->Hide();
			textBox1->Hide();
			checkBox1->Hide();
			label5->Show();
		}
		else
		{
			player2name = textBox1->Text;
			label3->Text = "Player 2: " + player2name + "  O";
			textBox1->Hide();
			label1->Hide();
			checkBox1->Hide();
			label5->Show();
		}
	}
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
		is_computer = false;
		label1->Show();
		textBox1->Show();
		checkBox1->Show();
		button12->Hide();
		button11->Hide();
		label4->Hide();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button2->Text != "X" && button2->Text != "O")
		{
			if (x_turn)
				button2->Text = "X";
			else
				button2->Text = "O";
			update_turn();
		}
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button4->Text != "X" && button4->Text != "O")
		{
			if (x_turn)
				button4->Text = "X";
			else
				button4->Text = "O";
			update_turn();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button3->Text != "X" && button3->Text != "O")
		{
			if (x_turn)
				button3->Text = "X";
			else
				button3->Text = "O";
			update_turn();
		}

	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button5->Text != "X" && button5->Text != "O")
		{
			if (x_turn)
				button5->Text = "X";
			else
				button5->Text = "O";
			update_turn();
		}

	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button9->Text != "X" && button9->Text != "O")
		{
			if (x_turn)
				button9->Text = "X";
			else
				button9->Text = "O";
			update_turn();
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button6->Text != "X" && button6->Text != "O")
		{
			if (x_turn)
				button6->Text = "X";
			else
				button6->Text = "O";
			update_turn();
		};

	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button7->Text != "X" && button7->Text != "O")
		{
			if (x_turn)
				button7->Text = "X";
			else
				button7->Text = "O";
			update_turn();
		}
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button8->Text != "X" && button8->Text != "O")
		{
			if (x_turn)
				button8->Text = "X";
			else
				button8->Text = "O";
			update_turn();
		}
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button10->Text != "X" && button10->Text != "O")
		{
			if (x_turn)
				button10->Text = "X";
			else
				button10->Text = "O";
			update_turn();
		}
	}
	};
}
