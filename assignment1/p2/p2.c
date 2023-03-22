#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>


#define READ_END	0
#define WRITE_END	1


int main(int argc, char *argv[]) {
   
    int n = atoi(argv[1]);
    int level=0;
    char *command= argv[2];
    char *argument= argv[3];
    int fd[n][2];
    int devout;
    char arr[n][100];
    double buf[n][sizeof(double)];
    int status=0;
    
    //pipes for each fork
    
       
    
   
    
     pid_t parentid=getpid();
      //printf("Main id %d level %d \n",parentid,level);
      
       struct timeval s;
          gettimeofday(&s,NULL);
     
      for(int i = 0; i < n; i++){
            
          if (pipe(fd[i]) == -1) {
		fprintf(stderr,"Pipe failed");
		exit(1);
	}
         
         
          
          pid_t pid=fork();
          
          
          
          if(pid==0){
              
              
              
              struct timeval f;
              level++;
              // printf("Child %d with parent %d level %d \n",getpid(),parentid,level);
               parentid=getpid();
               //we are in child process
               
               devout = open("/dev/null", 0666);
               dup2(devout, 1);
               
               
               close(devout); 
               gettimeofday(&f,NULL);
               double elapsed = (f.tv_sec - s.tv_sec) +
                (f.tv_usec - s.tv_usec) / 1000000.0;
                
                
                
                close(fd[i][READ_END]);
                //char string[]="tes";
                write(fd[i][WRITE_END], &elapsed,sizeof(elapsed));
                gettimeofday(&s,NULL);
                execlp(command,command,argument,NULL);
                exit(0);
                
            
               
               
               
          }
        
         
      }
       
       
       
       
       
       
       
         
          
              
              for(int i=0;i<n;i++){
                  close(fd[i][WRITE_END]);
                  read(fd[i][READ_END], &buf[i], sizeof(buf[i]));
                   close(fd[i][READ_END]);
              }
              double max=0;
              double min=9999;
              double total=0;
               for(int i=0;i<n;i++){
                 printf("Child %d Executed in %f\n ",i+1,*buf[i]);
                 //printarray(arr);
                 if(*buf[i]<min){
                     min=*buf[i];
                 }
                 else if(*buf[i]>max){
                     max=*buf[i];
                 }
                 total+=*buf[i];
              }
              printf("Max: %f\n ",max);
              printf("Min: %f\n ",min);
              printf("Avg: %f\n ",total/n);
     
                
               
                
                
      
      
     
      
}

