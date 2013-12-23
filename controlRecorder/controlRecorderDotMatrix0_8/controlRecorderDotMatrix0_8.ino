const  int sampleRange = 800;

byte xPos[sampleRange];
byte yPos[sampleRange];
byte rangeCount = 0;

const byte record = 5;
//const byte led = 13;
byte recordFlag = 0, buttonFlag = 0;
byte recording = 0;
byte play = 0;
int loopBack;
byte listFlag = 0;

int x = 0, y = 0;

const int S0 = 2;
const int S1 = 4;
const int S2 = 7;
const int Ss0 = 8;
const int Ss1 = 12;
const int Ss2 = 13;
byte spin = 0;
byte skip = 0;
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
  pinMode(10, INPUT);
  //pinMode(led, OUTPUT);
  for(int i = 0; i < sampleRange; i++){
    xPos[i] = 127;
    delay(1);
    yPos[i] = 127;
  }

  pinMode(record, INPUT);
  Serial.print("Setup Complete");
}

void loop(){
  /*
  if((digitalRead(10) == HIGH) && (listFlag == 0)){
   delay(50);
   listFlag = 1;
   }
   if((digitalRead(10) == LOW) && (listFlag == 1)){
   listFlag = 0;
   }
   */
  x = analogRead(A0)/4;
  y = analogRead(A1)/4;

  if((digitalRead(record) == HIGH) && (recordFlag == 0)){
    recording = 1;
    recordFlag = 1;
    rangeCount = 0;
    milliSamp = millis();
    delay(50);
  }

  recordSequence();
  skip = 0;
  playSequence();
  if(play < 1){
    spinCentre(); 
  }
}



void recordSequence(){
  while(recording == 1){
    if((millis() - milliSamp) >= 8){
      x = analogRead(A0)/4;
      xPos[rangeCount] = x;
      delay(2);
      y = analogRead(A1)/4;
      yPos[rangeCount] = y;

      rangeCount = rangeCount++;
      if(rangeCount == 799){
        //recordFlag = 0;
        recording = 0;
        play = 1;
        rangeCount = 0;
        skip = 1;
        //break;
      }
      milliSamp = millis();
      spinCentre();
    }
    //delay(3);
    if(skip == 0){
      if((digitalRead(record) == LOW) && (recordFlag == 1)){
        loopBack = rangeCount;
        recordFlag = 0;
        recording = 0;
        play = 1;
        rangeCount = 0;
      }
    }
    
  }
}



void playSequence(){
  while(play == 1){
    if((millis() - milliSamp) >= 8){
      x = xPos[rangeCount];
      y = yPos[rangeCount];
      rangeCount = rangeCount++;
      if(rangeCount > sampleRange){
        rangeCount = 0;
      }
      if(rangeCount >= loopBack){
        rangeCount = 0;
      }
      milliSamp = millis();
      spinCentre();
    }

    /*
    Serial.print(x);
     Serial.print("  ");
     Serial.println(y);
     */


    //delay(3);
    if((digitalRead(10) == HIGH) && (buttonFlag == 0)){
      buttonFlag = 1;
      delay(20);
    }
    if((digitalRead(10) == LOW) && (buttonFlag == 1)){
      delay(20);
      buttonFlag = 0;
      recordFlag = 0;
      play = 0;
      recording = 0;
      rangeCount = 0;
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
  x = x/32;
  y = y/32;
  mux1();
  mux2();
}

/*
void list(){
 for(int j; j < 800; j++){
 Serial.print(xPos[j]);
 Serial.print("  ");
 Serial.println(yPos[j]);
 }
 }
 */






