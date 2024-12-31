#ifndef HASH_MAP_H
#define HASH_MAP_H
#include<string>
#include"Array ADT.h"
using namespace std;
template<typename T>
class Pair
{
public:
    T val;
    int key;
    Pair<T>* next;
    Pair(T x, int y) :val(x), key(y), next(nullptr) {}
};
template<typename T>
class HashMap
{
    Pair<T>** list;
    int Hashing(int key);
public:
    HashMap();
    void put(int key, T value);
    T get(int key);
    void remove(int key);
    bool contains(int key);
};
template class Pair<int>;
template class Pair<string>;
template class HashMap<int>;
template class HashMap<string>;
#endif