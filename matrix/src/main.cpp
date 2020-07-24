/**
* @author Apurva Modak
* Created on: 07/23/2020
*/

//========================================================================//
//                   Matrix.                                              //
//========================================================================//
//
//     File Name: main.cpp
//     
//     Application: Matrix
//     
//     Contents: main function
//
//========================================================================//

#include "stopwatch.h"

#include <iostream>

int main() 
{
	StopWatch watch;
    watch.reset();
    std::cout << watch.elapsed() << " ms" << std::endl;
	return 0;
}