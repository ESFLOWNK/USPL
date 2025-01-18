#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Trims an string from 'from' (inclusive)
    to 'to' (inclusive). And viceversa.     */
char* strtrim(char *str, int from, int to){
  char *c;
  if(from < 0) from = 0;
  if(to < 0){
    c = malloc(sizeof(char[120]));
    for(int i = 0; *(str+(from+i+to*-1)) != '\0'; i++){
      *(c+i) = *(str+(from+i));
      if(*(str+(from+i+to*-1)) == '\0') *(c+(i+1)) = '\0';
    }
    return c;
  }
  else if(from > to){int aux=to;to=from;from=to;} //It swaps from and to, variables
  else if(from == to){c = malloc(sizeof(char[2]));*c=*(str+from);*(c+1)='\0';return c;}; //Sorry dear coder reader... I messed it up.

  c = malloc(sizeof(char[to-from+1]));
  for(int i = 0; i <= to; i++){
    *(c+i) = *(str+(i+from));
    if(i+1 == to+1) *(c+(i+1)) = '\0';
  }

  return c;
}

int strfind(char *str, char *search){
  int j = 0, pos = -1;
  for(int i = 0; *(str+i) != '\0'; i++){
    if(*(str+i) == *(search+j) && pos == -1) {pos = i; j++;}
    else if(*(str+i) == *(search+j) && pos != -1) j++;
    else {j = 0; pos = -1;}

    if(*(search+j) == '\0') return pos; 
  }

  return -1;
}

void format_remove(char *line){
  // erase comments stage
  int cp = strfind(line,"//")-1; // cp: comment position
  char *formatedline = malloc(sizeof(char[120]));
  strcpy(formatedline,line);
  if(cp > -1) formatedline = strtrim(formatedline,0,cp);
  else if(cp == -1){
    *line = '\0';
    return;
  }
  else if(cp == -2) return;

  // Erase endline character stage
  cp = strfind(line,"\n");
  if(cp != -1) formatedline = strtrim(formatedline,0,cp-1);

  strcpy(line,formatedline);
  free(formatedline);
}

int interpretFile(char *filedir){
  // return codes: 0, succesful; 1, file not found; 2, memory error;3, code error; NULL, other error. 
  FILE *code;
  code = fopen(filedir,"r");
  if(code == NULL) return 1;

  char *line = malloc(sizeof(char[120]));
  if(line == NULL) return 2;

  while(fgets(line,120,code) != NULL){
    format_remove(line);
    /*format_replace(&line); By the way, it removes the quote marks and replace the $'s for the vars'*/

    if(*(line+0) == '~'){
      char *printmsg = strtrim(line,1,-1);
      printf("%s\n",printmsg);
      free(printmsg);
    }
  }

  free(line);
  fclose(code);
  return 0;
}

int main(int argc, char *argv[]){
  if(argc == 2){
    int r = interpretFile(argv[1]);
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
