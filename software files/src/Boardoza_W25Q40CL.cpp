#include "Boardoza_W25Q40CL.h"

Boardoza_W25Q40CL::Boardoza_W25Q40CL(){}

/**
 * @brief Initializes the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function configures the necessary settings and parameters for using the W25Q40CL Flash Memory.
 * 
 * @param csPin The chip select pin connected to the Flash Memory.
 */
void Boardoza_W25Q40CL::begin(uint8_t csPin) {
    pinMode(csPin, OUTPUT);
    digitalWrite(csPin, HIGH);
    _csPin = csPin;
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE3);
    deactivatePD();
    disableWrite();
}

/**
 * @brief Deactivates the power down mode of the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function deactivates the power down mode of the Flash Memory by sending the appropriate command and waiting for completion.
 */
void Boardoza_W25Q40CL::deactivatePD() {
    digitalWrite(_csPin, LOW);
    SPI.transfer(RELEASE_POWER_DOWN);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
}

/**
 * @brief Waits for the completion of a command on the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function checks the status register of the Flash Memory to wait for the completion of a command.
 */
void Boardoza_W25Q40CL::waitForCompletion() {
    digitalWrite(_csPin, LOW);
    SPI.transfer(READ_STAT_REG1);
    while (bitRead(SPI.transfer(0),0) & 1) {
    }
    digitalWrite(_csPin, HIGH);
}

/**
 * @brief Enables write operations on the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function enables write operations on the Flash Memory by sending the write enable command and waiting for completion.
 */
void Boardoza_W25Q40CL::enableWrite() {
    digitalWrite(_csPin, LOW);
    SPI.transfer(WRITE_ENABLE);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
}

/**
 * @brief Disables write operations on the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function disables write operations on the Flash Memory by sending the write disable command and waiting for completion.
 */
void Boardoza_W25Q40CL::disableWrite() {
    digitalWrite(_csPin, LOW);
    SPI.transfer(WRITE_DISABLE);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
}

/**
 * @brief Performs a chip erase operation on the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function initiates a chip erase operation on the Flash Memory by enabling write operations 
 * sending the chip erase command, waiting for completion, and then disabling write operations.
 */
void Boardoza_W25Q40CL::chipErase() {
    enableWrite();
    digitalWrite(_csPin, LOW);
    SPI.transfer(CHIP_ERASE);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
    disableWrite();
}

/**
 * @brief Retrieves the manufacturer ID of the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function retrieves the manufacturer ID of the Flash Memory by sending the appropriate command and reading the response.
 * 
 * @return The manufacturer ID of the Flash Memory.
 */
byte Boardoza_W25Q40CL::manufecturerID() {
    digitalWrite(_csPin, LOW);
    SPI.transfer(MANUFECTURER_ID);
    SPI.transfer(0);
    SPI.transfer(0);
    SPI.transfer(0);
    byte value = SPI.transfer(0);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
    return value;
}

/**
 * @brief Retrieves the JEDEC ID of the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function retrieves the JEDEC ID of the Flash Memory by sending the appropriate command and reading the response.
 * 
 * @return The JEDEC ID of the Flash Memory.
 */
byte Boardoza_W25Q40CL::jedecID() {
    digitalWrite(_csPin, LOW);
    SPI.transfer(JEDEC_ID);
    SPI.transfer(0);
    byte value = SPI.transfer(0);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
    return value;
}

/**
 * @brief Enters low power mode on the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function puts the Flash Memory into low power mode by sending the appropriate command and waiting for completion.
 */
void Boardoza_W25Q40CL::lowPower() {
    digitalWrite(_csPin, LOW);
    SPI.transfer(POWER_DOWN);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
}

/**
 * @brief Checks if the current page address has reached the end and updates the page number and address if necessary.
 * 
 * This function checks if the current page address has reached the end of a page and updates the page number and address accordingly.
 * If the current page address is greater than 255, the page number is incremented and if the page number exceeds the maximum value, it is reset to 0.
 */
void Boardoza_W25Q40CL::pageEnd() {
    if(_pageAddress > 255) {
        _pageNumber++;
        if(_pageNumber > W25Q40) {
         _pageNumber = 0;
        }
        _pageAddress = 0;
    }
}

/**
 * @brief Reads data from a specific page in the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function reads data from the specified page in the Flash Memory by sending the appropriate command and page information.
 * 
 * @param pageNumber The number of the page to read data from.
 * @param pageAddress The address within the page to read data from.
 * @return The data read from the specified page and address.
 */
byte Boardoza_W25Q40CL::readData(uint32_t pageNumber, byte pageAddress) {
    _pageNumber = pageNumber;
    _pageAddress = pageAddress;
    digitalWrite(_csPin, LOW);
    SPI.transfer(READ_DATA);
    SPI.transfer((_pageNumber >> 8) & 0xFF);
    SPI.transfer((_pageNumber >> 0) & 0xFF);
    SPI.transfer(_pageAddress);
    byte value = SPI.transfer(0);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
    return value;
}

/**
 * @brief Writes data to a specific page and address in the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function writes the specified data to the specified page and address in the Flash Memory by sending the appropriate command and data.
 * 
 * @param pageNumber The number of the page to write data to.
 * @param pageAddress The address within the page to write data to.
 * @param value The data to write to the specified page and address.
 */
void Boardoza_W25Q40CL::writeData(uint32_t pageNumber, byte pageAddress, byte value) {
    _pageNumber = pageNumber;
    _pageAddress = pageAddress;
    enableWrite();
    digitalWrite(_csPin, LOW);
    SPI.transfer(PAGE_PROGRAM);
    SPI.transfer((_pageNumber >> 8) & 0xFF);
    SPI.transfer((_pageNumber >> 0) & 0xFF);
    SPI.transfer(_pageAddress);
    SPI.transfer(value);
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
    disableWrite();
}

/**
 * @brief Writes an array of data to a specific page and address in the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function writes an array of data to the specified page and address in the Flash Memory by sending the appropriate command and data.
 * 
 * @param pageNumber The number of the page to write data to.
 * @param pageAddress The address within the page to start writing data to.
 * @param buffer An array containing the data to write.
 * @param count The number of bytes to write from the buffer.
 */
void Boardoza_W25Q40CL::pageWriteData(uint32_t pageNumber, byte pageAddress, byte buffer[], byte count) {
    _pageNumber = pageNumber;
    _pageAddress = pageAddress;
    enableWrite();
    digitalWrite(_csPin, LOW);
    SPI.transfer(PAGE_PROGRAM);
    SPI.transfer((_pageNumber >> 8) & 0xFF);
    SPI.transfer((_pageNumber >> 0) & 0xFF);
    SPI.transfer(_pageAddress);
 
    for(byte i = 0; i < count; i++) {
        SPI.transfer(buffer[i]);

    }
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
    disableWrite();
}

/**
 * @brief Reads an array of data from a specific page and address in the W25Q40CL Flash Memory on the Boardoza platform.
 * 
 * This function reads an array of data from the specified page and address in the Flash Memory by sending the appropriate command and receiving the data into the buffer.
 * 
 * @param pageNumber The number of the page to read data from.
 * @param pageAddress The address within the page to start reading data from.
 * @param buffer An array to store the read data.
 * @param count The number of bytes to read into the buffer.
 */
void Boardoza_W25Q40CL::pageReadData(uint32_t pageNumber, byte pageAddress, byte buffer[], byte count) {
    _pageNumber = pageNumber;
    _pageAddress = pageAddress;
    digitalWrite(_csPin, LOW);
    SPI.transfer(READ_DATA);
    SPI.transfer((_pageNumber >> 8) & 0xFF);
    SPI.transfer((_pageNumber >> 0) & 0xFF);
    SPI.transfer(_pageAddress);
    for(byte i = 0; i < count; i++) {
        buffer[i]=SPI.transfer(0);
    }
    digitalWrite(_csPin, HIGH);
    waitForCompletion();
}