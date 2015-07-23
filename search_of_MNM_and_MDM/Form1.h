#pragma once
#include "Vertex.h"
#include "Graph.h"
#include "AddForm.h"
#include "AddEdgeForm.h"
#include "DeleteForm.h"
#include "DeleteEdgeForm.h"
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

namespace search_of_MNM_and_MDM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	typedef vector<int> line_t;
	typedef vector<vector<int>> matrix_t;

	struct Point
	{
		int x;
		int y;
	};

	Graph graph;
	int num_picture = 0;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 

	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::ListBox^  listBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button7;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBox1->Location = System::Drawing::Point(2, 45);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(104, 30);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Алгоритм\r\nБрона-Кербоша";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 55);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(102, 17);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Алгоритм Магу";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Location = System::Drawing::Point(519, 18);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(102, 123);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Поиск МНМ";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(6, 87);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(90, 17);
			this->radioButton3->TabIndex = 4;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Метод Ткача";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Location = System::Drawing::Point(519, 157);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(102, 57);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Поиск ДНМ";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(6, 19);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(86, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Метод Магу";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(512, 274);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 26);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Список\r\nнайденных МНМ";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(516, 300);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(111, 108);
			this->listBox1->TabIndex = 7;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(514, 445);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(111, 108);
			this->listBox2->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(511, 419);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 26);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Список\r\nнайденных МДМ";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(258, 551);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(244, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Очистить поле";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(2, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(122, 23);
			this->button3->TabIndex = 12;
			this->button3->Text = L"Добавить вершину";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(129, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(123, 23);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Удалить вершину";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(2, 551);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(250, 23);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Загрузить граф из файла";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(519, 232);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(102, 23);
			this->button6->TabIndex = 15;
			this->button6->Text = L"Начать поиск!";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(258, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(124, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Добавить ребро";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(388, 12);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(114, 23);
			this->button7->TabIndex = 17;
			this->button7->Text = L"Удалить ребро";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(640, 582);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Поиск МНМ и МДМ";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }

void drawGraph(Graphics^ graphics)
{
	Pen^ myPen = gcnew Pen(Color::Black);
	Point center;
	Dot dot;
	int coef = 10;
	center.x = pictureBox1->Width/2 - coef/2;
	center.y = pictureBox1->Height/2 - coef/2;
	int r = 170;
	int n = graph.vertex.size();
	Vertex vert;
	for (int i = 0; i < n; i++)
	{
		int x = center.x + (int)(r * Math::Cos(Math::PI + 2 * i * Math::PI / n));
		int y = center.y + (int)(r * Math::Sin(Math::PI + 2 * i * Math::PI / n));
		graphics->FillEllipse(Brushes::Black, x, y, coef, coef);

		std::ostringstream ost;
		std::string cst;
		ost << i+1;
		cst = ost.str();
		String^ num = gcnew String(cst.c_str());
		Drawing::Font^ drawFont = gcnew Drawing::Font("Times New Roman", 12, FontStyle::Regular);
		int xNum = center.x + (int)((r+coef + coef/2) * Math::Cos(Math::PI + 2 * i * Math::PI / n));
		int yNum = center.y + (int)((r+coef + coef/2) * Math::Sin(Math::PI + 2 * i * Math::PI / n));
		PointF drawPoint = PointF(xNum,yNum);
		graphics->DrawString(num, drawFont, Brushes::Black, drawPoint);

		dot.x = x+coef/2; dot.y = y+coef/2;
		vert.coord.push_back(dot);
	}
	for (int i = 0; i < n; i++)
	{
		std::vector<int> &adj = graph.vertex[i].adjacent;
		for (int j = 0; j < adj.size(); j++)
		{
			int x1 = vert.coord[i].x;
			int y1 = vert.coord[i].y;
			int x2 = vert.coord[adj[j]].x;
			int y2 = vert.coord[adj[j]].y;
			graphics->DrawLine(myPen, x1, y1, x2, y2);
		}
	}

}
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			Graphics^ graphics = e->Graphics;  // Создаем локальную версию объекта graphics для PictureBox.
			drawGraph(graphics);
			pictureBox1->Refresh();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 AddForm ^a = gcnew AddForm;
				 a->ShowDialog();

				 String^ new_neigh = Convert::ToString(a->textBox1->Text);
				 char* myString = new char[new_neigh->Length];
				 for(int i = 0; i < new_neigh->Length; i++)
					myString[i] = new_neigh[i];

				 std::istringstream iss (myString, std::istringstream::in);
				 int t;
				 line_t new_vert;
				 while(iss >> t) if(t <= graph.vertex.size()) new_vert.push_back(t-1);

				 graph.addVertex(new_vert);
				 pictureBox1->Refresh();
			 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				graph.vertex.clear();
				listBox1->Items->Clear();
				listBox2->Items->Clear();

				std::ofstream out("out.txt");
				String^ name = Convert::ToString(openFileDialog1->FileName);
				char* myString = new char[name->Length];
				bool flag = false;
				int k = 0;
				for(int i = 0; i < name->Length; i++)
				{
					if(name[i] == 'g') flag = true;
					if(flag) myString[k++] = name[i];
				}
				myString[k] = 0;

				std::ifstream in(myString);
				graph.initFromFile(in);
				
				pictureBox1->Refresh();
				in.close();
				out.close();
			}
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 DeleteForm ^b = gcnew DeleteForm;
			 b->ShowDialog();

			String^ new_neigh = Convert::ToString(b->textBox1->Text);
			char* myString = new char[new_neigh->Length];
			for(int i = 0; i < new_neigh->Length; i++) myString[i] = new_neigh[i];

			std::istringstream iss (myString, std::istringstream::in);
			int del_vert;
			iss >> del_vert;
			
			if(del_vert != '\0' && del_vert <= graph.vertex.size()) graph.deleteVertex(del_vert-1);
			pictureBox1->Refresh();
		 }
private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 AddEdgeForm ^b = gcnew AddEdgeForm;
			 b->ShowDialog();

			String^ new_neigh = Convert::ToString(b->textBox1->Text);
			char* myString = new char[new_neigh->Length];
			for(int i = 0; i < new_neigh->Length; i++) myString[i] = new_neigh[i];

			std::istringstream iss (myString, std::istringstream::in);
			int vert1, vert2;
			iss >> vert1 >> vert2;
			
			if(vert1 != '\0' && vert2 != '\0' && vert1 <= graph.vertex.size() && vert2 <= graph.vertex.size()) graph.addEdge(vert1-1, vert2-1);
			pictureBox1->Refresh();
		 }
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 DeleteEdgeForm ^b = gcnew DeleteEdgeForm;
			 b->ShowDialog();

			String^ new_neigh = Convert::ToString(b->textBox1->Text);
			char* myString = new char[new_neigh->Length];
			for(int i = 0; i < new_neigh->Length; i++) myString[i] = new_neigh[i];

			std::istringstream iss (myString, std::istringstream::in);
			int vert1, vert2;
			iss >> vert1 >> vert2;
			
			if(vert1 != '\0' && vert2 != '\0' && vert1 <= graph.vertex.size() && vert2 <= graph.vertex.size()) graph.deleteEdge(vert1-1, vert2-1);
			pictureBox1->Refresh();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 graph.vertex.clear();
			 listBox1->Items->Clear();
			 listBox2->Items->Clear();
			 pictureBox1->Refresh();
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 matrix_t mnm;
			 matrix_t mdm;
			 listBox1->Items->Clear();
			 listBox2->Items->Clear();
			 if(checkBox1->Checked)		      mdm = maguMethod(graph);
			 if(radioButton1->Checked)		  mnm = bronKerboshAlg(graph);
			 else if(radioButton2->Checked)   mnm = maguAlg(graph);
			 else if(radioButton3->Checked)   mnm = tkachAlg(graph);
			 ofstream out("out.txt");
			 for(int i = 0; i < mnm.size(); i++)
			 {
				 if(mnm[i].empty()) break;
				 ostringstream ost;
				 string cst;
				 ost << i+1;
				 cst = ost.str();
				 ost.flush();
				 String^ num = gcnew String(cst.c_str());
				 String^ elem;
				 num = num + ". { ";
				 for(int j = 0; j < mnm[i].size(); j++)
				 {	
					 ostringstream ost_j;
					 string cst_j;
					 ost_j.flush();
					 ost_j << mnm[i][j] + 1;
					 cst_j = ost_j.str();
					 elem = gcnew String(cst_j.c_str());
					 num += elem + " ";
				 }
				 num += "}";
				 listBox1->Items->Add(num);
			 }
			 for(int i = 0; i < mdm.size(); i++)
			 {
				 if(mdm[i].empty()) break;
				 ostringstream ost;
				 string cst;
				 ost << i+1;
				 cst = ost.str();
				 String^ num = gcnew String(cst.c_str());
				 String^ elem;
				 num = num + ". { ";
				 for(int j = 0; j < mdm[i].size(); j++)
				 {	
					 ostringstream ost1;
					 string cst1;
					 ost1 << mdm[i][j] + 1;
					 cst1 = ost1.str();
					 elem = gcnew String(cst1.c_str());
					 num += elem + " ";
				 }
				 num += "}";
				 listBox2->Items->Add(num);
			 }
		 }
matrix_t bronKerboshAlg(Graph &graph)
{
	matrix_t result;
	line_t compsub;
	line_t notElem;
	line_t candidates;
	for(int i = 0; i < graph.vertex.size(); i++) candidates.push_back(i);
	searchMNM(graph, candidates, notElem, compsub, result);
	return result;
}
void searchMNM(Graph &graph, line_t &candidates, line_t &notElem, line_t &compsub, matrix_t &result)
{
	while (!candidates.empty()  && graph.isAllAdjacent(candidates, notElem))
	{
		int v = candidates[0];
		line_t new_compsub = compsub;
		new_compsub.push_back(v);
		line_t new_candidates = candidates;
		line_t new_not = notElem;

		newCandAndNot(new_candidates, new_not, graph.vertex[v].adjacent);

		if(new_candidates.empty() && new_not.empty() && isMax(new_compsub, result)) result.push_back(new_compsub); 
		else searchMNM(graph, new_candidates, new_not, new_compsub, result);

		candidates.erase(candidates.begin());
		notElem.push_back(v);
	}
}
void newCandAndNot(line_t &candidates, line_t &not_elem, line_t const &adjacent)
{
	for(int i = 0; i < adjacent.size(); i++)
	{ 
		line_t::iterator it = find(candidates.begin(), candidates.end(), adjacent[i]);
		if (it < candidates.end()) candidates.erase(it);
		
		it = find(not_elem.begin(), not_elem.end(), adjacent[i]);
		if (it < not_elem.end()) not_elem.erase(it);
	}
	candidates.erase(candidates.begin());
}
bool isMax(line_t const &compsub, matrix_t &result)
{
	for(int i = 0; i < result.size(); i++)
	{
		int cnt = countSameNum(compsub, result[i]);

		if(cnt == compsub.size()) return false;
		if(cnt == result[i].size()) result.erase(result.begin() + i--);
	}
	return true;
}
matrix_t tkachAlg(Graph &graph)
{
	matrix_t result;
	const int graph_size = graph.vertex.size();
	for(int i = 0; i < graph_size; i++)
	{
		int k = 0;
		line_t &adjacent = graph.vertex[i].adjacent;
		line_t &inversion = graph.vertex[i].inversion;

		for(int j = 0; j < adjacent.size(); j++, k++)
			while(k < graph_size && adjacent[j] != k)
				inversion.push_back(k++);

		while(k < graph_size) inversion.push_back(k++);
	}

	for(int i = 0; i < graph_size; i++)
	{
		line_t &inversion = graph.vertex[i].inversion;
		line_t &inversionT = graph.vertex[i].inversionT;

		for(int j = 0; j < inversion.size(); j++)
		{
			int k = inversion[j];
			graph.vertex[k].inversionT.push_back(i);
		}
	}

	for(int i = 0; i < graph_size; i++)
	{
		int j = 0, k = 0;
		line_t &inversion = graph.vertex[i].inversion;
		line_t &inversionT = graph.vertex[i].inversionT;
		line_t &notAdjacent = graph.vertex[i].notAdjacent;

		while(j < inversion.size() && inversion[j] < inversionT[k]) j++;
		while(k < inversionT.size() && inversionT[k] < inversion[j]) k++;
		while(j < inversion.size() && k < inversionT.size() && inversion[j] == inversionT[k])
		{ notAdjacent.push_back(inversion[j++]); k++; }
	}

	for(int i = 0; i < graph_size; i++)
	{
		line_t candidates = graph.vertex[i].notAdjacent;
		while(candidates[0] < i) candidates.erase(candidates.begin());
		vector<int> compsub;
		findMNM(graph, candidates, compsub, result);
	}
	for(int i = 0; i < graph_size; i++)
	{
		graph.vertex[i].inversion.clear();
		graph.vertex[i].inversionT.clear();
		graph.vertex[i].notAdjacent.clear();
	}

	return result;
}
void findMNM(Graph &graph, line_t &candidates, line_t &compsub, matrix_t &result)
{
	while (!candidates.empty())
	{
		int v = candidates[0];
		line_t new_compsub = compsub;
		new_compsub.push_back(v);

		line_t new_candidates = candidates;
		new_candidates.erase(new_candidates.begin());

		if(isMNM(new_compsub, graph) && isMax(new_compsub, result)) result.push_back(new_compsub); 
		findMNM(graph, new_candidates, new_compsub, result);

		candidates.erase(candidates.begin());
	}
}
bool isMNM(line_t const &compsub, Graph &graph)
{
	int cnt = 0;
	for(int i = 0; i < compsub.size(); i++)
		cnt += isEq(graph.vertex[compsub[i]].notAdjacent, compsub);
	return cnt == compsub.size();
}
int isEq(line_t const &line1, line_t const &line2)
{
	int cnt = countSameNum(line1, line2);
	return cnt == line2.size();
}
matrix_t maguAlg(Graph &graph)
{
	matrix_t allPairs;
	const int graph_size = graph.vertex.size();
	
	//записать подвектор из матрицы связности начиная с номера превышающего номер строки в массив allPairs
	for(int i = 0; i < graph_size; i++)
	{
		int j = 0;
		line_t tmp;
		line_t &adjacent = graph.vertex[i].adjacent;

		while(j < adjacent.size() && i > adjacent[j]) j++;
		while(j < adjacent.size()) tmp.push_back(adjacent[j++]);
		allPairs.push_back(tmp);
	}

	//задание всех вариантов перемножения типа (a+b)(c+d)(e+f)(g+h)...(y+z)... 
	matrix_t allConj;
	line_t compsub;
	conjunction(allConj, compsub, allPairs, 0);

	for(int i = 0; i < allConj.size(); i++)
	{
		sort(allConj[i].begin(), allConj[i].end());
		allConj[i].erase(unique(allConj[i].begin(), allConj[i].end()),allConj[i].end());
	}

	for(int i = 0; i < allConj.size(); i++)
		if(deleteRow(allConj[i], allConj)) { allConj.erase(allConj.begin() + i); i--; }

	matrix_t result(allConj.size());
	for(int i = 0; i < allConj.size(); i++)
	{
		int k = 0;
		for(int j = 0; j < allConj[i].size(); j++, k++)
			while(k < graph_size && allConj[i][j] != k) result[i].push_back(k++);
		while(k < graph_size) result[i].push_back(k++);
	}

	return result;
}
void conjunction(matrix_t &result, line_t &compsub, matrix_t &b, int a)
{
	if (a == b.size()) result.push_back(compsub);
	else
	{
		line_t new_compsub = compsub;
		new_compsub.push_back(a);
		conjunction(result, new_compsub, b, a+1);
		new_compsub.pop_back();
		for(int i = 0; i < b[a].size(); i++)
			new_compsub.push_back(b[a][i]);
		conjunction(result, new_compsub, b, a+1);
	}
}
void deleteRow(line_t  const &row, matrix_t const &matrix, line_t  &index, int bi)
{
	for(int i = bi+1; i < matrix.size(); i++) if (index[i])
	{
		if (row.size()>matrix[i].size())
		{ if (subLine(row, matrix[i])) index[bi] = 0;}
		else if (subLine(matrix[i], row)) index[i] = 0;

	}
}
bool deleteRow(line_t const &row, matrix_t const &matrix, line_t const &index)
{
	int was = 0;
	for(int i = 0; i < matrix.size(); i++) if (index[i])
	{
		int cnt = subNumLine(row, matrix[i]);
		if(cnt == matrix[i].size())
		{
			if(cnt == row.size()) { was++; if (was > 1) return true; }
			else if(cnt < row.size()) return true;
		}
	}
	return false;
}
bool deleteRow(line_t const &row, matrix_t const &matrix)
{
	int was = 0;
	for(int i = 0; i < matrix.size(); i++)
	{
		int cnt = subNumLine(row, matrix[i]);
		if(cnt == matrix[i].size())
		{
			if(cnt == row.size()) { was++; if (was > 1) return true; }
			else if(cnt < row.size()) return true;
		}
	}
	return false;
}
bool subLine(line_t const &line1, line_t const &line2)
{
	int cnt = 0;
	for(int i = 0; i < line2.size(); i++)
	{
		int fnt = 0;
		for(int j = 0; j < line1.size(); j++) if(line1[j] == line2[i])
		{ cnt++; fnt++; break; }
		if (fnt == 0) return false;
	}
	return (cnt == line2.size());
}
int subNumLine(line_t const &line1, line_t const &line2)
{
	if (line2.size()>line1.size()) return 0;
	int cnt = 0;
	for(int i = 0; i < line1.size(); i++)
		for(int j = 0; j < line2.size(); j++) if(line2[j] == line1[i])
		{ cnt++; break; }
	return cnt;
}
int countSameNum(line_t const &line1, line_t const &line2)
{
	int cnt = 0;
	for(int i = 0; i < line1.size(); i++)
		for(int j = 0; j < line2.size(); j++)
			if(line1[i] == line2[j]) { cnt++; break; }
	return cnt;
}
matrix_t maguMethod(Graph &graph)
{
	matrix_t allPairs;
	const int graph_size = graph.vertex.size();
	matrix_t mdm(graph_size);
	
	for(int i = 0; i < graph_size; i++)
	{
		line_t &adjacent = graph.vertex[i].adjacent;
		for(int j = 0; j < adjacent.size(); j++)
			mdm[i].push_back(adjacent[j]);
	}

	matrix_t allConj;
	line_t compsub;
	conjunctionForMDM(allConj, compsub, mdm, 0);

	const int conj_size = allConj.size();
	for(int i = 0; i < conj_size; i++)
	{
		sort(allConj[i].begin(), allConj[i].end());
		allConj[i].erase(unique(allConj[i].begin(), allConj[i].end()),allConj[i].end());
	}

	line_t index(conj_size,1);

	for(int i = 0; i < conj_size; i++)	if (index[i])
		deleteRow(allConj[i], allConj, index, i);

	matrix_t newConj;
	for(int i = 0; i < conj_size; i++)	if(index[i]) 
		newConj.push_back(allConj[i]); 

	return newConj;
}
void conjunctionForMDM(matrix_t &result, line_t &compsub, matrix_t &b, int a)
{
	if (a == b.size()) result.push_back(compsub);
	else
	{
		line_t new_compsub = compsub;
		new_compsub.push_back(a);
		conjunctionForMDM(result, new_compsub, b, a+1);
		new_compsub.pop_back();
		for(int i = 0; i< b[a].size(); i++)
		{
			new_compsub.push_back(b[a][i]);
			conjunctionForMDM(result, new_compsub, b, a+1);
			new_compsub.pop_back();
		}
	}
}
};
}

