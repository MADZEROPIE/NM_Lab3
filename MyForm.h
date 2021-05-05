#pragma once
#include <math.h>

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
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(858, 497);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		double f1(double x){
			return sin(x);
		}

		double f2(double x) {
			return sin(2 * x);
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();
		PointPairList^ f1_list = gcnew ZedGraph::PointPairList();
		PointPairList^ f2_list = gcnew ZedGraph::PointPairList();

		// Интервал, где есть данные
		double xmin = Convert::ToDouble(textBox1->Text);
		double xmax = Convert::ToDouble(textBox2->Text);

		double h = Convert::ToDouble(textBox3->Text);


		double xmin_limit = xmin - 0.1;
		double xmax_limit = xmax + 0.1;
/*
		double ymin_limit = -1.0;
		double ymax_limit = 100.0;
*/
		// Список точек
		int i = 0;
		dataGridView1->Rows->Clear();
		for (double x = xmin; x <= xmax; x += h)
		{
			//Добавление на график
			f1_list->Add(x, f1(x));
			f2_list->Add(x, f2(x));
			//Печать в таблицу
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = x; 			
			dataGridView1->Rows[i]->Cells[1]->Value = floor(f1(x) * 1000) / 1000;
			dataGridView1->Rows[i]->Cells[2]->Value = floor(f2(x) * 1000) / 1000;
			i++;
		}
		LineItem Curve1 = panel->AddCurve("F1(x)", f1_list, Color::Red,SymbolType::Plus);
		LineItem Curve2 = panel->AddCurve("F2(x)", f2_list, Color::Blue, SymbolType::None);

		// Устанавливаем интересующий нас интервал по оси X
		panel->XAxis->Scale->Min = xmin_limit;
		panel->XAxis->Scale->Max = xmax_limit;
/*
		// Устанавливаем интересующий нас интервал по оси Y
		panel->YAxis->Scale->Min = ymin_limit;
		panel->YAxis->Scale->Max = ymax_limit;
*/
		// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
		// В противном случае на рисунке будет показана только часть графика, 
		// которая умещается в интервалы по осям, установленные по умолчанию
		zedGraphControl1->AxisChange();
		// Обновляем график
		zedGraphControl1->Invalidate();

	}
	private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	GraphPane^ panel = zedGraphControl1->GraphPane;
	double xmin = Convert::ToDouble(textBox5->Text);
	double xmax = Convert::ToDouble(textBox4->Text);
	// Устанавливаем интересующий нас интервал по оси X
	panel->XAxis->Scale->Min = xmin;
	panel->XAxis->Scale->Max = xmax;

	// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
	// В противном случае на рисунке будет показана только часть графика, 
	// которая умещается в интервалы по осям, установленные по умолчанию
	zedGraphControl1->AxisChange();
	// Обновляем график
	zedGraphControl1->Invalidate();

}
};
}
