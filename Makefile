##
## EPITECH PROJECT, 2019
## C Pool bistro-matic
## File description:
## Makefile
##

NAME = calc

FILES = core/main.c \
	core/main_tools.c \
	core/my_getnbr.c \
	core/printers.c \
	errors/check_args.c \
	errors/check_buffer.c \
	errors/check_help.c \
	errors/my_error.c \
	infnbr/add.c \
	infnbr/div.c \
	infnbr/div_mod_tools.c \
	infnbr/eval_expr.c \
	infnbr/inftools.c \
	infnbr/io_bases.c \
	infnbr/left_shift.c \
	infnbr/mod.c \
	infnbr/mult.c \
	infnbr/right_shift.c

all :	$(NAME)

$(NAME):
	gcc -o $(NAME) $(FILES)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re:	fclean all

prepush:	fclean
	rm -f *# *~ ./*/*# ./*/*~ ./*/*/*# ./*/*/*~
	git add --all
	git status

tree:	prepush
	tree -a -I .git

push:	prepush
	git commit -m 'auto-sync with master'
	git push origin master

pull:
	git pull origin master

sync:	pull	push

debug:
	clear
	gcc -o $(NAME) $(FILES) -Wall -Wextra

valgrind:
	gcc -g3 -o $(NAME) $(FILES)

relink:
	ln -f core/include/infnbr.h infnbr/include/infnbr.h
	ln -f core/include/infnbr.h errors/include/infnbr.h
