#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


typedef struct VectorString {
	int len;
	int cap;
	char** array;
} VectorString;

VectorString* initVectorS() {
	return (VectorString*) calloc(1, sizeof(VectorString));
}

char* atS(VectorString* v, int idx) {
	return v->array[idx];
}

void pushBackS(VectorString* v, char* el) {
    if (v->len >= v->cap) {
        v->cap = (v->len == 0) ? 2 : v->cap * v->cap;
        v->array = realloc(v->array, v->cap*sizeof(char*));
    }
    v->array[v->len++] = el;
}

void printVectorS(VectorString *v) {
	for (int i=0; i<v->len; i++) {
		printf("%s\n", atS(v, i));
	}
}


typedef struct File {
	char* name;
	VectorString* content;
} File;

File* initMyFile() {
	return (File*) calloc(1, sizeof(File));
}


typedef struct VectorFile {
	int len;
	int cap;
	File** array;
} VectorFile;

VectorFile* initVectorF() {
	return (VectorFile*) calloc(1, sizeof(VectorFile));
}

File* atF(VectorFile* v, int idx) {
	return v->array[idx];
}

void pushBackF(VectorFile* v, File* el) {
    if (v->len >= v->cap) {
        v->cap = (v->len == 0) ? 2 : v->cap * v->cap;
        v->array = realloc(v->array, v->cap*sizeof(File*));
    }
    v->array[v->len++] = el;
}

void printVectorF(VectorFile *v) {
	for (int i=0; i<v->len; i++) {
		printf("%d file name: %s\ncontent:\n", i, v->array[i]->name);
		printVectorS(v->array[i]->content);
		printf("==========================\n\n");
	}
}



char* getSubPath(char* dirPath, char* subName) {
    char* subPath = (char*) calloc((strlen(dirPath) + strlen(subName) + 2), sizeof(char));
    strcpy(subPath, dirPath);
    subPath[strlen(dirPath)] = '/';
    strcat(subPath, subName);
    return subPath;
}

int isNecessary(char* dirName) {
	return (strcmp(dirName, ".") != 0 && strcmp(dirName, "..") != 0);
}

VectorString* getDataFromFile(char* filePath) {
	FILE* fin;
	fin = fopen(filePath, "r");

	VectorString* content = initVectorS();
	char* line = (char*) malloc(1024*sizeof(char));
	while (fgets(line, 1024, fin)) {
		pushBackS(content, line);
	}
	return content;
}

void addToTree(char* filePath, VectorFile* tree) {
	File* newFile = initMyFile();
	newFile->name = strrchr(filePath, '/') + 1;
	newFile->content = getDataFromFile(filePath);
	pushBackF(tree, newFile);
}

void getFiles(char* dirPath, VectorFile* tree) {
	DIR* dir = opendir(dirPath);

	struct dirent* de;
	while ( de = readdir(dir) ) {
		if (de->d_type == 4) {
			if (isNecessary(de->d_name)) {
				getFiles(getSubPath(dirPath, de->d_name), tree);
			}
		} else if (de->d_type == 8) {
			addToTree(getSubPath(dirPath, de->d_name), tree);
		}
	}
}

int compareVectorsS(VectorString* v1, VectorString* v2) {
	if (v1->len != v2->len) return 0;
	for (int i=0; i<v1->len; i++) {
		if (v1->array[i] == NULL || v2->array[i] == NULL) {
			if (v1->array[i] != v2->array[i]) return 0;
		} else if (strcmp(v1->array[i], v2->array[i]) != 0) return 0;
	}
	return 1;
}

int compareFiles(File* f1, File* f2) {
	return (strcmp(f1->name, f2->name) == 0 && compareVectorsS(f1->content, f2->content));
}

int max(int p1, int p2) {
	return (p1 >= p2) ? p1 : p2;
}

int main() {
	VectorFile* tree = initVectorF();
	getFiles("tests", tree);
	printVectorF(tree);

	int* repeats = (int*) calloc(tree->len, sizeof(int));

	for (int i=0; i<tree->len; i++) {
		for (int j=0; j<tree->len; j++) {
			if (compareFiles(tree->array[i], tree->array[j])) repeats[i]++;
		}
	}

	// for (int i=0; i<tree->len; i++) {
	// 	printf("%d ", repeats[i]);
	// }
	// printf("\n");

	int mx = -1;
	char* ans;
	for (int i=0; i<tree->len; i++) {
		if (repeats[i] == mx) {
			if (strcmp(tree->array[i]->name, ans) > 0) {
				ans = tree->array[i]->name;
			}
		}
		if (repeats[i] > mx) {
			mx = repeats[i];
			ans = tree->array[i]->name;
		}
	}


	printf("%d; %s\n", mx, ans);

	return 0;
}