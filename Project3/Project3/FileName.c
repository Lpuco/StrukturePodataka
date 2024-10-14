/*
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char ime[10];
	char prezime[10];
	int bodovi;
}student;
int main() {
	FILE* f = fopen("lukaa.txt", "r");
	 student* s = NULL;
	 s = (student*)malloc(sizeof(student));
	 int i = 0;
	while (!feof(f)) {
		s = realloc(s, (i + 1) * sizeof(student));
		fscanf(f, "%s %s %d", (s + i)->ime, (s + i)->prezime, (s + i)->bodovi);
		i++;

	}
	for (int j = 0;j < i;j++) {
		printf("%s %s %d \n", (s + j)->ime, (s + j)->prezime, (s + j)->bodovi);
	}
} */