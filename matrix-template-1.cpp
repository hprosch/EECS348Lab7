
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin()
  {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        std::cin >> data[i][j];
      }
    }
  }

  // 2. Display a matrix
  void display() const
  {
    int counter = 0;

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        std::cout << data[i][j] << "\t";
        counter++;
        if (counter % SIZE == 0) {
          std::cout << endl;
        }
      }
    }

  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const
  {
    Matrix result;
     for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j]; 
            }
      }

      return result;

  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const
  {
    Matrix result;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
          result.data[i][j] = 0;
            for (int h = 0; h < SIZE; h++) {
                    result.data[i][j] += (data[i][h] * other.data[h][j]);
            }
                
        }
    }
    return result;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const
  {
      int result;

      for (int i = 0; i < SIZE; i++) {
            result += data[i][i];
            result += data[i][SIZE - (1+i)];
      }

      return result;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2)
  {
      int temp;
      for (int i = 0; i < SIZE; i++) {
        swap(data[row1][i], data[row2][i]);
         // temp = data[i][j];
          //data[i][j] = 

      }
  }
};

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
