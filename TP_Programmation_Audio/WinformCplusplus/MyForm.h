#include "Player.h"

#include <msclr/marshal.h>
#define	WATER_STREAM_0		"Ruisseau_Escattes_01.wav"
#define	WATER_STREAM_1		"Ruisseau_Escattes_02.wav"
#pragma once

namespace WinformCplusplus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			openedFileName = System::String::Empty;

			init();
		}


	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::String^ openedFileName;

	protected:

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ filesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::TrackBar^ SoundTrackBar;




	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::CheckBox^ checkBoxLoop;







	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->filesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SoundTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkBoxLoop = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SoundTrackBar))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->filesToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(575, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// filesToolStripMenuItem
			// 
			this->filesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->filesToolStripMenuItem->Name = L"filesToolStripMenuItem";
			this->filesToolStripMenuItem->Size = System::Drawing::Size(42, 20);
			this->filesToolStripMenuItem->Text = L"Files";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::OpenMenuFile);
			// 
			// SoundTrackBar
			// 
			this->SoundTrackBar->Location = System::Drawing::Point(281, 3);
			this->SoundTrackBar->Name = L"SoundTrackBar";
			this->SoundTrackBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->SoundTrackBar->Size = System::Drawing::Size(45, 131);
			this->SoundTrackBar->TabIndex = 6;
			this->SoundTrackBar->Scroll += gcnew System::EventHandler(this, &MyForm::SoundTrackBar_Scroll);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->groupBox1->Location = System::Drawing::Point(344, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 434);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Playlist";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Controls->Add(this->checkBoxLoop);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->SoundTrackBar);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Location = System::Drawing::Point(12, 36);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(551, 464);
			this->panel1->TabIndex = 9;
			// 
			// checkBoxLoop
			// 
			this->checkBoxLoop->AutoSize = true;
			this->checkBoxLoop->Location = System::Drawing::Point(157, 96);
			this->checkBoxLoop->Name = L"checkBoxLoop";
			this->checkBoxLoop->Size = System::Drawing::Size(50, 17);
			this->checkBoxLoop->TabIndex = 9;
			this->checkBoxLoop->Text = L"Loop";
			this->checkBoxLoop->UseVisualStyleBackColor = true;
			this->checkBoxLoop->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxLoop_CheckedChanged);
			// 
			// groupBox2
			// 
			this->groupBox2->Location = System::Drawing::Point(18, 25);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(245, 61);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Current Song";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(18, 121);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Pause";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(18, 92);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(18, 149);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Resume";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(18, 178);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(575, 512);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"VeryBadTool";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SoundTrackBar))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// Fonction bouton pour jouer le sons
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		if (openedFileName != System::String::Empty)
		{
			marshal_context^ context = gcnew marshal_context();
			const char* nativeString = context->marshal_as<const char*>(openedFileName);
			Play(nativeString);
			ToggleLoop(nativeString, checkBoxLoop->Checked);
			delete context;
		}
		else
		{
			System::Windows::Forms::MessageBox::Show("No File selected");
		}
	}
		   //Fonction bouton pour récupérer le sons depuis l'explorateur de fichiers
	private: System::Void OpenMenuFile(System::Object^ sender, System::EventArgs^ e) {
		this->openFileDialog1->Filter = "Fichiers WAV(*.wav)|*.wav|"
										"Fichiers OGG(*.ogg)|*.ogg|"
										"Tous les fichiers (*.*)|*.*";

		System::Windows::Forms::DialogResult resultat = openFileDialog1->ShowDialog();
		if (resultat == System::Windows::Forms::DialogResult::OK)
		{
			openedFileName = openFileDialog1->FileName;
		}
		else
		{
			openedFileName = System::String::Empty;
		}
	}
		   // Fonction bouton pour mettre en pause le sons
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openedFileName != System::String::Empty)
		{
			marshal_context^ context = gcnew marshal_context();
			const char* nativeString = context->marshal_as<const char*>(openedFileName);
			int result = Pause(nativeString);
			if (result == 0)
			{
				MessageBox::Show("Sound Paused");
			}
			else
			{
				MessageBox::Show("Can't pause sound");
			}
			delete context;
		}
		else
		{
			MessageBox::Show("No File selected");
		}
	}
		   // Fonction bouton pour arrêter le sons
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openedFileName != System::String::Empty)
		{
			marshal_context^ context = gcnew marshal_context();
			const char* nativeString = context->marshal_as<const char*>(openedFileName);
			int result = Stop(nativeString);
			if (result == 0)
			{
				MessageBox::Show("Sound Stopped");
			}
			else
			{
				MessageBox::Show("Can't stop sound");
			}
			delete context;
		}
		else
		{
			MessageBox::Show("No File selected");
		}
	}
		   // Fonction bouton pour reprendre le déroulement du sons
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (openedFileName != System::String::Empty)
		{
			marshal_context^ context = gcnew marshal_context();
			const char* nativeString = context->marshal_as<const char*>(openedFileName);
			int result = Resume(nativeString);
			if (result == 0)
			{
				MessageBox::Show("Sound Resumed");
			}
			else
			{
				MessageBox::Show("Can't resume sound");
			}
			delete context;
		}
		else
		{
			MessageBox::Show("No File selected");
		}
	}



private: System::Void checkBoxLoop_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	marshal_context^ context = gcnew marshal_context();
	const char* nativeString = context->marshal_as<const char*>(openedFileName);

	ToggleLoop(nativeString, checkBoxLoop->Checked);
}
private: System::Void SoundTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {

}
};
}
