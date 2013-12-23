int sampleRange = 5000;

unsigned long xPos[5000];
unsigned long yPos[5000];
int rangeCount = 0;

const int record = 4;
int recordFlag = 0;
int recording = 0;
int play = 0;

unsigned long milliSamp;

void setup(){
  for(int i = 0; i < sampleRange; i++)
    xPos[i] = 511;
    
  for(int j = 0; j < sampleRange; j++)
    yPos[j] = 511;
    
    pinMode(record, INPUT);
}

void loop(){
  if((digitalRead(record) == HIGH) && (recordFlag == 0)){
    recording = 1;
    recordFlag = 1;
    rangeCount = 0;
    delay(10);
  }
  recordSequence();
  
  //if((digitalRead(record) == LOW) && (recordFlag == 1)){
  //  recordFlag = 0;
  //}
}
    
    

void recordSequence(){
  while(recording == 1){
    if((millis() - milliSamp) >= 1){
      xPos[rangeCount] = analogRead(A0);
      Serial.println(xPos[rangeCount]);
      yPos[rangeCount] = analogRead(A1);
      rangeCount = rangeCount++;
      milliSamp = millis();
    }
    if(rangeCount > sampleRange){
      recordFlag = 0;
      recording = 0;
      play = 1;
    }
    if((digitalRead(record) == LOW) && (recordFlag == 1)){
      recordFlag = 0;
      recording = 0;
      play = 1;
    }
  }
}
      
  
