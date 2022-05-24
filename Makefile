ECHO = @echo -e

RED = /033[31m

GREEN = /033[32m

YELLOW = /033[33m

BLINK = /033[6m

RESETTXT = /033[0m

BOLD = 0/33[1m

RM = rm -rf

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)
# $@ nom cible $< nom premiere dependance $^ toutes les dependances $? dependance plus recente que la cible $* nom fichier sans extension

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

bonus : $(NAME)

all : $(NAME)

clean : $(OBJ)
	$(RM) $^

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all re bonus clean fclean