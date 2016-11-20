#pragma once

namespace MineSweeperGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	protected:
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  recordsToolStripMenuItem;
	private: System::Windows::Forms::FlowLayoutPanel^  OptionsMenuFLP;
	private: System::Windows::Forms::Button^  PresetsB;
	private: System::Windows::Forms::Button^  ControlB;
	private: System::Windows::Forms::Button^  CloseOptionsB;
	private: System::Windows::Forms::Panel^  PresetsP;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::MaskedTextBox^  GWidthMTB;








	private: System::Windows::Forms::FlowLayoutPanel^  DefaultPresetsFLP;
	private: System::Windows::Forms::RadioButton^  GPreset1RB;
	private: System::Windows::Forms::RadioButton^  GPreset2RB;
	private: System::Windows::Forms::RadioButton^  GPreset3RB;
	private: System::Windows::Forms::GroupBox^  OptionsGB;
	private: System::Windows::Forms::MaskedTextBox^  GMinesMTB;

	private: System::Windows::Forms::MaskedTextBox^  GHeightMTB;
	private: System::Windows::Forms::Label^  Preset3L;
	private: System::Windows::Forms::Label^  Preset2L;
	private: System::Windows::Forms::Label^  Preset1L;
	private: System::Windows::Forms::Panel^  ControlP;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  GCOpenCellB;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  GCSetFlagB;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  GCSetUndef;



















	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->recordsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->OptionsGB = (gcnew System::Windows::Forms::GroupBox());
			this->ControlP = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GCOpenCellB = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->GCSetFlagB = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->GCSetUndef = (gcnew System::Windows::Forms::Button());
			this->toolStrip1->SuspendLayout();
			this->OptionsMenuFLP->SuspendLayout();
			this->PresetsP->SuspendLayout();
			this->panel1->SuspendLayout();
			this->DefaultPresetsFLP->SuspendLayout();
			this->OptionsGB->SuspendLayout();
			this->ControlP->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripDropDownButton1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(475, 25);
			this->toolStrip1->TabIndex = 1;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->optionsToolStripMenuItem,
					this->recordsToolStripMenuItem
			});
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(29, 22);
			this->toolStripDropDownButton1->Text = L"toolStripDropDownButton1";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->optionsToolStripMenuItem->Text = L"Options";
			this->optionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::optionsToolStripMenuItem_Click);
			// 
			// recordsToolStripMenuItem
			// 
			this->recordsToolStripMenuItem->Name = L"recordsToolStripMenuItem";
			this->recordsToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->recordsToolStripMenuItem->Text = L"Records";
			// 
			// OptionsMenuFLP
			// 
			this->OptionsMenuFLP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->OptionsMenuFLP->Controls->Add(this->PresetsB);
			this->OptionsMenuFLP->Controls->Add(this->ControlB);
			this->OptionsMenuFLP->Controls->Add(this->CloseOptionsB);
			this->OptionsMenuFLP->Location = System::Drawing::Point(6, 19);
			this->OptionsMenuFLP->Name = L"OptionsMenuFLP";
			this->OptionsMenuFLP->Size = System::Drawing::Size(144, 329);
			this->OptionsMenuFLP->TabIndex = 1;
			// 
			// PresetsB
			// 
			this->PresetsB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PresetsB->Location = System::Drawing::Point(3, 3);
			this->PresetsB->Name = L"PresetsB";
			this->PresetsB->Size = System::Drawing::Size(135, 23);
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
			this->ControlB->Size = System::Drawing::Size(135, 23);
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
			this->CloseOptionsB->Size = System::Drawing::Size(135, 23);
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
			this->PresetsP->Location = System::Drawing::Point(165, 19);
			this->PresetsP->Name = L"PresetsP";
			this->PresetsP->Size = System::Drawing::Size(298, 329);
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
			this->panel1->Location = System::Drawing::Point(3, 141);
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
			this->DefaultPresetsFLP->Location = System::Drawing::Point(3, 3);
			this->DefaultPresetsFLP->Name = L"DefaultPresetsFLP";
			this->DefaultPresetsFLP->Size = System::Drawing::Size(290, 129);
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
			// 
			// GPreset2RB
			// 
			this->GPreset2RB->Location = System::Drawing::Point(3, 43);
			this->GPreset2RB->Name = L"GPreset2RB";
			this->GPreset2RB->Size = System::Drawing::Size(216, 34);
			this->GPreset2RB->TabIndex = 1;
			this->GPreset2RB->TabStop = true;
			this->GPreset2RB->Text = L"Cells - 81, mines - 10";
			this->GPreset2RB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->GPreset2RB->UseVisualStyleBackColor = true;
			// 
			// GPreset3RB
			// 
			this->GPreset3RB->Location = System::Drawing::Point(3, 83);
			this->GPreset3RB->Name = L"GPreset3RB";
			this->GPreset3RB->Size = System::Drawing::Size(216, 34);
			this->GPreset3RB->TabIndex = 2;
			this->GPreset3RB->TabStop = true;
			this->GPreset3RB->Text = L"Cells - 81, mines - 10";
			this->GPreset3RB->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->GPreset3RB->UseVisualStyleBackColor = true;
			// 
			// OptionsGB
			// 
			this->OptionsGB->Controls->Add(this->ControlP);
			this->OptionsGB->Controls->Add(this->PresetsP);
			this->OptionsGB->Controls->Add(this->OptionsMenuFLP);
			this->OptionsGB->Location = System::Drawing::Point(0, 28);
			this->OptionsGB->Name = L"OptionsGB";
			this->OptionsGB->Size = System::Drawing::Size(475, 366);
			this->OptionsGB->TabIndex = 0;
			this->OptionsGB->TabStop = false;
			this->OptionsGB->Text = L"Options";
			// 
			// ControlP
			// 
			this->ControlP->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ControlP->Controls->Add(this->flowLayoutPanel1);
			this->ControlP->Location = System::Drawing::Point(165, 19);
			this->ControlP->Name = L"ControlP";
			this->ControlP->Size = System::Drawing::Size(298, 329);
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
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 13);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(272, 214);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
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
			this->GCOpenCellB->Location = System::Drawing::Point(112, 3);
			this->GCOpenCellB->Name = L"GCOpenCellB";
			this->GCOpenCellB->Size = System::Drawing::Size(147, 50);
			this->GCOpenCellB->TabIndex = 3;
			this->GCOpenCellB->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
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
			this->GCSetFlagB->Location = System::Drawing::Point(112, 59);
			this->GCSetFlagB->Name = L"GCSetFlagB";
			this->GCSetFlagB->Size = System::Drawing::Size(147, 50);
			this->GCSetFlagB->TabIndex = 4;
			this->GCSetFlagB->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
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
			this->GCSetUndef->Location = System::Drawing::Point(112, 115);
			this->GCSetUndef->Name = L"GCSetUndef";
			this->GCSetUndef->Size = System::Drawing::Size(147, 50);
			this->GCSetUndef->TabIndex = 5;
			this->GCSetUndef->UseVisualStyleBackColor = true;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(475, 394);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->OptionsGB);
			this->Name = L"GameForm";
			this->Text = L"GameForm";
			this->Shown += gcnew System::EventHandler(this, &GameForm::GameForm_Shown);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->OptionsMenuFLP->ResumeLayout(false);
			this->PresetsP->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->DefaultPresetsFLP->ResumeLayout(false);
			this->OptionsGB->ResumeLayout(false);
			this->ControlP->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GameForm_Shown(System::Object^  sender, System::EventArgs^  e) {
		OptionsGB->Visible = false;
	}
private: System::Void optionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OptionsGB->Visible = true;
	ControlP->Visible = false;
	PresetsP->Visible = true;
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
};
}