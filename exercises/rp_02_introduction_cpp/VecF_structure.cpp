#include <iostream>

// Extend the VecF class so that it supports
// 
// Element access (by reference)
// 
// Addition 
// 
// Subtraction
// 
// Multiplication by a scalar (v*s)
//
// Dot product (v*v)


struct VecF {

    int size; // The size of the vector
    float* v; // A pointer to an array of floats.

    float get(int i) { return v[i];} // returns the element at index i from the array v

    void set(int i,float f) {v[i]=f;} // sets the value of the element 

    float& get_ref(int i) { 
        return v[i];
    }

    VecF() { // default constructor
        size=0; v=nullptr;
        std::cout << "Default constructor called at " << this << "\n";
    } 

    ~VecF() { // destructor
        std::cout << "Destructor called at " << this << "\n";
        if (size) delete [] v;
    }

    VecF& operator =(const VecF& other) { // overloads the assignment operator =
        std::cout << "Assigment operator called " << this << " = " << &other << "\n";
        if (size) delete[] v; size=0; v=0;
        if (! other.size) return *this;
        size=other.size; v=new float[size];
        for (int i=0; i<size; ++i)
            v[i]=other.v[i];
        return *this;
    }

    VecF(int size){ // parametrized constructor
        std::cout << "Parametrized constructor called at " << this << "\n";
        this->size=size;
        v=new float[size];
    }

    VecF(const VecF& other) { // copy constructure
        std::cout << "Copy constructor called at " << this << "\n";
        size=0; v=0;
        if (! other.size) return;
        size=other.size; v=new float[size];
        for (int i=0; i<size; ++i)
            v[i]=other.v[i];
    }

    VecF operator+(const VecF& other) { 
        std::cout << "Addition operator called " << this << " + " << &other << "\n";
        if (size != other.size) {
            std::cerr << "Error: Vectors must be of the same size." << std::endl;
            return VecF();  // Return an empty VecF if sizes do not match
        }
        
        VecF returned(*this); // Create a copy of the current object
        for (int i = 0; i < size; ++i) {
            returned.v[i] += other.v[i];
        }
        
        return returned; 
    }

    VecF operator-(const VecF& other){
        std::cout << "Substraction operator called " << this << " - " << &other << "\n";
        if(size != other.size){
            std::cerr << "Error: vectors must be the same size." << std::endl;
            return VecF();
        }

        VecF returned(*this);
        for(int i=0; i<size; i++){
            returned.v[i] -= other.v[i];
        }

        return returned;
    }

    VecF operator*(const VecF& other){
        std::cout << "Multiplication operator called " << this << " * " << &other << "\n";
        if(size != other.size){
            std::cerr << "Error: vectors must be the same size." << std::endl;
            return VecF();
        }

        int result=0;
        VecF returned(*this);

        for(int i=0; i<size; i++){
            result += returned.v[i] * other.v[i];
        }

        returned.size = 1;
        returned.v[0] = result;
        return returned;
    }

    VecF operator*(const int other){
        std::cout << "Scalar multiplication operator called " << this << " * " << &other << "\n";

        VecF returned(*this);

        for(int i=0; i<size; i++){
            returned.v[i] *= other;
        }

        return returned;
    }
};


int main() {
    VecF vec1(5);    // Create a VecF of size 5 using the parameterized constructor.
    vec1.set(0, 1.1f);
    vec1.set(1, 2.2f);
    
    VecF vec2 = vec1;  // Copy constructor is called
    
    VecF vec3;         // Default constructor.
    vec3 = vec1;       // Assignment operator is called
    vec1 * vec2;

    int s = 4;
    vec1 * s;

    float& a = vec1.get_ref(1);
    std:: cout << "Value of a: " << a << "\n"; 
    std:: cout << "Value of vec1: " << vec1.v[1] << "\n"; 

    a = 1.1f;
    std:: cout << "Value of a: " << a << "\n"; 
    std:: cout << "Value of vec1: " << vec1.v[1] << "\n"; 


    
    return 0;  // Destructor is called automatically for vec1, vec2, and vec3.
}


