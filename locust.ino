
int gronnPr = 0; // store the current light value
int gulPr = 0;
int rodPr = 0;
const int grense = 500;
const int resetKnapp = 2;
int knappStatus = 0;
int gronnTeller = 0;
int gulTeller = 0;
int rodTeller = 0;

const int blattLys = 3;

const int grontLys1 = 13;
const int grontLys2 = 12;
const int grontLys3 = 11;

const int gultLys1 = 9;
const int gultLys2 = 8;
const int gultLys3 = 7;

const int rodtLys1 = 6;
const int rodtLys2 = 5;
const int rodtLys3 = 4;
int sistOppdatert = 0;




void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600); //configure  serial to talk to computer
  //groenne
  
  pinMode(resetKnapp, INPUT_PULLUP);
  
  pinMode(blattLys, OUTPUT);//blattLys lys
  
  //gronne
  pinMode(grontLys1, OUTPUT);
  pinMode(grontLys2, OUTPUT);
  pinMode(grontLys3, OUTPUT);
  
  // gule
  pinMode(gultLys1, OUTPUT);
  pinMode(gultLys2, OUTPUT);
  pinMode(gultLys3, OUTPUT);
  
  // rode
  pinMode(rodtLys1, OUTPUT);
  pinMode(rodtLys2, OUTPUT);
  pinMode(rodtLys3, OUTPUT);
}



void  loop() {
    // put your main code here, to run repeatedly:
    gronnPr = analogRead(A0);  // read and save value from PR
    gulPr = analogRead(A1);
    rodPr = analogRead(A2);
  	// Forslag fra bruker, fungerte ikke
	knappStatus = digitalRead(resetKnapp);
  /*
  	if(digitalRead(resetKnapp) == LOW) {
      knappStatus = HIGH;
    }else {
      	knappStatus = LOW;
     }
     */
   
    Serial.println("groent lys: " + String(gronnPr)); // print current  light value
    Serial.println("gul lys :" + String(gulPr)); // print current  light value
    Serial.println("rod lys" + String(rodPr)); // print current  light value
	Serial.println("KNAPP" + String(knappStatus));
  	
	
  
  	if (knappStatus == LOW){
    gronnTeller = 0;
    gulTeller = 0;
    rodTeller = 0;
    digitalWrite(grontLys1, LOW);//evt sette alle disse inne i en else nede
    digitalWrite(grontLys2, LOW);
    digitalWrite(grontLys3, LOW);
    digitalWrite(gultLys1, LOW);
    digitalWrite(gultLys2, LOW);
    digitalWrite(gultLys3, LOW);
    digitalWrite(rodtLys1, LOW);
    digitalWrite(rodtLys2, LOW);
    digitalWrite(rodtLys3, LOW);
    Serial.println("RESET KNAPP TRYKKET");
    delay(6000);
    
  }
  
  
  if (gronnPr < grense && gulPr > grense && rodPr > grense && sistOppdatert != 1){
    gronnTeller ++;
    sistOppdatert = 1;
    digitalWrite(blattLys, HIGH);
    delay(1500);
    digitalWrite(blattLys, LOW);
    
  }
  
  if (gulPr < grense && gronnPr > grense && rodPr > grense && sistOppdatert != 2){
    gulTeller ++;
    sistOppdatert = 2;
   	digitalWrite(blattLys, HIGH);
	delay(1500);
    digitalWrite(blattLys, LOW);
	
  }
  
  if (rodPr < grense && gronnPr > grense && gulPr > grense && sistOppdatert != 3){
    rodTeller ++;
    sistOppdatert = 3;
    digitalWrite(blattLys, HIGH);
	delay(1500);
    digitalWrite(blattLys, LOW);
	
  }
  
  Serial.println("gronn teller =  " + String(gronnTeller));
  Serial.println("gul teller =  " + String(gulTeller));
  Serial.println("rod teller = " + String(rodTeller));
  
  
  //lysene


  if (gronnTeller >= 3 && gronnTeller < 6 ){
    digitalWrite(grontLys1, HIGH);
    
  }
  if (gronnTeller >= 6 && gronnTeller < 9){
    digitalWrite(grontLys2, HIGH);
  }
  if (gronnTeller >= 9){
    digitalWrite(grontLys3, HIGH);
  }
  
  
  if (gulTeller >= 3 && gulTeller < 6){
    digitalWrite(gultLys1, HIGH);
    
  }
  if (gulTeller >= 6 && gulTeller < 9){
    digitalWrite(gultLys2, HIGH);
  }
  if (gulTeller >= 9){
    digitalWrite(gultLys3, HIGH);
    
  }
  
  
  if (rodTeller >= 3 && rodTeller < 6){
    digitalWrite(rodtLys1, HIGH);
    
  }
  if (rodTeller >= 6 && rodTeller < 9){
    digitalWrite(rodtLys2, HIGH);
  }
  if (rodTeller >= 9){
    digitalWrite(rodtLys3, HIGH);
  }
  
  
delay(100);
}


