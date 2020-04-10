#ifndef HEAP_H
#define HEAP_H
#include <iostream>

const int min = 10;
enum Type { Min, Max };
template <class T>
class Heap
{
public:
    // 为真取前一个
    typedef bool (*Func)(T &t1, T &t2);
    Heap();

    void setType(Type t);
    Type type();

    inline void registerFunc(Func f) { campare = f; }

    void build(T *t, int length);
    void insert(T t);

    T *heap();
    T del();

    T head();

private:
    T *tArray = nullptr;
    int currentLength;
    int currentCap;
    Func campare;
    Type t;

    void swap(T *first, T *secend)
    {
        auto tem = *first;
        *first = *secend;
        *secend = tem;
    }
    void copy(T *copy, T *copied, int len);
};

template <class T>
Heap<T>::Heap()
{
}
template <class T>
void Heap<T>::setType(Type t)
{
    this->t = t;
}
template <class T>
Type Heap<T>::type()
{
    return t;
}
template <class T>
void Heap<T>::build(T *t, int length)
{
    if (tArray != nullptr)
        delete[] tArray;
    tArray = new T[length * 2];
    currentLength = length;
    currentCap = length * 2;
    for (auto i = length / 2; i > 0; i--) {
        if ((i * 2) < length) {
            auto root = &t[i - 1];
            auto left = &t[2 * i - 1];
            auto right = &t[2 * i];
            T *bools;
            bools = campare(*left, *right) ? left : right;
            if (!campare(*root, *bools)) {
                swap(root, bools);
            } else {
                auto root = &t[i - 1];
                auto left = &t[2 * i - 1];
                if (!campare(*root, *left))
                    swap(root, left);
            }
        }
    }

    for (auto i = 1; i <= length / 2; i++) {
        if ((i * 2) < length) {
            auto root = &t[i - 1];
            auto left = &t[2 * i - 1];
            auto right = &t[2 * i];
            T *bools;
            bools = campare(*left, *right) ? left : right;
            if (!campare(*root, *bools)) {
                swap(root, bools);
            } else {
                auto root = &t[i - 1];
                auto left = &t[2 * i - 1];
                if (!campare(*root, *left))
                    swap(root, left);
            }
        }
    }
    copy(t, tArray, length);
}
template <class T>
void Heap<T>::insert(T t)
{
    if (tArray == nullptr) {
        tArray = new T[min];
        tArray[0] = t;
        currentLength = 1;
        currentCap = min;
        return;
    }
    if (currentLength == currentCap) {
        auto temArray = new T[currentLength + 1];
        copy(tArray, temArray, currentLength);
        delete tArray;
        tArray = new T[2 * currentCap];
        copy(temArray, tArray, currentLength);
        delete[] temArray;
        currentCap = 2 * currentCap;
    }
    currentLength++;
    tArray[currentLength - 1] = t;
    for (auto i = currentLength / 2; i > 0; i--) {
        if ((i * 2) < currentLength) {
            auto root = &tArray[i - 1];
            auto left = &tArray[2 * i - 1];
            auto right = &tArray[2 * i];
            T *bools;
            bools = campare(*left, *right) ? left : right;
            if (!campare(*root, *bools)) {
                swap(root, bools);
            } else {
                auto root = &tArray[i - 1];
                auto left = &tArray[2 * i - 1];
                if (!campare(*root, *left))
                    swap(root, left);
            }
        }
    }
}

template <class T>
T *Heap<T>::heap()
{
    return tArray;
}

template <class T>
T Heap<T>::del()
{
    if (tArray == nullptr)
        return T();
    auto head = tArray[0];
    tArray[0] = tArray[currentLength - 1];
    for (auto i = 1; i <= (currentLength - 1) / 2; i++) {
        if ((i * 2) < currentLength - 1) {
            auto root = &tArray[i - 1];
            auto left = &tArray[2 * i - 1];
            auto right = &tArray[2 * i];
            T *bools;
            bools = campare(*left, *right) ? left : right;
            if (!campare(*root, *bools)) {
                swap(root, bools);
            } else {
                auto root = &tArray[i - 1];
                auto left = &tArray[2 * i - 1];
                if (!campare(*root, *left))
                    swap(root, left);
            }
        }
    }
    currentLength--;
    return head;
}
template <class T>
T Heap<T>::head()
{
    if (tArray)
        return tArray[0];
    return T();
}

template <class T>
void Heap<T>::copy(T *copy, T *copied, int len)
{
    for (auto i = 0; i < len; i++)
        copied[i] = copy[i];
}

#endif // HEAP_H
