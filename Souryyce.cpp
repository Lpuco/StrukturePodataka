#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct artikli {
	char naziv[1024];
	float cijena;
	int kolicina;
	struct artikli* next;
}art;
typedef struct racuni {
	int godina;
	int mjesec;
	int dan;
	art* head;
	struct racuni* next;
}rac;
typedef rac* positionrac;
typedef art* positionart;
void unos(positionart head, positionart uneseni) {
	while ( head->next != NULL && strcmp(head->next->naziv , uneseni->naziv)<0 ) {
		head = head->next;
	}
	uneseni->next = head->next;
	head->next = uneseni;
}
int provjera(positionart prvi, positionart naziv) {
	while (prvi != naziv && prvi != NULL) {
		if (strcmp(prvi->naziv, naziv->naziv)==0) {
			prvi->kolicina += naziv->kolicina;
			free(naziv);
			return 1;
		}
	}
	return 0;

}
int provjerarac(positionrac prvi, positionrac trenutni) {
	positionart tt;
	positionart t;
	while (prvi != NULL) {
		if (prvi->dan == trenutni->dan && prvi->godina == trenutni->godina && prvi->mjesec == trenutni->mjesec) {
			t = trenutni->head;
			t = t->next;
			while (t != NULL) {
				tt = t->next;
				if (provjera(prvi->head->next, t)) {}
				else {
					unos(prvi->head, t);
				}
				t = tt;

			}
			free(trenutni);
			return 1;

		}
		prvi = prvi->next;
	}
	return 0;
}

int manji(positionrac prvi, positionrac trenutni) {
	if (prvi->godina < trenutni->godina) {
		return 1;
	}
	else if (prvi->godina == trenutni->godina && prvi->mjesec < trenutni->mjesec) {
		return 1;
	}
	else if (prvi->godina == trenutni->godina && prvi->mjesec == trenutni->mjesec && prvi->dan < trenutni->dan) {
		return 1;
	}
	return 0;
}
void sortunos(positionrac head, positionrac trenutni) {
	while (manji(head->next, trenutni) && head->next != NULL) {
		head = head->next;
	}
	trenutni->next = head->next;
	head->next = trenutni;
}
int manjii(positionrac prvi, int godina, int mjesec, int dan) {
	if (prvi->godina < godina) {
		return 1;
	}
	else if (prvi->godina == godina && prvi->mjesec < mjesec) { return 1; }
	else if (prvi->godina == godina && prvi->mjesec == mjesec && prvi->dan < dan) { return 1; }
	return 0;
}
int manjijednak(positionrac prvi, int godina, int mjesec, int dan) {
	if (prvi->godina < godina) {
		return 1;
	}
	else if (prvi->godina == godina && prvi->mjesec < mjesec) { return 1; }
	else if (prvi->godina == godina && prvi->mjesec == mjesec && prvi->dan < dan) { return 1; }
	else if (prvi->godina == godina && prvi->mjesec == mjesec && prvi->dan == dan) { return 1; }
	return 0;
}
positionrac prvipoin(int godina, int mjesec, int dan, positionrac prvi) {
	while (manjii(prvi, godina, mjesec, dan))
		prvi = prvi->next;
	return prvi;
}
positionrac druguipoin(int godina, int mjesec, int dan, positionrac prvi) {
	while (manjii(prvi, godina, mjesec, dan))
		prvi = prvi->next;
	return prvi;
}
int main() {
	FILE* fp = fopen("Filename.txt", "r");
	char lin[1024];
	rac head;
	positionrac p = &head;
	p->next = NULL;
	positionrac t;
	positionart tt;
	positionart arti;
	while (!feof(fp)) {

		fscanf(fp, "%s", lin);
		printf("%s\n", lin);
		t = (positionrac)malloc(sizeof(rac));
		FILE* fpp = NULL;
		fpp =fopen(lin, "r");
		if (fpp == NULL)
		{
			printf("greska");
				return 1;
		}
		fscanf(fpp, "%d %d %d", &t->godina, &t->mjesec, &t->dan);
		printf("%d", t->godina);
		t->head = (positionart)malloc(sizeof(art));
		tt = t->head;
		tt->next = NULL;
		while (!feof(fpp)) {
			arti = (positionart)malloc(sizeof(art));

			fscanf(fpp, "%s %d %f", arti->naziv, &arti->kolicina, &arti->cijena);
			if (provjera(tt->next, arti)) {}
			else { unos(tt, arti); }


		}
		if (provjerarac(p->next, t)) {}
		else {
			sortunos(p, t);
		}
		
		

	}/*
	int godina1, godina2, mjesec1, mjesec2, dan1, dan2;
	char naziv[1024];
	scanf("%d %d %d %d %d %d %d %s", &godina1, &godina2, &mjesec1, &mjesec2, &dan1, &dan2, naziv);
	t = prvipoin(godina1, mjesec1, dan1, head.next);
	positionrac ttt = druguipoin(godina2, mjesec2, dan2, head.next);
	float ukupno = 0;
	while (t != ttt) {
		tt = t->head->next;
		while (tt != NULL) {
			if (strcmp(tt->naziv, naziv)==0) {
				printf("%d\n", tt->kolicina);
				ukupno += (float)tt->kolicina * tt->cijena;
				break;
			}
			tt = tt->next;
		}
		t = t->next;
	}
	printf("%d", ukupno);

	/*t = &head;
	t = t->next;
	while (t->next != NULL) {
		printf("%d %d %d\n", t->godina, t->mjesec, t->dan);
		t = t->next;
	} */

}