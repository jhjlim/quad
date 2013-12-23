void mux1(){
  if(x == 7){
    digitalWrite(S0, LOW);
    digitalWrite(S1, LOW);
    digitalWrite(S2, LOW);
  }
  if(x == 6){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
    digitalWrite(S2, LOW);
  }
  if(x == 5){
    digitalWrite(S0, LOW);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
  }
  if(x == 4){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
  }
  if(x == 3){
    digitalWrite(S0, LOW);
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
  }
  if(x == 2){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
  }
  if(x == 1){
    digitalWrite(S0, LOW);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, HIGH);
  }
  if(x == 0){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, HIGH);
  }
}


void mux2(){
  if(y == 0){
    digitalWrite(Ss0, LOW);
    digitalWrite(Ss1, LOW);
    digitalWrite(Ss2, LOW);
  }
  if(y == 1){
    digitalWrite(Ss0, HIGH);
    digitalWrite(Ss1, LOW);
    digitalWrite(Ss2, LOW);
  }
  if(y == 2){
    digitalWrite(Ss0, LOW);
    digitalWrite(Ss1, HIGH);
    digitalWrite(Ss2, LOW);
  }
  if(y == 3){
    digitalWrite(Ss0, HIGH);
    digitalWrite(Ss1, HIGH);
    digitalWrite(Ss2, LOW);
  }
  if(y == 4){
    digitalWrite(Ss0, LOW);
    digitalWrite(Ss1, LOW);
    digitalWrite(Ss2, HIGH);
  }
  if(y == 5){
    digitalWrite(Ss0, HIGH);
    digitalWrite(Ss1, LOW);
    digitalWrite(Ss2, HIGH);
  }
  if(y == 6){
    digitalWrite(Ss0, LOW);
    digitalWrite(Ss1, HIGH);
    digitalWrite(Ss2, HIGH);
  }
  if(y == 7){
    digitalWrite(Ss0, HIGH);
    digitalWrite(Ss1, HIGH);
    digitalWrite(Ss2, HIGH);
  }
}

