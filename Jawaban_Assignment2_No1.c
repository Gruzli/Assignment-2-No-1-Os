#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    //Data
    char nim[] = "2602056832";
    char nama[] = "Gregorius Cahyadi";
    char kelas[] = "LA01";

    //Parent ID
    pid_t parentId = getpid();
    printf("Parent ID : %d\n", parentId);

    //Loop untuk membuat 40 child process
    for (int i = 0; i < 40; i++) {
        pid_t childId = fork();

        if (childId == 0) {
            printf("%s - %s - %s - Child ID : %d\n", nim, nama, kelas, getpid());
            exit(0);
        }
        else if (childId < 0) {
            perror("Fork failed");
            exit(1);
        }
    }

    // Parent process menunggu semua child selesai
    for (int i = 0; i < 40; i++) {
        wait(NULL);
    }

    return 0;
}