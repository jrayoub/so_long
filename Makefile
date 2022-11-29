src = main.c map.c utils.c enemy.c animate.c map_track.c init_utils.c helper.c ./utils_functions/ft_putchar_fd.c ./utils_functions/ft_atoi.c\
		./utils_functions/ft_itoa.c ./utils_functions/ft_putnbr_fd.c ./utils_functions/ft_putstr_fd.c\
		./utils_functions/ft_lstadd_back.c ./utils_functions/ft_lstadd_front.c ./utils_functions/ft_lstiter.c\
		./utils_functions/ft_lstclear.c ./utils_functions/ft_lstdelone.c \
		./utils_functions/ft_lstlast.c ./utils_functions/ft_lstmap.c ./utils_functions/ft_lstnew.c \
		./utils_functions/ft_lstsize.c ./utils_functions/ft_printf.c ./utils_functions/ft_calc_num_base_size.c\
		./utils_functions/ft_converter_base_hex.c ./utils_functions/ft_put_unsigned.c ./utils_functions/print_hex.c \
		./utils_functions/print_ptr_adress.c ./utils_functions/get_next_line_utils.c ./utils_functions/get_next_line.c

NAME = SO_LONG

OBJFILES = $(src:.c=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	cc $(OBJFILES) -lmlx -framework OpenGl -framework Appkit -o so_long.out

run : $(NAME)
	./so_long.out map/level2.ber

clean:
	rm -rf $(OBJFILES)