#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

const int MAX_SIZE = 100;

void readMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& matrixSize, const std::string& filename);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void addMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void multMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void subMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

std::string user_file() {
    // Implement user_file function to get the file name from the user
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;
    return filename;
}

void readMatrix(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& matrixSize, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> matrixSize;
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                file >> matrixA[i][j];
            }
        }
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                file >> matrixB[i][j];
            }
        }
        file.close();
    }
    else {
        std::cout << "Error: Unable to open the file." << std::endl;
        exit(1);
    }
}

void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subMatrix(const int matrixA[MAX_SIZE][MAX_SIZE], const int matrixB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

int main() {
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int matrixSize;

    std::string file = user_file();
    readMatrix(matrixA, matrixB, matrixSize, file);

    std::cout << "\nBlake Smith\nLab #6: Matrix manipulation" << std::endl;

    std::cout << "\nMatrix A:" << std::endl;
    printMatrix(matrixA, matrixSize);

    std::cout << "\nMatrix B:" << std::endl;
    printMatrix(matrixB, matrixSize);

    addMatrix(matrixA, matrixB, result, matrixSize);
    std::cout << "\nMatrix Sum (A + B):" << std::endl;
    printMatrix(result, matrixSize);

    multMatrix(matrixA, matrixB, result, matrixSize);
    std::cout << "\nMatrix Product (A * B):" << std::endl;
    printMatrix(result, matrixSize);

    subMatrix(matrixA, matrixB, result, matrixSize);
    std::cout << "\nMatrix Difference (A - B):" << std::endl;
    printMatrix(result, matrixSize);

    return 0;
}
