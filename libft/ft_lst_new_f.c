/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:24:16 by bford             #+#    #+#             */
/*   Updated: 2019/09/22 14:33:09 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

f_list	*ft_lst_new_f(char c, int n)
{
	f_list	*new;

	if (!(new = (f_list *)malloc(sizeof(f_list))))
		return (NULL);
	new->c = c;
	new->n = n;
	new->next = NULL;
	return (new);
}