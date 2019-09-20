/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:53:04 by bford             #+#    #+#             */
/*   Updated: 2019/09/20 18:51:28 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // D E L E T E !
#include <stdlib.h>
#include <fcntl.h>

#include "./libft/libft.h"

int		main()
{
	char *str;
	int file;

	file = open("text.txt", O_RDONLY);

	
	while (get_next_line(file, &str))
	{
		printf("%s\n", str);
		free(str);
	}
	return (0);
}