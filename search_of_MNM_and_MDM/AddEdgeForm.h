#pragma once

namespace search_of_MNM_and_MDM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddEdgeForm
	/// </summary>
	public ref class AddEdgeForm : public System::Windows::Forms::Form
	{
	public:
		AddEdgeForm(void)
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
		~AddEdgeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	public: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::Button^  button1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(254, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������� ������ ���� ������, �������  ������ \r\n���� ��������� ������";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 49);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(254, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button1->Location = System::Drawing::Point(94, 75);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddEdgeForm::button1_Click);
			// 
			// AddEdgeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(281, 116);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"AddEdgeForm";
			this->Text = L"���������� �����";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
