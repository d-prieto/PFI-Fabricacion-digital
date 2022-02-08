# Módulo de Joystick con botón KY-023 Joystick

## Objetivos 

* Utilizar el sensor de joystick para este y otros proyectos. 

* Aprender a conectar sensores al protoboard y al arduino de diferentes formas según nuestras necesidades.

* Utilizar un código de referencia para comprobar que las conexiones son correctas 

* Añadir una funcionalidad extra a través de outputs que ya tenemos (servomotor, motor 9V, leds, ledRGB)

## Módulo de Joystick Qué es y cómo funciona

Este módulo es un pequeño circuito integrado como el resto de los sensores de la caja (es decir, tiene circuitos dentro con más o menos complejidad) y en este caso combina dos potenciómetros y 1 botón. Esta información es remitida a cada uno de los diferentes pines. 

Estamos acostumbrados a los potenciómetros que se giran respecto al eje "vertical" pues estos potenciómeros están "tumbados" 90 grados y cada uno de ellos gira 180 grados en función de cómo se mueva el joystick de un mínimo a un máximo. 

Sí, los mandos de una play funcionan con el mismo principio. 

Este es el esquema:

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Esquema%20JK-023.jpg)

Si el sensor está en el centro los valores de X y de Y estarán en torno a 500, cuando se mueve el joystick suben o bajan. 

En este caso, además, si se presiona el joystick se pulsa un botón (si os fijáis podéis ver el botón). 

### Conexiones del módulo

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick03.JPG)

El módulo tiene varias salidas y con su nombre indican hacia donde deberían ir. Os las enumero:

GND. -> Ground, toma tierra, 0V de potencial eléctrico. 

5V -> Voltaje de 5V. Esto hay que conectarlo a los 5 voltios de potencia para que pueda ser leído correctamente. 

VRx -> Este es el Voltaje Regulado en el eje X horizontal. Hay que conectarlo a un pin analógico para que pueda leerse.  

VRy -> Este es el Voltaje Regulado en el eje Y vertical. Hay que conectarlo a un pin de lectura analógica para que pueda leerse. 

SW -> Switch. Este es el botón. Al estar ya integrado se puede conectar directamente a un pin digital sin tener que incluir la resistencia. Sin embargo este es un botón PULL UP en vez de un botón PULL DOWN (que es lo que hemos realizado en el resto del curso). Esto significa que cuando está sin pulsar leerá 1 (o HIGH) y cuando esté pulsado leerá 0 (o LOW). 

## Conexión para la prueba

He realizado varias conexiones diferentes, utilizando los cables del starter kit y los cables que os dí de extra macho/hembra. Lo importante y común en las tres conexiones es lo siguiente:

* El GND lo llevo al ground del Arduino.

* El 5V lo conecto al 5V del arduino. 

* La conexión a VRx la llevo al pin analógico A0

* La conexión a VRy la llevo al pin analógico A1

* El SW lo conecto al pin 3 (porque el código de prueba usa el pin 3)

### Conexión solo con breadboard 

Os dejo aquí fotos de la conexión usando solo los conectores que tenemos del breadboard. Tendremos que conectar el joystick de tal forma que cada una de sus salidas quede en una fila diferente y conectar cables a esa fila. 


![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick05.JPG)

Conexiones sin el Joystick: 

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick04.JPG)

### Conexión solo con cables macho/hembra

Esta conexión la ventaja que tiene es que no necesita de breadboard con lo cual hay libertad total de dejar el joystick en la mesa y usarlo con cierta libertad. 

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick02.JPG)

### Conexión mixta

Esta conexión mezcla la ventaja de los cables macho/hembra con dejar el breadboard disponible para colocar otras piezas. Esta es la que os recomiendo para futuros proyectos (la prueba con varios leds)

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick01.JPG)

## Código de prueba 

He adaptado este código que podéis ver en este enlace. Transmite la información al PC y necesitaréis el monitor Serie para comprobar que funciona. 

[Código aquí](https://github.com/d-prieto/arduinoCourse/blob/main/joysticktest.ino)

## Tarea 

Crear un hardware diferente que utilice el joystick junto con su código, sacarle foto y subir el código a la documentación correctamente. 

Como ejemplo aquí he añadido 3 leds al Joystick (no he incluído el código para que los alumnos lo hagan por su cuenta on el comportamiento que ellos deseen). 

![](https://raw.githubusercontent.com/d-prieto/arduinoCourse/main/Images/Joystick%20con%203%20leds.JPG)


## Referencia 

Para este articulo he utilizado referencias en este artículo anterior http://cursoarduino.proserquisa.com/2016/10/13/tutorial-25-modulo-joystick-ky-023/
