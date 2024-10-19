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
    mvector operator+(const mvector &_sum_vector) // 向量加法
    {
        if (this->_size != _sum_vector._size)
        {
            cout << "The size of the two vectors Imcompable!(v+v)" << endl;
            abort();
        }
        mvector _result_of_sum_vector(this->_size);
        for (int i = 0; i < this->_size; i++)
        {
            _result_of_sum_vector.elements[i] = this->elements[i] + _sum_vector.elements[i];
        }
        return _result_of_sum_vector;
    }
    mvector operator-(const mvector &_sum_vector) // 向量减法
    {
        if (this->_size != _sum_vector._size)
        {
            cout << "The size of the two vectors Imcompable!(v-v)" << endl;
            abort();
        }
        mvector _result_of_sum_vector(this->_size);
        for (int i = 0; i < this->_size; i++)
        {
            _result_of_sum_vector.elements[i] = this->elements[i] - _sum_vector.elements[i];
        }
        return _result_of_sum_vector;
    }
    mvector operator*(const double _parameter) // 向量数乘
    {
        mvector _result_of_vec_mul_num(this->_size);
        for (int i = 0; i < this->_size; i++)
        {
            _result_of_vec_mul_num.elements[i] = this->elements[i] * _parameter;
        }
        return _result_of_vec_mul_num;
    }
    double operator*(const mvector &_dot_vector) // 向量点积
    {
        if (this->_size != _dot_vector._size)
        {
            cout << "The size of the two vectors Imcompable!(v*v)" << endl;
            abort();
        }
        double _result_of_dot = 0;
        for (int i = 0; i < _size; i++)
        {
            _result_of_dot += this->elements[i] * _dot_vector.elements[i];
        }
        return _result_of_dot;
    }
};

// member of vector
mvector::mvector(void)
{
    this->elements = NULL;
};
mvector::mvector(int _variable)
{
    this->elements = NULL;
    set_size(_variable);
    for (int i = 0; i < _variable; i++)
    {
        elements[i] = 0;
    }
}
mvector::mvector(const mvector &origin)
{
    this->elements = NULL;
    this->set_size(origin._size);
    for (int i = 0; i < _size; i++)
    {
        this->elements[i] = origin.elements[i];
    }
}
mvector::~mvector(void)
{
    delete elements;
}
void mvector::set_size(int _variable)
{
    _size = _variable;
    if (this->elements != NULL)
        delete this->elements;
    this->elements = new double[_variable];
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
    matrix operator+(const matrix &_sum_matrix) // 矩阵加法
    {
        if (this->row != _sum_matrix.row || this->column != _sum_matrix.column)
        {
            cout << "The size of the two vectors Imcompable!(m+m)" << endl;
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
    matrix operator-(const matrix &_sum_matrix) // 矩阵减法
    {
        if (this->row != _sum_matrix.row || this->column != _sum_matrix.column)
        {
            cout << "The size of the two vectors Imcompable!(m-m)" << endl;
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
    matrix operator*(double _parameter) // 矩阵数乘
    {
        matrix _result_of_mat_mul_num(this->row, this->column);
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                _result_of_mat_mul_num.elements[i][j] = _parameter * this->elements[i][j];
            }
        }
        return _result_of_mat_mul_num;
    }
    matrix operator*(const matrix &origin) // 矩阵乘法
    {
        if (this->row != origin.column)
        {
            cout << "The size of the two matrix are imcompatable!(m*m)" << endl;
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
    mvector operator*(mvector &_mvec) // 矩阵向量乘
    {
        if (column != _mvec._size)
        {
            cout << "The size of the matrix and the vector are Imcompable!(m*v)" << endl;
            abort();
        }
        mvector result_of_mat_vec(_mvec._size);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < _mvec._size; j++)
            {
                result_of_mat_vec.elements[i] += elements[i][j] * _mvec.elements[j];
            }
        }
        return result_of_mat_vec;
    }
};
// member of matrix
matrix::matrix(void) // 默认构造函数
{
    this->elements = NULL;
};
matrix::matrix(int row, int column) // 含参数构造函数
{
    this->elements = NULL;
    set_size(row, column);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            elements[i][j] = 0;
        }
    }
}
matrix::matrix(const matrix &origin) // 拷贝构造函数
{
    this->elements = NULL;
    set_size(origin.row, origin.column);
    for (int i = 0; i < origin.row; i++)
    {
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
void matrix::set_size(int variable_1, int variable_2)
{
    row = variable_1;
    column = variable_2;
    if (this->elements != NULL)
        delete this->elements;
    this->elements = new double *[variable_1];
    for (int i = 0; i < variable_1; i++)
    {
        this->elements[i] = new double[variable_2];
        for (int j = 0; j < variable_2; j++)
        {
            this->elements[i][j] = 0;
        }
    }
}

#endif
