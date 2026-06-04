#include "Game.h"

namespace SUMMERprak {

    void Game::ResetGame() {
        score = 0;
        birdVelocity = 0;
        this->points_label->Text = "Очки: 0";

        // Начальная позиция птички
        birg_pic->Top = 300;
        birg_pic->Left = 350;

        // Генерируем положение первых труб на правом краю экрана

        GeneratePipes(wall_pic1,wall_pic2 , 1000);

        GeneratePipes(wall_pic3, wall_pic4, 1600);
        GeneratePipes(wall_pic5, wall_pic6, 2200);

        

        timerGame->Start();
    }


    void Game::GeneratePipes(System::Windows::Forms::PictureBox^ topPipe, System::Windows::Forms::PictureBox^ bottomPipe, int startX) {

        int topPipeHeight = rand->Next(200,500);


        // Настраиваем верхнюю трубу, переданную в функцию
        topPipe->Left = startX;
        topPipe->Top = 0;
        topPipe->Height = topPipeHeight;

        // Настраиваем нижнюю трубу, переданную в функцию
        bottomPipe->Left = startX;
        bottomPipe->Top = topPipeHeight + pipeGap;
        bottomPipe->Height = this->ClientSize.Height - bottomPipe->Top;

    
    }

    void Game::Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e){
    

        if (e->KeyCode == Keys::Space && timerGame->Enabled) {
            birdVelocity = -10;
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



        if (wall_pic3->Left < -wall_pic3->Width) {
            
            GeneratePipes(wall_pic3, wall_pic4, this->Width);

            score++;
            points_label->Text = "Очки: " + score.ToString();

            if (score % 5 == 0) {
                pipeSpeed += 1;
            }
        }

        if (wall_pic1->Left < -wall_pic1->Width) {
            GeneratePipes(wall_pic1, wall_pic2, this->Width);
            

            score++;
            points_label->Text = "Очки: " + score.ToString();

            if (score % 5 == 0) {
                pipeSpeed += 1;
            }
        }
        if (wall_pic5->Left < -wall_pic5->Width) {
            GeneratePipes(wall_pic5, wall_pic6, this->Width);


            score++;
            points_label->Text = "Очки: " + score.ToString();

            if (score % 3 == 0) {
                pipeSpeed += 1;
            }
        }
        



        if (birg_pic->Top <= 0 || birg_pic->Bottom >= this->ClientSize.Height) {
            timerGame->Stop();
            MessageBox::Show("Игра окончена!\nВаш счет: " + score.ToString() + "\nНажмите R для перезапуска", "Flappy Bird");
        }


        if (birg_pic->Bounds.IntersectsWith(wall_pic1->Bounds) || birg_pic->Bounds.IntersectsWith(wall_pic2->Bounds)) {
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



    }

}