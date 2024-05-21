
#include <iostream>

namespace ilrd
{
    class Matrix
    {
    public:
        Matrix(size_t x = 3, size_t y = 3);
        Matrix(size_t x, size_t y, double **matrix);
        ~Matrix();

        Matrix(const Matrix &other) = default;
        Matrix &operator=(const Matrix &other) = default;

        size_t GetXAmount() const;
        size_t GetYAmount() const;
        double operator()(size_t x, size_t y) const;
        double &operator()(size_t x, size_t y);

        Matrix operator+(const Matrix &other) const;
        Matrix operator*(const Matrix &other) const;
        Matrix Transpose() const;
        void PrintMatrix() const;

    private:
        double **m_matrix;
        size_t x_size;
        size_t y_size;
    };

}

using namespace ilrd;

Matrix::Matrix(size_t x, size_t y) : x_size(x), y_size(y)
{
    try
    {
        m_matrix = new double *[y];
        for (size_t i = 0; i < y; ++i)
        {
            m_matrix[i] = new double[x];
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (size_t i = 0; i < y; ++i)
    {
        for (size_t j = 0; j < x; ++j)
        {
            m_matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(size_t x, size_t y, double **matrix) : y_size(y), x_size(x)
{
    try
    {
        m_matrix = new double *[y];
        for (size_t i = 0; i < y; ++i)
        {
            m_matrix[i] = new double[x];
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (size_t i = 0; i < y; ++i)
    {
        for (size_t j = 0; j < x; ++j)
        {
            m_matrix[i][j] = matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < y_size; ++i)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}

size_t Matrix::GetXAmount() const
{
    return x_size;
}

size_t Matrix::GetYAmount() const
{
    return y_size;
}

double Matrix::operator()(size_t x, size_t y) const
{
    return m_matrix[y][x];
}

double &Matrix::operator()(size_t x, size_t y)
{
    return m_matrix[y][x];
}

Matrix Matrix::operator+(const Matrix &other) const
{
    size_t x = other.GetXAmount();
    size_t y = other.GetYAmount();

    Matrix new_matrix(x, y);

    for (size_t i = 0; i < y; ++i)
    {
        for (size_t j = 0; j < x; ++j)
        {
            new_matrix(i, j) = m_matrix[i][j] + other(i, j);
        }
    }

    return new_matrix;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    size_t x = other.GetXAmount();
    size_t y = other.GetYAmount();

    Matrix new_matrix(x, y);

    for (size_t i = 0; i < y; ++i)
    {
        for (size_t j = 0; j < x; ++j)
        {
            new_matrix(i, j) = m_matrix[i][j] * other(i, j);
        }
    }

    return new_matrix;
}

Matrix Matrix::Transpose() const
{
    size_t x = GetXAmount();
    size_t y = GetYAmount();

    Matrix new_matrix(y, x);

    for (size_t i = 0; i < y; ++i)
    {
        for (size_t j = 0; j < x; ++j)
        {
            new_matrix(j, i) = m_matrix[i][j];
        }
    }
    return new_matrix;
}

void Matrix::PrintMatrix() const
{
    size_t x = GetXAmount();
    size_t y = GetYAmount();

    for (size_t i = 0; i < y; ++i)
    {
        for (size_t j = 0; j < x; ++j)
        {
            std::cout << m_matrix[i][j] << " ";
        }
        std::cout << " " << std::endl;
    }
}

int main()
{
    Matrix mat(4, 4);
    mat.PrintMatrix();
    std::cout << " " << std::endl;
    size_t counter = 0;

    size_t y = 3;
    size_t x = 3;

    double **m_matrix = new double *[y];
    for (size_t i = 0; i < y; ++i)
    {
        m_matrix[i] = new double[x];
    }

    for (size_t i = 0; i < y; ++i)
    {
        for (size_t j = 0; j < x; ++j)
        {
            m_matrix[i][j] = counter;
            ++counter;
        }
    }
    
    Matrix mat1(3, 3, m_matrix);

    for (size_t i = 0; i < y; ++i)
    {
        for (size_t j = 0; j < x; ++j)
        {
            m_matrix[i][j] = counter;
            ++counter;
        }
    }

    Matrix mat2(3, 3, m_matrix);

    Matrix mat3 = mat2 + mat1;
    mat3.PrintMatrix();
    std::cout << " " << std::endl;

    Matrix mat4 = mat2 * mat1;
    mat4.PrintMatrix();
    std::cout << " " << std::endl;

    Matrix mat5 = mat4.Transpose();
    mat5.PrintMatrix();
    for (size_t i = 0; i < y; ++i)
    {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;

    return 0;
}