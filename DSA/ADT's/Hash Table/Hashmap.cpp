#include<iostream>
#include"Hashmap.h"
template<typename T>
HashMap<T>::HashMap()
{
    list = new Pair<T>*[10];
    for (int i = 0; i < 10; i++)
    {
        list[i] = nullptr;
    }

}
template<typename T>
int HashMap<T>::Hashing(int key)
{
    return key % 10;
}
template<typename T>
void HashMap<T>::put(int key, T value)
{
    int index = Hashing(key);
    Pair<T>* temp = list[index];
    if (temp == nullptr)
    {
        list[index] = new Pair<T>(value, key);
        return;
    }
    Pair<T>* prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            temp->val = value;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = new Pair<T>(value, key);

}
template<typename T>
T HashMap<T>::get(int key)
{
    int index = Hashing(key);
    Pair<T>* temp = list[index];
    if (temp == nullptr)
    {
        cout << "!!!Not found!!!";
        exit(0);
    }
    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            return temp->val;
        }
        temp = temp->next;
    }
    cout << "!!!Not found!!!";
    exit(0);
}
template<typename T>
void HashMap<T>::remove(int key)
{
    int index = Hashing(key);
    Pair<T>* temp = list[index];
    Pair<T>* prev = nullptr;
    if (temp == nullptr)
        return;
    while (temp->next != nullptr)
    {
        if (temp->key == key)
            break;
        prev = temp;
        temp = temp->next;
    }
    if (temp != nullptr && temp->key == key)
    {
        if (prev == nullptr)
        {
            list[index] = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
    }
}
template <typename T>
bool HashMap<T>::contains(int key)
{
    int index = Hashing(key);
    Pair<T>* temp = list[index];
    if (temp == nullptr)
        return false;
    while (temp != nullptr)
    {
        if (temp->key == key)
            return true;
        temp = temp->next;
    }
    return false;
}
