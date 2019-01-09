#include <Mico.h>
#include "Bitmaps.h"

Mico m;
byte gameState = 0;

typedef struct {    
  byte x = 0;
  byte y = LCDHEIGHT/2;
  byte width = 10;
  byte height = 7;    
}
Player;

Player player;

void setup() {
  m.begin();  
  randomSeed(analogRead(A4));      
  m.battery.show = false;  
  gameTitle();
}


void gameTitle() {  
  m.titleScreen(F("Space-Impact"));  
  
  if (m.buttons.pressed(BTN_A)){
    gameState = 1;
  }
}


void gamePlay() {  
  playerMove();

  m.display.drawBitmap(player.x, player.y, hero_1);
  if (m.buttons.pressed(BTN_C)){
    gameState = 2;
    m.sound.playTick();
  }

  
}

void gamePause() {
  m.display.cursorX = 20;
  m.display.cursorY = 20;
  m.display.print(F("Game Paused"));
  
  if (m.buttons.pressed(BTN_C)) {
      gameState = 1;
      m.sound.playTick();           
  }
}

void gameOver() {
  

  if (m.buttons.pressed(BTN_B) || m.buttons.held(BTN_B, 2) || m.buttons.pressed(BTN_A) || m.buttons.held(BTN_A, 2)) {
    gameState = 0;
  }


}

void loop() {
  if (m.update()) {           
    switch (gameState) {      
      case 0: 
        gameTitle();
        break;
      case 1:
        gamePlay();
        break;
      case 2:
        gamePause();
        break;
      case 3:
        gameOver();
        break;      
    }
  }

}
