#pragma once
#include "Pols_main_form.h"

namespace SUMMERprak {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ admin_main_button;
	private: System::Windows::Forms::Button^ pols_main_button;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label_main;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ mainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->admin_main_button = (gcnew System::Windows::Forms::Button());
			this->pols_main_button = (gcnew System::Windows::Forms::Button());
			this->label_main = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// admin_main_button
			// 
			this->admin_main_button->Location = System::Drawing::Point(65, 242);
			this->admin_main_button->Name = L"admin_main_button";
			this->admin_main_button->Size = System::Drawing::Size(168, 106);
			this->admin_main_button->TabIndex = 0;
			this->admin_main_button->Text = L"Администратор";
			this->admin_main_button->UseVisualStyleBackColor = true;
			this->admin_main_button->Click += gcnew System::EventHandler(this, &MainForm::admin_main_button_Click);
			// 
			// pols_main_button
			// 
			this->pols_main_button->Location = System::Drawing::Point(332, 242);
			this->pols_main_button->Name = L"pols_main_button";
			this->pols_main_button->Size = System::Drawing::Size(168, 106);
			this->pols_main_button->TabIndex = 1;
			this->pols_main_button->Text = L"Пользователь";
			this->pols_main_button->UseVisualStyleBackColor = true;
			this->pols_main_button->Click += gcnew System::EventHandler(this, &MainForm::pols_main_button_Click);
			// 
			// label_main
			// 
			this->label_main->AutoSize = true;
			this->label_main->Location = System::Drawing::Point(191, 70);
			this->label_main->Name = L"label_main";
			this->label_main->Size = System::Drawing::Size(166, 20);
			this->label_main->TabIndex = 2;
			this->label_main->Text = L"АСУ \"Успеваемость\"";
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->mainToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(548, 33);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mainToolStripMenuItem
			// 
			this->mainToolStripMenuItem->Name = L"mainToolStripMenuItem";
			this->mainToolStripMenuItem->Size = System::Drawing::Size(67, 29);
			this->mainToolStripMenuItem->Text = L"main";
			
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(548, 384);
			this->Controls->Add(this->label_main);
			this->Controls->Add(this->pols_main_button);
			this->Controls->Add(this->admin_main_button);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Main";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void pols_main_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Pols_main_form^ pols = gcnew Pols_main_form(0);
		
		pols->Show();
		this->Hide();

	}

	private: System::Void admin_main_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Pols_main_form^ qwe = gcnew Pols_main_form(1);
		
		qwe->Show();
		this->Hide();

	}
};

}
