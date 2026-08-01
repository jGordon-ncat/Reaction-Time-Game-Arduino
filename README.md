# Arduino Two Player Reaction Speed Game

## Overview
This project is a two-player reaction time game built using an Arduino Uno. The system uses LEDs, push buttons, and an active buzzer to create a randomized reaction challenge where players compete to press their button first after the signal.
This project demonstrates Embedded C++ programming, digital input/output, hardware integration, and game-state logic on an Arduino.

## Demo Video

Watch the project in action:
[Arduino Reaction Speed Game Demo](https://youtube.com/shorts/YL_dDX6JNeI?feature=share)

## Features
- Two player reaction speed competition 
- LED countdown sequence
- Randomized start delay to prevent anticipation
- Button input detection using Arduino digital pins
- Active Buzzer feedback
- Automatic reset after each round

## Hardware Components
  - Arduino Uno
  - Breadboard
  - LEDs
  - Push Buttons
  - Active Buzzer
  - Resistors
  - Jumper wires

## How It Works
 1. The Arduino begins a countdown sequence using red, yellow and green LEDs.
 2. After the green LED turns on, the Arduino waits for a random amount of time.
 3. The white LEDs signal players to react.
 4. The first player to press their button is detected as the winner.
 5. When a player wins, their white LED stays on while the other player's LED turns off and the buzzer          provides feedback.

## Software Concepts Used
  - Embedded C++ programming
  - Digital input and output
  - INPUT_PULLUP button configuration
  - Conditional statements
  - Boolean state variables
  - Random number generation
  - Timing control

## Project Images

### Finished Build
![Project](images/final-setup.png)

### Circuit Closeup
![Circuit](images/circuit.png)
