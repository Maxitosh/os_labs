#include <stdlib.h>
#include <zconf.h>

int  main(void)
{
    setenv("PS1","SHELL> ",1);
    //replace image with shell from system:)
    execl("/bin/sh","/bin/sh",0);
    return 0;
}
