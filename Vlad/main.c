#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int validator(const char* str, const char* file_name){
    int flag = 0;
    if (strlen(file_name) == 5){
        for (int i = 0; i < strlen(str); i++){
            if (str[i] == file_name[0]){
                flag++;
            }
        }
    }
    return flag;
}

char* pathcat(const char* dir_name, const char* file_name){
    char* full_path = (char*) calloc(strlen(dir_name) + strlen(file_name) + 2, sizeof(char));
    sprintf(full_path,"%s/%s", dir_name, file_name);
    return full_path;
}



void list_dir(const char* dir_name, const char* str){
    // printf("%s\n", dir_name);
    DIR* dir = opendir(dir_name);
    if (dir){
        struct dirent* dir_element = readdir(dir);
        while (dir_element) {
            if (dir_element->d_type == DT_REG){
                if (validator(str, dir_element->d_name)){
                    printf("%s\n", dir_element->d_name); /* нужно сделать полный путь и выводить в файл */
                }
            }
            else if (dir_element->d_type == DT_DIR && strcmp(dir_element->d_name, ".") != 0 && strcmp(dir_element->d_name, "..") != 0){
                char* new_dir = pathcat(dir_name, dir_element->d_name);
                list_dir(new_dir, str);
            }
            dir_element = readdir(dir);
        }
        closedir(dir);
    }
    else
        printf("Can't open the directory\n");
}

int main() {
    char string[1000];
    const char* root = "./tmp";
    fgets(string,1000,stdin);
    list_dir(root, string);
}