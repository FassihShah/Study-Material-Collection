#include<iostream>
#include"Relation.h"
using namespace std;
Relation::Relation(Set s):setA(s)
{
	capacity = 0;
	noOfOrderedPair = 0;
	orderedPairList = nullptr;
}
Relation::Relation(const Relation& ref) :setA(ref.setA)
{
	orderedPairList = nullptr;
	capacity = ref.capacity;
	noOfOrderedPair = ref.noOfOrderedPair;
	if (noOfOrderedPair != 0)
	{
		orderedPairList = new OrderedPair[noOfOrderedPair];
	}
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		orderedPairList[i] = ref.orderedPairList[i];
	}
}
Relation::~Relation()
{
	if (orderedPairList != nullptr)
	{
		delete[]orderedPairList;
		capacity = 0;
		noOfOrderedPair = 0;
		orderedPairList = nullptr;
	}
}
void Relation::reSize()
{
	int cap = capacity + 1;
	OrderedPair* temp = new OrderedPair[cap];
	int i = 0;
	if (noOfOrderedPair != 0)
	{
		for (i = 0;  i < noOfOrderedPair; i = i + 1)
		{
			temp[i] = orderedPairList[i];
		}
	}
	i = noOfOrderedPair;
	capacity = cap;
	orderedPairList = temp;
	noOfOrderedPair = i;
}
void Relation::shrink()
{
	int i = 0, cap = capacity - 1;
	OrderedPair* temp = new OrderedPair[cap];
	if (noOfOrderedPair != 0)
	{
		for (i; i < cap && i < noOfOrderedPair; i = i + 1)
		{
			temp[i] = orderedPairList[i];
		}
	}
	int t = (noOfOrderedPair > cap ? cap : noOfOrderedPair);
	this->~Relation();
	capacity = cap;
	orderedPairList = temp;
	noOfOrderedPair = t;
}
bool Relation::isValidOrderedPair(const OrderedPair& pair)
{
	if (setA.isMember(pair.atA()) && setA.isMember(pair.atB()))
	{
		return true;
	}
	return false;
}
bool Relation::isUnique(const OrderedPair& pair)
{
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		if (orderedPairList[i].atA() == pair.atA() && orderedPairList[i].atB() == pair.atB())
			return false;
	}
	return true;
}
void Relation::insert(const OrderedPair& ref)
{
	if (capacity == noOfOrderedPair)
		reSize();
	if (isValidOrderedPair(ref) && isUnique(ref))
	{
		orderedPairList[noOfOrderedPair] = ref;
		noOfOrderedPair = noOfOrderedPair + 1;
	}
}
void Relation::remove(const OrderedPair& ref)
{
	if (noOfOrderedPair == 0 || isUnique(ref))
		return;
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		if (orderedPairList[i].atA() == ref.atA() && orderedPairList[i].atB() == ref.atB())
		{
			orderedPairList[i] = orderedPairList[noOfOrderedPair - 1];
			shrink();
		}
	}
}
bool Relation::compare(const Relation& ref) const
{
	if (noOfOrderedPair != ref.noOfOrderedPair)
		return false;
	bool flag = true;
	bool status = true;
	for (int i = 0; i < noOfOrderedPair && status; i = i + 1)
	{
		flag = true;
		for (int j = 0; j < noOfOrderedPair && flag; j = j + 1)
		{
			if ((orderedPairList[i].atA() == ref.orderedPairList[j].atA()) && (orderedPairList[i].atB() == ref.orderedPairList[j].atB()))
			{
				flag = false;
				status = true;
			}
			else
			{
				status = false;
			}
		}
	}
	return status;
}
int Relation::getCardinality() const
{
	return noOfOrderedPair;
}
bool Relation::isReflexive() const
{
	int count = 0;
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		if (orderedPairList[i].atA() == orderedPairList[i].atB())
		{
			count = count + 1;
		}
	}
	if (count == setA.getCardinality())
	{
		return true;
	}
	return false;
}
bool Relation::isIrreflexive() const
{
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		if (orderedPairList[i].atA() == orderedPairList[i].atB())
		{
			return false;
		}
	}
	return true;
}
bool Relation::isSymmetric() const
{
	bool status = true, flag = true;
	for (int i = 0; i < noOfOrderedPair && status; i = i + 1)
	{
		flag = true;
		for (int j = 0; j < noOfOrderedPair && flag; j = j + 1)
		{
			if ( (i !=j ) && (orderedPairList[i].atA() == orderedPairList[j].atB()) && (orderedPairList[j].atA() == orderedPairList[i].atB()))
			{
				flag = false;
				status = true;
			}
			else
			{
				status = false;
			}
		}
	}
	return status;
}
bool Relation::isTransitive() const
{
	for (int i = 0; i < noOfOrderedPair; i++) 
	{
		int a = orderedPairList[i].atA();
		int b = orderedPairList[i].atB();
		for (int j = 0; j < noOfOrderedPair; j++) 
		{
			if (orderedPairList[j].atA() == b) 
			{
				bool found = false;
				for (int k = 0; k < noOfOrderedPair; k++) 
				{
					if (orderedPairList[k].atA() == a && orderedPairList[k].atB() == orderedPairList[j].atB()) 
					{
						found = true;
						break;
					}
				}
				if (!found) {
					return false;
				}
			}
		}
	}
	return true;
}
void Relation::print() const
{
	for (int i = 0; i < noOfOrderedPair; i = i + 1)
	{
		cout << "(" << orderedPairList[i].atA() << "," << orderedPairList[i].atB() << ")";
		cout << " ";
	}
}