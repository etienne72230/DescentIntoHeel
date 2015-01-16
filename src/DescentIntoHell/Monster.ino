boolean place_ok;

void initMonster(){
  player.score+=2;
  alea=random(0,MAX_MONSTER);
  for(byte j=0;j<alea;j++){
    for(byte i=0;i<MAX_MONSTER;i++){
      if(monster[i].on==false){
          monster[i].on=true;
          monster[i].type=random(0,NUM_MONSTER);
          do{
            place_ok=true;
            monster[i].x=random(8,75);
            monster[i].y=random(8,35);
            monster[i].vx=1;
            monster[i].vy=1;
            for(byte k=0;k<MAX_MONSTER;k++){
              if(gb.collideBitmapBitmap(monster[i].x,monster[i].y, Sprites_monster[monster[i].type],monster[k].x,monster[k].y, Sprites_monster[monster[k].type]) and k!=i and monster[k].on==true){
                 place_ok=false; 
              }
            }
          }while(place_ok=false);
          monster[i].heal=monstertype[monster[i].type][0];
          monster[i].damage=monstertype[monster[i].type][1];
          monster[i].time_step=monstertype[monster[i].type][2];
          if(monster[i].type==1){
            do{
              monster[i].vx=random(-1,1);
              monster[i].vy=random(-1,1);
            }while(monster[i].vx==0 and monster[i].vy==0);
          }else if(monster[i].type==2){
            alea=random(0,2);
            if(alea==0){
              monster[i].vx=random(8,75);
              monster[i].vy=monster[i].y;
            }else{
              monster[i].vy=random(8,35);
              monster[i].vx=monster[i].x;
            }
          }
          wait = 20;
          break;
      } 
    }
  }
}

void updateMonster(){
    if(wait!=0){
       wait-=1; 
    }
    for(byte i=0;i<MAX_MONSTER;i++){
        if(monster[i].on==true){
           if(monster[i].time_step>0){
             monster[i].time_step-=1;
           }
           if(gb.collideBitmapBitmap(monster[i].x,monster[i].y, Sprites_monster[monster[i].type], player.x, player.y,Sprites_player[player.orientation])){
             
           }else{
             if( monster[i].time_step==0){
               switch(monster[i].type){
                case 0:
                    if(monster[i].x>player.x){
                      monster[i].x-=1;
                    }else{
                      monster[i].x+=1;
                    }
                    if(monster[i].y>player.y){
                      monster[i].y-=1;
                    }else{
                      monster[i].y+=1;
                    }
                break;
                case 1:
                    monster[i].x+=monster[i].vx;
                    monster[i].y+=monster[i].vy;
                    if(monster[i].y < 4){
                      monster[i].vy = -monster[i].vy;
                    }
                    if(monster[i].y > 36){
                      monster[i].vy = -monster[i].vy;
                    }
                    if(monster[i].x < 7){
                      monster[i].vx = -monster[i].vx;
                    }
                    if(monster[i].x > 72){
                      monster[i].vx = -monster[i].vx;
                    }
                    break;
                case 2:
                  if(monster[i].vx>monster[i].x){
                      monster[i].x+=1;
                     for(byte j=0;j<MAX_MONSTER;j++){ 
                       if(gb.collideBitmapBitmap(monster[i].x,monster[i].y, Sprites_monster[monster[i].type],monster[j].x,monster[j].y, Sprites_monster[monster[j].type]) and j!=i and monster[j].on==true){
                         monster[i].x-=1;
                       }
                     }
                  }
                  if(monster[i].vx<monster[i].x){
                      monster[i].x-=1;
                      for(byte j=0;j<MAX_MONSTER;j++){ 
                       if(gb.collideBitmapBitmap(monster[i].x,monster[i].y, Sprites_monster[monster[i].type],monster[j].x,monster[j].y, Sprites_monster[monster[j].type]) and j!=i and monster[j].on==true){
                         monster[i].x+=1;
                       }
                     }
                  }
                  if(monster[i].vy<monster[i].y){
                      monster[i].y-=1;
                      for(byte j=0;j<MAX_MONSTER;j++){ 
                       if(gb.collideBitmapBitmap(monster[i].x,monster[i].y, Sprites_monster[monster[i].type],monster[j].x,monster[j].y, Sprites_monster[monster[j].type]) and j!=i and monster[j].on==true){
                         monster[i].y+=1;
                       }
                     }
                  }
                  if(monster[i].vy>monster[i].y){
                      monster[i].y+=1;
                      for(byte j=0;j<MAX_MONSTER;j++){ 
                       if(gb.collideBitmapBitmap(monster[i].x,monster[i].y, Sprites_monster[monster[i].type],monster[j].x,monster[j].y, Sprites_monster[monster[j].type]) and j!=i and monster[j].on==true){
                         monster[i].y-=1;
                       }
                     }
                  } 
                  if(monster[i].vx==monster[i].x and monster[i].vy==monster[i].y){
                    alea=random(0,2);
                    if(alea==0){
                      monster[i].vx=random(8,72);
                      monster[i].vy=monster[i].y;
                    }else{
                      monster[i].vy=random(4,36);
                      monster[i].vx=monster[i].x;
                    }
                  }               
                   break; 
                case 3:
                  if(abs(monster[i].x-player.x) > abs(monster[i].y-player.y))
                    if(monster[i].x>player.x){
                       monster[i].x-=1; 
                    }else{
                       monster[i].x+=1; 
                    }
                  else{
                     if(monster[i].y>player.y){
                        monster[i].y-=1;
                     } else{
                       monster[i].y+=1;
                    }
                  }
                break;
                  
                case 4:
                  if(monster[i].x<7){
                   monster[i].x=7;
                   monster[i].vy=random(0,361);
                  }else if(monster[i].x>69){
                   monster[i].x=69;
                   monster[i].vy=random(0,361);
                  }else if(monster[i].y<4){
                    monster[i].y=4;
                    monster[i].vy=random(0,361);
                  }else if(monster[i].y>33){
                    monster[i].y=33;
                    monster[i].vy=random(0,361);
                  }
                  monster[i].vx=1;
                  monster[i].x+=monster[i].vx*cos(monster[i].vy);
                  monster[i].y+=monster[i].vx*sin(monster[i].vy);
                  int(monster[i].x);
                  int(monster[i].y);
                break;
                default:
                  break;
               }
              monster[i].time_step=monstertype[monster[i].type][2];
             }
           }
           if(monster[i].heal<=0){
               monster[i].on=false;
               player.score+=monstertype[monster[i].type][2];
               initItem(monster[i].x,monster[i].y);
           }
       }
   }
}

void drawMonster(){
  for(byte i=0;i<MAX_MONSTER;i++){
    if(monster[i].on==true){
      gb.display.drawBitmap(monster[i].x, monster[i].y,Sprites_monster[monster[i].type]);
    } 
  }
}
