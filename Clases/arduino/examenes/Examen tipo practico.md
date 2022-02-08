# Problemas tipo de cara al examen

En esta página paso a detallar varios problemas tipo similares a los que se pondrán el día del examen

## Estructura general 

### Documentación exigida

Se solicita al alumno que suba a su repositorio fotografía de cada uno de los problemas además de enseñarselo en funcionamiento al docente. Subirá al repositorio el código bien documentado. Subirlo con comentarios pertinentes hechos por el alumno suma puntos. 


### Formato de documentación 

Se requiere que el inicio del programa esté comentado e incluya Nombre del alumno, fecha, descripción del programa y hardware utilizado. 

**No subir la documentación correctamente sin el inicio programa comentado se considerará copia de programa de otra persona **

### Hardware requerido 

Se solicita al alumno que, utilizando los elementos del starter kit sepa montar por su cuenta un botón funcional, un potenciómetro funcional y un led. En función del problema puede haber más o menos leds o botones. 

### Pines personalizados

En estos problemas, para que cada solución sea diferente, se repartirá una hoja (que publicaré aquí también) en la cual cada alumno sabrá a qué pines debe conectar su hardware (y reflejarlo en su documentación). En la práctica será en función de la fila y será como sigue:

![imagen](https://user-images.githubusercontent.com/60569015/111081538-1a261980-8504-11eb-9e5d-94171d034499.png)

**No usar los pines asignados en el examen es motivo de puntuación 0 al ser sospechoso de copia de código.**

## Problemas propuestos de ejemplo 

### Ejemplo 01 

Utilizando dos botones y un led (led1), deseo que si pulso un botón (botón1), el led se encienda y permanezca encendido. Si pulso el otro botón (botón 2) el led se apagará y permanecerá apagado. 

### Ejemplo 02

Utilizando el potenciómetro y los 3 leds deseo que los leds se enciendan en función de la posición del potenciómetro de la siguiente forma:

- En una posición todos los leds están apagados
- En otra posición sólo está encendido el led1 (el resto apagados)
- En una tercera posición están encendidos el led1 y el led2 (el resto apagados)
- En una última posición están encendidos los 3 leds. 

### Ejemplo 03

Utilizando el potenciómetro y un botón deseo que si el potenciómetro está en uno de los extremos y pulso un botón, aparezca en el serial del ordenador el siguiente mensaje: "Comunicación establecida"

### Ejemplo 04

Utilizando el potenciómetro y el led2 deseo que si muevo el potenciómetro el led tenga más o menos potencia. 

### Ejemplo 05 

Utilizando dos botones y un led necesito que uno de ellos (led1) se encienda durante 5 segundos y se apague (para nunca más volver a encenderse). Después necesito que si pulsas los dos botones a la vez se encienda el led 2. Si no están pulsados los dos a la vez el led 2 estará apagado. 

### Ejemplo 06

Con el potenciómetro, un botón y un led. Se desea que el led se encienda si bien el botón está pulsado o si el potenciómetro pasa del valor 512. 

## Resolución del examen 

Para resolver el examen lo primero que me he hecho es una plantilla. Se puede hacer sin ésta pero a mí me sirve para ordenarme mejor. Pongo la documentación al principio del propio código. 

Los problemas, como siempre tienen varias opciones posibles. 

```C++
/*
 * Nombre: David Prieto
 * Fecha: 21 de Marzo de 2021
 * Descripcíón del programa: Plantilla para hacer los ejercicios del examen.
 * A partir de esto tengo configurado los pines y podré comenzar a hacer lo que se pida.
 * Hardware utlizado: Ninguno
 * 
 */

const int pinLed1 = 2;
const int pinLed2 = 3;
const int pinLed3 = 4;
const int pinBoton1 = 5;
const int pinBoton2 = 6;
const int pinPotenciometro = A0;

int estadoBoton1;
int estadoBoton2;
int valorPotenciometro;

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinBoton1, INPUT);
  pinMode(pinBoton2, INPUT);

  Serial.begin(9600);
}

void loop() {
  

}

```
### Problema 1

Utilizando 3 leds(led1, led2, led3) se necesita que el programa que haga lo siguiente. Tras
conectarlo, durante 1 segundo habrá un led (el led3) que se encenderá una única vez. Después
los 3 leds se encenderán y apagarán estando 1 segundo encendidos y 0,5 segundos apagados
en bucle.

Este requiere un digitalWrite en el setup y luego la intermitencia en el loop. 


```C++
/*
 * Nombre: David Prieto
 * Fecha: 21 de Marzo de 2021
 * Descripcíón del programa: Utilizando 3 leds(led1, led2, led3) se necesita que el programa que haga lo siguiente. 
 * Tras conectarlo, durante 1 segundo habrá un led (el led3) que se encenderá una única vez. 
Después los 3 leds se encenderán y apagarán estando 1 segundo encendidos y 0,5 segundos apagados en bucle.
 * Hardware utlizado: 3 Leds
 * 
 */

const int pinLed1 = 2;
const int pinLed2 = 3;
const int pinLed3 = 4;

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);

  digitalWrite(pinLed3, HIGH);
  delay(1000);
  digitalWrite(pinLed3, LOW);
}

void loop() {
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed3, HIGH);
  delay(1000);
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  delay(500);
}

```

### Problema 2

Utilizando un potenciómetro, un botón (botón1) y un led (led1) se necesita que el led se
encienda únicamente si el valor del potenciómetro es 0 y el botón está pulsado. En el resto de
los casos el led estará apagado.

Este ejercicio se resuelve leyendo los dos inputs y para decidir cuando encender el led (enchegar como dice Javi) se puede utilizar un único if con el operador Y. 

```C++
/*
 * Nombre: David Prieto
 * Fecha: 21 de Marzo de 2021
 * Descripcíón del programa: Utilizando un potenciómetro, un botón (botón1) y un led (led1) se necesita que el led se
encienda únicamente si el valor del potenciómetro es 0 y el botón está pulsado. En el resto de
los casos el led estará apagado.
 * Hardware utlizado: 1 botón (Pull-up), 1 potenciómetro y 1 led
 * 
 */

const int pinLed1 = 2;
const int pinBoton1 = 5;
const int pinPotenciometro = A0;

int estadoBoton1;
int valorPotenciometro;

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinBoton1, INPUT);
}

void loop() {
  estadoBoton1 = digitalRead(pinBoton1);
  valorPotenciometro = analogRead(valorPotenciometro);
  if (valorPotenciometro == 0 && estadoBoton1 == HIGH){
    digitalWrite(pinLed1, HIGH);
  }
  else {
    digitalWrite(pinLed1, LOW);
  }
}
```


### Problema 3

Con dos botones (botón 1 y botón 2) y un led(led1) se necesita que el led se encienda durante
1 segundo una única vez después de conectar el Arduino. Después, necesito que se encienda el
led si pulso cualquiera de los dos botones. En otro caso el led estará apagado.

Este ejercicio para su resolución necesita de nuevo colocar algo en el setup. Después es similar al segundo ejercicio, leyendo los 2 botones y se puede resolver con un operador || (operador "o").

```C++
/*
 * Nombre: David Prieto
 * Fecha: 21 de Marzo de 2021
 * Descripcíón del programa: Con dos botones (botón 1 y botón 2) y un led(led1) se necesita que el led se encienda durante
1 segundo una única vez después de conectar el Arduino. Después, necesito que se encienda el
led si pulso cualquiera de los dos botones. En otro caso el led estará apagado.

 * Hardware utlizado: 2 botones y 1 led
 * 
 */

const int pinLed1 = 2;
const int pinBoton1 = 5;
const int pinBoton2 = 6;

int estadoBoton1;
int estadoBoton2;

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinBoton1, INPUT);
  pinMode(pinBoton2, INPUT);

 
  digitalWrite(pinLed1, HIGH);
  delay(1000);
  digitalWrite(pinLed1, LOW);
}

void loop() {
    estadoBoton1 = digitalRead(pinBoton1);
    estadoBoton2 = digitalRead(pinBoton2);
    if (estadoBoton1 == HIGH || estadoBoton2 == HIGH){
      digitalWrite(pinLed1, HIGH);
    }
    else {
      digitalWrite(pinLed1, LOW);
   }

}
```

### Problema 4
Con un botón(botón2) y un led (led1) se necesita un programa que vaya cambiando en bucle
entre los siguientes modos:
-Encender un led
-Que ese led parpadeé
-Que ese led parpadee más rápido
-Apagar el led.
Para cambiar de modo bastará pulsar una vez el botón (no hace falta mantener pulsado)

Aquí necesitamos el Kill Switch. 

```C++
/*
 * Nombre: David Prieto
 * Fecha: 21 de Marzo de 2021
 * Descripcíón del programa: Con un botón(botón2) y un led (led1) se necesita un programa que vaya cambiando en bucle
entre los siguientes modos:
-Encender un led
-Que ese led parpadeé
-Que ese led parpadee más rápido
-Apagar el led.
Para cambiar de modo bastará pulsar una vez el botón (no hace falta mantener pulsado)

 * Hardware utlizado: Un botón y un led
 * 
 */

const int pinLed1 = 2;
const int pinBoton2 = 6;


int estadoBoton2;
bool estaSiendoPulsadoElBoton = false;

int estadoLed = 0;
// 0 apagado
// 1 encendido
// 2 parpadeo largo
// 3 parpadeo corto

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinBoton2, INPUT);

  Serial.begin(9600);
}

void loop() {
  checkButton();
  if (estadoLed == 0){
    digitalWrite(pinLed1, LOW);
  }
  if (estadoLed == 1){
    digitalWrite(pinLed1, HIGH);
  }
  if (estadoLed == 2){
    digitalWrite(pinLed1, HIGH);
    delay(800);
    digitalWrite(pinLed1, LOW);
    delay(800);
  }  
  if (estadoLed == 3){
    digitalWrite(pinLed1, HIGH);
    delay(200);
    digitalWrite(pinLed1, LOW);
    delay(200);
  } 
}

void checkButton() {
  // leemos el botón y lo guardamos en switchtate
  estadoBoton2 = digitalRead(switchPin);
  if (estadoBoton2 == HIGH) {
    if (estaSiendoPulsadoElBoton == false) {
      estadoLed ++;
      //reinicio de estadoLed
      if(estadoLed > 3){
        estadoLed =0;
      }
      estaSiendoPulsadoElBoton = true;
    }
  }
  else {
    estaSiendoPulsadoElBoton = false;
  }
}
```



### Problema 5

Con un potenciómetro y un botón (botón 1), se necesita que si el potenciómetro tiene valores
menores a 200 o superiores a 1000 se mande un mensaje al ordenador. Si el botón está
pulsado será “Activando botón”. Si no está pulsado el mensaje será “Botón no activado”. Si el
potenciómetro no tiene esos valores no ocurrirá nada. Los mensajes los mandará cada 0,2
segundos.

Aquí tenemos dos ifs anidados. Si el potenciómetro está en la posición adecuada, revisamos el estado del botón para mandar un mensaje o el otro. Añado comentarios a las líneas de las llaves. 

```C++

/*
 * Nombre: David Prieto
 * Fecha: 21 de Marzo de 2021
 * Descripcíón del programa: 
Con un potenciómetro y un botón (botón 1), se necesita que si el potenciómetro tiene valores
menores a 200 o superiores a 1000 se mande un mensaje al ordenador. Si el botón está
pulsado será “Activando botón”. Si no está pulsado el mensaje será “Botón no activado”. Si el
potenciómetro no tiene esos valores no ocurrirá nada. Los mensajes los mandará cada 0,2
segundos.
 * Hardware utlizado: 1 botón (Pull-up), 1 potenciómetro
 * 
 */

const int pinBoton1 = 5;
const int pinPotenciometro = A0;

int estadoBoton1;
int valorPotenciometro;

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinBoton1, INPUT);

  Serial.begin(9600);
}

void loop() {
  estadoBoton1 = digitalRead(pinBoton1);
  valorPotenciometro = analogRead(valorPotenciometro);
  if (valorPotenciometro < 200 ||valorPotenciometro > 1000){
    if (estadoBoton1 == HIGH) {
      Serial.println(“Activando botón”);
    } //llave del if del botón
    else{ //caso de que el botón no esté pulsado
      Serial.println(“Botón no activado”);
    }
    delay(200);
  } // llave del if del potenciómetro
} //llave del loop
```

### Problema 6
Utilizando los 2 botones, un potenciómetro y un led (led2) se necesita que el led se encienda.
Después, cuando un botón (cualquiera de ellos) está pulsado, el potenciómetro variará la
potencia del led. En caso de que ningún botón esté pulsado, el led quedará con la potencia
establecida por el potenciómetro la última vez que se hayan pulsado.


```C++
/*
 * Nombre: David Prieto
 * Fecha: 21 de Marzo de 2021
 * Descripcíón del programa: 
Utilizando los 2 botones, un potenciómetro y un led (led2) 
se necesita que el led se encienda. Después, cuando un botón 
(cualquiera de ellos) está pulsado, el potenciómetro variará la potencia del led.
En caso de que ningún botón esté pulsado, el led quedará con la potencia establecida
por el potenciómetro la última vez que se hayan pulsado.
 * Hardware utlizado: 2 botón (Pull-up), 1 potenciómetro, 1 led
 * 
 */
 

const int pinLed2 = 3;
const int pinBoton1 = 5;
const int pinBoton2 = 6;
const int pinPotenciometro = A0;

int estadoBoton1;
int estadoBoton2;
int valorPotenciometro;

void setup() {
  pinMode(pinLed2, OUTPUT);
  pinMode(pinBoton1, INPUT);
  pinMode(pinBoton2, INPUT);
  digitalWrite(pinLed2, HIGH);
  
}

void loop() {
  estadoBoton1 = digitalRead(pinBoton1);
  estadoBoton2 = digitalRead(pinBoton2);  
  valorPotenciometro = analogRead(valorPotenciometro);
  if (estadoBoton1 == HIGH || estadoBoton2 == HIGH){
   //divido entre cuatro porque analogRead va de 0 a 1023 y el analogWrite de 0 a 255
   analogWrite(pinLed2, valorPotenciometro/4);
  }
}
```
