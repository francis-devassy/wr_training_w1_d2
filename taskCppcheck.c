//Run cppcheck --enable=all   on the code

#include <stdio.h>

/* VIOLATION: Using short type (Rule 6.3) */
short global_short = -1;

/* VIOLATION: Function prototype mismatch (Rule 8.2) */
void message(int a, int b);   /* declared with two parameters */

/* VIOLATION: Deep nesting (Rule 15.2) */
int main(void)
{
    int i = 0;

    /* VIOLATION: Implicit signed/unsigned comparison (Rule 10.3/10.4) */
    unsigned int u_val = 5U;
    int s_val = -3;

    if (s_val < u_val)   /* signed vs unsigned */
    {
        printf("Comparison result\n");
    }

    /* VIOLATION: Magic number (Rule 2.5) */
    for (i = 0; i < 10; i++)   /* 10 is a magic number */
    {
        if (i > 5)             /* 5 is a magic number */
        {
            if (i % 2 == 0)
            {
                if (i == 8)
                {
                    printf("Deep nesting violation\n");
                }
            }
        }
    }

    message(1, 2);   /* call with two args */
    return 0;    /* VIOLATION: multiple exit points not used (Rule 15.5 advisory) */
}

/* VIOLATION: Function definition mismatch with declaration (Rule 8.2) */
void message(int x)   /* defined with one parameter */
{
    printf("foo called with %d\n", x);
}
