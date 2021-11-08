# fractol
This project’s goal is to create a small fractal exploration program using Minilibx

The software should offer :
- The Julia set and the Mandelbrot set
- The mouse wheel zooms in and out, almost infinitely (within the limits of the
computer). This is the very principle of fractals
- Use of at least a few colors to show the depth of each fractal. It’s even better
if you hack away on psychedelic effects.
- Parameter gestion. A parameter is passed on the command line to define what type of fractal will be
viewed. If no parameter is provided, or if the parameter is invalid, the program
displays a list of available parameters and exits properly. More parameters must be used for fractal parameters or ignored.
- You must be able to create different Julia set with the parameters of the program.

As for the graphic representation:
-ESC will exit the program.
-The use of images of the minilibX is strongly recommended.

BONUSES

One more different fractal (there are more than a hundred different types of fractals
referenced online).
- The zoom follows the actual mouse position.
- In addition to the zoom: moving with the arrows.
- Make the color range shift.

________________________________________________________________________
## Doc

How to start
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

Endianness
https://www.techtarget.com/searchnetworking/definition/big-endian-and-little-endian

_________________________________________________________________________
## Steps

### Hooks et Event

First we need to found the codes of the corresponding keys.

### Fractals and use of complex numbers

https://youtu.be/Y4ICbYtBGzA

### Optimization

_________________________________________________________________________
## What I learned more

### On flipping endianness in gdb
https://stackoverflow.com/questions/63552401/flipping-endianness-in-gdb
https://stackoverflow.com/questions/8172979/is-it-a-must-to-reverse-byte-order-when-sending-numbers-across-the-network

### Colors
8, 10 and 12 bits