riffle-ito
=========

The RIFFLE-ito is a lower-functionality and higher cost version of the [Riffle](http://publiclab.org/wiki/riffle) water quality sensor. The Riffle-ito is based on the Atmel328p, and is intended to be compatible with the accessibile and ubiquitous Wiring platform (and, by extension, the Arduino IDE). For a lower-cost, higher-functionalty Riffle that isn't yet compatible with Wiring, please see [here](https://github.com/bgamari/riffle). 

The width and height of the Riffle-ito device allows the device to fit through the mouth of a standard commercially produced plastic water bottle (20 mm). By inserting the Riffle-ito into such a bottle, along with a few AA batteries, and connecting a thermistor and other sensors that poke out through the water bottle cap, a very accessible water quality sensor may be constructed. 

![Alt text](https://raw.githubusercontent.com/p-v-o-s/riffle328/master/RiffleInBottle.png "Optional title")

Details:

- the Riffle-ito requires an [FTDI cable](https://www.adafruit.com/products/284) in order to be reprogrammed (e.g. Adafruit's [FTDI Friend](https://www.adafruit.com/products/284) or SparkFun's ['FTDI Basic Breakout'](https://www.sparkfun.com/products/9716)), which typically costs $15 or so. One cable can be used for several Riffle-ito senso nodes.
- includes a uSD holder, I2C EEPROM flash memory, and a high-precision real time clock (the DS3231) with coin battery backup
- programmable as an "Arduino UNO" board in the Arduino IDE
- runs at 3.3V / 16 MHz
- includes circuit for monitoring battery level
- the board width (18 mm) and height profile (uses right-angle headers) allows device to be inserted through mouth of standard plastic water bottle (one with 20 mm diameter or greater)
- in typical sampling configurations (every 5 minutes), the Riffle-ito can likely run for several weeks (perhaps months) on 3 AA batteries, especially if batteries with low self-discharging rates (like rechargeable Eneloops) are used
- Rough estimate of the total cost of parts that could be used to log temperature in a water bottle (not including shipping, the water bottle, or an FTDI cable): $38;  a detailed cost estimate is [here](https://docs.google.com/spreadsheets/d/1v0O8HmP8-q_kPunHILv5Io3zThpqvPBZZoY3aYnxRDc/edit#gid=0)
- For a diagram of pin locations and optional configurations, please see this [diagram in PDF format](https://github.com/p-v-o-s/riffle328/blob/master/riffleUsage.pdf)
