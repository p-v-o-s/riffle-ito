#include <JeeLib.h>

 ISR(WDT_vect) { Sleepy::watchdogEvent(); }
 
 
 #define outFileName "testDWB9.csv"
 
#define BATTERYPIN A3

 // which analog pin to connect
#define THERMISTORPIN A2       
// resistance at 25 degrees C
#define THERMISTORNOMINAL 10000      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25   
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 10000    

#define DEBUG F

#include <Wire.h>

int samples[NUMSAMPLES];
int led = 6;

#include <SPI.h>
#include <SD.h>

#include <RTClib.h>
#include <RTC_DS3231.h>

RTC_DS3231 RTC;


// On the Ethernet Shield, CS is pin 4. Note that even if it's not
// used as the CS pin, the hardware CS pin (10 on most Arduino boards,
// 53 on the Mega) must be left as an output or the SD library
// functions will not work.
const int chipSelect = 7;    
int SDpower = 5;
int sensorPower = 4;


File dataFile;


 
void setup(void) {
  
  pinMode(SDpower,OUTPUT);
  pinMode(sensorPower,OUTPUT);
  digitalWrite(SDpower,LOW);
  digitalWrite(sensorPower,LOW);
  
   //initialize the SD card
  
  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(SS, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1) ;
  }
  Serial.println("card initialized.");
  
  //shut down the SD and the sensor -- HIGH is off
  //digitalWrite(SDpower,HIGH);
 // digitalWrite(sensorPower,HIGH);
  
  pinMode(led, OUTPUT); 
  
  // for i2c for RTC
  Wire.begin();
  RTC.begin();
  
  Serial.begin(9600);
  //analogReference(EXTERNAL);

  
  
  
  // check on the RTC
  if (! RTC.isrunning()) {
      Serial.println("RTC is NOT running!");
      // following line sets the RTC to the date & time this sketch was compiled
      RTC.adjust(DateTime(__DATE__, __TIME__));
    }
  
    DateTime now = RTC.now();
    DateTime compiled = DateTime(__DATE__, __TIME__);
    if (now.unixtime() < compiled.unixtime()) {
      //Serial.println("RTC is older than compile time!  Updating");
      RTC.adjust(DateTime(__DATE__, __TIME__));
    }
    
  
  //digitalWrite(SDpower,LOW);
  //digitalWrite(sensorPower,LOW);
  
  
   // Open up the file we're going to log to!
  dataFile = SD.open(outFileName, FILE_WRITE);
  if (! dataFile) {
    Serial.println("error opening datalog.txt");
    // Wait forever since we cant write data
    while (1) ;
  }
  
}
 
void loop(void) {
    
  
  DateTime now = RTC.now();
  
  //get the onboard temp from the RTC
  //RTC.forceTempConv(true);  //DS3231 does this every 64 seconds, we are simply testing the function here
    float RTCTemp = RTC.getTempAsFloat();
  
  
   long unixNow = now.unixtime();
   //bSerial.println(now.unixtime());
   
    
  
   
  // delay(1000);
   
  uint8_t i;
  float average;
 
  // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) {
   samples[i] = analogRead(THERMISTORPIN);
   delay(10);
  }
 
  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;
 
  Serial.print("Average analog reading "); 
  Serial.println(average);
 
  // convert the value to resistance
  average = 1023 / average - 1;
  average = SERIESRESISTOR / average;
  Serial.print("Thermistor resistance "); 
  Serial.println(average);
 
  float steinhart;
  steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C
 
  Serial.print("Temperature "); 
  Serial.print(steinhart);
  Serial.println(" *C");
 
 
// get the battery level
int batteryLevel = analogRead(BATTERYPIN);

    
 // write to sd card
 

  
  float temp10=steinhart*10;
  int temp10int=(int) temp10;
  
  int onboardTempInt = (int) RTCTemp*10;
  
  
  // make a string for assembling the data to log:
  String dataString = "";
  
  dataString += String(unixNow);
  dataString +=",";
  
  dataString += onboardTempInt;
  
  //dataString += String(unixNow);
  dataString+=",";
  
    
  //Serial.print(steinhart);
  dataString += String(temp10int);
  dataString+=",";
    
  dataString += String(batteryLevel);
   //no final comma needed
 
  //write the string to the card
  dataFile.println(dataString);


  
  // print to the serial port too:
  Serial.println(dataString);
  
  // The following line will 'save' the file to the SD card after every
  // line of data - this will use more power and slow down how much data
  // you can read but it's safer! 
  // If you want to speed up the system, remove the call to flush() and it
  // will save the file only every 512 bytes - every time a sector on the 
  // SD card is filled with data.
  dataFile.flush();
// dataFile.close(); //<--- may be unnecessary
 
 
 //shut down the SD and the sensor
  //digitalWrite(SDpower,HIGH);
  //digitalWrite(sensorPower,HIGH);
  
//indicate end of session

    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led,LOW);
    
  Sleepy::loseSomeTime(2000); //-- will interfere with serial, so don't use when debugging 
  //delay (2000); // use when debugging -- loseSomeTime does goofy things w/ serial
  
  
}
