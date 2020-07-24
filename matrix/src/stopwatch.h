/**
* @author Apurva Modak
* Created on: 07/23/2020
*/

//========================================================================//
//                   Matrix Project.                                      //
//========================================================================//
//
//     File Name: stopwatch.h
//     
//     Application: 2D Matrix
//     
//     Contents: Utilities
//
//========================================================================//
#pragma once

#include <chrono>

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