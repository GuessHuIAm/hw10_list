#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "pepper.h"

int main(){
	srand(time(NULL));

	struct pepper *pepper_list = NULL;

	pepper_list = insert_front(pepper_list, "Carolina Reaper", 2000000, random()%100);
	pepper_list = insert_front(pepper_list, "Ghost Pepper", 1400000, random()%100);
	pepper_list = insert_front(pepper_list, "Habanero", 350000, random()%100);
	pepper_list = insert_front(pepper_list, "Spicy Jelly Beans", 1000, random()%100);
	pepper_list = insert_front(pepper_list, "Normal Jelly Beans", 10, random()%100);

	printf("Peppers in the list!\n");
	print_list(pepper_list);

	pepper_list = remove_pepper(pepper_list, "Ghost Pepper");
	printf("\nRemoving the Ghost Pepper because Halloween is over.\n");
	print_list(pepper_list);

	pepper_list = remove_pepper(pepper_list, "Spicy Jelly Beans");
	pepper_list = remove_pepper(pepper_list, "Normal Jelly Beans");
	printf("\nRemoving both Jelly Beans because those are not good things.\n");
	print_list(pepper_list);

	printf("\nLetting the peppers run free.\n");
	free_list(pepper_list);
	return 0;

	printf("\nWhat's left:");
	print_list(pepper_list);

	return 0;
}
