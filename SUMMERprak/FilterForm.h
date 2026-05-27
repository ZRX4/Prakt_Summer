#pragma once

namespace SUMMERprak {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FilterForm
	/// </summary>
	/// 
	ref class Pols_main_form;

	public ref class FilterForm : public System::Windows::Forms::Form
	{
	private: void proverka();
	
	private: Pols_main_form^ ssilk;
	
	public:
		FilterForm(Pols_main_form^ parentForm)
		{
			InitializeComponent();
			ssilk = parentForm;
			
			
		}
	

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FilterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ id_check_box;
	private: System::Windows::Forms::TextBox^ text_box_id;
	private: System::Windows::Forms::TextBox^ text_box_group;
	protected:



	private: System::Windows::Forms::CheckBox^ group_check_box;
	private: System::Windows::Forms::TextBox^ text_box_fio;


	private: System::Windows::Forms::CheckBox^ fio_check_box;
	private: System::Windows::Forms::CheckBox^ age_check_box;
	private: System::Windows::Forms::TextBox^ text_box_ot1;
	private: System::Windows::Forms::TextBox^ text_box_do1;


	private: System::Windows::Forms::Label^ label_ot1;
	private: System::Windows::Forms::Label^ label_do1;




	private: System::Windows::Forms::CheckBox^ number_check_box;
	private: System::Windows::Forms::TextBox^ text_box_number;

	private: System::Windows::Forms::TextBox^ text_box_adres;
	private: System::Windows::Forms::CheckBox^ adres_check_box;
	private: System::Windows::Forms::TextBox^ text_box_mail;

	private: System::Windows::Forms::CheckBox^ mail_check_box;
	private: System::Windows::Forms::Label^ label_do2;

	private: System::Windows::Forms::Label^ label_ot2;
	private: System::Windows::Forms::TextBox^ text_box_do2;


	private: System::Windows::Forms::TextBox^ text_box_ot2;


	private: System::Windows::Forms::Button^ button_clear;

	private: System::Windows::Forms::Label^ label_marks_matanalis;
	private: System::Windows::Forms::Label^ label_marks_phisic;
	private: System::Windows::Forms::Label^ label_marks_proga;
	private: System::Windows::Forms::Label^ label_marks_history;



	private: System::Windows::Forms::Label^ label_marks_OIT;

	private: System::Windows::Forms::Label^ label_marks_ecolog;
	private: System::Windows::Forms::Label^ label_marks_angl;


	private: System::Windows::Forms::Label^ label_marks_diskret;

	private: System::Windows::Forms::Label^ label_marks_fisra;
	private: System::Windows::Forms::Button^ button_parametr;
	private: System::Windows::Forms::TextBox^ text_box_matanalis;
	private: System::Windows::Forms::TextBox^ text_box_phisic;
	private: System::Windows::Forms::TextBox^ text_box_proga;
	private: System::Windows::Forms::TextBox^ text_box_ecolog;

	private: System::Windows::Forms::TextBox^ text_box_OIT;
	private: System::Windows::Forms::TextBox^ text_box_history;
	private: System::Windows::Forms::TextBox^ text_box_fisra;
	private: System::Windows::Forms::TextBox^ text_box_diskret;
	private: System::Windows::Forms::TextBox^ text_box_angl;
	private: System::Windows::Forms::RadioButton^ mark2_radio_button;

	private: System::Windows::Forms::RadioButton^ mark1_radio_button;










	protected:

	protected:

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
			this->id_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->text_box_id = (gcnew System::Windows::Forms::TextBox());
			this->text_box_group = (gcnew System::Windows::Forms::TextBox());
			this->group_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->text_box_fio = (gcnew System::Windows::Forms::TextBox());
			this->fio_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->age_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->text_box_ot1 = (gcnew System::Windows::Forms::TextBox());
			this->text_box_do1 = (gcnew System::Windows::Forms::TextBox());
			this->label_ot1 = (gcnew System::Windows::Forms::Label());
			this->label_do1 = (gcnew System::Windows::Forms::Label());
			this->number_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->text_box_number = (gcnew System::Windows::Forms::TextBox());
			this->text_box_adres = (gcnew System::Windows::Forms::TextBox());
			this->adres_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->text_box_mail = (gcnew System::Windows::Forms::TextBox());
			this->mail_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->label_do2 = (gcnew System::Windows::Forms::Label());
			this->label_ot2 = (gcnew System::Windows::Forms::Label());
			this->text_box_do2 = (gcnew System::Windows::Forms::TextBox());
			this->text_box_ot2 = (gcnew System::Windows::Forms::TextBox());
			this->button_clear = (gcnew System::Windows::Forms::Button());
			this->label_marks_matanalis = (gcnew System::Windows::Forms::Label());
			this->label_marks_phisic = (gcnew System::Windows::Forms::Label());
			this->label_marks_proga = (gcnew System::Windows::Forms::Label());
			this->label_marks_history = (gcnew System::Windows::Forms::Label());
			this->label_marks_OIT = (gcnew System::Windows::Forms::Label());
			this->label_marks_ecolog = (gcnew System::Windows::Forms::Label());
			this->label_marks_angl = (gcnew System::Windows::Forms::Label());
			this->label_marks_diskret = (gcnew System::Windows::Forms::Label());
			this->label_marks_fisra = (gcnew System::Windows::Forms::Label());
			this->button_parametr = (gcnew System::Windows::Forms::Button());
			this->text_box_matanalis = (gcnew System::Windows::Forms::TextBox());
			this->text_box_phisic = (gcnew System::Windows::Forms::TextBox());
			this->text_box_proga = (gcnew System::Windows::Forms::TextBox());
			this->text_box_ecolog = (gcnew System::Windows::Forms::TextBox());
			this->text_box_OIT = (gcnew System::Windows::Forms::TextBox());
			this->text_box_history = (gcnew System::Windows::Forms::TextBox());
			this->text_box_fisra = (gcnew System::Windows::Forms::TextBox());
			this->text_box_diskret = (gcnew System::Windows::Forms::TextBox());
			this->text_box_angl = (gcnew System::Windows::Forms::TextBox());
			this->mark2_radio_button = (gcnew System::Windows::Forms::RadioButton());
			this->mark1_radio_button = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			this->id_check_box->AutoSize = true;
			this->id_check_box->Location = System::Drawing::Point(36, 24);
			this->id_check_box->Name = L"id_check_box";
			this->id_check_box->Size = System::Drawing::Size(47, 24);
			this->id_check_box->TabIndex = 0;
			this->id_check_box->Text = L"id";
			this->id_check_box->UseVisualStyleBackColor = true;
			this->text_box_id->Location = System::Drawing::Point(119, 22);
			this->text_box_id->Multiline = true;
			this->text_box_id->Name = L"text_box_id";
			this->text_box_id->Size = System::Drawing::Size(129, 26);
			this->text_box_id->TabIndex = 1;
			this->text_box_group->Location = System::Drawing::Point(693, 20);
			this->text_box_group->Multiline = true;
			this->text_box_group->Name = L"text_box_group";
			this->text_box_group->Size = System::Drawing::Size(129, 26);
			this->text_box_group->TabIndex = 3;
			this->group_check_box->AutoSize = true;
			this->group_check_box->Location = System::Drawing::Point(579, 24);
			this->group_check_box->Name = L"group_check_box";
			this->group_check_box->Size = System::Drawing::Size(87, 24);
			this->group_check_box->TabIndex = 2;
			this->group_check_box->Text = L"Группа";
			this->group_check_box->UseVisualStyleBackColor = true;
			this->text_box_fio->Location = System::Drawing::Point(389, 24);
			this->text_box_fio->Multiline = true;
			this->text_box_fio->Name = L"text_box_fio";
			this->text_box_fio->Size = System::Drawing::Size(161, 26);
			this->text_box_fio->TabIndex = 5;
			this->fio_check_box->AutoSize = true;
			this->fio_check_box->Location = System::Drawing::Point(287, 24);
			this->fio_check_box->Name = L"fio_check_box";
			this->fio_check_box->Size = System::Drawing::Size(73, 24);
			this->fio_check_box->TabIndex = 4;
			this->fio_check_box->Text = L"ФИО";
			this->fio_check_box->UseVisualStyleBackColor = true;
			this->age_check_box->AutoSize = true;
			this->age_check_box->Location = System::Drawing::Point(36, 163);
			this->age_check_box->Name = L"age_check_box";
			this->age_check_box->Size = System::Drawing::Size(98, 24);
			this->age_check_box->TabIndex = 6;
			this->age_check_box->Text = L"Возраст";
			this->age_check_box->UseVisualStyleBackColor = true;
			this->text_box_ot1->Location = System::Drawing::Point(182, 162);
			this->text_box_ot1->Name = L"text_box_ot1";
			this->text_box_ot1->Size = System::Drawing::Size(100, 26);
			this->text_box_ot1->TabIndex = 7;
			this->text_box_do1->Location = System::Drawing::Point(324, 164);
			this->text_box_do1->Name = L"text_box_do1";
			this->text_box_do1->Size = System::Drawing::Size(104, 26);
			this->text_box_do1->TabIndex = 8;
			this->label_ot1->AutoSize = true;
			this->label_ot1->Location = System::Drawing::Point(141, 165);
			this->label_ot1->Name = L"label_ot1";
			this->label_ot1->Size = System::Drawing::Size(30, 20);
			this->label_ot1->TabIndex = 9;
			this->label_ot1->Text = L"От";
			this->label_do1->AutoSize = true;
			this->label_do1->Location = System::Drawing::Point(288, 164);
			this->label_do1->Name = L"label_do1";
			this->label_do1->Size = System::Drawing::Size(30, 20);
			this->label_do1->TabIndex = 10;
			this->label_do1->Text = L"До";
			this->number_check_box->AutoSize = true;
			this->number_check_box->Location = System::Drawing::Point(579, 94);
			this->number_check_box->Name = L"number_check_box";
			this->number_check_box->Size = System::Drawing::Size(85, 24);
			this->number_check_box->TabIndex = 11;
			this->number_check_box->Text = L"Номер";
			this->number_check_box->UseVisualStyleBackColor = true;
			this->text_box_number->Location = System::Drawing::Point(693, 94);
			this->text_box_number->Multiline = true;
			this->text_box_number->Name = L"text_box_number";
			this->text_box_number->Size = System::Drawing::Size(129, 26);
			this->text_box_number->TabIndex = 12;
			this->text_box_adres->Location = System::Drawing::Point(119, 96);
			this->text_box_adres->Multiline = true;
			this->text_box_adres->Name = L"text_box_adres";
			this->text_box_adres->Size = System::Drawing::Size(129, 26);
			this->text_box_adres->TabIndex = 14;
			this->adres_check_box->AutoSize = true;
			this->adres_check_box->Location = System::Drawing::Point(36, 94);
			this->adres_check_box->Name = L"adres_check_box";
			this->adres_check_box->Size = System::Drawing::Size(83, 24);
			this->adres_check_box->TabIndex = 13;
			this->adres_check_box->Text = L"Адрес";
			this->adres_check_box->UseVisualStyleBackColor = true;
			this->text_box_mail->Location = System::Drawing::Point(389, 96);
			this->text_box_mail->Multiline = true;
			this->text_box_mail->Name = L"text_box_mail";
			this->text_box_mail->Size = System::Drawing::Size(161, 26);
			this->text_box_mail->TabIndex = 16;
			this->mail_check_box->AutoSize = true;
			this->mail_check_box->Location = System::Drawing::Point(287, 94);
			this->mail_check_box->Name = L"mail_check_box";
			this->mail_check_box->Size = System::Drawing::Size(83, 24);
			this->mail_check_box->TabIndex = 15;
			this->mail_check_box->Text = L"Почта";
			this->mail_check_box->UseVisualStyleBackColor = true;
			this->label_do2->AutoSize = true;
			this->label_do2->Location = System::Drawing::Point(398, 280);
			this->label_do2->Name = L"label_do2";
			this->label_do2->Size = System::Drawing::Size(30, 20);
			this->label_do2->TabIndex = 21;
			this->label_do2->Text = L"До";
			this->label_ot2->AutoSize = true;
			this->label_ot2->Location = System::Drawing::Point(252, 283);
			this->label_ot2->Name = L"label_ot2";
			this->label_ot2->Size = System::Drawing::Size(30, 20);
			this->label_ot2->TabIndex = 20;
			this->label_ot2->Text = L"От";
			this->text_box_do2->Location = System::Drawing::Point(434, 280);
			this->text_box_do2->Name = L"text_box_do2";
			this->text_box_do2->Size = System::Drawing::Size(104, 26);
			this->text_box_do2->TabIndex = 19;
			this->text_box_ot2->Location = System::Drawing::Point(292, 278);
			this->text_box_ot2->Name = L"text_box_ot2";
			this->text_box_ot2->Size = System::Drawing::Size(100, 26);
			this->text_box_ot2->TabIndex = 18;
			this->button_clear->Location = System::Drawing::Point(627, 591);
			this->button_clear->Name = L"button_clear";
			this->button_clear->Size = System::Drawing::Size(167, 77);
			this->button_clear->TabIndex = 22;
			this->button_clear->Text = L"Отчистить фильтр";
			this->button_clear->UseVisualStyleBackColor = true;
			this->button_clear->Click += gcnew System::EventHandler(this, &FilterForm::button_clear_Click);
			this->label_marks_matanalis->AutoSize = true;
			this->label_marks_matanalis->Location = System::Drawing::Point(32, 431);
			this->label_marks_matanalis->Name = L"label_marks_matanalis";
			this->label_marks_matanalis->Size = System::Drawing::Size(98, 20);
			this->label_marks_matanalis->TabIndex = 24;
			this->label_marks_matanalis->Text = L"Мат.анализ";
			this->label_marks_phisic->AutoSize = true;
			this->label_marks_phisic->Location = System::Drawing::Point(32, 480);
			this->label_marks_phisic->Name = L"label_marks_phisic";
			this->label_marks_phisic->Size = System::Drawing::Size(67, 20);
			this->label_marks_phisic->TabIndex = 25;
			this->label_marks_phisic->Text = L"Физика";
			this->label_marks_proga->AutoSize = true;
			this->label_marks_proga->Location = System::Drawing::Point(32, 528);
			this->label_marks_proga->Name = L"label_marks_proga";
			this->label_marks_proga->Size = System::Drawing::Size(158, 20);
			this->label_marks_proga->TabIndex = 26;
			this->label_marks_proga->Text = L"Программирование";
			this->label_marks_history->AutoSize = true;
			this->label_marks_history->Location = System::Drawing::Point(318, 528);
			this->label_marks_history->Name = L"label_marks_history";
			this->label_marks_history->Size = System::Drawing::Size(73, 20);
			this->label_marks_history->TabIndex = 29;
			this->label_marks_history->Text = L"История";
			this->label_marks_OIT->AutoSize = true;
			this->label_marks_OIT->Location = System::Drawing::Point(318, 480);
			this->label_marks_OIT->Name = L"label_marks_OIT";
			this->label_marks_OIT->Size = System::Drawing::Size(41, 20);
			this->label_marks_OIT->TabIndex = 28;
			this->label_marks_OIT->Text = L"ОИТ";
			this->label_marks_ecolog->AutoSize = true;
			this->label_marks_ecolog->Location = System::Drawing::Point(318, 431);
			this->label_marks_ecolog->Name = L"label_marks_ecolog";
			this->label_marks_ecolog->Size = System::Drawing::Size(82, 20);
			this->label_marks_ecolog->TabIndex = 27;
			this->label_marks_ecolog->Text = L"Экология";
			this->label_marks_angl->AutoSize = true;
			this->label_marks_angl->Location = System::Drawing::Point(558, 528);
			this->label_marks_angl->Name = L"label_marks_angl";
			this->label_marks_angl->Size = System::Drawing::Size(50, 20);
			this->label_marks_angl->TabIndex = 32;
			this->label_marks_angl->Text = L"Ин.яз";
			this->label_marks_diskret->AutoSize = true;
			this->label_marks_diskret->Location = System::Drawing::Point(558, 480);
			this->label_marks_diskret->Name = L"label_marks_diskret";
			this->label_marks_diskret->Size = System::Drawing::Size(154, 20);
			this->label_marks_diskret->TabIndex = 31;
			this->label_marks_diskret->Text = L"Дискр.Математика";
			this->label_marks_fisra->AutoSize = true;
			this->label_marks_fisra->Location = System::Drawing::Point(558, 431);
			this->label_marks_fisra->Name = L"label_marks_fisra";
			this->label_marks_fisra->Size = System::Drawing::Size(64, 20);
			this->label_marks_fisra->TabIndex = 30;
			this->label_marks_fisra->Text = L"Физ-ра";
			this->button_parametr->Location = System::Drawing::Point(36, 591);
			this->button_parametr->Name = L"button_parametr";
			this->button_parametr->Size = System::Drawing::Size(167, 77);
			this->button_parametr->TabIndex = 33;
			this->button_parametr->Text = L"Отобразить параметры";
			this->button_parametr->UseVisualStyleBackColor = true;
			this->button_parametr->Click += gcnew System::EventHandler(this, &FilterForm::button_parametr_Click);
			this->text_box_matanalis->Location = System::Drawing::Point(213, 425);
			this->text_box_matanalis->Name = L"text_box_matanalis";
			this->text_box_matanalis->Size = System::Drawing::Size(55, 26);
			this->text_box_matanalis->TabIndex = 34;
			this->text_box_phisic->Location = System::Drawing::Point(213, 474);
			this->text_box_phisic->Name = L"text_box_phisic";
			this->text_box_phisic->Size = System::Drawing::Size(55, 26);
			this->text_box_phisic->TabIndex = 35;
			this->text_box_proga->Location = System::Drawing::Point(213, 528);
			this->text_box_proga->Name = L"text_box_proga";
			this->text_box_proga->Size = System::Drawing::Size(55, 26);
			this->text_box_proga->TabIndex = 36;
			this->text_box_ecolog->Location = System::Drawing::Point(434, 425);
			this->text_box_ecolog->Name = L"text_box_ecolog";
			this->text_box_ecolog->Size = System::Drawing::Size(55, 26);
			this->text_box_ecolog->TabIndex = 37;
			this->text_box_OIT->Location = System::Drawing::Point(434, 474);
			this->text_box_OIT->Name = L"text_box_OIT";
			this->text_box_OIT->Size = System::Drawing::Size(55, 26);
			this->text_box_OIT->TabIndex = 38;
			this->text_box_history->Location = System::Drawing::Point(434, 525);
			this->text_box_history->Name = L"text_box_history";
			this->text_box_history->Size = System::Drawing::Size(55, 26);
			this->text_box_history->TabIndex = 39;
			this->text_box_fisra->Location = System::Drawing::Point(739, 425);
			this->text_box_fisra->Name = L"text_box_fisra";
			this->text_box_fisra->Size = System::Drawing::Size(55, 26);
			this->text_box_fisra->TabIndex = 40;
			this->text_box_diskret->Location = System::Drawing::Point(739, 474);
			this->text_box_diskret->Name = L"text_box_diskret";
			this->text_box_diskret->Size = System::Drawing::Size(55, 26);
			this->text_box_diskret->TabIndex = 41;
			this->text_box_angl->Location = System::Drawing::Point(739, 522);
			this->text_box_angl->Name = L"text_box_angl";
			this->text_box_angl->Size = System::Drawing::Size(55, 26);
			this->text_box_angl->TabIndex = 42;
			this->mark2_radio_button->AutoSize = true;
			this->mark2_radio_button->Location = System::Drawing::Point(36, 375);
			this->mark2_radio_button->Name = L"mark2_radio_button";
			this->mark2_radio_button->Size = System::Drawing::Size(159, 24);
			this->mark2_radio_button->TabIndex = 43;
			this->mark2_radio_button->Text = L"Поиск по оценке";
			this->mark2_radio_button->UseVisualStyleBackColor = true;
			this->mark1_radio_button->AutoSize = true;
			this->mark1_radio_button->Location = System::Drawing::Point(36, 279);
			this->mark1_radio_button->Name = L"mark1_radio_button";
			this->mark1_radio_button->Size = System::Drawing::Size(196, 24);
			this->mark1_radio_button->TabIndex = 44;
			this->mark1_radio_button->Text = L"Оценки по диапозону";
			this->mark1_radio_button->UseVisualStyleBackColor = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(851, 694);
			this->Controls->Add(this->mark1_radio_button);
			this->Controls->Add(this->mark2_radio_button);
			this->Controls->Add(this->text_box_angl);
			this->Controls->Add(this->text_box_diskret);
			this->Controls->Add(this->text_box_fisra);
			this->Controls->Add(this->text_box_history);
			this->Controls->Add(this->text_box_OIT);
			this->Controls->Add(this->text_box_ecolog);
			this->Controls->Add(this->text_box_proga);
			this->Controls->Add(this->text_box_phisic);
			this->Controls->Add(this->text_box_matanalis);
			this->Controls->Add(this->button_parametr);
			this->Controls->Add(this->label_marks_angl);
			this->Controls->Add(this->label_marks_diskret);
			this->Controls->Add(this->label_marks_fisra);
			this->Controls->Add(this->label_marks_history);
			this->Controls->Add(this->label_marks_OIT);
			this->Controls->Add(this->label_marks_ecolog);
			this->Controls->Add(this->label_marks_proga);
			this->Controls->Add(this->label_marks_phisic);
			this->Controls->Add(this->label_marks_matanalis);
			this->Controls->Add(this->button_clear);
			this->Controls->Add(this->label_do2);
			this->Controls->Add(this->label_ot2);
			this->Controls->Add(this->text_box_do2);
			this->Controls->Add(this->text_box_ot2);
			this->Controls->Add(this->text_box_mail);
			this->Controls->Add(this->mail_check_box);
			this->Controls->Add(this->text_box_adres);
			this->Controls->Add(this->adres_check_box);
			this->Controls->Add(this->text_box_number);
			this->Controls->Add(this->number_check_box);
			this->Controls->Add(this->label_do1);
			this->Controls->Add(this->label_ot1);
			this->Controls->Add(this->text_box_do1);
			this->Controls->Add(this->text_box_ot1);
			this->Controls->Add(this->age_check_box);
			this->Controls->Add(this->text_box_fio);
			this->Controls->Add(this->fio_check_box);
			this->Controls->Add(this->text_box_group);
			this->Controls->Add(this->group_check_box);
			this->Controls->Add(this->text_box_id);
			this->Controls->Add(this->id_check_box);
			this->Name = L"FilterForm";
			this->Text = L"Фильтры для поиска";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		
#pragma endregion

	private: System::Void button_clear_Click(System::Object^ sender, System::EventArgs^ e);

	public: System::Void button_parametr_Click(System::Object^ sender, System::EventArgs^ e);


};
} 
