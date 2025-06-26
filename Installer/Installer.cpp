#include "Installer.h"

using namespace System;

using namespace System::Windows::Forms;

[STAThread]

int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Installer::Installer form;
    form.Width = 1920;
    form.Height = 1080;
    Application::Run(% form);
    return 0;
}