#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int  main(void)
{
    char buf [100];
    while(1)
    {
        fgets(buf, 20, stdin);
        if(strcmp(buf, "q\n") == 0)
            break;
        system(buf);
    }
    return 0;
}
