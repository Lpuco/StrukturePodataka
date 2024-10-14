#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char ime[10];
	char prezime[10];
	int bodovi;
}student;
int main() {
	FILE* f = fopen("lukaa.txt", "w");
	student* s = NULL;
	int n;
	scanf("%d", &n);
	s = (student*)malloc(n*sizeof(student));
	int i = 0;
	for (i = 0;i < n;i++) {
		scanf("%s %s %d", (s + i)->ime, (s + i)->prezime, &(s + i)->bodovi);
	}
	i = 0;
	for (int i = 0;i < n;i++) {
		fprintf(f,"%s %s %d", (s + i)->ime, (s + i)->prezime, (s + i)->bodovi);
	}
	
	fclose(f);
	return 0;
}