int x, y;

const int S0 = 2;
const int S1 = 4;
const int S2 = 7;
const int Ss0 = 8;
const int Ss1 = 12;
const int Ss2 = 13;

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  x = analogRead(A0)/127;
  y = analogRead(A1)/127;
  
  Serial.print(x);
  Serial.print("  ");
  Serial.println(y);
  delay(20);
  
  
  
}

void mux1(){
  if(x == 1){
    digitalWrite(S0, LOW);
    digitalWrite(S1, LOW);
    digitalWrite(S2, LOW);
  }
  if(x == 2){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
    digitalWrite(S2, LOW);
  }
  if(x == 3){
    digitalWrite(S0, LOW);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
  }
  if(x == 4){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, LOW);
  }
  if(x == 5){
    digitalWrite(S0, LOW);
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
  }
  if(x == 6){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);
    digitalWrite(S2, HIGH);
  }
  if(x == 7){
    digitalWrite(S0, LOW);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, HIGH);
  }
  if(x == 8){
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
    digitalWrite(S2, HIGH);
  }
}


void mux2(){
  if(y == 1){
    digitalWrite(Ss0, LOW);
    digitalWrite(Ss1, LOW);
    digitalWrite(Ss2, LOW);
  }
  if(y == 2){
    digitalWrite(Ss0, HIGH);
    digitalWrite(Ss1, LOW);
    digitalWrite(Ss2, LOW);
  }
  if(y == 3){
    digitalWrite(Ss0, LOW);
    digitalWrite(Ss1, HIGH);
    digitalWrite(Ss2, LOW);
  }
  if(y == 4){
    digitalWrite(Ss0, HIGH);
    digitalWrite(Ss1, HIGH);
    digitalWrite(Ss2, LOW);
  }
  if(y == 5){
    digitalWrite(Ss0, LOW);
    digitalWrite(Ss1, LOW);
    digitalWrite(Ss2, HIGH);
  }
  if(y == 6){
    digitalWrite(Ss0, HIGH);
    digitalWrite(Ss1, LOW);
    digitalWrite(Ss2, HIGH);
  }
  if(y == 7){
    digitalWrite(Ss0, LOW);
    digitalWrite(Ss1, HIGH);
    digitalWrite(Ss2, HIGH);
  }
  if(y == 8){
    digitalWrite(Ss0, HIGH);
    digitalWrite(Ss1, HIGH);
    digitalWrite(Ss2, HIGH);
  }
}
