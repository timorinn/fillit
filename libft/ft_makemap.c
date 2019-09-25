/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:23:57 by bford             #+#    #+#             */
/*   Updated: 2019/09/25 12:02:50 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include <stdio.h> // DEL

char	**ft_makemap(int z)
{
	/*
	char	*s;
	int		i;
	int		cpy;

	cpy = x + 1;
	x = (x + 1) * x + 1;
	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * x)))
		return (NULL);
	s[x] = '\0';
	while (i < x - 1)
	{
		if (!((i + 1) % cpy) && i)
			s[i] = '\n';
		else
			s[i] = '.';
		i++;
	}
	return (s);
	*/
	char	**map;
	int		y;
	int		x;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (z + 1))))
		return (NULL);
	map[z] = NULL;
	while (y < z)
	{
		x = 0;
		if (!(map[y] = (char *)malloc(sizeof(char) * (z + 2))))
			return (NULL);
		map[y][z + 1] = '\0';
		map[y][z] = '\n';
		while (x < z)
			map[y][x++] = '.';
		y++;
	}
	return (map);	
}
