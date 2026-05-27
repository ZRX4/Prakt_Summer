#include "Pols_main_form.h"   
#include "FilterForm.h"

namespace SUMMERprak {
	
	void FilterForm::proverka() {
		try {
			if(this->text_box_id->Text!="")Convert::ToInt32(this->text_box_id->Text);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка! В поле ID можно вводить только целые числа.", "Неверный формат");
			this->id_check_box->Checked = false;
		}

		try {
			int a, b;
			if (this->text_box_ot1->Text != "") a=Convert::ToInt32(this->text_box_ot1->Text);
			if (this->text_box_do1->Text != "")	b=Convert::ToInt32(this->text_box_do1->Text);
			if (this->text_box_ot1->Text != "" && this->text_box_do1->Text != "") 
				if (b < a) {
					MessageBox::Show("Ошибка! Второе число не должно быть меньше первого", "Неверный формат");
					this->age_check_box->Checked = false;
				}

				
		}	  
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка! В поле Возраста можно вводить только целые числа.", "Неверный формат");
			this->age_check_box->Checked = false;
			
		}

		try {
			int d, c;
			if (this->text_box_ot2->Text != "") d = Convert::ToInt32(this->text_box_ot2->Text);
			if (this->text_box_do2->Text != "")	c = Convert::ToInt32(this->text_box_do2->Text);
			if (this->text_box_ot2->Text != "" && this->text_box_do2->Text != "")
				if (d > c) {
					MessageBox::Show("Ошибка! Второе число не должно быть меньше первого", "Неверный формат");
					this->mark1_radio_button->Checked = false;
				}

			if (( d > 5 ||  d<0 )&& this->text_box_ot2->Text != "") {
				MessageBox::Show("Ошибка! Вводите оценки в пределах от 0 до 5", "Неверный формат");
				this->mark1_radio_button->Checked = false;
				}
			if ((c > 5 || c < 0) && this->text_box_do2->Text != "") {
				MessageBox::Show("Ошибка! Вводите оценки в пределах от 0 до 5", "Неверный формат");
				this->mark1_radio_button->Checked = false;
			}


		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка! В поле поиска по диапозону можно вводить только целые числа от 0 до 5.", "Неверный формат");
			this->mark1_radio_button->Checked = false;

		}


		try {
			if (this->text_box_matanalis->Text != "")Convert::ToInt32(this->text_box_matanalis->Text);
			if (this->text_box_phisic->Text != "")Convert::ToInt32(this->text_box_phisic->Text);
			if (this->text_box_proga->Text != "")Convert::ToInt32(this->text_box_proga->Text);
			if (this->text_box_ecolog->Text != "")Convert::ToInt32(this->text_box_ecolog->Text);
			if (this->text_box_OIT->Text != "")Convert::ToInt32(this->text_box_OIT->Text);
			if (this->text_box_history->Text != "")Convert::ToInt32(this->text_box_history->Text);
			if (this->text_box_fisra->Text != "")Convert::ToInt32(this->text_box_fisra->Text);
			if (this->text_box_diskret->Text != "")Convert::ToInt32(this->text_box_diskret->Text);
			if (this->text_box_angl->Text != "")Convert::ToInt32(this->text_box_angl->Text);


		}
		catch (Exception^ ex) {
			MessageBox::Show("Ошибка! В поле поиска по предмету можно вводить только целые числа от 0 до 5.", "Неверный формат");
			this->mark2_radio_button->Checked = false;

		}
		




	}
	void FilterForm::button_parametr_Click(System::Object^ sender, System::EventArgs^ e) {
		proverka();

        String^ filePath = "test.txt";
        if (!System::IO::File::Exists(filePath)) {
            MessageBox::Show("Файл с данными не найден!", "Ошибка");
            return;
        }
		try {
			System::Text::Encoding^ win1251 = System::Text::Encoding::GetEncoding(1251);
			System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(filePath, win1251);
			ssilk->dataGridViewPols->Rows->Clear();


			int ok;


			String^ line;
			while ((line = sr->ReadLine()) != nullptr) {
				ok = 1;
				array<String^>^ fields = line->Split('\t');
				if (fields->Length >= 8) {

					array<String^>^ marki = fields[4]->Split(gcnew array<wchar_t>{' '}, StringSplitOptions::RemoveEmptyEntries);
					array<int>^ prmark = gcnew array<int>(marki->Length);
					for (int i = 0; i < marki->Length; i++)
					{
						prmark[i] = Convert::ToInt32(marki[i]->Trim());
					}

					if (this->id_check_box->Checked) { if (fields[0]->Trim() != this->text_box_id->Text->Trim()) ok = 0;}
					if (this->fio_check_box->Checked) { if (!(fields[1]->Trim()->ToLower()->Contains(this->text_box_fio->Text->ToLower()->Trim()))) ok = 0; }
					if (this->group_check_box->Checked) { if (!(fields[3]->Trim()->ToLower()->Contains(this->text_box_group->Text->ToLower()->Trim()))) ok = 0; }
					if (this->adres_check_box->Checked) { if (!(fields[5]->Trim()->ToLower()->Contains(this->text_box_adres->Text->ToLower()->Trim()))) ok = 0; }
					if (this->mail_check_box->Checked) { if (!(fields[7]->Trim()->ToLower()->Contains(this->text_box_mail->Text->ToLower()->Trim()))) ok = 0; }
					if (this->number_check_box->Checked) { if (!(fields[6]->Trim()->ToLower()->Contains(this->text_box_number->Text->ToLower()->Trim()))) ok = 0; }
					if (this->age_check_box->Checked) {
						int age1, age2;
						if (this->text_box_ot1->Text == "") age1 = 0;
						else age1 = Convert::ToInt32(this->text_box_ot1->Text);
						if (this->text_box_do1->Text == "") age2 = 3000;
						else age2 = Convert::ToInt32(this->text_box_do1->Text);
						if (!(Convert::ToInt32(fields[2]) >= age1 && Convert::ToInt32(fields[2]) <= age2)) ok = 0;
						
						/*доделать защиту на поиск по оценке */
					}
					if (this->mark1_radio_button->Checked) {

						int mark1, mark2;
						if (this->text_box_ot2->Text == "") mark1 = 0;
						else mark1 = Convert::ToInt32(this->text_box_ot2->Text);
						if (this->text_box_do2->Text == "") mark2 = 5;
						else mark2 = Convert::ToInt32(this->text_box_do2->Text);
						
						for (int i = 0; i < (prmark->Length); i++) {
							
							if (!(prmark[i] >= mark1 && prmark[i] <= mark2)) { ok = 0; }
						}
					}
					if (this->mark2_radio_button->Checked) {
						if (this->text_box_matanalis->Text != "") if(this->text_box_matanalis->Text!=marki[0]) ok=0;
						if (this->text_box_phisic->Text != "") if((this->text_box_phisic->Text) != marki[1]) ok = 0;
						if (this->text_box_proga->Text != "")if ((this->text_box_proga->Text) != marki[2]) ok = 0;
						if (this->text_box_ecolog->Text != "")if ((this->text_box_ecolog->Text) != marki[3]) ok = 0;
						if (this->text_box_OIT->Text != "")if ((this->text_box_OIT->Text) != marki[4]) ok = 0;
						if (this->text_box_history->Text != "")if ((this->text_box_history->Text) != marki[5]) ok = 0;
						if (this->text_box_fisra->Text != "")if ((this->text_box_fisra->Text) != marki[6]) ok = 0;;
						if (this->text_box_diskret->Text != "")if ((this->text_box_diskret->Text) != marki[7]) ok = 0;
						if (this->text_box_angl->Text != "")if ((this->text_box_angl->Text) != marki[8]) ok = 0;



					}

					if (ok==1) {
						int row = ssilk->dataGridViewPols->Rows->Add();
						String^ nummail = fields[5] + "  \n" + fields[6] + "  \n" + fields[7];
						ssilk->dataGridViewPols->Rows[row]->Cells[0]->Value = fields[0];
						ssilk->dataGridViewPols->Rows[row]->Cells[1]->Value = fields[1];
						ssilk->dataGridViewPols->Rows[row]->Cells[2]->Value = fields[2];
						ssilk->dataGridViewPols->Rows[row]->Cells[3]->Value = fields[3];
						ssilk->dataGridViewPols->Rows[row]->Cells[4]->Value = fields[4];
						ssilk->dataGridViewPols->Rows[row]->Cells[5]->Value = nummail;
					}
				}
			}
			sr->Close();

		}

		catch (Exception^ ex) {
			MessageBox::Show("Ошибка: " + ex->Message);
		}
 
	}


	void FilterForm::button_clear_Click(System::Object^ sender, System::EventArgs^ e){
		this->text_box_id->Text = "";
		this->text_box_fio->Text = "";
		this->text_box_group->Text = "";
		this->text_box_adres->Text = "";
		this->text_box_mail->Text = "";
		this->text_box_number->Text = "";
		this->text_box_ot1->Text = "";
		this->text_box_do1->Text = "";
		this->text_box_ot2->Text = "";
		this->text_box_do2->Text = "";
		this->text_box_matanalis->Text = "";
		this->text_box_phisic->Text = "";
		this->text_box_proga->Text = "";
		this->text_box_ecolog->Text = "";
		this->text_box_OIT->Text = "";
		this->text_box_history->Text = "";
		this->text_box_fisra->Text = "";
		this->text_box_diskret->Text = "";
		this->text_box_angl->Text = "";
		this->id_check_box->Checked = false;
		this->fio_check_box->Checked = false;
		this->group_check_box->Checked = false;
		this->adres_check_box->Checked = false;
		this->mail_check_box->Checked = false;
		this->number_check_box->Checked = false;
		this->age_check_box->Checked = false;
		this->mark1_radio_button->Checked = false;
		this->mark2_radio_button->Checked = false;

		button_parametr->PerformClick();


	}
}