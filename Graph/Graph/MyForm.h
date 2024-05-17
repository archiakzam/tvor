#pragma once

GraphClass graph_1(15);
int serial_number = 1;

void display() { 
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f); 

	graph_1.draw_graph();

	glFlush();
	glutSwapBuffers();
}

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void) {
			InitializeComponent();	
		}
	protected:
		~MyForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_weight;
	protected:

	protected:

	private: System::Windows::Forms::Button^ add_vertex;
	private: System::Windows::Forms::Button^ add_edge;
	private: System::Windows::Forms::TextBox^ text_box_from;

	private: System::Windows::Forms::Button^ find_way;
	private: System::Windows::Forms::Button^ delete_vertex;
	private: System::Windows::Forms::Button^ delete_edge;
	private: System::Windows::Forms::Label^ label_from;
	private: System::Windows::Forms::TextBox^ text_box_to;
	private: System::Windows::Forms::Label^ label_to;
	private: System::Windows::Forms::TextBox^ text_box_weight;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->label_weight = (gcnew System::Windows::Forms::Label());
			this->add_vertex = (gcnew System::Windows::Forms::Button());
			this->add_edge = (gcnew System::Windows::Forms::Button());
			this->text_box_from = (gcnew System::Windows::Forms::TextBox());
			this->find_way = (gcnew System::Windows::Forms::Button());
			this->delete_vertex = (gcnew System::Windows::Forms::Button());
			this->delete_edge = (gcnew System::Windows::Forms::Button());
			this->label_from = (gcnew System::Windows::Forms::Label());
			this->text_box_to = (gcnew System::Windows::Forms::TextBox());
			this->label_to = (gcnew System::Windows::Forms::Label());
			this->text_box_weight = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label_weight
			// 
			this->label_weight->AutoSize = true;
			this->label_weight->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_weight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_weight->Font = (gcnew System::Drawing::Font(L"Calibri", 19, System::Drawing::FontStyle::Italic));
			this->label_weight->Location = System::Drawing::Point(171, 23);
			this->label_weight->Name = L"label_weight";
			this->label_weight->Size = System::Drawing::Size(122, 32);
			this->label_weight->TabIndex = 5;
			this->label_weight->Text = L"Вес ребра";
			this->label_weight->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// add_vertex
			// 
			this->add_vertex->BackColor = System::Drawing::Color::LightGray;
			this->add_vertex->Cursor = System::Windows::Forms::Cursors::Hand;
			this->add_vertex->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->add_vertex->FlatAppearance->BorderSize = 2;
			this->add_vertex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_vertex->Font = (gcnew System::Drawing::Font(L"Calibri", 19, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->add_vertex->Location = System::Drawing::Point(76, 131);
			this->add_vertex->Name = L"add_vertex";
			this->add_vertex->Size = System::Drawing::Size(300, 100);
			this->add_vertex->TabIndex = 6;
			this->add_vertex->Text = L"Добавить вершину";
			this->add_vertex->UseVisualStyleBackColor = false;
			this->add_vertex->Click += gcnew System::EventHandler(this, &MyForm::add_vertex_Click);
			// 
			// add_edge
			// 
			this->add_edge->BackColor = System::Drawing::Color::LightGray;
			this->add_edge->Cursor = System::Windows::Forms::Cursors::Hand;
			this->add_edge->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->add_edge->FlatAppearance->BorderSize = 2;
			this->add_edge->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->add_edge->Font = (gcnew System::Drawing::Font(L"Calibri", 19, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->add_edge->Location = System::Drawing::Point(76, 364);
			this->add_edge->Name = L"add_edge";
			this->add_edge->Size = System::Drawing::Size(300, 100);
			this->add_edge->TabIndex = 7;
			this->add_edge->Text = L"Добавить ребро";
			this->add_edge->UseVisualStyleBackColor = false;
			this->add_edge->Click += gcnew System::EventHandler(this, &MyForm::add_edge_Click);
			// 
			// text_box_from
			// 
			this->text_box_from->BackColor = System::Drawing::Color::LightGray;
			this->text_box_from->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->text_box_from->Font = (gcnew System::Drawing::Font(L"Calibri", 19, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_box_from->Location = System::Drawing::Point(12, 58);
			this->text_box_from->Name = L"text_box_from";
			this->text_box_from->Size = System::Drawing::Size(102, 38);
			this->text_box_from->TabIndex = 8;
			this->text_box_from->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// find_way
			// 
			this->find_way->BackColor = System::Drawing::Color::LightGray;
			this->find_way->Cursor = System::Windows::Forms::Cursors::Hand;
			this->find_way->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->find_way->FlatAppearance->BorderSize = 2;
			this->find_way->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->find_way->Font = (gcnew System::Drawing::Font(L"Calibri", 19, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->find_way->Location = System::Drawing::Point(76, 598);
			this->find_way->Name = L"find_way";
			this->find_way->Size = System::Drawing::Size(300, 100);
			this->find_way->TabIndex = 9;
			this->find_way->Text = L"Найти кратчайшее растояние";
			this->find_way->UseVisualStyleBackColor = false;
			this->find_way->Click += gcnew System::EventHandler(this, &MyForm::find_way_Click);
			// 
			// delete_vertex
			// 
			this->delete_vertex->BackColor = System::Drawing::Color::LightGray;
			this->delete_vertex->Cursor = System::Windows::Forms::Cursors::Hand;
			this->delete_vertex->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->delete_vertex->FlatAppearance->BorderSize = 2;
			this->delete_vertex->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_vertex->Font = (gcnew System::Drawing::Font(L"Calibri", 19, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->delete_vertex->Location = System::Drawing::Point(76, 249);
			this->delete_vertex->Name = L"delete_vertex";
			this->delete_vertex->Size = System::Drawing::Size(300, 100);
			this->delete_vertex->TabIndex = 10;
			this->delete_vertex->Text = L"Удалить вершину";
			this->delete_vertex->UseVisualStyleBackColor = false;
			this->delete_vertex->Click += gcnew System::EventHandler(this, &MyForm::delete_vertex_Click);
			// 
			// delete_edge
			// 
			this->delete_edge->BackColor = System::Drawing::Color::LightGray;
			this->delete_edge->Cursor = System::Windows::Forms::Cursors::Hand;
			this->delete_edge->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->delete_edge->FlatAppearance->BorderSize = 2;
			this->delete_edge->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delete_edge->Font = (gcnew System::Drawing::Font(L"Calibri", 19, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->delete_edge->Location = System::Drawing::Point(76, 481);
			this->delete_edge->Name = L"delete_edge";
			this->delete_edge->Size = System::Drawing::Size(300, 100);
			this->delete_edge->TabIndex = 11;
			this->delete_edge->Text = L"Удалить ребро";
			this->delete_edge->UseVisualStyleBackColor = false;
			this->delete_edge->Click += gcnew System::EventHandler(this, &MyForm::delete_edge_Click);
			// 
			// label_from
			// 
			this->label_from->AutoSize = true;
			this->label_from->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_from->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_from->Font = (gcnew System::Drawing::Font(L"Calibri", 19, System::Drawing::FontStyle::Italic));
			this->label_from->Location = System::Drawing::Point(35, 23);
			this->label_from->Name = L"label_from";
			this->label_from->Size = System::Drawing::Size(52, 32);
			this->label_from->TabIndex = 12;
			this->label_from->Text = L"От";
			this->label_from->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// text_box_to
			// 
			this->text_box_to->BackColor = System::Drawing::Color::LightGray;
			this->text_box_to->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->text_box_to->Font = (gcnew System::Drawing::Font(L"Calibri", 19, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_box_to->Location = System::Drawing::Point(345, 58);
			this->text_box_to->Name = L"text_box_to";
			this->text_box_to->Size = System::Drawing::Size(102, 38);
			this->text_box_to->TabIndex = 13;
			this->text_box_to->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_to
			// 
			this->label_to->AutoSize = true;
			this->label_to->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_to->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_to->Font = (gcnew System::Drawing::Font(L"Calibri", 19, System::Drawing::FontStyle::Italic));
			this->label_to->Location = System::Drawing::Point(379, 23);
			this->label_to->Name = L"label_to";
			this->label_to->Size = System::Drawing::Size(28, 32);
			this->label_to->TabIndex = 14;
			this->label_to->Text = L"К";
			this->label_to->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// text_box_weight
			// 
			this->text_box_weight->BackColor = System::Drawing::Color::LightGray;
			this->text_box_weight->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->text_box_weight->Font = (gcnew System::Drawing::Font(L"Calibri", 19, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_box_weight->Location = System::Drawing::Point(177, 58);
			this->text_box_weight->Name = L"text_box_weight";
			this->text_box_weight->Size = System::Drawing::Size(102, 38);
			this->text_box_weight->TabIndex = 15;
			this->text_box_weight->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MediumPurple;
			this->ClientSize = System::Drawing::Size(459, 722);
			this->Controls->Add(this->text_box_weight);
			this->Controls->Add(this->label_to);
			this->Controls->Add(this->text_box_to);
			this->Controls->Add(this->label_from);
			this->Controls->Add(this->delete_edge);
			this->Controls->Add(this->delete_vertex);
			this->Controls->Add(this->find_way);
			this->Controls->Add(this->text_box_from);
			this->Controls->Add(this->add_edge);
			this->Controls->Add(this->add_vertex);
			this->Controls->Add(this->label_weight);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Graph";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void add_vertex_Click(System::Object^ sender, System::EventArgs^ e) {
			graph_1.insert_vertex(serial_number);
			serial_number++;
		}
	private: 
		System::Void delete_vertex_Click(System::Object^ sender, System::EventArgs^ e) {
			graph_1.delete_vertex(serial_number - 1);
			serial_number--;
		}

	private: 
		System::Void add_edge_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->text_box_from->Text != "" && this->text_box_to->Text != "" && this->text_box_weight->Text != "") {
				try {
					unsigned int value_1 = Convert::ToUInt32(this->text_box_from->Text);
					unsigned int value_2 = Convert::ToUInt32(this->text_box_to->Text);
					unsigned int value_3 = Convert::ToUInt32(this->text_box_weight->Text);
					graph_1.insert_edge(value_1, value_2, value_3);
				}
				catch (FormatException^) {
					MessageBox::Show(this, "Введенное значение не является натуральным числом!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				catch (OverflowException^) {
					MessageBox::Show(this, "Введенное значение не является натуральным числом!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				this->text_box_from->Text = "";
				this->text_box_to->Text = "";
				this->text_box_weight->Text = "";
			}
			else {
				cout << "Введите значения!\n";
			}
		}
	private: 
		System::Void delete_edge_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->text_box_from->Text != "" && this->text_box_to->Text != "") {
				try {
					unsigned int value_1 = Convert::ToUInt32(this->text_box_from->Text);
					unsigned int value_2 = Convert::ToUInt32(this->text_box_to->Text);
					graph_1.delete_edge(value_1, value_2);
				}
				catch (FormatException^) {
					MessageBox::Show(this, "Введенное значение не является натуральным числом!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				catch (OverflowException^) {
					MessageBox::Show(this, "Введенное значение не является натуральным числом!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				this->text_box_from->Text = "";
				this->text_box_to->Text = "";
				this->text_box_weight->Text = "";
			}
			else {
				cout << "Введите значения!\n";
			}
		}
	private: 
		System::Void find_way_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->text_box_from->Text != "" && this->text_box_to->Text != "") {
				try {
					unsigned int value_1 = Convert::ToUInt32(this->text_box_from->Text);
					unsigned int value_2 = Convert::ToUInt32(this->text_box_to->Text);
					graph_1.shortest_path(value_1, value_2);
				}
				catch (FormatException^) {
					MessageBox::Show(this, "Введенное значение не является натуральным числом!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				catch (OverflowException^) {
					MessageBox::Show(this, "Введенное значение не является натуральным числом!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				this->text_box_from->Text = "";
				this->text_box_to->Text = "";
				this->text_box_weight->Text = "";
			}
			else {
				cout << "Введите значения!\n";
			}
		}
	};
}
