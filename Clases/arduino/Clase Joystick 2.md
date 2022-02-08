# Variaciones de Joystick



## Introducción

Para ahondar más en el sensor que hemos estado trabajando (el Joystick) vamos a hacer una serie de variaciones. Comenzaremos por las más sencillas y la más compleja que quiero hacer es un pequeño juego donde hay que detectar una posición determinada al azar con el joystick usando sonido. 

## Tareas 

* Hacer estos ejercicios y subir las fotografías y el código. 
* Crear una modificación personal de alguno de estos programas. 

_se pueden utilizar estas variaciones para completar tareas anteriores_

## Programas base 

### Código plantilla 

Este es el código plantilla para todos estos proyectos. Después sólo cambiaré elementos específicos. Está realizado a partir de [plantilla.ino](https://github.com/d-prieto/arduinoCourse/blob/main/plantilla.ino) y también a partir del proyecto de prueba del Joystick para definir las variables. 

```C++
/*
*  Documentación del programa 
*  Autore: 
*  Fecha:
*  Código referencia: (url)
*  Descripción del programa:
*  Hardware necesario:
*/

//Includes

//Definiciones de constantes de pines
const int pinBoton = 3; 
const int pinEjeY = A1; 
const int pinEjeX = A0; 

//Definición de variables globales 

void setup() {
//inicializaciones
  pinMode(pinBoton, INPUT);
  digitalWrite(pinBoton, HIGH);
  Serial.begin(9600);
//código que se ejecuta solo una vez. Calibraciones  
}

void loop() {
 //código que se repite una y otra vez. Recuerda colocar las funciones que hagan falta para que sea más claro.  
}  
```

## Proyecto de LED que se enciende cuando pulsas el botón del joystick 

### Nombre del archivo proyecto 

JoystickVariacion01

### Hardware

Tengo un led conectado en este caso al pin 9. Podeis usar este pin o cualquier otro. 

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick%20con%201%20led.JPG)

Esta es la variación que me ha pasado Alba 

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick%20Alba%20con%20led.JPG)

### Software 

Aquí explicaré primero las cosas que voy a añadir y cómo queda el código al final. 

#### Inicio del programa

Primero añadiré a la plantilla mi nombre, la fecha y lo que hace el programa

```C++
/*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 28/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/edit/main/Variaciones%20de%20Joystick.md
*  Descripción del programa: Este programa cuando se pulsa el botón del joystick se enciende un LED. Si no está pulsado el led está apagado. 
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/

```
#### Variables

Después añado en la sección de variables (antes del setup y el loop) las nuevas variables que necesito. Una de un pin y otra del estado del botón. En este caso para la definición de variables, para facilitar la comprensión las escribiré en castellano. Así que en vez de SwitchState estoy utilizando EstadoBoton

```C++
const int pinLed = 9;

 int estadoBoton = 1;
```
#### Setup 

En el Setup sólo tenemos que añadir una línea para inicializar el LED: 

```C++
 pinMode(pinLed, OUTPUT);
```
#### Loop 

Ahora el loop. Este loop lo hemos hecho varias veces. Necesitamos que 
a) Lea el botón
b) Decida si encender el led se enciende o no. 

Para lo primero usamos lo que hemos usado otras veces: 

```C++
 estadoBoton= digitalRead(pinBoton);
```
Recordad que digitalRead puede dar o 1 (HIGH) o 0 (LOW) y sólo esos 2 valores posibles. 

Si tuvieramos algún problema, añadiríamos después un Serial.println(estadoBoton) para ver en el PC qué señal recibe el botón y si está bien conectado (debería leer 0 cuando está pulsado y 1 cuando está sin pulsar). 

Después tenemos el control de flujo (el portero de discoteca que hemos mencionado algunas veces) if. Lo que ocurre es que este botón, a diferencia de los que solemos montar normalmente funciona que "LOW" es cuando está pulsado y no al revés. Esto depende de cómo sea la estructura eléctrica de la conexión del botón. 

En el caso de que sea "LOW" encenderemos el LED usando "digitalWrite" y le indicaremos el pin y HIGH para que lo encienda. En el else haremos lo contrario para que, si el botón no está pulsado, apague el LED

```C++
  if (estadoBoton == LOW){
  digitalWrite(pinLed, HIGH);
 }
 else{
  digitalWrite(pinLed, LOW);
 }
```
#### Código completo 

El código entero está aquí: https://github.com/d-prieto/arduinoCourse/blob/main/JoystickLedButton.ino


## Proyecto de LED que se enciende cuando llevas el joystick cerca del punto máximo en el eje X 

Este proyecto parte del mismo Hardware que tenemos pero vamos a revisar uno de los 2 ejes, el eje X. Después haremos otras acciones en el eje Y. Pero vamos despacio. 

Este proyecto parte del anterior así que iré mencionando las cosas que hay que **añadir** y también las que hay que **quitar**. Seguiremos el mismo orden que en el ejercicio anterior, salvo por la parte de que el código completo no estará disponible. (Se pide que los alumnos seáis capaces de montarlo por vuestra parte a partir de los anteriores ejercicios y subirlo correctamente). 

### Nombre del archivo proyecto 

JoystickVariacion02

### Hardware

Utiliza el mismo Hardware que el ejercicio anterior. 

### Software 

#### Inicio del programa

Primero añadiré a la plantilla mi nombre, la fecha y lo que hace el programa

```C++
/*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 28/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/blob/main/JoystickLedButton.ino
*  Descripción del programa: Este programa cuando el Joystick llega a determinado rango de valores en el EjeX ilumina el LED. Si no, el led se encuentra apagado. 
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/
```

#### Variables

Aquí sí es cierto que tenemos que guardar el pin del led, pero no necesitamos el **estadoBoton** para nada, así que lo borraremos. En su lugar vamos a utilizar una variable que le llamaremos **valorEjeX**

```C++

 int valorEjeX = 0; 
```
#### Setup 

Aquí no necesitamos cambiar el setup

#### Loop 

En este caso vamos a hacer algo similar que con el botón. Leeremos el sensor del ejeX. Pero en vez de usar DigitalRead, usaremos AnalogRead. DigitalRead (lectura digital traduciendo literalmente) nos da valores de 0 o 1. Pero AnalogRead nos da valores entre 0 y 1023. En este caso el valor 0 es el extremo izquierdo y el valor 1023 es el valor moviendo hasta el tope de la derecha el Joystick. 

```C++
 valorEjeX = analogRead(pinEjeX);
```

Después haremos un control de flujo (if) con la condición de que supere una determinada franja. En este caso he puesto el valor 800, pero **podéis probar otros valores para ver qué ocurre**. 

```C++
 
 if (valorEjeX > 800){
  digitalWrite(pinLed, HIGH);
 }
 else{
  digitalWrite(pinLed, LOW);
 }
```

El valor máximo que puede alcanzar el ejeX es 1023, con lo cual hasta entonces podemos ir viendo su sensibilidad. Con 800 el intervalo es bastante sensible. Y he visto que poniendo ==1023 no llego al tope físico del mecanismo sino que lo supero. 

## Proyecto de Joystick que solo ilumina cuando llega a un rango determinado del eje X 

Aquí hemos mirado un umbral (que sea superior a 800) pero vamos a hacer otra variación donde vamos a incluir 2 límites. Un mínimo y un máximo

### Nombre del archivo proyecto 

JoystickVariacion03


### Hardware

Utiliza el mismo Hardware que el ejercicio anterior. 

### Software 

#### Inicio del programa

Primero añadiré a la plantilla mi nombre, la fecha y lo que hace el programa. En este caso "determinado rango de valores" sigue siendo válido. Así que lo podemos dejar. 

```C++
/*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 28/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/blob/main/JoystickLedButton.ino
*  Descripción del programa: Este programa cuando el Joystick llega a determinado rango de valores en el EjeX ilumina el LED. Si no, el led se encuentra apagado. 
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/
```

#### Variables

No tenemos nada nuevo respecto al ejercicio anterior. 

#### Setup 

Aquí no necesitamos cambiar el setup

#### Loop 

Aquí sí vamos a tocar la parte de la condición del if. **El resto quedará igual**. Lo que vamos a hacer es que vaya sólo entre determinados valores. Para ello usaremos el operador Y (&&). Por ejemplo vamos a hacer que sea mayor que 100 y menor que 200 para que encienda el LED de la siguiente forma:


```C++
 
 if (valorEjeX > 100 && valorEjeX < 200){
  digitalWrite(pinLed, HIGH);
 }
 else{
  digitalWrite(pinLed, LOW);
 }
```


## Proyecto de Joystick que cuando llegas a un punto determinado suena una pequeña nota en el altavoz

Este proyecto sigue avanzando a partir del anterior. Vamos a utilizar aquí el eje Y, mientras el eje X sigue encendiendo el led. 

### Hardware

Añado el altavoz al pin 8. En este caso para poner el altavoz basta conectarlo si necesidad de resistencia. Uno de los palos del altavoz se conecta al pin 8 y otro se conecta al Ground.

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick%20con%20Led%20y%20altavoz.JPG)

En mi caso como el piezo se lo dejé a alguien que se le rompió el suyo, utilizo otro altavoz conectándolo con un cable negro al Ground y con un cable blanco al pin 8. 

Dejo igualmente el Joystick y el led donde estaban dado que siguen funcionando en este sketch. 

### Software

#### Inicio del programa

Aquí sí caben modificaciones en la parte del hardware y en la descripción. 

```C++
/*
*  Documentación del programa 
*  Autore: David Prieto
*  Fecha: 29/02/2021
*  Código referencia: https://github.com/d-prieto/arduinoCourse/blob/main/JoystickLedButton.ino
*  Descripción del programa: Este programa cuando el Joystick llega a determinado rango de valores en el EjeX ilumina el LED. Si no, el led se encuentra apagado. En el ejeY además si llega a determinado umbral, el altavoz hará un breve pitido. 
*  Hardware necesario: Joystick. Led. Resistencia de 220 Ohms
*/
```
#### Variables

Tenemos un pin nuevo así que una nueva constante para ese pin:

```C++

 const int pinAltavoz = 8; 
```


Añadimos la variable para guardar el eje Y. Le llamaremos valorEjeY, como la del ejeX podrá guardar valores entre 0 y 1023

```C++

 int valorEjeY = 0; 
```

También añado un par de variables que son la frecuencia del sonido (440 hertzios, un LA) y una duración del sonido (en milisegundos) para probar. 

```C++

 int frecuenciaNota = 440; 
 int duracionSonido = 250;
 
```

#### Setup 

Aquí no necesitamos cambiar el setup

#### Loop 

Este loop mantiene lo anterior, leer los datos del eje X y hacer algo con ello. De momento lo podemos dejar tal cual y poner después el eje Y. Cuando tengamos ese valor lo comparamos con un valor (por ejemplo que sea menor que 223) y en ese caso, ponemos un tone. Tone es la funcion que necesitamos para crear un sonido y necesita el pin, la frecuencia de la nota y la duración del sonido en milisegundos. Las tres cosas las tenemos guardadas en variables (ver sección de variables) así que las usamos. 

En el caso de que no estemos, voy a poner un "noTone" para silenciar el altavoz. 

```C++

 valorEjeY = analogRead(pinEjeY);
 if (valorEjeY < 223){
  tone(pinAltavoz,frecuenciaNota,duracionSonido);
 }
 else{
  noTone(pinAltavoz);
 }
 
 ```
 
 Probad diferentes valores de frecuencia y límites del valor de ejeY para ver que todo funciona bien y haced variaciones. 
