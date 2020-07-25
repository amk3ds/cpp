/**
* @author Apurva Modak
* Created on: 07/23/2020
*/

//========================================================================//
//                   Matrix Project.                                      //
//========================================================================//
//
//     File Name: myexception.h
//     
//     Application: 2D Matrix
//     
//     Contents: Utilities
//
//========================================================================//

#pragma once

#include <string>
#include <exception>

class MyException : public std::exception 
{
public:
    explicit MyException(const std::string& message);
    virtual const char* what() const throw() 
    {
    	return mMsg.c_str();
    }

private:
	std::string mMsg;
};


MyException::MyException(const std::string& message) : mMsg(message) 
{

}

class MatrixDimException : public MyException
{
	explicit MatrixDimException(const std::string& message) 
	    : MyException { message }
	{

	}
};