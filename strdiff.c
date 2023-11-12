#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
char tolower(char p){
    return p > 0x40 && p < 0x5b ? p | 0x60 : p;
}

int main(int argc, char *argv[])
{

    if (argc == 3)
    {
    }
    else if (argc > 3)
    {
        printf(1, "Too many arguments supplied.\n");
        exit();
    }
    else
    {
        printf(1, "Two argument expected.\n");
        exit();
    }

    char result[15];
    int i = 0;
    char *string1 = argv[1];
    char *string2 = argv[2];


    while (1)
    {
        if (string1[i] == '\0')
        {
            while (string2[i] != '\0')
            {
                result[i] = '1';
                i ++;
            }
            break;
        }
        if (string2[i] == '\0')
        {
            while (string1[i] != '\0')
            {
                result[i] = '0';
                i ++;
            }
            break;
        }

        if (tolower(string1[i]) >= tolower(string2[i]))

            result[i] = '0';

        else

            result[i] = '1';

        i++;
    }
    if (i > 15)
    {
        printf(1, "Strings must contain up to 15 characters!\n");
        exit();
    }

    result[i] = '\n';
    printf(1, "%s \n", result);
    int fd;
    fd = open("strdiff_result", O_CREATE | O_RDWR);
    int size = sizeof(result);
    write(fd, &result, size);
    close(fd);
    exit();
}

