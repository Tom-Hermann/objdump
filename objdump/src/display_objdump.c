/*
** EPITECH PROJECT, 2021
** B-PSU-400-RUN-4-1-nmobjdump-tom.hermann
** File description:
** display_objdump
*/

#include "objdump.h"

void display_header(data_t *data)
{
    if (data->architecture == ELFCLASS64) {
        printf("\n%s:     file format elf64-x86-64\n", data->name);
        printf("architecture: i386:x86-64, flags 0x%08x:\n", data->ehdr->e_flags);
        printf("HAS_RELOC, HAS_SYMS\n");
        printf("start address 0x%016lx\n\n", data->ehdr->e_entry);
    }
    else {
        printf("\n%s:     file format elf32-i386\n", data->name);
        printf("architecture: i386, flags 0x00000011:\nHAS_RELOC, HAS_SYMS\n");
        printf("start address 0x%08lx\n\n", data->ehdr->e_entry);
    }
}

void display_section_content(unsigned char *data, int size)
{
    for (int i = 0; i < 16; i++) {
        if (i < size)
            printf("%02x", data[i]);
        else
            printf("  ");
        if (((i + 1) % 4) == 0)
            printf(" ");
    }
    printf(" ");
    for (int i = 0; i < 16; i++) {
        if (i < size)
            printf("%c", (data[i] >= ' ' && data[i] <= '~') ? data[i] : '.');
        else
            printf(" ");
    }
    printf("\n");
}

void display_section_64(data_t *data)
{

    Elf64_Ehdr *ehdr = data->ehdr;
    Elf64_Shdr *shdr = data->shdr;
    char *name;

    for (int y = 0; y != ehdr->e_shnum; y++) {
        name = &NAME;
        if (!skip_section(name) && !(SHDR.sh_size == 0)) {
            printf("Contents of section %s:\n", name);
            for (unsigned int i = SHDR.sh_offset;
                i < (SHDR.sh_offset + SHDR.sh_size);
                i+= 16) {
                printf(" %04x ", (int)(SHDR.sh_addr + i - SHDR.sh_offset));
                display_section_content((unsigned char *)ehdr + i,
                SHDR.sh_offset + SHDR.sh_size - i);
            }
        }
    }
}

void display_section_32(data_t *data)
{

    Elf32_Ehdr *ehdr = (Elf32_Ehdr *)data->ehdr;
    Elf32_Shdr *shdr = (Elf32_Shdr *)data->shdr;
    char *name;

    for (int y = 0; y != ehdr->e_shnum; y++) {
        name = &NAME;
        if (!skip_section(name) && !(SHDR.sh_size == 0)) {
            printf("Contents of section %s:\n", name);
            for (unsigned int i = SHDR.sh_offset;
                i < (SHDR.sh_offset + SHDR.sh_size);
                i+= 16) {
                printf(" %04x ", (int)(SHDR.sh_addr + i - SHDR.sh_offset));
                display_section_content((unsigned char *)ehdr + i,
                SHDR.sh_offset + SHDR.sh_size - i);
            }
        }
    }
}

int display_objdump(data_t *data)
{
    display_header(data);
    if (data->architecture == ELFCLASS64)
        display_section_64(data);
    else
        display_section_32(data);
    return SUCCESS;
}