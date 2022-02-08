# Clase de bits y bytes

![](https://i.pinimg.com/originals/7f/7f/28/7f7f2882899755a705a2953b6fcfc263.gif)

_lluvia digital de Matrix_

## De interruptores a números

Cómo hemos visto en otras partes del curso, la unidad mínima de información en cualquier sistema informatizado es el bit. Un interruptor donde "encendido" es 1 y "apagado" es 0.

Con esto, podemos hacer números. Pero ¿cómo?

![imagen](https://user-images.githubusercontent.com/60569015/113589090-40396800-9631-11eb-9f52-a75d79419586.png)

Los números normalmente los expresamos con un sistema decimal, pero existen otros sistemas. En la pizarra explicaremos los sistemas binario, octal, hexadecimal y su comparación con el decimal. 

El binario sólo tiene 0 y 1. 

El octal tiene cifras del 0 al 7. 

El hexadecimal tiene cifras del 0 al 6 y de la a a la e para representar las 5 siguientes cifras. 

### Ejercicio con arduino. Hacer números con interruptores

Con esto podemos hacer un pequeño programa para hacer números con interruptores. Utilizaremos 5 interruptores. Este ejercicio no está _acabado_ sino que se pide crear un programa propio que combine los diferentes estadoBoton para generar números de diferentes formas. 

``` C++

const int pinBotones[] = {2,3,4,5,6};
const int numeroBotones = 5;
int estadoBoton1 = 0;
int estadoBoton2 = 0;
int estadoBoton3 = 0;
int estadoBoton4 = 0;
int estadoBoton5 = 0;

void setup() {
 for(int x=0; x<=numeroBotones; x++){
  pinMode(pinBotones[x],INPUT);
 }
Serial.begin(9600);
}

void loop() {
  //leer botones
  estadoBoton1 = digitalRead(pinBotones[0]);
  estadoBoton2 = digitalRead(pinBotones[1]);
  estadoBoton3 = digitalRead(pinBotones[2]);
  estadoBoton4 = digitalRead(pinBotones[3]);
  estadoBoton5 = digitalRead(pinBotones[4]);
  int numero;
// Espacio en blanco para hacer operaciones con números


//Mandamos al ordenador el número
  Serial.print("El número que sale con los botones es: ");
  Serial.println(numero);
}
``` 
Opciones posibles: sumarlos todos. Sumar algunos y restar otros. Sumar unos y multiplicarlos por otros. Multiplicar algunos de ellos por números más grandes (por ejemplo que el botón 4 signifique 432). 


Una vez tenemos _números_ podemos hacer cosas. Al menos representar números. Pero nos falta representar otras cosas como imágenes, sonidos o letras. 

La siguiente vuelta es hacer un traspase de números a letras

## De números a letras 

Para pasar de números a letras usaremos... una tabla. Concretamente la tabla ASCII. Le das un número y te devuelve una letra. Esto tiene ciertas limitaciones para determinados tipos de caracteres, pero Serial es lo que utiliza. 

En nuestro caso cogeremos 7 bits y en función de su varlor (de 0 a 128). Se puede consultar aquí: https://www.arduino.cc/en/Reference/ASCIIchart pero aquí está la imagen

![imagen](https://user-images.githubusercontent.com/60569015/113596375-821adc00-963a-11eb-9ff6-282d7f7e1c16.png)

### Ejercicio de combinacion de números

``` C++

/*
  Uses a for loop to print numbers in various formats.
*/
void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
}

void loop() {
  escribirTitulosDeColumnas();

  for (int x = 0; x < 1000; x++) { // only part of the ASCII chart, change to suit
    if(x%21 == 20){
      escribirTitulosDeColumnas();
    }
    // print it out in many formats:
    Serial.print(x);       // print as an ASCII-encoded decimal - same as "DEC"
    Serial.print("\t\t");  // prints two tabs to accomodate the label lenght

    Serial.print(x, DEC);  // print as an ASCII-encoded decimal
    Serial.print("\t");    // prints a tab

    Serial.print(x, HEX);  // print as an ASCII-encoded hexadecimal
    Serial.print("\t");    // prints a tab
    Serial.print("\t");    // prints a tab
    
    Serial.print(x, OCT);  // print as an ASCII-encoded octal
    Serial.print("\t");    // prints a tab

    Serial.print(x, BIN);  // print as an ASCII-encoded binary
    Serial.print("\t");    // prints a tab
    // then adds the carriage return with "println"
    Serial.println(char(x));
    delay(100);            // delay 100 milliseconds
  }
  Serial.println();        // prints another carriage return
}

void escribirTitulosDeColumnas() {
    // print labels
  Serial.print("Sin formato");  // prints a label
  Serial.print("\t");         // prints a tab

  Serial.print("DECimal");
  Serial.print("\t");

  Serial.print("HEXadecimal");
  Serial.print("\t");

  Serial.print("OCTal");
  Serial.print("\t");

  Serial.print("BINario");
  Serial.print("\t");

  Serial.print("caracter");  
  Serial.println();        // carriage return after the last label
}

```

Este código lo tomé de aquí: https://www.arduino.cc/reference/en/language/functions/communication/serial/print/ y sirve para ver cómo van los diferentes tipos de números. Y añadí los caracteres y que escribiera la cabecera de las columnas cada 21 líneas. 


Y ahora al revés: 

A partir de este código https://forum.arduino.cc/index.php?topic=647786.msg4369705#msg4369705 se puede tomar lo que le mandemos nosotros al arduino 


``` C++


void setup() {
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()){
      int c = Serial.read();
    if (c != -1) { // if we have received a byte
      Serial.print((char) c);
      Serial.print(F("\t0x"));
      Serial.print((byte) c, HEX);
      Serial.print(F("\t0b"));
      for (char aBit = 7; aBit >= 0; aBit--) {
        Serial.print(bitRead(c, aBit));
      }
      Serial.print(F("\t"));
      for (char aBit = 7; aBit >= 0; aBit--) {
        if (bitRead(c, aBit)) Serial.write('*'); else Serial.write('_');
      }
      Serial.println();
    }
  }
}
```

Este código habla a través del Serial y cuando escribimos algo, nos lo transforma en código hexadecimal y en bits de dos formas diferentes. 

Una versión con ocho leds sería así: 




``` C++
const int firstLedPin = 2;




void setup() {
  Serial.begin(9600);
  for (int x = firstLedPin; x <= firstLedPin +8; x++){
    pinMode(x, OUTPUT);
  }
}

void loop() {
  if(Serial.available()){
      int c = Serial.read();
    if (c != -1) { // if we have received a byte
      Serial.print((char) c);
      Serial.print(F("\t0x"));
      Serial.print((byte) c, HEX);
      Serial.print(F("\t0b"));
      for  (char aBit = 7; aBit >= 0; aBit--) {
        Serial.print(bitRead(c, aBit));
      }
      Serial.print(F("\t"));
      int pinLed = 2;
      for (char aBit = 7;  aBit >= 0; aBit--) {
        if (bitRead(c, aBit)) {
          Serial.write('*');
          digitalWrite(pinLed, HIGH);
        }
        else{
          Serial.write('_');
          digitalWrite(pinLed, LOW);
        }
        pinLed++;
      }
      Serial.println();
      delay(1000);
    }
    Serial.println("Fin del mensaje");
  }
}
```



Ahora vamos a intentar hacer lo contrario para lo cual vamos a necesitar 8 botones o 1 botón y cables con posible conexión manual a 5V o GND.  (no se incluye código aún)


## Requisitos para repositorio:

- Fotografía y apuntes sobre los sistemas de numeración. 
- Código de sistema de botones. Personal y resolución binaria. 
- Fotografia del caracter enviado y qué leds enciende. 
- Código y comentario.
- Fotografía del arduino con botones y los caracteres que crean.  
- Código y comentario.
