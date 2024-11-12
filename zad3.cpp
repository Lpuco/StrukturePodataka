#include<stdio.h>
#include<stdlib.h>
typedef struct el* position;
typedef struct el {
	int koef;
	int exp;
	position next;
} ell;
position unos(position ne) {
	position temp = (position)malloc(sizeof(ell));
	temp->exp = ne->exp;
	temp->koef = ne->koef;
	temp->next = NULL;
	return temp;
}
int zbrajanje(position prvi, position drugi, position zadnji) {
	while (prvi != NULL && drugi != NULL) {

		if (prvi->exp < drugi->exp) {
			zadnji->next = unos(prvi);
			prvi = prvi->next;

		}
		else if (drugi->exp < prvi->exp) {
			zadnji->next = unos(drugi);
			drugi = drugi->next;
		}
		else
		{
			zadnji->next = unos(prvi);
			prvi = prvi->next;
			drugi = drugi->next;
		}
		zadnji = zadnji->next;
	}
	if (prvi == NULL) {
		while (drugi != NULL) {
			zadnji = unos(drugi);
			drugi = drugi->next;
		}
		zadnji = zadnji->next;
	}
	else {
		while (prvi != NULL) {
			zadnji = unos(prvi);
			prvi = prvi->next;
			zadnji = zadnji->next;
		}
	}
	return 0;
}
void upisi(int exp, int koef, position head) {
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
void mnozenje(position prvi,position drugi,position head) {
	position drr = drugi;
	while (prvi != NULL) {
		drugi = drr;
		while (drugi != NULL) {
			int x = prvi->exp + drugi->exp;
			while (head->next != NULL && head->next->exp < x) {
				head = head->next;
			}
			if (x == head->next->exp) {
				head->next->koef = prvi->koef * drugi->koef;
			}
			else {
				position temp = (position)malloc(sizeof(ell));
				temp->exp = x;
				temp->koef= prvi->koef * drugi->koef;
				temp->next = head->next;
				head->next = temp;
			}
			drugi = drugi->next;
		}
		prvi = prvi->next;
	}
}
void citanje(FILE* fp) {
	int n = 0;
	char red[1024];
	fgets(red, 1024, fp);
	while () {

	}
}
int main() {
	ell head4;
	head4.next = NULL;
	ell head3;
	head3.next = NULL;
	ell head1;
	head1.next = NULL;
	ell head2;
	head2.next = NULL;
}