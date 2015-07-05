#include "unity.h"
#include "LinkedList.h"
#include <malloc.h>

void setUp(){}

void tearDown(){}

void test_createLinkedList_should_return_initialized_object(void){
	LinkedList *list;
	list = createLinkedList();
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_EQUAL(0,list->length);
}

void test_listAddFirst_should_add_first_element_into_linkedList(){
	LinkedList *list;
	list = createLinkedList();
	
	Element ele1 = {.next = (Element *)NULL, .data = (Element *)1};
	
	listAddFirst(&ele1,list);
	TEST_ASSERT_EQUAL(1,ele1.data);
	TEST_ASSERT_EQUAL(1,list->head->data);
	TEST_ASSERT_EQUAL(1,list->tail->data);
	TEST_ASSERT_EQUAL(list->head,list->tail);
	TEST_ASSERT_EQUAL(1,list->length);
	TEST_ASSERT_NULL(list->head->next);
}



