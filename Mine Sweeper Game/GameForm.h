#pragma once
#include "Cell.h"
#include <fstream>
#include <iostream>



//extern Cell **field;
static bool started;

void createField(Cell **field, int &width, int &height, int &mines, System::Windows::Forms::Form ^f, bool &started);
void openCell(Cell **field, int x, int y, int &width, int &height, int &mines, System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes, int &closedCells, bool &wasFirstClick);
void clearField(Cell **field, int &width, int &height);
void showMines(Cell **field, int &width, int &height, System::Windows::Forms::Form ^f);
void saveGame(Cell **field, int &width, int &height, int &mines, int &lifes, int &flags, int &time, bool &started, bool &wasFirstClicked);
Cell** loadGame(int &width, int &height, int &mines, int &lifes, int &time, int &flags, System::Windows::Forms::Form ^f, bool &started, bool &wasFirstClick, int &closedCells);

static Cell **field;
static int	width,
	height,
	mines,
	quantity_of_mines = 0,
	quantity_of_cells_width = 0,
	quantity_of_cells_height = 0,
	mb_open = 1,
	mb_flag = 2,
	mb_undefined = 3,
	lifes = 0,
	closedCells,
	time;
static bool wasFirstClick = false,
		    timerEnabled = false;
static int flags;

namespace MineSweeperGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStripDropDownButton^  MenuTCDDB;
	private: System::Windows::Forms::ToolStripMenuItem^  OptionsTSMI;

	private: System::Windows::Forms::ToolStripMenuItem^  RecordsTSMI;
	protected:

	protected:



	private: System::Windows::Forms::ToolStrip^  ToolsTS;



	private: System::Windows::Forms::FlowLayoutPanel^  OptionsMenuFLP;
	private: System::Windows::Forms::Button^  PresetsB;
	private: System::Windows::Forms::Button^  ControlB;
	private: System::Windows::Forms::Button^  CloseOptionsB;
	private: System::Windows::Forms::Panel^  PresetsP;

	private: System::Windows::Forms::FlowLayoutPanel^  DefaultPresetsFLP;
	private: System::Windows::Forms::RadioButton^  GPreset1RB;
	private: System::Windows::Forms::RadioButton^  GPreset2RB;
	private: System::Windows::Forms::RadioButton^  GPreset3RB;
	private: System::Windows::Forms::Panel^  ControlP;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  GCSetOpenInfo;

	private: System::Windows::Forms::Button^  GCOpenCellB;
	private: System::Windows::Forms::Label^  GCSetFlagInfo;

	private: System::Windows::Forms::Button^  GCSetFlagB;
	private: System::Windows::Forms::Label^  GCSetUndefined;

	private: System::Windows::Forms::Button^  GCSetUndef;
	private: System::Windows::Forms::GroupBox^  OptionsGB;

	private: System::Windows::Forms::ToolStripButton^  StartTSB;
	private: System::Windows::Forms::GroupBox^  RecordsGB;




	private: System::Windows::Forms::Button^  CloseRecordsB;
	private: System::Windows::Forms::Panel^  panel1;






	private: System::Windows::Forms::ToolStripTextBox^  TSTBMinesCounter;
	private: System::Windows::Forms::ToolStripLabel^  TSLInfo;






	private: System::Windows::Forms::Label^  GWidthInfo;
	private: System::Windows::Forms::TextBox^  GWidthTB;
	private: System::Windows::Forms::Label^  GHeightInfo;
	private: System::Windows::Forms::TextBox^  GHeightTB;
	private: System::Windows::Forms::Label^  GameMinesInfo;
	private: System::Windows::Forms::TextBox^  GMinesTB;
	private: System::Windows::Forms::RadioButton^  GRandomRB;
	private: System::Windows::Forms::TextBox^  GLifesTB;


	private: System::Windows::Forms::CheckBox^  GWrongCB;


	private: System::Windows::Forms::CheckBox^  GUnknownCB;


	private: System::Windows::Forms::ToolStripLabel^  TimerTSL;
	private: System::Windows::Forms::Timer^  Timer;


	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::RichTextBox^  richTextBox1;
private: System::Windows::Forms::ToolStripLabel^  TSLTime;





	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->ToolsTS = (gcnew System::Windows::Forms::ToolStrip());
			this->MenuTCDDB = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->OptionsTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RecordsTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StartTSB = (gcnew System::Windows::Forms::ToolStripButton());
			this->TSTBMinesCounter = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->TSLInfo = (gcnew System::Windows::Forms::ToolStripLabel());
			this->TimerTSL = (gcnew System::Windows::Forms::ToolStripLabel());
			this->TSLTime = (gcnew System::Windows::Forms::ToolStripLabel());
			this->OptionsMenuFLP = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->PresetsB = (gcnew System::Windows::Forms::Button());
			this->ControlB = (gcnew System::Windows::Forms::Button());
			this->CloseOptionsB = (gcnew System::Windows::Forms::Button());
			this->PresetsP = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->GWrongCB = (gcnew System::Windows::Forms::CheckBox());
			this->GUnknownCB = (gcnew System::Windows::Forms::CheckBox());
			this->GLifesTB = (gcnew System::Windows::Forms::TextBox());
			this->DefaultPresetsFLP = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GPreset1RB = (gcnew System::Windows::Forms::RadioButton());
			this->GPreset2RB = (gcnew System::Windows::Forms::RadioButton());
			this->GPreset3RB = (gcnew System::Windows::Forms::RadioButton());
			this->GWidthInfo = (gcnew System::Windows::Forms::Label());
			this->GWidthTB = (gcnew System::Windows::Forms::TextBox());
			this->GHeightInfo = (gcnew System::Windows::Forms::Label());
			this->GHeightTB = (gcnew System::Windows::Forms::TextBox());
			this->GameMinesInfo = (gcnew System::Windows::Forms::Label());
			this->GMinesTB = (gcnew System::Windows::Forms::TextBox());
			this->GRandomRB = (gcnew System::Windows::Forms::RadioButton());
			this->ControlP = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GCSetOpenInfo = (gcnew System::Windows::Forms::Label());
			this->GCOpenCellB = (gcnew System::Windows::Forms::Button());
			this->GCSetFlagInfo = (gcnew System::Windows::Forms::Label());
			this->GCSetFlagB = (gcnew System::Windows::Forms::Button());
			this->GCSetUndefined = (gcnew System::Windows::Forms::Label());
			this->GCSetUndef = (gcnew System::Windows::Forms::Button());
			this->OptionsGB = (gcnew System::Windows::Forms::GroupBox());
			this->RecordsGB = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->CloseRecordsB = (gcnew System::Windows::Forms::Button());
			this->Timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->ToolsTS->SuspendLayout();
			this->OptionsMenuFLP->SuspendLayout();
			this->PresetsP->SuspendLayout();
			this->panel1->SuspendLayout();
			this->DefaultPresetsFLP->SuspendLayout();
			this->ControlP->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->OptionsGB->SuspendLayout();
			this->RecordsGB->SuspendLayout();
			this->SuspendLayout();
			// 
			// ToolsTS
			// 
			this->ToolsTS->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->MenuTCDDB, this->StartTSB,
					this->TSTBMinesCounter, this->TSLInfo, this->TimerTSL, this->TSLTime
			});
			this->ToolsTS->Location = System::Drawing::Point(0, 0);
			this->ToolsTS->Name = L"ToolsTS";
			this->ToolsTS->Size = System::Drawing::Size(784, 25);
			this->ToolsTS->TabIndex = 1;
			this->ToolsTS->Text = L"toolStrip1";
			// 
			// MenuTCDDB
			// 
			this->MenuTCDDB->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->MenuTCDDB->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->MenuTCDDB->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->OptionsTSMI,
					this->RecordsTSMI
			});
			this->MenuTCDDB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"MenuTCDDB.Image")));
			this->MenuTCDDB->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->MenuTCDDB->Name = L"MenuTCDDB";
			this->MenuTCDDB->Size = System::Drawing::Size(51, 22);
			this->MenuTCDDB->Text = L"Menu";
			// 
			// OptionsTSMI
			// 
			this->OptionsTSMI->Name = L"OptionsTSMI";
			this->OptionsTSMI->Size = System::Drawing::Size(116, 22);
			this->OptionsTSMI->Text = L"Options";
			this->OptionsTSMI->Click += gcnew System::EventHandler(this, &GameForm::optionsToolStripMenuItem_Click);
			// 
			// RecordsTSMI
			// 
			this->RecordsTSMI->Name = L"RecordsTSMI";
			this->RecordsTSMI->Size = System::Drawing::Size(116, 22);
			this->RecordsTSMI->Text = L"Records";
			this->RecordsTSMI->Click += gcnew System::EventHandler(this, &GameForm::recordsToolStripMenuItem_Click);
			// 
			// StartTSB
			// 
			this->StartTSB->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->StartTSB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StartTSB.Image")));
			this->StartTSB->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->StartTSB->Name = L"StartTSB";
			this->StartTSB->Size = System::Drawing::Size(35, 22);
			this->StartTSB->Text = L"Start";
			this->StartTSB->Click += gcnew System::EventHandler(this, &GameForm::StartTSB_Click);
			// 
			// TSTBMinesCounter
			// 
			this->TSTBMinesCounter->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->TSTBMinesCounter->Name = L"TSTBMinesCounter";
			this->TSTBMinesCounter->Size = System::Drawing::Size(70, 25);
			// 
			// TSLInfo
			// 
			this->TSLInfo->Name = L"TSLInfo";
			this->TSLInfo->Size = System::Drawing::Size(0, 22);
			// 
			// TimerTSL
			// 
			this->TimerTSL->Name = L"TimerTSL";
			this->TimerTSL->Size = System::Drawing::Size(0, 22);
			// 
			// TSLTime
			// 
			this->TSLTime->Name = L"TSLTime";
			this->TSLTime->Size = System::Drawing::Size(0, 22);
			// 
			// OptionsMenuFLP
			// 
			this->OptionsMenuFLP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->OptionsMenuFLP->Controls->Add(this->PresetsB);
			this->OptionsMenuFLP->Controls->Add(this->ControlB);
			this->OptionsMenuFLP->Controls->Add(this->CloseOptionsB);
			this->OptionsMenuFLP->Location = System::Drawing::Point(6, 19);
			this->OptionsMenuFLP->Name = L"OptionsMenuFLP";
			this->OptionsMenuFLP->Size = System::Drawing::Size(227, 510);
			this->OptionsMenuFLP->TabIndex = 1;
			// 
			// PresetsB
			// 
			this->PresetsB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PresetsB->Location = System::Drawing::Point(3, 3);
			this->PresetsB->Name = L"PresetsB";
			this->PresetsB->Size = System::Drawing::Size(218, 23);
			this->PresetsB->TabIndex = 0;
			this->PresetsB->Text = L"Field preset";
			this->PresetsB->UseVisualStyleBackColor = true;
			this->PresetsB->Click += gcnew System::EventHandler(this, &GameForm::PresetsB_Click);
			// 
			// ControlB
			// 
			this->ControlB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ControlB->Location = System::Drawing::Point(3, 32);
			this->ControlB->Name = L"ControlB";
			this->ControlB->Size = System::Drawing::Size(218, 23);
			this->ControlB->TabIndex = 1;
			this->ControlB->Text = L"Control";
			this->ControlB->UseVisualStyleBackColor = true;
			this->ControlB->Click += gcnew System::EventHandler(this, &GameForm::ControlB_Click);
			// 
			// CloseOptionsB
			// 
			this->CloseOptionsB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CloseOptionsB->Location = System::Drawing::Point(3, 61);
			this->CloseOptionsB->Name = L"CloseOptionsB";
			this->CloseOptionsB->Size = System::Drawing::Size(218, 23);
			this->CloseOptionsB->TabIndex = 2;
			this->CloseOptionsB->Text = L"Close options";
			this->CloseOptionsB->UseVisualStyleBackColor = true;
			this->CloseOptionsB->Click += gcnew System::EventHandler(this, &GameForm::CloseOptionsB_Click);
			// 
			// PresetsP
			// 
			this->PresetsP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PresetsP->Controls->Add(this->panel1);
			this->PresetsP->Controls->Add(this->DefaultPresetsFLP);
			this->PresetsP->Location = System::Drawing::Point(243, 19);
			this->PresetsP->Name = L"PresetsP";
			this->PresetsP->Size = System::Drawing::Size(529, 510);
			this->PresetsP->TabIndex = 2;
			this->PresetsP->Visible = false;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->GWrongCB);
			this->panel1->Controls->Add(this->GUnknownCB);
			this->panel1->Controls->Add(this->GLifesTB);
			this->panel1->Location = System::Drawing::Point(35, 267);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(290, 140);
			this->panel1->TabIndex = 1;
			// 
			// GWrongCB
			// 
			this->GWrongCB->AutoSize = true;
			this->GWrongCB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GWrongCB->Location = System::Drawing::Point(3, 56);
			this->GWrongCB->Name = L"GWrongCB";
			this->GWrongCB->Size = System::Drawing::Size(177, 28);
			this->GWrongCB->TabIndex = 30;
			this->GWrongCB->Text = L"Right to be wrong";
			this->GWrongCB->UseVisualStyleBackColor = true;
			this->GWrongCB->CheckedChanged += gcnew System::EventHandler(this, &GameForm::GWrongCB_CheckedChanged_1);
			// 
			// GUnknownCB
			// 
			this->GUnknownCB->AutoSize = true;
			this->GUnknownCB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GUnknownCB->Location = System::Drawing::Point(3, 18);
			this->GUnknownCB->Name = L"GUnknownCB";
			this->GUnknownCB->Size = System::Drawing::Size(254, 28);
			this->GUnknownCB->TabIndex = 29;
			this->GUnknownCB->Text = L"Unknown quantity of mines";
			this->GUnknownCB->UseVisualStyleBackColor = true;
			// 
			// GLifesTB
			// 
			this->GLifesTB->Enabled = false;
			this->GLifesTB->Location = System::Drawing::Point(208, 62);
			this->GLifesTB->Name = L"GLifesTB";
			this->GLifesTB->Size = System::Drawing::Size(41, 20);
			this->GLifesTB->TabIndex = 28;
			// 
			// DefaultPresetsFLP
			// 
			this->DefaultPresetsFLP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DefaultPresetsFLP->Controls->Add(this->GPreset1RB);
			this->DefaultPresetsFLP->Controls->Add(this->GPreset2RB);
			this->DefaultPresetsFLP->Controls->Add(this->GPreset3RB);
			this->DefaultPresetsFLP->Controls->Add(this->GWidthInfo);
			this->DefaultPresetsFLP->Controls->Add(this->GWidthTB);
			this->DefaultPresetsFLP->Controls->Add(this->GHeightInfo);
			this->DefaultPresetsFLP->Controls->Add(this->GHeightTB);
			this->DefaultPresetsFLP->Controls->Add(this->GameMinesInfo);
			this->DefaultPresetsFLP->Controls->Add(this->GMinesTB);
			this->DefaultPresetsFLP->Controls->Add(this->GRandomRB);
			this->DefaultPresetsFLP->Location = System::Drawing::Point(35, 3);
			this->DefaultPresetsFLP->Name = L"DefaultPresetsFLP";
			this->DefaultPresetsFLP->Size = System::Drawing::Size(290, 243);
			this->DefaultPresetsFLP->TabIndex = 0;
			// 
			// GPreset1RB
			// 
			this->GPreset1RB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GPreset1RB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GPreset1RB->Location = System::Drawing::Point(3, 3);
			this->GPreset1RB->Name = L"GPreset1RB";
			this->GPreset1RB->Size = System::Drawing::Size(216, 34);
			this->GPreset1RB->TabIndex = 0;
			this->GPreset1RB->TabStop = true;
			this->GPreset1RB->Text = L"Cells - 81, mines - 10";
			this->GPreset1RB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->GPreset1RB->UseVisualStyleBackColor = true;
			this->GPreset1RB->CheckedChanged += gcnew System::EventHandler(this, &GameForm::GPreset1RB_CheckedChanged);
			// 
			// GPreset2RB
			// 
			this->GPreset2RB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GPreset2RB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GPreset2RB->Location = System::Drawing::Point(3, 43);
			this->GPreset2RB->Name = L"GPreset2RB";
			this->GPreset2RB->Size = System::Drawing::Size(216, 34);
			this->GPreset2RB->TabIndex = 1;
			this->GPreset2RB->TabStop = true;
			this->GPreset2RB->Text = L"Cells - 256, mines - 40";
			this->GPreset2RB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->GPreset2RB->UseVisualStyleBackColor = true;
			this->GPreset2RB->CheckedChanged += gcnew System::EventHandler(this, &GameForm::GPreset2RB_CheckedChanged);
			// 
			// GPreset3RB
			// 
			this->GPreset3RB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GPreset3RB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GPreset3RB->Location = System::Drawing::Point(3, 83);
			this->GPreset3RB->Name = L"GPreset3RB";
			this->GPreset3RB->Size = System::Drawing::Size(216, 34);
			this->GPreset3RB->TabIndex = 2;
			this->GPreset3RB->TabStop = true;
			this->GPreset3RB->Text = L"Cells - 480, mines - 99";
			this->GPreset3RB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->GPreset3RB->UseVisualStyleBackColor = true;
			this->GPreset3RB->CheckedChanged += gcnew System::EventHandler(this, &GameForm::GPreset3RB_CheckedChanged);
			// 
			// GWidthInfo
			// 
			this->GWidthInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GWidthInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GWidthInfo->Location = System::Drawing::Point(3, 120);
			this->GWidthInfo->Name = L"GWidthInfo";
			this->GWidthInfo->Size = System::Drawing::Size(199, 23);
			this->GWidthInfo->TabIndex = 24;
			this->GWidthInfo->Text = L"Width....................:";
			// 
			// GWidthTB
			// 
			this->GWidthTB->Location = System::Drawing::Point(208, 123);
			this->GWidthTB->Name = L"GWidthTB";
			this->GWidthTB->Size = System::Drawing::Size(41, 20);
			this->GWidthTB->TabIndex = 31;
			this->GWidthTB->TextChanged += gcnew System::EventHandler(this, &GameForm::GWidthTB_TextChanged);
			// 
			// GHeightInfo
			// 
			this->GHeightInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GHeightInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GHeightInfo->Location = System::Drawing::Point(3, 146);
			this->GHeightInfo->Name = L"GHeightInfo";
			this->GHeightInfo->Size = System::Drawing::Size(199, 31);
			this->GHeightInfo->TabIndex = 36;
			this->GHeightInfo->Text = L"Height...................:";
			// 
			// GHeightTB
			// 
			this->GHeightTB->Location = System::Drawing::Point(208, 149);
			this->GHeightTB->Name = L"GHeightTB";
			this->GHeightTB->Size = System::Drawing::Size(41, 20);
			this->GHeightTB->TabIndex = 38;
			this->GHeightTB->TextChanged += gcnew System::EventHandler(this, &GameForm::GHeightTB_TextChanged);
			// 
			// GameMinesInfo
			// 
			this->GameMinesInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GameMinesInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GameMinesInfo->Location = System::Drawing::Point(3, 177);
			this->GameMinesInfo->Name = L"GameMinesInfo";
			this->GameMinesInfo->Size = System::Drawing::Size(199, 31);
			this->GameMinesInfo->TabIndex = 41;
			this->GameMinesInfo->Text = L"Mines....................:";
			// 
			// GMinesTB
			// 
			this->GMinesTB->Location = System::Drawing::Point(208, 180);
			this->GMinesTB->Name = L"GMinesTB";
			this->GMinesTB->Size = System::Drawing::Size(41, 20);
			this->GMinesTB->TabIndex = 42;
			this->GMinesTB->TextChanged += gcnew System::EventHandler(this, &GameForm::GMinesTB_TextChanged);
			// 
			// GRandomRB
			// 
			this->GRandomRB->AutoSize = true;
			this->GRandomRB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GRandomRB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GRandomRB->Location = System::Drawing::Point(3, 211);
			this->GRandomRB->Name = L"GRandomRB";
			this->GRandomRB->Size = System::Drawing::Size(138, 28);
			this->GRandomRB->TabIndex = 43;
			this->GRandomRB->Text = L"Random field";
			this->GRandomRB->UseVisualStyleBackColor = true;
			// 
			// ControlP
			// 
			this->ControlP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ControlP->Controls->Add(this->flowLayoutPanel1);
			this->ControlP->Location = System::Drawing::Point(243, 19);
			this->ControlP->Name = L"ControlP";
			this->ControlP->Size = System::Drawing::Size(529, 510);
			this->ControlP->TabIndex = 6;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->GCSetOpenInfo);
			this->flowLayoutPanel1->Controls->Add(this->GCOpenCellB);
			this->flowLayoutPanel1->Controls->Add(this->GCSetFlagInfo);
			this->flowLayoutPanel1->Controls->Add(this->GCSetFlagB);
			this->flowLayoutPanel1->Controls->Add(this->GCSetUndefined);
			this->flowLayoutPanel1->Controls->Add(this->GCSetUndef);
			this->flowLayoutPanel1->Location = System::Drawing::Point(39, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(270, 188);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// GCSetOpenInfo
			// 
			this->GCSetOpenInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GCSetOpenInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GCSetOpenInfo->Location = System::Drawing::Point(3, 0);
			this->GCSetOpenInfo->Name = L"GCSetOpenInfo";
			this->GCSetOpenInfo->Size = System::Drawing::Size(103, 53);
			this->GCSetOpenInfo->TabIndex = 0;
			this->GCSetOpenInfo->Text = L"Open cell";
			this->GCSetOpenInfo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GCOpenCellB
			// 
			this->GCOpenCellB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GCOpenCellB->Location = System::Drawing::Point(112, 3);
			this->GCOpenCellB->Name = L"GCOpenCellB";
			this->GCOpenCellB->Size = System::Drawing::Size(147, 50);
			this->GCOpenCellB->TabIndex = 3;
			this->GCOpenCellB->UseVisualStyleBackColor = true;
			// 
			// GCSetFlagInfo
			// 
			this->GCSetFlagInfo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GCSetFlagInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GCSetFlagInfo->Location = System::Drawing::Point(3, 56);
			this->GCSetFlagInfo->Name = L"GCSetFlagInfo";
			this->GCSetFlagInfo->Size = System::Drawing::Size(103, 53);
			this->GCSetFlagInfo->TabIndex = 1;
			this->GCSetFlagInfo->Text = L"Set flag";
			this->GCSetFlagInfo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GCSetFlagB
			// 
			this->GCSetFlagB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GCSetFlagB->Location = System::Drawing::Point(112, 59);
			this->GCSetFlagB->Name = L"GCSetFlagB";
			this->GCSetFlagB->Size = System::Drawing::Size(147, 50);
			this->GCSetFlagB->TabIndex = 4;
			this->GCSetFlagB->UseVisualStyleBackColor = true;
			this->GCSetFlagB->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::GCSetFlagB_MouseDown);
			// 
			// GCSetUndefined
			// 
			this->GCSetUndefined->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GCSetUndefined->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GCSetUndefined->Location = System::Drawing::Point(3, 112);
			this->GCSetUndefined->Name = L"GCSetUndefined";
			this->GCSetUndefined->Size = System::Drawing::Size(103, 53);
			this->GCSetUndefined->TabIndex = 2;
			this->GCSetUndefined->Text = L"Set undefenite";
			this->GCSetUndefined->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GCSetUndef
			// 
			this->GCSetUndef->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GCSetUndef->Location = System::Drawing::Point(112, 115);
			this->GCSetUndef->Name = L"GCSetUndef";
			this->GCSetUndef->Size = System::Drawing::Size(147, 50);
			this->GCSetUndef->TabIndex = 5;
			this->GCSetUndef->UseVisualStyleBackColor = true;
			this->GCSetUndef->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::GCSetUndef_MouseDown);
			// 
			// OptionsGB
			// 
			this->OptionsGB->Controls->Add(this->OptionsMenuFLP);
			this->OptionsGB->Controls->Add(this->PresetsP);
			this->OptionsGB->Controls->Add(this->ControlP);
			this->OptionsGB->Location = System::Drawing::Point(0, 28);
			this->OptionsGB->Name = L"OptionsGB";
			this->OptionsGB->Size = System::Drawing::Size(784, 535);
			this->OptionsGB->TabIndex = 0;
			this->OptionsGB->TabStop = false;
			this->OptionsGB->Text = L"Options";
			this->OptionsGB->Visible = false;
			// 
			// RecordsGB
			// 
			this->RecordsGB->Controls->Add(this->richTextBox1);
			this->RecordsGB->Controls->Add(this->textBox3);
			this->RecordsGB->Controls->Add(this->textBox2);
			this->RecordsGB->Controls->Add(this->textBox1);
			this->RecordsGB->Controls->Add(this->CloseRecordsB);
			this->RecordsGB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->RecordsGB->Location = System::Drawing::Point(1, 26);
			this->RecordsGB->Name = L"RecordsGB";
			this->RecordsGB->Size = System::Drawing::Size(783, 531);
			this->RecordsGB->TabIndex = 6;
			this->RecordsGB->TabStop = false;
			this->RecordsGB->Text = L"Records";
			this->RecordsGB->Visible = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(145, 94);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(317, 254);
			this->richTextBox1->TabIndex = 7;
			this->richTextBox1->Text = L"";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(484, 58);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(362, 58);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(145, 58);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(194, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// CloseRecordsB
			// 
			this->CloseRecordsB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CloseRecordsB->Location = System::Drawing::Point(346, 502);
			this->CloseRecordsB->Name = L"CloseRecordsB";
			this->CloseRecordsB->Size = System::Drawing::Size(135, 23);
			this->CloseRecordsB->TabIndex = 3;
			this->CloseRecordsB->Text = L"Close records";
			this->CloseRecordsB->UseVisualStyleBackColor = true;
			// 
			// Timer
			// 
			this->Timer->Interval = 1000;
			this->Timer->Tick += gcnew System::EventHandler(this, &GameForm::Timer_Tick);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->ToolsTS);
			this->Controls->Add(this->RecordsGB);
			this->Controls->Add(this->OptionsGB);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GameForm::GameForm_FormClosed);
			this->Shown += gcnew System::EventHandler(this, &GameForm::GameForm_Shown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::GameForm_MouseClick);
			this->ToolsTS->ResumeLayout(false);
			this->ToolsTS->PerformLayout();
			this->OptionsMenuFLP->ResumeLayout(false);
			this->PresetsP->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->DefaultPresetsFLP->ResumeLayout(false);
			this->DefaultPresetsFLP->PerformLayout();
			this->ControlP->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->OptionsGB->ResumeLayout(false);
			this->RecordsGB->ResumeLayout(false);
			this->RecordsGB->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void GameForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		std::fstream load;
		started = false;

		if (mb_open == 1) {
			GCOpenCellB->Text = "Left mouse button";
		}
		else {
			if (mb_open == 2) {
				GCOpenCellB->Text = "Right mouse button";
			}
			else {
				if (mb_open == 3) {
					GCOpenCellB->Text = "Middle mouse button";
				}
			}
		}

		if (mb_flag == 1) {
			GCSetFlagB->Text = "Left mouse button";
		}
		else {
			if (mb_flag == 2) {
				GCSetFlagB->Text = "Right mouse button";
			}
			else {
				if (mb_flag == 3) {
					GCSetFlagB->Text = "Middle mouse button";
				}
			}
		}

		if (mb_undefined == 1) {
			GCSetUndef->Text = "Left mouse button";
		}
		else {
			if (mb_undefined == 2) {
				GCSetUndef->Text = "Right mouse button";
			}
			else {
				if (mb_undefined == 3) {
					GCSetUndef->Text = "Middle mouse button";
				}
			}
		}

		std::fstream file;
		time = 0;
		file.open("Save.sav", std::ios::in);
		if (file.is_open()) {
			file.seekg(std::ios::end);
			if (file.tellg()>0) {
				file.close();
				field = loadGame(width, height, mines, lifes, time, flags, this, started,wasFirstClick, closedCells);
				if (started == false) {
					TSLInfo->Text = "looser";
					showMines(field, width, height, this);
				}
			}
		}
		TSLTime->Text = time.ToString();
	}

	private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OptionsGB->Visible = true;
		ControlP->Visible = false;
		PresetsP->Visible = true;
		RecordsGB->Visible = false;
	}
	private: System::Void CloseOptionsB_Click(System::Object^  sender, System::EventArgs^  e) {
		OptionsGB->Visible = false;
		if (GWidthTB->Text == "" || GHeightTB->Text == "" || GMinesTB->Text == "" && GPreset1RB->Checked == false && GPreset2RB->Checked == false && GPreset3RB->Checked == false && GRandomRB->Checked == false) {
			MessageBox::Show("All fields must be filled!!! Preset 1 is chosen.");
		}
	}
	private: System::Void ControlB_Click(System::Object^  sender, System::EventArgs^  e) {
		ControlP->Visible = true;
		PresetsP->Visible = false;
	}
	private: System::Void PresetsB_Click(System::Object^  sender, System::EventArgs^  e) {
		PresetsP->Visible = true;
		ControlP->Visible = false;
	}
	private: System::Void recordsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		RecordsGB->Visible = true;
		OptionsGB->Visible = false;
	}
	private: System::Void CloseRecordsB_Click_1(System::Object^  sender, System::EventArgs^  e) {
		RecordsGB->Visible = false;

	}

	private: System::Void StartTSB_Click(System::Object^  sender, System::EventArgs^  e) {
		if (width != 0 && height != 0) {
			clearField(field, width, height);
		}

		if (quantity_of_cells_width == 0 && quantity_of_cells_height == 0 && quantity_of_mines == 0) {
			width = 9;
			height = 9;
			mines = 10;
		}
		else {
			width = quantity_of_cells_width;
			height = quantity_of_cells_height;
			mines = quantity_of_mines;
		}

		field = new Cell*[width];

		for (int i = 0; i < width; i++) {
			field[i] = new Cell[height];
		}

		closedCells = width*height;
		createField(field, width, height, mines, this, started);
		TSTBMinesCounter->Text = "Mines: " + mines.ToString();
		time = 0;
		wasFirstClick = false;
		showMines(field, width, height, this);
	}


	private: System::Void GPreset1RB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		quantity_of_cells_width = 9;
		quantity_of_cells_height = 9;
		quantity_of_mines = 10;
		GWidthTB->Text = "";
		GHeightTB->Text = "";
	}
	private: System::Void GPreset2RB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		quantity_of_cells_width = 16;
		quantity_of_cells_height = 16;
		quantity_of_mines = 40;
		GWidthTB->Text = "";
		GHeightTB->Text = "";
	}
	private: System::Void GPreset3RB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		quantity_of_cells_width = 24;
		quantity_of_cells_height = 20;
		quantity_of_mines = 99;
		GWidthTB->Text = "";
		GHeightTB->Text = "";
	}

	private: System::Void GCOpenCellB_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int tmp_mb_open = mb_open;
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			mb_open = 1;
		}
		else {
			if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				mb_open = 2;
			}
			else {
				if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
					mb_open = 3;
				}
			}
		}

		if (mb_open == mb_flag) {
			mb_flag = tmp_mb_open;
		}
		if (mb_open == mb_undefined) {
			mb_undefined = tmp_mb_open;
		}

		if (mb_open == 1) {
			GCOpenCellB->Text = "Left mouse button";
		}
		else {
			if (mb_open == 2) {
				GCOpenCellB->Text = "Right mouse button";
			}
			else {
				if (mb_open == 3) {
					GCOpenCellB->Text = "Middle mouse button";
				}
			}
		}

		if (mb_flag == 1) {
			GCSetFlagB->Text = "Left mouse button";
		}
		else {
			if (mb_flag == 2) {
				GCSetFlagB->Text = "Right mouse button";
			}
			else {
				if (mb_flag == 3) {
					GCSetFlagB->Text = "Middle mouse button";
				}
			}
		}

		if (mb_undefined == 1) {
			GCSetUndef->Text = "Left mouse button";
		}
		else {
			if (mb_undefined == 2) {
				GCSetUndef->Text = "Right mouse button";
			}
			else {
				if (mb_undefined == 3) {
					GCSetUndef->Text = "Middle mouse button";
				}
			}
		}
	}
	private: System::Void GCSetFlagB_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int tmp_mb_flag = mb_flag;
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			mb_flag = 1;
		}
		else {
			if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				mb_flag = 2;
			}
			else {
				if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
					mb_flag = 3;
				}
			}
		}

		if (mb_open == mb_flag) {
			mb_open = tmp_mb_flag;
		}
		if (mb_flag == mb_undefined) {
			mb_undefined = tmp_mb_flag;
		}

		if (mb_open == 1) {
			GCOpenCellB->Text = "Left mouse button";
		}
		else {
			if (mb_open == 2) {
				GCOpenCellB->Text = "Right mouse button";
			}
			else {
				if (mb_open == 3) {
					GCOpenCellB->Text = "Middle mouse button";
				}
			}
		}

		if (mb_flag == 1) {
			GCSetFlagB->Text = "Left mouse button";
		}
		else {
			if (mb_flag == 2) {
				GCSetFlagB->Text = "Right mouse button";
			}
			else {
				if (mb_flag == 3) {
					GCSetFlagB->Text = "Middle mouse button";
				}
			}
		}

		if (mb_undefined == 1) {
			GCSetUndef->Text = "Left mouse button";
		}
		else {
			if (mb_undefined == 2) {
				GCSetUndef->Text = "Right mouse button";
			}
			else {
				if (mb_undefined == 3) {
					GCSetUndef->Text = "Middle mouse button";
				}
			}
		}
	}
	private: System::Void GCSetUndef_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int tmp_mb_undefined = mb_undefined;
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			mb_undefined = 1;
		}
		else {
			if (e->Button == System::Windows::Forms::MouseButtons::Right) {
				mb_undefined = 2;
			}
			else {
				if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
					mb_undefined = 3;
				}
			}
		}

		if (mb_open == mb_undefined) {
			mb_open = tmp_mb_undefined;
		}
		if (mb_flag == mb_undefined) {
			mb_flag = tmp_mb_undefined;
		}

		if (mb_open == 1) {
			GCOpenCellB->Text = "Left mouse button";
		}
		else {
			if (mb_open == 2) {
				GCOpenCellB->Text = "Right mouse button";
			}
			else {
				if (mb_open == 3) {
					GCOpenCellB->Text = "Middle mouse button";
				}
			}
		}

		if (mb_flag == 1) {
			GCSetFlagB->Text = "Left mouse button";
		}
		else {
			if (mb_flag == 2) {
				GCSetFlagB->Text = "Right mouse button";
			}
			else {
				if (mb_flag == 3) {
					GCSetFlagB->Text = "Middle mouse button";
				}
			}
		}

		if (mb_undefined == 1) {
			GCSetUndef->Text = "Left mouse button";
		}
		else {
			if (mb_undefined == 2) {
				GCSetUndef->Text = "Right mouse button";
			}
			else {
				if (mb_undefined == 3) {
					GCSetUndef->Text = "Middle mouse button";
				}
			}
		}
	}

	private: System::Void GameForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int mb;

		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			mb = 1;
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			mb = 2;
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
			mb = 3;
		}
		if (started == true) {
			if (timerEnabled == false) {
			}
			timerEnabled = true;
			Timer->Enabled = true;
			openCell(field, e->X, e->Y, width, height, mines, this, started, mb, lifes, closedCells, wasFirstClick);
			TSTBMinesCounter->Text = "Flags: " + flags.ToString();
			if (started == false) {
				showMines(field, width, height, this);
				TSLInfo->Text = "You are looser!!! LOL";
				timerEnabled = false;
				Timer->Enabled = false;
			}
			if (mines == 0 || closedCells == mines) {
				started = false;
				TSLInfo->Text = "Win!!!!";
				timerEnabled = false;
				Timer->Enabled = false;
			}
		}
	}

	private: System::Void GWrongCB_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {
		if (GWrongCB->Checked == true) {
			GLifesTB->Enabled = true;
		}
		else {
			GLifesTB->Enabled = 0;
			GLifesTB->Text = "";
		}
	}
	private: System::Void GWidthTB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		GPreset1RB->Checked = false;
		GPreset2RB->Checked = false;
		GPreset3RB->Checked = false;
		GRandomRB->Checked = false;
	}
	private: System::Void GHeightTB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		GPreset1RB->Checked = false;
		GPreset2RB->Checked = false;
		GPreset3RB->Checked = false;
		GRandomRB->Checked = false;
	}
	private: System::Void GMinesTB_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		GPreset1RB->Checked = false;
		GPreset2RB->Checked = false;
		GPreset3RB->Checked = false;
		GRandomRB->Checked = false;
		if (GMinesTB->Text != "") {
			GUnknownCB->Checked = false;
		}
		else {
			GUnknownCB->Checked = true;
		}
	}

private: System::Void GameForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	saveGame(field, width, height, mines, lifes, flags, time, started, wasFirstClick);
}


private: System::Void Timer_Tick(System::Object^  sender, System::EventArgs^  e) {
	TSLTime->Text = time.ToString();
	time++;
}
};


}
