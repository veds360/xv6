#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user/user.h"


int main(int argc,char * argv[]){
    if(argc<=1){
        fprintf(2,"Please provide atleast 1 file\n");
        exit(0);
    }
    int i;

    for(i=1;i<argc;i++){
        char * current_file=argv[i];
        int fd=open(current_file,O_RDONLY);
        int n;
        char c;
        char buf[32];
        int idx=0;
        int start=1;
       
        while((n=read(fd,&c,1))>0){
            if(start==0){
                if(c==' ' || c=='-' || c=='\r' || c=='\t' || c=='\n' || c=='.' || c=='/' || c==','){
                    start=1;
                }
            }
            else{
                if(c>='0' && c<='9'){
                    buf[idx++]=c;
                }
                else if(c==' ' || c=='-' || c=='\r' || c=='\t' || c=='\n' || c=='.' || c=='/' || c==','){
                    buf[idx]='\0';
                    if(idx>0){
                    int number=atoi(buf);
                    if((number%5==0) || (number%6==0)){
                        printf("%d\n",number);
                    }
                }
                    start=1;
                    idx=0;
                }
                else{
                    start=0;
                    idx=0;
                }
            }
        }
        if(idx>0){
            buf[idx]='\0';
            int number=atoi(buf);
            if((number%5==0) || (number%6==0)){
                printf("%d\n",number);
            }
        }
        close(fd);
    }

    exit(0);

}