#include <LiquidCrystal.h>

// C++ code
//
int distancia = 0;
String vagasLiberadasString = "Vagas Livres   ";
String vagasOcupadasString = "Vagas Ocupadas ";
int vagasLiberadas = 0;
int vagasOcupadas = 0;
int rs = 12, en=11, db4=5, db5=4, db6=3, db7=2;
LiquidCrystal lcd(rs, en, db4, db5, db6, db7);

int distanciaDois = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  lcd.begin(16,2);
  
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  lcd.clear();
  vagasLiberadas = 0;
  vagasOcupadas = 0;
  distanciaDois = 0.01723 * readUltrasonicDistance(0, 1);
  if (distanciaDois < 200) {
    vagasOcupadas = vagasOcupadas + 1;
    digitalWrite(8, HIGH);
    digitalWrite(10, LOW);
  } else {
    vagasLiberadas = vagasLiberadas + 1;
    digitalWrite(8, LOW);
    digitalWrite(10, HIGH);
  }
  distancia = 0.01723 * readUltrasonicDistance(6, 7);
  if (distancia < 200) {
    vagasOcupadas = vagasOcupadas + 1;
    digitalWrite(9, HIGH);
    digitalWrite(13, LOW);
  } else {
    vagasLiberadas = vagasLiberadas + 1;
    digitalWrite(9, LOW);
    digitalWrite(13, HIGH);
  }
  lcd.setCursor(0,0);
  lcd.print(vagasLiberadasString + vagasLiberadas);
  lcd.setCursor(0,1);
  lcd.print(vagasOcupadasString + vagasOcupadas);
  delay(100); // Delay a little bit to improve simulation performance
}