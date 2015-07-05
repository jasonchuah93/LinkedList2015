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



