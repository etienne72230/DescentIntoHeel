void initShoot(){
  gb.sound.playTick();
  for(byte i=0;i<MAX_SHOOT;i++){
     if(shoot[i].on==false){
        shoot[i].on=true;
        shoot[i].vx=3;
        shoot[i].vy=3;
        shoot[i].orientation=player.orientation;
        if(shoot[i].orientation==0){
          shoot[i].x=player.x+1;
          shoot[i].y=player.y-2;
          shoot[i].orientation==0;
        }else if(shoot[i].orientation==1){
          shoot[i].x=player.x+5;
          shoot[i].y=player.y+2;
          shoot[i].orientation==1;   
        }else if(shoot[i].orientation==2){
          shoot[i].x=player.x+1;
          shoot[i].y=player.y+6;  
          shoot[i].orientation==2;        
        }else if(shoot[i].orientation==3){
          shoot[i].x=player.x-2;
          shoot[i].y=player.y+2;
          shoot[i].orientation==3; 
        }         
        break;
     } 
  }
}

void updateShoot(){
  
  for(byte i=0;i<MAX_SHOOT;i++){
     if(shoot[i].on==true){
       if(shoot[i].orientation==0){
          shoot[i].y-=shoot[i].vy;
        }else if(shoot[i].orientation==1){
          shoot[i].x+=shoot[i].vx;  
        }else if(shoot[i].orientation==2){
          shoot[i].y+=shoot[i].vy;
        }else if(shoot[i].orientation==3){
          shoot[i].x-=shoot[i].vx; 
        }
        if(shoot[i].x>78 or shoot[i].x<6 or shoot[i].y>41 or shoot[i].y<2 ){
            shoot[i].on=false;
        }
       for(byte j=0;j<MAX_MONSTER;j++){
          if(monster[j].on==true){
            if(gb.collideBitmapBitmap(monster[j].x,monster[j].y, Sprites_monster[monster[j].type], shoot[i].x, shoot[i].y,bullet)){
                gb.display.setColor(INVERT);
                gb.display.drawBitmap(monster[j].x, monster[j].y,Sprites_monster[monster[j].type]);
                gb.display.setColor(BLACK);
                monster[j].heal-=player.damage;
                shoot[i].on=false;
            }
          }
       }
       
     }
  }
}

void drawShoot(){
  for(byte i=0;i<MAX_SHOOT;i++){
    if(shoot[i].on==true){
      gb.display.drawBitmap(shoot[i].x, shoot[i].y,bullet);
    } 
  }
}
                   
                    
                    
