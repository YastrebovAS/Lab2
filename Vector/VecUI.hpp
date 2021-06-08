#ifndef menu_vector_hpp
#define menu_vector_hpp
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

#include "Vec.hpp"

int chooseVectorFunction() {
    int func;
    cout << "What function do you want to use?: \n"
        << "\t1: Sum of Vectors\n"
        << "\t2: Multiplication of scalar and vector\n"
        << "\t3: Vector Norm\n"
        << "\t4: Scalar Multiplication\n"
        << "\t5: Vector tests\n" << endl
        << "\t0: Return to select type\n"
        << "Enter a number: ";
    cin >> func;
    return func;
}

template <typename T>
Vector<T>* inputVector() {
    int dim;
    cout << "Enter a dimension of vector:";
    cin >> dim; cout << endl;
    Vector<T>* vect = new Vector<T>();
    cout << "Enter Coordinates (one by one):" << endl;
    T coord;
    for (int i = 0; i < dim; i++) {
        cin >> coord;
        vect->Append(coord);
    }
    return vect;
}
Vector<complex<double>>* inputComplexVector() {
    int dim;
    cout << "Enter a dimension of vector:";
    cin >> dim; cout << endl;
    Vector<complex<double>>* vect = new Vector<complex<double>>();
    cout << "Enter Coordinates (one by one):" << endl;
    complex<double> coord;
    double real, im;
    for (int i = 0; i < dim; i++) {
        cout << "Enter Real and Imaginary number (separated by a space): " << endl;
        cin >> real >> im;
        coord = complex<double>(real, im);
        vect->Append(coord);
    }
    return vect;
}

void MenuVector() {
    while (true) {
        int type = chooseType(); //1 - int ; 2 - double ; 3 - complex; 0 - return to select class
        if (type == 0) {
            break;
        }
        if (type == 1) {
            while (true) {
                int function = chooseVectorFunction();
                if (function == 1) {
                    cout << "Enter 1 vector:" << endl;
                    auto* vect1 = inputVector<int>();
                    cout << "Enter 2 vector:" << endl;
                    auto* vect2 = inputVector<int>();
                    cout << "Vector 1 = " << vect1 << endl;
                    cout << "Vector 2 = " << vect2 << endl;
                    auto* sum = vect1->SumOfVectors(vect2);
                    cout << "Sum of Vector 1 and Vector 2 = " << sum << endl;
                }
                else if (function == 2) {
                    cout << "Enter vector:" << endl;
                    auto* vect = inputVector<int>();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << "Vector = " << vect << endl;
                    cout << "Scalar = " << scalar << endl;
                    auto vectorMult = vect->MultOnScalar(scalar);
                    cout << "Multiplication of vector and scalar = " << vectorMult << endl;
                }
                else if (function == 3) {
                    cout << "Enter vector:" << endl;
                    auto* vect = inputVector<int>();
                    cout << "Vector = " << vect << endl;
                    auto vectorNorm = vect->NormOfVector<double>();
                    cout << "Vector norm = " << vectorNorm << endl;
                }
                else if (function == 4) {
                    cout << "Enter 1 vector:" << endl;
                    auto* vect1 = inputVector<int>();
                    cout << "Enter 2 vector:" << endl;
                    auto* vect2 = inputVector<int>();
                    cout << "Vector 1 = " << vect1 << endl;
                    cout << "Vector 2 = " << vect2 << endl;
                    auto mult = vect1->ScalarMult(vect2);
                    cout << "Scalar multiplication of Vector 1 and Vector 2 = " << mult << endl;
                }
                else if (function == 0) break;
                else
                    cout << "Enter the correct number!" << endl;
                cout << sep << endl;
            }
        }
        else if (type == 2) {
            while (true) {
                int function = chooseVectorFunction();
                if (function == 1) {
                    cout << "Enter 1 vector:" << endl;
                    auto* vect1 = inputVector<double>();
                    cout << "Enter 2 vector:" << endl;
                    auto* vect2 = inputVector<double>();
                    cout << "Vector 1 = " << vect1 << endl;
                    cout << "Vector 2 = " << vect2 << endl;
                    auto* sum = vect1->SumOfVectors(vect2);
                    cout << "Sum of Vector 1 and Vector 2 = " << sum << endl;
                }
                else if (function == 2) {
                    cout << "Enter vector:" << endl;
                    auto* vect = inputVector<double>();
                    cout << "Enter scalar: " << endl;
                    double scalar;
                    cin >> scalar;
                    cout << "Vector = " << vect << endl;
                    cout << "Scalar = " << scalar << endl;
                    auto vectorMult = vect->MultOnScalar(scalar);
                    cout << "Multiplication of vector and scalar = " << vectorMult << endl;
                }
                else if (function == 3) {
                    cout << "Enter vector:" << endl;
                    auto* vect = inputVector<double>();
                    cout << "Vector = " << vect << endl;
                    auto vectorNorm = vect->NormOfVector<double>();
                    cout << "Vector norm = " << vectorNorm << endl;
                }
                else if (function == 4) {
                    cout << "Enter 1 vector:" << endl;
                    auto* vect1 = inputVector<double>();
                    cout << "Enter 2 vector:" << endl;
                    auto* vect2 = inputVector<double>();
                    cout << "Vector 1 = " << vect1 << endl;
                    cout << "Vector 2 = " << vect2 << endl;
                    auto mult = vect1->ScalarMult(vect2);
                    cout << "Scalar multiplication of Vector 1 and Vector 2 = " << mult << endl;
                }
                else if (function == 0) break;
                else
                    cout << "Enter the correct number!" << endl;
                cout << sep << endl;
            }
        }
        else if (type == 3) {
            while (true) {
                int function = chooseVectorFunction();
                if (function == 1) {
                    cout << "Enter 1 vector:" << endl;
                    auto* vect1 = inputComplexVector();
                    cout << "Enter 2 vector:" << endl;
                    auto* vect2 = inputComplexVector();
                    cout << "Vector 1 = " << vect1 << endl;
                    cout << "Vector 2 = " << vect2 << endl;
                    auto* sum = vect1->SumOfVectors(vect2);
                    cout << "Sum of Vector 1 and Vector 2 = " << sum << endl;
                }
                else if (function == 2) {
                    cout << "Enter vector:" << endl;
                    auto* vect = inputComplexVector();
                    cout << "Enter scalar: " << endl;
                    complex<double> scalar;
                    double real, im;
                    cout << "Enter Real and Imaginary number (separated by a space): " << endl;
                    cin >> real >> im;
                    scalar = complex<double>(real, im);
                    cout << "Vector = " << vect << endl;
                    cout << "Scalar = " << scalar << endl;
                    auto vectorMult = vect->MultOnScalar(scalar);
                    cout << "Multiplication of vector and scalar = " << vectorMult << endl;
                }
                else if (function == 3) {
                    cout << "Enter vector:" << endl;
                    auto* vect = inputComplexVector();
                    cout << "Vector = " << vect << endl;
                    auto vectorNorm = vect->NormOfVector<complex<double>>();
                    cout << "Vector norm = " << vectorNorm << endl;
                }
                else if (function == 4) {
                    cout << "Enter 1 vector:" << endl;
                    auto* vect1 = inputComplexVector();
                    cout << "Enter 2 vector:" << endl;
                    auto* vect2 = inputComplexVector();
                    cout << "Vector 1 = " << vect1 << endl;
                    cout << "Vector 2 = " << vect2 << endl;
                    auto mult = vect1->ScalarMult(vect2);
                    cout << "Scalar multiplication of Vector 1 and Vector 2 = " << mult << endl;
                }
                else if (function == 0) break;
                else
                    cout << "Enter the correct number!" << endl;
                cout << sep << endl;
            }
        }
    }
}



#endif /* menu_vector_hpp */