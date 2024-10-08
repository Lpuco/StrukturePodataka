#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int count_rows(char* filename);
int main() {
	return 0;
}
int count_rows(char* filename) {
	FILE* fp = NULL;
	fp = fopen(filename, "r");
	if (fp == NULL) {
		return ERROR_OPENING_FILE;

	}
	while (!feof(fp)) {
		char buffer[1024];
		fgets(buffer, 1024, fp);
	}
	fclose(fp);
	return 0;
}