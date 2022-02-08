# Variantes de contador 

## Origen de este documento

Este documento explica las variantes realizadas a partir del trabajo de [Bangwei](https://github.com/chenbangwei/Arduino). En su proyecto (complejo) consistía que presionando un botón se inciiara una secuencia que iniciase varios leds (incluyendo un led RGB) hasta iniciar el motor. 

Este es el hardware 

<image src="https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Variaciones%20LED%20Hardware%2001.jpg" width="500">
  
<image src="https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Variaciones%20LED%20Hardware%2002.jpg" width="500">

He creado esta secuencia de programas, de más sencillo a más complejo para ilustrar el proceso de programación de algo así. 

## Programas

### Parpadeo de prueba

Primero, para revisar si mi hardware estaba bien instalado he colocado un programa de parpadeo (blink) que es [este de aquí.](https://github.com/d-prieto/arduinoCourse/blob/main/Countdown_blink.ino)

### Reloj de arena digital

Una vez he visto que funcionaba he modificado el programa del digital clock para que funcione con el mismo funcionamiento [aquí.](https://github.com/d-prieto/arduinoCourse/blob/main/Countdown_digitaltimer_only_pressed.ino)

### Refactorizando el reloj digital

Después lo he refactorizado (en parte) para poder hacer y analizar el código mejor. Cada vez modifico las variables para que tengan sentido en ese programa. Así que puede haber cambios en los nombres de las variables (porque al hacer cosas diferentes, prefiero cambiarles de nombre a uno que tenga sentido en ese programa).

Esta versión además solo funciona si el botón está pulsado permanentemente (si no, no se encienden los pines). Se puede ver [aquí.](https://github.com/d-prieto/arduinoCourse/blob/main/Countdown_digitaltimer_refactored.ino).

Básicamente se separa checkbutton y updatePins en dos funciones. También tengo que poner la variable de current time como global para que siga en el ámbito de ambas funciones. 

### Añadiendo el Kill Switch

Después he añadido el Kill Switch para que pulsando o dejando de pulsar se active o desactive la secuencia. Este es un _snippet_ que los alumnos han copiado. [Se puede ver acá por ejemplo](https://github.com/Albitah24/arduino/blob/main/snippet_kill_switch.cpp) (en el repositorio de [Alba](https://github.com/Albitah24/arduino/))

El resultado de este Kill Switch es [este](https://github.com/d-prieto/arduinoCourse/blob/main/Countdown_killSwitch). Aquí además incluyo una nueva función para separar también la función de apagado. (turnOffSequence)

### Creando una secuencia de apagado

La siguiente iteración es que al pulsar el botón inicie una secuencia de apagado que inicia donde está encendido el último led encendido hasta el primero. Si se vuelve a pulsar el encendido comienza donde quedó.[Se puede ver aquí](https://github.com/d-prieto/arduinoCourse/blob/main/Countdown_killSwitch_shutdown_sequence.ino)

## Variaciones para les alumnes

A partir de estos se pueden hacer otros programas. 

- Conectar otros outputs a este proyecto, de tal forma que el motor sea el último en encenderse. (Este es el proyecto de Bangwei)
- Utilizar Arrays para cambiar la secuencia de encendido y apagado. [Alba tiene una versión similar que se puede utilizar de referencia](https://github.com/Albitah24/arduino/blob/main/Reloj__de_arena_desordenadoUwU.ino)
- Que la secuencia de encendido apague todo lo que estuviera encendido antes de arrancar. (Este requiere añadir una secuencia de "reinicio" cuando se acaba de pulsar el botón para iniciar
- Que la secuencia de apagado no solo funcionara con KillSwitch sino cuando no pulsas el botón. (Este es mezclar el último que funciona con KillSwitch con alguno de los checkbuttons anteriores)
- Hacer que la velocidad de apagado y encendido sean diferentes.
- Hacer que la velocidad de apagado y encendido no sea idéntica siempre. Que entre la primera y la segunda luz que se encienda haya menos tiempo que entre la siguiente. 

Se pide que el alumno haga una de estas variaciones y la documente. 




