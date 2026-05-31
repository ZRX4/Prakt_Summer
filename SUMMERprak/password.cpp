#include "Pols_main_form.h"
#include "MainForm.h"   
#include "Login_form.h" 

namespace SUMMERprak {

	void Login_form::mainToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MainForm^ mq = gcnew MainForm();
		mq->Show();
		this->Hide();
	}


	void Login_form::pass_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->pass_text->Text == "qwert1234") {
			Pols_main_form^ op = gcnew Pols_main_form(1);
			op->Show();
			this->Hide();
		}
		else {
			MessageBox::Show("Неверный пароль", "Ошибка");
		}
	}
}