#include "LinTest.hpp"
#include <cassert>

void LinearFormTest() {
    int length = 10;
    int* items = new int[length];
    for (int i = 0; i < length; i++)
        items[i] = i + 1;
    LinearForm<int>* lf11 = new LinearForm<int>;
    assert(lf11->GetDim() == 0);

    LinearForm<int>* lf21 = new LinearForm<int>(items, length);
    assert(lf21->GetDim() == length);
    for (int i = 0; i < length; i++)
        assert(lf21->GetCoord(i) == i + 1);

    LinearForm<int>* lf31 = new LinearForm<int>(lf21);
    assert(lf31->GetDim() == length);
    for (int i = 0; i < length; i++)
        assert(lf31->GetCoord(i) == i + 1);

    const int length1 = 5;
    const int number = 2;
    int* items1 = new int[length1];
    for (int i = 0; i < length1; i++)
        items1[i] = 2;
    int* items2 = new int[length1];
    for (int i = 0; i < length1; i++)
        items2[i] = 1;
    int* items3 = new int[length1];
    for (int i = 0; i < length1; i++)
        items3[i] = 2;
    LinearForm<int>* lf1 = new LinearForm<int>(items1, length1);
    LinearForm<int>* lf2 = new LinearForm<int>(items2, length1);
    LinearForm<int>* lf_numbers = new LinearForm<int>(items3, length1);

    int lf_sum[length1] = { 3, 3, 3, 3, 3 };
    int lf_sub[length1] = { 1, 1, 1, 1, 1 };
    int lf_MultOnScalar[length1] = { 4, 4, 4, 4, 4 };
    int lf_GetValue = 20;

    auto* lf_sum1 = lf1->SumOfLinearForm(lf2);
    auto* lf_sub1 = lf1->SubtractionOfLinearForm(lf2);
    auto* lf_MultOnScalar1 = lf1->MultOnScalar(number);
    int lf_GetValue1 = lf1->GetValue(lf_numbers);


    for (int i = 0; i < length1; i++) {
        assert(lf_sum[i] == lf_sum1->GetCoord(i));
    }
    for (int i = 0; i < length1; i++) {
        assert(lf_sub[i] == lf_sub1->GetCoord(i));
    }
    for (int i = 0; i < length1; i++) {
        assert(lf_MultOnScalar[i] == lf_MultOnScalar1->GetCoord(i));
    }
    assert(lf_GetValue == lf_GetValue1);
};