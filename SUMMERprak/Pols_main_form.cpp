#include "Pols_main_form.h"
#include "MainForm.h"   
#include <io.h>


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
        this->dataGridViewPols->ColumnHeadersDefaultCellStyle->WrapMode = System::Windows::Forms::DataGridViewTriState::True;

        // 2. Отключаем авто-высоту шапки и задаем её вручную (например, 45 пикселей, чтобы влезло две строки)
        this->dataGridViewPols->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
        this->dataGridViewPols->ColumnHeadersHeight = 45;

        // 2. Включаем автоматическое растяжение столбцов СТРОГО по ширине текста в шапке
        this->dataGridViewPols->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::ColumnHeader;
        this->dataGridViewPols->Columns[1]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
        this->dataGridViewPols->Columns[4]->HeaderText = "Оценки\n1 2 3 4 5 6 7 8 9";


        // 5. Настраиваем ширину столбца оценок, чтобы цифры не переносились хаотично
        this->dataGridViewPols->Columns[4]->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
        this->dataGridViewPols->Columns[4]->Width = 140; // Элегантно вместит все 9 цифр с пробелами в один ряд


        if (this->status == 1) {
            this->dataGridViewPols->ReadOnly = false;              // Разрешаем редактировать ячейки
            this->dataGridViewPols->AllowUserToAddRows = true;
            delet_pols_button->Visible = true;
            this->dataGridViewPols->Columns[0]->ReadOnly = true;
            delet_text_box->Visible = true;
            id_delet_label->Visible = true;
            this->Save_data_button->Visible = true;
            this->Text = "База данных в пежиме администратора";
        }
        else {
            this->dataGridViewPols->ReadOnly = true;               // Запрещаем любое редактирование
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
        System::String^ sourcePath = "database.txt";      // Ваш исходный файл
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
            // Разбиваем строку по табуляции, чтобы узнать ID
            bool rezf = false;
            array<System::String^>^ fields = line->Split('\t');

            for (int i = 0; i < id_del->Length; i++) {
                if (fields->Length > 0 && System::String::Compare(fields[0]->Trim(), id_del[i]->Trim()) == 0) {
                    rezf = true;
                    printline = printline + "Успешное удаление " + id_del[i] + "\n";
                } // ПРОПУСКАЕМ эту строку, не записываем её во временный файл
            }
            if (rezf) {
                found = true; continue;
            }
            // Все остальные строки записываем обратно
            writer->WriteLine(line);
        }

        reader->Close();
        writer->Close();
        if (found) {
            // Удаляем старый файл базы данных
            System::IO::File::Delete(sourcePath);
            // Переименовываем временный файл в основной
            System::IO::File::Move(tempPath, sourcePath);

            System::Windows::Forms::MessageBox::Show(printline);
        }
        else {
            // Если ничего не нашли, просто удаляем пустой временный файл
            System::IO::File::Delete(tempPath);
            System::Windows::Forms::MessageBox::Show("id Для удаления не найдены");
        }

        Pols_main_form::LoadDataFromFile();
    }

    void Pols_main_form::dataGridViewPols_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
        if (e->RowIndex >= 0 && !dataGridViewPols->Rows[e->RowIndex]->IsNewRow) {

            // Берем ID текущей изменённой строки
            System::Object^ idVal = dataGridViewPols->Rows[e->RowIndex]->Cells[0]->Value;

            if (idVal != nullptr) {
                System::String^ currentId = idVal->ToString()->Trim();

                // Если этого ID еще нет в списке изменённых, добавляем его
                if (!modifiedIds->Contains(currentId)) {
                    modifiedIds->Add(currentId);
                }
            }
        }
    }



    void Pols_main_form::Save_data_button_Click(System::Object^ sender, System::EventArgs^ e) {

        System::String^ sourcePath = "database.txt";
        System::String^ tempPath = "database_temp.txt";

        bool hasNewRows = false;

        // === ЭТАП 1: ДОЗАПИСЬ ТОЛЬКО НОВЫХ СТРОК В КОНЕЦ ФАЙЛА ===
        // Открываем файл в режиме дозаписи (true)
        System::IO::StreamWriter^ appendWriter = gcnew System::IO::StreamWriter(sourcePath, true, System::Text::Encoding::GetEncoding(1251));

        for (int i = 0; i < dataGridViewPols->Rows->Count; i++) {
            if (dataGridViewPols->Rows[i]->IsNewRow) continue;

            // Если ячейка ID пустая — это абсолютно новый добавленный пользователь
            if (dataGridViewPols->Rows[i]->Cells[0]->Value == nullptr ||
                System::String::IsNullOrWhiteSpace(dataGridViewPols->Rows[i]->Cells[0]->Value->ToString())) {

                // Временно закрываем поток дозаписи, генерируем минимальный свободный ID и открываем снова
                appendWriter->Close();
                int newId = 0; // Ваша функция из прошлых шагов
                appendWriter = gcnew System::IO::StreamWriter(sourcePath, true, System::Text::Encoding::GetEncoding(1251));

                // Записываем сгенерированный ID в таблицу
                dataGridViewPols->Rows[i]->Cells[0]->Value = newId.ToString();

                // Собираем данные строки и пишем в конец файла
                System::String^ newLine = BuildStringFromRow(i);
                appendWriter->WriteLine(newLine);
                hasNewRows = true;
            }
        }
        appendWriter->Close();


        // === ЭТАП 2: ТОЧЕЧНОЕ ОБНОВЛЕНИЕ ИЗМЕНЁННЫХ СТРОК ===
        // Выполняется только в том случае, если в процессе редактирования таблицы менялись старые данные
        if (modifiedIds->Count > 0) {
            System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(sourcePath, System::Text::Encoding::GetEncoding(1251));
            System::IO::StreamWriter^ tempWriter = gcnew System::IO::StreamWriter(tempPath, false, System::Text::Encoding::GetEncoding(1251));
            System::String^ line;

            while ((line = reader->ReadLine()) != nullptr) {
                if (System::String::IsNullOrWhiteSpace(line)) continue;

                array<System::String^>^ fields = line->Split('\t');
                System::String^ fileId = fields[0]->Trim();

                // Если ID текущей строки из файла совпадает с одним из изменённых ID
                if (modifiedIds->Contains(fileId)) {
                    // Ищем эту строку в таблице DataGridView, чтобы взять обновленные данные
                    for (int i = 0; i < dataGridViewPols->Rows->Count; i++) {
                        if (dataGridViewPols->Rows[i]->IsNewRow) continue;

                        if (dataGridViewPols->Rows[i]->Cells[0]->Value->ToString()->Trim() == fileId) {
                            // Вместо старой строки из файла пишем в темп-файл обновленную строку из таблицы
                            tempWriter->WriteLine(BuildStringFromRow(i));
                            break;
                        }
                    }
                }
                else {
                    // Если строка не менялась, переносим её как есть
                    tempWriter->WriteLine(line);
                }
            }

            reader->Close();
            tempWriter->Close();

            // Заменяем оригинальный файл временным файлом с обновлениями
            System::IO::File::Delete(sourcePath);
            System::IO::File::Move(tempPath, sourcePath);

            // Очищаем список изменений после успешного сохранения
            modifiedIds->Clear();
        }

        // Сообщаем пользователю о результате работы
        if (hasNewRows || modifiedIds->Count == 0) {
            MessageBox::Show("Изменения успешно сохранены в БД!", "Успех");
        }



    }
}

