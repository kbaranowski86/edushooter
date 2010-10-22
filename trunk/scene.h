#pragma once

// Project libraries
#include "point.h"
#include "weapon.h"
#include "light.h"
#include "score.h"
#include "infobar.h"

//System libraries
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

//3rd party libraries
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define _USE_MATH_DEFINES

//---------------------------------------------------------------------------

using namespace std;

// Container for all the logic of game
class Scene
{
      public:
        static Light L1;
        static BoxSet BS;
        static Room room;
        static Weapon Wpon;
        static float tX, tY;
        static point camPosition;
        static int windowX, windowY;
        static float tmpX, tmpY;
        static Score scr;
        static InfoBar iBar;
      
      // Initializing all neccessary objects
      static void InitializeScene()
      {
            
            scr.TimeStart();
            
            /*funkcje biblioteki glut s¹ odpowiedzialne za przenosnosc kodu miedzy OSami (cross-platform)*/
            // Inicjujemy OpenGL w trybie RGB i z podwójnym buforowaniem:
            glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
            
            // Ustawiamy rozmiar pocz¹tkowy okna na 100 na 100:
            glutInitWindowSize(1024, 768);
            
            // Enable textures
            glEnable(GL_TEXTURE_2D);
            
            // Tworzymy okno
            glutCreateWindow("Simple Shooter");
            glutFullScreen();
            
            glutSetCursor(GLUT_CURSOR_NONE);
            // Ustawiamy kolor, do którego bêdzie czyszczony ekran funkcj¹ glClear();
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            
            // Ustawiamy odpowiednie funkcje do obs³ugi zdarzeñ [cross-platform]:
            glutDisplayFunc(Display);
            glutReshapeFunc(Reshape);
            glutTimerFunc(1, Idle, 0);
            glutMouseFunc(MouseClick);
            glutPassiveMotionFunc(MouseMotion);
            glutKeyboardFunc(KeyPressed);
            
            // W³¹czamy nasz program:
            glutMainLoop();
      }  
   
   private:
       
      // Draw objects on scene       
      static void DrawObjects()
      {
             
             iBar. DrawBar();
                     
             room.Draw();  
                          
             BS.DrawBoxes();
             
             Wpon.DrawViewFinder();
             
             Wpon.DrawBullets();
             
      }
      
      //odrysowanie przy przesuniêciu b¹dŸ zmianie rozmiaru okna
      static void Reshape(int x, int y)
      { 
            //ustawiamy zmienne globalne
            windowX = x;
            windowY = y;
            
            glViewport(0, 0, windowX, windowY);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            
            //setup perspektywy
            gluPerspective(60.0f, (float)windowX / (float)windowY, 0.25, 200); 
            
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
      }
      
      // Refreshing display
      static void Idle(int)
      {
             glutTimerFunc(1, Idle , 0);
             glutPostRedisplay();
             
             Wpon.ChangeDirection( tX, tY );
             
             scr.TimeProgress();
             iBar.SetAll(scr.GetPoints(), scr.GetTimeOfGame(), Wpon.GetLastBulletsNum() );
             
      }
      
      //Mouse move event
      static void MouseMotion(int x,int y)//ruch myszy
      {
      
          float s;
          srand(time(0));
          s = rand() % 100;
      
          x = x-windowX / 2 ;
          y = y-windowY / 2 ;
          tX += ( ( x - tmpX ) / 100.0f ) * 1.5;
          tY -= ( ( y - tmpY ) / 100.0f ) * 1.5;
          tmpX = x;
          tmpY = y;
   
      }
      
      //Mouse click event
      static void MouseClick(int button, int state, int x, int y)
      {
             if (state == GLUT_DOWN) //przycisk wcisniety?
             {
                 if (button == GLUT_LEFT_BUTTON) //lewy? -obracamy
                 {
                    Wpon.Shot();
                 }
             }
          }
      
      //Keyboard key pressed event
      static void KeyPressed(unsigned char key, int, int)//nasza obs³uga klawiatury
      {
         if(key == 'q' || key == 'Q')  exit(0);
      }
      
      static void Display(void)
      {
            L1.put(); 
             
            glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glEnable (GL_DEPTH_TEST) ;
            glFrontFace(GL_CCW);
            GLfloat gray[] = { 1, 1, 1, 1.0f };
            
            GLfloat  specref[] =  { 1.0f, 0.0f, 0.0f, 1.0f };
            glEnable(GL_COLOR_MATERIAL);
            glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
            glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
            glMateriali(GL_FRONT, GL_SHININESS,128);
            
            DrawObjects();
            gluLookAt( camPosition.GetX(), camPosition.GetY(), camPosition.GetZ(), tX, tY, 0.0, 0.0, 0.1, 0.0 );
            
            //glFlush();
            glutSwapBuffers();     
      }
      
};

Score Scene::scr = Score();
InfoBar Scene::iBar(point(0, 0, 0));
float Scene::tX = 0;
float Scene::tY = 0;
point Scene::camPosition = point(0, 0, 12);
int Scene::windowX = 0;
int Scene::windowY = 0;
float Scene::tmpX = 0;
float Scene::tmpY = 0;
BoxSet Scene::BS(0.2, -1, 0.8);
Room Scene::room(point(-10 , 5, -8), point(10, -0.99, 20), 1, 1, 0, "cegla.bmp");
Weapon Scene::Wpon(point(camPosition.GetX(), camPosition.GetY(), camPosition.GetZ()), 100, &Scene::BS, &Scene::room);

//Light arrays of parameters
GLfloat ambient[] = {0.3, 0.3, 0.3, 1};
GLfloat specular[] = {0.4, 0.4, 0.4, 0.4};
GLfloat diffuse[] = {1, 1, 1, 1};

Light Scene::L1 = Light(point(1,3,5), ambient, specular, diffuse);
