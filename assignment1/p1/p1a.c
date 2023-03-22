#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   
    int n = atoi(argv[1]);
    int level=0;
    
     pid_t parentid=getpid();
      printf("Main id %d level %d \n",parentid,level);
     
      for(int i = 0; i < n; i++){
          
          pid_t pid=fork();
          
          if(pid==0){
              level++;
               printf("Child %d with parent %d level %d \n",getpid(),parentid,level);
               parentid=getpid();
          }
         
          
          
      }
}

