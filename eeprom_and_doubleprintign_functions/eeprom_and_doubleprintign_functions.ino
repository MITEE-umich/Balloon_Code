#include <EEPROM.h>
#include "EEPROMAnything.h"
#include <stdio.h>

int a = 0;
int num_bytes_eeprom = 1024;

void setup()
{
  Serial.begin(9600);
}

int count = 0;
double dub = 5.390;

void loop()
{
//  if(count < 1) {
////     EEPROM_writeAnything(0, dub);
//     double val = EEPROM_readAnything(0, dub);
//     printDouble(dub,100);
//     Serial.println(count);
////     printDouble(val,1000);
//  }
//  count = count + 1;
//  Serial.println(count);
//  delay(1000);


}

void read_full_eeprom()
{
   for(int i = 0; i < num_bytes_eeprom; i++) {
    int value = EEPROM.read(i);
    Serial.println(value);
  } 
}

void zero_out_eeprom()
{
   for(int i = 0; i < num_bytes_eeprom; i++) {
      EEPROM.write(i, 0);
  } 
  read_full_eeprom();
}

void printDouble(double val, unsigned int precision){
// prints val with number of decimal places determine by precision
// NOTE: precision is 1 followed by the number of zeros for the desired number of decimial places
// example: printDouble( 3.1415, 100); // prints 3.14 (two decimal places)

    Serial.print (int(val));  //prints the int part
    Serial.print("."); // print the decimal point
    unsigned int frac;
    if(val >= 0)
      frac = (val - int(val)) * precision;
    else
       frac = (int(val)- val ) * precision;
    int frac1 = frac;
    while( frac1 /= 10 )
        precision /= 10;
    precision /= 10;
    while(  precision /= 10)
        Serial.print("0");

    Serial.println(frac,DEC) ;
}






