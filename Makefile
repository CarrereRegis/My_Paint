##
## EPITECH PROJECT, 2023
## b1
## File description:
## Makefile
##

CC	:=	gcc

CPPFLAGS	=	-I./include/

CFLAGS	=  	-W -Wall -Wextra

NAME    =  	my_paint

SRC		=	./src/file/new.c				\
			./src/file/help.c				\
			./src/file/open.c 				\
			./src/file/save.c				\
			./src/tools/size.c 				\
			./src/tools/paint.c 			\
			./src/tools/eraser.c 			\
			./src/tools/circle_shape.c		\
			./src/manager/vertex_pix.c		\
			./src/manager/scroll_file.c 	\
			./src/manager/scroll_size.c 	\
			./src/manager/scroll_tools.c	\
			./src/manager/image_loader.c 	\
			./src/manager/event_manager.c   \
			./src/manager/button_manager.c 	\

SRC	+=	./src/main.c

TEST_SRC	:=	$(SRC)
TEST_SRC	+=	./tests/my_test.c
TEST_SRC	+=	./src/my_putstr.c

OBJ     =	$(SRC:.c=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

CSFML	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all	:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(CSFML) -o $(NAME)

unit_tests:	CFLAGS	+=	-g3 --coverage -lcriterion
unit_tests: $(TEST_OBJ)
			$(CC) $(TEST_OBJ) $(CFLAGS) -o unit_tests

clean:
	@ rm -f $(OBJ)
	@ rm -f $(TEST_OBJ)
	@ find . -name "*.gcda" -delete -o -name "*.gcno" -delete

fclean: clean
	@ rm -f $(NAME)
	@ rm -f unit_tests

re: fclean all

.PHONY: all clean fclean re
