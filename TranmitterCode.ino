#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>


// Define the digital inputs
#define jB1 2  // Joystick button 1
#define jB2 3  // Joystick button 2



RF24 radio(10, 9);   // nRF24L01 (CE, CSN)
const byte address[6] = "00001"; // Address

// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
  byte j1PotX;
  byte j1PotY;
  byte j1Button;
  byte j2PotX;
  byte j2PotY;
  byte j2Button;
};

Data_Package data; //Create a variable with the above structure

void setup() {
  Serial.begin(9600);
  
  // Define the radio communication
  radio.begin();
  radio.openWritingPipe(address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  
  // Activate the Arduino internal pull-up resistors
  pinMode(jB1, INPUT_PULLUP);
  pinMode(jB2, INPUT_PULLUP);

  
  // Set initial default values
  data.j1PotX = 127; // Values from 0 to 255. When Joystick is in resting position, the value is in the middle, or 127. We actually map the pot value from 0 to 1023 to 0 to 255 because that's one BYTE value
  data.j1PotY = 127;
  data.j2PotX = 127;
  data.j2PotY = 127;
  data.j1Button = 1;
  data.j2Button = 1;

}
void loop() {
  // Read all analog inputs and map them to one Byte value
  data.j1PotX = map(analogRead(A1), 0, 1023, 0, 255); // Convert the analog read value from 0 to 1023 into a BYTE value from 0 to 255
  data.j1PotY = map(analogRead(A0), 0, 1023, 0, 255);
  data.j2PotX = map(analogRead(A2), 0, 1023, 0, 255);
  data.j2PotY = map(analogRead(A3), 0, 1023, 0, 255);

  Serial.print("x1 = ");
  Serial.println(data.j1PotX);
  Serial.print("y1 = ");
  Serial.println(data.j1PotY);
  Serial.print("x2 = ");
  Serial.println(data.j2PotX);
  Serial.print("y2 = ");
  Serial.println(data.j2PotY);
  Serial.println("********************");

  // Read all digital inputs
  data.j1Button = digitalRead(jB1);
  data.j2Button = digitalRead(jB2);

  
  radio.write(&data, sizeof(Data_Package));
}
