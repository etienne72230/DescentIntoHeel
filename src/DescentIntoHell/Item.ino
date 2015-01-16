void initItem(int x,int y){
  alea=random(0,6);
  if (alea==1){
    for(byte i=0;i<MAX_MONSTER;i++){
      if(item[i].on==false){
        item[i].on=true;
        alea=random(0,6);
        if(alea==3 or alea==4 or alea==5){
           alea=0; 
        }else if(alea==6){
           alea=1;
        } 
        if(player.heal==5 and alea==2){
           alea=0; 
        }
        item[i].type=alea;
        item[i].x=x;
        item[i].y=y;
        break;
      }
    }
  }
}
void updateItem(){
  for(byte i=0;i<MAX_MONSTER;i++){
   if(gb.collideBitmapBitmap(item[i].x,item[i].y, Sprites_item[item[i].type], player.x, player.y,Sprites_player[player.orientation])and item[i].on==true){
       gb.sound.playOK();
       switch(item[i].type){
       case 0:
         player.rate+=1;
         item[i].on=false;
         break;
       case 1:
         player.damage+=1;
         item[i].on=false;
         break;
       case 2:
         player.heal+=1;
         item[i].on=false;
         break;
       default:
         break;
       } 
    }
  }
}
void drawItem(){
  for(byte i=0;i<MAX_MONSTER;i++){
    if(item[i].on==true){
      gb.display.drawBitmap(item[i].x, item[i].y,Sprites_item[item[i].type]);
    } 
  }
}

