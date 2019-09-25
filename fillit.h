/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:37:20 by bford             #+#    #+#             */
/*   Updated: 2019/09/25 13:13:49 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

int				g_a[19][8] = {
	{0, 1, 1, 0, 1, 1, 2, 2}, {1, 0, 2, 0, 3, 0, 4, 1},
	{0, 1, 0, 2, 0, 3, 1, 4}, {0, 1, 1, 0, 2, 0, 3, 2},
	{0, 1, 0, 2, 1, 2, 2, 3}, {1, 0, 2, -1, 2, 0, 3, 2},
	{1, 0, 1, 1, 1, 2, 2, 3}, {0, 1, 1, 1, 2, 1, 3, 2},
	{1, -2, 1, -1, 1, 0, 2, 3}, {1, 0, 2, 0, 2, 1, 3, 2},
	{0, 1, 0, 2, 1, 0, 2, 3}, {1, 0, 1, 1, 2, 1, 3, 2},
	{0, 1, 1, -1, 1, 0, 2, 3}, {1, -1, 1, 0, 2, -1, 3, 2},
	{0, 1, 1, 1, 1, 2, 2, 3}, {1, 0, 1, 1, 2, 0, 3, 2},
	{1, -1, 1, 0, 2, 0, 3, 2}, {1, -1, 1, 0, 1, 1, 2, 3},
	{0, 1, 0, 2, 1, 1, 2, 3}};

t_fil	*g_l;

#endif
