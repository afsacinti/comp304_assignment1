#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUMCOUNT 1000

int main(int argc, char* argv[]) {

    int searchNumber = atoi(argv[1]);
    int numChildren = atoi(argv[2]);
int numbers[NUMCOUNT];

    
    char inputBuffer[10];
    for (int i=0;i<NUMCOUNT;i++) {
        fgets(inputBuffer, 10, stdin);
        numbers[i] = atoi(inputBuffer);
    }
     
    
    
    int partSize = NUMCOUNT / numChildren;
   

    pid_t pid=getpid();
    
    for (int i = 0; i < numChildren; i++) {
        int startIndex = i * partSize;
            int finishIndex;
        if(i==numChildren-1){
            finishIndex=NUMCOUNT;
        }
        else{
            finishIndex=(i+1)*partSize;
        }

    

pid = fork();
    if (pid == 0) {
            for (int i = startIndex; i < finishIndex; i++) {
                if (numbers[i] == searchNumber) {
                    printf("%d 'th number is %d", i,searchNumber);
                        exit(0);
                }
                
                    
                
            }
        exit(1);
            kill(pid, SIGKILL);
        }
    }

    

    
   
}
