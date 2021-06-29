#include <Keypad.h>

const byte numRows= 4; //Numero de filas del teclado
const byte numCols= 4; //Numero de columnas del teclado
long int id;
int last;
int c = 0;
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
}
 
void loop() {
  
tecla = teclado.getKey();
  if (tecla && c<11)// Detecta si el usuario oprimio una tecla
  { 
    id*=10;
    if(tecla!='*'){
     c++;
      if(tecla!=48){
        id+=tecla;
      } 
     last = tecla;
     Serial.write(tecla);
     
    }else if(tecla == '*'){
      id-=last;
      id/=10;
      Serial.write(42);
      c--;
    }
    
  }else if(c==10){
    Serial.println("el id es: ");
    Serial.println(id);
    delay(10000);
  }
}
