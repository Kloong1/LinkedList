#include <stdio.h>
#include <stdlib.h>
#define DATA int

typedef struct _NODE { 
	DATA data;
	struct _NODE* next;
} NODE;

void PrintAll(NODE* head){
	if(head == NULL){
		printf("Error: Head is NULL\n");
		return;
	}
	NODE* node = head->next;

	printf("\n");
	while(node!=NULL){
		printf("%d -> ",node->data);
		node = node->next;
	}
	printf("\n");
}

void Add(NODE* head){
	if(head == NULL){
		printf("Error: Head is NULL\n");
		return;
	}
	
	printf("\n\nAdd\n\n");

	int input = 0;
	printf("Input Data: ");
	scanf("%d", &input);
	
	NODE* temp = head;
	
	while(temp->next != NULL)
		temp = temp->next;
	
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = input;
	newNode->next = NULL;

	temp->next = newNode;
}

void Delete(NODE* head){
	if(head == NULL){
		printf("Error: Head is NULL\n");
		return;
	}

	printf("\n\nDelete\n\n");

	int input = 0;
	printf("Input Data: ");
	scanf("%d", &input);

	NODE* node = head->next;
	NODE* preNode = head;

	while(node!=NULL){
		if(node->data == input) break;
		preNode = node;
		node = node->next;
	}

	if(node == NULL){
		printf("Error: %d doesn't exist!\n\n", input);
		return;
	}

	preNode->next = node->next;
	free(node);
}

void DeleteAll(NODE* head){
	if(head == NULL){
		printf("Error: Head is NULL\n");
		return;
	}

	printf("\n\nDelete All\n\n");

	NODE* node = head->next;
	NODE* preNode = NULL;

	while(node!=NULL){
		preNode = node;
		node = node->next;
		free(preNode);
	}

	head->next = NULL;
}

void Find(NODE* head){
	if(head == NULL){
		printf("Error: Head is NULL\n");
		return;
	}

	printf("\n\nFind\n\n");

	int input = 0;
	printf("Input Data: ");
	scanf("%d", &input);
	
	int count = 1;
	NODE* node = head->next;

	while(node!=NULL){
		if(node->data == input) break;
		node = node->next;
		count++;
	}
	
	if(node == NULL){
		printf("%d doesn't exist!", input);
		return;
	}
	
	printf("Data: %d, Location: %d", input, count);
}
