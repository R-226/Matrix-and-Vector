#ifndef LINEAR_ALGEBRA_HPP
#define LINEAR_ALGEBRA_HPP
#include <iostream>
using namespace std;

// vector
class mvector
{
private:
protected:
public:
    int _size;
    double *elements;
    mvector(void);                  // 默认构造函数
    mvector(int _variable);         // 含参数构造函数
    mvector(const mvector &origin); // 拷贝构造函数
    ~mvector(void);                 // 析构函数
    void set_size(int _variable);
    int get_size(void);
    mvector sum_vector(mvector &_sum_vector);
    double vec_dot(mvector _dot_vector);
    mvector &operator=(const mvector &origin) // 向量赋值
    {
        double *temp_num = new double[origin._size];
        for (int i = 0; i < origin._size; i++)
            temp_num[i] = origin.elements[i];
        delete this->elements;
        this->elements = temp_num;
        this->_size = origin._size;
        return *this;
    }
    mvector operator+(mvector &_sum_vector) // 向量加法
    {
        mvector _result_of_sum_vector(this->_size);
        for (int i = 0; i < this->_size; i++)
        {
            _result_of_sum_vector.elements[i] = this->elements[i] + _sum_vector.elements[i];
        }
        return _result_of_sum_vector;
    }
    mvector operator-(mvector &_sum_vector) // 向量减法
    {
        mvector _result_of_sum_vector(this->_size);
        for (int i = 0; i < this->_size; i++)
        {
            _result_of_sum_vector.elements[i] = this->elements[i] - _sum_vector.elements[i];
        }
        return _result_of_sum_vector;
    }
    double operator*(mvector _dot_vector) // 向量点积
    {
        double _result_of_dot = 0;
        for (int i = 0; i < _size; i++)
        {
            _result_of_dot += this->elements[i] * _dot_vector.elements[i];
        }
        return _result_of_dot;
    }
};

// member of vector
mvector::mvector(void) {};
mvector::mvector(int _variable)
{
    set_size(_variable);
    elements = new double[_variable];
    for (int i = 0; i < _variable; i++)
    {
        elements[i] = 0;
    }
}
mvector::mvector(const mvector &origin)
{
    set_size(origin._size);
    elements = new double[_size];
    for (int i = 0; i < _size; i++)
    {
        elements[i] = origin.elements[i];
    }
}
mvector::~mvector(void)
{
    delete elements;
}
void mvector::set_size(int _variable)
{
    _size = _variable;
}
int mvector::get_size(void)
{
    return _size;
}

// matrix
class matrix
{
private:
protected:
public:
    int row;
    int column;
    double **elements;
    matrix(void);                 // 默认构造函数
    matrix(int row, int column);  // 构造函数
    matrix(const matrix &origin); // 拷贝构造函数
    ~matrix(void);                // 析构函数
    void set_size(int variable_1, int variable_2);
    int get_row(void);
    int get_column(void);
    matrix sum_matrix(matrix &_sum_matrix);
    mvector mat_mul_vec(mvector &_mvec);
    matrix &operator=(const matrix &origin) // 矩阵赋值
    {
        double **temp_num = new double *[origin.row];
        for (int i = 0; i < origin.row; i++)
        {
            temp_num[i] = new double[origin.column];
            for (int j = 0; j < origin.column; j++)
            {
                temp_num[i][j] = origin.elements[i][j];
            }
        }
        this->elements = temp_num;
        this->row = origin.row;
        this->column = origin.column;
        return *this;
    }
    matrix operator+(matrix &_sum_matrix) // 矩阵加法
    {
        if (this->row != _sum_matrix.row || this->column != _sum_matrix.column)
        {
            cout << "This size of the two matrix are imcompatable!(sum)" << endl;
            abort();
        }
        matrix _result_of_sum_matrix(row, column);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                _result_of_sum_matrix.elements[i][j] = this->elements[i][j] + _sum_matrix.elements[i][j];
            }
        }
        return _result_of_sum_matrix;
    }
    matrix operator-(matrix &_sum_matrix) // 矩阵减法
    {
        if (this->row != _sum_matrix.row || this->column != _sum_matrix.column)
        {
            cout << "This size of the two matrix are imcompatable!(sum)" << endl;
            abort();
        }
        matrix _result_of_sum_matrix(row, column);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                _result_of_sum_matrix.elements[i][j] = this->elements[i][j] - _sum_matrix.elements[i][j];
            }
        }
        return _result_of_sum_matrix;
    }
    matrix operator*(const matrix &origin) // 矩阵乘法
    {
        if (this->row != origin.column)
        {
            cout << "The size of the two matrix are imcompatable!(mul)" << endl;
            abort();
        }
        matrix temp_matrix(this->row, origin.column);
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                double temp_sum = 0;
                for (int k = 0; k < origin.row; k++)
                {
                    temp_matrix.elements[i][j] += this->elements[i][k] * origin.elements[k][j];
                }
            }
        }
        return temp_matrix;
    }
};
// member of matrix
matrix::matrix(void) {};            // 默认构造函数
matrix::matrix(int row, int column) // 含参数构造函数
{
    set_size(row, column);
    elements = new double *[row];
    for (int i = 0; i < row; i++)
    {
        elements[i] = new double[column];
        for (int j = 0; j < column; j++)
        {
            elements[i][j] = 0;
        }
    }
}
matrix::matrix(const matrix &origin) // 拷贝构造函数
{
    set_size(origin.row, origin.column);
    elements = new double *[origin.row];
    for (int i = 0; i < origin.row; i++)
    {
        elements[i] = new double[origin.column];
        for (int j = 0; j < origin.column; j++)
        {
            elements[i][j] = origin.elements[i][j];
        }
    }
}
matrix::~matrix(void) // 析构函数
{
    for (int i = 0; i < row; i++)
        delete elements[i];
    delete elements;
}
int matrix::get_row(void)
{
    return row;
}
int matrix::get_column(void)
{
    return column;
}
void matrix::set_size(int variable_1, int variable_2)
{
    row = variable_1;
    column = variable_2;
}

mvector matrix::mat_mul_vec(mvector &_mvec)
{
    if (column != _mvec.get_size())
    {
        cout << "The size of the matrix and the vector are Imcompable!" << endl;
        abort();
    }
    mvector result_of_mat_vec(_mvec.get_size());
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < _mvec.get_size(); j++)
        {
            result_of_mat_vec.elements[i] += elements[i][j] * _mvec.elements[j];
        }
    }
    return result_of_mat_vec;
}

#endif
