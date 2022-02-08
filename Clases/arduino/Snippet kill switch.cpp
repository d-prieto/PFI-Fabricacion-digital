//Colocar en la sección de variables globales.

int switchState = 0;
bool isTheButtonBeingPressed = false;
bool play = false;

int buttonPin = 2;


// Incluir dentro del setup.
pinMode(buttonPin, INPUT);


//Sustituir loop.

void loop() {
  checkButton();
  if (play) {
  // incluir aquí el código a ejecutar   
  }
}


//Incluir después del loop

//La función de checkbutton revisa el botón en el pinbutton y si está siendo pulsada solo por primera vez cambia el sentido de !play
void checkButton(){
  switchState = digitalRead(buttonPin);
  if (switchState == HIGH && !isTheButtonBeingPressed){
    play = !play;
    isTheButtonBeingPressed = true;
  }
  
  if (switchState == LOW)
  {
  isTheButtonBeingPressed = false;
  }

}
