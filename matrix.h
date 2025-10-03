#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <stdexcept>
template<typename T>
class Matrix {
    std::vector<T> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r*c) {}

    T& at(int r, int c) { return data[r * cols + c]; }
    const T& at(int r, int c) const { return data[r * cols + c]; }

    std::vector<int> shape() const { return {rows, cols}; }

    Matrix<T> transpose() const {
        Matrix<T> transposed(cols, rows);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                transposed.at(j, i) = at(i, j);
            }
        }
        return transposed;
    }

    Matrix<T> operator+(const Matrix<T>& mat2) const {

      if(this->shape()!=mat2.shape()) throw std::invalid_argument("Matrix Shapes Must Match");

      Matrix<T> resultant(this->shape()[0],this->shape()[1]);
      for(int i=0;i<this->shape()[0];i++) {
        for(int j=0;j<this->shape()[1];j++) {
         resultant.at(i, j) = this->at(i, j) +mat2.at(i, j);
        }
      }
      return resultant;
    }

    Matrix<T> operator+(const T num) const {
      Matrix<T> resultant(this->shape()[0],this->shape()[1]);
      for(int i=0;i<this->shape()[0];i++) {
        for(int j=0;j<this->shape()[1];j++) {
         resultant.at(i, j) = this->at(i, j) + num;
        }
      }
      return resultant;
    }

    Matrix<T> operator-(const Matrix<T>& mat2) const {

      if(this->shape()!=mat2.shape()) throw std::invalid_argument("Matrix Shapes Must Match");

      Matrix<T> resultant(this->shape()[0],this->shape()[1]);
      for(int i=0;i<this->shape()[0];i++) {
        for(int j=0;j<this->shape()[1];j++) {
         resultant.at(i, j) = this->at(i, j) -imat2.at(i, j);
        }
      }
      return resultant;
    }

    Matrix<T> operator-(const T num) const {
      Matrix<T> resultant(this->shape()[0],this->shape()[1]);
      for(int i=0;i<this->shape()[0];i++) {
        for(int j=0;j<this->shape()[1];j++) {
         resultant.at(i, j) = this->at(i, j) - num;
        }
      }
      return resultant;
    }    Matrix<T> operator*(const Matrix<T>& mat2) const {

      if(this->shape()!=mat2.shape()) throw std::invalid_argument("Matrix Shapes Must Match");

      Matrix<T> resultant(this->shape()[0],this->shape()[1]);
      for(int i=0;i<this->shape()[0];i++) {
        for(int j=0;j<this->shape()[1];j++) {
         resultant.at(i, j) = this->at(i, j) *mat2.at(i, j);
        }
      }
      return resultant;
    }

    Matrix<T> operator*(const T num) const {
      Matrix<T> resultant(this->shape()[0],this->shape()[1]);
      for(int i=0;i<this->shape()[0];i++) {
        for(int j=0;j<this->shape()[1];j++) {
         resultant.at(i, j) = this->at(i, j) / num;
        }
      }
      return resultant;
    }    Matrix<T> operator/(const Matrix<T>& mat2) const {

      if(this->shape()!=mat2.shape()) throw std::invalid_argument("Matrix Shapes Must Match");

      Matrix<T> resultant(this->shape()[0],this->shape()[1]);
      for(int i=0;i<this->shape()[0];i++) {
        for(int j=0;j<this->shape()[1];j++) {
         if(mat2.at(i, j)==0) throw std::invalid_argument("Division by 0");

         resultant.at(i, j) = this->at(i, j) +mat2.at(i, j);
        }
      }
      return resultant;
    }

    Matrix<T> operator/(const T num) const {
    if(num==0) throw std::invalid_argument("Division by 0");

      Matrix<T> resultant(this->shape()[0],this->shape()[1]);

      for(int i=0;i<this->shape()[0];i++) {
        for(int j=0;j<this->shape()[1];j++) {
         resultant.at(i, j) = this->at(i, j) + num;
        }
      }
      return resultant;
    }

/*

    operator-(Matrix<T> mat1, Matrix<T> mat2) {
      for(int i;i<mat1.shape[0];i++) {
        int 
      }

    }

    operator*(Matrix<T> mat1, Matrix<T> mat2) {
      for(int i;i<mat1.shape[0];i++) {
        int 
      }

    }

    operator/(Matrix<T> mat1, Matrix<T> mat2) {
      for(int i;i<mat1.shape[0];i++) {
        int 
      }

    }

    operator^(Matrix<T> mat1, Matrix<T> mat2) {
      for(int i;i<mat1.shape[0];i++) {
        int 
      }
    
    }

    Matrix<T> ln(Matrix<T> mat) {
      for(int i;i<mat1.shape[0];i++) {
        int 
      }

    }
*/    
};

#endif
