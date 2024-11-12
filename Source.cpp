#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<stdlib.h>
#include<string>

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
void upisi(int koef, int exp, position head) {
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
void mnozenje(position prvi, position drugi, position head) {
	position drr = drugi;
	int x;
	while (prvi != NULL) {
		drugi = drr;
		while (drugi != NULL) {
			x = prvi->exp + drugi->exp;
			while (head->next != NULL && head->next->exp < x) {
				head = head->next;
			}
			if (head->next == NULL) {
				position temp = (position)malloc(sizeof(ell));
				temp->exp = x;
				temp->koef = prvi->koef * drugi->koef;
				temp->next = head->next;
				head->next = temp;
			}
			else if (x == head->next->exp ) {
				head->next->koef = prvi->koef * drugi->koef;
			}
			else {
				position temp = (position)malloc(sizeof(ell));
				temp->exp = x;
				temp->koef = prvi->koef * drugi->koef;
				temp->next = head->next;
				head->next = temp;
			}
			drugi = drugi->next;
		}
		prvi = prvi->next;
	}
}
void ispisi(position prvi) {
	while (prvi != NULL) {
		printf("%d %d\n", prvi->koef, prvi->exp);
		prvi = prvi->next;
	}
}
void citanje(FILE* fp,position head,position head2) {
	int n = 0;
	char red[1024];
	char* buff=red;
	fgets(red, 1024, fp);
	int exp, koef;
	while (strlen(buff)) {
		sscanf(buff, "%d %d %n", &koef, &exp, &n);
		buff += n;
		upisi(koef, exp, head);
	}
	fgets(red, 1024, fp);
	buff = red;
	while (strlen(buff)) {
		
		sscanf(buff, "%d %d %n", &koef, &exp, &n);
		buff += n;
		upisi(koef, exp, head2);
	}
}
int main() {
	FILE* fp = fopen("text.txt", "r");
	ell head4;
	head4.next = NULL;
	ell head3;
	head3.next = NULL;
	ell head1;
	head1.next = NULL;
	ell head2;
	head2.next = NULL;
	citanje(fp, &head1, &head2);
	zbrajanje(head1.next, head2.next, &head3);
	mnozenje(head1.next, head2.next, &head4);
	ispisi(head1.next);
	printf("\n");
	ispisi(head2.next);
	printf("\n");
	ispisi(head3.next);
	printf("\n");
	ispisi(head4.next);
}