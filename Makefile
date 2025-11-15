CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = ft_putchar.c ft_putstr.c 
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@(ar rc $@ $^)

%.o: %.c 
	@echo " ⋆ $< ⋆ : Compiling ...  "
	@($(CC) $(CFLAGS) -c $<)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(OBJS) $(NAME)
re: fclean all

.PHONY: all fclean clean re all