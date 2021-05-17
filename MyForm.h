#pragma once
#include "Methods.h"
#include <thread>
#include <msclr\marshal_cppstd.h>
#include <fstream>

namespace DirikhleGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;

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

	protected:
		G_Func* gf = nullptr;
		bool generated = false;
		uint64_t G_SEED = 15; // G*ndam SEED

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;

	private: Thread^ thread2 = nullptr;

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
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(408, 295);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000000, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(101, 20);
			this->numericUpDown2->TabIndex = 41;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(298, 297);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 15);
			this->label6->TabIndex = 40;
			this->label6->Text = L"Число разбиений";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 25);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(52, 13);
			this->label5->TabIndex = 39;
			this->label5->Text = L"Задача 1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(21, 260);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 38;
			this->label4->Text = L"Задача 2";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(586, 279);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(255, 110);
			this->button3->TabIndex = 37;
			this->button3->Text = L"Посчитать функцию";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(38, 340);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 18);
			this->label3->TabIndex = 36;
			this->label3->Text = L"eps";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(73, 340);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(159, 20);
			this->textBox1->TabIndex = 35;
			this->textBox1->Text = L"0,00001";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(73, 293);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(159, 29);
			this->button2->TabIndex = 34;
			this->button2->Text = L"Сгенерировать задачу";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton4->Location = System::Drawing::Point(19, 297);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(48, 20);
			this->radioButton4->TabIndex = 33;
			this->radioButton4->Text = L"g(x)";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->checkBox3->Location = System::Drawing::Point(136, 97);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(155, 22);
			this->checkBox3->TabIndex = 32;
			this->checkBox3->Text = L"Формула Симпсона";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->checkBox2->Location = System::Drawing::Point(136, 74);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(137, 22);
			this->checkBox2->TabIndex = 31;
			this->checkBox2->Text = L"Метод Трапеций";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->checkBox1->Location = System::Drawing::Point(136, 50);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(192, 22);
			this->checkBox1->TabIndex = 30;
			this->checkBox1->Text = L"Метод Прямоугольников";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(596, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(255, 110);
			this->button1->TabIndex = 29;
			this->button1->Text = L"Посчитать для выбранных методов";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(474, 50);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000000, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(101, 20);
			this->numericUpDown1->TabIndex = 28;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(363, 52);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 15);
			this->label2->TabIndex = 27;
			this->label2->Text = L"Число разбиений";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(386, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 56);
			this->label1->TabIndex = 26;
			this->label1->Text = L"f(x) = (1+2x)/(4x) \na = 1   b = 2";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->radioButton3->Location = System::Drawing::Point(7, 96);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(109, 22);
			this->radioButton3->TabIndex = 23;
			this->radioButton3->Text = L"f(x)+cos(100x)";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->radioButton2->Location = System::Drawing::Point(8, 73);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(102, 22);
			this->radioButton2->TabIndex = 24;
			this->radioButton2->Text = L"f(x)+cos(10x)";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Open Sans Semibold", 9.75F, System::Drawing::FontStyle::Bold));
			this->radioButton1->Location = System::Drawing::Point(8, 50);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(46, 22);
			this->radioButton1->TabIndex = 25;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"f(x)";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(875, 429);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button3);
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
			this->Text = L"Лабораторная работа №3. 381803-2. Команда 7";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: void BackgroundWorker1_DoWork() {
			// Sleep 2 seconds to emulate getting data.
			system("python show_plot.py");
		}
	


private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	int64_t N = Convert::ToInt64(numericUpDown1->Text);
	String^ tmp = "Интеграл для функции ";
	if (radioButton1->Checked) {
		tmp += "f(x) при " + (N)+" разбиениях равен: \n";
		double ans = ans_1();
		tmp += "Истинное значение интеграла: " + ans + "\n\n";
		if (checkBox1->Checked) {
			double res = rectInteg(f1, 1, 2, N);
			tmp += "Методом прямоугольников : " + res + "\n";
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
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!generated) {
		button2_Click(sender, e);
	}
	int64_t N = Convert::ToInt64(numericUpDown2->Text);
	double eps = Convert::ToDouble(textBox1->Text);
	double a = 0; double b = 1;
	double h = (b - a) / N;
	std::ofstream file;
	file.open("res.csv");
	//file << "sep=,\n";
	for (int i = 0; i < N; ++i) {
		auto res = gf->operator()(a + i * h, eps);
		file << res.x << "," << res.y << "," << res.T << "\n";
	}
	auto res = gf->operator()(b, eps);
	file << res.x << "," << res.y << "," << res.T << "\n";
	Process^ myProcess = gcnew Process();
	myProcess->StartInfo->FileName = "python";
	myProcess->StartInfo->Arguments = "show_plot.py";
	myProcess->Start();
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	delete this->gf;
	uint64_t seed = G_SEED;;
	THillFunc hf(seed);
	auto coeffs = hf.getCoeffs();
	double alp = hf.getAlpha();
	generated = true;
	gf = new G_Func(hf);
	String^ mes = "Сгенерирована функция со следующими коэффициентами: \n";
	for (int i = 0; i < 14; ++i) {
		mes += "A[" + (i + 1) + "] " + coeffs.first[i] + "\tB[" + (i + 1) + "] " + coeffs.second[i] + "\n";
	}
	/*mes += "\nB: ";
	for (int i = 0; i < 14; ++i) {
		mes += "B[" + (i + 1) + "] " + coeffs.second[i] + "\n";
	}*/
	mes += "\na = " + alp;
	MessageBox::Show(mes);
	++G_SEED;
}
};
}
