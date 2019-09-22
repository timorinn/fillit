/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:53:04 by bford             #+#    #+#             */
/*   Updated: 2019/09/22 15:41:03 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // D E L E T E !
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"

#include "./libft/libft.h"

int		val_ini_add(char *s)
{
	char *copy;
	int	i;

	i = 0;
	copy = s;
	while (*s && (*s == '#' || *s == '.'))
		s++;

	if (*s)
		return (0); // МЫ НАШЛИ В СТРОКЕ НЕ "." и не "#"
	s = copy;
	s = ft_strsub(s, ft_strchr(s, '#') - s, ft_strrchr(s, '#') - ft_strchr(s, '#') + 1);
	//free(copy);

	while (i < 19)
	{
		if (!(ft_strcmp(g_array[i], s)))
		{
			printf("S = Array[%d]\n", i);
			return (0);
		}
		i++;
	}
	return (0);
}

int		reading_file(int fd)
{
	char	*new;
	char	*s_block;
	int 	i;

	i = 4;
	s_block = NULL;
	while (get_next_line(fd, &new))	//
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
					val_ini_add(s_block);
					//printf("%s\n", s_block);
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
	return (0);
}