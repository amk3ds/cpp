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

#include "deck.h"

#include <iostream>

int main() {
    Deck dk(1);
    std::cout << dk.summary() << std::endl;
	return 0;
}