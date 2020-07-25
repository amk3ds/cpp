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

	Matrix() {  Matrix(0, 0); }
	Matrix(size_t rows, size_t cols)
	{
		if (rows != 0 && cols != 0)
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

	Matrix<T> operator+(const Matrix<T>& other);
	Matrix<T> operator-(const Matrix<T>& other);
	Matrix<T> operator*(const Matrix<T>& other);
    Matrix<T> operator+(const T& scalar);
    Matrix<T> operator-(const T& scalar);
    Matrix<T> operator*(const T& scalar);
    Matrix<T> operator/(const T& scalar);

    T& operator()(const size_t& row, const size_t& col) 
    {
    	return data[row * nCol + col];
    }
    const T& operator()(const size_t& row, const size_t& col) const
    {
    	return data[row * nCol + col];
    }
    size_t rows() const {return nRow;}
    size_t cols() const {return nCol;}

private:

	T* data = nullptr;
	size_t nRow = 0;
	size_t nCol = 0;
};
