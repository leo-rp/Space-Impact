#include <Mico.h>
#include "Bitmaps.h"

#define GAME_TITLE 0
#define GAME_PLAY 1
#define GAME_PAUSE 2
#define GAME_OVER 3 
#define GAME_NEXT_LEVEL 4 

Mico m;
byte gameState = 0;

#define HUD_HEIGHT 5

#define MAX_BULLETS 40
#define BULLET_SIZE 2
byte bullets[MAX_BULLETS][3];
byte lvl = 1;



typedef struct {    
  byte x = 0;
  byte y = LCDHEIGHT/2;
  byte width = 10;
  byte height = 7;
  byte lives = 3;
  unsigned int  score = 0;   
}
Player;

Player player;

void setup() {
  m.begin();  
  randomSeed(analogRead(A4));      
  m.battery.show = false;
  m.bootLogo = false;
  gameState = GAME_TITLE;
}


void gameTitle() {    
  m.titleScreen(F("Space-Impact"));  
  if (m.buttons.pressed(BTN_A)){
    gameInit();
    gameState = GAME_PLAY;
  }
}


void gamePlay() {    
  levels();  
  gameDraw();
  
  
  if (player.lives == 0){
    gameState = GAME_OVER;  
  }  
  if (m.buttons.pressed(BTN_C)){
    gameState = GAME_PAUSE;
    m.sound.playTick();
  } 
}

  
void gamePause() {
  m.display.cursorX = 20;
  m.display.cursorY = 20;
  m.display.print(F("Game Paused"));
  
  if (m.buttons.pressed(BTN_C)) {
      gameState = GAME_PLAY;
      m.sound.playTick();           
  }
}

void gameOver() {

}

void loop() {
  if (m.update()) {      
    game();
  }
}
