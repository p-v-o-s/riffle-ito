riffle-ito
=========

"Riffle in a Bottle"

A lower-functionality / higher cost / Arduino IDE - compatible [Riffle](http://publiclab.org/wiki/riffle), based on Atmel328p.

- Requires FTDI cable for programming (e.g. Adafruit's "FTDI Friend") -- typically $15
- Includes uSD, flash memory, high-precision real time clock (DS3231) with coin battery backup
- Programmable as "Arduino UNO" in Arduino IDE
- runs at 3.3V and 16 MHz
- includes circuit for monitoring battery level
- board width allows device to be inserted through mouth of standard plastic water bottle (one with 20 mm diameter or greater)
- can run for several weeks (perhaps months) on 3 AA batteries, especially if low self-discharging batteries (like rechargeable Eneloops) are used
- Rough estimate of cost of parts that could be used to log temperature in a water bottle (not including shipping, or FTDI cable): $38 -- cost estimate [here](https://docs.google.com/spreadsheets/d/1v0O8HmP8-q_kPunHILv5Io3zThpqvPBZZoY3aYnxRDc/edit#gid=0)

### Usage

![Alt text](https://raw.githubusercontent.com/p-v-o-s/riffle328/master/RiffleInBottle.png "Optional title")

- For a diagram of pin locations and optional configurations, please see this [diagram in PDF format](https://github.com/p-v-o-s/riffle328/blob/master/riffleUsage.pdf)
