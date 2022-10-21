# Embedded-Drivrers
## Embedded Systems Drivers for ATmega32 & ATmega32L
Atmega32 is an 8-bit AVR microcontroller with 32K bytes In-System Programmable Flash

## Contents
1. [Drivers]()

    - [Analog to Digital Converter (ADC)](https://github.com/1brahimmohamed/Embedded-Drivers/tree/master/ADC)
    - [General Purpose Input/Output (GPIO) (DIO)](https://github.com/1brahimmohamed/Embedded-Drivers/tree/master/GPIOs)
    - [Pluse Width Modulation (PWM)](https://github.com/1brahimmohamed/Embedded-Drivers/tree/master/PWM)
    - [Input Capture Unit (ICU)](https://github.com/1brahimmohamed/Embedded-Drivers/tree/master/ICU)
    - [Liquid Crytsal Display (LCD)](https://github.com/1brahimmohamed/Embedded-Drivers/tree/master/LCD)
    - [Temperature Sensor  LM35](https://github.com/1brahimmohamed/Embedded-Drivers/tree/master/LM%2035%20-%20Temperature%20Sensor)
    - [Ultrasonic HCSR04](https://github.com/1brahimmohamed/Embedded-Drivers/tree/master/HC-SRO4%20-%20Ultrasonic)
    - [DC Motor]()

1. [Atmega32 Features](#atmega32-features)

### Atmega32 Features: 

- High-performance, Low-power AVR® 8-bit Microcontroller
-  Advanced RISC Architecture
    - 131 Powerful Instructions – Most Single-clock Cycle Execution
    - 32 x 8 General Purpose Working Registers
    -  Fully Static Operation
    -  Up to 16 MIPS Throughput at 16 MHz
    -  On-chip 2-cycle Multiplier
-  Nonvolatile Program and Data Memories
    - 32K Bytes of In-System Self-Programmable Flash
    
        Endurance: 10,000 Write/Erase Cycles

    -  Optional Boot Code Section with Independent Lock Bits
        
        In-System Programming by On-chip Boot Program
        True Read-While-Write Operation

    - 1024 Bytes EEPROM
        
        Endurance: 100,000 Write/Erase Cycles
    -  2K Byte Internal SRAM
    -  Programming Lock for Software Security

- JTAG (IEEE std. 1149.1 Compliant) Interface
    - Boundary-scan Capabilities According to the JTAG Standard
    - Extensive On-chip Debug Support
    - Programming of Flash, EEPROM, Fuses, and Lock Bits through the JTAG Interface

- Peripheral Features
    - Two 8-bit Timer/Counters with Separate Prescalers and Compare Modes
    - One 16-bit Timer/Counter with Separate Prescaler, Compare Mode, and Capture
Mode
    - Real Time Counter with Separate Oscillator
    - Four PWM Channels
    - 8-channel, 10-bit ADC
    - 8 Single-ended Channels
    - 7 Differential Channels in TQFP Package Only
    - 2 Differential Channels with Programmable Gain at 1x, 10x, or 200x
    - Byte-oriented Two-wire Serial Interface
    - Programmable Serial USART
    - Master/Slave SPI Serial Interface
    - Programmable Watchdog Timer with Separate On-chip Oscillator
    - On-chip Analog Comparator

- Special Microcontroller Features
    - Power-on Reset and Programmable Brown-out Detection
    - Internal Calibrated RC Oscillator
    - External and Internal Interrupt Sources
    - Six Sleep Modes: Idle, ADC Noise Reduction, Power-save, Power-down, Standby
and Extended Standby
- I/O and Packages
    - 32 Programmable I/O Lines
    - 40-pin PDIP, 44-lead TQFP, and 44-pad MLF
-  Operating Voltages
    -  4.5 - 5.5V for ATmega32
    -  2.7 - 5.5V for ATmega32L
-  Speed Grades
    -  0 - 8 MHz for ATmega32L
    -  0 - 16 MHz for ATmega32
-  Power Consumption at 1 MHz, 3V, 25°C for ATmega32L
    -  Active: 1.1 mA
    -  Idle Mode: 0.35 mA
    -  Power-down Mode: < 1 μA