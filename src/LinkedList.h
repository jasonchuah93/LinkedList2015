#ifndef LinkedList_H
#define LinkedList_H

typedef struct Element_t
{
	struct Element_t *next;
	void *data;
}Element;

typedef struct
{
	Element *head;
	Element *tail;
	int length;
}LinkedList;

LinkedList *createLinkedList();

#endif // LinkedList_H
