#!/bin/bash
clear
echo "Preparing git submodules..."
sleep .1
git submodule update --init --recursive
echo "Submodules are OK!"
sleep .1
echo "Copying random.c"
sleep .1
cp random/random.c random.c
echo "Compiling the helper program..."
sleep .1
gcc random.c -o randomGen
echo "Compilation of the helper program was successful!"
sleep .1
echo "Enter how many input files to generate (number between 1 and 10):"
sleep .1
read quant
echo "Generating files..."
sleep .1
./randomGen $quant
echo "Files generated successfully!"
sleep .1
echo "Removing the garbage..."
sleep .1
rm -rf random.c randomGen
echo "Garbage removed successfully!"
sleep .1
echo "Compiling the main program..."
sleep .1
make
make clean
echo "The main program compilation was successful!"
sleep .1
# continuar a implementação do script
# $quant deve ser usada em um 'for' para fornecer os arquivos
# echo "Enter the number of threads to be used (2, 4, 8, or 16):"
# read numThreads
# echo "Enter the number to be searched for in the input files (between 0 and 1000):"
# read num
# ./multifind $numThreads $num <arquivos gerados>
# echo "Removing the garbage..."
# rm -rf *.in
echo "Press any key to exit"
read key
echo "Exiting..."
sleep 1
clear
