#pragma once
#include <iostream>
#include "Model.h"

namespace BademV1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for InitBadem
	/// </summary>
	public ref class InitBadem : public System::Windows::Forms::Form
	{
	public:
		InitBadem(void)
		{
			InitializeComponent();
			image = new double[280 * 280];
			img   = new double*[1];
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~InitBadem()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	protected:

	private:
		/// <summary>
		/// Required designer variable.

		double* image; //= new double[280 * 280];
		double** img;

	private: System::Windows::Forms::Button^ button_Resize;
	private: System::Windows::Forms::Label^ labelProbability;
	private: System::Windows::Forms::Label^ labelPredict;


	private: System::Windows::Forms::Button^ button_Predict;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button1_Click;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;







		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->button_Resize = (gcnew System::Windows::Forms::Button());
			   this->labelProbability = (gcnew System::Windows::Forms::Label());
			   this->labelPredict = (gcnew System::Windows::Forms::Label());
			   this->button_Predict = (gcnew System::Windows::Forms::Button());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->button1_Click = (gcnew System::Windows::Forms::Button());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::White;
			   this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->pictureBox1->Location = System::Drawing::Point(3, 3);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(280, 280);
			   this->pictureBox1->TabIndex = 0;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &InitBadem::pictureBox1_MouseMove);
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackColor = System::Drawing::Color::White;
			   this->pictureBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->pictureBox2->Location = System::Drawing::Point(318, 135);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(28, 28);
			   this->pictureBox2->TabIndex = 1;
			   this->pictureBox2->TabStop = false;
			   // 
			   // button_Resize
			   // 
			   this->button_Resize->BackColor = System::Drawing::SystemColors::Control;
			   this->button_Resize->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->button_Resize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->button_Resize->Location = System::Drawing::Point(398, 45);
			   this->button_Resize->Name = L"button_Resize";
			   this->button_Resize->Size = System::Drawing::Size(138, 25);
			   this->button_Resize->TabIndex = 3;
			   this->button_Resize->Text = L"Resize";
			   this->button_Resize->UseVisualStyleBackColor = false;
			   this->button_Resize->Click += gcnew System::EventHandler(this, &InitBadem::button_Resize_Click);
			   // 
			   // labelProbability
			   // 
			   this->labelProbability->AutoSize = true;
			   this->labelProbability->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->labelProbability->Location = System::Drawing::Point(101, 12);
			   this->labelProbability->Name = L"labelProbability";
			   this->labelProbability->Size = System::Drawing::Size(22, 16);
			   this->labelProbability->TabIndex = 4;
			   this->labelProbability->Text = L"- -";
			   // 
			   // labelPredict
			   // 
			   this->labelPredict->AutoSize = true;
			   this->labelPredict->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->labelPredict->Location = System::Drawing::Point(101, 46);
			   this->labelPredict->Name = L"labelPredict";
			   this->labelPredict->Size = System::Drawing::Size(22, 16);
			   this->labelPredict->TabIndex = 5;
			   this->labelPredict->Text = L"- -";
			   // 
			   // button_Predict
			   // 
			   this->button_Predict->BackColor = System::Drawing::SystemColors::Control;
			   this->button_Predict->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->button_Predict->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->button_Predict->Location = System::Drawing::Point(398, 76);
			   this->button_Predict->Name = L"button_Predict";
			   this->button_Predict->Size = System::Drawing::Size(138, 25);
			   this->button_Predict->TabIndex = 6;
			   this->button_Predict->Text = L"Predict";
			   this->button_Predict->UseVisualStyleBackColor = false;
			   this->button_Predict->Click += gcnew System::EventHandler(this, &InitBadem::button_Predict_Click);
			   // 
			   // panel1
			   // 
			   this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel1->Controls->Add(this->panel2);
			   this->panel1->Controls->Add(this->pictureBox1);
			   this->panel1->Controls->Add(this->button_Predict);
			   this->panel1->Controls->Add(this->pictureBox2);
			   this->panel1->Controls->Add(this->button1_Click);
			   this->panel1->Controls->Add(this->button_Resize);
			   this->panel1->Location = System::Drawing::Point(73, 36);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(563, 290);
			   this->panel1->TabIndex = 7;
			   // 
			   // panel2
			   // 
			   this->panel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel2->Controls->Add(this->label4);
			   this->panel2->Controls->Add(this->label3);
			   this->panel2->Controls->Add(this->labelProbability);
			   this->panel2->Controls->Add(this->labelPredict);
			   this->panel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->panel2->Location = System::Drawing::Point(398, 208);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(138, 75);
			   this->panel2->TabIndex = 7;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(4, 46);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(97, 16);
			   this->label4->TabIndex = 7;
			   this->label4->Text = L"Predict        =";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(4, 12);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(99, 16);
			   this->label3->TabIndex = 6;
			   this->label3->Text = L"Probability  =";
			   // 
			   // button1_Click
			   // 
			   this->button1_Click->BackColor = System::Drawing::SystemColors::Control;
			   this->button1_Click->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			   this->button1_Click->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->button1_Click->Location = System::Drawing::Point(398, 14);
			   this->button1_Click->Name = L"button1_Click";
			   this->button1_Click->Size = System::Drawing::Size(138, 25);
			   this->button1_Click->TabIndex = 2;
			   this->button1_Click->Text = L"Init";
			   this->button1_Click->UseVisualStyleBackColor = false;
			   this->button1_Click->Click += gcnew System::EventHandler(this, &InitBadem::button_Init);
			   // 
			   // InitBadem
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::ControlLight;
			   this->ClientSize = System::Drawing::Size(737, 389);
			   this->Controls->Add(this->panel1);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			   this->Name = L"InitBadem";
			   this->Text = L"BADEM";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void button_Init(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Refresh();
		for (int i = 0; i < 280 * 280; i++) 
			image[i] = 255.0;
	}
	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Pen^ pix = gcnew Pen(Color::Black, 2);
		Graphics^ g = pictureBox1->CreateGraphics();
		int x, y;
		x = (int)e->X;
		y = (int)e->Y;

		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			g->DrawRectangle(pix, x, y, 5, 5);
			g->FillRectangle(Brushes::Black, x, y, 5, 5);
			image[y * 280 + x] = 0.0;
		}
	}
	private: System::Void button_Resize_Click(System::Object^ sender, System::EventArgs^ e) {
		Color backround = Color::FromArgb(0, 0, 0);
		Color label = Color::FromArgb(255, 255, 255);
		System::Drawing::Bitmap^ drem = gcnew  System::Drawing::Bitmap(28, 28);

		int row, col;

		img[0] = new double[28 * 28];
		for (int i = 0; i < 28 * 28; i++)
			img[0][i] = 255.0;

		double min = 0.0;
		for (int i = 0; i < 270; i += 10)
		{
			row++;
			col = 0;
			for (int j = 0; j < 270; j += 10)
			{
				col++;
				for (int x = 0; x < 10; x++)
				{
					for (int y = 0; y < 10; y++)
					{
						if ((y + i) > 280 || (x + j) > 280)continue;
						min += image[(i + x) * 280 + j + y];
					}
				}
				img[0][row * 28 + col] = min / 100;
				if (img[0][row * 28 + col] < 255.0) img[0][row * 28 + col] = 0.0;
				min = 0.0;
			}
		}

		for (int i = 0; i < 28; i++)
		{
			for (int j = 0; j < 28; j++)
			{
				if (img[0][i * 28 + j] == 0.0)
				{
					drem->SetPixel(j, i, label);
					img[0][i * 28 + j] = 255.0;
				}
				else {
					drem->SetPixel(j, i, backround);
					img[0][i * 28 + j] = 0.0;
				}
			}
		}

		for (int y = 0; y < 28; y++) {
			for (int x = 0; x < 28; x++) {
				img[0][y * 28 + x] /= 255.0;
			}
		}
		this->pictureBox2->Image = drem;
	}
	private: System::Void button_Predict_Click(System::Object^ sender, System::EventArgs^ e) {
		//std::string image = "D://TASARIM//BademV1.0//MnıstValidBıas//9.txt";
		std::string kernel1 = "D://TASARIM//Badem_Mnıst_Interface//MnıstValidBıas//CNN0.txt";
		std::string kernel2 = "D://TASARIM//Badem_Mnıst_Interface//MnıstValidBıas//CNN1.txt";
		std::string weight1 = "D://TASARIM//Badem_Mnıst_Interface//MnıstValidBıas//FCN0.txt";
		std::string weight2 = "D://TASARIM//Badem_Mnıst_Interface//MnıstValidBıas//FCN1.txt";

		Model m;

		m.setImage(img);
		//m.ReadImageFile(image);
		m.Conv2D(kernel1, "relu", "valid", "true", 1);
		m.Conv2D(kernel2, "relu", "valid", "true", 1);
		m.MaxPooling2D(2);
		m.Flatten();
		m.Dense(weight1, "relu");
		m.Dense(weight2, "softmax");

		labelProbability->Text = Convert::ToString(m.getProbability().ToString("0.##"));
		labelPredict->Text = m.getPredict().ToString();

		////Cifar10
		//std::string image   = "C://Users//poyra//Desktop//Tasarım//TasarimBadem//BademV1.0//Cifar//1.txt";
		//std::string kernel1 = "C://Users//poyra//Desktop//Tasarım//TasarimBadem//BademV1.0//Cifar//CNN0.txt";
		//std::string kernel2 = "C://Users//poyra//Desktop//Tasarım//TasarimBadem//BademV1.0//Cifar//CNN1.txt";
		//std::string weight1 = "C://Users//poyra//Desktop//Tasarım//TasarimBadem//BademV1.0//Cifar//FCN0.txt";
		//std::string weight2 = "C://Users//poyra//Desktop//Tasarım//TasarimBadem//BademV1.0//Cifar//FCN1.txt";

		//Model m;
		//m.ReadImageFile(image);
		//m.Conv2D(kernel1, "relu", "valid", "false", 1);
		//m.Conv2D(kernel2, "relu", "valid", "false", 1);
		//m.MaxPooling2D(2);
		//m.Flatten();
		//m.Dense(weight1, "relu");
		//m.Dense(weight2, "softmax");

	}
};
}
