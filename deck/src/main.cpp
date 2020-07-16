/**
* @author Apurva Modak
* Created on: 07/15/2020
*/

//========================================================================//
//                   Deck of Cards Project.                               //
//========================================================================//
//
//     File Name: main.cpp
//     
//     Application: Deck of Cards
//     
//     Contents: main function
//
//========================================================================//

#include "utils.h"
#include "deck.h"

#include <iostream>

int main() 
{

	StopWatch watch;
    Deck dk(100);

    watch.reset();
    std::cout << dk.summary() << std::endl;
    std::cout << watch.elapsed() << " ms" << std::endl;

	return 0;

}