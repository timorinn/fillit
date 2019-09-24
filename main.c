/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:53:04 by bford             #+#    #+#             */
/*   Updated: 2019/09/24 12:38:27 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // D E L E T E !
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

#include "./libft/libft.h"

int		val_ini_add(char **s)
{
	int		ar[8];
	int		i;
	f_list	*ptr;
	static char		c;
	
	if (!c)
		c = 'A' - 1;
	if (++c > 'Z' || ft_numofc(*s, '#') != 4)
		return (-1);
	if (g_l)
		ptr = g_l;
	i = 0;
	ar[0] = (ft_strchr(*s, '#') - *s) / 4;
	ar[1] = (ft_strchr(*s, '#') - *s) % 4;
	ar[2] = (ft_ptrofc(*s, '#', 2) - *s) / 4 - ar[0];
	ar[3] = (ft_ptrofc(*s, '#', 2) - *s) % 4 - ar[1];
	ar[4] = (ft_ptrofc(*s, '#', 3) - *s) / 4 - ar[0];
	ar[5] = (ft_ptrofc(*s, '#', 3) - *s) % 4 - ar[1];
	ar[6] = (ft_ptrofc(*s, '#', 4) - *s) / 4 - ar[0];
	ar[7] = (ft_ptrofc(*s, '#', 4) - *s) % 4 - ar[1];
	while (i < 19)
	{
		if (!(ar[2] - g_a[i][0]) && !(ar[3] - g_a[i][1]) && !(ar[4] - g_a[i][2]) &&
		!(ar[5] - g_a[i][3]) && !(ar[6] - g_a[i][4]) && !(ar[7] - g_a[i][5]))
		{
			if (!g_l)
			{
				if (!(g_l = ft_lst_new_f(c, i)))
					return (-1);
				return (1);
			}
			else
			{
				while (g_l->next)
					g_l = g_l->next;
				if (!(g_l->next = ft_lst_new_f(c, i)))
					return (-1);
				g_l = ptr;
				return (1);
			}
		}
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
		if ((ft_strlen(new) == 4 && i) || (ft_strlen(new) == 0 && !i))
		{
			if (ft_strlen(new) == 4)
			{
				if (!(ft_strduporjoin(&s_block, &new)))
					return (-1);
				if (ft_strlen(s_block) == 16)
				{
					if (val_ini_add(&s_block) == -1)
						return (-1);
					free(s_block);
					s_block = NULL;
				}
				i--;
			}
			else
				i = 4;
		}
		else
			return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("KAKA9 TO OIIIu6KA\n", 2);
		return (0);
	}
	else
		printf("RESULT = %d\n", reading_file(open(argv[1], O_RDONLY)));
		/* обработка карты */
		/* вывод карты */
	
	printf("%c %d\n", g_l->c, g_l->n);
	while (g_l->next)
	{
		g_l = g_l->next;
		printf("%c %d\n", g_l->c, g_l->n);
	}
	return (0);
}