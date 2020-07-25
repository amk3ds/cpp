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
#include <iterator>
#include <iostream>

#include "myexception.h"

template <typename T>
class Matrix
{
public:

	Matrix() {  Matrix(0, 0); }
	Matrix(size_t rows, size_t cols)
	{
		if (rows > 0 && cols > 0)
		{
			nRow = rows;
			nCol = cols;
			data = new T[nRow * nCol]();
		}
	}
	
	virtual ~Matrix()
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

	Matrix<T> operator+(const Matrix<T>& other)
	{
		try
		{
			if (nRow != other.nRow || nCol != other.nCol)
			{
				throw MatrixDimException("Matrix Dimensions do not match!");
			}
			Matrix copy(other.nRow, other.nCol);
			std::transform(
				std::cbegin(data), std::cend(data),
				std::cbegin(other.data),
				std::begin(copy.data),
				[](const int& i, const int& j) {return i + j;});
			return copy;
		}
    	catch (const MatrixDimException& e)
    	{
    		std::cout << e.what() << std::endl;
    	}
	}
	Matrix<T> operator-(const Matrix<T>& other)
	{
		try
		{
			if (nRow != other.nRow || nCol != other.nCol)
			{
				throw MatrixDimException("Matrix Dimensions do not match!");
			}
			Matrix copy(other.nRow, other.nCol);
			std::transform(
				std::cbegin(data), std::cend(data),
				std::cbegin(other.data),
				std::begin(copy.data),
				[](const int& i, const int& j) {return i - j;});
			return copy;
		}
    	catch (const MatrixDimException& e)
    	{
    		std::cout << e.what() << std::endl;
    	}
	}
	Matrix<T> operator*(const Matrix<T>& other)
	{
		try
		{
			if (nCol != other.nRow)
			{
				throw MatrixDimException("Matrix Dimensions do not match!");
			}
			Matrix copy(nRow, other.nCol);
			for (size_t i = 0; i < nRow; i++)
			{
				for (size_t j = 0; j < other.nCol; j++)
				{
					T sum {};
					for (size_t k = 0; k < other.nRow; k++)
					{
						sum += data[i * nCol + k] * other.data[k * other.nCol + j];
					}
					copy.data[i * other.nCol + j] = sum;
				}
			}
			return copy;
		}
    	catch (const MatrixDimException& e)
    	{
    		std::cout << e.what() << std::endl;
    	}
	}

	Matrix<T> operator+(const T& scalar)
	{
		Matrix copy(nRow, nCol);
		std::transform(
			std::cbegin(data), std::cend(data),
			std::begin(copy.data),
			[&](const int& i, const int& j) {return i + scalar;});
		return copy;
	}
	Matrix<T> operator-(const T& scalar)
	{
		Matrix copy(nRow, nCol);
		std::transform(
			std::cbegin(data), std::cend(data),
			std::begin(copy.data),
			[&](const int& i, const int& j) {return i - scalar;});
		return copy;
	}
	Matrix<T> operator*(const T& scalar)
	{
		Matrix copy(nRow, nCol);
		std::transform(
			std::cbegin(data), std::cend(data),
			std::begin(copy.data),
			[&](const int& i, const int& j) {return i * scalar;});
		return copy;
	}
	Matrix<T> operator/(const T& scalar)
	{
		Matrix copy(nRow, nCol);
		std::transform(
			std::cbegin(data), std::cend(data),
			std::begin(copy.data),
			[&](const int& i, const int& j) {return i / scalar;});
		return copy;
    }

    T& operator()(const size_t& row, const size_t& col)
    {
    	try
    	{
    		if (row > nRow || col > nCol)
    		{
    			throw std::out_of_range("Matrix index out of range");
    		}
    		return data[row * nCol + col];
    	}
    	catch (const std::out_of_range& e)
    	{
    		std::cout << e.what() << std::endl;
    	}
    }
    const T& operator()(const size_t& row, const size_t& col) const
    {
    	try
    	{
    		if (row > nRow || col > nCol)
    		{
    			throw std::out_of_range("Matrix index out of range");
    		}
    		return data[row * nCol + col];
    	}
    	catch (const std::out_of_range& e)
    	{
    		std::cout << e.what() << std::endl;
    	}
    }
    
    size_t rows() const {return nRow;}
    size_t cols() const {return nCol;}

private:

	T* data = nullptr;
	size_t nRow = 0;
	size_t nCol = 0;
};
