CC = cc 
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h 

NAME = push_swap

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
	./push_swap.c 

OFILES = $(SFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) 
	$(CC) $(FLAGS) $(OFILES) -o $@

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all