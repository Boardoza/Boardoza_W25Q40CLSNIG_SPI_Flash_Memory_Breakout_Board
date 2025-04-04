#include "Boardoza_W25Q40CL.h"

#define WP 25
#define HOLD 33

Boardoza_W25Q40CL flash;
uint8_t buffer_tx[128];
uint8_t buffer_rx[128];

void setup() {
  Serial.begin(115200);
  while(!Serial) {

  }
  pinMode(WP, OUTPUT);
  pinMode(HOLD, OUTPUT);
  digitalWrite(WP, HIGH);
  digitalWrite(HOLD, HIGH);
  flash.begin(5);
  flash.chipErase();
  flash.lowPower();
}

uint8_t i;

void loop() {
  uint32_t pageAddress = 0; uint32_t pageNumber = 1;
  flash.deactivatePD();
  i = 0;
  buffer_tx[0]=1;
  buffer_tx[1]=2;
  buffer_tx[2]=3;
  buffer_tx[3]=4;
  buffer_tx[4]=5;
  buffer_tx[5]=6;
  buffer_tx[6]=7;
  buffer_tx[7]=8;
  buffer_tx[8]=9;
  while(i < 1) {
    flash.pageWriteData(pageNumber, pageAddress, buffer_tx, 9);
    //flash.writeData(pageNumber, pageAddress, 55);
    flash.pageEnd();
    i++;
    delay(5);
  }
  delay(100);
  pageAddress = 0; pageNumber = 1;
  i = 0;
  flash.pageReadData(pageNumber, pageAddress, buffer_rx,9);

  /*while (i<9)
    {
    Serial.println(buffer_rx[i]);
    i++;
    }*/

   while(i < 9) {
    Serial.println(flash.readData(pageNumber, pageAddress));
    pageAddress++;
    flash.pageEnd();
    i++;
    delay(5);
  }
  pageAddress = 0; pageNumber = 1;
  delay(500);
}