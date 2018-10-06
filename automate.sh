#!/bin/bash
clear
echo "Preparing git submodules..."
git submodule update --init --recursive
echo "Submodules are OK!"
echo "Copying random.c"
cp random/random.c random.c
echo "Compiling the helper program..."
gcc random.c -o randomGen
echo "Compilation of the helper program was successful!"
echo "Enter how many input files to generate (number between 1 and 10):"
read quant
echo "Generating files..."
./randomGen $quant
echo "Files generated successfully!"
echo "Removing the garbage..."
rm -rf random.c randomGen
echo "Garbage removed successfully!"
echo "Compiling the main program..."
make
make clean
echo "The main program compilation was successful!"
echo "Enter the number of threads to be used (2, 4, 8, or 16):"
read numThreads
echo "Enter the number to be searched for in the input files (between 0 and 1000):"
read num
./multifind $numThreads $num *.in
echo "Removing the garbage..."
rm -rf *.in
echo "Press any key to exit"
read key
echo "Exiting..."
sleep 1
clear
