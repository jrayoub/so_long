/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:35:48 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/29 07:35:50 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>

# define BLOCK_SIZE 32
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct blockes
{
	void	*brick_block;
	void	*grass_block;
	void	*door_block;
	void	*foor_block;
	void	*hero_block;
}	t_blockes;

typedef struct coordinations
{
	int	x;
	int	y;
	int	orientation;
}	t_coordinations;

typedef struct game_state
{
	int				eaten_c;
	int				availables_c;
	int				hero_moves;
}	t_game_satate;

typedef struct map
{
	int						h;
	int						w;
	void					*mlx;
	void					*mlx_win;
	struct coordinations	*cords;
	char					**map_l;
	int						is_game_over;
	struct game_state		*game;
	struct blockes			*block;
}	t_map;

typedef struct valide_path
{
	int	is_valide;
	int	eaten_c;
}	t_valide_path;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void			draw_map(t_map *map, char *level);
t_map			*init_window(void *mlx, char *level);
t_coordinations	*new_cords(int x, int y);
int				obj_on_map_chr(const char *s, int c);
void			end_game(t_map *map, char *msg);
void			set_eaten_c(t_map *map);
void			refresh_out_put(t_map *map);
void			render_hero(t_map *map, int sec_counter);
t_valide_path	*is_valide_path(int x, int y, char **map_l,
					t_valide_path *valide_path);
t_game_satate	*init_game_satate(void);
void			init_map(t_map *map, int width, int i, void *mlx);
t_map			*init_window(void *mlx, char *level);
size_t			ft_strlen(const char *c);
char			*ft_strdup(const char *s);
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_lstiter(t_list **lst, int (*f)(void *, t_map *, int),
					t_map *map, int sec_counter);
int				ft_printf(const char *str, ...);
int				ft_calc_num_base_size(long int n, int base);
void			ft_converter_base_hex(unsigned long int n,
					char format, int *size);
void			ft_put_unsigned(unsigned int num, int *i);
int				print_hex(unsigned int n, char formate);
int				print_ptr_adress(size_t n);
char			*get_next_line(int fd);
char			*gt_strjoin(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
void			exite(t_map *map, char *msg);
void			free_map(char **map);
int				check_path(t_map *map, int x, int y);
int				check_map_formate(t_map *map);
void			navigate_hero(t_map *map, int keycode);
char			**map_l_cpy(t_map *map);
void			strip_nl(char *line);
int				animate(t_map *map);
#endif
