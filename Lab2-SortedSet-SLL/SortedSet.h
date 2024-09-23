#pragma once

typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111

class SortedSetIterator;

class SortedSet {
	friend class SortedSetIterator;
private:
    struct Node {
        TElem elem;
        Node * next;
        Node(const TElem& e): elem(e), next(nullptr){};
    };
    
    Node * head;
    int nrElems;
    Relation rel;

public:
	//constructor
	SortedSet(Relation r);
	bool add(TComp e);
	bool remove(TComp e);
	bool search(TElem elem) const;
	int size() const;
	bool isEmpty() const;

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;
    // destructor
	~SortedSet();
};
