#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    

    if (argc == 2)
    {
    }
    else if (argc > 2)
    {
        printf(1, "Too many arguments supplied.\n");
        exit();
    }
    else
    {
        printf(1, "One argument expected.\n");
        exit();
    }

    int number=atoi(argv[1]);
    digitalRoot(number);
    exit();

}

