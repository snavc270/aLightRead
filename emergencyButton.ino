#include <Adafruit_Thermal.h>
#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial);     // Pass addr to printer constructor

int buttonState = 0;
int previousButtonState = 0;
const int buttonPin = 7;
int randomNum;
boolean firstPressed = false;
int charInt = 0;
int percentage = 100; 
int storyInt = 1; 

//String story[5] = {"hello", "how", "are", "you", "?"};
String story[28] = {"You", "want", "to", "be", "a", "master ", "he", "said", "well",  "you","are", "not", "a", "master ", "That", "took", "me", "down", "a", "peg.", "Seems", "I", "still", "have", "a", "lot", "to", "learn"};
//String story2[30] = {"She", "likes", "it", "She", "is", "like", "me", "Therefore", "I", "might", "like", "it", "She", "is", "like", "me", "She", "likes", "the", "things", "I", "like", "She", "likes", "this", "So", "I", "might", "like", "it"}; 
                    
String story3[28] = {"Into", "how", "small", "a", "place", "the", "word", "judgement", "can", "be", "compressed", "it", "must", "fit", "inside", "the", "brain", "of", "a", "ladybug", "as", "she", 
                  "before", "my", "eyes", "makes", "a", "decision"}; 

String story4[46] = {"Color", "these", "fish", "Cut", "them," "out", "Punch", "a", "hole", "in", "the", "top", "of", "each", "fish", "Put", "a", "ribbon", "through", "all", "the", "holes",
                    "Tie", "these", "fish", "together", "Now", "read", "what", "is", "written", "on", "these", "fish", "Jesus", "is", "a", "friend", "Jesus", "gathers", "friends", "I", "am", "a", "friend", "of", "Jesus"}; 

String story5[10] = {"Under", "all", "this", "dirt", "the", "floor", "is", "really", "very", "clean"}; 
  

void setup() {
  pinMode(7, OUTPUT); digitalWrite(7, LOW);
  // put your setup code here, to run once:
  Serial.begin(19200); 
  mySerial.begin(19200);
  printer.begin();

//  printer.underlineOn();
////  printer.println(F("CHARACTER SET EXAMPLE\n"));
//  printer.underlineOff();

//  printer.println(F("DEFAULT CHARSET & CODE PAGE:"));
//  dump();
//
  // Charset selection alters a few chars in ASCII 0x23-0x7E range.
  printer.setCharset(CHARSET_NORWAY);
  // Code page selects alt symbols for 'upper' ASCII 0x80-0xFF.
  // There's a TON of these, best to check datasheet!
  printer.setCodePage(CODEPAGE_KATAKANA);
//  dump();

  printer.feed(2);
  printer.setDefault(); // Restore printer to defaults

  pinMode(buttonPin, INPUT_PULLUP);

  randomSeed(analogRead(0));

}

void loop() {

  buttonState = digitalRead(buttonPin);

  switch(storyInt){
    case 1:
      percentage = map(pow(charInt, 2), 0, 729, 90, 2); 
      Serial.println(percentage); 
      {
        if (buttonState != previousButtonState) {
          if (buttonState == 1) {
            int randomNum = random(0, 100);
            
           if (randomNum < percentage) {
              printer.println(story[charInt]);          
              if (charInt < 27) {
                charInt ++;
              }
            } else {
              mySerial.println(".");
            }
         }
        }
        if(charInt == 27){
            storyInt = 2; 
       }
      break; 
      }
//      case 2: {
//         if (buttonState != previousButtonState) {
//          if (buttonState == 1) {
//            int randomNum = random(0, 100);
//           
//            if (randomNum < percentage) {
//              printer.print(story2[charInt]); 
//      //        mySerial.println(story[charInt]);
//              if(percentage> 70){
//                percentage -=5; 
//              }else if (percentage <= 70 && percentage > 10){
//                percentage -=3; 
//              }else if (percentage<= 10 && percentage >2){
//                percentage -= 2; 
//              }
//              if (charInt < 28) {
//                charInt ++;
//              }
//            } else {
//              mySerial.println(".");
//            }
//         }
//      }
//      if(charInt == 29){
//            storyInt = 3; 
//         }
//      break; 
//      }

      case 3: {
        percentage = map(pow(charInt, 2), 0, 676, 90, 2); 
        if (buttonState != previousButtonState) {
          if (buttonState == 1) {
            int randomNum = random(0, 100);
           
            if (randomNum < percentage) {
              printer.print(story3[charInt]); 
      //        mySerial.println(story[charInt]);
              if (charInt < 26) {
                charInt ++;
              }
            } else {
              mySerial.println(".");
            }
         }
      }
      if(charInt == 27){
            storyInt = 4; 
      }
      break; 
      }
      case 4: {
        percentage = map(pow(charInt, 2), 0, 1936, 90, 2); 
        if (buttonState != previousButtonState) {
          if (buttonState == 1) {
            int randomNum = random(0, 100);
           
            if (randomNum < percentage) {
              printer.print(story4[charInt]); 
      //        mySerial.println(story[charInt]);
              if (charInt < 44) {
                charInt ++;
              }
            } else {
              mySerial.println(".");
            }
         }
      }
      if(charInt == 45){
            storyInt = 5; 
      }
      break; 
      }

      case 5: {
        percentage = map(pow(charInt, 2), 0, 64, 90, 2); 
        if (buttonState != previousButtonState) {
          if (buttonState == 1) {
            int randomNum = random(0, 100);
           
            if (randomNum < percentage) {
              printer.print(story5[charInt]); 
      //        mySerial.println(story[charInt]);
              if (charInt < 8) {
                charInt ++;
              }
            } else {
              mySerial.println(".");
            }
         }
      }
      if(charInt == 9){
            storyInt = 1; 
      }
      break; 
      }
      default: 
        printer.println("master "); 
        break; 
  }
  
  previousButtonState = buttonState;


}
