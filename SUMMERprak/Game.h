#pragma once

namespace SUMMERprak {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{

	private: void ResetGame();
	private: void GeneratePipes(System::Windows::Forms::PictureBox^ topPipe, System::Windows::Forms::PictureBox^ bottomPipe, int startX);
	public:
		Game(void)
		{
			
			
			InitializeComponent();
			

			int startX = this->Width;
			System::Windows::Forms::PictureBox^ wall1 = wall_pic1;
			System::Windows::Forms::PictureBox^ wall2 = wall_pic2;

		
			this->DoubleBuffered = true;
			this->SetStyle(System::Windows::Forms::ControlStyles::Opaque, false); // Запрещает форме быть прозрачной
			this->SetStyle(System::Windows::Forms::ControlStyles::AllPaintingInWmPaint |
				System::Windows::Forms::ControlStyles::UserPaint |
				System::Windows::Forms::ControlStyles::DoubleBuffer, true);
			this->UpdateStyles();
			ResetGame();
			GeneratePipes (wall1, wall2, startX );
			//
			//TODO: добавьте код конструктора
			//
		}

	private:
		bool scoreAdded1;
		bool scoreAdded3;
		bool scoreAdded5;

	private:
		int lalastPipeHeight = 0;

	private:
		System::Drawing::Bitmap^ backgroundday= gcnew System::Drawing::Bitmap("bit1.jpg");
		System::Drawing::Bitmap^ backgroundsun = gcnew System::Drawing::Bitmap("bit2.jpg");
		System::Drawing::Bitmap^ backgroundnight = gcnew System::Drawing::Bitmap("bit3.jpg");
		bool pic1;
		bool pic2;
		bool pic3;
		bool pic;
		

	private:
		
		int gravity = 3;          // Сила, тянущая птичку вниз
		int pipeSpeed = 20;        // Скорость движения труб влево
		int score = 0;            // Счет
		int birdVelocity = 0;     // Текущая вертикальная скорость птички
		int pipeGap = 450;        // Размер прохода между трубами (в пикселях)
		System::Random^ rand = gcnew System::Random(); // Для случайной высоты труб


	private: System::Windows::Forms::PictureBox^ birg_pic;
	private: System::Windows::Forms::PictureBox^ wall_pic1;
	private: System::Windows::Forms::PictureBox^ wall_pic2;
	private: System::Windows::Forms::Label^ points_label;
	private: System::Windows::Forms::Timer^ timerGame;
	private: System::Windows::Forms::PictureBox^ wall_pic3;
	private: System::Windows::Forms::PictureBox^ wall_pic4;
	private: System::Windows::Forms::PictureBox^ wall_pic5;
	private: System::Windows::Forms::PictureBox^ wall_pic6;









		   int groundLevel = 250;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Game::typeid));
			this->birg_pic = (gcnew System::Windows::Forms::PictureBox());
			this->wall_pic1 = (gcnew System::Windows::Forms::PictureBox());
			this->wall_pic2 = (gcnew System::Windows::Forms::PictureBox());
			this->points_label = (gcnew System::Windows::Forms::Label());
			this->timerGame = (gcnew System::Windows::Forms::Timer(this->components));
			this->wall_pic3 = (gcnew System::Windows::Forms::PictureBox());
			this->wall_pic4 = (gcnew System::Windows::Forms::PictureBox());
			this->wall_pic5 = (gcnew System::Windows::Forms::PictureBox());
			this->wall_pic6 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->birg_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic6))->BeginInit();
			this->SuspendLayout();
			// 
			// birg_pic
			// 
			this->birg_pic->BackColor = System::Drawing::Color::Transparent;
			this->birg_pic->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"birg_pic.Image")));
			this->birg_pic->Location = System::Drawing::Point(128, 700);
			this->birg_pic->Name = L"birg_pic";
			this->birg_pic->Size = System::Drawing::Size(154, 120);
			this->birg_pic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->birg_pic->TabIndex = 0;
			this->birg_pic->TabStop = false;
			// 
			// wall_pic1
			// 
			this->wall_pic1->BackColor = System::Drawing::Color::Transparent;
			this->wall_pic1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wall_pic1.Image")));
			this->wall_pic1->Location = System::Drawing::Point(580, -20);
			this->wall_pic1->Name = L"wall_pic1";
			this->wall_pic1->Size = System::Drawing::Size(200, 468);
			this->wall_pic1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->wall_pic1->TabIndex = 1;
			this->wall_pic1->TabStop = false;
			// 
			// wall_pic2
			// 
			this->wall_pic2->BackColor = System::Drawing::Color::Transparent;
			this->wall_pic2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wall_pic2.Image")));
			this->wall_pic2->Location = System::Drawing::Point(614, 983);
			this->wall_pic2->Name = L"wall_pic2";
			this->wall_pic2->Size = System::Drawing::Size(186, 569);
			this->wall_pic2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->wall_pic2->TabIndex = 2;
			this->wall_pic2->TabStop = false;
			// 
			// points_label
			// 
			this->points_label->AutoSize = true;
			this->points_label->BackColor = System::Drawing::Color::Transparent;
			this->points_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->points_label->Font = (gcnew System::Drawing::Font(L"Consolas", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->points_label->Location = System::Drawing::Point(12, 140);
			this->points_label->Name = L"points_label";
			this->points_label->Size = System::Drawing::Size(206, 56);
			this->points_label->TabIndex = 3;
			this->points_label->Text = L"Очки: 0";
			// 
			// timerGame
			// 
			this->timerGame->Interval = 16;
			this->timerGame->Tick += gcnew System::EventHandler(this, &Game::timerGame_Tick);
			// 
			// wall_pic3
			// 
			this->wall_pic3->BackColor = System::Drawing::Color::Transparent;
			this->wall_pic3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wall_pic3.Image")));
			this->wall_pic3->Location = System::Drawing::Point(1294, -32);
			this->wall_pic3->Name = L"wall_pic3";
			this->wall_pic3->Size = System::Drawing::Size(200, 468);
			this->wall_pic3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->wall_pic3->TabIndex = 4;
			this->wall_pic3->TabStop = false;
			// 
			// wall_pic4
			// 
			this->wall_pic4->BackColor = System::Drawing::Color::Transparent;
			this->wall_pic4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wall_pic4.Image")));
			this->wall_pic4->Location = System::Drawing::Point(1308, 813);
			this->wall_pic4->Name = L"wall_pic4";
			this->wall_pic4->Size = System::Drawing::Size(186, 569);
			this->wall_pic4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->wall_pic4->TabIndex = 5;
			this->wall_pic4->TabStop = false;
			// 
			// wall_pic5
			// 
			this->wall_pic5->BackColor = System::Drawing::Color::Transparent;
			this->wall_pic5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wall_pic5.Image")));
			this->wall_pic5->Location = System::Drawing::Point(901, -11);
			this->wall_pic5->Name = L"wall_pic5";
			this->wall_pic5->Size = System::Drawing::Size(200, 468);
			this->wall_pic5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->wall_pic5->TabIndex = 6;
			this->wall_pic5->TabStop = false;
			// 
			// wall_pic6
			// 
			this->wall_pic6->BackColor = System::Drawing::Color::Transparent;
			this->wall_pic6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wall_pic6.Image")));
			this->wall_pic6->Location = System::Drawing::Point(964, 849);
			this->wall_pic6->Name = L"wall_pic6";
			this->wall_pic6->Size = System::Drawing::Size(186, 569);
			this->wall_pic6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->wall_pic6->TabIndex = 7;
			this->wall_pic6->TabStop = false;
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1912, 1158);
			this->Controls->Add(this->wall_pic6);
			this->Controls->Add(this->wall_pic5);
			this->Controls->Add(this->wall_pic4);
			this->Controls->Add(this->wall_pic3);
			this->Controls->Add(this->wall_pic2);
			this->Controls->Add(this->wall_pic1);
			this->Controls->Add(this->birg_pic);
			this->Controls->Add(this->points_label);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Game";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Flappy Bird";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Game::Game_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Game::Game_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->birg_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wall_pic6))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	

private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) {
	System::Drawing::Bitmap^ rawBmp1 = gcnew System::Drawing::Bitmap("bit1.jpg");
	System::Drawing::Bitmap^ rawBmp2 = gcnew System::Drawing::Bitmap("bit2.jpg");
	System::Drawing::Bitmap^ rawBmp3 = gcnew System::Drawing::Bitmap("bit3.jpg");
	
	backgroundday = gcnew System::Drawing::Bitmap(1920, 1200, System::Drawing::Imaging::PixelFormat::Format32bppPArgb);
	backgroundsun = gcnew System::Drawing::Bitmap(1920, 1200, System::Drawing::Imaging::PixelFormat::Format32bppPArgb);
	backgroundnight = gcnew System::Drawing::Bitmap(1920, 1200, System::Drawing::Imaging::PixelFormat::Format32bppPArgb);
	
	System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(backgroundday);
	System::Drawing::Graphics^ h = System::Drawing::Graphics::FromImage(backgroundsun);
	System::Drawing::Graphics^ j = System::Drawing::Graphics::FromImage(backgroundnight);

	g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::Low; 
	g->DrawImage(rawBmp1, 0, 0, 1920, 1200);
	delete g; 

	h->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::Low; 
	h->DrawImage(rawBmp2, 0, 0, 1920, 1200);
	delete h;

	j->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::Low; 
	j->DrawImage(rawBmp3, 0, 0, 1920, 1200);
	delete j;
	
	delete rawBmp1;
	delete rawBmp2;
	delete rawBmp3;

	ResetGame();
}

private: System::Void timerGame_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
private: System::Void Game_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);

};
}
