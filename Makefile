NAME = libftprintf.a

SOURCES = ft_print_hex.c ft_print_ptr.c ft_printf.c ft_utilities.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJECTS) 
	$(AR) rcs $(NAME) $(OBJECTS) $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $(SOURCES) $?

clean:
	rm -f $(OBJECTS) 
	
fclean: clean
	rm -f $(NAME)

re: fclean all