#include "LinUI.hpp"
#include "LinTest.hpp"
#include "VecUI.hpp"
#include "VecTest.hpp"
#include "ArraySequence.hpp"
#include "LinkedSequence.hpp"
#include "mainTest.hpp"


int main() {
    while (true) {
        int classType;
        cout << "Vector - 1 , Linear form - 2 , Tests - 3 , Exit - 0 " << endl;
        cin >> classType;

        if (classType != 0 & classType != 1 & classType != 2 & classType != 3) {
            cout << "The number is incorrect. Please, enter the correct number" << endl;
        }
        if (classType == 1) {
            MenuVector();
        }
        else if (classType == 2) {
            MenuLinearForm();
        }
        else if (classType == 3) {
            VectorTest();
            LinearFormTest();
            ArraySequenceTest();
            LinkedSequenceTest();
            DynamicArrayTest();
            LinkedListTest();
            cout << "All tests passed!" << endl;
            cout << sep << endl;
        }
        else if (classType == 0) {
            break;
        }

    }
    return 0;
};