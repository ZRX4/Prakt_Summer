#include "Game.h"
#include "MainForm.h"

namespace SUMMERprak {

   

    void Game::ResetGame() {
        
        this->BackgroundImage = backgroundday;
        pic1 = true;
        pic2 = false;
        pic3 = false;
        pic = true;
        score = 0;
        birdVelocity = 0;
        this->points_label->Text = "Очки: 0";
        pipeSpeed = 20;
        // Начальная позиция птички
        birg_pic->Top = 300;
        birg_pic->Left = 300;

     

        GeneratePipes(wall_pic1,wall_pic2 , 800);
        wall_pic1->Visible=false;
        wall_pic2->Visible = false;
        GeneratePipes(wall_pic3, wall_pic4, 1600);
        GeneratePipes(wall_pic5, wall_pic6, 2300);

        

        timerGame->Start();
    }


    void Game::GeneratePipes(System::Windows::Forms::PictureBox^ topPipe, System::Windows::Forms::PictureBox^ bottomPipe, int startX) {

        int topPipeHeight = 0;

        
        do {
            
            topPipeHeight = rand->Next(1, 12) * 50;

        } while (topPipeHeight == lalastPipeHeight);
        lalastPipeHeight = topPipeHeight;
       
        // Настраиваем верхнюю трубу
        topPipe->Left = startX;
        topPipe->Top = 0;
        topPipe->Height = topPipeHeight;

        // Настраиваем нижнюю трубу
        bottomPipe->Left = startX;
        bottomPipe->Top = topPipeHeight + pipeGap;
        bottomPipe->Height = this->ClientSize.Height - bottomPipe->Top;

    
    }

    void Game::Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
       
       
        if (e->KeyCode == Keys::Space && timerGame->Enabled) {
            birdVelocity = -24;
        }

        if (e->KeyCode == Keys::Space && !timerGame->Enabled) {
            ResetGame();
        }

        if (e->KeyCode == Keys::R) {
            ResetGame();
        }


    }

    void  Game::timerGame_Tick(System::Object^ sender, System::EventArgs^ e) {
        


        birdVelocity += gravity;
        birg_pic->Top += birdVelocity;

    

        wall_pic1->Left -= pipeSpeed;
        wall_pic2->Left -= pipeSpeed;

        wall_pic3->Left -= pipeSpeed;
        wall_pic4->Left -= pipeSpeed;

        wall_pic5->Left -= pipeSpeed;
        wall_pic6->Left -= pipeSpeed;



        // Проверка для стены 1
        if (wall_pic1->Left < birg_pic->Left && !scoreAdded1) {
            if (score != 0) {
                pic = false;
                score++;
                scoreAdded1 = true;


            }
        }

        // Проверка для стены 3
        if (wall_pic3->Left < birg_pic->Left && !scoreAdded3) {
            pic = false;
            score++;
            scoreAdded3 = true;
        }

        // Проверка для стены 5
        if (wall_pic5->Left < birg_pic->Left && !scoreAdded5) {
            pic = false;
            score++;
            scoreAdded5 = true;
        }

        
        points_label->Text = "Очки: " + score.ToString();

        if (wall_pic3->Left < -wall_pic3->Width) {
            
            GeneratePipes(wall_pic3, wall_pic4, this->Width);
            
            scoreAdded3 = false;
            
            if (score % 5 == 0) {
                pipeSpeed += 1;
            }
        }
        if ((wall_pic1->Left < -wall_pic1->Width)&&score<=2) {
            wall_pic1->Visible = true;
            wall_pic2->Visible = true;
        }

        if (wall_pic1->Left < -wall_pic1->Width) {
            
            GeneratePipes(wall_pic1, wall_pic2, this->Width);
            
            scoreAdded1 = false;
            
            if (score % 5 == 0) {
                pipeSpeed += 1;
            }
        }
        if (wall_pic5->Left < -wall_pic5->Width) {
            GeneratePipes(wall_pic5, wall_pic6, this->Width);
            

            scoreAdded5 = false;
            
            if (score % 5 == 0) {
                pipeSpeed += 1;
            }
        }
        



        if (birg_pic->Top <= 0 || birg_pic->Bottom >= this->ClientSize.Height) {
            timerGame->Stop();
            MessageBox::Show("Игра окончена!\nВаш счет: " + score.ToString() + "\nНажмите R для перезапуска", "Flappy Bird");
        }


        if ((birg_pic->Bounds.IntersectsWith(wall_pic1->Bounds) || birg_pic->Bounds.IntersectsWith(wall_pic2->Bounds))&&score>=1) {
            timerGame->Stop();
            MessageBox::Show("Игра окончена!\nВаш счет: " + score.ToString() + "\nНажмите R для перезапуска", "Flappy Bird");

        }

        if (birg_pic->Bounds.IntersectsWith(wall_pic3->Bounds) || birg_pic->Bounds.IntersectsWith(wall_pic4->Bounds)) {
            timerGame->Stop();
            MessageBox::Show("Игра окончена!\nВаш счет: " + score.ToString() + "\nНажмите R для перезапуска", "Flappy Bird");

        }

        if (birg_pic->Bounds.IntersectsWith(wall_pic5->Bounds) || birg_pic->Bounds.IntersectsWith(wall_pic6->Bounds)) {
            timerGame->Stop();
            MessageBox::Show("Игра окончена!\nВаш счет: " + score.ToString() + "\nНажмите R для перезапуска", "Flappy Bird");

        }

        if (score%20 ==0&&score!=0&&!pic) {

            if (pic3) {
                pic1 = true; pic3 = false;
                this->BackgroundImage = backgroundday;
                pic = true;
            }
            
               
            else if (pic1) {
                pic2 = true; pic1 = false;
                this->BackgroundImage = backgroundsun;
                pic = true;
            }

            else if (pic2) {
                pic3 = true; pic2 = false;
                this->BackgroundImage = backgroundnight;
                pic = true;
            }
            
        }



    }

    void Game::Game_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
        MainForm^kko=gcnew MainForm;
        kko->Show();
        
    }

}