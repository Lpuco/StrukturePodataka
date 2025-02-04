#include<stdio.h>
#include<string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
typedef struct mapa {
	int broj;
	int bio;
	int put;
	struct mapa* next;
}map;
typedef map* position;

int smjerx[4] = { 1,0,-1,0 };
int smjery[4] = { 0,1,0,-1 };
//char polje[1][1];
int rr=0;
int iii = 0,oo=0;
int pozicijax = 0, pozicijay = 0;
int br =50;
int najblizi=2*br;
position najblizih;
int granicei = -1, granicej = -1;
int provjera(int i, int j,position head) {
	position t = head;
	int r = 0;
	rr = 0;
	while (head != NULL && head->broj < i * br + j) {
		head = head->next;
	}
	if (head!=NULL && head->broj == i * br + j) {
		rr = 3;
		return 0;
	}
	head = t;
	while (head != NULL) {
		for (int k = 0;k < 4;k++) {
			if (((head->broj / br) + smjery[k]) * br + head->broj % br + smjerx[k] == i * br + j) {
				r++;
			}
		}
		head=head->next;
	}
	if (r >= 2 || najblizi == br-1-i+br-1-j) {
		return 1;
	}
	return 0;
}
int unoslist(int i, int j, position head) {
	printf("\n\n");
	while (head->next!=NULL && i * br + j > head->next->broj) {
		head = head->next;
	}
	if (head->next == NULL && head->broj != i * br + j) {
		position t = NULL;
		t = (position)malloc(sizeof(map));
		if (t == NULL) {
			printf("greska");
		}
		t->broj = i * br + j;
		t->next = head->next;
		head->next = t;
		//polje[i][j] = '#';
	}
	else if (head->next!=NULL && head->broj != i * br + j && head->next->broj != i * br + j) {
		
			position t = NULL;
			t = (position)malloc(sizeof(map));
			if (t == NULL) {
				printf("greska");
			}
			t->broj = i * br + j;
			t->next = head->next;
			head->next = t;
			//polje[i][j] = '#';
	}
	head->next->bio = 0;
	head->next->put = 0;
	if (najblizi > br-1-i+br-1-j) {
		najblizi = br - 1 - i + br - 1 - j;
		najblizih = head->next;
	}
	position t;
	t = head;
	printf("\n\n");
	/*while (t->next != NULL) {
		for (int i = t->broj;i < t->next->broj;i++) {
			if (i % br == 0) {
				printf("\n");
			}
			if (i == t->broj && t->broj != pozicijay * br + pozicijax) {
				printf("#");
			}
			else if (i == pozicijay * br + pozicijax) {
				printf("x");
			}
			else {
				printf(".");
			}
		}
		t = t->next;

	}*/
	return 1;
}
int novi(position head,position headp) {
	int i = head->broj / br;
	int j = head->broj % br;
	if (j + 1 < br) {
		granicej = j;
		granicei = i - 1;
		return 1;
	}
	else {
		
		granicei = i;
		granicej = j - 1;
		return 2;
	}
	
}
int generiraj(int i, int j,int x,position head,position headp) {
	iii++;
	if (iii == 200) {
		 novi(najblizih, headp);
		iii = 0;
		i = granicei + 1;
		j = granicej + 1;


	}
	
	//printf("%d\n", oo++);
	if (i == br || i == granicei || j == br || j == granicej) {

		return 0;
	}
	if (provjera(i, j,headp)) {
		return 0;
	}
	else if(rr!=3) {

		unoslist(i, j, headp);

	}
	
	if (i == br-1 && j == br-1) {

		return 1;
	}

	int r = rand() % 4;
	while (!generiraj(i + smjery[r], j + smjerx[r],r,head,headp)) {
		r = rand() % 4;
	}
	return 1;

}
void gore(position head) {
	if (pozicijay-1< 0) {
		return;
	}
	while (head!=NULL && head->broj < (pozicijay - 1) * br + pozicijax) {
		head = head->next;
	}
	if (head != NULL && head->broj != (pozicijay - 1) * br + pozicijax) {
		return;
	}
	pozicijay = pozicijay - 1;
}
void dole(position head) {
	if (pozicijay +1>=br ) {
		return;
	}
	while (head != NULL && head->broj < (pozicijay + 1) * br + pozicijax) {
		head = head->next;
	}
	if (head != NULL && head->broj != (pozicijay + 1) * br + pozicijax) {
		return;
	}
	pozicijay = pozicijay + 1;
}
void desno(position head) {
	if (pozicijax + 1 >= br) {
		return;
	}
	while (head != NULL && head->broj < (pozicijay) * br + pozicijax+1) {
		head = head->next;
	}
	if (head != NULL && head->broj != (pozicijay) * br + pozicijax+1) {
		return;
	}
	pozicijax = pozicijax + 1;
}
void livo(position head) {
	if (pozicijax - 1 < 0) {
		return;
	}
	while (head != NULL && head->broj < (pozicijay)*br + pozicijax - 1) {
		head = head->next;
	}
	if (head != NULL && head->broj != (pozicijay)*br + pozicijax - 1) {
		return;
	}
	pozicijax = pozicijax - 1;
}
int s = 0;
int nadiput(position head,int prethodni,position headp) {
	if (head->next == NULL) {
		head->put = 1;
		return 1;
	}
	
	position t=headp;
	while (t != NULL) {
		for (int k = 0;k < 4;k++) {
			if (((t->broj / br) + smjery[k]) * br + t->broj % br + smjerx[k] == head->broj && t->broj!=prethodni) {
				
				//printf("ndjdj");
				if (nadiput(t, head->broj, headp)) {
					
					t->put = 1;
					return 1;
				}
			}
		}
		t = t->next;
	}
	return 0;
	
}
int main() {
	srand(time(NULL));
	for (int i = 0;i < br;i++) {
		for (int j = 0;j < br;j++) {
			//polje[i][j] = '.';
		}
	}
	//polje[0][0] = '#';
	map head;
	head.next = NULL;
	head.broj = 0;
	najblizih = &head;
	generiraj(0, 0,4,&head,&head);

	//printf("111\n");
	position t = &head;
	t->put = 1;
	nadiput(t, -1, t);
	/*for (int i = 0;i < br;i++) {
		for (int j = 0;j < br;j++) {
			//printf("%c", polje[i][j]);
		}
		printf("\n");
	}*/
	//printf("%d\n", iii);
	int provjera = 1;
	system("cls");
	char smjer;
	int bb = 1;
	int brgr = 0;
	while (provjera == 1) {
		system("cls");
		t = &head;
		
		while (t->next != NULL) {
			for (int i = t->broj;i < t->next->broj;i++) {
				if (i % br == 0) {
					printf("\n");
				}
				
				if (i == t->broj && t->broj != pozicijay * br + pozicijax) {
					printf("#");
				}
				else if (i == pozicijay * br + pozicijax) {
					printf("x");
					if (bb == 0 && t->put==1) {
						brgr++;
						bb = 1;
					}
					else if (bb == 1 && t->put == 0) {
						bb = 0;
					}
				}
				else {
					printf(".");
				}
			}
			t = t->next;

		}
		printf("#\n");
		t = t->next;
		//scanf_s("%c",
		// &smjer);
		printf("%d", brgr);
		smjer= _getch();
		switch (smjer)
		{
		case 'w':
			gore(&head);
			break;
		case 'd':
			desno(&head);
			break;
		case 's':
			dole(&head);
			break;
		case 'a':
			livo(&head);
			break;

		}
		if (pozicijax == br - 1 && pozicijay == br - 1) {
			provjera = 0;
			//printf("prosli ste");
		}
	}
	system("cls");
	t = &head;
	while (t->next != NULL) {
		for (int i = t->broj;i < t->next->broj;i++) {
			if (i % br == 0) {
				printf("\n");
			}
			if (i == t->broj && t->broj != pozicijay * br + pozicijax) {
				printf("#");
			}
			else if (i == pozicijay * br + pozicijax) {
				printf("x");
			}
			else {
				printf(".");
			}
		}
		t = t->next;

	}
	printf("x");
	
	
	
	return 0;
}
