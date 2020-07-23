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

template <typename T>
class Interval
{
public:
    Interval(const T& lo, const T& hi) : low(lo), high(hi) {}
    bool contains(const T& value) const { return low <= value && value < high; }
private:
    const T low;
    const T high;
};
template <typename T>
inline Interval<T> interval(const T& lo, const T& hi) { return Interval<T>(lo, hi); }


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