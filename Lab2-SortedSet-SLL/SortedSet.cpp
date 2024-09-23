#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
    rel = r;
    head = nullptr;
    nrElems = 0;
}


bool SortedSet::add(TComp elem) {
    //if the Set is Empty
    if (head == nullptr) {
        head = new Node(elem);
        nrElems++;
        return true;
    }
    
	//search for elem with 2 pointers
    Node * current = head;
    Node * prev = nullptr;
    
    //position prev and current to correct spot and according to rel
    while (current != nullptr && rel(current->elem, elem)) {
        if (current->elem == elem) {
            return false; // elem already exists
        }
        prev = current;
        current = current->next;
    }
      
    Node * newNode = new Node(elem);
    if (prev == nullptr) {  //check if head
        newNode->next = head;
        head = newNode;
    } else if (current == nullptr){  //check if last
        prev->next = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
    
    nrElems++;
    return true;
}


bool SortedSet::remove(TComp elem) {
    //if set is empty
    if (head == nullptr) {
        return false;
    }
	//go to node
    Node * current = head;
    Node * prev = nullptr;
    
    while (current != nullptr && current->elem != elem) {
        prev = current;
        current = current->next;
    }
    //if not found nothing to remove
    if (current == nullptr) {
        return false;
    }
    //if head
    if (current == head) {
        head = head->next;
    } else {
        prev->next = current->next; // if in middle or last
    }
    
    delete current;
    nrElems--;
	return true;
}


bool SortedSet::search(TComp elem) const {
    Node * current = head;
    while (current != nullptr) {
        if (current->elem == elem) {
            return true;
        }
        current = current->next;
    }
	return false;
}


int SortedSet::size() const {
	return nrElems;
}


bool SortedSet::isEmpty() const {
	return nrElems == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    while (head != nullptr) {
        Node * temp = head;
        head = head->next;
        delete temp;
    }
}
