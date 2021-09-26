/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-nmobjdump-tom.hermann
** File description:
** main
*/

#include "objdump.h"

void print_usage(void)
{
    printf("Usage: ./my_objdump <file(s)>\n");
}

int help(int argc, char **argv)
{
    if (argc == 1) {
        print_usage();
        return TRUE;
    }
    for (int i = 0; i != argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage();
            return TRUE;
        }
    }
    return FALSE;
}

int main(int argc, char **argv)
{
    if (help(argc, argv))
        return SUCCESS;
    if (loop_file(argc, argv) == FAILURE)
        return FAILURE;
    return SUCCESS;
}