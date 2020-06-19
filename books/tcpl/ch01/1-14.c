//
// Created by zing on 6/19/2020.
//


#include <stdio.h>
#include <stdlib.h>

#define NUMCHARS 128 /* number of characters in ASCII-I */

int main(void) {
    int c, chars[NUMCHARS];

    for (c = 0; c < NUMCHARS; ++c)
        chars[c] = 0;

    while ((c = getchar()) != EOF){
        if (c == 'q'){
            break;
        }
        chars[c] += 1;
    }

    /* horizontal histogram */
    for (c = 0; c < NUMCHARS; ++c) {
        if (chars[c] > 0) {
            if (c == '\b')          /* backspace */
                printf("\\b");
            else if (c == '\n')     /* new line*/
                printf("\\n");
            else if (c == '\t')     /* (horizontal) tab */
                printf("\\t)");
            else                    /* all other chars */
                printf("%2c", c);
            /* ASCII code & frequency */
            printf(" (%3d): %3d\n", c, chars[c]);
        }
    }
    return EXIT_SUCCESS;
}
