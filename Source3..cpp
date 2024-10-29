#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct osoba* pozicija;
struct osoba {
	char ime[10];
	char prezime[10];
	int godina;
	pozicija next;
};
int dodajpocetak(char ime[10], char prezime[10], int godina, pozicija p) {
	pozicija q = NULL;
	q = (pozicija)malloc(sizeof(osoba));
	if (q == NULL) {
		return 0;
	}
	strcpy_s((q->ime), ime);
	strcpy_s(q->prezime, prezime);
	q->godina = godina;
	pozicija t = p->next;
	p->next = q;
	q->next = t;
	return 0;
}
void ispisilistu(pozicija p) {
	while (p != NULL) {
		printf("%s %s %d \n", p->ime, p->prezime, p->godina);
		p = p->next;
	}

}
int dodajnakraj(char ime[10], char prezime[10], int godina, pozicija p) {
	while (p->next != NULL) {
		p = p->next;
	}
	dodajpocetak(ime, prezime, godina, p);
	return 0;
}
pozicija pronalazi(char prezime[10], pozicija p) {
	while (p != NULL && strcmp(prezime, p->prezime) != 0) {
		p = p->next;
	}
	if (p == NULL) {
		return NULL;
	}
	return p;

}
int brisi(char prezime[10], pozicija p) {
	while (strcmp(p->next->prezime, prezime) != 0 && p->next != NULL) {
		p = p->next;
	}
	if (p->next == NULL) {
		printf("element ne postoji");
		return 0;
	}
	pozicija t = p->next;
	p->next = p->next->next;
	free(t);

}
void dodajizael(pozicija prvi, char prezime[10],char ime[10],char prezimee[10],int godina) {
	pozicija p = NULL;
	p=pronalazi(prezime, prvi);
	if (p == NULL) {
		printf("greska");
		return;
	}
	dodajpocetak(ime, prezimee, godina, p);
}
pozicija prethodnik(pozicija head,char prezime[10]) {
	while (head->next != NULL && strcmp(prezime, head->next->prezime) != 0) {
		head = head->next;
	}
	if (head->next == NULL) {
		return NULL;

	}
	return head;
}
void dodajispred(pozicija head,char nadi[10]) {
	head = prethodnik(head, nadi);
	char ime[10], prezime[10];
	int godina;
	scanf("%s %s %d", ime, prezime, &godina);
	dodajpocetak(ime, prezime, godina, head);
}
void sort(pozicija head) {
	int t = 1;
	pozicija q = head;
	while (t) {
		t = 0;
		q = head;
		while (q->next->next != NULL) {
			if (strcmp(q->next->prezime, q->next->next->prezime) > 0) {
				pozicija prvi = q->next;
				pozicija drugi = q->next->next;
				q->next = drugi;
				prvi->next = drugi->next;
				drugi->next = prvi;
				t = 1;
				
			}
			q = q->next;
		}

	}
}
int main() {
	osoba p;
	pozicija head = NULL;
	head = (pozicija)malloc(sizeof(osoba));
	head->next = NULL;
	char ime[10] = "luka";
	char prezime[10] = "puco";
	dodajpocetak(ime, prezime, 2004, head);
	ispisilistu(head->next);
}