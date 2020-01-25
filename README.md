# Steampunk Goggles v1.0
Servo controlled goggles.

## Links

Hackster.io [project write-up](https://www.hackster.io/justin-revelstoke/3d-printed-mechanized-steampunk-iris-goggles-8f17c9)

Thingiverse [steampunk googles](https://www.thingiverse.com/thing:1833286)

Particle [photon maker kit](https://store.particle.io/products/particle-maker-kit)

Particle [power shield](https://store.particle.io/collections/accessories/products/power-shield-with-headers)

Rotary [encoder](https://www.amazon.com/DIYhz-Rotary-Encoder-Digital-Potentiometer/dp/B07D3DF8TK)

Song [repo](https://github.com/robsoncouto/arduino-songs)

## Description

These goggles are a remix of the above thingiverse link, but instead of the spring and 
fishing line they are controlled by independent servos.
The maker kit comes with an ES08AII, a second one will be required. I used an additional
RGB led and push button rotary encoder also.
The AA battery pack powers the servos power shield/lipo battery power everything else.

Solder the female headers onto the prototype board.
The peizo buzzer and 6 male headers (2x3) also are soldered directly on the board.
A red, green, 2 RGB leds in series, the servos and a push button rotary encoder are wired
from the goggles to the board using old ethernet cables and in the case of the servos, 
2 sets of male to female jumpers. No resistors were used with the LED's due to the resistance
in the wires.

Full wiring diagram and additional .stl model files pending.
