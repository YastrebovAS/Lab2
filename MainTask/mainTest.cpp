#include "mainTest.hpp"
#include <cassert>
#include "iostream"

using namespace std;
float round_float(float num, int order) {
    for (int i = 0; i < order; i++) {
        num = num * 10;
    }
    num = (float)(int)num;
    for (int i = 0; i < order; i++) {
        num = num / 10;
    }
    return num;
}

void DynamicArrayTest() {
    int arr1[] = { 1, 2, 3, 4, 5 };
    auto* dynArray = new DynamicArray<int>(arr1, 5);
    assert(dynArray->GetSize() == 5);
    assert(dynArray->Get(3) == 4);
    dynArray->Resize(8);
    assert(dynArray->GetSize() == 8);
    dynArray->Set(3, 10);
    assert(dynArray->Get(3) == 10);
    dynArray->Resize(0);
    assert(dynArray->GetSize() == 0);
    dynArray->Delete_DynamicArray();

    auto* arr2 = new DynamicArray<int>(10);
    assert(arr2->GetSize() == 10);
    arr2->Delete_DynamicArray();

    int arr3[] = { 1, 2, 3, 4, 5 };
    DynamicArray<int>* array = new DynamicArray<int>(arr3, 5);
    DynamicArray<int>* newArr = new DynamicArray<int>(array);
    assert(newArr->GetSize() == 5);
    assert(newArr->Get(2) == 3);
    assert(newArr->Get(1) == 2);
    array->Delete_DynamicArray();

    DynamicArray<int>* array2 = new DynamicArray<int>();
    assert(array2->GetSize() == 0);
    array2->Delete_DynamicArray();

    int arr[] = { 1, 2, 3, 4, 5 };
    auto* array3 = new DynamicArray<int>(arr, 5);
    assert(array3->Get(3) == 4);
    assert(array3->Get(4) == 5);
    assert(array3->Get(0) == 1);
    array3->Delete_DynamicArray();

    int arr4[] = { 1, 2, 3, 4, 5 };
    auto* array4 = new DynamicArray<int>(arr4, 5);
    assert(array4->GetSize() == 5);
    array4->Delete_DynamicArray();

    int arr5[] = { 1, 2, 3, 4, 5 };
    auto* array5 = new DynamicArray<int>(arr5, 5);
    array5->Delete_DynamicArray();

    int arr6[] = { 1, 2, 3, 4, 5 };
    auto* array6 = new DynamicArray<int>(arr6, 5);
    array6->Set(3, 100);
    assert(array6->Get(3) == 100);
    assert(array6->Get(2) == 3);
    array6->Delete_DynamicArray();

    int arr7[] = { 1, 2, 3, 4, 5 };
    auto* array7 = new DynamicArray<int>(arr7, 5);
    assert(array7->GetSize() == 5);
    array7->Resize(10);
    assert(array7->GetSize() == 10);
    array7->Delete_DynamicArray();
}

void LinkedListTest() {
    float arr1[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list1 = new LinkedList<float>(arr1, 5);
    assert(list1->GetLength() == 5);
    assert(round_float(list1->Get(1), 1) == round_float(6.6, 1));
    list1->Delete_LinkedList();

    auto* list2 = new LinkedList<float>;
    assert(list2->GetLength() == 0);
    list2->Delete_LinkedList();

    float arr3[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list1_1 = new LinkedList<float>(arr3, 5);
    auto* list2_1 = new LinkedList<float>(list1_1);
    assert(list1_1->GetLength() == list2_1->GetLength());
    assert(list1_1->Get(3) == list2_1->Get(3));
    assert(list1_1->Get(0) == list2_1->Get(0));
    assert(list1_1->Get(2) == list2_1->Get(2));
    list1->Delete_LinkedList();

    float arr4[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list4 = new LinkedList<float>(arr4, 5);
    assert(round_float(list4->GetFirst(), 2) == round_float(5.5, 2));
    list4->Delete_LinkedList();

    float arr5[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list5 = new LinkedList<float>(arr5, 5);
    assert(round_float(list5->GetLast(), 2) == round_float(0, 2));
    list5->Delete_LinkedList();

    float arr6[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list6 = new LinkedList<float>(arr6, 5);
    assert(round_float(list6->Get(0), 2) == round_float(5.5, 2));
    assert(round_float(list6->Get(1), 2) == round_float(6.6, 2));
    assert(round_float(list6->Get(3), 2) == round_float(-9.9, 2));
    list6->Delete_LinkedList();

    float arr7[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list1_2 = new LinkedList<float>(arr7, 5);
    auto* list2_2 = list1_2->GetSublist(1, 4);
    assert(round_float(list2_2->Get(0), 2) == round_float(6.6, 2));
    assert(round_float(list2_2->Get(1), 2) == round_float(-7.8, 2));
    assert(round_float(list2_2->Get(2), 2) == round_float(-9.9, 2));
    assert(list2_2->GetLength() == 3);
    list1_2->Delete_LinkedList();
    list2_2->Delete_LinkedList();

    float arr8[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list1_3 = new LinkedList<float>(arr8, 5);
    assert(list1_3->GetLength() == 5);
    list1_3->Delete_LinkedList();

    float arr9[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list1_4 = new LinkedList<float>(arr9, 5);
    list1_4->Append(-10.5);
    assert(list1_4->GetLength() == 6);
    assert(round_float(list1_4->Get(5), 2) == round_float(-10.5, 2));
    assert(round_float(list1_4->Get(4), 2) == round_float(0, 2));
    auto* list2_4 = new LinkedList<int>();
    list2_4->Append(5);
    assert(list2_4->GetLength() == 1);
    assert(list2_4->Get(0) == 5);
    list1_4->Delete_LinkedList();
    list2_4->Delete_LinkedList();

    float arr10[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list1_5 = new LinkedList<float>(arr10, 5);
    list1_5->Prepend(3.5);
    assert(list1_5->GetLength() == 6);
    assert(round_float(list1_5->Get(0), 2) == round_float(3.5, 2));
    assert(round_float(list1_5->Get(1), 2) == round_float(5.5, 2));
    list1_5->Delete_LinkedList();

    float arr11[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list7 = new LinkedList<float>(arr11, 5);
    list7->InsertAt(4, 3);
    assert(list7->GetLength() == 6);
    assert(round_float(list7->Get(3), 2) == round_float(4, 2));
    assert(round_float(list7->Get(2), 2) == round_float(-7.8, 2));
    assert(round_float(list7->Get(4), 2) == round_float(-9.9, 2));
    list7->Delete_LinkedList();

    float arr12[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list1_6 = new LinkedList<float>(arr12, 5);
    float arr22[] = { 5.5, 6.6, -7.8, -9.9, 0 };
    auto* list2_6 = new LinkedList<float>(arr22, 5);
    auto* list3_6 = list1_6->Concat(list2_6);
    assert(list3_6->GetLength() == 10);
    assert(round_float(list3_6->Get(5), 2) == round_float(5.5, 2));
    list1_6->Delete_LinkedList();
    list2_6->Delete_LinkedList();
    list3_6->Delete_LinkedList();
}

void ArraySequenceTest() {
    ArraySequence<int>* arraySequence1 = new ArraySequence<int>();

    assert(arraySequence1->GetLength() == 0);

    for (int i = 1; i < 100; i++) {
        auto* arr = new int[i];
        for (int j = 0; j < i; j++) {
            arr[j] = rand();
        }

        ArraySequence<int>* arraySequence2 = new ArraySequence<int>(arr, i);
        assert(arraySequence2->GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(arraySequence2->Get(k) == arr[k]);
        }
        ArraySequence<int>* arraySequence3 = new ArraySequence<int>(arraySequence2);
        assert(arraySequence3->GetLength() == arraySequence2->GetLength());
        assert(arraySequence2->GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(arraySequence3->Get(k) == arraySequence2->Get(k));
        }

        arraySequence3->Delete_ArraySequence();
        delete[] arr;
    }
    arraySequence1->Delete_ArraySequence();

    for (int i = 1; i < 100; i++) {
        auto array = new int[i];
        for (int j = 0; j < i; j++) {
            array[j] = rand();
        }
        ArraySequence<int>* arraySequence = new ArraySequence<int>(array, i);
        assert(arraySequence->GetFirst() == array[0]);
        assert(arraySequence->GetLast() == array[i - 1]);
        assert(arraySequence->GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(arraySequence->Get(k) == array[k]);
        }
        arraySequence->Delete_ArraySequence();
        delete[] array;
    }

    for (int i = 1; i < 100; i++) {
        auto array = new int[i];
        for (int j = 0; j < i; j++) {
            array[j] = rand();
        }
        ArraySequence<int>* arraySequence = new ArraySequence<int>(array, i);
        int item = rand();
        arraySequence->Append(item);
        assert(arraySequence->GetLength() == i + 1);
        assert(arraySequence->Get(i) == item);
        arraySequence->Prepend(item);
        assert(arraySequence->GetLength() == i + 2);
        assert(arraySequence->Get(0) == item);
        arraySequence->Delete_ArraySequence();
        delete[] array;
    }
}
void LinkedSequenceTest() {
    LinkedSequence<int>* listSequence1 = new LinkedSequence<int>();
    assert(listSequence1->GetLength() == 0);
    for (int i = 1; i < 100; i++) {
        auto array = new int[i];
        LinkedSequence<int>* listSequence2 = new LinkedSequence<int>();
        int num;
        for (int j = 0; j < i; j++) {
            num = rand();
            listSequence2->Append(num);
            array[j] = num;
        }

        assert(listSequence2->GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(listSequence2->Get(k) == array[k]);
        }
        LinkedSequence<int>* listSequence3 = new LinkedSequence<int>(listSequence2);
        assert(listSequence3->GetLength() == listSequence2->GetLength());
        for (int k = 0; k < i; k++) {
            assert(listSequence3->Get(k) == listSequence2->Get(k));
        }

        listSequence2->Delete_LinkedListSequence();
        listSequence3->Delete_LinkedListSequence();
        delete[] array;
    }
    listSequence1->Delete_LinkedListSequence();

    for (int i = 1; i < 100; i++) {
        auto array = new int[i];
        LinkedSequence<int>* listSequence = new LinkedSequence<int>();
        int num;
        for (int j = 0; j < i; j++) {
            num = rand();
            listSequence->Append(num);
            array[j] = num;
        }
        assert(listSequence->GetFirst() == array[0]);
        assert(listSequence->GetLast() == array[i - 1]);
        assert(listSequence->GetLength() == i);
        for (int k = 0; k < i; k++) {
            assert(listSequence->Get(k) == array[k]);
        }
        listSequence->Delete_LinkedListSequence();
        delete[] array;
    }

    for (int i = 1; i < 100; i++) {
        auto array = new int[i];
        LinkedSequence<int>* listSequence = new LinkedSequence<int>();
        int num;
        for (int j = 0; j < i; j++) {
            num = rand();
            listSequence->Append(num);
            array[j] = num;
        }
        int item = rand();
        listSequence->Append(item);
        assert(listSequence->GetLength() == i + 1);
        assert(listSequence->Get(i) == item);
        listSequence->Prepend(item);
        assert(listSequence->GetLength() == i + 2);
        assert(listSequence->Get(0) == item);
        listSequence->Delete_LinkedListSequence();
        delete[] array;
    }
}
