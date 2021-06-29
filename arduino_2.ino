int c = 0;
int state = 0;
bool flag = true;
String id; 
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Write your ID:");
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  while(flag){
	state= Serial.read();
    
    if(state!=42 && state!=-1){
      lcd.setCursor(c, 1);
      c++;


      if(state == 48){
        Serial.println(0);
      	Serial.println(c);

        lcd.print(0);
      }else{
        Serial.println(state);
      	Serial.println(c);
      	lcd.print(state); 
      }
      
	  
    }else if(state==42){
      c--;
      Serial.println(state);
      Serial.println(c);
      
	  lcd.setCursor(c, 1);
      lcd.print(" ");
      
    }
    if(c==10){
    	flag = false;  
    }
  }
  	lcd.setCursor(0, 0);
  	lcd.print("It is correct? 1=YES 2=NO");
    delay(200);  
}
