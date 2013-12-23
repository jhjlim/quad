const  int sampleRange = 800;

byte xPos[sampleRange];
byte yPos[sampleRange];
byte rangeCount = 0;

const byte record = 4;
const byte led = 13;
byte recordFlag = 0;
byte recording = 0;
byte play = 0;

unsigned long milliSamp;

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  for(int i = 0; i < sampleRange; i++)
    xPos[i] = 511;
    
  for(int j = 0; j < sampleRange; j++)
    yPos[j] = 511;
    
    pinMode(record, INPUT);
    Serial.print("Setup Complete");
}

void loop(){
  if((digitalRead(record) == HIGH) && (recordFlag == 0)){
    recording = 1;
    recordFlag = 1;
    rangeCount = 0;
    delay(50);
    digitalWrite(led, LOW);
    milliSamp = millis();
  }
  recordSequence();
  playSequence();
  //if((digitalRead(record) == LOW) && (recordFlag == 1)){
  //  recordFlag = 0;
  //}
}
    
    

void recordSequence(){
  while(recording == 1){
    if((millis() - milliSamp) >= 10){
      xPos[rangeCount] = (analogRead(A0))/8;
      Serial.println(xPos[rangeCount]);
      yPos[rangeCount] = (analogRead(A1))/8;
      rangeCount = rangeCount++;
      milliSamp = millis();
    }
    if(rangeCount > sampleRange){
      recordFlag = 0;
      recording = 0;
      play = 1;
      rangeCount = 0;
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
    digitalWrite(led, HIGH);
    if((millis() - milliSamp) >= 10){
      Serial.println(xPos[rangeCount]);
      rangeCount = rangeCount++;
      if(rangeCount > sampleRange){
        rangeCount = 0;
      }
      milliSamp = millis();
      
      
    }
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
      digitalWrite(led, LOW);
    }
    
    
  }
}
      
  
