/**
* @author Apurva Modak
* Created on: 07/15/2020
*/

//========================================================================//
//                   Deck of Cards Project.                               //
//========================================================================//
//
//     File Name: deck.h
//     
//     Application: Deck of Cards
//     
//     Contents: Deck and related classes
//
//========================================================================/

#include <stdlib.h>
#include <time.h>

#include "utils.h"
#include "deck.h"


Deck::Deck(size_t packs)
{
	nPacks = packs;
	int currentTime = (unsigned int) time(NULL);
	srand(currentTime);
	initialize();
}

Deck::Deck()
{
	Deck(1);
}

Deck::~Deck()
{
	cards.clear();
	nPacks = 0;
}

void Deck::shuffle()
{
  for (int i = 0; i < (int) cards.size(); i++)
  {
	  std::swap(cards[i], cards[rand() % (int) cards.size()]);
  }
}

std::string Deck::summary(Card card) const
{
  std::string rv;
  rv.append(CardUtil::to_string(rank(card)));
  rv.append(" of "); 
  rv.append(CardUtil::to_string(suit(card)));
  rv.append("\n");
  return rv;
}

std::string Deck::summary() const
{
  std::string rv;
  for (auto& cd : cards)
  {
    rv.append(summary(cd));
  }
  return rv;
}

void Deck::initialize()
{
  cards.clear();
  size_t deckSize = nPacks * PACKSIZE;
  cards.reserve(deckSize);
  for (size_t i = 0; i < deckSize; i++)
  {
    cards.push_back(i);
  }
}

Rank Deck::rank(Card card) const
{
  size_t cd = card % PACKSIZE;
  cd = cd % SUITSIZE;
  return static_cast<Rank>(cd);
}

Suit Deck::suit(Card card) const
{
  size_t cd = card % PACKSIZE;
  if (interval(size_t(0), SUITSIZE).contains(cd))
    return Suit::CLUBS;
  else if (interval(SUITSIZE, size_t(2) * SUITSIZE).contains(cd))
    return Suit::DIAMONDS;
  else if (interval(size_t(2) * SUITSIZE, size_t(3) * SUITSIZE).contains(cd))
    return Suit::HEARTS;
  else
    return Suit::SPADES;
}