#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main(int argc, char **argv)
{
  int pipe_1[2], pipe_2[2];
  int pid;

  char *wc_args[] = {"wc", NULL};
  char *grep_args[] = {"grep", "--binary-files=text", "-i", "hai",  NULL};

  pipe(pipe_1);
  pipe(pipe_2);

  pid = fork();

  if (pid < 0)
    perror("ERROR IN FORKING!");
  else if (pid > 0)
  {
    char count;
    close(pipe_1[0]);
    close(pipe_2[1]);

    dup2(pipe_2[0], 0);
    close(pipe_2[0]);

    FILE *f = fopen("input.txt", "r");
    while ((count = fgetc(f)) != EOF)
      write(pipe_1[1], &count, 1);
    close(pipe_1[1]);
    
    wait(NULL);  

    execvp(*wc_args, wc_args);
  }
  else
  {
    close(pipe_1[1]);
    close(pipe_2[0]);

    dup2(pipe_1[0], 0);
    dup2(pipe_2[1], 1);

    close(pipe_1[0]);
    close(pipe_2[1]);

    execvp(*grep_args, grep_args);
  }
}