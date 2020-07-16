/**
* @author Apurva Modak
* Created on: 04/02/2020
*/

//========================================================================//
//                   Deck of Cards Project.                               //
//========================================================================//
//
//     File Name: card.h
//     
//     Application: Deck of Cards
//     
//     Contents: Suit and Rank enums and to_string method
//
//========================================================================//
#pragma once

#include <string>

enum class Suit
{
  CLUBS = 0,
  DIAMONDS,
  HEARTS,
  SPADES
};

enum class Rank
{
  ACE = 0,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING
};

class CardUtil
{
public:
  
  static std::string to_string(Suit s) 
  {
    switch (s) 
    {
    case Suit::CLUBS:    return "Clubs";
    case Suit::DIAMONDS: return "Diamonds";
    case Suit::HEARTS:   return "Hearts";
    case Suit::SPADES:   return "Spades";
    } 
    return {};
  }

  static std::string to_string(Rank s) 
  {
    switch (s) 
    {
    case Rank::ACE:    return "Ace";
    case Rank::TWO:    return "Two";
    case Rank::THREE:  return "Three";
    case Rank::FOUR:   return "Four";
    case Rank::FIVE:   return "Five";
    case Rank::SIX:    return "Six";
    case Rank::SEVEN:  return "Seven";
    case Rank::EIGHT:  return "Eight";
    case Rank::NINE:   return "Nine";
    case Rank::TEN:    return "Ten";
    case Rank::JACK:   return "Jack";
    case Rank::QUEEN:  return "Queen";
    case Rank::KING:   return "King";
    }
    return {};
  }
};