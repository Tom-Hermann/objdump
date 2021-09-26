/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-nmobjdump-tom.hermann
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#define TRUE 1
#define FALSE 0

#define FAILURE 84
#define SUCCESS 0

#define SHDR shdr[y]

#define NAME ((char *)ehdr + shdr[ehdr->e_shstrndx].sh_offset)[shdr[y].sh_name]

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <elf.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

typedef struct data_s {
    char        *name;
    Elf64_Ehdr  *ehdr;
    Elf64_Shdr  *shdr;
    long size;
    int fd;
    int architecture;
} data_t;

void print_usage(void);

int loop_file(int argc, char **argv);

int display_objdump(data_t *data);
int skip_section(char *name_section);
#endif /* !OBJDUMP_H_ */
