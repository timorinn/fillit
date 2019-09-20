/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bford <bford@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:25:41 by bford             #+#    #+#             */
/*   Updated: 2019/09/20 17:51:53 by bford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		finish(my_list **lst, char **line, my_list **l_copy)
{
	if (!(*lst)->content)
	{
		*line = NULL;
		return (0);
	}
	*line = ft_strdup((*lst)->content);
	if (!(ft_strlen(*line)))
		return (0);
	free((*lst)->content);
	(*lst)->content = NULL;
	*lst = *l_copy;
	return (1);
}

int		find_lst(my_list **lst, my_list **l_copy, int fd)
{
	if (!(*lst))
		if (!(*lst = ft_lstnewget(fd)))
			return (-1);
	*l_copy = *lst;
	while ((*lst)->nfd != fd && (*lst)->next)
		*lst = (*lst)->next;
	if ((*lst)->nfd != fd)
	{
		if (!((*lst)->next = ft_lstnewget(fd)))
			return (-1);
		*lst = (*lst)->next;
	}
	return (1);
}

int		check(char **con, char **line, my_list **l_copy, my_list **lst)
{
	char	*p;
	char	*p2;

	if (!(*con) || !(ft_strchr(*con, '\n')))
		return (0);
	p = ft_strchr(*con, '\n');
	p2 = *con;
	*p++ = '\0';
	*line = ft_strdup(*con);
	if (!(*line) || !(*con = ft_strdup(p)))
		return (-1);
	free(p2);
	*lst = *l_copy;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static my_list	*lst;
	char			buff[BUFF_SIZE + 1];
	int				t;
	my_list			*l_copy;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (find_lst(&lst, &l_copy, fd) == -1)
		return (-1);
	t = check(&(lst->content), line, &l_copy, &lst);
	if (t)
		return (t);
	while ((t = read(fd, buff, BUFF_SIZE)))
	{
		buff[t] = '\0';
		if (lst->content)
			lst->content = ft_strjoinfree(lst->content, buff);
		else
			lst->content = ft_strdup(buff);
		t = check(&(lst->content), line, &l_copy, &lst);
		if (t)
			return (t);
	}
	return (finish(&lst, line, &l_copy));
}
