#include "Pols_main_form.h"
#include "MainForm.h"   
#include "Login_form.h" 
#include <msclr\marshal_cppstd.h>


namespace SUMMERprak {



	System::String^ ComputeSHA256(System::String^ input) {
		if (System::String::IsNullOrEmpty(input)) return "";

		array<System::Byte>^ inputBytes = System::Text::Encoding::UTF8->GetBytes(input);

		System::Security::Cryptography::SHA256^ sha256 = System::Security::Cryptography::SHA256::Create();
		array<System::Byte>^ hashBytes = sha256->ComputeHash(inputBytes);

		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();

		for (int i = 0; i < hashBytes->Length; i++) {
			sb->Append(hashBytes[i].ToString("x2"));
		}
		
		return sb->ToString();
	
	}

	void Login_form::mainToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MainForm^ mq = gcnew MainForm();
		mq->Show();
		this->Hide();
	}


	void Login_form::pass_button_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ enteredHash = ComputeSHA256(this->pass_text->Text);

		System::String^ correctHash = "0542d8871f7076b1c6ac0aa89a8ac6494f965f4edc7ade6c11c05ca516264b1c";

		if (System::String::Compare(enteredHash,correctHash)==0) {
			Pols_main_form^ op = gcnew Pols_main_form(1);
			op->Show();
			this->Hide();
		}
		else {
			MessageBox::Show("Неверный пароль", "Ошибка");
		}
	}
}