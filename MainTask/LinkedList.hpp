#ifndef link_list_hpp
#define link_list_hpp

#include "Sequence.hpp"

#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;
const string INDEX_OUT_OF_RANGE = "Index out of range";
const string SIZE_LESS_0 = "Size is less than 0";


template <typename T> class Place {
public:
    T value;
    Place<T>* next_el;

    Place() {
        value = 0;
        next_el = nullptr;
    };
    Place(T value, Place<T>* next_el) {
        this->value = value;
        this->next_el = next_el;
    };
};

template <typename T> 
class LinkedList {
private:
    Place<T>* head = nullptr;
    int size;
public:
    //Constructor

    LinkedList() {//Create empty list
        size = 0;
        head = nullptr;
    }
    LinkedList(int size) {//create empty list of given lenght
        this->size = size;
        head = nullptr;
    }
    LinkedList(T* items, int count) {//copy elements from given array
        if (count < 0) {
            throw length_error(SIZE_LESS_0);
        };
        for (int i = 0; i < count; i++) {
            Append(items[i]);
        };
    };
    LinkedList(const LinkedList<T>& list) {// Copyed constructor
        for (int i = 0; i < list.GetLength(); i++) {
            this->Append(list.Get(i));
        }
    };
    LinkedList(LinkedList<T>* list) {
        head = list->head;
        size = list->size;
    }
    //Destructor
    ~LinkedList() {//Destructor
        Delete_LinkedList();
    };
    void Delete_LinkedList() {
        Place<T>* hold = new Place<T>();
        head = nullptr;
        while (head != nullptr) {
            hold = head;
            delete hold;
            head = head->next_el;
        }
        size = 0;
    }

    //Decomposition(Descriprion of each is in sequence.hpp)
    T GetFirst() const {
        if (head == nullptr) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        return head->value;
    };
    T GetLast() const {
        if (head == nullptr) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        return Get(size - 1);
    };
    T Get(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        Place<T>* hold = head;
        for (int i = 0; i < index; i++) {
            hold = hold->next_el;
        }
        return hold->value;
    };
    LinkedList<T>* GetSublist(int start, int end) {
        if (start >= size || end >= size || start < 0 || end < 0) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }

        LinkedList<T>* new_list = new LinkedList<T>();
        for (int i = start; i < end; i++) {
            new_list->Append(this->Get(i));
        }
        new_list->size = end - start;
        return new_list;
    };
    int GetLength() const {
        return size;
    };


    //Operations
    void Append(T value) {//adds element to the end
        Place<T>* newElem = new Place<T>;
        newElem->value = value;
        newElem->next_el = nullptr;
        if (head == nullptr) {
            head = newElem;
            size = 1;
            return;
        }
        else {
            Place<T>* hold = head;
            while (hold->next_el != nullptr) {
                hold = hold->next_el;
            }
            size++;
            hold->next_el = newElem;
        }
    };
    void Prepend(T value) {//adds element to the beginning
        this->head = new Place<T>(value, this->head);
        size++;
    };
    void InsertAt(T value, int index) {//adds element to specific position
        if (index < 0 || index > this->size) {
            throw out_of_range("InsertAt : Index out of range");
        }
        Place<T>* hold = head;
        while (hold->next_el != nullptr) {
            hold = hold->next_el;
        }
        Place<T>* new_node = new Place<T>(value, hold->next_el);
        hold->next_el = new_node;
        size++;
    };
    void Set(T value, int index) {//replaces element at specific position
        if (index < 0 || index > size - 1)
            throw out_of_range(INDEX_OUT_OF_RANGE);
        Place<T>* gold = head;
        for (int i = 0; i < index; i++)
            gold = gold->next_el;
        gold->value = value;
    }
    LinkedList<T>* Concat(LinkedList<T>* list) {//combines two lists
        LinkedList<T>* newList = new LinkedList<T>();
        newList->head = this->head;
        Place<T>* hold = this->head;
        for (int i = 0; i < this->GetLength() - 1; i++) {
            hold = hold->next_el;
        };
        newList->size = list->size + this->size;
        hold->next_el = list->head;
        return newList;
    };


    //Operators
    Place<T>* operator[] (int index) {
        if (index < 0 || index > this->size - 1) {
            throw out_of_range(INDEX_OUT_OF_RANGE);
        }
        Place<T>* hold = head;
        for (int i = 0; i < index; i++) {
            hold = hold->next_el;
        }
        return hold;
    };

};
#endif /* link_list_hpp */