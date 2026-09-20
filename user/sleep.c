#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"





int main(int argc,char *argv[]){
   //    int i;
    if(argc<=1){
        printf("Please provide a valid argument\n");
        exit(1);
    }

    char * argument=argv[1];
    int time=atoi(argument);
    pause(time);
    exit(0);
}