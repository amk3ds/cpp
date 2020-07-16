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
//     Contents: Suit and Rank enums and to_string method
//
//========================================================================//

public class Stopwatch {

    /**
     * Start time.
     */
    private final long start;

    /**
     * Construct to set current time in milliseconds to start time.
     */
    public Stopwatch() {
        start = System.currentTimeMillis();
    }

    /**
     * Returns time (in milliseconds) since this object was created.
     * @return time in milliseconds
     */
    public double elapsedTime() {
        long now = System.currentTimeMillis();
        return now - start;
    }

}