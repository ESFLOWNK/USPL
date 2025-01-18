#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char interpretFile(){

  

  return 0;
}

int main(int argc, char *argv[]){
  if(argc == 2){
    unsigned char r = interpretFile(argv[1]);
    switch (r) {
      case 1: printf("File error ocurred!\n");
              break;
      case 2: printf("Memory error, try to run the program again.\n");
              break;
    }
    return r;
  } else if(argc == 4 && argv[2] == "-c"){
    // Beautiful code goes here!
    // If there's a -c in the args, compile it!
    printf("Compile feature coming soon!");
  }

  return 0;
}
