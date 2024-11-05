#include<stdio.h>
#include<stdlib.h>
typedef struct el* position;
typedef struct el {
	int koef;
	int exp;
	position next;
} ell;
position unos(position ne,position zadnji) {
	position temp = (position)malloc(sizeof(ell));
	temp->exp = ne->exp;
	temp->koef = ne->koef;
	zadnji->next = temp;
	temp->next = NULL;
	return temp;
}
int zbrajanje(position prvi, position drugi, position zadnji) {
	while (prvi != NULL && drugi != NULL) {
		if (prvi->exp < drugi->exp) {
			zadnji=unos(prvi,zadnji);
			prvi = prvi->next;
			
		}
		else if (drugi->exp<prvi->exp) {
			zadnji=unos(drugi,zadnji);
			drugi = drugi->next;
		}
		else
		{
			zadnji=unos(prvi,zadnji);
			prvi = prvi->next;
			drugi = drugi->next;
		}
	}
	if (prvi == NULL) {
		while (drugi != NULL) {
			zadnji=unos(drugi,zadnji);
			drugi = drugi->next;
		}
	}
	else {
		while (prvi != NULL) {
			zadnji=unos(prvi,zadnji);
			prvi = prvi->next;
		}
	}
	return 0;
}
void upisi(int exp,int koef,position head) {
	while (head->next != NULL && head->next->exp < exp) {
		head = head->next;
	}
	position ne = NULL;
	ne = (position)malloc(sizeof(ell));
	ne->exp = exp;
	ne->koef = koef;
	position t;
	t = head->next;
	head->next = ne;
	ne->next = t;
}
int main() {
	ell head3;
	head3.next = NULL;
	ell head1;
	head1.next = NULL;
	ell head2;
	head2.next = NULL;
}