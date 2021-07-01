int state = 0;
int c;
int total_money;
bool on_id = true;
bool on_money = false;

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
	id();
  
}

void id(){
  c=0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Insert your id:");
  
  while(on_id){
   	state= Serial.read();
    if(state!=-1){
      if(state!=42){
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

    }else if(state == 42 && c>=0){
      c--;
      Serial.write('borrar');
      Serial.println(c);

      lcd.setCursor(c, 1);
      lcd.print(" ");

    }
    if(c==10){
      on_id = false;  
      choice();
    }
  }
  }
}

void money(){
  c=0;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Insert money: ");
  while(on_money){
    state= Serial.read();
    
    if(state!=-1){
      if(state!=42){
        if(state==100){ 
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Depositing");
          delay(2300);
          lcd.clear();
          lcd.print("Deposite");
          lcd.setCursor(0,1); 
          lcd.print("Successfully");
          delay(2000);
          on_id = true;
          on_money = false;
          id();
        }
      	lcd.setCursor(c, 1);
      	c++;

        if(state == 48 && total_money>0){
          total_money*=10;
          Serial.println(0);
          Serial.println(c);
          lcd.print(0);
      	}else{
          if(total_money>0){
            total_money*=10;
          }
          total_money+=state;
          Serial.println(state);
          Serial.println(c);
          lcd.print(state); 
        }
      }
      else if(state == 42 && c>=0){
      c--;
      Serial.println('Borrar');
      Serial.println(c);
		
      lcd.setCursor(c, 1);
      lcd.print(" ");
	  
      }
    }
  }
}
void choice(){
  lcd.setCursor(0, 0);
  lcd.print("Is it correct? ");
  while(state!= 42 && state!=35){
    state = Serial.read();
    if(state == 42){
      on_id=true;
      on_money=false;
      id();
    }
    if(state == 35){
      on_id=false;
      on_money=true;
      money();
  }
  }
}
