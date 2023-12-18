#pragma once
#include<array>
#include<string>

namespace GamesGUI {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	


	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();


			this->SuspendLayout();

			// Connect four window 

			this->ClientSize = System::Drawing::Size(920, 455);
			this->Name = L"connecg_four_window";
			this->Text = L"Connnect FOUR!";
			this->ResumeLayout(false);
		}

		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ _0_btn;
	private: System::Windows::Forms::Button^ _1_btn;
	private: System::Windows::Forms::Button^ _3_btn;
	private: System::Windows::Forms::Button^ _2_btn;
	private: System::Windows::Forms::Button^ _6_btn;
	private: System::Windows::Forms::Button^ _5_btn;
	private: System::Windows::Forms::Button^ _4_btn;



		   //Grid of the game represented in btns

	private: System::Windows::Forms::Button^ btn_1_0;
	private: System::Windows::Forms::Button^ btn_3_0;
	private: System::Windows::Forms::Button^ btn_2_0;
	private: System::Windows::Forms::Button^ btn_5_0;
	private: System::Windows::Forms::Button^ btn_4_0;
	private: System::Windows::Forms::Button^ btn_0_0;
	private: System::Windows::Forms::Button^ btn_0_1;
	private: System::Windows::Forms::Button^ btn_5_1;
	private: System::Windows::Forms::Button^ btn_4_1;
	private: System::Windows::Forms::Button^ btn_3_1;
	private: System::Windows::Forms::Button^ btn_2_1;
	private: System::Windows::Forms::Button^ btn_1_1;
	private: System::Windows::Forms::Button^ btn_0_2;
	private: System::Windows::Forms::Button^ btn_5_2;
	private: System::Windows::Forms::Button^ btn_4_2;
	private: System::Windows::Forms::Button^ btn_3_2;
	private: System::Windows::Forms::Button^ btn_2_2;
	private: System::Windows::Forms::Button^ btn_1_2;
	private: System::Windows::Forms::Button^ btn_0_3;
	private: System::Windows::Forms::Button^ btn_5_3;
	private: System::Windows::Forms::Button^ btn_4_3;
	private: System::Windows::Forms::Button^ btn_3_3;
	private: System::Windows::Forms::Button^ btn_2_3;
	private: System::Windows::Forms::Button^ btn_1_3;
	private: System::Windows::Forms::Button^ btn_0_4;
	private: System::Windows::Forms::Button^ btn_5_4;
	private: System::Windows::Forms::Button^ btn_4_4;
	private: System::Windows::Forms::Button^ btn_3_4;
	private: System::Windows::Forms::Button^ btn_2_4;
	private: System::Windows::Forms::Button^ btn_1_4;
	private: System::Windows::Forms::Button^ btn_0_5;
	private: System::Windows::Forms::Button^ btn_5_5;
	private: System::Windows::Forms::Button^ btn_4_5;
	private: System::Windows::Forms::Button^ btn_3_5;
	private: System::Windows::Forms::Button^ btn_2_5;
	private: System::Windows::Forms::Button^ btn_1_5;
	private: System::Windows::Forms::Button^ btn_0_6;
	private: System::Windows::Forms::Button^ btn_5_6;
	private: System::Windows::Forms::Button^ btn_4_6;
	private: System::Windows::Forms::Button^ btn_3_6;
	private: System::Windows::Forms::Button^ btn_2_6;
	private: System::Windows::Forms::Button^ btn_1_6;


	public:System::ComponentModel::Container^ components;


		  // functions
		  //void CenterImage();



		  //System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e);
		  //void MyForm1_Layout(System::Object^ sender, System::Windows::Forms::LayoutEventArgs^ e);

		  const int n_rows = 6;
		  const int n_cols = 7;
		  System::String^ player1name;
		  System::String^ player2name;
		  bool isname1taken = false;
		  bool isplayer1turn = true;
		  int n_moves = 0;
		  int MAX_MOVES = 42;
		  bool is_initialized = false;
		  const int gridLength = n_rows * n_cols;


		  array<char>^ charGrid = gcnew array<char>(gridLength);

		  int GetIndex(int row, int column) { // Function to convert 2D coordinates to a single index
			  return row * n_cols + column;
		  }
		  void SetValue(int row, int column, char value) { // Function to set value at specific coordinates
			  int index = GetIndex(row, column);
			  charGrid[index] = value;
		  }
		  char GetValue(int row, int column) { // Function to get value at specific coordinates
			  int index = GetIndex(row, column);
			  return charGrid[index];
		  }
		  void initialize_core_grid() {
			  for (int i = 0; i < 5; ++i) {
				  for (int j = 0; j < 5; ++j) {
					  SetValue(i, j, '0');
				  }
			  }
		  }
		  bool winner() {
			  // diagonal with positive slope handling
			  for (int i = n_rows - 1; i >= 0; i--) {
				  for (int j = n_cols - 1; j >= 0; j--) {

					  if (j + 3 <= n_cols && i - 3 >= 0)
					  {
						  if (GetValue(i, j) && (GetValue(i - 1, j + 1) & GetValue(i - 2, j + 2) & GetValue(i - 3, j + 3)) == GetValue(i, j)) // handle one diagonal 
							  return true; // Found a diagonal match with positive slope
					  }

				  }
			  }

			  // verticall handling
			  for (int i = 0; i < 3; i++)
			  {
				  for (int j = 0; j < n_cols; j++) {
					  if (GetValue(i, j) && (GetValue(i + 1, j) & GetValue(i + 2, j) & GetValue(i + 3, j)) == GetValue(i, j))
						  return true;
				  }
			  }

			  // Horizontal handling
			  for (int i = 0; i < n_rows; i++) {
				  for (int j = 0; j < 4; j++) {

					  if (GetValue(i, j) && (GetValue(i, j + 1) & GetValue(i, j + 2) & GetValue(i, j + 3)) == GetValue(i, j)) // handle Horizontal
						  return true;
				  }
			  }

			  // diagonal with a negative slope handling
			  for (int i = 0; i < 3; i++) {
				  for (int j = 0; j < 4; j++) {

					  if (GetValue(i, j) && (GetValue(i + 1, j + 1) & GetValue(i + 2, j + 2) & GetValue(i + 3, j + 3)) == GetValue(i, j))
						  return true; // Found a diagonal match with negative slope
				  }
			  }

			  return false; // No winner
		  }
		  void print_winner(int player_turn) {
			  if (player_turn){
				  player_turn = 0;
			  } else {
				  player_turn = 1;
			  }
			  System::String^ message_winner = gameSetup.players_names[player_turn] + " is the Winner :)";
			  MessageBox::Show(message_winner); // Show a message box


			  this->Close();  // Close the form
		  }
		  void update_status() {
			  if (winner()) {
				  print_winner(player_turn - 1);
			  }
		  }


		  void InitializeComponent(void)
		  {
			  System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			  this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			  this->label8 = (gcnew System::Windows::Forms::Label());
			  this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			  this->button1 = (gcnew System::Windows::Forms::Button());
			  this->_0_btn = (gcnew System::Windows::Forms::Button());
			  this->_1_btn = (gcnew System::Windows::Forms::Button());
			  this->_3_btn = (gcnew System::Windows::Forms::Button());
			  this->_2_btn = (gcnew System::Windows::Forms::Button());
			  this->_6_btn = (gcnew System::Windows::Forms::Button());
			  this->_5_btn = (gcnew System::Windows::Forms::Button());
			  this->_4_btn = (gcnew System::Windows::Forms::Button());
			  this->btn_1_0 = (gcnew System::Windows::Forms::Button());
			  this->btn_3_0 = (gcnew System::Windows::Forms::Button());
			  this->btn_2_0 = (gcnew System::Windows::Forms::Button());
			  this->btn_5_0 = (gcnew System::Windows::Forms::Button());
			  this->btn_4_0 = (gcnew System::Windows::Forms::Button());
			  this->btn_0_0 = (gcnew System::Windows::Forms::Button());
			  this->btn_0_1 = (gcnew System::Windows::Forms::Button());
			  this->btn_5_1 = (gcnew System::Windows::Forms::Button());
			  this->btn_4_1 = (gcnew System::Windows::Forms::Button());
			  this->btn_3_1 = (gcnew System::Windows::Forms::Button());
			  this->btn_2_1 = (gcnew System::Windows::Forms::Button());
			  this->btn_1_1 = (gcnew System::Windows::Forms::Button());
			  this->btn_0_2 = (gcnew System::Windows::Forms::Button());
			  this->btn_5_2 = (gcnew System::Windows::Forms::Button());
			  this->btn_4_2 = (gcnew System::Windows::Forms::Button());
			  this->btn_3_2 = (gcnew System::Windows::Forms::Button());
			  this->btn_2_2 = (gcnew System::Windows::Forms::Button());
			  this->btn_1_2 = (gcnew System::Windows::Forms::Button());
			  this->btn_0_3 = (gcnew System::Windows::Forms::Button());
			  this->btn_5_3 = (gcnew System::Windows::Forms::Button());
			  this->btn_4_3 = (gcnew System::Windows::Forms::Button());
			  this->btn_3_3 = (gcnew System::Windows::Forms::Button());
			  this->btn_2_3 = (gcnew System::Windows::Forms::Button());
			  this->btn_1_3 = (gcnew System::Windows::Forms::Button());
			  this->btn_0_4 = (gcnew System::Windows::Forms::Button());
			  this->btn_5_4 = (gcnew System::Windows::Forms::Button());
			  this->btn_4_4 = (gcnew System::Windows::Forms::Button());
			  this->btn_3_4 = (gcnew System::Windows::Forms::Button());
			  this->btn_2_4 = (gcnew System::Windows::Forms::Button());
			  this->btn_1_4 = (gcnew System::Windows::Forms::Button());
			  this->btn_0_5 = (gcnew System::Windows::Forms::Button());
			  this->btn_5_5 = (gcnew System::Windows::Forms::Button());
			  this->btn_4_5 = (gcnew System::Windows::Forms::Button());
			  this->btn_3_5 = (gcnew System::Windows::Forms::Button());
			  this->btn_2_5 = (gcnew System::Windows::Forms::Button());
			  this->btn_1_5 = (gcnew System::Windows::Forms::Button());
			  this->btn_0_6 = (gcnew System::Windows::Forms::Button());
			  this->btn_5_6 = (gcnew System::Windows::Forms::Button());
			  this->btn_4_6 = (gcnew System::Windows::Forms::Button());
			  this->btn_3_6 = (gcnew System::Windows::Forms::Button());
			  this->btn_2_6 = (gcnew System::Windows::Forms::Button());
			  this->btn_1_6 = (gcnew System::Windows::Forms::Button());
			  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			  this->SuspendLayout();
			  // 
			  // pictureBox1
			  // 
			  this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
			  this->pictureBox1->Image = System::Drawing::Image::FromFile("six_by_seven_Grid.jpg");
			  this->pictureBox1->Location = System::Drawing::Point(140, 99);
			  this->pictureBox1->Name = L"pictureBox1";
			  this->pictureBox1->Size = System::Drawing::Size(484, 315);
			  this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			  this->pictureBox1->TabIndex = 0;
			  this->pictureBox1->TabStop = false;
			  // 
			  // label8
			  // 
			  this->label8->AutoSize = true;
			  this->label8->Location = System::Drawing::Point(53, 28);
			  this->label8->Name = L"label8";
			  this->label8->Size = System::Drawing::Size(159, 13);
			  this->label8->TabIndex = 8;
			  this->label8->Text = L"Enter the name of the first player";
			  // 
			  // textBox1
			  // 
			  this->textBox1->Location = System::Drawing::Point(56, 44);
			  this->textBox1->Name = L"textBox1";
			  this->textBox1->Size = System::Drawing::Size(146, 20);
			  this->textBox1->TabIndex = 9;
			  //this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox1_TextChanged);
			  // 
			  // button1
			  // 
			  this->button1->Location = System::Drawing::Point(56, 70);
			  this->button1->Name = L"button1";
			  this->button1->Size = System::Drawing::Size(75, 23);
			  this->button1->TabIndex = 10;
			  this->button1->Text = L"Submit";
			  this->button1->UseVisualStyleBackColor = true;
			  this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			  // 
			  // _0_btn
			  // 
			  this->_0_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			  this->_0_btn->Location = System::Drawing::Point(180, 70);
			  this->_0_btn->Name = L"_0_btn";
			  this->_0_btn->Size = System::Drawing::Size(27, 23);
			  this->_0_btn->TabIndex = 11;
			  this->_0_btn->Text = L"0";
			  this->_0_btn->UseVisualStyleBackColor = true;
			  this->_0_btn->Click += gcnew System::EventHandler(this, &MyForm1::_0_btn_Click);
			  // 
			  // _1_btn
			  // 
			  this->_1_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			  this->_1_btn->Location = System::Drawing::Point(241, 70);
			  this->_1_btn->Name = L"_1_btn";
			  this->_1_btn->Size = System::Drawing::Size(27, 23);
			  this->_1_btn->TabIndex = 12;
			  this->_1_btn->Text = L"1";
			  this->_1_btn->UseVisualStyleBackColor = true;
			  this->_1_btn->Click += gcnew System::EventHandler(this, &MyForm1::_1_btn_Click);
			  // 
			  // _3_btn
			  // 
			  this->_3_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			  this->_3_btn->Location = System::Drawing::Point(369, 70);
			  this->_3_btn->Name = L"_3_btn";
			  this->_3_btn->Size = System::Drawing::Size(27, 23);
			  this->_3_btn->TabIndex = 14;
			  this->_3_btn->Text = L"3";
			  this->_3_btn->UseVisualStyleBackColor = true;
			  this->_3_btn->Click += gcnew System::EventHandler(this, &MyForm1::_3_btn_Click);
			  // 
			  // _2_btn
			  // 
			  this->_2_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			  this->_2_btn->Location = System::Drawing::Point(304, 70);
			  this->_2_btn->Name = L"_2_btn";
			  this->_2_btn->Size = System::Drawing::Size(27, 23);
			  this->_2_btn->TabIndex = 13;
			  this->_2_btn->Text = L"2";
			  this->_2_btn->UseVisualStyleBackColor = true;
			  this->_2_btn->Click += gcnew System::EventHandler(this, &MyForm1::_2_btn_Click);
			  // 
			  // _6_btn
			  // 
			  this->_6_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			  this->_6_btn->Location = System::Drawing::Point(555, 70);
			  this->_6_btn->Name = L"_6_btn";
			  this->_6_btn->Size = System::Drawing::Size(27, 23);
			  this->_6_btn->TabIndex = 16;
			  this->_6_btn->Text = L"6";
			  this->_6_btn->UseVisualStyleBackColor = true;
			  this->_6_btn->Click += gcnew System::EventHandler(this, &MyForm1::_6_btn_Click);
			  // 
			  // _5_btn
			  // 
			  this->_5_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			  this->_5_btn->Location = System::Drawing::Point(493, 70);
			  this->_5_btn->Name = L"_5_btn";
			  this->_5_btn->Size = System::Drawing::Size(27, 23);
			  this->_5_btn->TabIndex = 15;
			  this->_5_btn->Text = L"5";
			  this->_5_btn->UseVisualStyleBackColor = true;
			  this->_5_btn->Click += gcnew System::EventHandler(this, &MyForm1::_5_btn_Click);
			  // 
			  // _4_btn
			  // 
			  this->_4_btn->Anchor = System::Windows::Forms::AnchorStyles::None;
			  this->_4_btn->Location = System::Drawing::Point(432, 70);
			  this->_4_btn->Name = L"_4_btn";
			  this->_4_btn->Size = System::Drawing::Size(27, 23);
			  this->_4_btn->TabIndex = 17;
			  this->_4_btn->Text = L"4";
			  this->_4_btn->UseVisualStyleBackColor = true;
			  this->_4_btn->Click += gcnew System::EventHandler(this, &MyForm1::_4_btn_Click);
			  // 
			  // btn_1_0
			  // 
			  this->btn_1_0->Location = System::Drawing::Point(171, 167);
			  this->btn_1_0->Name = L"btn_1_0";
			  this->btn_1_0->Size = System::Drawing::Size(48, 37);
			  this->btn_1_0->TabIndex = 19;
			  this->btn_1_0->UseVisualStyleBackColor = true;
			  // 
			  // btn_3_0
			  // 
			  this->btn_3_0->Location = System::Drawing::Point(171, 262);
			  this->btn_3_0->Name = L"btn_3_0";
			  this->btn_3_0->Size = System::Drawing::Size(48, 37);
			  this->btn_3_0->TabIndex = 21;
			  this->btn_3_0->UseVisualStyleBackColor = true;
			  // 
			  // btn_2_0
			  // 
			  this->btn_2_0->Location = System::Drawing::Point(171, 215);
			  this->btn_2_0->Name = L"btn_2_0";
			  this->btn_2_0->Size = System::Drawing::Size(48, 37);
			  this->btn_2_0->TabIndex = 20;
			  this->btn_2_0->UseVisualStyleBackColor = true;
			  // 
			  // btn_5_0
			  // 
			  this->btn_5_0->Location = System::Drawing::Point(171, 352);
			  this->btn_5_0->Name = L"btn_5_0";
			  this->btn_5_0->Size = System::Drawing::Size(48, 37);
			  this->btn_5_0->TabIndex = 23;
			  this->btn_5_0->UseVisualStyleBackColor = true;
			  // 
			  // btn_4_0
			  // 
			  this->btn_4_0->Location = System::Drawing::Point(171, 305);
			  this->btn_4_0->Name = L"btn_4_0";
			  this->btn_4_0->Size = System::Drawing::Size(48, 37);
			  this->btn_4_0->TabIndex = 22;
			  this->btn_4_0->UseVisualStyleBackColor = true;
			  // 
			  // btn_0_0
			  // 
			  this->btn_0_0->Location = System::Drawing::Point(171, 121);
			  this->btn_0_0->Name = L"btn_0_0";
			  this->btn_0_0->Size = System::Drawing::Size(48, 37);
			  this->btn_0_0->TabIndex = 24;
			  this->btn_0_0->UseVisualStyleBackColor = true;
			  // 
			  // btn_0_1
			  // 
			  this->btn_0_1->Location = System::Drawing::Point(234, 121);
			  this->btn_0_1->Name = L"btn_0_1";
			  this->btn_0_1->Size = System::Drawing::Size(48, 37);
			  this->btn_0_1->TabIndex = 30;
			  this->btn_0_1->UseVisualStyleBackColor = true;
			  // 
			  // btn_5_1
			  // 
			  this->btn_5_1->Location = System::Drawing::Point(234, 352);
			  this->btn_5_1->Name = L"btn_5_1";
			  this->btn_5_1->Size = System::Drawing::Size(48, 37);
			  this->btn_5_1->TabIndex = 29;
			  this->btn_5_1->UseVisualStyleBackColor = true;
			  // 
			  // btn_4_1
			  // 
			  this->btn_4_1->Location = System::Drawing::Point(234, 305);
			  this->btn_4_1->Name = L"btn_4_1";
			  this->btn_4_1->Size = System::Drawing::Size(48, 37);
			  this->btn_4_1->TabIndex = 28;
			  this->btn_4_1->UseVisualStyleBackColor = true;
			  // 
			  // btn_3_1
			  // 
			  this->btn_3_1->Location = System::Drawing::Point(234, 262);
			  this->btn_3_1->Name = L"btn_3_1";
			  this->btn_3_1->Size = System::Drawing::Size(48, 37);
			  this->btn_3_1->TabIndex = 27;
			  this->btn_3_1->UseVisualStyleBackColor = true;
			  // 
			  // btn_2_1
			  // 
			  this->btn_2_1->Location = System::Drawing::Point(234, 215);
			  this->btn_2_1->Name = L"btn_2_1";
			  this->btn_2_1->Size = System::Drawing::Size(48, 37);
			  this->btn_2_1->TabIndex = 26;
			  this->btn_2_1->UseVisualStyleBackColor = true;
			  // 
			  // btn_1_1
			  // 
			  this->btn_1_1->Location = System::Drawing::Point(234, 167);
			  this->btn_1_1->Name = L"btn_1_1";
			  this->btn_1_1->Size = System::Drawing::Size(48, 37);
			  this->btn_1_1->TabIndex = 25;
			  this->btn_1_1->UseVisualStyleBackColor = true;
			  // 
			  // btn_0_2
			  // 
			  this->btn_0_2->Location = System::Drawing::Point(298, 121);
			  this->btn_0_2->Name = L"btn_0_2";
			  this->btn_0_2->Size = System::Drawing::Size(48, 37);
			  this->btn_0_2->TabIndex = 36;
			  this->btn_0_2->UseVisualStyleBackColor = true;
			  // 
			  // btn_5_2
			  // 
			  this->btn_5_2->Location = System::Drawing::Point(298, 352);
			  this->btn_5_2->Name = L"btn_5_2";
			  this->btn_5_2->Size = System::Drawing::Size(48, 37);
			  this->btn_5_2->TabIndex = 35;
			  this->btn_5_2->UseVisualStyleBackColor = true;
			  // 
			  // btn_4_2
			  // 
			  this->btn_4_2->Location = System::Drawing::Point(298, 305);
			  this->btn_4_2->Name = L"btn_4_2";
			  this->btn_4_2->Size = System::Drawing::Size(48, 37);
			  this->btn_4_2->TabIndex = 34;
			  this->btn_4_2->UseVisualStyleBackColor = true;
			  // 
			  // btn_3_2
			  // 
			  this->btn_3_2->Location = System::Drawing::Point(298, 262);
			  this->btn_3_2->Name = L"btn_3_2";
			  this->btn_3_2->Size = System::Drawing::Size(48, 37);
			  this->btn_3_2->TabIndex = 33;
			  this->btn_3_2->UseVisualStyleBackColor = true;
			  // 
			  // btn_2_2
			  // 
			  this->btn_2_2->Location = System::Drawing::Point(297, 215);
			  this->btn_2_2->Name = L"btn_2_2";
			  this->btn_2_2->Size = System::Drawing::Size(48, 37);
			  this->btn_2_2->TabIndex = 32;
			  this->btn_2_2->UseVisualStyleBackColor = true;
			  // 
			  // btn_1_2
			  // 
			  this->btn_1_2->Location = System::Drawing::Point(298, 167);
			  this->btn_1_2->Name = L"btn_1_2";
			  this->btn_1_2->Size = System::Drawing::Size(48, 37);
			  this->btn_1_2->TabIndex = 31;
			  this->btn_1_2->UseVisualStyleBackColor = true;
			  // 
			  // btn_0_3
			  // 
			  this->btn_0_3->Location = System::Drawing::Point(357, 121);
			  this->btn_0_3->Name = L"btn_0_3";
			  this->btn_0_3->Size = System::Drawing::Size(48, 37);
			  this->btn_0_3->TabIndex = 42;
			  this->btn_0_3->UseVisualStyleBackColor = true;
			  // 
			  // btn_5_3
			  // 
			  this->btn_5_3->Location = System::Drawing::Point(357, 352);
			  this->btn_5_3->Name = L"btn_5_3";
			  this->btn_5_3->Size = System::Drawing::Size(48, 37);
			  this->btn_5_3->TabIndex = 41;
			  this->btn_5_3->UseVisualStyleBackColor = true;
			  // 
			  // btn_4_3
			  // 
			  this->btn_4_3->Location = System::Drawing::Point(357, 305);
			  this->btn_4_3->Name = L"btn_4_3";
			  this->btn_4_3->Size = System::Drawing::Size(48, 37);
			  this->btn_4_3->TabIndex = 40;
			  this->btn_4_3->UseVisualStyleBackColor = true;
			  // 
			  // btn_3_3
			  // 
			  this->btn_3_3->Location = System::Drawing::Point(357, 262);
			  this->btn_3_3->Name = L"btn_3_3";
			  this->btn_3_3->Size = System::Drawing::Size(48, 37);
			  this->btn_3_3->TabIndex = 39;
			  this->btn_3_3->UseVisualStyleBackColor = true;
			  // 
			  // btn_2_3
			  // 
			  this->btn_2_3->Location = System::Drawing::Point(357, 215);
			  this->btn_2_3->Name = L"btn_2_3";
			  this->btn_2_3->Size = System::Drawing::Size(48, 37);
			  this->btn_2_3->TabIndex = 38;
			  this->btn_2_3->UseVisualStyleBackColor = true;
			  // 
			  // btn_1_3
			  // 
			  this->btn_1_3->Location = System::Drawing::Point(357, 167);
			  this->btn_1_3->Name = L"btn_1_3";
			  this->btn_1_3->Size = System::Drawing::Size(48, 37);
			  this->btn_1_3->TabIndex = 37;
			  this->btn_1_3->UseVisualStyleBackColor = true;
			  // 
			  // btn_0_4
			  // 
			  this->btn_0_4->Location = System::Drawing::Point(422, 122);
			  this->btn_0_4->Name = L"btn_0_4";
			  this->btn_0_4->Size = System::Drawing::Size(48, 37);
			  this->btn_0_4->TabIndex = 48;
			  this->btn_0_4->UseVisualStyleBackColor = true;
			  // 
			  // btn_5_4
			  // 
			  this->btn_5_4->Location = System::Drawing::Point(422, 353);
			  this->btn_5_4->Name = L"btn_5_4";
			  this->btn_5_4->Size = System::Drawing::Size(48, 37);
			  this->btn_5_4->TabIndex = 47;
			  this->btn_5_4->UseVisualStyleBackColor = true;
			  // 
			  // btn_4_4
			  // 
			  this->btn_4_4->Location = System::Drawing::Point(422, 306);
			  this->btn_4_4->Name = L"btn_4_4";
			  this->btn_4_4->Size = System::Drawing::Size(48, 37);
			  this->btn_4_4->TabIndex = 46;
			  this->btn_4_4->UseVisualStyleBackColor = true;
			  // 
			  // btn_3_4
			  // 
			  this->btn_3_4->Location = System::Drawing::Point(422, 263);
			  this->btn_3_4->Name = L"btn_3_4";
			  this->btn_3_4->Size = System::Drawing::Size(48, 37);
			  this->btn_3_4->TabIndex = 45;
			  this->btn_3_4->UseVisualStyleBackColor = true;
			  // 
			  // btn_2_4
			  // 
			  this->btn_2_4->Location = System::Drawing::Point(422, 216);
			  this->btn_2_4->Name = L"btn_2_4";
			  this->btn_2_4->Size = System::Drawing::Size(48, 37);
			  this->btn_2_4->TabIndex = 44;
			  this->btn_2_4->UseVisualStyleBackColor = true;
			  // 
			  // btn_1_4
			  // 
			  this->btn_1_4->Location = System::Drawing::Point(422, 168);
			  this->btn_1_4->Name = L"btn_1_4";
			  this->btn_1_4->Size = System::Drawing::Size(48, 37);
			  this->btn_1_4->TabIndex = 43;
			  this->btn_1_4->UseVisualStyleBackColor = true;
			  // 
			  // btn_0_5
			  // 
			  this->btn_0_5->Location = System::Drawing::Point(484, 122);
			  this->btn_0_5->Name = L"btn_0_5";
			  this->btn_0_5->Size = System::Drawing::Size(48, 37);
			  this->btn_0_5->TabIndex = 54;
			  this->btn_0_5->UseVisualStyleBackColor = true;
			  // 
			  // btn_5_5
			  // 
			  this->btn_5_5->Location = System::Drawing::Point(484, 353);
			  this->btn_5_5->Name = L"btn_5_5";
			  this->btn_5_5->Size = System::Drawing::Size(48, 37);
			  this->btn_5_5->TabIndex = 53;
			  this->btn_5_5->UseVisualStyleBackColor = true;
			  // 
			  // btn_4_5
			  // 
			  this->btn_4_5->Location = System::Drawing::Point(484, 306);
			  this->btn_4_5->Name = L"btn_4_5";
			  this->btn_4_5->Size = System::Drawing::Size(48, 37);
			  this->btn_4_5->TabIndex = 52;
			  this->btn_4_5->UseVisualStyleBackColor = true;
			  // 
			  // btn_3_5
			  // 
			  this->btn_3_5->Location = System::Drawing::Point(484, 263);
			  this->btn_3_5->Name = L"btn_3_5";
			  this->btn_3_5->Size = System::Drawing::Size(48, 37);
			  this->btn_3_5->TabIndex = 51;
			  this->btn_3_5->UseVisualStyleBackColor = true;
			  // 
			  // btn_2_5
			  // 
			  this->btn_2_5->Location = System::Drawing::Point(484, 216);
			  this->btn_2_5->Name = L"btn_2_5";
			  this->btn_2_5->Size = System::Drawing::Size(48, 37);
			  this->btn_2_5->TabIndex = 50;
			  this->btn_2_5->UseVisualStyleBackColor = true;
			  // 
			  // btn_1_5
			  // 
			  this->btn_1_5->Location = System::Drawing::Point(484, 168);
			  this->btn_1_5->Name = L"btn_1_5";
			  this->btn_1_5->Size = System::Drawing::Size(48, 37);
			  this->btn_1_5->TabIndex = 49;
			  this->btn_1_5->UseVisualStyleBackColor = true;
			  // 
			  // btn_0_6
			  // 
			  this->btn_0_6->Location = System::Drawing::Point(545, 123);
			  this->btn_0_6->Name = L"btn_0_6";
			  this->btn_0_6->Size = System::Drawing::Size(48, 37);
			  this->btn_0_6->TabIndex = 60;
			  this->btn_0_6->UseVisualStyleBackColor = true;
			  // 
			  // btn_5_6
			  // 
			  this->btn_5_6->Location = System::Drawing::Point(545, 354);
			  this->btn_5_6->Name = L"btn_5_6";
			  this->btn_5_6->Size = System::Drawing::Size(48, 37);
			  this->btn_5_6->TabIndex = 59;
			  this->btn_5_6->UseVisualStyleBackColor = true;
			  // 
			  // btn_4_6
			  // 
			  this->btn_4_6->Location = System::Drawing::Point(545, 307);
			  this->btn_4_6->Name = L"btn_4_6";
			  this->btn_4_6->Size = System::Drawing::Size(48, 37);
			  this->btn_4_6->TabIndex = 58;
			  this->btn_4_6->UseVisualStyleBackColor = true;
			  // 
			  // btn_3_6
			  // 
			  this->btn_3_6->Location = System::Drawing::Point(545, 264);
			  this->btn_3_6->Name = L"btn_3_6";
			  this->btn_3_6->Size = System::Drawing::Size(48, 37);
			  this->btn_3_6->TabIndex = 57;
			  this->btn_3_6->UseVisualStyleBackColor = true;
			  // 
			  // btn_2_6
			  // 
			  this->btn_2_6->Location = System::Drawing::Point(544, 217);
			  this->btn_2_6->Name = L"btn_2_6";
			  this->btn_2_6->Size = System::Drawing::Size(48, 37);
			  this->btn_2_6->TabIndex = 56;
			  this->btn_2_6->UseVisualStyleBackColor = true;
			  // 
			  // btn_1_6
			  // 
			  this->btn_1_6->Location = System::Drawing::Point(545, 169);
			  this->btn_1_6->Name = L"btn_1_6";
			  this->btn_1_6->Size = System::Drawing::Size(48, 37);
			  this->btn_1_6->TabIndex = 55;
			  this->btn_1_6->UseVisualStyleBackColor = true;
			  // 
			  // MyForm1
			  // 
			  this->ClientSize = System::Drawing::Size(800, 500);
			  this->Controls->Add(this->btn_0_6);
			  this->Controls->Add(this->btn_5_6);
			  this->Controls->Add(this->btn_4_6);
			  this->Controls->Add(this->btn_3_6);
			  this->Controls->Add(this->btn_2_6);
			  this->Controls->Add(this->btn_1_6);
			  this->Controls->Add(this->btn_0_5);
			  this->Controls->Add(this->btn_5_5);
			  this->Controls->Add(this->btn_4_5);
			  this->Controls->Add(this->btn_3_5);
			  this->Controls->Add(this->btn_2_5);
			  this->Controls->Add(this->btn_1_5);
			  this->Controls->Add(this->btn_0_4);
			  this->Controls->Add(this->btn_5_4);
			  this->Controls->Add(this->btn_4_4);
			  this->Controls->Add(this->btn_3_4);
			  this->Controls->Add(this->btn_2_4);
			  this->Controls->Add(this->btn_1_4);
			  this->Controls->Add(this->btn_0_3);
			  this->Controls->Add(this->btn_5_3);
			  this->Controls->Add(this->btn_4_3);
			  this->Controls->Add(this->btn_3_3);
			  this->Controls->Add(this->btn_2_3);
			  this->Controls->Add(this->btn_1_3);
			  this->Controls->Add(this->btn_0_2);
			  this->Controls->Add(this->btn_5_2);
			  this->Controls->Add(this->btn_4_2);
			  this->Controls->Add(this->btn_3_2);
			  this->Controls->Add(this->btn_2_2);
			  this->Controls->Add(this->btn_1_2);
			  this->Controls->Add(this->btn_0_1);
			  this->Controls->Add(this->btn_5_1);
			  this->Controls->Add(this->btn_4_1);
			  this->Controls->Add(this->btn_3_1);
			  this->Controls->Add(this->btn_2_1);
			  this->Controls->Add(this->btn_1_1);
			  this->Controls->Add(this->btn_0_0);
			  this->Controls->Add(this->btn_5_0);
			  this->Controls->Add(this->btn_4_0);
			  this->Controls->Add(this->btn_3_0);
			  this->Controls->Add(this->btn_2_0);
			  this->Controls->Add(this->btn_1_0);
			  this->Controls->Add(this->_4_btn);
			  this->Controls->Add(this->_6_btn);
			  this->Controls->Add(this->_5_btn);
			  this->Controls->Add(this->_3_btn);
			  this->Controls->Add(this->_2_btn);
			  this->Controls->Add(this->_1_btn);
			  this->Controls->Add(this->_0_btn);
			  this->Controls->Add(this->button1);
			  this->Controls->Add(this->textBox1);
			  this->Controls->Add(this->label8);
			  this->Controls->Add(this->pictureBox1);
			  this->Name = L"MyForm1";
			  this->Text = L"Connect Four";
			  //this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			  this->Resize += gcnew System::EventHandler(this, &MyForm1::MyForm1_Resize);
			  (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			  this->ResumeLayout(false);
			  this->PerformLayout();

		  }

		  //---------------------------- PLAYERS TURNS and SYMBOLS ---------------------------- 
		  ref class CoreEngine {
		  public:
			  array<System::String^>^ players_names ;
			  array<System::String^>^ symbols;
			  array<char>^ symbols_CHAR;

			  CoreEngine(){
				  players_names = gcnew array<System::String^>(2) { "Player1", "Player2" };
				  symbols = gcnew array<System::String^>(2) { "X", "O" };
				  symbols_CHAR = gcnew array<char>(2) { 'X', 'O' };
			  }
		  };

		  CoreEngine gameSetup;
		  
		  int player_turn = 0;
		  void next_turn() {
			  if (player_turn) {
				  player_turn = 0;
			  }
			  else {
				  player_turn = 1;
			  }
		  }


		  // Handle the form's resize event to re-center the image when the form size changes
		  System::Void MyForm1_Resize(System::Object^ sender, System::EventArgs^ e)
		  {

		  }

		  // Game movements

	private: System::Void _0_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		if (btn_5_0->Text == "" && n_moves < 42) {

			btn_5_0->Text = gameSetup.symbols[player_turn];
			SetValue(5, 0, gameSetup.symbols_CHAR[player_turn]);

			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_0->Text != "" && btn_4_0->Text == "" && n_moves < 42) {

			btn_4_0->Text = gameSetup.symbols[player_turn];
			SetValue(4, 0, gameSetup.symbols_CHAR[player_turn]);

			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_0->Text != "" && btn_4_0->Text != "" && btn_3_0->Text == "" && n_moves < 42) {
			btn_3_0->Text = gameSetup.symbols[player_turn];
			SetValue(3, 0, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_0->Text != "" && btn_4_0->Text != "" && btn_3_0->Text != "" && btn_2_0->Text == "" && n_moves < 42) {
			btn_2_0->Text = gameSetup.symbols[player_turn];
			SetValue(2, 0, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_0->Text != "" && btn_4_0->Text != "" && btn_3_0->Text != "" && btn_2_0->Text != "" && btn_1_0->Text == "" && n_moves < 42) {
			btn_1_0->Text = gameSetup.symbols[player_turn];
			SetValue(1, 0, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_0->Text != "" && btn_4_0->Text != "" && btn_3_0->Text != "" && btn_2_0->Text != "" && btn_1_0->Text != "" && btn_0_0->Text == "" && n_moves < 42) {
			btn_0_0->Text = gameSetup.symbols[player_turn];
			SetValue(0, 0, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else {

		}
	}
	private: System::Void _1_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		if (btn_5_1->Text == "" && n_moves < 42) {
			btn_5_1->Text = gameSetup.symbols[player_turn];
			SetValue(5, 1, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_1->Text != "" && btn_4_1->Text == "" && n_moves < 42) {
			btn_4_1->Text = gameSetup.symbols[player_turn];
			SetValue(4, 1, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_1->Text != "" && btn_4_1->Text != "" && btn_3_1->Text == "" && n_moves < 42) {
			btn_3_1->Text = gameSetup.symbols[player_turn];
			SetValue(3, 1, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_1->Text != "" && btn_4_1->Text != "" && btn_3_1->Text != "" && btn_2_1->Text == "" && n_moves < 42) {
			btn_2_1->Text = gameSetup.symbols[player_turn];
			SetValue(2, 1, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_1->Text != "" && btn_4_1->Text != "" && btn_3_1->Text != "" && btn_2_1->Text != "" && btn_1_1->Text == "" && n_moves < 42) {
			btn_1_1->Text = gameSetup.symbols[player_turn];
			SetValue(1, 1, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_1->Text != "" && btn_4_1->Text != "" && btn_3_1->Text != "" && btn_2_1->Text != "" && btn_1_1->Text != "" && btn_0_1->Text == "" && n_moves < 42) {
			btn_0_1->Text = gameSetup.symbols[player_turn];
			SetValue(0, 1, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();
		}
		else {

		}
	}
	private: System::Void _2_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn_5_2->Text == "" && n_moves < 42) {
			btn_5_2->Text = gameSetup.symbols[player_turn];
			SetValue(5, 2, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_2->Text != "" && btn_4_2->Text == "" && n_moves < 42) {
			btn_4_2->Text = gameSetup.symbols[player_turn];
			SetValue(4, 2, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_2->Text != "" && btn_4_2->Text != "" && btn_3_2->Text == "" && n_moves < 42) {
			btn_3_2->Text = gameSetup.symbols[player_turn];
			SetValue(3, 2, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_2->Text != "" && btn_4_2->Text != "" && btn_3_2->Text != "" && btn_2_2->Text == "" && n_moves < 42) {
			btn_2_2->Text = gameSetup.symbols[player_turn];
			SetValue(2, 2, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_2->Text != "" && btn_4_2->Text != "" && btn_3_2->Text != "" && btn_2_2->Text != "" && btn_1_2->Text == "" && n_moves < 42) {
			btn_1_2->Text = gameSetup.symbols[player_turn];
			SetValue(1, 2, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();
		}
		else if (btn_5_2->Text != "" && btn_4_2->Text != "" && btn_3_2->Text != "" && btn_2_2->Text != "" && btn_1_2->Text != "" && btn_0_2->Text == "" && n_moves < 42) {
			btn_0_2->Text = gameSetup.symbols[player_turn];
			SetValue(0, 2, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();
		}
		else {

		}
	}
	private: System::Void _3_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn_5_3->Text == "" && n_moves < 42) {
			btn_5_3->Text = gameSetup.symbols[player_turn];
			SetValue(5, 3, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_3->Text != "" && btn_4_3->Text == "" && n_moves < 42) {
			btn_4_3->Text = gameSetup.symbols[player_turn];
			SetValue(4, 3, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_3->Text != "" && btn_4_3->Text != "" && btn_3_3->Text == "" && n_moves < 42) {
			btn_3_3->Text = gameSetup.symbols[player_turn];
			SetValue(3, 3, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_3->Text != "" && btn_4_3->Text != "" && btn_3_3->Text != "" && btn_2_3->Text == "" && n_moves < 42) {
			btn_2_3->Text = gameSetup.symbols[player_turn];
			SetValue(2, 3, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_3->Text != "" && btn_4_3->Text != "" && btn_3_3->Text != "" && btn_2_3->Text != "" && btn_1_3->Text == "" && n_moves < 42) {
			btn_1_3->Text = gameSetup.symbols[player_turn];
			SetValue(1, 3, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_3->Text != "" && btn_4_3->Text != "" && btn_3_3->Text != "" && btn_2_3->Text != "" && btn_1_3->Text != "" && btn_0_3->Text == "" && n_moves < 42) {
			btn_0_3->Text = gameSetup.symbols[player_turn];
			SetValue(0, 3, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();
		}
		else {

		}
	}

	private: System::Void _4_btn_Click(System::Object^ sender, System::EventArgs^ e) {

		if (btn_5_4->Text == "" && n_moves < 42) {
			btn_5_4->Text = gameSetup.symbols[player_turn];
			SetValue(5, 4, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_4->Text != "" && btn_4_4->Text == "" && n_moves < 42) {
			btn_4_4->Text = gameSetup.symbols[player_turn];
			SetValue(4, 4, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_4->Text != "" && btn_4_4->Text != "" && btn_3_4->Text == "" && n_moves < 42) {
			btn_3_4->Text = gameSetup.symbols[player_turn];
			SetValue(3, 4, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_4->Text != "" && btn_4_4->Text != "" && btn_3_4->Text != "" && btn_2_4->Text == "" && n_moves < 42) {
			btn_2_4->Text = gameSetup.symbols[player_turn];
			SetValue(2, 4, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_4->Text != "" && btn_4_4->Text != "" && btn_3_4->Text != "" && btn_2_4->Text != "" && btn_1_4->Text == "" && n_moves < 42) {
			btn_1_4->Text = gameSetup.symbols[player_turn];
			SetValue(1, 4, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_4->Text != "" && btn_4_4->Text != "" && btn_3_4->Text != "" && btn_2_4->Text != "" && btn_1_4->Text != "" && btn_0_4->Text == "" && n_moves < 42) {
			btn_0_4->Text = gameSetup.symbols[player_turn];
			SetValue(0, 4, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();
		}
		else {

		}
	}
	private: System::Void _5_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn_5_5->Text == "" && n_moves < 42) {
			btn_5_5->Text = gameSetup.symbols[player_turn];
			SetValue(5, 5, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_5->Text != "" && btn_4_5->Text == "" && n_moves < 42) {
			btn_4_5->Text = gameSetup.symbols[player_turn];
			SetValue(4, 5, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_5->Text != "" && btn_4_5->Text != "" && btn_3_5->Text == "" && n_moves < 42) {
			btn_3_5->Text = gameSetup.symbols[player_turn];
			SetValue(3, 5, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_5->Text != "" && btn_4_5->Text != "" && btn_3_5->Text != "" && btn_2_5->Text == "" && n_moves < 42) {
			btn_2_5->Text = gameSetup.symbols[player_turn];
			SetValue(2, 5, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_5->Text != "" && btn_4_5->Text != "" && btn_3_5->Text != "" && btn_2_5->Text != "" && btn_1_5->Text == "" && n_moves < 42) {
			btn_1_5->Text = gameSetup.symbols[player_turn];
			SetValue(1, 5, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_5->Text != "" && btn_4_5->Text != "" && btn_3_5->Text != "" && btn_2_5->Text != "" && btn_1_5->Text != "" && btn_0_5->Text == "" && n_moves < 42) {
			btn_0_5->Text = gameSetup.symbols[player_turn];
			SetValue(0, 5, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();
		}
		else {

		}
	}
	private: System::Void _6_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (btn_5_6->Text == "" && n_moves < 42) {
			btn_5_6->Text = gameSetup.symbols[player_turn];
			SetValue(5, 6, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_6->Text != "" && btn_4_6->Text == "" && n_moves < 42) {
			btn_4_6->Text = gameSetup.symbols[player_turn];
			SetValue(4, 6, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_6->Text != "" && btn_4_6->Text != "" && btn_3_6->Text == "" && n_moves < 42) {
			btn_3_6->Text = gameSetup.symbols[player_turn];
			SetValue(3, 6, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_6->Text != "" && btn_4_6->Text != "" && btn_3_6->Text != "" && btn_2_6->Text == "" && n_moves < 42) {
			btn_2_6->Text = gameSetup.symbols[player_turn];
			SetValue(2, 6, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_6->Text != "" && btn_4_6->Text != "" && btn_3_6->Text != "" && btn_2_6->Text != "" && btn_1_6->Text == "" && n_moves < 42) {
			btn_1_6->Text = gameSetup.symbols[player_turn];
			SetValue(1, 6, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();

		}
		else if (btn_5_6->Text != "" && btn_4_6->Text != "" && btn_3_6->Text != "" && btn_2_6->Text != "" && btn_1_6->Text != "" && btn_0_6->Text == "" && n_moves < 42) {
			btn_0_6->Text = gameSetup.symbols[player_turn];
			SetValue(0, 6, gameSetup.symbols_CHAR[player_turn]);
			next_turn();
			n_moves++;
			update_status();
		}
		else {

		}
	}

		   // Core intialization for the game
		   // 
		   // Submit button
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!isname1taken) {
			player1name = textBox1->Text;
			isname1taken = true;
		}
		else {
			player2name = textBox1->Text;
			label8->Text = player1name + " vs " + player2name + " good luck :)";

		}
		textBox1->Clear();
		label8->Text = "player 2 enter your name";
		initialize_core_grid();
		is_initialized = true;
	}


	};
}
