/**
* @author Apurva Modak
* Created on: 07/23/2020
*/

//========================================================================//
//                   Matrix Project.                                      //
//========================================================================//
//
//     File Name: matrix.h
//     
//     Application: 2D Matrix
//     
//     Contents: Matrix class
//
//========================================================================//
#pragma once

#include <algorithm>

template <typename T>
class Matrix
{
public:
	Matrix() {}

    ~Matrix()
    {
    	delete [] data;
    }

	Matrix(const Matrix& rhs)
	{
		data = new T[rhs.nRow * rhs.nCol];
		nRow = rhs.nRow;
		nCol = rhs.nCol;
		std::copy(rhs.data, rhs.data + (nRow * nCol), data);
	}

	Matrix(Matrix&& rhs) noexcept
	{
		data = std::exchange(rhs.data, nullptr);
		nRow = std::exchange(rhs.nRow, 0);
		nCol = std::exchange(rhs.nCol, 0);
	}

	Matrix& operator=(const Matrix& rhs)
	{
		Matrix copy(rhs);
		copy.swap(*this);
		return *this;
	}

	Matrix& operator=(Matrix&& rhs)
	{
		Matrix copy(std::move(rhs));
		copy.swap(*this);
		return *this;
	}

	void swap(Matrix& rhs) noexcept
	{
		std::swap(data, rhs.data);
		std::swap(nRow, rhs.nRow);
		std::swap(nCol, rhs.nCol);
	}

	friend void swap(Matrix& a, Matrix& b) noexcept
	{
		a.swap(b);
	}

	T* data = nullptr;
    size_t nRow = 0;
    size_t nCol = 0;
};
