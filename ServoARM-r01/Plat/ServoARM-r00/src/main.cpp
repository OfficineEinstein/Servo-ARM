#include <Arduino.h>

//Gestione Potenziometri
#define NumPot 3
#define Pot1 0
#define Pot2 1
#define Pot3 2

uint8_t Pot[NumPot] = {Pot1, Pot2, Pot3};
uint16_t ARead[NumPot];

//Gestone ADC
#define ADCStep 1023

//Gestione PWM
#define PWMStep 255
#define NumPWMPort 4
#define PWMOut1 3
#define PWMOut2 5
#define PWMOut3 6
#define PWMOut4 9

uint8_t PWMOut[NumPWMPort] = {PWMOut1, PWMOut2, PWMOut3, PWMOut4};
uint16_t PWMVal[NumPWMPort];

void setup() 
{
  Serial.begin(115200);
  Serial.println("Prova Microfono");
}

void loop() 
{
  Serial.print("Potenziometro ");
  for (uint8_t ii=0; ii<NumPot; ii++)
  {
    Serial.print(ii+1);
    Serial.print(" -> ");
    //legge i singoli potenziometri (0-1023),
    //Carica il risultato nell'array ARead[] per successive elaborazioni
    ARead[ii] = analogRead(Pot[ii]);
    //Riproietta il valore letto dalla scala dell'ADC alla scala del PWM
    //e salva il valore per successive elaborazioni
    PWMVal[ii] = map(ARead[ii], 0, ADCStep, 0, PWMStep);
    Serial.print(PWMVal[ii]);
    Serial.print(" -");
    //Setta l'uscita corrispondente al potenziometro corrente
    //con il valore del PWM calcolato
    analogWrite(PWMOut[ii],PWMVal[ii]);
    //Se è il terzo potenziometro setta la quarta uscita allo stesso valore
    if (ii==2)
    {
      ii++;
      analogWrite(PWMOut[ii],PWMVal[ii-1]);
    }
  }
  Serial.println();
  delay(20);
}