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

	using namespace System::IO;
	using namespace System::Collections::Generic;
	using namespace System::Xml::Serialization;

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

			rand = gcnew System::Random();
			heightBandes = gcnew array<int>(nbBandes);
			for (int i = 0; i < nbBandes; i++)
			{
				heightBandes[i] = 10; //  base height
			}

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
	private: System::String^ currentAudioName;
	private: bool isCurrentAudioFinished;

	protected:

	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ filesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::TrackBar^ trackBarVolume;






	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::CheckBox^ checkBoxLoop;
	private: System::Windows::Forms::ToolStripMenuItem^ playlistToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ addPlaylistButton;


	private: System::Windows::Forms::ToolStripMenuItem^ loadPlaylistToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearPlaylistToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ savePlaylistToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ CurrentSong;
	private: System::Windows::Forms::Timer^ ToolTimer;
	private: System::Windows::Forms::Button^ button5;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ animation_Timer;
		   int nbBandes = 100;
		   array<int>^ heightBandes;
	private: System::Windows::Forms::Panel^ panelEqualizer;
		   System::Random^ rand;
	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->filesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->playlistToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addPlaylistButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadPlaylistToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->savePlaylistToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearPlaylistToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trackBarVolume = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->checkBoxLoop = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->CurrentSong = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->animation_Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->ToolTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelEqualizer = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarVolume))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->filesToolStripMenuItem,
					this->playlistToolStripMenuItem
			});
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
			this->filesToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->filesToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->openToolStripMenuItem->Text = L"Load audio file";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::OpenMenuFile);
			// 
			// playlistToolStripMenuItem
			// 
			this->playlistToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->addPlaylistButton,
					this->loadPlaylistToolStripMenuItem, this->savePlaylistToolStripMenuItem, this->clearPlaylistToolStripMenuItem
			});
			this->playlistToolStripMenuItem->Name = L"playlistToolStripMenuItem";
			this->playlistToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->playlistToolStripMenuItem->Text = L"Playlist";
			// 
			// addPlaylistButton
			// 
			this->addPlaylistButton->Name = L"addPlaylistButton";
			this->addPlaylistButton->Size = System::Drawing::Size(180, 22);
			this->addPlaylistButton->Text = L"Add to playlist";
			this->addPlaylistButton->Click += gcnew System::EventHandler(this, &MyForm::addPlaylistButton_Click);
			// 
			// loadPlaylistToolStripMenuItem
			// 
			this->loadPlaylistToolStripMenuItem->Name = L"loadPlaylistToolStripMenuItem";
			this->loadPlaylistToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->loadPlaylistToolStripMenuItem->Text = L"Load playlist";
			this->loadPlaylistToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loadPlaylistToolStripMenuItem_Click);
			// 
			// savePlaylistToolStripMenuItem
			// 
			this->savePlaylistToolStripMenuItem->Name = L"savePlaylistToolStripMenuItem";
			this->savePlaylistToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->savePlaylistToolStripMenuItem->Text = L"Save playlist";
			this->savePlaylistToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::savePlaylistToolStripMenuItem_Click);
			// 
			// clearPlaylistToolStripMenuItem
			// 
			this->clearPlaylistToolStripMenuItem->Name = L"clearPlaylistToolStripMenuItem";
			this->clearPlaylistToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->clearPlaylistToolStripMenuItem->Text = L"Clear playlist";
			// 
			// trackBarVolume
			// 
			this->trackBarVolume->Location = System::Drawing::Point(281, 3);
			this->trackBarVolume->Name = L"trackBarVolume";
			this->trackBarVolume->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBarVolume->Size = System::Drawing::Size(45, 131);
			this->trackBarVolume->TabIndex = 6;
			this->trackBarVolume->Value = 5;
			this->trackBarVolume->Scroll += gcnew System::EventHandler(this, &MyForm::SoundTrackBar_Scroll);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->groupBox1->Controls->Add(this->listBox1);
			this->groupBox1->Location = System::Drawing::Point(344, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 434);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Playlist";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(6, 19);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(188, 407);
			this->listBox1->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->panel1->Controls->Add(this->panelEqualizer);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->checkBoxLoop);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->trackBarVolume);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Location = System::Drawing::Point(12, 36);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(551, 464);
			this->panel1->TabIndex = 9;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(18, 207);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Skip";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
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
			this->groupBox2->Controls->Add(this->CurrentSong);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(18, 25);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(245, 61);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Current Song";
			// 
			// CurrentSong
			// 
			this->CurrentSong->AutoSize = true;
			this->CurrentSong->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CurrentSong->Location = System::Drawing::Point(16, 26);
			this->CurrentSong->Name = L"CurrentSong";
			this->CurrentSong->Size = System::Drawing::Size(10, 13);
			this->CurrentSong->TabIndex = 0;
			this->CurrentSong->Text = L"-";
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
			// animation_Timer
			// 
			this->animation_Timer->Enabled = true;
			this->animation_Timer->Interval = 80;
			this->animation_Timer->Tick += gcnew System::EventHandler(this, &MyForm::animationTimer_tick);
			// 
			// ToolTimer
			// 
			this->ToolTimer->Interval = 50;
			this->ToolTimer->Tick += gcnew System::EventHandler(this, &MyForm::ToolTimer_Tick);
			// 
			// panelEqualizer
			// 
			this->panelEqualizer->BackColor = System::Drawing::Color::Black;
			this->panelEqualizer->Location = System::Drawing::Point(113, 284);
			this->panelEqualizer->Name = L"panelEqualizer";
			this->panelEqualizer->Size = System::Drawing::Size(200, 100);
			this->panelEqualizer->TabIndex = 0;
			this->panelEqualizer->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panelEqualizer_Paint);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarVolume))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
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
			float volume = static_cast<float>(trackBarVolume->Value) / 100.0f;

			int result = Play(nativeString);

			isCurrentAudioFinished = false;

			//Sound polling
			ToolTimer->Start();

			ToggleLoop(nativeString, checkBoxLoop->Checked);
			SetVolume(nativeString, volume);
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
			Stop(ManagedToNativeString(openedFileName).c_str());

			openedFileName = openFileDialog1->FileName;

			System::String^ audioName = GetAudioName(openFileDialog1->FileName);
			CurrentSong->Text = audioName;
		}
		else
		{
			openedFileName = "-";
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
				//MessageBox::Show("Sound Paused");
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
				//MessageBox::Show("Sound Stopped");
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
				//MessageBox::Show("Sound Resumed");
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
		if (String::IsNullOrEmpty(openedFileName))
		{
			return;
		}

		msclr::interop::marshal_context context;

		const char* nativeString = context.marshal_as<const char*>(openedFileName);

		float volume = static_cast<float>(trackBarVolume->Value) / 100.0f;
		SetVolume(nativeString, volume);
	}

	private: System::Void addPlaylistButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::OpenFileDialog^ ofd = (gcnew System::Windows::Forms::OpenFileDialog());

		ofd->Filter = "Fichiers WAV(*.wav)|*.wav|"
			"Fichiers OGG(*.ogg)|*.ogg|"
			"Tous les fichiers (*.*)|*.*";

		System::Windows::Forms::DialogResult resultat = ofd->ShowDialog();
		if (resultat == System::Windows::Forms::DialogResult::OK)
		{
			std::string audioExtension = GetAudioExtension(ofd->FileName);
			if (audioExtension == ".wav" || audioExtension == ".ogg")
			{
				System::String^ audioName = GetAudioName(ofd->FileName);
				listBox1->Items->Add(audioName);
				AddToPlaylist(ofd->FileName);
			}
			else
			{
				MessageBox::Show("Can't add this to playlist");
			}
		}
		else
		{
			MessageBox::Show("Failed to open file");
		}
	}
	private: System::Void ToolTimer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		if (IsAudioFinished(ManagedToNativeString(openedFileName)) && !isCurrentAudioFinished)
		{
			isCurrentAudioFinished = true;
			bool result = PlayNextFromPlaylist();
			if (result)
			{
				if (listBox1->Items->Count > 0)
				{
					openedFileName = msclr::interop::marshal_as<System::String^>(GetPlayingAudioName());
					CurrentSong->Text = listBox1->Items[0]->ToString();
					listBox1->Items->RemoveAt(0);
					isCurrentAudioFinished = false;
				}
			}
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		bool result = PlayNextFromPlaylist();
		if (result)
		{
			if (listBox1->Items->Count > 0)
			{

				openedFileName = msclr::interop::marshal_as<System::String^>(GetPlayingAudioName());
				CurrentSong->Text = listBox1->Items[0]->ToString();
				listBox1->Items->RemoveAt(0);

				msclr::interop::marshal_context context;
				const char* nativeString = context.marshal_as<const char*>(openedFileName);

				float volume = static_cast<float>(trackBarVolume->Value) / 100.0f;
				SetVolume(nativeString, volume);
				isCurrentAudioFinished = false;

				//Sound polling
				ToolTimer->Start();
			}
		}
	}
	private: System::Void panelEqualizer_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void animationTimer_tick(System::Object^ sender, System::EventArgs^ e) {
		int heightMax = panelEqualizer->Height - 10;

		for (unsigned int i = 0; i < nbBandes; i++)
		{
			heightBandes[i] = rand->Next(10, heightMax);
		}

		panelEqualizer->Invalidate();
	}
	private: System::Void savePlaylistToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Fichiers XML (*.xml)|*.xml|Tous les fichiers (*.*)|*.*";
		saveFileDialog1->Title = "Save playlist";
		saveFileDialog1->DefaultExt = "xml";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			List<String^>^ listData = gcnew List<String^>();
			for each (Object ^ item in listBox1->Items)
			{
				std::string filename = GetFileName(ManagedToNativeString(item->ToString()));
				System::String^ managedString = gcnew System::String(filename.c_str());
				listData->Add(managedString);
			}

			StreamWriter^ writer = gcnew StreamWriter(saveFileDialog1->FileName);
			XmlSerializer^ serializer = gcnew XmlSerializer(List<String^>::typeid);

			serializer->Serialize(writer, listData);
			writer->Close();
		}
	}


	private: System::Void loadPlaylistToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Fichiers XML (*.xml)|*.xml|Tous les fichiers (*.*)|*.*";
		openFileDialog1->Title = "Load playlist";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			try
			{
				StreamReader^ reader = gcnew StreamReader(openFileDialog1->FileName);
				XmlSerializer^ serializer = gcnew XmlSerializer(List<String^>::typeid);

				List<String^>^ listData = safe_cast<List<String^>^>(serializer->Deserialize(reader));
				reader->Close();

				listBox1->BeginUpdate();
				listBox1->Items->Clear();
				for each (String ^ item in listData)
				{
					listBox1->Items->Add(GetAudioName(item));
					AddToPlaylist(item);
					Stop(ManagedToNativeString(openedFileName).c_str());
				}
				listBox1->EndUpdate();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error when loading " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	};
}
