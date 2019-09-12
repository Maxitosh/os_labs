#include  <stdio.h>
#include <unistd.h>

int  main(void)
{
    for(int i = 0; i < 5; i++)
    {
        fork();
        sleep(5);
    }
    return 0;
}
/*
 \-+= 05629 maxitosh -bash
       \-+= 06006 maxitosh ./ex2
         |-+- 06007 maxitosh ./ex2
         | |-+- 06021 maxitosh ./ex2
         | | \--- 06043 maxitosh ./ex2
         | \--- 06042 maxitosh ./ex2
         |-+- 06022 maxitosh ./ex2
         | \--- 06044 maxitosh ./ex2
         \--- 06045 maxitosh ./ex2

         8 processes total = 2^3
-----------------------------------------------------------------------------------------------------------------------
     \-+= 05629 maxitosh -bash
       \-+= 06483 maxitosh ./ex2
         |-+- 06484 maxitosh ./ex2
         | |-+- 06494 maxitosh ./ex2
         | | |-+- 06513 maxitosh ./ex2
         | | | |-+- 06532 maxitosh ./ex2
         | | | | \--- 06564 maxitosh ./ex2
         | | | \--- 06558 maxitosh ./ex2
         | | |-+- 06530 maxitosh ./ex2
         | | | \--- 06560 maxitosh ./ex2
         | | \--- 06554 maxitosh ./ex2
         | |-+- 06512 maxitosh ./ex2
         | | |-+- 06533 maxitosh ./ex2
         | | | \--- 06563 maxitosh ./ex2
         | | \--- 06557 maxitosh ./ex2
         | |-+- 06527 maxitosh ./ex2
         | | \--- 06555 maxitosh ./ex2
         | \--- 06556 maxitosh ./ex2
         |-+- 06495 maxitosh ./ex2
         | |-+- 06514 maxitosh ./ex2
         | | |-+- 06528 maxitosh ./ex2
         | | | \--- 06562 maxitosh ./ex2
         | | \--- 06551 maxitosh ./ex2
         | |-+- 06531 maxitosh ./ex2
         | | \--- 06561 maxitosh ./ex2
         | \--- 06552 maxitosh ./ex2
         |-+- 06515 maxitosh ./ex2
         | |-+- 06529 maxitosh ./ex2
         | | \--- 06559 maxitosh ./ex2
         | \--- 06553 maxitosh ./ex2
         |-+- 06534 maxitosh ./ex2
         | \--- 06565 maxitosh ./ex2
         \--- 06566 maxitosh ./ex2

         32 processes total = 2^5
 */