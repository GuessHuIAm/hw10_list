#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pepper{
        char name[256];
        int scoville;
        int eaten;

	struct pepper *next;
};

//print pepper
void print_pepper(struct pepper *p){
	printf("Pepper: %s\tSpicyness: %d\tAmount eaten: %d\n", p->name, p->scoville, p->eaten);
}

//new pepper
struct pepper * new_pepper(char *n, int s, int e, struct pepper *nextpepper){
	struct pepper *np;

	np = malloc(sizeof(struct pepper));
	strncpy(np->name, n, sizeof(np->name) - 1);
	np->scoville = s;
	np->eaten = e;
	np->next = nextpepper;

	return np;
}

//change the pepper
void repepper(struct pepper *p, char *n, int s, int e, struct pepper *nextpepper){
	strncpy(p->name, n, sizeof(p->name) - 1);
	p->scoville = s;
	p->eaten = e;
	p->next = nextpepper;
}

//print a pepper list
void print_list(struct pepper *p){
	while(p != NULL){
		print_pepper(p);
		p = p->next;
	}
}

//insert a pepper to the front
struct pepper * insert_front(struct pepper *list, char *n, int s, int e){
	struct pepper *np = new_pepper(n, s, e, list);
	return np;
}

//free a pepper list
struct pepper * free_list(struct pepper *p){
	struct pepper *first = p;
	struct pepper *next;

	while(p != NULL){
		next = p->next;
		printf("Free %s\n", p->name);
		free(p);
		p = next;
	}
	return first;
}

//remove a pepper from a list
struct pepper * remove_pepper(struct pepper *front, char *name){
	struct pepper* first = front;
	struct pepper* previous = NULL;

	while (front != NULL){
		if (!strcmp(front->name, name)){
			if (previous != NULL){
				previous->next = front->next;
				free(front);
				break;
			}
			return front->next;
		}
		previous = front;
		front = front->next;
	}
	return first;
}
