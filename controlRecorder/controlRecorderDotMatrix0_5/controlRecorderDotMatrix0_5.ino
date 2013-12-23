const  int sampleRange = 800;

byte xPos[sampleRange];
byte yPos[sampleRange];
byte rangeCount = 0;

const byte record = 5;
//const byte led = 13;
byte recordFlag = 0;
byte recording = 0;
byte play = 0;

int x = 0, y = 0;

const int S0 = 2;
const int S1 = 4;
const int S2 = 7;
const int Ss0 = 8;
const int Ss1 = 12;
const int Ss2 = 13;
byte spin = 0;
unsigned long centre;



unsigned long milliSamp;

void setup(){
  Serial.begin(9600);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(Ss0, OUTPUT);
  pinMode(Ss1, OUTPUT);
  pinMode(Ss2, OUTPUT);
  //pinMode(led, OUTPUT);
  for(int i = 0; i < sampleRange; i++)
    xPos[i] = 127;

  for(int j = 0; j < sampleRange; j++)
    yPos[j] = 127;

  pinMode(record, INPUT);
  Serial.print("Setup Complete");
}

void loop(){
  x = analogRead(A0)/4;
  y = analogRead(A1)/4;


  if((digitalRead(record) == HIGH) && (recordFlag == 0)){
    recording = 1;
    recordFlag = 1;
    rangeCount = 0;
    delay(50);
    milliSamp = millis();
  }

  recordSequence();
  playSequence();
  if(play < 1){
    spinCentre(); 
  }
}



void recordSequence(){
  while(recording == 1){
    if((millis() - milliSamp) >= 10){
      xPos[rangeCount] = (analogRead(A0))/4;
      //Serial.println(xPos[rangeCount]);
      yPos[rangeCount] = (analogRead(A1))/4;
      rangeCount = rangeCount++;
      milliSamp = millis();
    }
    if(rangeCount > sampleRange){
      recordFlag = 0;
      recording = 0;
      play = 1;
      rangeCount = 0;
      while(digitalRead(record) == HIGH){
        //Jam
      }
    }
    if((digitalRead(record) == LOW) && (recordFlag == 1)){
      recordFlag = 0;
      recording = 0;
      play = 1;
      rangeCount = 0;
    }
  }
}

void playSequence(){
  while(play == 1){
    //digitalWrite(led, HIGH);
    if((millis() - milliSamp) >= 10){
      //Serial.print(xPos[rangeCount]);
      x = xPos[rangeCount];
      y = yPos[rangeCount];
      rangeCount = rangeCount++;
      if(rangeCount > sampleRange){
        rangeCount = 0;
      }
      milliSamp = millis();


    }

    Serial.print(x);
    Serial.print("  ");
    Serial.println(y);

    spinCentre();

    if((digitalRead(record) == HIGH) && (recordFlag == 0)){
      recordFlag = 1;
      delay(20);
    }
    if((digitalRead(record) == LOW) && (recordFlag == 1)){
      delay(20);
      recordFlag = 0;
      play = 0;
      recording = 0;
      rangeCount = 0;
      //digitalWrite(led, LOW);
    }


  }
}


void spinCentre(){
  if(((x > 124) && (x < 130)) && ((y > 124) && (y < 130))){
    if((millis() - centre) >= 70){
      spin = spin++;
      if(spin > 3){
        spin = 0;
      }
      centre = millis();
    }
    if(spin == 0){
      x = 112;
      y = 112;
    }
    if(spin == 1){
      x = 112;
      y = 140;
    }
    if(spin == 2){
      x = 140;
      y = 140;
    }
    if(spin == 3){
      x = 140;
      y = 112;
    }
  }

  /*
  Serial.print(x);
   Serial.print("  ");
   Serial.print(y);
   Serial.print("  ");
   */

  x = x/32;
  y = y/32;



  mux1();
  mux2();
  delay(1);
}







