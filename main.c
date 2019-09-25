/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:53:04 by bford             #+#    #+#             */
/*   Updated: 2019/09/25 18:25:39 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // D E L E T E !
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"
#include "./libft/libft.h"

int		ft_check_borders(t_fil *l, int x, int y, int z)
{
	return (y + g_a[l->n][0] < z && y + g_a[l->n][0] >= 0 &&
			x + g_a[l->n][1] < z && x + g_a[l->n][1] >= 0 &&
			y + g_a[l->n][2] < z && y + g_a[l->n][2] >= 0 &&
			x + g_a[l->n][3] < z && x + g_a[l->n][3] >= 0 &&
			y + g_a[l->n][4] < z && y + g_a[l->n][4] >= 0 &&
			x + g_a[l->n][5] < z && x + g_a[l->n][5] >= 0);
}

char **ft_greatmap(char **map, t_fil *l, char c, int z)
{
	int		y;
	int		x;
	
	char **cpy;

	cpy = map;
	while (*map)
		printf("%s", *map++);
	printf("\n");
	map = cpy;

	y = -1;
	while (++y < z)
	{
		x = -1;
		while (++x < z)
			if (map[y][x] == '.' &&
			ft_check_borders(l, x, y, z) &&
			map[y + g_a[l->n][0]][x + g_a[l->n][1]] == '.' &&
			map[y + g_a[l->n][2]][x + g_a[l->n][3]] == '.' &&
			map[y + g_a[l->n][4]][x + g_a[l->n][5]] == '.')
			{
				map[y][x] = c;
				map[y + g_a[l->n][0]][x + g_a[l->n][1]] = c;
				map[y + g_a[l->n][2]][x + g_a[l->n][3]] = c;
				map[y + g_a[l->n][4]][x + g_a[l->n][5]] = c;
				if (l->next && (cpy = ft_greatmap(map, l->next, c + 1, z)))
				{
					//cpy = ft_greatmap(map, l->next, c + 1, z);
					//if (cpy)
						return (cpy);
				}
				if (!(l->next))
					return (map);
				map[y][x] = '.';
				map[y + g_a[l->n][0]][x + g_a[l->n][1]] = '.';
				map[y + g_a[l->n][2]][x + g_a[l->n][3]] = '.';
				map[y + g_a[l->n][4]][x + g_a[l->n][5]] = '.';
			}
	}
	return (NULL);
}

int		ft_init(char **s)
{
	int				ar[8];
	int				i;
	t_fil			*ptr;
	static char		c;

	i = 0;
	if (!c)
		c = 'A' - 1;
	if (++c > 'Z' || ft_numofc(*s, '#') != 4)
		return (-1);
	if (g_l)
		ptr = g_l;
	ft_make_array_great_again(ar, s);
	while (i < 19)
	{
		if (!(ar[2] - g_a[i][0]) && !(ar[3] - g_a[i][1]) &&
		!(ar[4] - g_a[i][2]) && !(ar[5] - g_a[i][3]) &&
		!(ar[6] - g_a[i][4]) && !(ar[7] - g_a[i][5]))
			return (ft_lstnewornot(&g_l, &ptr, c, i));
		i++;
	}
	return (-1);
}

int		reading_file(int fd)
{
	char	*new;
	char	*s_block;
	int 	i;

	i = 4;
	s_block = NULL;
	while (get_next_line(fd, &new))
		if ((ft_strlen(new) == 4 && i--) || (ft_strlen(new) == 0 && !i))
			if (ft_strlen(new) == 4)
			{
				if (!(ft_strduporjoin(&s_block, &new)))
					return (-1);
				if (ft_strlen(s_block) == 16)
				{
					if (ft_init(&s_block) == -1)
						return (-1);
					ft_strdel(&s_block);
				}
			}
			else
				i = 4;
		else
			return (-1);
	return (0);
}

int		main(int argc, char **argv)
{
	int result;
	char **map;
	int z;

	if (argc != 2)
	{
		ft_putstr_fd("KAKA9 TO OIIIu6KA\n", 2);
		return (0);
	}
	else
	{	
		if ((result = reading_file(open(argv[1], O_RDONLY))))
			return (0);
		map = ft_makemap(z = ft_min_square(g_l));
		while (!(ft_greatmap(map, g_l, 'A', z)))
			map = ft_makemap(++z);
		while (*map)
			printf("%s", *map++);
	}
	return (0);
}
