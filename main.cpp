#include "matrix.h"
#include <iostream>
int main() {
    Matrix<float> mat(2, 3);
    Matrix<float> mat1(2, 2);
    Matrix<float> result(2, 3);
    result = mat + mat1;

    for(int i = 0; i < mat.shape()[0];i++) {
      for(int j = 0; j < mat.shape()[1];j++) {
        std::cout<< result.at(i,j) <<std::endl;
      }    
    }
    return 0;
}
