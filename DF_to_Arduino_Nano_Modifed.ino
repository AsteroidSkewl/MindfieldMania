//This is a modified version of some code by "munir03125344286". I changed up when the sound is played to when I have a switch flipped.

#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// Use pins 2 and 3 to communicate with DFPlayer Mini
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX 
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX 
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

const int wirePin = 4; 
const int endPin = 5; 

// Create the Player object
DFRobotDFPlayerMini player;

void setup() {

pinMode(wirePin, INPUT);
pinMode(endPin, INPUT);
pinMode(4, INPUT);

  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

void loop() {
  // Start communication with DFPlayer Mini
  if (digitalRead(4)) {
   Serial.println("OK");

    // Set volume to maximum (0 to 30).
    player.volume(30);
    // Play the first MP3 file on the SD card
    player.play(1);
  } else {
    Serial.println("Turn switch on.");
  }
}
 
   }
