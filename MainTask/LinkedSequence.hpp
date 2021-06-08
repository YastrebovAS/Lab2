#ifndef LinkSequence_hpp
#define LinkSequence_hpp

#include "LinkedList.hpp"
#include "Sequence.hpp"

template <typename T> class LinkedSequence : public Sequence<T> {
private:
    LinkedList<T>* linkedSequence;
public:
    //Constructor
    //Constructor
    LinkedSequence() {
        linkedSequence = new LinkedList<T>();
    };
    LinkedSequence(T* items, int count) {
        linkedSequence = new LinkedList<T>(items, count);
    };
    LinkedSequence(LinkedList<T>& list) {
        linkedSequence = LinkedList<T>(list);
    }
    LinkedSequence(LinkedList<T>* list) {
        linkedSequence = list;
    };
    LinkedSequence(LinkedSequence<T>* list) {
        linkedSequence = list->linkedSequence;
    }

    //Destructor
    ~LinkedSequence() {
        linkedSequence->Delete_LinkedList();
    }
    void Delete_LinkedListSequence() {
        linkedSequence->Delete_LinkedList();
    }
    //Decomposition
    T GetFirst() override {
        return linkedSequence->GetFirst();
    };
    T GetLast() override {
        return linkedSequence->GetLast();
    };
    T Get(int index) override {
        return linkedSequence->Get(index);
    };
    LinkedSequence<T>* GetSubsequence(int startIndex, int endIndex) override {
        LinkedList<T>* list;
        list = this->linkedSequence->GetSublist(startIndex, endIndex);
        auto* list_sequence = new LinkedSequence<T>(list);
        return list_sequence;
    };
    int GetLength() override {
        return linkedSequence->GetLength();
    };


   //Operations
    void Append(T item) override {
        linkedSequence->Append(item);
    }; 
    void Prepend(T item) override {
        linkedSequence->Prepend(item);
    }; 
    void Set(T item, int index) override {
        linkedSequence->Set(item, index);
    }; 
    void InsertAt(T item, int index) override {
        linkedSequence->InsertAt(item, index);
    }; 
    LinkedSequence <T>* Concat(Sequence<T>* list) override {
        auto* new_LinkedList = new LinkedSequence<T>(linkedSequence);
        for (int i = 0; i < list->GetLength(); i++) {
            new_LinkedList->Append(list->Get(i));
        }

        return new_LinkedList;
    }; 
   //operators
    T operator[] (int index) override {
        return linkedSequence->Get(index);
    };
};
#endif //LinkSequence_hpp