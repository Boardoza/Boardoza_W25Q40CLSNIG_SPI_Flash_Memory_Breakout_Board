#ifndef Boardoza_W25Q40CL_h
#define Boardoza_W25Q40CL_h

#include "Arduino.h"
#include <SPI.h>

#define W25Q40 2047

#define WRITE_ENABLE 0x06
#define WRITE_ENABLE_VOLSTATREG 0x50
#define WRITE_DISABLE 0x04
#define READ_STAT_REG1 0x05
#define READ_STAT_REG2 0x35
#define WRITE_STAT_REG 0x01
#define PAGE_PROGRAM 0x02
#define QUAD_PAGE_PROGRAM 0x32
#define SECTOR_ERASE 0x20
#define BLOCK_ERASE32 0x52
#define BLOCK_ERASE64 0xD8
#define CHIP_ERASE 0xC7
#define RELEASE_POWER_DOWN 0xAB
#define POWER_DOWN 0xB9
#define READ_DATA 0x03
#define MANUFECTURER_ID 0x90
#define JEDEC_ID 0x9F

class Boardoza_W25Q40CL {
public:
    Boardoza_W25Q40CL();
    void begin(uint8_t csPin);
    void deactivatePD();
    void waitForCompletion();
    void enableWrite();
    void disableWrite();
    void chipErase();
    byte manufecturerID();
    byte jedecID();
    void lowPower();
    void pageEnd();
    byte readData(uint32_t pageNumber, byte pageAddress);
    void writeData(uint32_t pageNumber, byte pageAddress, byte value);
    void pageWriteData(uint32_t pageNumber, byte pageAddress, byte buffer[],byte count);
    void pageReadData(uint32_t pageNumber, byte pageAddress, byte buffer[], byte count);
private:
    uint8_t _csPin;
    uint32_t _pageNumber = 0;
    uint32_t _pageAddress = 0;
};

#endif