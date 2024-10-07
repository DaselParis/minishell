SRC = list_utils.c  main.c secondmain.c split.c  utils2.c utils.c redirection.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
READLINEFLAGS = -lreadline
# VFLAGS =  valgrind --leak-check=full --show-reachable=yes
NAME = minishell

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(READLINEFLAGS) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean clean all

.PHONY: all bonus clean fclean re
