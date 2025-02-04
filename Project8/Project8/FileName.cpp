/*#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>
typedef struct mapa {
	int i, j;
	int kraj;
	struct mapa* desno;struct mapa* livo;struct mapa* gore;struct mapa* dole;
}map;
typedef map* position;
int smjerx[4] = { 1,0,-1,0 };
int smjery[4] = { 0,1,0,-1 };
char polje[20][20];
int provjera(int i, int j) {
	int r = 0;
	if (polje[i][j] == '#')
		return 0;
	for (int z = 0;z < 4;z++) {
		if (polje[i + smjerx[z]][j + smjery[z]] == '#') { r++; }
	}
	if (r >= 2) {
		return 1;
	}
	return 0;
}
int generiraj(int i,int j) {

	if (i == 10 || i == -1 || j == 10 || j == -1) {
		
		return 0;
	}
	if (provjera(i, j)) {
		return 0;
	}
	else { 
		
		polje[i][j] = '#';
		
	}
	if (i == 9 && j == 9) {
		
		return 1;
	}
	
	int r = rand()%4;
	while (!generiraj(i+smjerx[r], j +smjery[r])) {
		r = rand() % 4;
	}
	return 1;

}
int upisulistu(position head,int n) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			head->i = i;
			head->j = j;
			if (i == n - 1 && j == n - 1) {
				head->kraj = 1;
			}
			else { head->kraj = 0; }
			for (int z = 0;z < 4;z++) {
				if (polje[i + smjerx[z]][j + smjery[z]] == '#') {

				}
			}
		}
	}
	return 0;
}
int main() {
	srand(time(NULL));
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			polje[i][j] = '.';
		}
	}
	generiraj(0, 0);

	printf("111\n");
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			printf("%c", polje[i][j]);
		}
		printf("\n");
	}
	int n=10;
	map head;
	//upisulistu(&head,n);
	return 0;
}
*/