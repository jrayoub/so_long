Utils = ./utils_functions/ft_putchar_fd.c ./utils_functions/ft_atoi.c \
		./utils_functions/ft_itoa.c ./utils_functions/ft_putnbr_fd.c ./utils_functions/ft_putstr_fd.c \
		./utils_functions/ft_lstadd_back.c ./utils_functions/ft_lstiter.c \
		./utils_functions/ft_lstnew.c ./utils_functions/get_next_line_utils.c ./utils_functions/get_next_line.c \
		./utils_functions/ft_printf.c ./utils_functions/ft_calc_num_base_size.c \
		./utils_functions/ft_converter_base_hex.c ./utils_functions/ft_put_unsigned.c ./utils_functions/print_hex.c \
		./utils_functions/print_ptr_adress.c 

src = Mendatory/main.c Mendatory/map.c Mendatory/utils.c Mendatory/map_track.c Mendatory/init_utils.c Mendatory/helper.c Mendatory/animate.c

bonus_files = Bonus/main.c Bonus/map.c Bonus/utils.c Bonus/enemy.c Bonus/animate.c Bonus/map_track.c Bonus/init_utils.c Bonus/helper.c

NAME = so_long.out

utils_obj = $(Utils:.c=.o)
OBJFILES = $(src:.c=.o)
bonus_obj = $(bonus_files:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJFILES) $(utils_obj)
	cc $(CFLAGS) $(OBJFILES) $(utils_obj) -lmlx -framework OpenGl -framework Appkit -o $(NAME)

clean:
	rm -rf $(OBJFILES) $(utils_obj) $(bonus_obj)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

bonus : $(bonus_obj) $(Utils)
	cc $(CFLAGS) $(bonus_obj) $(Utils) -lmlx -framework OpenGl -framework Appkit -o $(NAME)