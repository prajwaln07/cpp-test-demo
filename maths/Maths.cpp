#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        if (r <= 0 || c <= 0)
            throw invalid_argument("Matrix dimensions must be positive");
        data = vector<vector<double>>(r, vector<double>(c, 0));
    }

    Matrix(const vector<vector<double>>& values) {
        if (values.empty() || values[0].empty())
            throw invalid_argument("Matrix cannot be empty");
        rows = values.size();
        cols = values[0].size();
        for (const auto& row : values) {
            if (row.size() != cols)
                throw invalid_argument("Irregular matrix dimensions");
        }
        data = values;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    double get(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Index out of bounds");
        return data[r][c];
    }

    void set(int r, int c, double value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw out_of_range("Index out of bounds");
        data[r][c] = value;
    }

    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions must match for addition");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix subtract(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw invalid_argument("Matrix dimensions must match for subtraction");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows)
            throw invalid_argument("Matrix dimensions incompatible for multiplication");

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[j][i] = data[i][j];
        return result;
    }

    void print() const {
        for (const auto& row : data) {
            for (double val : row)
                cout << val << " ";
            cout << endl;
        }
    }
};

int main() {
    vector<vector<double>> a = {{1, 2}, {3, 4}};
    vector<vector<double>> b = {{5, 6}, {7, 8}};

    Matrix m1(a);
    Matrix m2(b);

    cout << "Matrix A + B:\n";
    m1.add(m2).print();

    cout << "\nMatrix A * B:\n";
    m1.multiply(m2).print();

    cout << "\nTranspose of A:\n";
    m1.transpose().print();

    return 0;
}
