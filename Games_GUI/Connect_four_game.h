#pragma once

namespace GamesGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class Connect_Four_Board : public System::Windows::Forms::Form
	{
	public:
		Connect_Four_Board(void)
		{
			InitializeComponent();


			this->SuspendLayout();

			// Connect four window 

			this->ClientSize = System::Drawing::Size(920, 455);
			this->Name = L"Connnect FOUR window";
			this->Text = L"Connnect FOUR";
			this->ResumeLayout(false);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Connect_Four_Board()
		{
			if (components)
			{
				delete components;
			}
		}

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
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(957, 522);
			this->Name = L"Connnect FOUR window";
			this->Text = L"Connnect FOUR";
			this->Load += gcnew System::EventHandler(this, &Connect_Four_Board::MyForm1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
