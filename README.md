riffle-ito
=========

"Riffle in a Bottle"

A lower-functionality / higher cost / version of the [Riffle](http://publiclab.org/wiki/riffle), based on the Atmel328p, intended to be compatible with the highly accessibile Wiring platform (and the Arduino IDE). For a lower-cost, higher-functionalty Riffle that isn't yet compatible with Wiring, please see [here](https://github.com/bgamari/riffle). 

Details of this version:

- the Riffle-ito requires an [FTDI cable](https://www.adafruit.com/products/284) in order to be reprogrammed (e.g. Adafruit's "FTDI Friend"), which typically costs $15 or so. One cable can be used for several Riffle-ito nodes.
- includes uSD, flash memory, and a high-precision real time clock (the DS3231) with coin battery backup
- programmable as an "Arduino UNO" board in the Arduino IDE
- runs at 3.3V, 16 MHz
- includes circuit for monitoring battery level
- board width allows device to be inserted through mouth of standard plastic water bottle (one with 20 mm diameter or greater)
- the device can likely run for several weeks (perhaps months) on 3 AA batteries, especially if low self-discharging batteries (like rechargeable Eneloops) are used
- Rough estimate of cost of parts that could be used to log temperature in a water bottle (not including shipping, or FTDI cable): $38 -- cost estimate [here](https://docs.google.com/spreadsheets/d/1v0O8HmP8-q_kPunHILv5Io3zThpqvPBZZoY3aYnxRDc/edit#gid=0)

### Usage

![Alt text](https://raw.githubusercontent.com/p-v-o-s/riffle328/master/RiffleInBottle.png "Optional title")

- For a diagram of pin locations and optional configurations, please see this [diagram in PDF format](https://github.com/p-v-o-s/riffle328/blob/master/riffleUsage.pdf)
