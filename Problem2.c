#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct num
{
    short x;
}num;



int main(int argc,char* argv[]){
if (argc < 1)
{
   perror("No given files!");
   exit(-1);
}else{
      int sum = 0;
    for (int i = 1; i < argc; i++)
    {
        num y;
         pid_t pid = fork();
         
        FILE *fp = fopen(argv[i],"rb");
        if (fp<0)
        {
            perror("error");
            exit(-1);
        }
          fseek(fp,0,SEEK_SET);

         while (fread(&y,sizeof(num),1,fp) != 0)
         {
             sum += y.x;
         }
         

   
          if ( fclose(fp) == -1){
          perror("Exit file!");
        return 1;
    }
         exit(EXIT_SUCCESS);
    }
    
    for (int i = 1; i < argc; i++)
    {
        wait(NULL);
    }
    
   
    
}
return 0;
}