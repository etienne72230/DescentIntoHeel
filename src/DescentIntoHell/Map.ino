
void Map(){
    while(true){
      ok=0;
      for(byte i=0;i<25;i++){
        if(Donjon[7][i]==1){
          gb.display.setColor(BLACK);
          gb.display.fillRect(Donjon[1][i]*9+1, Donjon[2][i]*9, 9, 9);
          gb.display.setColor(WHITE);
          if(Donjon[3][i]==1){
            gb.display.fillRect(Donjon[1][i]*9+4, Donjon[2][i]*9, 3, 3);
          }else if(Donjon[3][i]==2){
            ok=1;
          }
          if(Donjon[4][i]==1){
            gb.display.fillRect(Donjon[1][i]*9+7, Donjon[2][i]*9+3, 3, 3);
          }else if(Donjon[4][i]==2){
            ok=1;
          }
          if(Donjon[5][i]==1){
            gb.display.fillRect(Donjon[1][i]*9+4, Donjon[2][i]*9+6, 3, 3);
          }else if(Donjon[5][i]==2){
            ok=1;
          }
          if(Donjon[6][i]==1){
            gb.display.fillRect(Donjon[1][i]*9+1, Donjon[2][i]*9+3, 3, 3);
          }else if(Donjon[6][i]==2){
            ok=1;
          }
          gb.display.fillRect(Donjon[1][i]*9+2, Donjon[2][i]*9+1, 7, 7);
          gb.display.setColor(BLACK);
          if(ok==1){
            gb.display.drawBitmap(Donjon[1][i]*9+2, Donjon[2][i]*9+1,map_exit);
            ok=0;
          }
          if(i==player.donjonroom){ 
            gb.display.setColor(WHITE);
            gb.display.fillRect(Donjon[1][i]*9+2, Donjon[2][i]*9+1, 7, 7);
            gb.display.setColor(BLACK);
            gb.display.drawBitmap(Donjon[1][i]*9+2, Donjon[2][i]*9+1,map_perso);
          }
        }
      }
      gb.display.cursorY = 0;
      gb.display.cursorX = 50;
      gb.display.fontSize = 1;
      gb.display.print("Level");
      gb.display.cursorX = 75;
      gb.display.print(donjonlevel);
      gb.display.cursorY = 6;
      gb.display.cursorX = 47;
      gb.display.print("S");
      gb.display.cursorX = 55;
      gb.display.print(player.score);
      gb.display.drawBitmap(47,14,rate);
      gb.display.cursorY = 12;
      gb.display.cursorX = 55;
      gb.display.print(player.rate);
      gb.display.drawBitmap(47,19,damage);
      gb.display.cursorY = 18;
      gb.display.cursorX = 55;
      gb.display.print(player.damage);
      gb.display.cursorY = 26;
      gb.display.cursorX = 47;
      gb.display.print("\25 return");
      gb.display.cursorY = 33;
      gb.display.cursorX = 47;
      gb.display.print("\26 Score");
      gb.display.cursorY = 40;
      gb.display.cursorX = 47;
      gb.display.print("\27 Quit");
      
      
      
      
     if(gb.update()){
        if(gb.buttons.pressed(BTN_A)){ 
          gb.display.setColor(BLACK);
          break;
        }
        if(gb.buttons.pressed(BTN_B)){
          gb.display.setColor(BLACK);
          displayHighScores();
        }
        if(gb.buttons.pressed(BTN_C)){
          initGame();
        }
     }
  }
}
