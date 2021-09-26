/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-nmobjdump-tom.hermann
** File description:
** exec_objdump
*/

#include "objdump.h"

int set_shdr(data_t *data, void *ptr)
{
    if (data->architecture == ELFCLASS32) {
        data->shdr = (Elf64_Shdr *)((char *)data->ehdr +
                ((Elf32_Ehdr *)data->ehdr)->e_shoff);
    }
    else {
        data->shdr = (Elf64_Shdr *) (ptr + data->ehdr->e_shoff);
    }
    return SUCCESS;
}

int set_data(char *file_path, int fd, data_t *data)
{
    void *ptr;

    data->name = file_path;
    data->size = lseek(fd, 0, SEEK_END);
    data->fd = fd;
    ptr = mmap(NULL, data->size, PROT_READ, MAP_SHARED, fd, 0);
    data->ehdr = (Elf64_Ehdr *)ptr;
    if (data->ehdr->e_ident[EI_CLASS] == ELFCLASS32)
        data->architecture = ELFCLASS32;
    else
        data->architecture = ELFCLASS64;
    return set_shdr(data, ptr);
}

int exec_objdump(char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    struct stat stat_file;
    data_t data;

    if (fd <= 0) {
        fprintf(stderr, "objdump: \'%s\': No such file\n", file_path);
        return FAILURE;
    }
    else if (fstat(fd, &stat_file)) {
        fprintf(stderr, "objdump: Warnin: \'%s\': is a directory\n", file_path);
        return FAILURE;
    }
    if (set_data(file_path, fd, &data) == FAILURE) return FAILURE;
    return display_objdump(&data);
}

int loop_file(int argc, char **argv)
{
    if (argc == 1)
        return exec_objdump("a.out");
    for (int i = 1; i != argc; i++) {
        if (argv[i][0] ==  '-') continue;
        if (exec_objdump(argv[i]) == FAILURE)
            return FAILURE;
    }
    return SUCCESS;
}