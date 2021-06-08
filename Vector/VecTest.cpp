#include "VecTest.hpp"
#include <cassert>
#include "iostream"

void VectorTest() {
    int length1 = 100;
    int* items = new int[length1];
    for (int i = 0; i < length1; i++)
        items[i] = i * 3;
    Vector<int>* vector11 = new Vector<int>;
    assert(vector11->GetDim() == 0);

    Vector<int>* vector21 = new Vector<int>(items, length1);
    assert(vector21->GetDim() == length1);
    for (int i = 0; i < length1; i++)
        assert(vector21->GetCoord(i) == i * 3);

    Vector<int>* vector31 = new Vector<int>(vector21);
    assert(vector31->GetDim() == length1);
    for (int i = 0; i < length1; i++)
        assert(vector31->GetCoord(i) == i * 3);

    const int length = 3;


    int first_vector_data[length] = { 1, 2, 3 };
    int second_vector_data[length] = { 4, 5, 6 };

    int* pointer_first_data = new int[length];
    for (int i = 0; i < length; i++)
        pointer_first_data[i] = first_vector_data[i];
    int* pointer_second_data = new int[length];
    for (int i = 0; i < length; i++)
        pointer_second_data[i] = second_vector_data[i];

    int scalar = 2;

    int vector_sum[length] = { 5, 7, 9 };
    int vectors_ScalarMult = 32;
    int vector1_MultOnScalar[length] = { 2, 4, 6 };
    int vector2_MultOnScalar[length] = { 8, 10, 12 };

    Vector<int>* vector1 = new Vector<int>(pointer_first_data, length);
    Vector<int>* vector2 = new Vector<int>(pointer_second_data, length);
    auto* Sumofvectors = vector1->SumOfVectors(vector2);
    auto* MultOnScalarVector1 = vector1->MultOnScalar(scalar);
    auto* MultOnScalarVector2 = vector2->MultOnScalar(scalar);
    int scalar_mult = vector1->ScalarMult(vector2);


    for (int i = 0; i < length; i++) {

        assert(Sumofvectors->GetCoord(i) == vector_sum[i]);
        assert(MultOnScalarVector1->GetCoord(i) == vector1_MultOnScalar[i]);
        assert(MultOnScalarVector2->GetCoord(i) == vector2_MultOnScalar[i]);
        assert(scalar_mult == vectors_ScalarMult);
    }

}