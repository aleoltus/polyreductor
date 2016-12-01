#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
#if _DEBUG
	if (AllocConsole())   // <-- http://msdn.microsoft.com/en-us/library/windows/desktop/ms681952(v=vs.85).aspx
		if (!AttachConsole(ATTACH_PARENT_PROCESS));  // -1 == ATTACH_PARENT_PROCESS or Process ID
			//System::Windows::MessageBox::Show(L"Unable to attach console window", L"Error", System::Windows::MessageBoxButton::OK, System::Windows::MessageBoxImage::Exclamation);
#endif

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	PolyReductorProjectttttt::MyForm form;
	Application::Run(%form);

#if _DEBUG
	FreeConsole();       // <-- http://msdn.microsoft.com/en-us/library/windows/desktop/ms683150(v=vs.85).aspx
#endif
}
