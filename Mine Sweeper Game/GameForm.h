#pragma once
#include "Cell.h"


extern Cell **field;
static bool started;

//bool started;

void createField(Cell **field, int &width, int &height, System::Windows::Forms::Form ^f, bool &started);
void openCell(Cell **field, int x, int y, int &width, int &height, System::Windows::Forms::Form ^f, bool &started, int &mb, int &lifes);
extern int	width,
	        height,
            mines,
		    quantity_of_mines,
			quantity_of_cells_width,
			quantity_of_cells_height,
		    mb_open,
			mb_flag,
			mb_undefined,
			lifes;


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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  GCOpenCellB;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  GCSetFlagB;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  GCSetUndef;
	private: System::Windows::Forms::GroupBox^  OptionsGB;

	private: System::Windows::Forms::ToolStripButton^  StartTSB;
	private: System::Windows::Forms::GroupBox^  RecordsGB;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  RPreset1TP;
	private: System::Windows::Forms::TabPage^  RPreset2TP;
	private: System::Windows::Forms::TabPage^  RPreset3TP;
	private: System::Windows::Forms::Button^  CloseRecordsB;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  Preset3L;
	private: System::Windows::Forms::Label^  Preset2L;
	private: System::Windows::Forms::Label^  Preset1L;
	private: System::Windows::Forms::MaskedTextBox^  GMinesMTB;
	private: System::Windows::Forms::MaskedTextBox^  GHeightMTB;
	private: System::Windows::Forms::MaskedTextBox^  GWidthMTB;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->ToolsTS = (gcnew System::Windows::Forms::ToolStrip());
			this->MenuTCDDB = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->OptionsTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->RecordsTSMI = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StartTSB = (gcnew System::Windows::Forms::ToolStripButton());
			this->OptionsMenuFLP = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->PresetsB = (gcnew System::Windows::Forms::Button());
			this->ControlB = (gcnew System::Windows::Forms::Button());
			this->CloseOptionsB = (gcnew System::Windows::Forms::Button());
			this->PresetsP = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Preset3L = (gcnew System::Windows::Forms::Label());
			this->Preset2L = (gcnew System::Windows::Forms::Label());
			this->Preset1L = (gcnew System::Windows::Forms::Label());
			this->GMinesMTB = (gcnew System::Windows::Forms::MaskedTextBox());
			this->GHeightMTB = (gcnew System::Windows::Forms::MaskedTextBox());
			this->GWidthMTB = (gcnew System::Windows::Forms::MaskedTextBox());
			this->DefaultPresetsFLP = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->GPreset1RB = (gcnew System::Windows::Forms::RadioButton());
			this->GPreset2RB = (gcnew System::Windows::Forms::RadioButton());
			this->GPreset3RB = (gcnew System::Windows::Forms::RadioButton());
			this->ControlP = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GCOpenCellB = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->GCSetFlagB = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->GCSetUndef = (gcnew System::Windows::Forms::Button());
			this->OptionsGB = (gcnew System::Windows::Forms::GroupBox());
			this->RecordsGB = (gcnew System::Windows::Forms::GroupBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->RPreset1TP = (gcnew System::Windows::Forms::TabPage());
			this->RPreset2TP = (gcnew System::Windows::Forms::TabPage());
			this->RPreset3TP = (gcnew System::Windows::Forms::TabPage());
			this->CloseRecordsB = (gcnew System::Windows::Forms::Button());
			this->ToolsTS->SuspendLayout();
			this->OptionsMenuFLP->SuspendLayout();
			this->PresetsP->SuspendLayout();
			this->panel1->SuspendLayout();
			this->DefaultPresetsFLP->SuspendLayout();
			this->ControlP->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->OptionsGB->SuspendLayout();
			this->RecordsGB->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ToolsTS
			// 
			this->ToolsTS->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->MenuTCDDB, this->StartTSB });
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
			this->panel1->Controls->Add(this->Preset3L);
			this->panel1->Controls->Add(this->Preset2L);
			this->panel1->Controls->Add(this->Preset1L);
			this->panel1->Controls->Add(this->GMinesMTB);
			this->panel1->Controls->Add(this->GHeightMTB);
			this->panel1->Controls->Add(this->GWidthMTB);
			this->panel1->Location = System::Drawing::Point(35, 188);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(290, 181);
			this->panel1->TabIndex = 1;
			// 
			// Preset3L
			// 
			this->Preset3L->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Preset3L->Location = System::Drawing::Point(27, 100);
			this->Preset3L->Name = L"Preset3L";
			this->Preset3L->Size = System::Drawing::Size(86, 31);
			this->Preset3L->TabIndex = 8;
			this->Preset3L->Text = L"Mines:";
			// 
			// Preset2L
			// 
			this->Preset2L->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Preset2L->Location = System::Drawing::Point(27, 66);
			this->Preset2L->Name = L"Preset2L";
			this->Preset2L->Size = System::Drawing::Size(86, 31);
			this->Preset2L->TabIndex = 7;
			this->Preset2L->Text = L"Height:";
			// 
			// Preset1L
			// 
			this->Preset1L->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Preset1L->Location = System::Drawing::Point(27, 29);
			this->Preset1L->Name = L"Preset1L";
			this->Preset1L->Size = System::Drawing::Size(86, 31);
			this->Preset1L->TabIndex = 6;
			this->Preset1L->Text = L"Width:";
			// 
			// GMinesMTB
			// 
			this->GMinesMTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GMinesMTB->Location = System::Drawing::Point(119, 100);
			this->GMinesMTB->Mask = L"00";
			this->GMinesMTB->Name = L"GMinesMTB";
			this->GMinesMTB->Size = System::Drawing::Size(100, 31);
			this->GMinesMTB->TabIndex = 5;
			// 
			// GHeightMTB
			// 
			this->GHeightMTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GHeightMTB->Location = System::Drawing::Point(119, 66);
			this->GHeightMTB->Mask = L"00";
			this->GHeightMTB->Name = L"GHeightMTB";
			this->GHeightMTB->Size = System::Drawing::Size(100, 31);
			this->GHeightMTB->TabIndex = 4;
			// 
			// GWidthMTB
			// 
			this->GWidthMTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->GWidthMTB->Location = System::Drawing::Point(119, 29);
			this->GWidthMTB->Mask = L"00";
			this->GWidthMTB->Name = L"GWidthMTB";
			this->GWidthMTB->Size = System::Drawing::Size(100, 31);
			this->GWidthMTB->TabIndex = 3;
			// 
			// DefaultPresetsFLP
			// 
			this->DefaultPresetsFLP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DefaultPresetsFLP->Controls->Add(this->GPreset1RB);
			this->DefaultPresetsFLP->Controls->Add(this->GPreset2RB);
			this->DefaultPresetsFLP->Controls->Add(this->GPreset3RB);
			this->DefaultPresetsFLP->Location = System::Drawing::Point(35, 3);
			this->DefaultPresetsFLP->Name = L"DefaultPresetsFLP";
			this->DefaultPresetsFLP->Size = System::Drawing::Size(290, 179);
			this->DefaultPresetsFLP->TabIndex = 0;
			// 
			// GPreset1RB
			// 
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
			this->flowLayoutPanel1->Controls->Add(this->label1);
			this->flowLayoutPanel1->Controls->Add(this->GCOpenCellB);
			this->flowLayoutPanel1->Controls->Add(this->label2);
			this->flowLayoutPanel1->Controls->Add(this->GCSetFlagB);
			this->flowLayoutPanel1->Controls->Add(this->label3);
			this->flowLayoutPanel1->Controls->Add(this->GCSetUndef);
			this->flowLayoutPanel1->Location = System::Drawing::Point(39, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(270, 188);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 53);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Open cell";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// GCOpenCellB
			// 
			this->GCOpenCellB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GCOpenCellB->Location = System::Drawing::Point(112, 3);
			this->GCOpenCellB->Name = L"GCOpenCellB";
			this->GCOpenCellB->Size = System::Drawing::Size(147, 50);
			this->GCOpenCellB->TabIndex = 3;
			this->GCOpenCellB->UseVisualStyleBackColor = true;
			this->GCOpenCellB->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::GCOpenCellB_MouseDown);
			// 
			// label2
			// 
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 53);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Set flag";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// label3
			// 
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(3, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(103, 53);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Set undefenite";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->OptionsGB->Controls->Add(this->ControlP);
			this->OptionsGB->Controls->Add(this->PresetsP);
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
			this->RecordsGB->Controls->Add(this->tabControl1);
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
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->RPreset1TP);
			this->tabControl1->Controls->Add(this->RPreset2TP);
			this->tabControl1->Controls->Add(this->RPreset3TP);
			this->tabControl1->Location = System::Drawing::Point(3, 16);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(774, 467);
			this->tabControl1->TabIndex = 4;
			// 
			// RPreset1TP
			// 
			this->RPreset1TP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->RPreset1TP->Location = System::Drawing::Point(4, 22);
			this->RPreset1TP->Name = L"RPreset1TP";
			this->RPreset1TP->Padding = System::Windows::Forms::Padding(3);
			this->RPreset1TP->Size = System::Drawing::Size(766, 441);
			this->RPreset1TP->TabIndex = 0;
			this->RPreset1TP->Text = L"9x9, 10 m";
			this->RPreset1TP->UseVisualStyleBackColor = true;
			// 
			// RPreset2TP
			// 
			this->RPreset2TP->Location = System::Drawing::Point(4, 22);
			this->RPreset2TP->Name = L"RPreset2TP";
			this->RPreset2TP->Padding = System::Windows::Forms::Padding(3);
			this->RPreset2TP->Size = System::Drawing::Size(766, 441);
			this->RPreset2TP->TabIndex = 1;
			this->RPreset2TP->Text = L"16x16, 40 m";
			this->RPreset2TP->UseVisualStyleBackColor = true;
			// 
			// RPreset3TP
			// 
			this->RPreset3TP->Location = System::Drawing::Point(4, 22);
			this->RPreset3TP->Name = L"RPreset3TP";
			this->RPreset3TP->Size = System::Drawing::Size(766, 441);
			this->RPreset3TP->TabIndex = 2;
			this->RPreset3TP->Text = L"20x24, 99 m";
			this->RPreset3TP->UseVisualStyleBackColor = true;
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
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->ToolsTS);
			this->Controls->Add(this->OptionsGB);
			this->Controls->Add(this->RecordsGB);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->Shown += gcnew System::EventHandler(this, &GameForm::GameForm_Shown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GameForm::GameForm_MouseClick);
			this->ToolsTS->ResumeLayout(false);
			this->ToolsTS->PerformLayout();
			this->OptionsMenuFLP->ResumeLayout(false);
			this->PresetsP->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->DefaultPresetsFLP->ResumeLayout(false);
			this->ControlP->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->OptionsGB->ResumeLayout(false);
			this->RecordsGB->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void GameForm_Shown(System::Object^  sender, System::EventArgs^  e) {
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
	}

private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OptionsGB->Visible = true;
	ControlP->Visible = false;
	PresetsP->Visible = true;
	RecordsGB->Visible = false;
}
private: System::Void CloseOptionsB_Click(System::Object^  sender, System::EventArgs^  e) {
	OptionsGB->Visible = false;
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
	 //**field = new Cell*[width];
	
	field = new Cell*[width];
	
	for (int i = 0; i < height; i++) {
		field[i] = new Cell[32];
	}
	
	
	createField(field, width, height, this, started);
	
	//spawnMines(field, width, height, mines);
}

/*private: System::Void GameForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	
	System::Drawing::Graphics ^g = e->Graphics;
}*/

private: System::Void GPreset1RB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	quantity_of_cells_width = 9;
	quantity_of_cells_height = 9;
	quantity_of_mines = 10;
}
private: System::Void GPreset2RB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	quantity_of_cells_width = 16;
	quantity_of_cells_height = 16;
	quantity_of_mines = 40;
}
private: System::Void GPreset3RB_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	quantity_of_cells_width = 24;
	quantity_of_cells_height = 20;
	quantity_of_mines = 99;
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

	openCell(field, e->X, e->Y, width, height, this, started, mb, lifes);
}
};


}
