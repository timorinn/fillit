/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduporjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:01:58 by bford             #+#    #+#             */
/*   Updated: 2019/09/28 14:16:14 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strduporjoin(char **s, char *s2)
{
	if (!(*s))
	{
		if (!(*s = ft_strdup(s2)))
			return (0);
		return (1);
	}
	else if (!(*s = ft_strjoinfree(*s, s2)))
		return (0);
	return (1);
}
