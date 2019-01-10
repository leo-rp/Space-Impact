void bulletsInit(){
  for( int i = 0; i < MAX_BULLETS; i++){
     bullets[i][0] = 0;
     bullets[i][1] = 0;
     bullets[i][2] = 0;
  }
}

void bulletsNew(){   
  for( int i = 0; i < MAX_BULLETS; i++){
    if( bullets[i][2] == 0){    
     bullets[i][0] = player.x + 10;
     bullets[i][1] = player.y + 3;
     bullets[i][2] = 1;
     player.score+=1;     
     break;
    }
  }
}

void bulletsDraw(){  
  for( int i = 0; i < MAX_BULLETS ; i++){
    if( bullets[i][0] > LCDWIDTH ){
      bullets[i][2] = 0;    
    }
    
    if(bullets[i][2] == 1){    
     /*if( bullets[i -1 ][0] + BULLET_SIZE >  bullets[i][0] + BULLET_SIZE ){      */
      m.display.drawLine(bullets[i][0], bullets[i][1], ( bullets[i][0] + 1), bullets[i][1]);   
      m.sound.playTick();           
      bullets[i][0]+=1;        
     //}
    }
  }
}
