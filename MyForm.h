#pragma once
#include <math.h>

#include "Methods.h"
#include <functional>
#include <time.h>

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		bool generated = false;
		G_Func* gf = nullptr;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ radioButton1;
	protected:
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::Label^ label1;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;





	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(13, 13);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(41, 19);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"f(x)";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(13, 36);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(88, 19);
			this->radioButton2->TabIndex = 0;
			this->radioButton2->Text = L"f(x)+cos(10x)";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton3->Location = System::Drawing::Point(12, 59);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(94, 19);
			this->radioButton3->TabIndex = 0;
			this->radioButton3->Text = L"f(x)+cos(100x)";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(391, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 56);
			this->label1->TabIndex = 5;
			this->label1->Text = L"f(x) = (1+2x)/(4x) \na = 1   b = 2";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(368, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 15);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Число разбиений";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(479, 13);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(101, 20);
			this->numericUpDown1->TabIndex = 9;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(601, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(255, 110);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Посчитать для выбранных методов";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(178, 11);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(168, 19);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"Метод Прямоугольников";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox2->Location = System::Drawing::Point(178, 35);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(118, 19);
			this->checkBox2->TabIndex = 12;
			this->checkBox2->Text = L"Метод Трапеций";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox3->Location = System::Drawing::Point(178, 59);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(135, 19);
			this->checkBox3->TabIndex = 13;
			this->checkBox3->Text = L"Формула Симпсона";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton4->Location = System::Drawing::Point(12, 113);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(48, 20);
			this->radioButton4->TabIndex = 14;
			this->radioButton4->Text = L"g(x)";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(64, 109);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 29);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Сгенерировать задачу";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(64, 156);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(159, 20);
			this->textBox1->TabIndex = 16;
			this->textBox1->Text = L"0.001";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(19, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"eps";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(858, 497);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Лабораторная работа 3. Команда 7";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 



	private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {
	}


private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int N = Convert::ToInt32( numericUpDown1->Text);
	String^ tmp = "Интеграл для функции ";
	if (radioButton1->Checked) {
		tmp += "f(x) при " + (N)+ " разбиениях равен: \n";
		double ans = ans_1();
		tmp += "Истинное значение интеграла: " + ans + "\n\n";
		if (checkBox1->Checked) {
			double res = rectInteg(f1, 1, 2, N);
			tmp += "Методом прямоугольников : " + res +"\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}
		if (checkBox2->Checked) {
			double res = trapInteg(f1, 1, 2, N);
			tmp += "Методом трапеций : " + res + "\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}
		if (checkBox3->Checked) {
			double res = simpInteg(f1, 1, 2, N);
			tmp += "Формулой Симпсона : " + res + "\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}	
	}
	else if (radioButton2->Checked) {
		tmp += "f(x)+cos(10x) при " + (N)+" разбиениях равен: \n";
		double ans = ans_2();
		tmp += "Истинное значение интеграла: " + ans + "\n\n";
		if (checkBox1->Checked) {
			double res = rectInteg(f2, 1, 2, N);
			tmp += "Методом прямоугольников : " + res + "\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}
		if (checkBox2->Checked) {
			double res = trapInteg(f2, 1, 2, N);
			tmp += "Методом трапеций : " + res + "\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}
		if (checkBox3->Checked) {
			double res = simpInteg(f2, 1, 2, N);
			tmp += "Формулой Симпсона : " + res + "\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}
	}
	else if (radioButton3->Checked) {
		tmp += "f(x)+cos(100x) при " + (N)+" разбиениях равен: \n";
		double ans = ans_3();
		tmp += "Истинное значение интеграла: " + ans + "\n\n";
		if (checkBox1->Checked) {
			double res = rectInteg(f3, 1, 2, N);
			tmp += "Методом прямоугольников : " + res + "\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}
		if (checkBox2->Checked) {
			double res = trapInteg(f3, 1, 2, N);
			tmp += "Методом трапеций : " + res + "\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}
		if (checkBox3->Checked) {
			double res = simpInteg(f3, 1, 2, N);
			tmp += "Формулой Симпсона : " + res + "\n";
			tmp += "Модуль отклонения от истинного значения: " + fabs(res - ans) + "\n\n";
		}
	}

	MessageBox::Show(tmp);


}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	delete this->gf;
	uint64_t seed = time(0);
	THillFunc hf(seed);
	auto coeffs = hf.getCoeffs();
	double alp = hf.getAlpha();
	generated = true;
	gf = new G_Func(hf);
	String^ mes ="Сгенерирована функция со следующими коэффициентами: \nA: ";
	for (int i = 0; i < 14; ++i) {
		mes += coeffs.first[i] + " ";
	}
	mes += "\nB: ";
	for (int i = 0; i < 14; ++i) {
		mes += coeffs.second[i] + " ";
	}
	mes += "\na = " + alp;
	MessageBox::Show(mes);
}
};
}
