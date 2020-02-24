#include <stdio.h>
#include <stdlib.h>
#define DATA int

typedef struct _NODE { 
	DATA data;
	struct _NODE* next;
} NODE;


int PrintMenu();

NODE* Init();

void PrintAll(NODE*);
void Add(NODE*);
void Delete(NODE*);
void Find(NODE*);
void DeleteAll(NODE*);

int main()
{
	int input = 0;
	NODE* head = Init();
	
	printf("\n\nLinked List\n\n");

	while(1){

		input = PrintMenu();

		switch (input) {
			case 1:
				Add(head);
				break;
			case 2:
				Delete(head);
				break;
			case 3:
				Find(head);
				break;
			case 4:
				PrintAll(head);
				break;
			case 5:
				DeleteAll(head);
				break;
		}

		fflush(stdin);

	}	
	
	DeleteAll(head); //Free all nodes
	free(head);

	return 0;
}

int PrintMenu(){
	printf("\n1. Add\n");
	printf("2. Delete\n");
	printf("3. Find\n");
	printf("4. Print All\n");
	printf("5. Delete All\n");

	int input = 0;
	printf("Input: ");
	scanf("%d", &input);
	
	if(input < 1 || input > 5){
		printf("Wrong Input!\n\n");
		fflush(stdin);
		return PrintMenu();
	}

	return input;
}

NODE* Init(){
	NODE* head = (NODE*)malloc(sizeof(NODE));
	head->data = 0;
	head->next = NULL;

	return head;
}
