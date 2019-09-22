/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:53:04 by bford             #+#    #+#             */
/*   Updated: 2019/09/22 18:42:24 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // D E L E T E !
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

#include "./libft/libft.h"

int		val_ini_add(char **s)
{
	f_list	*p;
	char	*copy;
	int		i;

	i = 0;
	copy = *s;
	if (g_l)
		p = g_l;
	while (**s && (**s == '#' || **s == '.'))
		(*s)++;
	if (**s)
		return (0); // ЕСЛИ МЫ НАШЛИ В СТРОКЕ НЕ "." и не "#"
	*s = copy;
	if (!(*s = ft_strsub(*s, ft_strchr(*s, '#') - *s,
	ft_strrchr(*s, '#') - ft_strchr(*s, '#') + 1)))
		return (0);
	free(copy);
	while (i < 19 && ft_strcmp(g_array[i], *s)) // ИЩЕМ В МАССИВЕ ПОДХОДЯЩУЮ СТРОКУ
		i++;
	if (i >= 19)
		return (0);
	if (!g_l)
	{
		if(!(g_l = ft_lst_new_f(g_c, i)))
			return (0);
		g_c++;
		return (1);
	}
	while (g_l->next)
		g_l = g_l->next;
	if (!(g_l->next = ft_lst_new_f(g_c, i)))
		return (0);
	g_c++;
	g_l = p;
	return (1);
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
				if (!s_block)
				{
					if (!(s_block = ft_strdup(new)))
						return (0);
				}
				else if (!(s_block = ft_strjoinfree(s_block, new)))
					return (0);
				if (ft_strlen(s_block) == 16)
				{
					val_ini_add(&s_block);
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
	int i = 0;
	if (argc != 2)
	{
		ft_putstr_fd("KAKA9 TO OIIIu6KA\n", 2);
		return (0);
	}
	else
		printf("RESULT = %d\n", reading_file(open(argv[1], O_RDONLY)));
		printf("L[%d] = %c %D\n", i++, g_l->c, g_l->n);
		while (g_l->next)
		{
			g_l = g_l->next;
			printf("L[%d] = %c %D\n", i++, g_l->c, g_l->n);
		}
		/* обработка карты */
		/* вывод карты */
	return (0);
}