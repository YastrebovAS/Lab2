#ifndef Sequence_hpp
#define Sequence_hpp

template <class T> class Sequence {
public:
    //Decomposition
    virtual T GetFirst() = 0;//get element on the first position
    virtual T GetLast() = 0;//get element on the last position
    virtual T Get(int index) = 0;//get index of Node
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;//get list of elements
    virtual int GetLength() = 0;// get array length

    //Operations
    virtual void Append(T item) = 0; //add elemetn at the end
    virtual void Prepend(T item) = 0; //add element at the beggining
    virtual void Set(T item, int index) = 0; // replace element at the index
    virtual void InsertAt(T item, int index) = 0; //add element at index
    virtual Sequence <T>* Concat(Sequence <T>* list) = 0; //concat two sequences

    //operators
    virtual T operator[] (int index) = 0;
};

#endif //Sequence_hpp