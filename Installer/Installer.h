#pragma once
#include <stdlib.h>
#include <exception>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace Installer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::WindowsAPICodePack::Dialogs;
	using namespace System::Diagnostics;
	using namespace System::IO;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Installer : public System::Windows::Forms::Form
	{
		String^ selectedPath;
	public:
		Installer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Installer()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::GroupBox^ installWindow;
	private: System::Windows::Forms::Button^ installLocation;
	private: System::Windows::Forms::GroupBox^ installingWindow;
	private: System::Windows::Forms::Label^ installingMessage;
	private: System::Windows::Forms::GroupBox^ finishedWindow;
	private: System::Windows::Forms::Label^ quit;
	private: System::Windows::Forms::Button^ openNext;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->installWindow = (gcnew System::Windows::Forms::GroupBox());
			this->installLocation = (gcnew System::Windows::Forms::Button());
			this->installingWindow = (gcnew System::Windows::Forms::GroupBox());
			this->installingMessage = (gcnew System::Windows::Forms::Label());
			this->finishedWindow = (gcnew System::Windows::Forms::GroupBox());
			this->quit = (gcnew System::Windows::Forms::Label());
			this->openNext = (gcnew System::Windows::Forms::Button());
			this->installWindow->SuspendLayout();
			this->installingWindow->SuspendLayout();
			this->finishedWindow->SuspendLayout();
			this->SuspendLayout();
			// 
			// installWindow
			// 
			this->installWindow->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->installWindow->Controls->Add(this->installLocation);
			this->installWindow->Location = System::Drawing::Point(0, 0);
			this->installWindow->Name = L"installWindow";
			this->installWindow->Size = System::Drawing::Size(1920, 1080);
			this->installWindow->TabIndex = 0;
			this->installWindow->TabStop = false;
			// 
			// installLocation
			// 
			this->installLocation->BackColor = System::Drawing::SystemColors::ControlDark;
			this->installLocation->Location = System::Drawing::Point(795, 511);
			this->installLocation->Name = L"installLocation";
			this->installLocation->Size = System::Drawing::Size(331, 58);
			this->installLocation->TabIndex = 0;
			this->installLocation->Text = L"Where do you want to install this software\?";
			this->installLocation->UseVisualStyleBackColor = false;
			this->installLocation->Click += gcnew System::EventHandler(this, &Installer::Install);
			// 
			// installingWindow
			// 
			this->installingWindow->AutoSize = true;
			this->installingWindow->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->installingWindow->Controls->Add(this->installingMessage);
			this->installingWindow->Location = System::Drawing::Point(0, 0);
			this->installingWindow->Name = L"installingWindow";
			this->installingWindow->Size = System::Drawing::Size(1920, 1080);
			this->installingWindow->TabIndex = 1;
			this->installingWindow->TabStop = false;
			this->installingWindow->Visible = false;
			// 
			// installingMessage
			// 
			this->installingMessage->BackColor = System::Drawing::SystemColors::ControlDark;
			this->installingMessage->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->installingMessage->Location = System::Drawing::Point(795, 511);
			this->installingMessage->Name = L"installingMessage";
			this->installingMessage->Size = System::Drawing::Size(331, 58);
			this->installingMessage->TabIndex = 0;
			this->installingMessage->Text = L"Installing components...";
			this->installingMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// finishedWindow
			// 
			this->finishedWindow->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->finishedWindow->Controls->Add(this->quit);
			this->finishedWindow->Controls->Add(this->openNext);
			this->finishedWindow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->finishedWindow->Location = System::Drawing::Point(0, 0);
			this->finishedWindow->Name = L"finishedWindow";
			this->finishedWindow->Size = System::Drawing::Size(1920, 1080);
			this->finishedWindow->TabIndex = 0;
			this->finishedWindow->TabStop = false;
			// 
			// quit
			// 
			this->quit->BackColor = System::Drawing::SystemColors::ControlDark;
			this->quit->Location = System::Drawing::Point(795, 511);
			this->quit->Name = L"quit";
			this->quit->Size = System::Drawing::Size(331, 58);
			this->quit->TabIndex = 0;
			this->quit->Text = L"You can close this app now";
			this->quit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// openNext
			// 
			this->openNext->BackColor = System::Drawing::SystemColors::ControlDark;
			this->openNext->Location = System::Drawing::Point(795, 569);
			this->openNext->Name = L"openNext";
			this->openNext->Size = System::Drawing::Size(331, 58);
			this->openNext->TabIndex = 0;
			this->openNext->Text = L"Or open the installed program";
			this->openNext->UseVisualStyleBackColor = false;
			this->openNext->Click += gcnew System::EventHandler(this, &Installer::Open);
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->installWindow);
			this->Name = L"MyForm";
			this->Text = L"Object detector";
			this->installWindow->ResumeLayout(false);
			this->installingWindow->ResumeLayout(false);
			this->finishedWindow->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Install(System::Object^ sender, System::EventArgs^ e) {

		CommonOpenFileDialog^ dialog = gcnew CommonOpenFileDialog();
		dialog->IsFolderPicker = true;

		//String^ selectedPath = "";

		if (dialog->ShowDialog() != CommonFileDialogResult::Ok) return;
		selectedPath = dialog->FileName;


		array<String^>^ files = Directory::GetFiles(selectedPath);
		if (files->Length != 0) {
			MessageBox::Show("Program already installed");
			return;
		}

		/*
		array<String^>^ userFiles = Directory::GetFileSystemEntries("C:\\Users");


		bool foundLocation = false;
		for (int i = 0; i < userFiles->Length; i++) {
			array<String^>^ subArray = Directory::GetFileSystemEntries(userFiles[i]);
			for (int j = 0; j < subArray->Length; j++) {
				if (subArray[j]->EndsWith("Documents") && !subArray[j]->Contains("All Users")) {
					FileStream^ saveFile = File::Create(subArray[j] + "\\ImageDetection.txt");
					StreamWriter^ sw = gcnew StreamWriter(saveFile);
					sw->WriteLine(selectedPath);
					sw->Close();

					foundLocation = true;
					break;
				}
			}
			if (foundLocation)
				break;
		}
		*/


		installWindow->Visible = false;
		installingWindow->Visible = true;

		this->Controls->Remove(installLocation);
		this->Controls->Add(installingWindow);
		Process::Start("cmd.exe", "/C pip install torch numpy pillow pickle scikit-learn");
		Process::Start("cmd.exe", "/C git clone https://github.com/DeanWinchester01/ObjectDetection.git \"" + selectedPath + "\"");
		this->Controls->Remove(installingWindow);
		this->Controls->Add(finishedWindow);
	}


	private: System::Void Open(System::Object^ sender, System::EventArgs^ e) {
		String^ fullPath = "\"" + selectedPath + "\\ObjectDetection.exe\"";
		Process::Start("cmd.exe", "/C start \"\" " + fullPath);
		Application::Exit();
	}
	};
}
