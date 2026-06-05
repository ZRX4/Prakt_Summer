#include "MainForm.h" // Имя вашей формы
#include "Pols_main_form.h"
#include "FilterForm.h"
#include "Login_form.h"
#include"Game.h"
#include "windows.h"
#pragma comment(lib, "User32.lib")

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {

    SetProcessDPIAware();

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Вместо Project1 укажите пространство имен (обычно совпадает с именем проекта)
    SUMMERprak::MainForm form;
    Application::Run(% form);
    return 0;
}