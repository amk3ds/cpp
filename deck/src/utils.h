/**
* @author Apurva Modak
* Created on: 07/15/2020
*/

//========================================================================//
//                   Deck of Cards Project.                               //
//========================================================================//
//
//     File Name: card.h
//     
//     Application: Deck of Cards
//     
//     Contents: Utilities
//
//========================================================================//
#pragma once

class Interval
{
public:
    Interval(size_t lo, size_t hi) : low(lo), high(hi) {}
    bool contains(size_t value) const { return low <= value && value < high; }
private:
    size_t low;
    size_t high;
};

Interval interval(size_t lo, size_t hi) { return Interval(lo, hi); }