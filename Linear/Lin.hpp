#ifndef LinearForm_hpp
#define LinearForm_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <complex>
#include "ArraySequence.hpp"


template <typename T> class LinearForm {
private:
    ArraySequence<T>* linearform;
public:

    //Constructor
    LinearForm() {
        linearform = new ArraySequence<T>;
    };
    LinearForm(T* coords, int count) {
        linearform = new ArraySequence<T>(coords, count);
    };
    LinearForm(ArraySequence<T>* new_LinearForm) {
        linearform = new_LinearForm;
    };
    LinearForm(LinearForm<T>* LinearForm1) {
        linearform = LinearForm1->linearform;
    }

    //Destructor
    ~LinearForm() {
        linearform->Delete_ArraySequence();
    }
    void Delete_LinearForm() {
        linearform->Delete_ArraySequence();
    }

    //Decomposition
    T GetCoord(int index) {
        return linearform->Get(index);
    };
    int GetDim() {
        return linearform->GetLength();
    };

    //Operations
    void Append(T item) {
        return linearform->Append(item);
    }
    void Set(T item, int index) {
        return linearform->Set(item, index);
    }
    LinearForm<T>* SumOfLinearForm(LinearForm<T>* v) {
        auto* new_linearform = new LinearForm<T>;
        T item;
        if (this->GetDim() > v->GetDim()) {
            for (int i = 0; i < v->GetDim(); i++) {
                item = this->linearform->Get(i) + v->linearform->Get(i);
                new_linearform->Append(item);
            }
            for (int i = v->GetDim(); i < this->GetDim(); i++) {
                item = this->linearform->Get(i);
                new_linearform->Append(item);
            }
        }
        else if (this->GetDim() < v->GetDim()) {
            for (int i = 0; i < this->GetDim(); i++) {
                item = this->linearform->Get(i) + v->linearform->Get(i);
                new_linearform->Append(item);
            }
            for (int i = this->GetDim(); i < v->GetDim(); i++) {
                item = v->linearform->Get(i);
                new_linearform->Append(item);
            }
        }
        else if (this->GetDim() == v->GetDim()) {
            for (int i = 0; i < this->GetDim(); i++) {
                item = this->linearform->Get(i) + v->linearform->Get(i);
                new_linearform->Append(item);
            }
        }
        return new_linearform;
    }

    LinearForm<T>* SubtractionOfLinearForm(LinearForm<T>* v) {
        auto* new_linearform = new LinearForm<T>;
        T item;
        if (this->GetDim() > v->GetDim()) {
            for (int i = 0; i < v->GetDim(); i++) {
                item = this->linearform->Get(i) - v->linearform->Get(i);
                new_linearform->Append(item);
            }
            for (int i = v->GetDim(); i < this->GetDim(); i++) {
                item = this->linearform->Get(i);
                new_linearform->Append(item);
            }
        }
        else if (this->GetDim() < v->GetDim()) {
            for (int i = 0; i < this->GetDim(); i++) {
                item = this->linearform->Get(i) - v->linearform->Get(i);
                new_linearform->Append(item);
            }
            for (int i = this->GetDim(); i < v->GetDim(); i++) {
                item = v->linearform->Get(i);
                new_linearform->Append(item);
            }
        }
        else if (this->GetDim() == v->GetDim()) {
            for (int i = 0; i < this->GetDim(); i++) {
                item = this->linearform->Get(i) - v->linearform->Get(i);
                new_linearform->Append(item);
            }
        }
        return new_linearform;
    };


    LinearForm<T>* MultOnScalar(T scalar) {
        T item;
        auto* new_linearform = new LinearForm<T>;
        for (int i = 0; i < this->GetDim(); i++) {
            item = this->GetCoord(i) * scalar;
            new_linearform->Append(item);
        }
        return new_linearform;
    };


    T GetValue(LinearForm<T>* v) {
        T item = 0;
        if (this->GetDim() > v->GetDim()) {
            throw out_of_range("Dimensions are not the equal");
        }
        else if (this->GetDim() < v->GetDim()) {
            throw out_of_range("Dimensions are not the equal");
        }
        else if (this->GetDim() == v->GetDim()) {
            item = this->linearform->Get(0) * v->linearform->Get(0);
            for (int i = 1; i < this->GetDim(); i++) {
                item += this->linearform->Get(i) * v->linearform->Get(i);
            }
        }
        return item;
    };


    void ComplexLinearFormPrint() {
        cout << "F(x) = ";
        for (int i = 0; i < this->GetDim() - 1; i++) {
            cout << "(" << real(this->GetCoord(i)) << " + " << imag(this->GetCoord(i)) << "i)*x" << i + 1 << " + ";

        }
        cout << "(" << real(this->GetCoord(this->GetDim() - 1)) << " + " << imag(this->GetCoord(this->GetDim() - 1)) << "i)*x" << this->GetDim();
        cout << endl;
    }

    friend ostream& operator << (ostream& cout, LinearForm<T>* lf) {
        cout << "F(x) = ";
        for (int i = 0; i < lf->GetDim() - 1; i++) {
            cout << lf->GetCoord(i) << "*x" << i + 1 << " + ";
        }
        cout << lf->GetCoord(lf->GetDim() - 1) << "*x" << lf->GetDim();
        cout << endl;
        return cout;
    };


};
#endif /* LinearForm_hpp */
