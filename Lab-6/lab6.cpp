#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

const int MAX_SIZE = 100;

// Function prototypes
void read(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int& matrixSize, const std::string& filename);
void print(const int matrix[MAX_SIZE][MAX_SIZE], int size);
void add(const int matA[MAX_SIZE][MAX_SIZE], const int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void mult(const int matA[MAX_SIZE][MAX_SIZE], const int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);
void sub(const int matA[MAX_SIZE][MAX_SIZE], const int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size);

std::string user_file() {
    // Implement user_file function to get the file name from the user
    std::string filename;
    std::cout << "Enter the file name: ";
    std::cin >> filename;
    return filename;
}

void read(int matA[MAX_SIZE][MAX_SIZE], int matB[MAX_SIZE][MAX_SIZE], int& matrixSize, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> matrixSize;
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                file >> matA[i][j];
            }
        }
        for (int i = 0; i < matrixSize; i++) {
            for (int j = 0; j < matrixSize; j++) {
                file >> matB[i][j];
            }
        }
        file.close();
    }
    else {
        std::cout << "Error: Unable to open the file." << std::endl;
        exit(1);
    }
}

void print(const int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void add(const int matA[MAX_SIZE][MAX_SIZE], const int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void mult(const int matA[MAX_SIZE][MAX_SIZE], const int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

void sub(const int matA[MAX_SIZE][MAX_SIZE], const int matB[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

int main() {
    int matA[MAX_SIZE][MAX_SIZE];
    int matB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int matrixSize;

    std::string file = user_file();
    read(matA, matB, matrixSize, file);

    std::cout << "\nWesley McDougal\nLab #6: Matrix manipulation" << std::endl;

    std::cout << "\nMatrix A:" << std::endl;
    print(matA, matrixSize);

    std::cout << "\nMatrix B:" << std::endl;
    print(matB, matrixSize);

    add(matA, matB, result, matrixSize);
    std::cout << "\nMatrix Sum (A + B):" << std::endl;
    print(result, matrixSize);

    mult(matA, matB, result, matrixSize);
    std::cout << "\nMatrix Product (A * B):" << std::endl;
    print(result, matrixSize);

    sub(matA, matB, result, matrixSize);
    std::cout << "\nMatrix Difference (A - B):" << std::endl;
    print(result, matrixSize);

    return 0;
}
