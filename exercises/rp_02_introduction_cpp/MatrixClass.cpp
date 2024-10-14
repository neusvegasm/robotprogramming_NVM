#include <iostream>

struct Matrix {

    int rows;
    int cols;
    float* data;

    // Default constructor:
    Matrix() {
        rows = 0;
        cols = 0;
        data = nullptr;
        std::cout << "Default constructor called at " << this << "\n";
    }

    // Destructor:
    ~Matrix() {
        std::cout << "Destructor called at " << this << "\n";
        if (data){
           delete [] data; 
        }
    }

    // Parametrized constructor:
    Matrix(int rows, int cols){
        std::cout << "Parametrized constructor called at " << this << "\n";
        (*this).rows = rows;
        (*this).cols = cols;
        data = new float[rows*cols];
    }

    // Copy constructor
    Matrix(const Matrix& to_copy){
        std::cout << "Copy constructor called at " << this << "\n";
        rows = to_copy.rows;
        cols = to_copy.cols;
        data = new float[rows*cols];
        for (int i=0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                data[cols*i+j] = to_copy.data[cols*i+j];
            }
        }
    }

    float get(int row, int col) {
        return data[cols*row+col];
    }

    void set(float value, int row, int col){
        data[cols*row+col] = value;
    }

    // Addition
    Matrix operator +(const Matrix& other){
        std::cout << "Addition operator called " << this << " + " << &other << "\n";
        if (rows != other.rows || cols != other.cols ) {
            std::cerr << "Error: Vectors must be of the same size." << std::endl;
            return Matrix();  // Return an empty matrix if sizes do not match
        }

        Matrix returned(*this);
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                returned.data[cols*i+j] += other.data[cols*i+j];
            }
        }
        return returned;
    }

    // Substraction
    Matrix operator -(const Matrix& other){
        std::cout << "Addition operator called " << this << " + " << &other << "\n";
        if (rows != other.rows || cols != other.cols ) {
            std::cerr << "Error: Vectors must be of the same size." << std::endl;
            return Matrix();  
        }

        Matrix returned(*this);
        for (int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                returned.data[cols*i+j] -= other.data[cols*i+j];
            }
        }
        return returned;
    }

    // Scalar multiplication
    Matrix operator *(const float scalar){

        Matrix returned(*this);

        for (int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                returned.data[cols*i+j] *= scalar;
            }
        }
        return returned;
    }

    // Vector multiplication
    Matrix operator *(const float* vec){
        
        Matrix returned(*this);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                returned.data[cols * i + j] *= vec[j]; 
            }
        }
        return returned;
    }

    Matrix operator *(const Matrix& other){

        if((*this).cols != other.rows ){
            std::cerr << "Error: Sizes don't match for matrix multiplication." << std::endl;
            return Matrix(); 
        }

        int new_rows = (*this).rows;
        int new_cols = other.cols;

        Matrix returned(new_rows, new_cols);


        int col = 0;
        int row = 0;

        for (int i = 0; i < rows; i++) {

            while(row < new_rows){
                
                float result = 0;
                for (int j=0; j<other.cols; j++){
                    result += data[cols*i+j] * other.data[cols*j+i];
                }

                returned.data[new_rows*row+col] = result;

            }
            
        }
            
            


        
        return returned;
    }


};

int main() {

    Matrix m0;
    Matrix m4(2,2);

    m4.set(2.2f, 1, 1);
    float a = m4.get(1,1);
    std::cout << "Value of a: " << a << "\n";

    Matrix m1(3, 2);  
    Matrix m2(2, 3);  

    m1.set(1.0f, 0, 0);
    m1.set(1.0f, 1, 1);
    m1.set(1.0f, 2, 0);
    m1.set(1.0f, 2, 1);

    m2.set(1.0f, 0, 0);
    m2.set(1.0f, 0, 2);
    m2.set(2.0f, 2, 2);
    m2.set(2.0f, 1, 0);
    m2.set(2.0f, 1, 1);
    m2.set(2.0f, 1, 2);
    

    float scalar = 2.0f;
    float vec[] = {1,2,3};
    Matrix result = m2*m1;
    std::cout << "Result of addition:\n";
    for (int i = 0; i < result.rows; i++) {
        for (int j = 0; j < result.cols; j++) {
            std::cout << result.get(i, j) << " ";
        }
        std::cout << "\n";
    }


    return 0;
}