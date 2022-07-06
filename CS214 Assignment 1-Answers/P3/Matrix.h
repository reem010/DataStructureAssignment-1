#pragma once
#include <iostream>
using namespace std;
template<class T>
class Matrix
{
    T** matrix;
    int rows, cols;
public:
    Matrix() {}
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        matrix = new T * [rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new T[cols];
    }
    Matrix(const Matrix& obj)
    {
        rows = obj.rows; cols = obj.cols;
        matrix = new T * [rows];
        for (int i = 0; i < rows; i++)
            matrix[i] = new T[cols];
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = obj.matrix[i][j];

    }
    friend istream& operator>>(istream& in, Matrix<T>& obj)
    {
        for (int i = 0; i < obj.rows; i++)
            for (int j = 0; j < obj.cols; j++)
                in >> obj.matrix[i][j];
        return in;
    }

    friend ostream& operator<< (ostream& out, const Matrix<T>& obj)
    {
        for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
            {
                out << obj.matrix[i][j] << " ";
            }out << endl;
        }
        return out;
    }

    Matrix<T>operator+(const Matrix<T>& obj)
    {
        Matrix<T>ans(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ans.matrix[i][j] = (matrix[i][j] + obj.matrix[i][j]);
            }
        }
        return  ans;
    }
    Matrix<T>operator-(const Matrix<T>& obj)
    {
        Matrix<T>ans(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ans.matrix[i][j] = (matrix[i][j] - obj.matrix[i][j]);
            }
        }
        return ans;
    }
    Matrix<T>operator*(const Matrix<T>& obj)
    {
        Matrix<T>ans(rows, obj.cols);
        for (int loop1 = 0; loop1 < rows; loop1++)
        {
            for (int loop2 = 0; loop2 < obj.cols; loop2++)
            {
                ans.matrix[loop1][loop2] = 0; // intilizeing by zero

                for (int loop3 = 0; loop3 < cols; loop3++)
                {
                    ans.matrix[loop1][loop2] += (matrix[loop1][loop3] * obj.matrix[loop3][loop2]);
                }
            }
        }
        return ans;
    }

    // this fuction will transpose the matrix when we call it
    void transpose()
    {
        // saving the orginal matrix in temp
        Matrix<T> temp(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.matrix[i][j] = matrix[i][j];

        // deleteing the old matrix (untransposed) to store in it the new matrix(transposed matrix)
        for (int i = 0; i < rows; i++)delete[] matrix[i];
        delete[] matrix;

        // allocating new memory for the trasnposed matrix
        matrix = new T * [cols];
        for (int i = 0; i < cols; i++)
            matrix[i] = new T[rows];

        swap(rows, cols);

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = temp.matrix[j][i];
            }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)delete[] matrix[i];
        delete[] matrix;
    }
};
