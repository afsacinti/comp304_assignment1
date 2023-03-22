#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   
    int maxZombie = atoi(argv[1]);
    int level=0;
    
    
     
      
     
      for(int i = 0; i < maxZombie; i++){
          
          pid_t pid=fork();
          
          if(pid==0){
              
               exit(0);
          }
          else{
              
              sleep(5);
              
          }
         
          
          
      }
      kill(getpid());
      printf("killed!");
}



