#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int a=fork();
    if(a<0){
        while(wait()!=-1){}
    }
    else if(a==0){
        while(1){}
    }
    int b=fork();
    if(b<0){
        while(wait()!=-1){}
    }
    else if(b==0){
        while(1){}
    }
    int c=fork();
    if(c<0){
        while(wait()!=-1){}
    }
    else if(c==0){

        int a_child=fork();
        if(a_child==0){
            sleep(2);
        uncleCount(getpid());
        sleep(2);
        }
        
        while(1){}
    }
    
    sleep(2);
    uncleCount(a);
    sleep(2);
    uncleCount(b);
    sleep(2);
    uncleCount(c);
    sleep(2);
    exit();
    return 0;

}

