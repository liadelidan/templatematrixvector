#ifndef EX3_MATRIX_H
#define EX3_MATRIX_H

#include <vector>
#include <algorithm>
#include <functional>
#include "iostream"
#include "Complex.h"

/**
 * Class Matrix hpp file.
 * Created by Liad Elidan, 203380050, user:sharon1832
 */

template <class T>
class Matrix
{

private:
    // The generic vector the is actually the matrix as a long vector.
    std::vector<T> _matrix;
    // The rows of the matrix.
    unsigned int _rows;
    // The columns of the matrix.
    unsigned int _cols;

public:
    /**
     * Default constructor.
     * exception: std::vector might through it cannot allocate space.
     */
    Matrix();

    /**
     * Constructor that receives the rows and columns of the matrix as ints.
     * exception: std::vector might through it cannot allocate space.
     * exception: std::invalid_argument will through - Matrix sizes should be
     * non-negative if rows < 0 or cols < 0.
     * @param rows, int, the rows of the matrix.
     * @param cols, int, the columns of the matrix.
     */
    Matrix(unsigned int rows, unsigned int cols);

    /**
     * Copy constructor.
     * exception: std::vector might through it cannot allocate space.
     * @param oldMatrix, const Matrix<T>& type matrix.
     */
    Matrix(const Matrix<T>& oldMatrix);

    /**
     * Constructor the receives the rows, columns and cells to be in the matrix.
     * exception: std::vector might through it cannot allocate space.
     * exception: std::invalid_argument will through - Matrix sizes should be
     * non-negative if rows < 0 or cols < 0, and also if the size of the
     * cells is not equal to rows*cols, it will through : "vector is size is not
     * rows*cols" message.
     * @param rows, int, the rows of the matrix.
     * @param cols, int, the columns of the matrix.
     * @param cells, const std::vector<T>&, the cells of the matrix.
     */
    Matrix(unsigned int rows, unsigned int cols, const std::vector<T>& cells);

    /**
     * Overloading "=" between two matrixs.
     * @param other, const Matrix<T>& object.
     * @return Matrix& which is the copy of the Matrix object received.
     */
    Matrix& operator=(const Matrix<T>& other);

    /**
     * Overloading "+" operator between two matrixs, adding between them.
     * exception: bad allocation will be thrown if the resultMatrix,
     * would not be allocated proparly.
     * exception: std::out_of_rance if Matrices not the same size +.
     * @param other, const Matrix<T>& object.
     * @return Matrix object which is the matrix after the "+" operator.
     */
    Matrix operator+(const Matrix<T>& other);

    /**
     * Overloading "-" operator between two matrixs, subtracting them.
     * exception: bad allocation will be thrown if the resultMatrix,
     * would not be allocated proparly.
     * exception: std::out_of_rance if Matrices not the same size -.
     * @param other, const Matrix<T>& object.
     * @return Matrix object which is the matrix after the "-" operator.
     */
    Matrix operator-(const Matrix<T>& other);

    /**
     * Overloading "*" operator between a matrix and a matrix, multiplying them.
     * exception: bad allocation will be thrown if the resultMatrix,
     * would not be allocated proparly.
     * exception: std::out_of_rance if Matrices not fitting size *.
     * @param other, const Matrix<T>& object.
     * @return Matrix object which is the matrix after the "*" operator.
     */
    Matrix operator*(const Matrix<T>& other);

    /**
     * Overloading "==" operator between a matrix and a matrix, check if they are equal.
     * @param other, const Matrix<T>&.
     * @return bool value, true if the matrix are equal, false otherwise.
     */
    bool operator==(const Matrix<T>& other) const;

    /**
     * Overloading "!=" operator between a matrix and a matrix, check if they are un-equal.
     * @param other, const Matrix<T>&.
     * @return bool value, false if the matrix are equal, true otherwise.
     */
    bool operator!=(const Matrix<T>& other) const;

    /**
     * Overloading "()" operator, returns the value in a specific column and row in the matrix.
     * The non-const option.
     * exception: std::out_of_rance if index received out of range.
     * @param specificRow, int, which is the specific row in the matrix.
     * @param specificColumn, int, which is the specific column in the matrix.
     * @return T& generic value which is the value in the specific requested cell in the matrix.
     */
    T& operator()(unsigned int specificRow, unsigned int specificColumn);

    /**
     * Overloading "()" operator, returns the value in a specific column and row in the matrix.
     * The const option.
     * exception: std::out_of_rance if index received out of range.
     * @param specificRow, int, which is the specific row in the matrix.
     * @param specificColumn, int, which is the specific column in the matrix.
     * @return T& generic value which is the value in the specific requested cell in the matrix.
     */
    const T operator()(unsigned int specificRow, unsigned int specificColumn) const;

    /**
     * A method transpose the matrix.
     * exception: std::invalid_argument if matrix is not squared.
     * @return Matrix<T> object, which is the transposed matrix.
     */
    Matrix<T> trans() const;

    /**
     * A method that checks if the matrix is squared.
     * @return bool value, true if the matrix is squared, false otherwise.
     */
    bool isSquareMatrix() const;

    /**
     * Overloading "<<" of a matrix.
     * @param out, std::ostream& object.
     * @param matrix, const Matrix which is the matrix to print.
     * @return
     */
    friend std::ostream& operator<<(std::ostream &out, const Matrix &matrix)
    {
        for (unsigned int i = 0; i < matrix._rows; i++)
        {
            for (unsigned int j = 0; j < matrix._cols ; j++)
            {
                out << matrix(i, j) << '\t';
            }
            out << std::endl;
        }
        return out;
    }

    /**
     * Method that return the number of columns of the matrix.
     * @return int, which is the number of columns of the matrix.
     */
    unsigned int cols() const;

    /**
     * Method that return the number of rows of the matrix.
     * @return int, which is the number of rows of the matrix.
     */
    unsigned int rows() const;

    typedef typename std::vector<T>::const_iterator const_iterator;
    /**
     * Iterator begin.
     * @return const_iterator begin.
     */
    typename Matrix<T>::const_iterator begin() const
    {
        return _matrix.begin();
    }

    /**
     * Iterator end.
     * @return const_iterator end.
     */
    typename Matrix<T>::const_iterator end() const
    {
        return _matrix.end();
    }
};

template <class T>
Matrix<T>::Matrix()
{
    _rows = 1;
    _cols = 1;

    _matrix.push_back(0);
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
{
    if (rows < 0 || cols < 0)
    {
        throw std::invalid_argument("Matrix sizes should be non-negative");
    }
    else
    {
        _rows = rows;
        _cols = cols;

        for(unsigned int i = 0; i < rows*cols ; i++)
        {
            _matrix.push_back(0);
        }
    }
}

template <class T>
Matrix<T>::Matrix(const Matrix& oldMatrix)
{
    _matrix = oldMatrix._matrix;
    _rows = oldMatrix._rows;
    _cols = oldMatrix._cols;
}

template <class T>
Matrix<T>::Matrix(unsigned int rows, unsigned int cols, const std::vector<T>& cells)
{
    if (rows < 0 or cols < 0)
    {
        throw std::invalid_argument("Matrix sizes should be non-negative");
    }
    else
    {
        if (cells.size() != rows*cols)
        {
            throw std::invalid_argument("vector is size is not rows*cols");
        }
        else
        {
            for (auto specificValue : cells)
            {
                _matrix.push_back(specificValue);
            }
            _rows = rows;
            _cols = cols;
        }
    }
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
    _matrix = other._matrix;
    _rows = other._rows;
    _cols = other._cols;

    return *this;
}

template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other)
{
    if (this->_cols != other._cols or this->_rows != other._rows)
    {
        throw std::out_of_range("Matrices not the same size +");
    }
    else
    {
        Matrix resultMatrix = Matrix(other._rows, other._cols);
        std::transform(_matrix.begin(), _matrix.end(), other._matrix.begin(),
                       resultMatrix._matrix.begin(), std::plus<T>());

        return resultMatrix;
    }
}

template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other)
{
    if (this->_cols != other._cols or this->_rows != other._rows)
    {
        throw std::out_of_range("Matrices not the same size -");
    }
    else
    {
        Matrix resultMatrix = Matrix(other._rows, other._cols);
        std::transform(_matrix.begin(), _matrix.end(), other._matrix.begin(),
                       resultMatrix._matrix.begin(), std::minus<T>());

        return resultMatrix;
    }
}

template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other)
{
    if (this->_cols != other._rows)
    {
        throw std::invalid_argument("Matrices not fitting size *");
    }
    else
    {
        Matrix resultMatrix(this->_rows, other._cols);

        for (unsigned int i = 0; i < this->_rows; i++)
        {
            for (unsigned int j = 0; j < other._cols; j++)
            {
                T sum = 0;
                for (unsigned int k = 0; k < this->_cols; k++)
                {
                    sum = sum + (*this)(i, k) * other(k, j);
                }
                resultMatrix(i, j) = sum;
            }
        }

        return resultMatrix;
    }
}

template <class T>
bool Matrix<T>::operator==(const Matrix<T>& other) const
{
    if (this->_matrix == other._matrix && this->_cols == other._cols && this->_rows == other._rows)
    {
        return true;
    }
    return false;
}

template <class T>
bool Matrix<T>::operator!=(const Matrix<T>& other) const
{
    if (this->_matrix != other._matrix || this->_cols != other._cols || this->_rows != other._rows)
    {
        return true;
    }
    return false;
}

template <class T>
T& Matrix<T>::operator()(unsigned int specificRow, unsigned int specificColumn)
{
    if (specificRow < 0 || specificRow >= _rows || specificColumn < 0 || specificColumn >= _cols)
    {
        throw std::out_of_range("index out of range");
    }
    else
    {
        unsigned int index = specificRow*_cols + specificColumn;
        return _matrix.at(index);
    }
}

template <class T>
const T Matrix<T>::operator()(unsigned int specificRow, unsigned int specificColumn) const
{
    if (specificRow < 0 || specificRow >= _rows || specificColumn < 0 || specificColumn >= _cols)
    {
        throw std::out_of_range("index out of range");
    }
    else
    {
        unsigned int index = specificRow*_cols + specificColumn;
        return _matrix.at(index);
    }
}

template <class T>
Matrix<T> Matrix<T>::trans() const
{
    if (this->_cols != this->_rows)
    {
        throw std::invalid_argument("matrix is not squared");
    }
    else
    {
        Matrix resultMatrix = *this;

        for(unsigned int i = 0; i < this->_rows; i++)
        {
            for (unsigned int j = 0; j < this->_cols; j++)
            {
                resultMatrix(i, j) = _matrix.at(j * _cols + i);
            }
        }
        return resultMatrix;
    }
}

template <>
Matrix<Complex> Matrix<Complex>::trans() const
{
    if (this->_cols != this->_rows)
    {
        throw std::invalid_argument("matrix is not squared (Complex)");
    }
    else
    {
        Matrix resultMatrix = *this;

        for(unsigned int i = 0; i < this->_rows; i++)
        {
            for(unsigned int j = 0; j < this->_cols; j++)
            {
                unsigned int index = j * _cols + i;
                resultMatrix(i, j) = _matrix.at(index);
            }
        }

        for (unsigned int j = 0; j < _matrix.size(); j++)
        {
            resultMatrix._matrix.at(j) = resultMatrix._matrix.at(j).conj();
        }

        return resultMatrix;
    }
}

template <class T>
bool Matrix<T>::isSquareMatrix() const
{
    if(_cols == _rows)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
unsigned int Matrix<T>::cols() const
{
    return _cols;
}

template <class T>
unsigned int Matrix<T>::rows() const
{
    return _rows;
}

#endif //EX3_MATRIX_H
