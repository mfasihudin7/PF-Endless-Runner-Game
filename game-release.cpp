#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include<cmath>     
using namespace std;

void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); 
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}
//Main Object
int x5=240,y5=100;
//Coins
int x11=240,y11=900;
string pcoin;
int coins=0;
//Variables For Shapes
int x9=240,y9=900;
int x1=240,y10=900;
int x2=425,y2=900;
int x3=610,y3=900;
int lives=3,score=0;
//Enemy Variable
int x6=x5;
float y6=0;
int u=2;
int x20=240,y20=900;
//random
int x; 
//counter
int c=1;
int enemyHit=0;
//Speed Variables
int speed1=2;
int speed2=4;
int speed3=3;
string pscore,plives;
void Display(){
//This Condition Checks If Any Printable Keys Stops Functions
if(u==1) {
    glClearColor(0, 0.0,0.0, 0 );
    glClear(GL_COLOR_BUFFER_BIT); 
    
    //This Condition Checks Lives if lives=0 so it does not run 
    if(lives>0)
    {
    score++;
    }
    //Roads
    if(score>0 && score<1000) {
	DrawSquare( 175 , 0 ,900,colors[131]);
        DrawSquare( 725 ,  0 ,600,colors[31]);
        DrawSquare( 725 ,  600 ,900,colors[63]);
        DrawSquare( -725 ,  600 ,900,colors[63]);
        DrawSquare( -425 ,  0 ,600,colors[31]);
        DrawCircle( 830 , 800 , 30 , colors[15]);
        DrawTriangle( 725, 600 , 813, 700 , 900 , 600, colors[2] ); 
        DrawTriangle( 0, 600 , 88, 700 , 175 , 600, colors[2] ); 
    }
    else if(score>2000 && score<3000) {
        DrawSquare( 175 , 0 ,900,colors[131]);
        DrawSquare( 725 ,  0 ,600,colors[31]);
        DrawSquare( 725 ,  600 ,900,colors[130]);
        DrawSquare( -725 ,  600 ,900,colors[130]);
        DrawSquare( -425 ,  0 ,600,colors[31]);
        DrawCircle( 830 , 800 , 30 , colors[15]);
        DrawCircle( 800 , 800 , 30 , colors[130]);
        DrawTriangle( 725, 600 , 813, 700 , 900 , 600, colors[2] ); 
        DrawTriangle( 0, 600 , 88, 700 , 175 , 600, colors[2] ); 
    }
    else
    {
        DrawSquare( 175 , 0 ,900,colors[131]);
        DrawSquare( 725 ,  0 ,600,colors[31]);
        DrawSquare( 725 ,  600 ,900,colors[17]);
        DrawSquare( -725 ,  600 ,900,colors[17]);
        DrawSquare( -425 ,  0 ,600,colors[31]);
        DrawCircle( 830 , 800 , 30 , colors[14]);
        DrawTriangle( 725, 600 , 813, 700 , 900 , 600, colors[2] ); 
        DrawTriangle( 0, 600 , 88, 700 , 175 , 600, colors[2] ); 
    }
	
	DrawLine( 175 , 0 ,  175 , 900 , 10 , colors[MISTY_ROSE] );
	DrawLine( 725 , 0 ,  725 , 900 , 10 , colors[MISTY_ROSE] );
	//Left lanes
	DrawLine( 357 , 20 ,  357 , 150 , 6 , colors[MISTY_ROSE] );
	DrawLine( 357 , 250 ,  357 , 380 , 6 , colors[MISTY_ROSE] );
	DrawLine( 357 , 500 ,  357 , 630 , 6 , colors[MISTY_ROSE] );
	DrawLine( 357 , 750 ,  357 , 870 , 6 , colors[MISTY_ROSE] );
	//Right Lane
	DrawLine( 534 , 20 ,  534 , 150 , 6 , colors[MISTY_ROSE] );
	DrawLine( 534 , 250 ,  534 , 380 , 6 , colors[MISTY_ROSE] );
	DrawLine( 534 , 500 ,  534 , 630 , 6 , colors[MISTY_ROSE] );
	DrawLine( 534 , 750 ,  534 , 870 , 6 , colors[MISTY_ROSE] );
	//objects
	//DrawSquare( x9 , y9 ,50,colors[11]);
	DrawRoundRect(x1,y10,50,100,colors[DARK_SEA_GREEN],70);
	if(y10<0)
	{
	y10=900;
	}
	y10-=speed1;
	DrawRoundRect(x2,y2,50,100,colors[DARK_SEA_GREEN],70);
	if(y2<0)
	{
	y2=900;
	}
	y2-=speed2;
	DrawRoundRect(x3,y3,50,100,colors[DARK_SEA_GREEN],70);
	if(y3<0)
	{
	y3=900;
	}
	y3-=speed3;

//End Game Message
if(lives<=0)
{
pscore="Your Score: "+to_string(score);
pcoin="Total Coins: "+to_string(coins);
DrawSquare( 0 ,  0 ,950,colors[130]);
DrawString( 350, 600, "GAME OVER", colors[1]);
DrawString( 350, 550, pscore, colors[MISTY_ROSE]);
DrawString( 350, 500, pcoin, colors[MISTY_ROSE]);
DrawString( 340, 450, "Press ESC To Exit", colors[MISTY_ROSE]);
}

//Speed Of Game After 1000 Score
if(score>=1000*c){
  speed1+=2;
  speed2+=2;
  speed3+=2;
  c++;
}
//Coins 
DrawCircle( x11 , y11 , 20 , colors[5]);
y11-=5;
if(x5 < x11 + 40 && x5 + 40 > x11 && y5 - 5 < y11 + 40 && y5 + 35 > y11)
{
     x=1+rand()%3;
     if(x==1) {
           x11=240;
     }
     if(x==2) {
           x11=425;
     }
     if(x==3) {
          x11=610;
     }
     y11=900;
     coins+=10;
}
if(y11 < 0)
{
     x=1+rand()%3;
     if(x==1) {
           x11=240;
     }
     if(x==2) {
           x11=425;
     }
     if(x==3) {
          x11=610;
     }
     y11=900;
}


//Main Object   
DrawCircle( x5+20 , y5+45 , 15 , colors[1]);
DrawLine( x5+10 , y5-30 ,  x5+10 , y5+10 , 15 , colors[1] );
DrawLine( x5+30 , y5-30 ,  x5+30 , y5+10 , 15 , colors[1] );
DrawLine( x5 , y5+25 ,  x5-10 , y5 , 15 , colors[1] );
DrawLine( x5+20 , y5 ,  x5+50 , y5+50 , 15 , colors[1] );
DrawSquare( x5 ,  y5-5 ,40,colors[10]); 
//Main Object End

  DrawSquare( 0 , 750 ,150,colors[MISTY_ROSE]);
  plives="Lives: "+to_string(lives);  //lives
  pscore="Distance: "+to_string(score); //Distance
  pcoin="Score: "+to_string(coins);  //Coins
      DrawString( 10, 870, pscore, colors[130]);
      DrawString( 10, 820, pcoin, colors[130]);
      DrawString( 10, 770, plives, colors[130]);

//enemy
int run=score;
if(run>2000)
{
    x6=x5;
    DrawSquare( x6 ,  y6 ,40,colors[66]);
    y6+=0.5;
    if(y6>900)
    {
        y6=0;
    }
    if(x5 < x6 + 40 && x5 + 40 > x6 && y5 - 5 < y6 + 40 && y5 + 35 > y6)
    {
        if(enemyHit==0)
        {
            lives--;
            enemyHit=1;
            y6=0;
        }
    }
    else
    {
        enemyHit=0;
    }
}

//Collision
if(x5 < x1 + 50 && x5 + 40 > x1 && y5 - 5 < y10 + 100 && y5 + 35 > y10)
{
    lives--;
    y10=900;
}
if(x5 < x2 + 50 && x5 + 40 > x2 && y5 - 5 < y2 + 100 && y5 + 35 > y2)
{
    lives--;
    y2=900;
}
if(x5 < x3 + 50 && x5 + 40 > x3 && y5 - 5 < y3 + 100 && y5 + 35 > y3)
{
    lives--;
    y3=900;
}

if(lives<=0)
{
pscore="Your Score: "+to_string(score);
pcoin="Total Coins: "+to_string(coins);
DrawSquare( 0 ,  0 ,950,colors[130]);
DrawString( 350, 600, "GAME OVER", colors[1]);
DrawString( 350, 550, pscore, colors[MISTY_ROSE]);
DrawString( 350, 500, pcoin, colors[MISTY_ROSE]);
DrawString( 340, 450, "Press ESC To Exit", colors[MISTY_ROSE]);
}

}
//For Pause The Game
else if(u==0)
{
DrawString( 400, 700, "MENU", colors[130]);
DrawString( 370, 600, "Resume (R/r)", colors[130]);
DrawString( 370, 550, "Restart (A/a)", colors[130]);
DrawString( 310, 500, "Press ESC To End Game", colors[130]);
}	
//Start Game
else
{
DrawSquare( 0 , 0 ,900,colors[131]);
DrawString( 310, 500, "Press Enter To Start Game", colors[130]);
}    

   glutSwapBuffers(); 
}

//Non Printable Keys
void NonPrintableKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
	if(x5>240) {	
	             x5-=185;   
	}
    }
    
    else if (key == GLUT_KEY_RIGHT) {
	if(x5<610) {
	             x5+=185;   
	}
    } 
    
    else if (key == GLUT_KEY_UP) {
       if(y5<850) {
                     y5+=20; 
       }
    }
    
    else if (key == GLUT_KEY_DOWN) {
	if(y5>100) { 
	 y5-=20;  
       }	
    }
     glutPostRedisplay();
}
//Non Printable Keys End

//Printable Keys 
void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC) {
        exit(0); 
    }
    if (key == 'R' || key=='r') {
        u=1; 
    }
    if(key=='P' || key=='p')
    {
     u=0;
    }
    else if (int(key) == 13)
    {  
    u=1;
    }
    if(key=='A' || key=='a' ) {
            lives=3;
            score=0;
            coins=0;
            u=1;
            x5=240;
            y5=100;
            x1=240;
            y10=900;
            x2=425;
            y2=900;
            x3=610;
            y3=900;
            x11=240;
            y11=900;
            x6=x5;
            y6=0;
            c=1;
            speed1=2;
            speed2=4;
            speed3=3;
     }
    glutPostRedisplay();
}
//Printable Keys End

//Timer Function
void Timer(int m) {


	glutPostRedisplay();
    glutTimerFunc(20.0 / FPS, Timer, 0);
}
//Timer Function Ends

//Main Function
int main(int argc, char*argv[]) {
string name;
    int width = 900, height = 900; 
    InitRandomizer(); 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(width, height); 
    glutCreateWindow("PF's Game"); 
    SetCanvasSize(width, height); 
    glutDisplayFunc(Display); 
    glutSpecialFunc(NonPrintableKeys); 
    glutKeyboardFunc(PrintableKeys); 
    glutTimerFunc(100.0 / FPS, Timer, 0);
    glutMainLoop();
    return 1;
}
#endif 

