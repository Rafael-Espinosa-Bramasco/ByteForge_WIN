# Byte Forge
## Install

You just need to download the "byteforge.exe" file and add it to the PATH

## Compile

If you want to compile the app by yourself, you need GCC 64 15.1.0 (i recommend using MSYS2 to install it instead of MinGW Insall Manager)

Once you have the correct compiler, you need to run the following command on your CMD:

    gcc src/main.c -o byteforge

and that's it, you can now add it to the PATH

## How to use

Once you either download it or compile it by yourself and added it to the PATH, yo can call:

    byteforge

and if it return an error, it worked.

Byte forge can recive just 2 arguments: The output file name and the number of bytes to generate.

If you write 2 or more numbers it will result on an error.

    byteforge 256 hola.bin 1026 2356

If you write 2 or more file names (with or without file extentions) it will result on an error.

    byteforge mydata 256 myotherdata.bin

You can call the app with just the number of bytes (the output file name will be data.bin).

    byteforge 1024

You can't call the app with just the output file name, it will result on an error.

    byteforge data.bin