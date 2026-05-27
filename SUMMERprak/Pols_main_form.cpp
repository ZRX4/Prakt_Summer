#include "Pols_main_form.h"
#include "MainForm.h"   

namespace SUMMERprak {
    void Pols_main_form::mainToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        MainForm^ mmm = gcnew MainForm();
        mmm->Show();
        this->Close();
        if (mma != nullptr) {
            mma->Close();
        }
    
    }

    void Pols_main_form::Pols_main_form_Load(System::Object^ sender, System::EventArgs^ e) {

        if (this->status == 1) {
            delet_pols_button->Visible = true;
            this->Text = "База данных в пежиме администратора";
        }
        else {
            delet_pols_button->Visible = false;
            this->Text = "База данных в пежиме пользователя";
        }

    }

    void Pols_main_form::LoadDataFromFile() {
        String^ filePath = "test.txt";
        if (!System::IO::File::Exists(filePath)) {
            MessageBox::Show("Файл с данными не найден!", "Ошибка");
            return;
        }

        try {
            
            System::Text::Encoding^ win1251 = System::Text::Encoding::GetEncoding(1251);
            System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(filePath, win1251);
            dataGridViewPols->Rows->Clear();

            String^ line;
            while ((line = sr->ReadLine()) != nullptr) {
                array<String^>^ fields = line->Split('\t');
                if (fields->Length >= 8) {
                    int row = dataGridViewPols->Rows->Add();
                    String^ nummail = fields[5]+"  \n"+fields[6]+ "  \n" + fields[7];
                    dataGridViewPols->Rows[row]->Cells[0]->Value = fields[0];
                    dataGridViewPols->Rows[row]->Cells[1]->Value = fields[1];
                    dataGridViewPols->Rows[row]->Cells[2]->Value = fields[2];
                    dataGridViewPols->Rows[row]->Cells[3]->Value = fields[3];
                    dataGridViewPols->Rows[row]->Cells[4]->Value = fields[4];
                    dataGridViewPols->Rows[row]->Cells[5]->Value =nummail;
                }
            } 
            sr->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка: " + ex->Message);
        }
    }

}

