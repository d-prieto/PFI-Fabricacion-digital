# Clase de operadores

## Objetivos

* Repasar y entender los conceptos de operadores para el control del flujo de un programa

## Tarea

* Realizar un código propio (y su hardware) que incluya cada uno de los operadores lógicos "Y", "O" y "NO"

* Documentarlo y subirlo al repositorio bajo el epìgrafe "clase de operadores"

* Actualizar el snippet del Kill Switch. 

## Hardware requerido

Esta clase requiere de vuestro arduino pero se puede llevar sin tener hardware utilizando únicamente Serial.write y Serial.read, pero es más divertida con algo de hardware. 

En los ejemplos que voy a usar voy a utilizar lo creado ayer, un par de potenciómetros y un botón en forma conjunta de un joystick y 3 leds. Serán cosas sencillas pero que luego irán creciendo

## Explicación

Cuando queremos que algo se ejecute a veces pero no siempre hemos utilizado la estructura "if" con "else". Esta resuelve una variable booleana y si esta variable es "true" ejecuta lo que haya entre las llaves ({) y si no, ejecuta lo que haya en las llaves del "else". Si no existe else, no ejecuta nada.

### Operadores de comparación

Hemos utilizado comparadores para que esto funcione. Haciendo un repaso rápido son los siguientes:

* Distinto de: != (not equal to)
* Menor que < (less than)
* Menor o igual a <= (less than or equal to)
* Igual a == (equal to) -recuérdese que son 2 iguales y no solo uno cuando estamos haciendo comparaciones-
* Mayor que > (greater than)
* Mayor o igual a >= (greater than or equal to) 


Estos toman 2 variables y las comparan. Después, en función de la comparación se devolverá un "true" o un "false". Es un atajo a una "función" que podría escribirse así: 

```C++
 bool esIgualA (obj cosa1aComparar, obj cosa2aComparar) {
 //magia
 }

```

Hoy lo que vamos a ver es cómo componemos estas operaciones para tener condiciones más complicadas. 

### Operadores booleanos

Cuando hicimos el ejemplo en la pizarra, tenemos el ejemplo de "meapetecenpatatas" pero puedo tener una decisión más compleja "me apetecen patatas, además tengo la sartén limpia y además tengo tiempo disponible". 

Para ello tenemos 3 operadores booleanos que podemos usar

* El operador y (&&)

El operador y sólo devuelve "true" cuando ambas condiciones devuelven "true". En este caso "me apetecen patatas" Y "tengo sarten" ambas tienen que ser verdad para que funcione. 

Para escribirlo en teclado español de España, se utiliza el shift (la flecha arriba) con el 6 para crear el símbolo &. Es importante saber que se escriben 2. 

* El operador o (||)

El operador o devuelve "true" cuando al menos una de las dos condiciones devuelve "true". Si la condición fuera "me apetecen patatas o tengo sartén", la función se ejecutaría en caso de que ambas fueran verdad pero también en caso de que apetecieran patatas pero no hay sartén o si hay sarten pero no apetecen patatas. 

Para escribirlo hay que pulsar la tecla "Alt GR" y el número 1 en los teclados en español de España.


* El operador no (!)

Este operador niega lo que tenga después de él. Esto vale para hacer comparaciones (en el caso de los ifs) pero también sirve para assignar valores de variables boleanas. 

* Combinación de operadores y paréntesis. 

Es posible combinar estos operadores para realizar complejas decisiones (Si el parámetro de cuanto me gustan las patatas pasa cierto umbral pero luego resulta que la disponibilidad de sarten es diferente a 2 y luego el tiempo disponible es superior a tanto y además inferior a este otro y mi cantidad de hambre llega a determinado nivel).

Es habitual usarlas combinar estas operaciones pero es bueno evitar cosas demasiado complejas precisamente para facilitar la lectura y mantenimiento del código. 

#### Ejemplos de operadores booleanos

Un ejempplo "Quiero que se ejecute algo si tal variable supera 200 pero que sea false la variable deberiaComerPatatas" sería así

```C++
 if ((variableTal > 200) && !deberiaComerPatatas) {
 //cosa
  }
```

Otro ejemplo:

"Deseo que el valor de un sensor (guardado en sensorValue) sea más de 514 y menor que 600 para encender un led"

```C++
 if (sensorValue > 514 && sensorValue < 600) {
   digitalWrite(pinLed, HIGH);
  }
```
Este le hemos utilizado en el caso del piano donde los valores del sensor eran los que teníamos en las resistencias y en vez de valores fijos tenían cierta variación. 


En el caso que tengo yo donde el sensor solo ilumina al llegar a los extremos pero no en el centro, tengo que utilizar el operador "o" de forma obligada. Necesito que el led se active o cuando el sensorX vale muy poco (menor que 100 puse) o cuando vale un valor muy alto (mayor que  923). 

```C++
 if (sensorX < 100 || sensorX > 923) {
   digitalWrite(pinLed, HIGH);
  }
```

A veces se puede hacer 2 condiciones que digan lo mismo. Cuando esto ocurre muchas veces una forma es mucho más fácil de leer que la otra. En este caso yo puedo escribir la misma condición (encender en caso de que llegue a los extremos) así:

```C++
 if (!(sensorX >= 100 && sensorX <= 923)) {
   digitalWrite(pinLed, HIGH);
  }
```

Esto se leería como "que el sensor no esté entre 100 y 923". En algunos programas es puñetero porque esa exclamación a veces es difícil de ver.

También existe la opción de que alguien escriba lo siguiente, suponiendo que vamos a reproducir un tono si el valor del sensor analógico esté entre 505 y 515

```C++
 if (sensorValue > 504) {
   if (sensorValue <516){
       tone(speakerPin,tone,duration);
    }
  }
```

Encadenar ifs hace lo mismo pero, en general es poco recomendable a menos que tengas un else por ahí. Por ejemplo


```C++
 if (sensorValue > 504) {
   if (sensorValue <516){
       tone(speakerPin,tone,duration);
    }
    else{
       digitalWrite(pin, HIGH);
    }
  }
```

En este caso en caso de que el sensorValue valga 516 o más, en vez de activar el altavoz activará un pin. 

De hecho esto lo podríamos aplicar a nuestro snippet del Kill Switch para escribirlo un poco mejor 

Nuestro Checkbutton hace lo siguiente:

```C++
void checkButton() {
  // leemos el botón y lo guardamos en switchtate
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  if (switchState == HIGH) {
    if (isTheButtonBeingPressed == false) {
      shouldLightPins = !shouldLightPins;
      isTheButtonBeingPressed = true;
    }
  }
  else {
    isTheButtonBeingPressed = false;
  }
}
```

Aquí tenemos el mismo problema que antes, tenemos un par de ifs concatenados extraños. Vamos a mejorarlos


```C++
void checkButton() {
  // leemos el botón y lo guardamos en switchtate
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  if (switchState == HIGH && !isTheButtonBeingPressed) {
      shouldLightPins = !shouldLightPins;
      isTheButtonBeingPressed = true;
  }
  else {
    isTheButtonBeingPressed = false;
  }
}
```

Aquí vemos que no es _tan_ complicado pero de primeras podría ser difícil. En especial por toos estos "not" que salen. 

### Fragmento de código de ejemplo con Joystick

No voy a copiar todo el código pero tengo un joystick y 3 leds. Quiero que un led se active cuando el eje x llegue a los extremos y que el segundo led haga lo mismo con el eje y, y por último un tercer led que se encianda cuando pulso el botón. El loop luce algo así como (habiendo declarado todas las variables y haciendo el setup correctamente)

Pongo las variables en castellano

```C++
void loop() {
  //lo leo todo del tiron
  ejeX = analogRead(pinEjeX);
  ejeY = analogRead(pinEjeY);
  estadoBoton = digitalRead(pinBoton);
  //reviso el botón primero
  if (estadoBoton == LOW){
    digitalWrite(pinLedBoton, HIGH);
  }
  else{
    digitalWrite(pinLedBoton, LOW);
  }
  //reviso el eje X
  if (ejeX >= 923 || ejeX <= 100){
    digitalWrite(pinLedEjeX, HIGH);
  }
  else{
    digitalWrite(pinLedEjeX, LOW);
  }
  //reviso el eje Y
  if (ejeY >= 923 || ejeY <= 100){
    digitalWrite(pinLedEjeY, HIGH);
  }
  else{
    digitalWrite(pinLedEjeY, LOW);
  }
}

```

Este programa podría escribirlo como comentaba de otra forma que realiza exactament ela misma función: 

```C++
void loop() {
  //lo leo todo del tiron
  ejeX = analogRead(pinEjeX);
  ejeY = analogRead(pinEjeY);
  estadoBoton = digitalRead(pinBoton);
  //reviso el botón primero
  if (estadoBoton != HIGH){
    digitalWrite(pinLedBoton, HIGH);
  }
  else{
    digitalWrite(pinLedBoton, LOW);
  }
  //reviso el eje X
  if (!(ejeX < 923 && ejeX > 100)){
    digitalWrite(pinLedEjeX, HIGH);
  }
  else{
    digitalWrite(pinLedEjeX, LOW);
  }
  //reviso el eje Y
  if (!(ejeY < 923 && ejeY > 100)){
    digitalWrite(pinLedEjeY, HIGH);
  }
  else{
    digitalWrite(pinLedEjeY, LOW);
  }
}

```

### Tarea

 Por un lado necesitamos utilizar este contenido en alguno de los programas. Puede ser utilizando el Led RGB, puede ser el Joystick. Se puede hacer un programa que tenga las 3 condiciones o se pueden escribir 3 programas que use cada uno uno de los tres operadores (&&, ||, !). Por último hay que actualizar el Kill Switch para dejarlo de forma más limpia. 
 
 Recordad documentar correctamente. 
