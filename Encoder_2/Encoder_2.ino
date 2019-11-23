#include<Encoder.h> 
// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability

Encoder myEnc1(19,18);
Encoder myEnc2(20,21);
//   avoid using pins with LEDs attached
void go_forward(long);
void go_backward(long);
void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
  digitalWrite(4,LOW);          //Need to declare them 
  digitalWrite(5,HIGH);         //in function
  digitalWrite(9,LOW);          //go_forward and g0_backward
  digitalWrite(17,HIGH);        //right now declared for bwd movement
}
long oldPosition1  = -999;
long oldPosition2  = -999;
/*
 * Total rising and falling pulses as produced by both the encoders in one full rotation=820 
 * distance moved in 1 full rotation=3*Pi cm
 * block length=16 cm
 * Therefore,pulses generated when one block is traversed~~1392
 */

void loop() 
{
  //go_forward(1392);
  go_backward(1392);
}
void go_forward(long distance) 
{
  //long distance=1392;
  long newPosition1=0;
  long newPosition2=0;
  if(newPosition1<distance*0.5)
  {
    newPosition1 = myEnc1.read();
    if (newPosition1 != oldPosition1) 
    {
      oldPosition1 = newPosition1;
      Serial.println(newPosition1);
    }
  }
  if(newPosition2<distance*0.5)
  {
    newPosition2 = myEnc2.read();
    if (newPosition2 != oldPosition2) 
    {
      oldPosition2 = newPosition2;
      Serial.println(newPosition2);
    }
  }
  if(newPosition1>(distance*0.5)&&newPosition1<distance*0.7)
  {
    analogWrite(4,100); 
    newPosition1 = myEnc1.read();
    if (newPosition1 != oldPosition1) 
    {
      oldPosition1 = newPosition1;
      Serial.println(newPosition1);
    }
  }
  if(newPosition2>(distance*0.5)&&newPosition2<distance*0.7)
  {
    analogWrite(9,100); 
    newPosition2 = myEnc2.read();
    if (newPosition2 != oldPosition2) 
    {
      oldPosition2 = newPosition2;
      Serial.println(newPosition2);
    }
  }
  if(newPosition1>(distance*0.7)&&newPosition1<distance*0.85)
  {
    analogWrite(4,70); 
    newPosition1 = myEnc1.read();
    if (newPosition1 != oldPosition1) 
    {
      oldPosition1 = newPosition1;
      Serial.println(newPosition1);
    }
  }
  if(newPosition2>(distance*0.7)&&newPosition2<distance*0.85)
  {
    analogWrite(9,70); 
    newPosition2 = myEnc2.read();
    if (newPosition2 != oldPosition2) 
    {
      oldPosition2 = newPosition2;
      Serial.println(newPosition2);
    }
  }
  if(newPosition1>distance*0.85)    //Need to tune this distance part
  {
    analogWrite(4,0);
  }
  if(newPosition2>distance*0.85)
  {
    analogWrite(9,0);
  }
}


void go_backward(long distance) 
{
  //long distance=1392;
  long newPosition1=0;
  long newPosition2=0;
  if(newPosition1<distance*0.5)
  {
    newPosition1 = abs(myEnc1.read());
    if (newPosition1 != oldPosition1) 
    {
      oldPosition1 = newPosition1;
      Serial.println(newPosition1);
    }
  }
  if(newPosition2<distance*0.5)
  {
    newPosition2 = abs(myEnc2.read());
    if (newPosition2 != oldPosition2) 
    {
      oldPosition2 = newPosition2;
      Serial.println(newPosition2);
    }
  }
  if(newPosition1>(distance*0.5)&&newPosition1<distance*0.7)
  {
    analogWrite(5,100); 
    newPosition1 = myEnc1.read();
    if (newPosition1 != oldPosition1) 
    {
      oldPosition1 = newPosition1;
      Serial.println(newPosition1);
    }
  }
  if(newPosition2>(distance*0.5)&&newPosition2<distance*0.7)
  {
    analogWrite(17,100); 
    newPosition2 = abs(myEnc2.read());
    if (newPosition2 != oldPosition2) 
    {
      oldPosition2 = newPosition2;
      Serial.println(newPosition2);
    }
  }
  if(newPosition1>(distance*0.7)&&newPosition1<distance*0.85)
  {
    analogWrite(5,70); 
    newPosition1 = abs(myEnc1.read());
    if (newPosition1 != oldPosition1) 
    {
      oldPosition1 = newPosition1;
      Serial.println(newPosition1);
    }
  }
  if(newPosition2>(distance*0.7)&&newPosition2<distance*0.85)
  {
    analogWrite(17,70); 
    newPosition2 = abs(myEnc2.read());
    if (newPosition2 != oldPosition2) 
    {
      oldPosition2 = newPosition2;
      Serial.println(newPosition2);
    }
  }
  if(newPosition1>distance*0.85)
  {
    analogWrite(5,0);
  }
  if(newPosition2>distance*0.85)      //NOT working properly, needs to be tuned
  {
    analogWrite(17,0);
  }
}
