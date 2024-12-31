#ifndef RELATION_H
#define RELATION_H
#include"OrderedPair.h"
class Relation
{
	Set setA;
	OrderedPair* orderedPairList;
	int capacity;
	int noOfOrderedPair;
	void reSize();
	void shrink();
	bool isUnique(const OrderedPair&);
	bool isValidOrderedPair(const OrderedPair&);
public:
	Relation(Set);
	Relation(const Relation&);
	~Relation();
	void insert(const OrderedPair&);
	void remove(const OrderedPair&);
	int getCardinality() const;
	bool compare(const Relation&) const;
	bool isReflexive() const;
	bool isSymmetric() const;
	bool isIrreflexive() const;
	bool isTransitive() const;
	void print() const;
};
#endif