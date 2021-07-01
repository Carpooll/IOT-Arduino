#include <Keypad.h>

const byte numRows= 4; //Numero de filas del teclado
const byte numCols= 4; //Numero de columnas del teclado
int id[10];
int money;
int last;
int c = 0;
bool on_id;
bool on_money;
bool on_choice;
//keymap define las teclas que aparecen en el teclado
char keymap[numRows][numCols]= 
{
{1,2,3, 'A'}, 
{4,5,6, 'B'}, 
{7,8,9, 'C'},
{'*','0', '#', 'D'},
};


//Configuracion de los pines de conexion del teclado con el Arduino
byte rowPins[numRows] = {11,10,9,8}; //filas 0 a 3
byte colPins[numCols]= {7,6,5,4}; //Columnas 0 a 3

//Inicializacion y configuracion del teclado
Keypad teclado= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);


char tecla;
void setup()
{
	Serial.begin(9600);
	on_id=true;
}
 
void loop() {
  
  tecla = teclado.getKey();
  if (tecla){// Detecta si el usuario oprimio una tecla 
    if(on_id){
      if(tecla!='*'){
      	if(tecla==48){
        	id[c] = 0;
      	}else{
     		id[c] = tecla;
      	}
     	Serial.write(tecla);
     	c++;
      }else if(tecla == '*' && c>0){
      	Serial.write(42);
      	c--;
   	  }
      if(c==10){
        on_id = false;
        on_choice=true;
      }
    }
    if(on_choice){

      if(tecla=='*'){
      	Serial.write(42);
        on_id=true;
        on_choice = false;
        c = 0;
      }else if(tecla=='#'){
        Serial.write(35);
        on_money = true;
        on_choice = false;
      }
    }
    if(on_money){
      if(tecla=='#'){
      }
      else if(tecla=='A'){
        Serial.write(100);
      }else if(tecla=='*' && money>0){
        money-=tecla;
        Serial.write(42);
        if(money >= 10){
          money/=10;
        }
      }else{
        if(money>0){
          money*=10;
        }
        if(tecla==48){
          Serial.write(0);
        }else{
          money+=tecla;
          Serial.write(tecla);
        }
      }
    }  
  }
}
/*else if(c==10){
    Serial.println();
    Serial.println("el id es: ");
    for(int i = 0; i<10; i++){
      Serial.print(id[i]);
    }
    delay(10000);
  }*/
