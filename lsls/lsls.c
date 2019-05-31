#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * Main
 */

#define PROMPT "INPUT PATH: "
#define MAX_COMMANDLINE_SIZE 2048
#define MAX_TOKENS 100

char **parse_commandline(char *commandline, char **args, int *args_count)
{
  char *token;
  // don't forget to derefence since args_count came in as a pointer
  *args_count = 0;

  token = strtok(commandline, " \t\n\r");

  while (token != NULL)
  {
    // put the token in the args array
    args[*args_count] = token;
    (*args_count)++;
    token = strtok(NULL, " \t\n\r");
  }

  // add a NULL to the end of the args array to indicate that there are no more args
  args[*args_count] = NULL;
  return args;
}

int main(int argc, char **argv)
{

  char commandline[MAX_COMMANDLINE_SIZE];
  char *args[MAX_TOKENS];
  int args_count;

  DIR *d;
  struct dirent *dir;

  while (1)
  {

    printf("%s", PROMPT);

    fgets(commandline, sizeof(commandline), stdin);
    // be able to exit the shell
    // to do that let's check for end of file (CTRL-D)
    if (feof(stdin))
    {
      break;
    }
    // parse the commandline

    parse_commandline(commandline, args, &args_count);

    for (int i = 0; i < args_count; i++)
    {
      printf("%s\n", args[i]);
    }

    if (args_count == 0)
    {
      d = opendir(".");
      if (d)
      {
        while ((dir = readdir(d)) != NULL)
        {

          printf("%s\n", dir->d_name);
        }
        closedir(d);
      }

      continue;
    }

    // allow the user to exit by typing 'exit'
    if (strcmp(args[0], "exit") == 0)
    {
      break;
    }

    if (args_count > 0)
    {

      d = opendir(args[0]);
      if (d)
      {
        while ((dir = readdir(d)) != NULL)
        {

          printf("%s\n", dir->d_name);
        }
        closedir(d);
      }
      continue;
    }
  }

  return 0;
}