/**
* @author Apurva Modak
* Created on: 04/02/2020
*/

//========================================================================//
//                   Black Queen Simulator Project.                       //
//========================================================================//
//
//     File Name: deck.h
//     
//     Application: Black Queen Simulation
//     
//     Contents: Deck and related classes
//
//========================================================================//
#pragma once

#include "card.h"

#include <vector>

constexpr size_t NSUITS = 4;
constexpr size_t SUITSIZE = 13;
constexpr size_t PACKSIZE = 52;

using Card = size_t;

class Deck
{
public:
	Deck(size_t nPacks);
	Deck();
	~Deck();

    std::string summary(Card card) const;
    std::string summary() const;

protected:
    virtual void shuffle();

private:
    void initialize();
    Rank rank(Card card) const;
    Suit suit(Card card) const;

private:
    std::vector<Card> cards; 
	size_t nPacks = 0;
};
