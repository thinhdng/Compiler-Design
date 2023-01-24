#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create the rot13 function with string input
char *rot13(const char *src)
{

    //if string is null, abort
    if(src == NULL){
      return NULL;
    }
    
    //create the result string array and allocate memory according to how long the OG string is 
    char* result = malloc(strlen(src));
    
    //loop through the string and encode or decode the string word for word   
    if(result != NULL){
      strcpy(result, src);
      char* current_char = result;
      
      while(*current_char != '\0'){
        //Only increment alphabet characters
        if((*current_char >= 97 && *current_char <= 122) || (*current_char >= 65 && *current_char <= 90)){
          if(*current_char > 109 || (*current_char > 77 && *current_char < 91)){
            //Characters that wrap around to the start of the alphabet
            *current_char -= 13;
          }else{
            //Characters that can be safely incremented
            *current_char += 13;
          }
        }
        current_char++;
      }
    }
    return result;
}

int main(int argc, char *argv[])
{
    //initialising
    FILE    *textfile;
    char    *text;
    long    numbytes;
    char options[100];
    char filename[100];
    
    //take command inputs and name of file 
    scanf("%s %s", options, filename);
    
    //open the file
    textfile = fopen(filename, "r");
    if(textfile == NULL)
       { printf("File not found");
        return 1;}
        
    //go to the end of the file and figure out how long it is 
    fseek(textfile, 0L, SEEK_END);
    numbytes = ftell(textfile);
    
    //go to the beginning of the file
    fseek(textfile, 0L, SEEK_SET);  
    
    //allocate memory for the string array based on how long the file is
    text = (char*)calloc(numbytes, sizeof(char));   
    
    //read the file into the array text
    fread(text, sizeof(char), numbytes, textfile);
    fclose(textfile);


    /*check commands and run the rot13 function accordingly
    since rot13 has a wrap around both if statements are the same*/
    if(strcmp(options, "encode") == 0)
    {
        printf("%s", rot13(text));
    }else if(strcmp(options, "decode") == 0)
    {
        printf("%s", rot13(text));
    }else{
        printf("Wrong command");
    }

    //printf("%s\n", a);
    //printf("%s", rot13(text));

return(0);
}