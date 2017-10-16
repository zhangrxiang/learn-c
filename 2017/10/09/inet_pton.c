//
// Created by zhangrongxiang on 2017/10/9 16:18
// File inet_pton
//


#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//http://www.man7.org/linux/man-pages/man3/inet_pton.3.html
/*
 * The program below demonstrates the use of inet_pton() and
       inet_ntop(3).  Here are some example runs:

           $ ./a.out i6 0:0:0:0:0:0:0:0
           ::
           $ ./a.out i6 1:0:0:0:0:0:0:8
           1::8
           $ ./a.out i6 0:0:0:0:0:FFFF:204.152.189.116
           ::ffff:204.152.189.116
 */
int main(int argc, char *argv[]) {
    unsigned char buf[sizeof(struct in6_addr)];
    int domain, s;
    char str[INET6_ADDRSTRLEN];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s {i4|i6|<num>} string\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    domain = (strcmp(argv[1], "i4") == 0) ? AF_INET
                                          : (strcmp(argv[1], "i6") == 0) ? AF_INET6 : atoi(argv[1]);
    printf("domain is %d\n", domain);
    s = inet_pton(domain, argv[2], buf);
    if (s <= 0) {
        if (s == 0)
            fprintf(stderr, "Not in presentation format\n");
        else
            perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (inet_ntop(domain, buf, str, INET6_ADDRSTRLEN) == NULL) {
        perror("inet_ntop");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", str);

    exit(EXIT_SUCCESS);
}