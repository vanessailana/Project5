#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


//determining which files are being passed 
int main(int argc, char **argv)
{

if(argc==2)
{
printdirectory(argv[1]);
}

else if(argc==1) {

printdirectory(".");
}

else {

fprintf(stderr,"too many files");
exit(1);
}
return 0;
}

