// Variables that store the pins the jumper wires are connected to.

bool buttonPressed = false;  // Starts as false because neither button has been pressed yet.
// INPUT_PULLUP makes digitalRead(button1) return LOW when the button is pressed.

pinMode(whiteLED1, OUTPUT);  // Configures whiteLED1 as an output so it can be controlled with digitalWrite().

pinMode(button1, INPUT_PULLUP);  // Configures the button to read LOW when pressed and HIGH when released.

randomSeed(analogRead(A0));  // Reads a value from analog pin A0 to seed the random number generator.
// If nothing is connected to A0, the pin picks up small amounts of electrical noise, producing a different value each time.
// Since computers cannot generate truly random numbers on their own, this value provides a more unpredictable starting point
// for Arduino's pseudo-random number generator.


// Sequence of LEDs (red, yellow, green, then both white LEDs).

digitalWrite(redLED, HIGH);  // Turns the red LED on.
digitalWrite(buzzer, HIGH);  // Turns the buzzer on at the same time as the red LED.
delay(100);                  // Keeps the buzzer on for 100 ms.
digitalWrite(buzzer, LOW);   // Turns the buzzer off.
delay(900);                  // Combined with the previous delay, the red LED stays on for 1 second.
digitalWrite(redLED, LOW);   // Turns the red LED off.

digitalWrite(yellowLED, HIGH);  // Turns the yellow LED on.
digitalWrite(buzzer, HIGH);     // Turns the buzzer on at the same time as the yellow LED.
delay(100);                     // Keeps the buzzer on for 100 ms.
digitalWrite(buzzer, LOW);      // Turns the buzzer off.
delay(900);                     // Combined with the previous delay, the yellow LED stays on for 1 second.
digitalWrite(yellowLED, LOW);   // Turns the yellow LED off.

digitalWrite(greenLED, HIGH);  // Turns the green LED on.
digitalWrite(buzzer, HIGH);    // Turns the buzzer on at the same time as the green LED.
delay(100);                    // Keeps the buzzer on for 100 ms.
digitalWrite(buzzer, LOW);     // Turns the buzzer off.
delay(900);                    // Combined with the previous delay, the green LED stays on for 1 second.
delay(random(900, 4901));      // Waits a random time between 900 ms and 4900 ms.
// This random delay prevents players from predicting when they should press the button, making the reaction test fair.
digitalWrite(greenLED, LOW);   // Turns the green LED off.

// Turn both white LEDs on at the same time.
digitalWrite(whiteLED1, HIGH);
digitalWrite(whiteLED2, HIGH);
delay(1000);

// Turn both white LEDs off at the same time.
digitalWrite(whiteLED1, LOW);
digitalWrite(whiteLED2, LOW);

while (buttonPressed == false) {  // Continues until either player presses a button.

  // Keep both white LEDs on while waiting for a button press.
  digitalWrite(whiteLED1, HIGH);
  digitalWrite(whiteLED2, HIGH);

  if (digitalRead(button1) == LOW) {  // INPUT_PULLUP causes the button to read LOW when pressed.
    buttonPressed = true;             // Stops the loop and starts the end-of-game sequence.
    digitalWrite(whiteLED2, LOW);     // Turns off the opposite player's LED to indicate Player 1 won.
  }
  else if (digitalRead(button2) == LOW) {  // Checks whether Player 2 pressed their button.
    buttonPressed = true;
    digitalWrite(whiteLED1, LOW);          // Turns off the opposite player's LED to indicate Player 2 won.
  }
}

// End-of-game sequence.
digitalWrite(buzzer, HIGH);
delay(500);   // Sounds the buzzer for 500 ms.
digitalWrite(buzzer, LOW);
delay(2500);  // Keeps the winning LED on for a total of 3 seconds.

// Turn both white LEDs off.
digitalWrite(whiteLED1, LOW);
digitalWrite(whiteLED2, LOW);

buttonPressed = false;  // Reset the button state so the game can be played again.
