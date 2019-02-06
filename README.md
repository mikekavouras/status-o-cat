# HubStatus

![status](https://user-images.githubusercontent.com/627794/52372753-f049c100-2a26-11e9-9259-d60f92e2b7a2.gif)

## Hardware

* [WS2812 LED](https://tinkersphere.com/addressable-rgb-products/732-addressable-rgb-led-sequin-5v-ws2812-neopixel-compatible.html)
* [Particle Photon](https://store.particle.io)
* 220Ω resitor 
* [Octocat](https://github.myshopify.com/products/octocat-figurine)

## How to

**Compile**
```
particle compile photon main.ino neopixel.cpp neopixel.h
```

**Flash**
```
particle flash 3c0036000347343337373739 photon_firmware_*
```

**Clean up**
```
rm photon_firmware_*
```

## Dependencies

https://github.com/technobly/Particle-NeoPixel
