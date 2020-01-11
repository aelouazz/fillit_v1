/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelouazz <aelouazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 00:50:59 by aelouazz          #+#    #+#             */
/*   Updated: 2019/07/19 13:38:54 by aelouazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>

typedef struct		s_tet
{
	char			set[22];
	char			table[4][5];
	int				row[4];
	int				col[4];
	char			letter;
	int				height;
	int				width;
}					t_tet;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

int					wtf(char **map, t_tet **list, int map_size, int i);
int					validation(int fd, t_tet **list, int *nbr_p);
void				extraction(t_tet **list);
char				**map_it(int sz);
void				free_map(char **map, int map_size);
int					set_piece(char **map, t_tet *piece,
					t_point point, char letter);
void				print_map(char **map);
int					ft_max(int *pos);
int					ft_min(int *pos);
int					check_place(char **map, t_tet *piece, t_point point);
int					free_all(char **map, int map_size, t_tet **list);
#endif
