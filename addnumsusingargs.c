#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
   
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int z = x + y;
    if(argc < 2){
        printf("no argument in command line.\n");
    }else{
        printf("The answer is:%d\n" , z);
    }
}