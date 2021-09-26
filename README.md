# My objdump

The goal is to code an equivalent to the system commands objdump with -fs
option.

You must handle a variable number of parameters.

The display produced MUST be the same as the one on your dump.

The programs must work with the following:
- relocatable files .o & .a
- shared files .so
- executable files

## Compile

The project compile with *Makefile*:

For compile the project use the commande:

```console
foo@bar:~/objdump$ make re
```

For clean the project use:

```console
foo@bar:~/objdump$ make fclean
```

Get instruction with:
```console
foo@bar:~/malloc$ ./my_objdump
```