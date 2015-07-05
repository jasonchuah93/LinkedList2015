#include "unity.h"
#include "LinkedList.h"
#include <malloc.h>

void setUp(){}

void tearDown(){}

void test_createLinkedList_should_return_initialized_object(void){
	LinkedList *list = createLinkedList();
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_EQUAL(0,list->length);
}

void test_listAddFirst_should_add_first_element_into_linkedList(){
	LinkedList *list = createLinkedList();
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	
}

void test_listAddFirst_should_add_elements_into_linkedList(){
	LinkedList *list = createLinkedList();
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	Element ele2 = {.next = (Element *)NULL, .data = (Element *)5};
	Element ele3 = {.next = (Element *)NULL, .data = (Element *)10};
	Element ele4 = {.next = (Element *)NULL, .data = (Element *)15};
	Element ele5 = {.next = (Element *)NULL, .data = (Element *)20};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele2,list);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(5,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele3,list);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(10,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele4,list);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(15,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele5,list);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(20,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(5,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
}

void test_listRemoveFirst_should_remove_first_element_from_linkedList(){
	LinkedList *list = createLinkedList();
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listRemoveFirst(list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(NULL,list->head);
	TEST_ASSERT_EQUAL(NULL,list->tail);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
}

void test_listRemoveFirst_should_remove_elements_from_linkedList(){
	LinkedList *list = createLinkedList();
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	Element ele2 = {.next = (Element *)NULL, .data = (Element *)5};
	Element ele3 = {.next = (Element *)NULL, .data = (Element *)10};
	Element ele4 = {.next = (Element *)NULL, .data = (Element *)15};
	Element ele5 = {.next = (Element *)NULL, .data = (Element *)20};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele2,list);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(5,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele3,list);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(10,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele4,list);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(15,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddFirst(&ele5,list);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(20,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_NOT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(5,list->length);
	TEST_ASSERT_NOT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listRemoveFirst(list); //Removed 20
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(15,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(4,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveFirst(list); //Removed 15
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(10,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(3,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveFirst(list); //Removed 10
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(5,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(2,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveFirst(list); //Removed 5
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(5,ele2.data);
	TEST_ASSERT_EQUAL(10,ele3.data);
	TEST_ASSERT_EQUAL(15,ele4.data);
	TEST_ASSERT_EQUAL(20,ele5.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NOT_NULL(list->head);
	TEST_ASSERT_NOT_NULL(list->tail);
	
	listRemoveFirst(list); //Removed 1
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(NULL,list->head);
	TEST_ASSERT_EQUAL(NULL,list->tail);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(0,list->length);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
}

void test_listAddLast_should_add_first_element_into_linkedList(){
	LinkedList *list = createLinkedList();
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	
	listAddLast(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
}

void test_listAddLast_should_add_elements_into_linkedList(){
	LinkedList *list = createLinkedList();
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	Element ele2 = {.next = (Element *)NULL, .data = (Element *)5};
	
	listAddLast(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
	TEST_ASSERT_NULL(list->tail->next);
	
	listAddLast(&ele2,list);
	TEST_ASSERT_EQUAL(5,ele2.data);
	
}

