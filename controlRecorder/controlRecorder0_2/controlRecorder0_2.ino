int sampleRange = 200;

unsigned long xPos[200];
unsigned long yPos[200];
int rangeCount = 0;

const int record = 4;
const int led = 13;
int recordFlag = 0;
int recording = 0;
int play = 0;

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
  
  //if((digitalRead(record) == LOW) && (recordFlag == 1)){
  //  recordFlag = 0;
  //}
}
    
    

void recordSequence(){
  while(recording == 1){
    if((millis() - milliSamp) >= 10){
      xPos[rangeCount] = analogRead(A0);
      Serial.println(xPos[rangeCount]);
      yPos[rangeCount] = analogRead(A1);
      rangeCount = rangeCount++;
      milliSamp = millis();
    }
    if(rangeCount > 198){
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
      Serial.print(xPos[rangeCount]);
      rangeCount = rangeCount++;
      if(rangeCount > 198){
        rangeCount = 0;
      }
      milliSamp = millis();
      
      
    }
    
    
  }
}
      
  
