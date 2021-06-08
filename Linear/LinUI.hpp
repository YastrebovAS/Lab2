#ifndef Menu_LinearForm_hpp
#define Menu_LinearForm_hpp

#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

const string sep = "<====================================================>";
#include "Lin.hpp"

int chooseType() {
    int type;
    cout << "Select type of numbers: \n"
        << "\t1: int\n"
        << "\t2: double\n"
        << "\t3: complex\n\n"
        << "\t0: Return to select class\n"
        << "Enter a number: ";
    cin >> type;
    return type;
}

int chooseLFFunction() {
    int func;
    cout << "What function do you want to use?: \n"
        << "\t1: Sum of Linears form\n"
        << "\t2: Substract of Linears form\n"
        << "\t3: Multiplication of linears form on scalar\n"
        << "\t4: Get value\n"
        << "\t5: Tests\n" << endl
        << "\t0: Return to select type\n"
        << "Enter a number: ";
    cin >> func;
    cout << func << endl;
    return func;
}

template <typename T>
LinearForm<T>* inputLinearForm() {
    int dim;
    cout << "Enter a dimension of a linear form:";
    cin >> dim; cout << endl;
    LinearForm<T>* lf = new LinearForm<T>();
    cout << "Enter Coordinates (one by one):" << endl;
    T coord;
    for (int i = 0; i < dim; i++) {
        cin >> coord;
        lf->Append(coord);
    }
    return lf;
}
LinearForm<complex<double>>* inputComplexLinearForm() {
    int dim;
    cout << "Enter a dimension of a complex linear form:";
    cin >> dim; cout << endl;
    LinearForm<complex<double>>* lf = new LinearForm<complex<double>>();
    cout << "Enter Coordinates (one by one):" << endl;
    complex<double> coord;
    double real, im;
    for (int i = 0; i < dim; i++) {
        cout << "Enter Real and Imaginary number (separated by a space): " << endl;
        cin >> real >> im;
        coord = complex<double>(real, im);
        lf->Append(coord);
    }
    return lf;
}

void MenuLinearForm() {
    while (true) {
        int type = chooseType(); //1 - int ; 2 - double ; 3 - complex; 0 - return to select class
        if (type == 0) {
            break;
        }
        if (type == 1) {
            while (true) {
                int function = chooseLFFunction();
                if (function == 1) {
                    cout << "Enter 1 linear form:" << endl;
                    auto* lf1 = inputLinearForm<int>();
                    cout << "Enter 2 linear form:" << endl;
                    auto* lf2 = inputLinearForm<int>();
                    cout << lf1 << endl;
                    cout << lf2 << endl;
                    auto* sum = lf1->SumOfLinearForm(lf2);
                    cout << "Sum of Linear form 1 and Linear form 2 = " << sum << endl;
                }
                else if (function == 3) {
                    cout << "Enter Linear form:" << endl;
                    auto* lf = inputLinearForm<int>();
                    cout << "Enter scalar: " << endl;
                    int scalar;
                    cin >> scalar;
                    cout << lf << endl;
                    cout << scalar << endl;
                    auto lfMult = lf->MultOnScalar(scalar);
                    cout << "Multiplication of Linear form and scalar = " << lfMult << endl;
                }
                else if (function == 2) {
                    cout << "Enter 1 linear form:" << endl;
                    auto* lf1 = inputLinearForm<int>();
                    cout << "Enter 2 linear form:" << endl;
                    auto* lf2 = inputLinearForm<int>();
                    cout << lf1 << endl;
                    cout << lf2 << endl;
                    auto* substract = lf1->SubtractionOfLinearForm(lf2);
                    cout << "Substraction of linear forms = " << substract << endl;
                }
                else if (function == 4) {
                    cout << "Enter linear form:" << endl;
                    auto* lf1 = inputLinearForm<int>();
                    cout << "Enter coordinates:" << endl;
                    auto* lf2 = inputLinearForm<int>();
                    cout << "Print it? -> 1 - yes | 0 - no" << endl;
                    int buf;
                    cin >> buf;
                    cout << lf1 << endl;
                    auto mult = lf1->GetValue(lf2);
                    cout << "F(a) = " << mult << endl << sep << endl;
                }
                else if (function == 0) break;
                else
                    cout << "Incorrect input!" << endl;
                cout << sep << endl;
            }
        }
        else if (type == 2) {
            while (true) {
                int function = chooseLFFunction();
                if (function == 1) {
                    cout << "Enter 1 linear form:" << endl;
                    auto* lf1 = inputLinearForm<double>();
                    cout << "Enter 2 linear form:" << endl;
                    auto* lf2 = inputLinearForm<double>();
                    cout << lf1 << endl;
                    cout << lf2 << endl;
                    auto* sum = lf1->SumOfLinearForm(lf2);
                    cout << "Sum of Linear form 1 and Linear form 2 = " << sum << endl;
                }
                else if (function == 3) {
                    cout << "Enter Linear form:" << endl;
                    auto* lf = inputLinearForm<double>();
                    cout << "Enter scalar: " << endl;
                    double scalar;
                    cin >> scalar;
                    cout << lf << endl;
                    cout << scalar << endl;
                    auto lfMult = lf->MultOnScalar(scalar);
                    cout << "Multiplication of linear form and scalar: " << lfMult << endl;
                }
                else if (function == 2) {
                    cout << "Enter 1 linear form:" << endl;
                    auto* lf1 = inputLinearForm<double>();
                    cout << "Enter 2 linear form:" << endl;
                    auto* lf2 = inputLinearForm<double>();
                    cout << lf1 << endl;
                    cout << lf2 << endl;
                    auto* substract = lf1->SubtractionOfLinearForm(lf2);
                    cout << "Substraction of linear forms = " << substract << endl;
                }
                else if (function == 4) {
                    cout << "Enter linear form:" << endl;
                    auto* lf1 = inputLinearForm<double>();
                    cout << "Enter coordinates:" << endl;
                    auto* lf2 = inputLinearForm<double>();
                    cout << lf1 << endl;
                    auto mult = lf1->GetValue(lf2);
                    cout << "F(a) = " << mult << endl << sep << endl;
                }
                else if (function == 0) break;
                else
                    cout << "Wrong input!" << endl;
                cout << sep << endl;;
            }
        }
        else if (type == 3) {
            while (true) {
                int function = chooseLFFunction();
                if (function == 1) {
                    cout << "Enter 1 linear form:" << endl;
                    auto* lf1 = inputComplexLinearForm();
                    cout << "Enter 2 linear form:" << endl;
                    auto* lf2 = inputComplexLinearForm();
                    lf1->ComplexLinearFormPrint();
                    lf2->ComplexLinearFormPrint();
                    auto* sum = lf1->SumOfLinearForm(lf2);
                    cout << "Sum of Linear form 1 and Linear form 2: ";
                    sum->ComplexLinearFormPrint();
                }
                else if (function == 3) {
                    cout << "Enter linear form:" << endl;
                    auto* lf = inputComplexLinearForm();
                    cout << "Enter scalar: " << endl;
                    complex<double> scalar;
                    double real, im;
                    cout << "Enter Real and Imaginary number (separated by a space): " << endl;
                    cin >> real >> im;
                    scalar = complex<double>(real, im);
                    lf->ComplexLinearFormPrint();
                    cout << "Scalar = " << scalar << endl;
                    auto lfMult = lf->MultOnScalar(scalar);
                    cout << "Multiplication of Linear form and scalar = ";
                    lfMult->ComplexLinearFormPrint();
                }
                else if (function == 2) {
                    cout << "Enter 1 linear form:" << endl;
                    auto* lf1 = inputComplexLinearForm();
                    cout << "Enter 2 linear form:" << endl;
                    auto* lf2 = inputComplexLinearForm();
                    lf1->ComplexLinearFormPrint();
                    lf2->ComplexLinearFormPrint();
                    auto* substract = lf1->SubtractionOfLinearForm(lf2);
                    cout << "Substraction of linear forms = ";
                    substract->ComplexLinearFormPrint();
                }
                else if (function == 4) {
                    cout << "Enter linear form:" << endl;
                    auto* lf1 = inputComplexLinearForm();
                    cout << "Enter coordinates:" << endl;
                    auto* lf2 = inputComplexLinearForm();
                    lf1->ComplexLinearFormPrint();
                    auto mult = lf1->GetValue(lf2);
                    cout << "F(a) = " << mult << endl;
                }
                else if (function == 0) break;
                else
                    cout << "Wrong input!" << endl;
                cout << sep << endl;
            }
        }
    }
}

#endif /* Menu_LinearForm_hpp */