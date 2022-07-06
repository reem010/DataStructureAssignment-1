
#ifndef A1_P3_20200007_20201075_20190235_20200019_MATRIX_H
#define A1_P3_20200007_20201075_20190235_20200019_MATRIX_H
#include <bits/stdc++.h>
using namespace std;
template <class T>
class matrix
{
private:
    int row, col;
    T** mat;
public:
    //default cons
    matrix() {}

    matrix(int _row, int _col)
    {
        row=_row; col=_col;
        mat = new T * [row];
        for (int i = 0; i < row; i++)
            mat[i] = new T[col];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                mat[i][j] = 0;
    }
    //copy constructor
    matrix(const matrix<T>& old) :row(old.col), col(old.row)
    {
        mat = new T * [row];

        for (int i = 0; i < row; i++)
            mat[i] = new T[col];

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                this->mat[i][j] = old.mat[i][j];
    }

    //getters
    int getrow()
    {
        return row;
    }
    int getcol() {
        return col;
    }


    // addition of two matrices
    matrix<T> operator+(matrix<T>& obj)
    {
        matrix<T>newMat(row, col);
        for (int i = 0; i < obj.row; i++)
        {
            for (int j = 0; j < obj.col; j++)
            {
                newMat.mat[i][j] = (mat[i][j] + obj.mat[i][j]);
            }
        }
        return newMat;
    }

    // subtraction of two matrices
    matrix<T> operator-(matrix<T>& obj)
    {
        matrix<T> newMat(row, col);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                newMat.mat[i][j] = (mat[i][j] - obj.mat[i][j]);
            }
        }
        return newMat;
    }
    // multiplication of two matrices
    matrix<T> operator*(matrix<T>& obj)
    {
        matrix<T> newMat(row, obj.col);

        for (int i = 0; i < row; i++)
            for (int j = 0; j < obj.col; j++)
                for (int k = 0; k < col; k++)
                {
                    newMat.mat[i][j] += (mat[i][k] * obj.mat[k][j]);
                }
        return newMat;
    }
    void operator=(const matrix<T>& obj)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                mat[i][j] = obj.mat[i][j];
            }
        }
    }
    // istream for input

    friend istream& operator>> (istream& in, matrix<T>& mat)
    {

        for (int i = 0; i < mat.row; i++)
            for (int j = 0; j < mat.col; j++)
                in >> mat.mat[i][j];

        return in;
    }
    //ostream for output

    friend ostream& operator<< (ostream& out, const matrix<T>& mat)
    {
        for (int i = 0; i < mat.row; i++)
        {
            out << endl;
            for (int j = 0; j < mat.col; j++)
                out << mat.mat[i][j] << "  ";
        }
        out << endl << endl;

        return out;
    }



    void transpose()
    {
        matrix<T> temp(row, col);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                temp.mat[i][j] = mat[i][j];

        for (int i = 0; i < row; i++)delete[] mat[i];
        delete[] mat;

        mat = new T * [col];
        for (int i = 0; i < col; i++)
            mat[i] = new T[row];


        for (int i = 0; i < col; i++)
            for (int j = 0; j < row; j++)
            {
                mat[i][j] = temp.mat[j][i];
            }
        swap(row,col);

    }

    //destructor
    virtual ~matrix()
    {
        for (int i = 0; i < row; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        mat = NULL;
    }
};

#endif //A1_P3_20200007_20201075_20190235_20200019_MATRIX_H
