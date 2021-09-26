##
## EPITECH PROJECT, 2021
## B-PSU-400-RUN-4-1-nmobjdump-tom.hermann
## File description:
## Makefile
##


SRC_NM			=	nm/src/main.c

SRC_OBJ			=	objdump/src/exec_objdump.c		\
					objdump/src/display_objdump.c	\
					objdump/src/usefull.c			\
					objdump/src/main.c

SRC_UT			=	tests/*.c

OBJ_NM			=	$(SRC_NM:.c=.o)

OBJ_OBJ			=	$(SRC_OBJ:.c=.o)

OBJ_M			=	$(SRC_M:.c=.o)

INCLUDE			=	-I./include

NAME_NM			=	my_nm

NAME_OBJ		=	my_objdump

NAME_UT			=	unit_test

CFLAGS			=	-W -Werror -Wall -Wextra -g -I./objdump/include

CFLAGS_UT		=	-lcriterion --coverage

RM				=	rm -rf


all:	objdump

objdump:	$(OBJ_OBJ)
		gcc -o $(NAME_OBJ) $(SRC_OBJ) $(CFLAGS)

nm: $(OBJ_NM)
		gcc -o $(NAME_NM) $(SRC_NM) $(INCLUDE) $(CFLAGS)



tests_run:
		gcc -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS_UT)
		./$(NAME_UT)

clean:
		$(RM) $(OBJ_NM) $(OBJ_OBJ) $(OBJ_UT)

fclean:		clean fclean_ut
		$(RM) $(NAME_NM)
		$(RM) $(NAME_OBJ)
		$(RM) *.gcda *.gcno

fclean_ut:	clean
		$(RM) $(NAME_UT)
		$(RM) *.gcda *.gcno

re:		fclean all
