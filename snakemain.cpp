#include <iostream>
#include "snake.h"

//snake maing

using namespace std;

 int main ()
 {

   Snake snake;
   snake.setup();


   initscr();
   cbreak();
   // timeout(200);//change the time to 200
    while(!snake.gameover)  //this is going to keep looping until the game is over(there was a collision of the snake has gotten below 0 in the x and y axis )
    {
      snake.draw();
      snake.imput();
      snake.logic();
    }

     endwin();



   return 0;
 }
