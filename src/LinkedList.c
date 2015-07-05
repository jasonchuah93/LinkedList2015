#include <stdio.h>
#include <malloc.h>
#include "LinkedList.h"

LinkedList *createLinkedList(){
		LinkedList *list = malloc(sizeof(LinkedList));
		list->head = NULL;
		list->tail = NULL;
		list->length = 0;
		return list ;
}

Element *listAddFirst(Element *newElement, LinkedList *list){
	if(list->head == NULL && list->tail == NULL){
		list->head = list->tail = newElement;
		newElement -> next = NULL;
	}else{
		newElement->next=list->head;
		list->head=newElement;
	}
	list->length++;
}