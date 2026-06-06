#include "Pols_main_form.h"
#include "MainForm.h"   
#include <io.h>

using namespace System::Drawing::Drawing2D;

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

        GraphicsPath^ roundPath = gcnew GraphicsPath();
        roundPath->AddEllipse(0, 0, help_button->Width, help_button->Height);

       
        help_button->Region = gcnew System::Drawing::Region(roundPath);

        this->dataGridViewPols->ColumnHeadersDefaultCellStyle->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
        
        
        this->dataGridViewPols->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
        this->dataGridViewPols->ColumnHeadersHeight = 45;

        this->dataGridViewPols->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
        this->dataGridViewPols->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
        this->dataGridViewPols->Columns[1]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
        this->dataGridViewPols->Columns[4]->HeaderText = "Оценки\n1 2 3 4 5 6 7 8 9";


      
        this->dataGridViewPols->Columns[4]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
        this->dataGridViewPols->Columns[4]->Width = 140; 


        if (this->status == 1) {
            this->dataGridViewPols->ReadOnly = false;              
            this->dataGridViewPols->AllowUserToAddRows = true;
            delet_pols_button->Visible = true;
            this->dataGridViewPols->Columns[0]->ReadOnly = true;
            delet_text_box->Visible = true;
            id_delet_label->Visible = true;
            this->Save_data_button->Visible = true;
            this->Text = "База данных в пежиме администратора";
        }
        else {
            this->dataGridViewPols->ReadOnly = true;               
            this->dataGridViewPols->AllowUserToAddRows = false;
            delet_pols_button->Visible = false;

            delet_text_box->Visible = false;
            id_delet_label->Visible = false;
            this->Save_data_button->Visible = false;
            this->Text = "База данных в пежиме пользователя";
        }

    }

    void Pols_main_form::LoadDataFromFile() {
        String^ filePath = "database.txt";
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
                    String^ nummail = fields[5] + "  \n" + fields[6] + "  \n" + fields[7];
                    dataGridViewPols->Rows[row]->Cells[0]->Value = fields[0];
                    dataGridViewPols->Rows[row]->Cells[1]->Value = fields[1];
                    dataGridViewPols->Rows[row]->Cells[2]->Value = fields[2];
                    dataGridViewPols->Rows[row]->Cells[3]->Value = fields[3];
                    dataGridViewPols->Rows[row]->Cells[4]->Value = "  " + fields[4];
                    dataGridViewPols->Rows[row]->Cells[5]->Value = nummail;
                }
            }
            sr->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка: " + ex->Message);
        }
    }


    void Pols_main_form::delet_pols_button_Click(System::Object^ sender, System::EventArgs^ e) {
        if (this->delet_text_box->Text == "") {
            MessageBox::Show("Введите числовые id!", "Ошибка");
            return;
        }
        System::String^ sourcePath = "database.txt";      
        System::String^ tempPath = "database_temp.txt";

        if (!System::IO::File::Exists(sourcePath)) {
            System::Windows::Forms::MessageBox::Show("Файл базы данных не найден!");
            return;

        }

        System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(sourcePath, System::Text::Encoding::GetEncoding(1251));
        System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(tempPath, false, System::Text::Encoding::GetEncoding(1251));


        array<String^>^ id_del = this->delet_text_box->Text->Split(gcnew array<wchar_t>{' '}, StringSplitOptions::RemoveEmptyEntries);
        array<int>^ id_id = gcnew array<int>(id_del->Length);
        for (int i = 0; i < id_del->Length; i++)
        {
            try {
                id_id[i] = Convert::ToInt32(id_del[i]->Trim());
            }
            catch (Exception^ ex) {
                MessageBox::Show("Ошибка: Используйте целые числа для id");
                reader->Close();
                writer->Close();
                return;

            }
        }


        System::String^ printline = "";
        bool found = false;
        System::String^ line;
        while ((line = reader->ReadLine()) != nullptr) {
           
            bool rezf = false;
            array<System::String^>^ fields = line->Split('\t');

            for (int i = 0; i < id_del->Length; i++) {
                if (fields->Length > 0 && System::String::Compare(fields[0]->Trim(), id_del[i]->Trim()) == 0) {
                    rezf = true;
                    printline = printline + "Успешное удаление " + id_del[i] + "\n";
                } 
            }
            if (rezf) {
                found = true; continue;
            }
           
            writer->WriteLine(line);
        }

        reader->Close();
        writer->Close();
        if (found) {
           
            System::IO::File::Delete(sourcePath);
            
            System::IO::File::Move(tempPath, sourcePath);

            System::Windows::Forms::MessageBox::Show(printline);
        }
        else {
            
            System::IO::File::Delete(tempPath);
            System::Windows::Forms::MessageBox::Show("id Для удаления не найдены");
        }

        Pols_main_form::LoadDataFromFile();
    }

    //проверяем на поменялась ли строка таблицы
    void Pols_main_form::dataGridViewPols_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0 && !dataGridViewPols->Rows[e->RowIndex]->IsNewRow) {

            
            System::Object^ idVal = dataGridViewPols->Rows[e->RowIndex]->Cells[0]->Value;

            if (idVal != nullptr) {
                System::String^ currentId = idVal->ToString()->Trim();

                
                if (!modifiedIds->Contains(currentId)) {
                    modifiedIds->Add(currentId);
                }
            }
        }
    }

    //получаем минимальный id 
    int GetMinUnusedId(System::String^ filePath) {
        
        if (!System::IO::File::Exists(filePath)) return 1;

        
        System::Collections::Generic::List<int>^ busyIds = gcnew System::Collections::Generic::List<int>();

        System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(filePath, System::Text::Encoding::GetEncoding(1251));
        System::String^ line;

        while ((line = reader->ReadLine()) != nullptr) {
            if (System::String::IsNullOrWhiteSpace(line)) continue;

            array<System::String^>^ fields = line->Split('\t');
            if (fields->Length > 0) {
                int currentId = 0;
               
                if (System::Int32::TryParse(fields[0]->Trim(), currentId)) {
                    busyIds->Add(currentId);
                }
            }
        }
        reader->Close();

        
        busyIds->Sort();

        int targetId = 1;
        for (int i = 0; i < busyIds->Count; i++) {
            if (busyIds[i] == targetId) {
                targetId++; 
            }
            else if (busyIds[i] > targetId) {
                break; 
            }
        }

        return targetId;
    }

    //проверка на ввод
    int proverka_data(System::String^ strprov)
    {
        if (System::String::IsNullOrWhiteSpace(strprov) || strprov->Length < 4)
            return 0;

        array<String^>^ provprov = strprov->Split('\t');

        // Проверка количества полей (ID + 7 полей = 8)
        if (provprov->Length < 8)
        {
            MessageBox::Show("Неверный формат строки: недостаточно полей.", "Ошибка");
            return 0;
        }

        // Проверка на пустые значения ключевых полей (индексы 1-7)
        for (int i = 1; i <= 7; i++)
        {
            if (System::String::IsNullOrWhiteSpace(provprov[i]))
            {
                MessageBox::Show("Все поля должны быть заполнены.", "Ошибка");
                return 0;
            }
        }

        // Проверка возраста (поле 2)
        try
        {
            int b = Convert::ToInt32(provprov[2]->Trim());
            if (b < 1926 || b > 2010)
            {
                MessageBox::Show("Ошибка! Возраст должен быть целым числом от 1926 до 2010.",
                    "Неверный формат");
                return 0;
            }
        }
        catch (Exception^)
        {
            MessageBox::Show("Ошибка! Возраст должен быть целым числом.",
                "Неверный формат");
            return 0;
        }
        //проверка группы 

        try {
            if (provprov[3]->Contains("\n")) {
                MessageBox::Show("Группа не должны содержать сивола новой строки",
                    "Неверный формат");
                return 0;
            }
        }
        catch (Exception^)
        {
            MessageBox::Show("Ошибка!",
                "Неверный формат");
            return 0;
        }


        // Проверка оценок (поле 4)
        try
        {
           
            array<String^>^ marki = provprov[4]->Split(
                gcnew array<wchar_t>{' '}, StringSplitOptions::RemoveEmptyEntries);

            if (marki->Length != 9)
            {
                MessageBox::Show("Оценки должны содержать ровно 9 цифр от 0 до 5!",
                    "Неверный формат");
                return 0;
            }

            if (provprov[4]->Contains("\n")) {
                MessageBox::Show("Оценки не должны содержать сивола новой строки",
                    "Неверный формат");
                return 0;
            }

            for (int i = 0; i < marki->Length; i++)
            {
                int mark = Convert::ToInt32(marki[i]->Trim());
                if (mark < 0 || mark > 5)
                {
                    MessageBox::Show("Каждая оценка должна быть от 0 до 5!",
                        "Неверный формат");
                    return 0;
                }
            }
        }
        catch (Exception^)
        {
            MessageBox::Show("Ошибка! Оценки должны быть целыми числами от 0 до 5.",
                "Неверный формат");
            return 0;
        }

        // Проверка ФИО на отсутствие цифр (поле 1)
        for (int i = 0; i < provprov[1]->Length; i++)
        {
            if (Char::IsDigit(provprov[1][i])|| provprov[1][i]=='\n')
            {
                MessageBox::Show("Ошибка! ФИО не должно содержать цифр и знака переноса строки.",
                    "Неверный формат");
                return 0;
            }
        }

        return 1; // все проверки пройдены
    }




    void Pols_main_form::Save_data_button_Click(System::Object^ sender, System::EventArgs^ e)
    {
        String^ sourcePath = "database.txt";
        String^ tempPath = "database_temp.txt";

        
        for (int i = 0; i < dataGridViewPols->Rows->Count; i++)
        {
            if (dataGridViewPols->Rows[i]->IsNewRow) continue;

            
            System::Object^ fioCellCheck = dataGridViewPols->Rows[i]->Cells[1]->Value;
            if (fioCellCheck == nullptr || String::IsNullOrWhiteSpace(fioCellCheck->ToString())) {
                continue; // Строка пустая, полностью игнорируем её и не отправляем на проверку ошибок
            }

            // Строка считается новой, если ID пуст
            bool isNew = (dataGridViewPols->Rows[i]->Cells[0]->Value == nullptr ||
                String::IsNullOrWhiteSpace(dataGridViewPols->Rows[i]->Cells[0]->Value->ToString()));

            // Строка изменена, если её ID есть в списке modifiedIds
            bool isModified = false;
            if (dataGridViewPols->Rows[i]->Cells[0]->Value != nullptr) {
                isModified = (modifiedIds != nullptr && modifiedIds->Contains(
                    dataGridViewPols->Rows[i]->Cells[0]->Value->ToString()->Trim()));
            }

            if (isNew || isModified)
            {
                String^ line = "0" + "\t" + BuildStringFromRow(i);
                if (!proverka_data(line))
                {
                    // Ошибка уже показана в proverka_data, просто выходим
                    return;
                }
            }
        }


        bool hasNewRows = false;

      
        System::IO::StreamWriter^ appendWriter = nullptr;
        try
        {
            appendWriter = gcnew System::IO::StreamWriter(sourcePath, true, System::Text::Encoding::GetEncoding(1251));

            for (int i = 0; i < dataGridViewPols->Rows->Count; i++)
            {
                if (dataGridViewPols->Rows[i]->IsNewRow) continue;

                
                System::Object^ fioCell = dataGridViewPols->Rows[i]->Cells[1]->Value;
                if (fioCell == nullptr || System::String::IsNullOrWhiteSpace(fioCell->ToString())) {
                    continue; 
                }

                if (dataGridViewPols->Rows[i]->Cells[0]->Value == nullptr ||
                    String::IsNullOrWhiteSpace(dataGridViewPols->Rows[i]->Cells[0]->Value->ToString()))
                {
                    // Получаем минимальный свободный ID
                    appendWriter->Close();
                    int newId = GetMinUnusedId(sourcePath);
                    dataGridViewPols->Rows[i]->Cells[0]->Value = newId.ToString();
                    appendWriter = gcnew System::IO::StreamWriter(sourcePath, true, System::Text::Encoding::GetEncoding(1251));
                    String^ newLine = BuildStringFromRow(i);
                    appendWriter->WriteLine(newId.ToString() + "\t" + newLine);
                    hasNewRows = true;
                }
            }
        }
        finally
        {
            if (appendWriter != nullptr)
                appendWriter->Close();
        }

        
        if (modifiedIds != nullptr && modifiedIds->Count > 0)
        {
            System::IO::StreamReader^ reader = nullptr;
            System::IO::StreamWriter^ tempWriter = nullptr;
            try
            {
                reader = gcnew System::IO::StreamReader(sourcePath, System::Text::Encoding::GetEncoding(1251));
                tempWriter = gcnew System::IO::StreamWriter(tempPath, false, System::Text::Encoding::GetEncoding(1251));

                String^ line;
                while ((line = reader->ReadLine()) != nullptr)
                {
                    if (String::IsNullOrWhiteSpace(line)) continue;

                    array<String^>^ fields = line->Split('\t');
                    String^ fileId = fields[0]->Trim();

                    if (modifiedIds->Contains(fileId))
                    {
                        
                        bool found = false;
                        for (int i = 0; i < dataGridViewPols->Rows->Count; i++)
                        {
                            if (dataGridViewPols->Rows[i]->IsNewRow) continue;

                            
                            if (dataGridViewPols->Rows[i]->Cells[0]->Value == nullptr) continue;

                            String^ gridId = dataGridViewPols->Rows[i]->Cells[0]->Value->ToString()->Trim();
                            if (gridId == fileId)
                            {
                                tempWriter->WriteLine(gridId + "\t" + BuildStringFromRow(i));
                                found = true;
                                break;
                            }
                        }
                        if (!found) 
                            tempWriter->WriteLine(line);
                    }
                    else
                    {
                        tempWriter->WriteLine(line);
                    }
                }
            }
            finally
            {
                if (reader != nullptr) reader->Close();
                if (tempWriter != nullptr) tempWriter->Close();
            }

            // Замена оригинального файла временным
            System::IO::File::Delete(sourcePath);
            System::IO::File::Move(tempPath, sourcePath);

            modifiedIds->Clear();
        }

        
        if (hasNewRows || (modifiedIds != nullptr && modifiedIds->Count == 0))
            MessageBox::Show("Изменения успешно сохранены в БД!", "Успех");
    }

}

