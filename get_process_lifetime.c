
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(void)
{

    int pid = fork();
    if (pid < 0)
    {
        printf(1, "fork failed.\n");
    }
    else if (pid == 0)
    {
        // Child process
        int t2 = get_process_lifetime(getpid());
        printf(1, "child process lifetime before sleep: %d\n", t2);
        sleep(10);
        int t1 = get_process_lifetime(getpid());
        printf(1, "child process lifetime after sleep: %d\n", t1);
        exit();
    }
    else
    {
        // Parent process
        wait();
        sleep(10);
        int t3 = get_process_lifetime(getpid());
        printf(1, "parent process lifetime: %d\n", t3);

    }

    
    exit();
}