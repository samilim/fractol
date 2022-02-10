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

YTB
nicsure

How to start
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
https://github.com/qst0/ft_libgfx#getting-started-with-fractol-ft_fractal

Endianness
https://www.techtarget.com/searchnetworking/definition/big-endian-and-little-endian

Fractal algorithms
https://lodev.org/cgtutor/juliamandelbrot.html
https://rosettacode.org/wiki/Julia_set
https://batchloaf.wordpress.com/2016/02/13/example-code-from-presentation-ways-of-seeing-julia-sets/

_________________________________________________________________________
## Steps

### Hooks et Event

First we need to found the codes of the corresponding keys.

### Draw fractals with the use of complex numbers

(FR) Comprendre les nb complexes et leur lien avec le set de Mandelbrot
https://youtu.be/Y4ICbYtBGzA

Understand the logic behind the calculation
https://youtu.be/mBg74yR3ZiY
https://youtu.be/6z7GQewK-Ks

To obtain the magnitude of a complex number, we add the squared real part to the squared imaginary part and calculate the square root of the result.
Ex : 4 + i2 = square root of 20

Now we want to calculte (a + ib²), which is equal to (a² + bi² + 2 * a * bi).
But remember, a complex number² = -1, so that means that (a² + bi² + 2 * a * bi) is equal to (a² + (b² * (-1)) + 2abi) which can be simplified as (a² - b² + 2abi).
That way we have to distinct parts ; (a² - b²) which is the real part and (2abi) the imaginary part.
(a² - b²) + (2abi) is the formula we use to calculate the square of a complex number.
Ex : (4 + 2i)²
= (4² - 2²) + (2*4*2i)
= 12 + 16i

If I want to add or substract complex nb, i just have to add each respective parts
Ex : (4 + 2i) + (3 + 5i)
= 7 + 7i

### Understand the MinilibX

### Optimization

_________________________________________________________________________
## What I learned more

### On flipping endianness in gdb
https://stackoverflow.com/questions/63552401/flipping-endianness-in-gdb
https://stackoverflow.com/questions/8172979/is-it-a-must-to-reverse-byte-order-when-sending-numbers-across-the-network

### Colors
8, 10 and 12 bits
