#pragma once


namespace SUMMERprak {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class Login_form : public System::Windows::Forms::Form
	{
	public:
		Login_form(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Login_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ mainToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ pass_text;

	private: System::Windows::Forms::Label^ pass_label;
	private: System::Windows::Forms::Button^ pass_button;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pass_text = (gcnew System::Windows::Forms::TextBox());
			this->pass_label = (gcnew System::Windows::Forms::Label());
			this->pass_button = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::Info;
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->mainToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(547, 33);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mainToolStripMenuItem
			// 
			this->mainToolStripMenuItem->Name = L"mainToolStripMenuItem";
			this->mainToolStripMenuItem->Size = System::Drawing::Size(67, 29);
			this->mainToolStripMenuItem->Text = L"main";
			this->mainToolStripMenuItem->Click += gcnew System::EventHandler(this, &Login_form::mainToolStripMenuItem_Click);
			// 
			// pass_text
			// 
			this->pass_text->Location = System::Drawing::Point(132, 187);
			this->pass_text->Name = L"pass_text";
			this->pass_text->Size = System::Drawing::Size(252, 26);
			this->pass_text->TabIndex = 1;
			// 
			// pass_label
			// 
			this->pass_label->AutoSize = true;
			this->pass_label->Cursor = System::Windows::Forms::Cursors::SizeWE;
			this->pass_label->Location = System::Drawing::Point(181, 129);
			this->pass_label->Name = L"pass_label";
			this->pass_label->Size = System::Drawing::Size(135, 20);
			this->pass_label->TabIndex = 2;
			this->pass_label->Text = L"¬ведите пароль";
			// 
			// pass_button
			// 
			this->pass_button->Location = System::Drawing::Point(197, 251);
			this->pass_button->Name = L"pass_button";
			this->pass_button->Size = System::Drawing::Size(119, 66);
			this->pass_button->TabIndex = 3;
			this->pass_button->Text = L"¬ойти";
			this->pass_button->UseVisualStyleBackColor = true;
			this->pass_button->Click += gcnew System::EventHandler(this, &Login_form::pass_button_Click);
			// 
			// Login_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PeachPuff;
			this->ClientSize = System::Drawing::Size(547, 439);
			this->Controls->Add(this->pass_button);
			this->Controls->Add(this->pass_label);
			this->Controls->Add(this->pass_text);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Login_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"¬вод парол€";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void mainToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pass_button_Click(System::Object^ sender, System::EventArgs^ e);
};
}
