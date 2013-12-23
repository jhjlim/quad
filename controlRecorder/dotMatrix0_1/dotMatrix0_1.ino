int x = 0, y = 0;

const int S0 = 2;
const int S1 = 4;
const int S2 = 7;
const int Ss0 = 8;
const int Ss1 = 12;
const int Ss2 = 13;
int spin = 0;
unsigned long centre;

void setup(){
  Serial.begin(9600);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(Ss0, OUTPUT);
  pinMode(Ss1, OUTPUT);
  pinMode(Ss2, OUTPUT);
}

void loop(){



  x = analogRead(A0);
  y = analogRead(A1);

  Serial.print(x);
  Serial.print("  ");
  Serial.println(y);

  if(((x > 505) && (x < 516)) && ((y > 505) && (y < 516))){
    if((millis() - centre) >= 70){
      spin = spin++;
      if(spin > 3){
        spin = 0;
      }
      centre = millis();
    }
    if(spin == 0){
      x = 450;
      y = 450;
    }
    if(spin == 1){
      x = 450;
      y = 560;
    }
    if(spin == 2){
      x = 560;
      y = 560;
    }
    if(spin == 3){
      x = 560;
      y = 450;
    }
  }

  x = x/127;
  y = y/127;

  mux1();
  mux2();
  //delayMicroseconds(1);

  /*
  x = x++;
   if(x > 7){
   x = 0;
   y = y++;
   }
   if(y > 7){
   y = 0;
   }
   */
}

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

