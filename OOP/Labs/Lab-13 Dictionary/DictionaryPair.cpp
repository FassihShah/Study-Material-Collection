#include"DictionaryPair.h"
template<typename T, typename R>
DictionaryPair<T,R>::DictionaryPair()
{
}
template<typename T, typename R>
DictionaryPair<T, R>::DictionaryPair(T k, R v):key(k),value(v)
{
}
template<typename T, typename R>
void DictionaryPair<T, R>::setKey(T k)
{
	key = k;
}
template<typename T, typename R>
void DictionaryPair<T, R>::setValue(R v)
{
	value = v;
}
template<typename T, typename R>
T DictionaryPair<T, R>::getKey()
{
	return key;
}
template<typename T, typename R>
R DictionaryPair<T, R>::getValue()
{
	return value;
}