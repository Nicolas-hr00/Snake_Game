#include <iostream>
//#include <conio.h>

#include <ncurses.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//it contains all the libraries
// #include <conio.h>
  using namespace std;


class Snake
{
public:
  Snake();
  void draw();
  void setup();
  void imput();
  void logic();

  void setfruit();
  int Getfruit();
  void setsnake();
  int getsnake();
  void test();

  bool gameover;
  const int width = 30; //width of the board
 const int height = 15; //height of the board
 int x, y, fruitX, fruitY, score;   //the variables to create the snake, fuit and the score
 string snakes;  // test run
 enum Direction {STOP =0,LEFT = 1, RIGHT = 2, FORWARD = 3,BACK=4};//this is how we control the snake 
 Direction direction;

};
