# *Class of Matrix* &nbsp; $\scriptsize{{0.0.0}}$

This is the first demo of "Class of 'Matrix and vector'",including identification of matrix and vector and basic calculation in linear algera.

## :star: Feature:
1. :paw_prints:The identification of "matrix" and "vector";
2. :paw_prints:Suppoted calculation: vector addition, vector dot product, matrix addition, matrix multiplication, matrix-vector multiplication.
3. :paw_prints:Easy to use:simple syntax.

## :rocket: How to use
### 1. Initialize the vector/matrix in the following format:
#### Matrix:
```cpp
matrix name_of_matrix (); //No parameter initialization
```

```cpp
matrix name_of_matrix (${number of rows in matrix},{number of columns in matrix}); //Initialization with parameter
```

#### Vector:
```cpp
mvector name_of_vector (); //No parameter initialization
```

```cpp
mvector name_of_vector (${number of numbers in matrix}); //Initialization with parameter
```

(I used **"mvector"** to distinguish it from the C++ **"vector"** container. The "m" means "matrix", so "mvector" represents "vectors that can be operated with matrix")

**PS:** In default model, if you initialize the vactor/matrix with parameter, it will be filled with double "0" not "null".

### 2.Express
You can express the "matrix of math" in the matrix of this code by:

```cpp
matrix example(3,3);
cout << example.elements[0][0];
```

The output is:

```
0
```

The "example.elements" is a "double**" point to an array with 3 rows and 3 columns.

### 3. Assignment
You can directly assign matrix/vector with another matrix/vector like:

```cpp
matrix example1(3,3),example2(3,3);
for(int i=0; i<3; i++)
{
    for(int j=0; j<3; j++)
    {
        example[i][j]=9;
    }
}
example2 = example1;
for(int i=0; i<3; i++)
{
    for(int j=0; j<3; j++)
    {
        cout << example2[i][j] << " ";
    }
    cout << endl;
}
```

The output is:
```
9 9 9
9 9 9
9 9 9
```
### 4. Calculation
#### vector/matrix addition:
```cpp
//set the vector1 and vector2
mvector result = vector1 + vector2;
//other calculation
```
#### vector dot:
```cpp
//set the vector1 and vector2
double result = vector1 * vector2;
//other calculation
```
#### matrix multiplication:
```cpp
//set the matrix1 and matrix2
matrix result = matrix1 * matrix2;
//other calculation
```
#### matrix-vector multiplication:
```cpp
//set the matrix_example and vector_example
mvector result = matrix_example * vector_example;
//other calculation
```

## :blush: Thanks
This is not a mature programm, but a little practice as I am learning C++ and Numerical analysis. To practice writing a class while facilitating the coding of numerical analysis related algorithms later, I decieded to write such a matrix/vector class.So it is not a useful project, please forgive me.

I will be more than grateful if anyone would like to add new feature to this code.

Maybe I will add more function to it in the future.