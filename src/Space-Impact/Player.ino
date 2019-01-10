#define BTN_ZERO 10
#define BTN_DURATION 3
byte btnCode = BTN_ZERO;

/* one key pressed at time ; 4 way fix*/
void playerMove(){
  if (btnCode == BTN_ZERO ){   
    if (m.buttons.pressed(BTN_LEFT) || m.buttons.repeat(BTN_LEFT, BTN_DURATION) ) {      
      btnCode = BTN_LEFT;      
    }   
    
    if (m.buttons.pressed(BTN_UP) || m.buttons.repeat(BTN_UP, BTN_DURATION) ) {    
      btnCode = BTN_UP;
    }
    if (m.buttons.pressed(BTN_RIGHT) || m.buttons.repeat(BTN_RIGHT, BTN_DURATION))  {      
      btnCode = BTN_RIGHT;      
    }  
    if (m.buttons.pressed(BTN_DOWN) || m.buttons.repeat(BTN_DOWN, BTN_DURATION) ) {      
      btnCode = BTN_DOWN;      
    }    
    
    if (m.buttons.pressed(BTN_A) ) {
        btnCode = BTN_A;  
        bulletsNew();                
    }        
  }else{    
    if (m.buttons.released(btnCode) ){ 
      btnCode = BTN_ZERO; 
    }   
  }

  switch (btnCode) {      
    case BTN_LEFT:
      playerMoveLeft();
      break;
    case BTN_UP: 
      playerMoveUp();
      break;
    case BTN_RIGHT:
      playerMoveRight();
      break;
    case BTN_DOWN:
      playerMoveDown();
      break;
     case BTN_A:
      btnCode = BTN_ZERO;
      break;
     default: 
      btnCode = BTN_ZERO; 
      break;     
  }
}


void playerMoveLeft(){
  if (player.x > 0){
    player.x-= 1;
  } 
}


void playerMoveUp(){
  if (player.y > HUD_HEIGHT){
    player.y-= 1;
  } 
}

void playerMoveRight(){
  if( (player.x + player.width) < LCDWIDTH){
    player.x+= 1;
  } 
}

void playerMoveDown(){
  if( (player.y + player.height ) < LCDHEIGHT){
    player.y+= 1;
  } 
}

void playerDraw(){
  playerMove(); 
  m.display.drawBitmap(player.x, player.y, hero_1);  
}
