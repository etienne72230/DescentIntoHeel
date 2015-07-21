void initDonjon(){
    while(finish==false){
      alea=random(0,24);
      cote=random(0,2);
      if(Donjon[1][alea]==4){
         cote=1;
      }
      if(Donjon[2][alea]==4){
         cote=0; 
      }
      if(Donjon[2][alea]==4 and Donjon[1][alea]==4){
         cote=2; 
      }
      if(cote==0 and Donjon[0][alea]!= Donjon[0][alea+1]){
          for(byte i=0;i<25;i++){
             if(Donjon[0][alea+1]==Donjon[0][i] and i!=(alea+1)){
                Donjon[0][i]=Donjon[0][alea];
             } 
          }
          Donjon[0][alea+1]=Donjon[0][alea];
          Donjon[4][alea]=1;
          Donjon[6][alea+1]=1;
      }
      if(cote==1 and Donjon[0][alea]!= Donjon[0][alea+5]){
          for(byte i=0;i<25;i++){
             if(Donjon[0][alea+5]==Donjon[0][i] and i!=(alea+5)){
                Donjon[0][i]=Donjon[0][alea];
             } 
          }
          Donjon[0][alea+5]=Donjon[0][alea];
          Donjon[5][alea]=1;
          Donjon[3][alea+5]=1;
      }
      ok=0;
      for(byte i=0;i<25;i++){
           if(Donjon[0][0]==Donjon[0][i]){
              ok+=1; 
           }
      }
      if(ok==25){
         finish=true;
      }
    }
    while(fin==false){
        ok=0;
        alea=random(0,25);
        for(byte i=3;i<7;i++){
            if(Donjon[i][alea]==1 and alea!=12 ){
              ok+=1;
            }
        }
        if(ok==1){
            while(finish==true){
                rando=random(3,7);
                if(Donjon[rando][alea]==0){
                    Donjon[rando][alea]=2;
                    fin=true;
                    finish=false;
                }
            }
        }
    }
 }
