#ifndef MATRIX
#define MATRIX

#include <stdexcept>
#include <iostream>

class MatrixOutOfRange : public std::out_of_range
{
public:
    MatrixOutOfRange() : std::out_of_range("MatrixOutOfRange") {}
};

template <class T, size_t N, size_t M>
class Matrix
{
public:
    T matrix[N][M]{};

    size_t RowsNumber() const
    {
        return N;
    }

    size_t ColumnsNumber() const
    {
        return M;
    }

    const T &operator()(size_t i, size_t j) const
    {
        return matrix[i][j];
    }

    T &operator()(size_t i, size_t j)
    {
        return matrix[i][j];
    }

    T &At(size_t i, size_t j)
    {
        if (j >= M || i >= N)
        {
            throw MatrixOutOfRange();
        }
        return matrix[i][j];
    }

    const T &At(size_t i, size_t j) const
    {
        if (j >= M || i >= N)
        {
            throw MatrixOutOfRange();
        }
        return matrix[i][j];
    }

    Matrix &operator+=(Matrix other)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                matrix[i][j] += other(i, j);
            }
        }
        return *this;
    }

    Matrix &operator-=(Matrix other)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                matrix[i][j] -= other(i, j);
            }
        }
        return *this;
    }

    Matrix &operator*=(const Matrix<T, M, M> &other)
    {
        Matrix temp_matrix{};
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                for (size_t k = 0; k < M; ++k)
                {
                    temp_matrix(i, j) += matrix[i][k] * other(k, j);
                }
            }
        }
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                matrix[i][j] = temp_matrix(i, j);
            }
        }
        return *this;
    }

    Matrix &operator*=(T a)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                matrix[i][j] *= a;
            }
        }
        return *this;
    }

    Matrix &operator/=(T a)
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < M; ++j)
            {
                matrix[i][j] /= a;
            }
        }
        return *this;
    }
};

template <class T, size_t N, size_t M>
Matrix<T, M, N> GetTransposed(Matrix<T, N, M> matrix)
{
    Matrix<T, M, N> transposed{};
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            transposed(j, i) = matrix(i, j);
        }
    }
    return transposed;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator+(Matrix<T, N, M> first, Matrix<T, N, M> second)
{
    Matrix<T, N, M> new_matrix{};
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            new_matrix(i, j) = first(i, j) + second(i, j);
        }
    }
    return new_matrix;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator-(Matrix<T, N, M> first, Matrix<T, N, M> second)
{
    Matrix<T, N, M> new_matrix{};
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            new_matrix(i, j) = first(i, j) - second(i, j);
        }
    }
    return new_matrix;
}

template <class T, size_t N, size_t M, size_t K>
Matrix<T, N, M> operator*(Matrix<T, N, K> first, Matrix<T, K, M> second)
{
    Matrix<T, N, M> new_matrix{};
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            for (size_t k = 0; k < K; ++k)
            {
                new_matrix(i, j) += first(i, k) * second(k, j);
            }
        }
    }
    return new_matrix;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator*(Matrix<T, N, M> matrix, T a)
{
    Matrix<T, N, M> new_matrix = matrix;
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            new_matrix(i, j) *= a;
        }
    }
    return new_matrix;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator*(T a, Matrix<T, N, M> matrix)
{
    return matrix * a;
}

template <class T, size_t N, size_t M>
Matrix<T, N, M> operator/(Matrix<T, N, M> matrix, T a)
{
    Matrix<T, N, M> new_matrix = matrix;
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            new_matrix(i, j) /= a;
        }
    }
    return new_matrix;
}

template <class T, size_t N, size_t M>
bool operator==(Matrix<T, N, M> first, Matrix<T, N, M> second)
{
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            if (first(i, j) != second(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

template <class T, size_t N, size_t M>
bool operator!=(Matrix<T, N, M> first, Matrix<T, N, M> second)
{
    return !(first == second);
}

template <class T, size_t N, size_t M>
std::istream &operator>>(std::istream &operation, Matrix<T, N, M> &matrix)
{
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            operation >> matrix.matrix[i][j];
        }
    }
    return operation;
}

template <class T, size_t N, size_t M>
std::ostream &operator<<(std::ostream &operation, const Matrix<T, N, M> &matrix)
{
    for (size_t i = 0; i < N; ++i)
    {
        for (size_t j = 0; j < M; ++j)
        {
            if (j == M - 1)
            {
                operation << matrix(i, j) << '\n';
            }
            else
            {
                operation << matrix(i, j) << " ";
            }
        }
    }
    return operation;
}

#endif