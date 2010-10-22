#include <time.h>
#include <stdlib.h>

//Projet libraries
#include "box.h"

class Bullet;

class BoxSet{ //zestaw klocków
      public:
      
      Box boxes[24];
      Box* shuffledBox;
      bool cycleEnd;
      float moveSpeedMultiplier;
      
      // Locating boxes on the scene
      BoxSet(float spacing, float verticalPosition, float depth)
      {
               moveSpeedMultiplier = 1;
               cycleEnd = 0;
               int i;
               for(i = 0; i < 24; i++){
                        if(i < 8){
                                boxes[i] = Box(point(4.7 - i - spacing*i-1, verticalPosition, 0), point(4.7-i-spacing*i, -1.3 + verticalPosition, 0 + depth), 1, 0, 0);
                        }
                        else if(i >= 8 && i < 16){
                                boxes[i] = Box(point(4.7 - (i-8)-spacing*(i-8)-1, verticalPosition, 3), point(4.7-(i-8)-spacing*(i-8), -1.3 + verticalPosition, 3 + depth), 0, 1, 0);
                        }
                        else if(i >= 16 && i < 24){
                                boxes[i] = Box(point(4.7 - (i - 16) - spacing * (i - 16) - 1, verticalPosition, 6), point(4.7 - (i - 16)-spacing*(i - 16), -1.3 + verticalPosition, 6 + depth), 0, 1, 0);
                        }
               }
               
               Shuffle();
      }
      
      void DrawBoxes(){           
           int i;
           for(i = 0; i < 24; i++)
           {
               boxes[i].Draw();
           }
           MoveShuffled(0.01 * moveSpeedMultiplier, 0.3 * moveSpeedMultiplier);
      }
      
      void Shuffle(){
           int s;
           s = rand() % 23;
           
           this->shuffledBox = &boxes[s];
           
           // Unhit shuffled box if hit
           if(shuffledBox->CheckIfHit())
           {
                shuffledBox->UnHit();
           }
           
      }
      
      // Move shuffled box up and down
      void MoveShuffled(float moveDownSpeed, float moveUpSpeed){
           
           if(cycleEnd == false){
                       
               if(shuffledBox->P1.GetY() > 0)
               {
                   shuffledBox->moveDirection = - moveDownSpeed;
               }
               else if(shuffledBox->P1.GetY() < -1.0)
               {
                   cycleEnd = true;
                   
                   shuffledBox->moveDirection = moveUpSpeed;
                   
                   shuffledBox->P1.SetY(-1.0);
                                     
                   Shuffle();
                   
                   return;
               }
               shuffledBox->MoveAlongY(shuffledBox->moveDirection);
               
           }
           else
           {
                cycleEnd = false;
           }
           
           
      }
      
      void CheckBoxesForHit(Bullet* hittingBullet)
      {
         int i;
         for(i = 0; i < 24; i++)
         {
             if(boxes[i].CheckIfHit(hittingBullet))
             {
                  moveSpeedMultiplier += 0.01;
             }
         }
      }
};
