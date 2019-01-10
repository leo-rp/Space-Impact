void gameInit(){
  bulletsInit();
}

void gameDraw(){
  gameHud();
  playerMove(); 
  playerDraw();
  bulletsDraw();  
}

void gameHud(){
  /*lives*/
  for(byte i = 0; i < player.lives ; i++){       
    m.display.drawBitmap( (6 * i), 0, heart);
  }  
  
  /*score*/
  m.display.cursorY = 0;
  m.display.cursorX = 60;
  if (player.score < 10000){
    m.display.print('0');    
  } 
  if (player.score < 1000){
    m.display.print('0');    
  } 
  if (player.score <100){
    m.display.print('0');    
  }  
  if (player.score < 10){ 
    m.display.print('0');    
  }  
  m.display.print(player.score);
}

void invertedDisplay(){
  m.display.fillScreen(BLACK);    
  m.display.setColor(WHITE);   
}

void normalDisplay(){
  m.display.setColor(BLACK);    
}

void game(){
  switch (gameState) {      
      case GAME_TITLE: 
        gameTitle();
        break;
      case GAME_PLAY:
        gamePlay();
        break;
      case GAME_PAUSE:
        gamePause();
        break;
      case GAME_OVER:
        gameOver();
        break;      
      case GAME_NEXT_LEVEL:
        nextLevel();
        break;      
    }
}
