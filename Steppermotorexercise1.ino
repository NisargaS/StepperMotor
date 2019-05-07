/* The below defined variables indicates the step sequence of stepper motor */
#define Full_Step         1
#define Half_Step         2
#define onebyfourt_Step   3
#define onebyeight_Step   4
#define onebysixteen_Step 5

const int en =  5;   /*Enable pin*/ 
const int dir = 3;   /*Direction pin*/
const int pul = 4;   /*Pulse pin*/
int NumberofSteps = 200;  /*variable defined to store the steps per revolution of motor */
int StepMode = 2;       /*variable defined to store the step mode/step sequence of motor i.e 1- full Step , 2- half step , 3- 1/4 step , 4- 1/8 step, 5- 1/16 step */
int StepCount;      /*variable defined to store the stepcount for one revolution based on the step sequence of motor */
int Speed = 5000;          /*variable defined to store the speed of motor */
unsigned int LoopCounter; /*variable defined for for loop*/
boolean pluse = HIGH; 
boolean Direction = LOW; 
int directionchangeflag=0;
     

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

/*setting the pin modes of enable, pulse and direction pin*/
pinMode(en, OUTPUT);  
pinMode(dir, OUTPUT);
pinMode(pul, OUTPUT);

/*writing zero to those pins*/
digitalWrite(en,LOW);
digitalWrite(dir,LOW);
digitalWrite(pul,LOW);

/* Serial.println("Enter the Steps per Revolution of the Stepper Motor:   ");
  while(Serial.available() > 0){
    NumberofSteps = Serial.read();
  }
Serial.println("Enter the Step Mode in which the Stepper Motor should work: "); /* 1- full Step , 2- half step , 3- 1/4 step , 4- 1/8 step, 5- 1/16 step*/
   /*while(Serial.available() > 0){
    StepMode = Serial.read();
 }
Serial.println("Enter the speed at which Stepper Motor should work range 1-10,00,000: "); /* From the calculation that I have done, speed range of NEMA 23 lays between 1- 10,00,00  */
  /* while(Serial.available() > 0){
    Speed = Serial.read();
  }*/
StepCount_StepsCalculation();  /* Function which calculates step angle and step count based on the input given by the user */

      digitalWrite(dir,HIGH);
     
      for(LoopCounter = 0; LoopCounter < StepCount; LoopCounter++){
   
          digitalWrite(pul,HIGH);    /*  */
          delayMicroseconds(Speed);
          digitalWrite(pul,LOW);    /*  */
          delayMicroseconds(Speed);
     }
  delay(1000);
     
      digitalWrite(dir,LOW);
     
      for(LoopCounter = 0; LoopCounter < StepCount; LoopCounter++){
   
          digitalWrite(pul,HIGH);    /*  */
          delayMicroseconds(Speed);
          digitalWrite(pul,LOW);    /*  */
          delayMicroseconds(Speed);
     }
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

  /* This is to make stepper motor to make roation once in clock wise direction and next rotation in anti clock wise direction*/
 /*     if(Direction == LOW){
        Direction = HIGH;   /*Clock wise rotation*/
     /*else{
        Direction = LOW;    /*Anti-clock wise rotation*/
}

/*This function calculates the step angle and step count based on the inputs given by the user*/
void StepCount_StepsCalculation(){
  
  int stepangle;
  
  stepangle = 360/NumberofSteps;
  
  if (StepMode == Full_Step){
      StepCount = 360/stepangle ;
  }else if(StepMode == Half_Step){  /*For 1.8 step, half step corresponds to (360/0.9)= 400 steps, so 400 counts are required for completing one rotation in half step*/
      stepangle = (stepangle/2);
      StepCount = 360/stepangle;
  }else if(StepMode == onebyfourt_Step){
      stepangle = (stepangle/4);
      StepCount = 360/stepangle;
  }else if(StepMode == onebyeight_Step){
      stepangle = (stepangle/8);
      StepCount = 360/stepangle;
  }else if(StepMode == onebysixteen_Step){
      stepangle = (stepangle/16);
      StepCount = 360/stepangle;
  }else{
    StepCount = NumberofSteps;
  }
  
}
