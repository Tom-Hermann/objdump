/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-nmobjdump-tom.hermann
** File description:
** usefull
*/

#include "objdump.h"

int skip_section(char *name_section)
{
    char *skip_section[] = {
        "",
        ".bss",
        ".shstrtab",
        ".symtab",
        ".strtab",
        ".rela.text",
        ".rela.debug_info",
        ".rela.debug_aranges",
        ".rela.debug_line",
        ".rela.eh_frame",
        ".tbss",
        "__libc_freeres_ptrs",
        NULL
    };

    for (int i = 0; skip_section[i] != NULL; i++) {
        if (strcmp(skip_section[i], name_section) == 0)
            return TRUE;
    }
    return FALSE;
}