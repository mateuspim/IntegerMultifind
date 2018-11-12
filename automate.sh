#!/bin/bash
clear
echo "\e[1;4;32mPreparing\e[24m git submodules\e[31m"
git submodule update --init --recursive
git submodule foreach git pull origin master
echo "\e[32mSubmodules are \e[7mOK!\e[0m"
echo "\e[1;4;32mCopying\e[24m the helper program"
cp random/random.c random.c
echo "Copy are \e[7mOK!\e[0m"
echo "\e[1;4;32mCompiling\e[24m the helper program"
gcc random.c -o randomGen
echo "Compilation of the helper program was \e[7msuccessful!\e[0m"
echo "\e[1;97mEnter how many input files to generate (number between 1 and 10):\e[0;34m"
read quant
#TODO: create functions to make the code leaner and more comprehensible.
if [ $quant -lt 1 ]
then
	echo "\e[1;32mThe number you entered is invalid"
	sleep 1
	echo "Press any key to exit"
	read key
	clear
	echo "Exiting..."
	echo "\e[7mBye!\e[0m"
	sleep 1
	clear
	exit 0
fi
if [ $quant -gt 10 ]
then
	echo "\e[1;32mThe number you entered is invalid"
	sleep 1
	echo "Press any key to exit"
	read key
	clear
	echo "Exiting..."
	echo "\e[7mBye!\e[0m"
	sleep 1
	clear
	exit 0
fi
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
echo "\e[0;1;97mEnter the number to be searched for in the input files (between 0 and 1000):\e[0;34m"
read num
if [ $num -lt 0 ]
then
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
	exit 0
fi
if [ $num -gt 1000 ]
then
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
	exit 0
fi
echo "\e[1;97mEnter the number of threads to be used (2, 4, 8, or 16):\e[0;34m"
read numThreads
echo "\e[1;97mDo you want to save a copy of the generated data on disk? (y or n)\e[0;34m"
read fileResponse
#TODO: create functions to make the code leaner and more comprehensible.
case $numThreads in
2)
	case $fileResponse in
	'y')
		echo "\e[0m"
		./multifind $numThreads $num *.in > out.txt
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
	;;
	'n')
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
		leep 1
		clear
	;;
	esac
;;
4)
	case $fileResponse in
	'y')
		echo "\e[0m"
		./multifind $numThreads $num *.in > out.txt
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
	;;
	'n')
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
		leep 1
		clear
	;;
	esac
;;
8)
	case $fileResponse in
	'y')
		echo "\e[0m"
		./multifind $numThreads $num *.in > out.txt
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
	;;
	'n')
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
		leep 1
		clear
	;;
	esac
;;
16)
	case $fileResponse in
	'y')
		echo "\e[0m"
		./multifind $numThreads $num *.in > out.txt
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
	;;
	'n')
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
		leep 1
		clear
	;;
	esac
;;
*)
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
;;
esac
