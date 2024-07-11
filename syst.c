#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid;
    pid = fork();   
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        printf("Hello from Child Process!\n");
    } else {
        printf("Hello from Parent Process!\n");	 }  
    return 0;	}


#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    } else if (pid == 0) {
        execlp("ls", "ls", NULL);
        printf("execlp failed\n");
        return 1;
    } else {
        printf("Parent process\n");
    }
    return 0;
}


#include <stdio.h>
#include <dirent.h>
int main() {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) {
        printf("Could not open current directory\n");
        return 1;
    }
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}	


#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    char filename[] = "example.txt";
    struct stat fileStat;
    if (stat(filename, &fileStat) == -1) {
        perror("stat");
        return 1;
    }
    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", fileStat.st_size);
    printf("Owner ID: %d\n", fileStat.st_uid);
    printf("Group ID: %d\n", fileStat.st_gid);
    printf("Permissions: %o\n", fileStat.st_mode & 0777);
    return 0;
}
