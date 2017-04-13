#include <stdio.h>
#include <stdlib.h> 
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

xs
void print_dir(char *d);

int main(int argc, char **argv)
{
  // One file passed
  if(argc == 2) {
    print_dir(argv[1]);
  }
  // No files passed
  else if(argc == 1) {
    print_dir(".");
  }
  else {
    //passing in way to many files
    fprintf(stderr, "lsdir: too many files.\n");
    exit(1);
  }
  return 0;
}

// Recursively prints out directories
void print_dir(char *d)
{
  DIR *dp;
  struct dirent *dir;
  chdir (d);
  if ((dp = opendir(".")) == NULL) {
    fprintf(stderr, "lsdir: cannot open directory %s.\n", d);
    exit(1);
  }
  //looping through the directory 
  while ((dir = readdir(dp)) != NULL) {
    if (dir->d_ino == 0) 
      continue;
    ///comparing the directory with the directory name 
    if (strcmp(dir->d_name,".") == 0 || 
      strcmp(dir->d_name,"..") == 0) continue;   

    if (dir->d_type & DT_DIR) {
      //print out the directory namme 
      printf("%s\n", dir->d_name);
      print_dir(dir->d_name);
      chdir("..");
    }
  }  
  closedir(dp);
}

