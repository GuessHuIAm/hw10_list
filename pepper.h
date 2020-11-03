#ifndef PEPPER_H
#define PEPPER_H

struct pepper{
        char name[256];
        int scoville;
	int eaten;
	struct pepper *next;
};

void print_pepper(struct pepper *p);
struct pepper * new_pepper(char *n, int s, int e, struct pepper *next);
void repepper(struct pepper *p, char *n, int s, int e, struct pepper *next);
void print_list(struct pepper *p);
struct pepper * insert_front(struct pepper *p, char *, int s, int e);
struct pepper * free_list(struct pepper *p);
struct pepper * remove_pepper(struct pepper *front, char *);

#endif
