
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(int argc, char *argv[]) 
{
    if (argc != 3){
        printf(1, "Two arguments expected.\n");
        exit();
        
    }
    char *src = argv[1];
    char *dst = argv[2];
    int result = copy_file(src, dst);
    if (result == -1)
        printf(1, "copy failed.\n");
    if (result == 0)
        printf(1, "copy succeeded.\n");
    exit();
} 