// C++ code
//

bool buttonMinusLastState = false;
bool buttonPlusLastState = false;
int ledCount = 0;

void setup()
{  
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop()
{
  bool buttonMinusState = digitalRead(2);
  bool buttonPlusState = digitalRead(3);
  
  if(buttonMinusState != buttonMinusLastState)
  {
    if(buttonMinusState)
    {
      if(ledCount > 0)
      {
        ledCount--;
      }
      buttonMinusLastState = true;
    } else {
      buttonMinusLastState = false;
    } 
  }

  if(buttonPlusState != buttonPlusLastState)
  {
    if(buttonPlusState)
    {
      if(ledCount < 3)
      {
        ledCount++;
      }
      buttonPlusLastState = true;
    } else {
      buttonPlusLastState = false;
    }
    
  }
  
  if(ledCount > 0){
    digitalWrite(A0, HIGH);
  } else {
    digitalWrite(A0, LOW);
  }
  
  if(ledCount > 1){
    digitalWrite(A1, HIGH);
  } else {
    digitalWrite(A1, LOW);
  }

  if(ledCount > 2){
    digitalWrite(A2, HIGH);
  } else {
    digitalWrite(A2, LOW);
  }
  
}