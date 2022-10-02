#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
	int value;
	struct Person *link;
}Person;

int josephusProblem(int n, int k) {
	Person *head = NULL;
	Person *temp = NULL;
	for (int i = 1; i <= n; i++) {
		Person *person = (Person *)malloc(sizeof(Person));
		person->value = i;
		person->link = NULL;
		if (head == NULL) {
			head = person;
			temp = person;
		}
		else {
			temp->link = person;
			temp = person;
		}
	}
	temp->link = head;
	temp = head;
	while (n-- != 1) {
		for (int i = 1; i < k-1; i++) {
			temp = temp->link;
		}
		Person *extraTemp = temp->link;
		temp->link = extraTemp->link;
		free(extraTemp);
		extraTemp = NULL;
		temp = temp->link;
	}
	return temp->value;
}

int main() {
	printf("%d\n",josephusProblem(6, 2));
	return 0;
}