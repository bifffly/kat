#include "kat.h"

static FILE* openFile(char* path, char* method) {
	FILE* file = fopen(path, method);
	if (file == NULL) {
		fprintf(stderr, "kat: %s: No such file or directory\n", path);
		exit(10);
	}
	return file;
}

void view(char* path) {
	FILE* file = openFile(path, "r");
	char* line = calloc(1024, sizeof(char));
	while (fgets(line, 1024, file) != NULL) {
		printf("%s", line);
	}
	fclose(file);
}

void mirror() {
	char* line = calloc(1024, sizeof(char));
	while (fgets(line, 1024, stdin) != NULL) {
		printf("%s", line);
	}
}

void cat(char* path1, char* path2) {
	char* line = calloc(1024, sizeof(char));

	FILE* file1 = openFile(path1, "r");
	while (fgets(line, 1024, file1) != NULL) {
		printf("%s", line);
	}
	fclose(file1);

	FILE* file2 = openFile(path2, "r");
	while (fgets(line, 1024, file2) != NULL) {
		printf("%s", line);
	}
	fclose(file2);
}
