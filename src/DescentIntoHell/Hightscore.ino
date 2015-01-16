///////////////////////////////////// LOAD HIGHSCORE
void loadHighscore(){
  for(byte thisScore = 0; thisScore < RANKMAX; thisScore++){
    for(byte i=0; i<NAMELENGTH; i++){
      name[thisScore][i] = EEPROM.read(i + thisScore*(NAMELENGTH+2));
    }
    highscore[thisScore] = EEPROM.read(NAMELENGTH + thisScore*(NAMELENGTH+2)) & 0x00FF; //LSB
    highscore[thisScore] += (EEPROM.read(NAMELENGTH+1 + thisScore*(NAMELENGTH+2)) << 8) & 0xFF00; //MSB
    highscore[thisScore] = (highscore[thisScore]==0xFFFF) ? 0 : highscore[thisScore];
  }
}  

///////////////////////////////////// SAVE HIGHSCORE
void saveHighscore(){
  gb.getDefaultName(name[RANKMAX-1]);
  gb.display.setFont(font5x7);
  gb.keyboard(name[RANKMAX-1], NAMELENGTH+1);
  highscore[RANKMAX-1] = player.score;
  for(byte i=RANKMAX-1; i>0; i--){ //bubble sorting FTW
    if(highscore[i-1] < highscore[i]){
      char tempName[NAMELENGTH];
      strcpy(tempName, name[i-1]);
      strcpy(name[i-1], name[i]);
      strcpy(name[i], tempName);
      unsigned int tempScore;
      tempScore = highscore[i-1];
      highscore[i-1] = highscore[i];
      highscore[i] = tempScore;
    }
    else{
      break;
    }
  }
  for(byte thisScore = 0; thisScore < RANKMAX; thisScore++){
    for(byte i=0; i<NAMELENGTH; i++){
      EEPROM.write(i + thisScore*(NAMELENGTH+2), name[thisScore][i]);
    }
    EEPROM.write(NAMELENGTH + thisScore*(NAMELENGTH+2), highscore[thisScore] & 0x00FF); //LSB
    EEPROM.write(NAMELENGTH+1 + thisScore*(NAMELENGTH+2), (highscore[thisScore] >> 8) & 0x00FF); //MSB
  }
  displayHighScores();
}
///////////////////////////////////// DISPLAY HIGHSCORES
void displayHighScores(){
  while(true){
    if(gb.update()){
      gb.display.cursorX = 10;
      gb.display.cursorY = 1;
      gb.display.println(F("HIGH SCORES"));
      gb.display.textWrap = false;
      gb.display.cursorX = 0;
      gb.display.cursorY = gb.display.fontHeight;
      for(byte thisScore=0; thisScore<RANKMAX; thisScore++){
        if(highscore[thisScore]==0)
          gb.display.print('-');
        else
          gb.display.print(name[thisScore]);
        gb.display.cursorX = LCDWIDTH-3*gb.display.fontWidth;
        gb.display.cursorY = gb.display.fontHeight+gb.display.fontHeight*thisScore;
        gb.display.println(highscore[thisScore]);
      }
      if(gb.buttons.pressed(BTN_A) || gb.buttons.pressed(BTN_B) || gb.buttons.pressed(BTN_C)){
        gb.sound.playOK();
        break;
      }
    }
  }
}
