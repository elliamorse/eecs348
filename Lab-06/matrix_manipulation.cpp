/*
written by Ellia Morse, debugged using ChatGPT
EECS 348 Oct 18 2023


Problem Description

You are tasked with implementing a C++ program that performs various operations on square matrices using functions and arrays (no classes or objects yet). 
Your program should read matrix data from a file, perform matrix operations, and output the results. The max size of the square matrices should be defined as a static constant 100 but the actual size of the square matrix will be the first line of data, and it will less than or equal to 100. For this assignment, you will write the following functions:

1. Read values from a file into a matrix:
Create a function to read matrix data from a specified file and store it in a 2D array.

2. Print a matrix:
Implement a function to display a matrix in a user-friendly format. The matrix values should nicely align in a column.

3. Add two matrices and place the result in a third matrix; print the result:
Create a function that adds two matrices of the same size and stores the result in a third matrix. Display the resulting matrix.

4. Multiply two matrices and place the result in a third matrix; print the result:
Implement a function for matrix multiplication (matrix1 * matrix2 = result_matrix). Display the resulting matrix.

5. Subtract the second matrix from the first matrix and place the result in a third matrix; print the result:
Develop a function to subtract one matrix from another and store the result in a third matrix. Display the resulting matrix.

Constraints
The matrices are square matrices (NxN), where N is defined as a static constant. 
The input matrices are read from a file named "matrix_input.txt". The output matrices are displayed on the console.
Place only the functional prototypes before the main function. Place the function bodies below the main program.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Provided size cap
const int MAX_SIZE = 100;

//Function that reads matrixs from a file
void readMatrixFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int &size, const string &fileName) {
    ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        inputFile >> size;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                inputFile >> matrixA[i][j];
            }
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                inputFile >> matrixB[i][j];
            }
        }

        inputFile.close();
    } else {
        //couldn't open the file
        cerr << "Unable to open file";
    }
}

//Function to print matrixs
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size, const string &matrixName) {
    //Print the matrix name
    cout << matrixName << ":\n";
    //Print each row of the matrix
    for (int i = 0; i < size; ++i) {
        //Print each element in the row
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        //Move to the next line
        cout << endl;
    }
}

//Function to add two matrixs
void addMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int matrixSum[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) { //double for loops
        for (int j = 0; j < size; ++j) {
            matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

//Function to multiply two matrixs
void multiplyMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int matrixProduct[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrixProduct[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                matrixProduct[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

//Function to subtract two matrixs
void subtractMatrices(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int matrixDiff[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrixDiff[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

//Main function
int main() {
    //Declare variables
    int size = 0;
    int matrixA[MAX_SIZE][MAX_SIZE]; //create templates
    int matrixB[MAX_SIZE][MAX_SIZE];
    int matrixSum[MAX_SIZE][MAX_SIZE];
    int matrixProduct[MAX_SIZE][MAX_SIZE];
    int matrixDiff[MAX_SIZE][MAX_SIZE];

    //Read matrixs from the file
    readMatrixFromFile(matrixA, matrixB, size, "matrix_input.txt");

    //me lol
    cout << "Ellia Morse\nLab #6: Matrix manipulation\n\n";

    //Print matrixs A and B
    printMatrix(matrixA, size, "Matrix A");
    cout << endl;
    printMatrix(matrixB, size, "Matrix B");
    cout << endl;

    //Add matrixs A and B
    addMatrices(matrixA, matrixB, matrixSum, size);
    printMatrix(matrixSum, size, "Matrix Sum (A + B)");
    cout << "\n";

    //Multiply matrixs A and B
    multiplyMatrices(matrixA, matrixB, matrixProduct, size);
    printMatrix(matrixProduct, size, "Matrix Product (A * B)");
    cout << "\n";

    //Subtract matrixs A and B
    subtractMatrices(matrixA, matrixB, matrixDiff, size);
    printMatrix(matrixDiff, size, "Matrix Difference (A - B)");
    cout << "\n";
    return 0;
}
