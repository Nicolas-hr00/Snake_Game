#include "snake.h"
#include <vector> // test run
#include <stdio.h>
#include <stdlib.h>
//all functions and functionality of the game will be here

 //========================================================================================
    Snake::Snake()
    {

    }

   void Snake::draw() //this is going to draw the board of the game, including borders, head of the snake and the fruit based on the parameters of the height and the width
    {
      // sleep(0.5);
      int snake[width][height];
      clear(); //system ("clear");
       for (int i =0; i < width; i++)
          // cout << "*";
          // printw("*");
          addstr("#");

       // cout << endl;
        // printw("\n");
        addstr("\n");
      for (int i =0; i < height;i ++)
       {
          for (int j=1; j < width; j++)
           {
               if (j==1)
               {
               // printw("*");
               addstr("#");
                }
                if (i == y && j ==x)
                 {
                   // printw("S");
                   //snakes = "S";
                   addstr("S");
                 }
                 else if (i == fruitY && j == fruitX)
                  {
                      // printw("F") ;
                      addstr("*");
                  }
                  else
                 // printw(" ");
                 addstr(" ");
              if ( j == width-1)
               {
                // printw("*");
                addstr("#");
               }
           }
           // cout << endl;
           // printw("\n");
           addstr("\n");

        }
         for (int i =0; i < width; i++)
         {
           // cout << "*";
           // printw("\n");
           addstr("#");
           // cout << endl;
         }
         addstr("\nScore: ");
          // cout << "Score: " << score;
          if(x == fruitX && y == fruitY)
          {
            fruitX = rand()% (width);
            fruitY = rand()% (height);
             // addstr(to_string(score).c_str());
             score += 10;
             if (score == 0)    //we could use a switch statement so the run time could be faster, so it doesnt have to check each one of the if statements, but I didn't have time.
              {
                timeout(800);//change the time to 200
              }
             else if (score == 10)
              {
                timeout(700);//change the time to 200
              }
              else if (score == 20)
               {
                 timeout(600);//change the time to 200
               }
               else if (score == 30)
                {
                  timeout(500);//change the time to 200
                }
                else if (score == 40)
                 {
                   timeout(400);//change the time to 200
                 }
                 else if (score == 50)
                  {
                    timeout(300);//change the time to 200
                  }
                  else if (score == 60)
                   {
                     timeout(200);//change the time to 200
                   }
                   else if (score == 70)
                    {
                      timeout(100);//change the time to 200
                    }
                    else if (score == 120)
                     {
                       timeout(75);//change the time to 200
                     }
                     else if (score == 150)
                      {
                        timeout(50);//change the time to 200
                      }
                     // else if (score == 90)
                     //  {
                     //    timeout(25);//change the time to 200
                     //  }
                      // else if (score == 100)
                      //  {
                      //    timeout(25);//change the time to 200
                      //  }
                       // else if (score == 110)
                       //  {
                       //    timeout(5);//change the time to 200
                       //  }
                       //  else if (score == 120)
                       //   {
                       //     timeout(25);//change the time to 200
                       //   }
        }
          refresh();
          addstr(to_string(score).c_str());

    }
    void Snake::setup() // these are 2 different logics we used in order to plug the fuirt and the snake in the plane. We are going to be taking random
                  //numbers and generated in the board in order to have a better randomization of the postions of the objects
     {
      gameover = false;
      direction = STOP;
      x = width /2;
      y = height /2;
      srand(time(0));
      fruitX = rand()%(width);
      fruitY = rand()% (height);
      score =0;

     }
   void Snake::imput() // the imput function is going to be the one in charge to give orders to the computer, this means that if the user is trying to type either w,s,a,d. THe computer should detect these values and it should read them.
                  // the if statement is going to give the option to the computer to let the computer know that a key has been pressed, and the switch statement is going to have the task of
                  //taking the order directly and execute it. We used and enum function to do that.
    {
       int x = getch();
       addstr(to_string(x).c_str());
       refresh();
           switch (x)
            {
              case 'a':
               {
                 direction = LEFT;
                 break;
               }
               case 'd':
                {
                  direction = RIGHT;
                  break;
                }
                case 'w':
                 {
                   direction = FORWARD;
                   break;
                 }
                 case 's':
                 {
                    direction = BACK;
                    break;
                 }
                // case 'x':
                //   {
                //      gameover = true;
                //      addstr("You lost");
                //
                //      break;
                //    }
            }
    }
    void Snake::logic() //the logic is going to be where the whole game movement is going to work. I am thinking that this is going to work as a cartesian plane where the x is the width and y is the heigh, so every time the key 'a' is being pressed it is going to move to the left because it will be giving negative values to the computer
                    //which is going to make our snake move to the left side, and the same thing is going to happen with right, up,down as the values increase or decrease depending the spot of where the snake is located in the plane
     {
       // sleep(0.);
       switch (direction)
        {
           case LEFT:
               x--;   //snake moving left
               break;
           case RIGHT:
              x++;    //snake moving right
              break;
            case FORWARD:
              y--; // this is because is moving up
              break;
            case BACK:
              y++;  //snake moving down
              break;
            default:
             break;
        }
        if (x > width || x < 0 || y > height || y < 0) //the game has to end in some way, to do so we based this to the carteaisn plane again because the first line of the board is in the index 0x, so if it goes lower than that of if there is a collision this is going to end the infinite loop
         {
           gameover = true;

         }
     }
     void Snake::test()
     {

     }

//========================================================================================
