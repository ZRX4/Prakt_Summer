#pragma once
#include "FilterForm.h"

namespace SUMMERprak {
	

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Pols_main_form
	/// </summary>
	public ref class Pols_main_form : public System::Windows::Forms::Form
	{
	private: void LoadDataFromFile();
	private: int status;
	
	public:
		Pols_main_form(int mode)
		{
			InitializeComponent();
			LoadDataFromFile();
			this->status = mode;
		}

	private:
		FilterForm^ mma = nullptr; // Инициализируем пустым указателем

	public: Pols_main_form^ ssilk = this;
	private: System::Windows::Forms::Button^ delet_pols_button;
	public:

	
	


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Pols_main_form()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^ dataGridViewPols;
	protected:

	protected:

	protected:


	private: System::Windows::Forms::ToolStripMenuItem^ menu_pols_main;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ mainMenuToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ mainToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_row;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ fio_row;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ age_row;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ group_row;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ marks_row;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dopinfo_row;
	private: System::Windows::Forms::ToolStripMenuItem^ filtersToolStripMenuItem;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridViewPols = (gcnew System::Windows::Forms::DataGridView());
			this->id_row = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->fio_row = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->age_row = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->group_row = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->marks_row = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dopinfo_row = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menu_pols_main = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mainMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->mainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filtersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->delet_pols_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPols))->BeginInit();
			this->menuStrip2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridViewPols
			// 
			this->dataGridViewPols->AllowUserToAddRows = false;
			this->dataGridViewPols->AllowUserToDeleteRows = false;
			this->dataGridViewPols->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridViewPols->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewPols->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id_row,
					this->fio_row, this->age_row, this->group_row, this->marks_row, this->dopinfo_row
			});
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridViewPols->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewPols->Location = System::Drawing::Point(78, 48);
			this->dataGridViewPols->Name = L"dataGridViewPols";
			this->dataGridViewPols->ReadOnly = true;
			this->dataGridViewPols->RowHeadersVisible = false;
			this->dataGridViewPols->RowHeadersWidth = 62;
			this->dataGridViewPols->RowTemplate->Height = 28;
			this->dataGridViewPols->Size = System::Drawing::Size(1366, 360);
			this->dataGridViewPols->TabIndex = 0;
			// 
			// id_row
			// 
			this->id_row->HeaderText = L"id";
			this->id_row->MinimumWidth = 8;
			this->id_row->Name = L"id_row";
			this->id_row->ReadOnly = true;
			this->id_row->Width = 150;
			// 
			// fio_row
			// 
			this->fio_row->HeaderText = L"ФИО";
			this->fio_row->MinimumWidth = 8;
			this->fio_row->Name = L"fio_row";
			this->fio_row->ReadOnly = true;
			this->fio_row->Width = 150;
			// 
			// age_row
			// 
			this->age_row->HeaderText = L"Возраст";
			this->age_row->MinimumWidth = 8;
			this->age_row->Name = L"age_row";
			this->age_row->ReadOnly = true;
			this->age_row->Width = 150;
			// 
			// group_row
			// 
			this->group_row->HeaderText = L"Группа";
			this->group_row->MinimumWidth = 8;
			this->group_row->Name = L"group_row";
			this->group_row->ReadOnly = true;
			this->group_row->Width = 150;
			// 
			// marks_row
			// 
			this->marks_row->HeaderText = L"Оценки";
			this->marks_row->MinimumWidth = 8;
			this->marks_row->Name = L"marks_row";
			this->marks_row->ReadOnly = true;
			this->marks_row->Width = 150;
			// 
			// dopinfo_row
			// 
			this->dopinfo_row->HeaderText = L"Дополнительная информация";
			this->dopinfo_row->MinimumWidth = 8;
			this->dopinfo_row->Name = L"dopinfo_row";
			this->dopinfo_row->ReadOnly = true;
			this->dopinfo_row->Width = 253;
			// 
			// menu_pols_main
			// 
			this->menu_pols_main->Name = L"menu_pols_main";
			this->menu_pols_main->Size = System::Drawing::Size(32, 19);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(32, 19);
			// 
			// menuStrip1
			// 
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Location = System::Drawing::Point(0, 33);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1779, 24);
			this->menuStrip1->TabIndex = 1;
			// 
			// mainMenuToolStripMenuItem
			// 
			this->mainMenuToolStripMenuItem->Name = L"mainMenuToolStripMenuItem";
			this->mainMenuToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// menuStrip2
			// 
			this->menuStrip2->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->mainToolStripMenuItem,
					this->filtersToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(1779, 33);
			this->menuStrip2->TabIndex = 2;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// mainToolStripMenuItem
			// 
			this->mainToolStripMenuItem->Name = L"mainToolStripMenuItem";
			this->mainToolStripMenuItem->Size = System::Drawing::Size(67, 29);
			this->mainToolStripMenuItem->Text = L"main";
			this->mainToolStripMenuItem->Click += gcnew System::EventHandler(this, &Pols_main_form::mainToolStripMenuItem_Click);
			// 
			// filtersToolStripMenuItem
			// 
			this->filtersToolStripMenuItem->Name = L"filtersToolStripMenuItem";
			this->filtersToolStripMenuItem->Size = System::Drawing::Size(71, 29);
			this->filtersToolStripMenuItem->Text = L"filters";
			this->filtersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Pols_main_form::filtersToolStripMenuItem_Click);
			// 
			// delet_pols_button
			// 
			this->delet_pols_button->Location = System::Drawing::Point(311, 449);
			this->delet_pols_button->Name = L"delet_pols_button";
			this->delet_pols_button->Size = System::Drawing::Size(172, 88);
			this->delet_pols_button->TabIndex = 3;
			this->delet_pols_button->Text = L"Удалить ";
			this->delet_pols_button->UseVisualStyleBackColor = true;
			// 
			// Pols_main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1779, 549);
			this->Controls->Add(this->delet_pols_button);
			this->Controls->Add(this->dataGridViewPols);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Pols_main_form";
			this->Text = L"База Данных (пользовательский просмотр)";
			this->Load += gcnew System::EventHandler(this, &Pols_main_form::Pols_main_form_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewPols))->EndInit();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void mainToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void filtersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	if (mma == nullptr) {

		mma = gcnew FilterForm(this);

		mma->FormClosed += gcnew FormClosedEventHandler(this, &Pols_main_form::OnFormClosed);

		mma->Show();


	}

	else {
		if (mma->WindowState == FormWindowState::Minimized) {
			mma->WindowState = FormWindowState::Normal;
		}
		mma->Activate();
	}
}
private: System::Void OnFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
		   mma = nullptr; 
	 }
private: System::Void Pols_main_form_Load(System::Object^ sender, System::EventArgs^ e);
};
}
