#include <stdio.h>
#include <malloc.h>
#include <string.h>


#define BUFSIZE 1000


typedef struct Node{
	char *string;
	struct Node *next;

}Node;


Node* newNode(char *string){
	Node *result = malloc(sizeof(Node));
	result->string = malloc(strlen(string) + sizeof(char));
	result->string = strcpy(result->string, string);

	result->next = NULL;
	return result;
}


void deleteNode(Node *node){
	Node *tmp = node;
	
	while (node != NULL){
		node = node->next;
		free(tmp->string);
		free(tmp);
		tmp = node;
	}

}


void printList(Node *list){
	for (Node *token = list; token != NULL; token = token->next){
		printf("%s", token->string);
	}

}




int main(){
	char *buffer = malloc(BUFSIZE * sizeof(char));

	Node *currentNode = newNode("this is the head of the list");
	Node *head = currentNode;


	printf("head->string = %s\n", head->string);

	printf("Enter lines (len < %d). Print '.' to stop\n", BUFSIZE);

	while(fgets(buffer, BUFSIZE-1, stdin)){
		if (buffer[0] == '.'){
			break;
		}
		
		currentNode->next = newNode(buffer);

		currentNode = currentNode->next;
	}

	printf("head->next->string = %s\n", head->next->string);

	printList(head->next);


	free(buffer);
	free(currentNode);
	deleteNode(head);
	return 0;
}
