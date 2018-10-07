#!/bin/bash
clear
echo "\e[1;4;32mPreparing\e[24m git submodules"
git submodule update --init --recursive
echo "Submodules are \e[7mOK!\e[0m"
echo "\e[1;4;32mCopying\e[24m the helper program"
cp random/random.c random.c
echo "Copy are \e[7mOK!\e[0m"
echo "\e[1;4;32mCompiling\e[24m the helper program"
gcc random.c -o randomGen
echo "Compilation of the helper program was \e[7msuccessful!\e[0m"
echo "\e[1;97mEnter how many input files to generate (number between 1 and 10):\e[0;34m"
read quant
echo "\e[1;4;32mGenerating\e[24m files"
./randomGen $quant
echo "Files generated \e[7msuccessfully!\e[0m"
echo "\e[1;4;32mRemoving\e[24m the garbage"
rm -rf random.c randomGen
echo "Garbage removed \e[7msuccessfully!\e[0m"
echo "\e[1;4;32mCompiling\e[24m the main program\e[31m"
make
make clean
echo "\e[32mThe main program compilation was \e[7msuccessful!\e[0m"
echo "\e[1;97mEnter the number of threads to be used (2, 4, 8, or 16):\e[0;34m"
read numThreads
if [ $numThreads != 2 ]; then
	if [ $numThreads != 4 ]; then
		if [ $numThreads != 8 ]; then
			if [ $numThreads != 16 ]; then
				echo "\e[1;32mThe number you entered is invalid"
				sleep 1
				echo "\e[4mRemoving\e[24m the garbage"
				rm -rf *.in
				rm -rf multifind
				echo "\e[1;32mGarbage removed \e[7msuccessfully!\e[0m"
				echo "\e[1;32mPress any key to exit"
				read key
				clear
				echo "Exiting..."
				echo "\e[7mBye!\e[0m"
				sleep 1
				clear
			fi
		fi
	fi
else
	echo "\e[0;1;97mEnter the number to be searched for in the input files (between 0 and 1000):\e[0;34m"
	read num
	echo "\e[0m"
	./multifind $numThreads $num *.in
	echo "\e[1;4;32mRemoving\e[24m the garbage"
	rm -rf *.in
	rm -rf multifind
	echo "Garbage removed \e[7msuccessfully!\e[0m"
	echo "\e[1;32mPress any key to exit"
	read key
	clear
	echo "Exiting..."
	echo "\e[7mBye!\e[0m"
	sleep 1
	clear
fi
