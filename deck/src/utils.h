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

#include <chrono>

class Interval
{
public:
    Interval(size_t lo, size_t hi) : low(lo), high(hi) {}
    bool contains(size_t value) const { return low <= value && value < high; }
private:
    size_t low;
    size_t high;
};
inline Interval interval(size_t lo, size_t hi) { return Interval(lo, hi); }


using Clock = std::chrono::high_resolution_clock;
using ms = std::chrono::milliseconds;
class StopWatch 
{
public:
    StopWatch() { reset(); }
    inline void reset() { start = Clock::now(); }
    inline double elapsed() const 
    {
        return std::chrono::duration_cast<ms>(Clock::now() - start).count();
    }
private:
    std::chrono::time_point<Clock> start;
};