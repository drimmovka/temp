#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct Vector {
	int size;
	int capacity;
	char** array;
} Vector;

Vector* initVector() {
	Vector* v = (Vector*) calloc(1, sizeof(Vector));
	return v;
}

char* at(Vector* v, int idx) {
	return v->array[idx];
}

void printVector(Vector *v) {
	for (int i=0; i<v->size; i++) {
		printf("%s\n", at(v, i));
	}
}

void pushBack(Vector* v, char* el) {
    if (v->size >= v->capacity) {
        v->capacity = (v->size == 0) ? 2 : v->capacity*v->capacity;
        v->array = realloc(v->array, v->capacity*sizeof(char*));
    }
    v->array[v->size++] = el;
}

Vector* getNewCopy(Vector* v, char* el) {
	Vector* copy = initVector();
	for (int i=0; i<v->size; i++) {
		pushBack(copy, at(v, i));
	}
	pushBack(copy, el);
	return copy;
}

void getDataFromFile(char* filePath, Vector* v) {
	FILE* fin = fopen(filePath, "r");

	char* string = (char*) malloc(128*sizeof(char));
	while (fgets(string, 128, fin)) {
		if (strchr(string, '\n')) {
			*(strchr(string, '\n')) = '\0';
		}
		pushBack(v, string);
		string = (char*) malloc(128*sizeof(char));
	}

	fclose(fin);
}

char* getSubPath(char* dirPath, char* subName) {
    char* subPath = (char*) calloc((strlen(dirPath) + strlen(subName) + 2), sizeof(char));
    strcpy(subPath, dirPath);
    subPath[strlen(dirPath)] = '/';
    strcat(subPath, subName);
    return subPath;
}

void getTargetFilePath(char* dirPath, char** targetFilePath, char* targetFile) {
	DIR* dir = opendir(dirPath);

	struct dirent* de = readdir(dir);

	while (de) {
		char* subPath = getSubPath(dirPath, de->d_name);

		if (de->d_type == DT_REG && strcmp(de->d_name, targetFile) == 0) {
			(*targetFilePath) = (char*) malloc((strlen(subPath)+1)*sizeof(char));
			strcpy(*targetFilePath, subPath);
		}

		if (de->d_type == DT_DIR) {
			if (strcmp(de->d_name, ".") != 0 && strcmp(de->d_name, "..") != 0) {
				getTargetFilePath(subPath, targetFilePath, targetFile);
			}
		}

		de = readdir(dir);
	}

	closedir(dir);
}

void output(char* filePath, Vector* labyrinthPath) {
    FILE* fout = fopen(filePath, "w");
    char buffer[124];

    for (int i=0; i<labyrinthPath->size; i++) {
		sprintf(buffer, "%s\n", at(labyrinthPath, i));
    	fputs(buffer, fout);
	}

    fclose(fout);
}

void traversal(char* targetFilePath, Vector* labyrinthPath) {
	Vector* data = initVector();
	getDataFromFile(targetFilePath, data);


	if (strcmp(at(data, 0), "Minotaur") == 0) {
		output("result.txt", labyrinthPath);
		return;
	}

	if (strcmp(at(data, 0), "Deadlock") == 0) {
		return;
	}

	for (int i=0; i<data->size; i++) {
		char* targetFilePath = NULL;
		getTargetFilePath("./labyrinth", &targetFilePath, strchr(at(data, i), ' ') + 1);

		traversal(targetFilePath, getNewCopy(labyrinthPath, targetFilePath));
	}
}

int main() {
	char* targetFilePath = NULL;
	getTargetFilePath("./labyrinth", &targetFilePath, "file.txt");
	
	Vector* labyrinthPath = initVector();
	pushBack(labyrinthPath, targetFilePath);
	traversal(targetFilePath, labyrinthPath);
}