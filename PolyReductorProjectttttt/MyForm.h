#pragma once

namespace PolyReductorProjectttttt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  load_model;
	protected:
	private: System::Windows::Forms::Button^  save_model;
	private: System::Windows::Forms::Button^  toolbar;
	private: System::Windows::Forms::CheckBox^  automatically;
	private: System::Windows::Forms::Label^  text_num_of_polygon;
	private: System::Windows::Forms::Label^  text_deg_of_deform;
	private: System::Windows::Forms::Button^  reduce;
	private: System::Windows::Forms::TrackBar^  track_polygons;
	private: System::Windows::Forms::TrackBar^  track_deformations;
	private: System::Windows::Forms::Button^  check;
	private: System::Windows::Forms::Label^  text_com_oryg_model;
	private: System::Windows::Forms::TextBox^  textBox_compliance;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->load_model = (gcnew System::Windows::Forms::Button());
			this->save_model = (gcnew System::Windows::Forms::Button());
			this->toolbar = (gcnew System::Windows::Forms::Button());
			this->automatically = (gcnew System::Windows::Forms::CheckBox());
			this->text_num_of_polygon = (gcnew System::Windows::Forms::Label());
			this->text_deg_of_deform = (gcnew System::Windows::Forms::Label());
			this->reduce = (gcnew System::Windows::Forms::Button());
			this->track_polygons = (gcnew System::Windows::Forms::TrackBar());
			this->track_deformations = (gcnew System::Windows::Forms::TrackBar());
			this->check = (gcnew System::Windows::Forms::Button());
			this->text_com_oryg_model = (gcnew System::Windows::Forms::Label());
			this->textBox_compliance = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->track_polygons))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->track_deformations))->BeginInit();
			this->SuspendLayout();
			// 
			// load_model
			// 
			this->load_model->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->load_model->Location = System::Drawing::Point(13, 13);
			this->load_model->Name = L"load_model";
			this->load_model->Size = System::Drawing::Size(186, 46);
			this->load_model->TabIndex = 0;
			this->load_model->Text = L"Load Model";
			this->load_model->UseVisualStyleBackColor = false;
			this->load_model->Click += gcnew System::EventHandler(this, &MyForm::load_model_Click);
			// 
			// save_model
			// 
			this->save_model->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->save_model->Location = System::Drawing::Point(227, 13);
			this->save_model->Name = L"save_model";
			this->save_model->Size = System::Drawing::Size(185, 46);
			this->save_model->TabIndex = 1;
			this->save_model->Text = L"Save Model";
			this->save_model->UseVisualStyleBackColor = false;
			this->save_model->Click += gcnew System::EventHandler(this, &MyForm::save_model_Click);
			// 
			// toolbar
			// 
			this->toolbar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->toolbar->Location = System::Drawing::Point(442, 12);
			this->toolbar->Name = L"toolbar";
			this->toolbar->Size = System::Drawing::Size(167, 47);
			this->toolbar->TabIndex = 2;
			this->toolbar->Text = L"Toolbar";
			this->toolbar->UseVisualStyleBackColor = false;
			this->toolbar->Click += gcnew System::EventHandler(this, &MyForm::toolbar_Click);
			// 
			// automatically
			// 
			this->automatically->AutoSize = true;
			this->automatically->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->automatically->ForeColor = System::Drawing::SystemColors::Control;
			this->automatically->Location = System::Drawing::Point(13, 156);
			this->automatically->Name = L"automatically";
			this->automatically->Size = System::Drawing::Size(113, 21);
			this->automatically->TabIndex = 3;
			this->automatically->Text = L"Automatically";
			this->automatically->UseVisualStyleBackColor = false;
			this->automatically->CheckedChanged += gcnew System::EventHandler(this, &MyForm::automatically_CheckedChanged);
			// 
			// text_num_of_polygon
			// 
			this->text_num_of_polygon->AutoSize = true;
			this->text_num_of_polygon->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->text_num_of_polygon->Location = System::Drawing::Point(13, 203);
			this->text_num_of_polygon->Name = L"text_num_of_polygon";
			this->text_num_of_polygon->Size = System::Drawing::Size(146, 17);
			this->text_num_of_polygon->TabIndex = 4;
			this->text_num_of_polygon->Text = L"Numbers Of Polygons";
			// 
			// text_deg_of_deform
			// 
			this->text_deg_of_deform->AutoSize = true;
			this->text_deg_of_deform->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->text_deg_of_deform->Location = System::Drawing::Point(16, 299);
			this->text_deg_of_deform->Name = L"text_deg_of_deform";
			this->text_deg_of_deform->Size = System::Drawing::Size(162, 17);
			this->text_deg_of_deform->TabIndex = 5;
			this->text_deg_of_deform->Text = L"Degree Of Deformations";
			// 
			// reduce
			// 
			this->reduce->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->reduce->ForeColor = System::Drawing::SystemColors::Desktop;
			this->reduce->Location = System::Drawing::Point(398, 497);
			this->reduce->Name = L"reduce";
			this->reduce->Size = System::Drawing::Size(211, 112);
			this->reduce->TabIndex = 6;
			this->reduce->Text = L"Reduce";
			this->reduce->UseVisualStyleBackColor = false;
			this->reduce->Click += gcnew System::EventHandler(this, &MyForm::reduce_Click);
			// 
			// track_polygons
			// 
			this->track_polygons->Location = System::Drawing::Point(13, 239);
			this->track_polygons->Name = L"track_polygons";
			this->track_polygons->Size = System::Drawing::Size(399, 56);
			this->track_polygons->TabIndex = 7;
			this->track_polygons->Scroll += gcnew System::EventHandler(this, &MyForm::track_polygons_Scroll);
			track_polygons->Maximum = 100;
			track_polygons->TickFrequency = 10;
			// 
			// track_deformations
			// 
			this->track_deformations->Location = System::Drawing::Point(16, 343);
			this->track_deformations->Name = L"track_deformations";
			this->track_deformations->Size = System::Drawing::Size(396, 56);
			this->track_deformations->TabIndex = 8;
			this->track_deformations->Scroll += gcnew System::EventHandler(this, &MyForm::track_deformations_Scroll);
			track_deformations->Maximum = 100;
			track_deformations->TickFrequency = 10;
			// 
			// check
			// 
			this->check->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->check->Location = System::Drawing::Point(12, 572);
			this->check->Name = L"check";
			this->check->Size = System::Drawing::Size(159, 37);
			this->check->TabIndex = 9;
			this->check->Text = L"Check";
			this->check->UseVisualStyleBackColor = false;
			// 
			// text_com_oryg_model
			// 
			this->text_com_oryg_model->AutoSize = true;
			this->text_com_oryg_model->ForeColor = System::Drawing::SystemColors::Control;
			this->text_com_oryg_model->Location = System::Drawing::Point(9, 497);
			this->text_com_oryg_model->Name = L"text_com_oryg_model";
			this->text_com_oryg_model->Size = System::Drawing::Size(229, 17);
			this->text_com_oryg_model->TabIndex = 10;
			this->text_com_oryg_model->Text = L"Compliance with the oryginal model";
			// 
			// textBox_compliance
			// 
			this->textBox_compliance->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->textBox_compliance->Location = System::Drawing::Point(12, 533);
			this->textBox_compliance->Name = L"textBox_compliance";
			this->textBox_compliance->ReadOnly = true;
			this->textBox_compliance->Size = System::Drawing::Size(162, 22);
			this->textBox_compliance->TabIndex = 11;
			this->textBox_compliance->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox_compliance_TextChange);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(419, 239);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(30, 22);
			this->textBox1->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(419, 343);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(30, 22);
			this->textBox2->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->ClientSize = System::Drawing::Size(621, 668);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox_compliance);
			this->Controls->Add(this->text_com_oryg_model);
			this->Controls->Add(this->check);
			this->Controls->Add(this->track_deformations);
			this->Controls->Add(this->track_polygons);
			this->Controls->Add(this->reduce);
			this->Controls->Add(this->text_deg_of_deform);
			this->Controls->Add(this->text_num_of_polygon);
			this->Controls->Add(this->automatically);
			this->Controls->Add(this->toolbar);
			this->Controls->Add(this->save_model);
			this->Controls->Add(this->load_model);
			this->Name = L"MyForm";
			this->Text = L"PolyReductor";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->track_polygons))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->track_deformations))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void reduce_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void load_model_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ load = gcnew OpenFileDialog;
	if (load->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
	}
}
private: System::Void save_model_Click(System::Object^  sender, System::EventArgs^  e) {
	SaveFileDialog^ save = gcnew SaveFileDialog;
	if (save->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
	}
}
private: System::Void toolbar_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenFileDialog^ toolbar = gcnew OpenFileDialog;
	if (toolbar->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
	}
}
private: System::Void automatically_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (automatically->Checked == true) {
		/*The degree of similarity model*/
		this->text_num_of_polygon->Text = L"Degree of similary model";
	}
	else {
		this->text_num_of_polygon->Text = L"Numbers of Polygons";
	}
}
private: System::Void textBox_compliance_TextChange(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void track_polygons_Scroll(System::Object^ sender, System::EventArgs^ e) {
		textBox1->Text = String::Concat("", track_polygons->Value);
	}
 private: System::Void track_deformations_Scroll(System::Object^ sender, System::EventArgs^ e) {
		 textBox2->Text = String::Concat("", track_deformations->Value);
	 }
};
};
