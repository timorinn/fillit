/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewget.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:18:53 by bford             #+#    #+#             */
/*   Updated: 2019/09/20 17:34:38 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

my_list	*ft_lstnewget(int fd)
{
	my_list	*new;

	if (!(new = (my_list *)malloc(sizeof(my_list) * 1)))
		return (NULL);
	new->content = NULL;
	new->nfd = fd;
	new->next = NULL;
	return (new);
}
