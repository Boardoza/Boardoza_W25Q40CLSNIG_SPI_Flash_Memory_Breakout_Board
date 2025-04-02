# Boardoza W25Q40CLSNIG Serial Flash Memory Breakout Board

The **Boardoza W25Q40CLSNIG** is a compact and high-performance **SPI Flash memory breakout board** built around the Winbond W25Q40CLSNIG chip. Offering **4 megabits (512 kilobytes)** of non-volatile storage, it is ideal for embedded applications requiring **code execution, configuration retention, or data logging**.

With support for **SPI communication up to 104 MHz**, this module enables fast and reliable read/write operations, even in timing-critical environments. The board is equipped with power and I/O indicators and is fully compatible with microcontrollers and single-board computers that require external SPI-based flash memory.

## [Click here to purchase!](https://www.ozdisan.com/maker-ve-iot-urunleri/boardoza/boardoza-modulleri/BOARDOZA-W25Q/1206520)

|Front Side|Back Side|
|:---:|:---:|
| ![ Front](./assets/W25Q40CLSNIG%20Front.png)| ![ Back](./assets/W25Q40CLSNIG%20Back.png)|

---

## Key Features

- **4M-bit / 512KB Serial Flash Memory:** Ideal for code or data storage in embedded systems.
- **Fast SPI Interface:** Operates at up to 104 MHz clock speed.
- **Flexible Erase Architecture:** Supports uniform 4KB sectors, and larger 32KB / 64KB block erase operations.
- **Durable & Reliable:** Over 100,000 write/erase cycles with >20 years of data retention.
- **Low Power Consumption:** Optimized for battery-powered systems.
- **Power LED Indicator (D1):** Helps monitor power state visually.

---

## Technical Specifications

**Model:** Winbond W25Q40CLSNIG  
**Input Voltage:** 3.3V – 5V  
**Functions:** Serial Flash Memory  
**Memory Size:** 4 Mbit (512KB)  
**Speed:** Up to 104 MHz  
**Interface:** SPI  
**Endurance:** 100,000+ write/erase cycles  
**Data Retention:** > 20 years  
**Operating Temperature:** -40°C ~ +85°C  
**Board Dimensions:** 20mm x 20mm  

---

## Board Pinout

### ( J1 ) Power and Basic SPI Interface

| Pin Number | Pin Name | Description |
|:---:|:---:|---|
| 1 | 5V   | Positive Power Supply |
| 2 | CLK  | Serial Clock Input (SCK) |
| 3 | DI   | Data Input (IO0 / MOSI) |
| 4 | GND  | Ground |

### ( J2 ) Additional SPI Control Pins

| Pin Number | Pin Name | Description |
|:---:|:---:|---|
| 1 | CS    | Chip Select (Active Low) |
| 2 | DO    | Data Output (IO1 / MISO) |
| 3 | WP    | Write Protect Input (IO2) |
| 4 | HOLD  | Hold Input (IO3) |

---

## Board Dimensions

<img src="./assets/W25Q40CLSNIG Dimension.png" alt="Board Dimensions" width="450"/>

---

## Step Files

[Boardoza W25Q40CLSNIG.step](./assets/W25Q40CLSNIG%20Step.step)

---

## Datasheet

[W25Q40CLSNIG Datasheet.pdf](./assets/W25Q40CLSNIG%20Datasheet.pdf)

---

## Version History

- V1.0.0 – Initial Release

---

## Support

For questions or technical support, please contact **<support@boardoza.com>**

---

## License

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]  

This work is licensed under a [Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].  

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]  

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/  
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png  
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
