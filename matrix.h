#ifndef MATRIX_H
#define MATRIX_H

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
};

#endif
