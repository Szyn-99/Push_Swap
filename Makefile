CC = cc 
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h 
HEADER_BONUS = ./Bonus/checker.h 

NAME = push_swap
BONUS = checker
SFILES = ./parsing/ft_split.c \
	./parsing/input_parsing_utils_2.c \
	./parsing/input_parsing_utils_3.c \
	./parsing/input_parsing_utils_4.c \
	./parsing/input_parsing_utils.c \
	./utils_list/ft_lstadd_back_bonus.c \
	./utils_list/ft_lstclear_bonus.c \
	./utils_list/ft_lstdelone_bonus.c \
	./utils_list/ft_lstlast_bonus.c \
	./utils_list/ft_lstnew_bonus.c \
	./utils_list/ft_lstsize_bonus.c \
	./operations/push.c \
	./operations/rotate.c \
	./operations/rotate_reverse.c \
	./operations/swap.c \
	./sort/chunks_sort.c \
	./sort/egde_cases.c \
	./sort/edge_cases_utils.c \
	./sort/edge_cases_2.c \
	./push_swap.c 

SFILES_CHECKER = ./Bonus/checker.c \
	./Bonus/checker_utils.c \
	./parsing/ft_split.c \
	./parsing/input_parsing_utils.c \
	./parsing/input_parsing_utils_2.c \
	./parsing/input_parsing_utils_3.c \
	./parsing/input_parsing_utils_4.c \
	./utils_list/ft_lstadd_back_bonus.c \
	./utils_list/ft_lstclear_bonus.c \
	./utils_list/ft_lstdelone_bonus.c \
	./utils_list/ft_lstlast_bonus.c \
	./utils_list/ft_lstnew_bonus.c \
	./utils_list/ft_lstsize_bonus.c \
	./operations/push.c \
	./operations/rotate.c \
	./operations/rotate_reverse.c \
	./operations/swap.c \
	./Bonus/get_next_line.c \
	./Bonus/get_next_line_utils.c


OFILES = $(SFILES:.c=.o)
OFILES_CHECKER = $(SFILES_CHECKER:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) 
	$(CC) $(FLAGS) $(OFILES) -o $@


%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(BONUS) 

$(BONUS): $(OFILES_CHECKER)
	$(CC) $(FLAGS) $^ -o $@

Bonus/%.o: Bonus/%.c $(HEADER_BONUS)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES) $(OFILES_CHECKER)

fclean: clean
	rm -rf $(NAME) checker

re: fclean all