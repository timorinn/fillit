/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:53:04 by bford             #+#    #+#             */
/*   Updated: 2019/09/23 17:44:13 by bford            ###   ########.fr       */
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

	if (ft_numofc(*s, '#') != 4)
		return (-1);
	ar[0] = (ft_strchr(*s, '#') - *s) / 4;
	ar[1] = (ft_strchr(*s, '#') - *s) % 4;
	ar[2] = (ft_ptrofc(*s, '#', 2) - *s) / 4 - ar[0];
	ar[3] = (ft_ptrofc(*s, '#', 2) - *s) % 4 - ar[1];
	ar[4] = (ft_ptrofc(*s, '#', 3) - *s) / 4 - ar[0];
	ar[5] = (ft_ptrofc(*s, '#', 3) - *s) % 4 - ar[1];
	ar[6] = (ft_ptrofc(*s, '#', 4) - *s) / 4 - ar[0];
	ar[7] = (ft_ptrofc(*s, '#', 4) - *s) % 4 - ar[1];
	printf("%d %d %d %d %d %d %d %d\n", ar[0], ar[1], ar[2], ar[3], ar[4], ar[5], ar[6], ar[7]);
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