#include <Arduino.h>

//Déclaration des broches d'entrée/sortie
const int MOTOR2_PIN = 21;
const int s1 =17;
const int buttonPin = 6;     // the number of the pushbutton pin
const int button1Pin = 5;     // the number of the pushbutton pin
const int button2Pin = 8;     // the number of the pushbutton pin
const int electrovanne_pin = 5;// broche de commande de l'électrovanne
const int DISTRIBUTEUR_PIN = 1;
const int VerinAPin = 3;
const int VerinBPin = 4;
const int MOTOR1_PIN = 19;
const int cp = 2;
const int dcy = 22;


int buttonState = 0;         // variable for reading the pushbutton status
int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;         // variable for reading the pushbutton status


void setup() {
  // put your setup code here, to run once:
    pinMode(MOTOR2_PIN, OUTPUT);
    pinMode(s1, INPUT);
    pinMode(MOTOR1_PIN, OUTPUT);
    pinMode(dcy, INPUT);
    pinMode(cp, INPUT);


    pinMode(electrovanne_pin, OUTPUT);
    pinMode(DISTRIBUTEUR_PIN, OUTPUT);
    pinMode(VerinAPin, OUTPUT);
    pinMode(VerinBPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int s1 = digitalRead(s1);
    int dcy = digitalRead(dcy) ;
    int cp = digitalRead(cp);
         
  buttonState = digitalRead(buttonPin);
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) 
  {
    // turn LED on:
    digitalWrite(dcy, HIGH);
  } else {
    // turn LED off:
    digitalWrite(dcy, LOW);
  }
  
  if (button1State == HIGH) {
    // turn LED on:
    digitalWrite(cp, HIGH);
  } else {
    // turn LED off:
    digitalWrite(cp, LOW) ;
  }
  if (button2State == HIGH) {
    // turn LED on:
    digitalWrite(s1, HIGH);
  } else {
    // turn LED off:
    digitalWrite(s1, LOW) ;
  }

     if (dcy == HIGH && cp==HIGH && s1==HIGH )  
     {
    digitalWrite(MOTOR1_PIN, HIGH); // Keep the motor on
     }
     if (dcy == HIGH && cp==HIGH && s1==HIGH )  
     {
    digitalWrite(MOTOR2_PIN, HIGH);
    digitalWrite(electrovanne_pin, HIGH); // Activer l'électrovanne 
    digitalWrite(DISTRIBUTEUR_PIN, HIGH); //Commande pour avancer le vérin
    digitalWrite(VerinAPin, HIGH);
    delay(3000); //Attente de 3 seconde pour que le vérin atteigne la position souhaitée
    digitalWrite(MOTOR2_PIN, LOW);
    digitalWrite(electrovanne_pin, LOW); // Désactiver l'électrovanne
    digitalWrite(DISTRIBUTEUR_PIN, LOW); //Arrêt de la commande
    digitalWrite(VerinAPin, LOW); //Commande pour reculer le vérin
     }
    else {
    digitalWrite(MOTOR1_PIN, LOW);
    digitalWrite(MOTOR2_PIN, LOW);
    digitalWrite(electrovanne_pin, LOW); // Désactiver l'électrovanne
    digitalWrite(DISTRIBUTEUR_PIN, LOW); //Arrêt de la commande
    digitalWrite(VerinAPin, LOW); //Commande pour reculer le vérin
     
    }
    if (s1==HIGH)
    {
    digitalWrite(MOTOR2_PIN, HIGH);
    digitalWrite(electrovanne_pin, HIGH); // Activer l'électrovanne 
    digitalWrite(DISTRIBUTEUR_PIN, HIGH); //Commande pour avancer le vérin
    digitalWrite(VerinAPin, HIGH);
    delay(3000); //Attente de 3 seconde pour que le vérin atteigne la position souhaitée
    digitalWrite(MOTOR2_PIN, LOW);
    digitalWrite(electrovanne_pin, LOW); // Désactiver l'électrovanne
    digitalWrite(DISTRIBUTEUR_PIN, LOW); //Arrêt de la commande
    digitalWrite(VerinAPin, LOW); //Commande pour reculer le vérin
    }
    else 
    {
    digitalWrite(MOTOR2_PIN, LOW);
    digitalWrite(electrovanne_pin, LOW); // Désactiver l'électrovanne
    digitalWrite(DISTRIBUTEUR_PIN, LOW); //Arrêt de la commande
    digitalWrite(VerinAPin, LOW); //Commande pour reculer le vérin 
    }
     
 
}