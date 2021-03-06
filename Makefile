ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

RM = rm -rf

SRC = $(wildcard */*.c)

SRCTEST = $(wildcard ./main/tester/*.c)

OBJ = $(SRC:.c=.o)

OBJTEST = $(SRCTEST:.c=.o)

NAME = libftprintf.a

NAMETEST = MyTester

CC = gcc

AR = ar rcs

CFLAGS = -Wall -Werror -Wextra

$(NAME) : $(OBJ)
	$(ECHO) "$(YELLOW)Compilation de libftprintf.a...$(RESETTXT)"
	@$(AR) $@ $^
# $@ nom cible $< nom premiere dependance $^ toutes les dependances $? dependance plus recente que la cible $* nom fichier sans extension
	$(ECHO)  "$(GREEN)$(BOLD)Compilation Terminer !!!$(RESETTXT)"

$(NAMETEST) : $(OBJ) $(OBJTEST)
	$(ECHO) "$(YELLOW)Compilation de MyTester...$(RESETTXT)"
	@$(CC) -o $@ $^
	$(ECHO)  "$(GREEN)$(BOLD)Compilation Terminer !!!$(RESETTXT)"

%.o : %.c
	$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus : $(NAME)

all : $(NAME)

norm :
	@norminette HEADER/*.h print_functions/*.c main/*.c utils/*.c counters/*.c text_mod/*.c

clean :
	$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
	@$(RM) $(OBJ)
	$(ECHO) "$(GREEN)$(BOLD)Terminer !$(RESETTXT)"

clean_t : clean
	$(ECHO) "$(RED)Suppression des objets MyTester...$(RESETTXT)"
	@$(RM) $(OBJTEST)
	$(ECHO) "$(GREEN)$(BOLD)Terminer !$(RESETTXT)"

fclean : clean
	$(ECHO) "$(RED)Suppression de libftprintf.a...$(RESETTXT)"
	@$(RM) $(NAME)
	$(ECHO) "$(GREEN)$(BOLD)Terminer !$(RESETTXT)"

fclean_t : clean_t
	$(ECHO) "$(RED)Suppression de MyTester...$(RESETTXT)"
	@$(RM) $(NAMETEST)
	$(ECHO) "$(GREEN)$(BOLD)Terminer !$(RESETTXT)"

re : fclean all

re_t : fclean_t $(NAMETEST)

.PHONY: all re bonus clean fclean