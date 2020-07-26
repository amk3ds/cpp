/**
* @author Apurva Modak
* Created on: 07/23/2020
*/

//========================================================================//
//                   Matrix Project.                                      //
//========================================================================//
//
//     File Name: interval.h
//     
//     Application: 2D Matrix
//     
//     Contents: Utilities
//
//========================================================================//
#pragma once

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
inline Interval<T> interval(T&& lo, T&& hi) { return Interval<T>(lo, hi); }
