void nextLevel(){
  if(player.x > LCDWIDTH ){
    lvl+=1;
    player.x = 0;
    bulletsInit();
    gameState = GAME_PLAY;
    return;
  }
  
  player.y = LCDHEIGHT/2;
  player.x+=3;
  levels();  
  gameHud();
  playerDraw();

}

void levels(){  
  switch (lvl) {      
      case 1:
        level_1();
        break;
      case 2:
        level_2();
        break;
      case 3:
        level_3();
        break;
       default:
        lvl = 1;
        break;       
    }
}


void level_1(){
  invertedDisplay();
}

void level_2(){  
  normalDisplay();
}

void level_3(){
  normalDisplay();
}
