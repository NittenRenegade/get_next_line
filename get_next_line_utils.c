/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:21:36 by coskelet          #+#    #+#             */
/*   Updated: 2021/12/02 17:48:36 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_list_elem(const int fd, t_list **lst, t_list **l_elem)
{
	t_list	*prev;

	prev = NULL;
	*l_elem = *lst;
	while (*l_elem && (*l_elem)->fd != fd)
	{
		prev = *l_elem;
		*l_elem = (*l_elem)->next;
	}
	if (*l_elem && (*l_elem)->fd == fd)
		return ;
	*l_elem = (t_list *)malloc(sizeof(t_list));
	if (!(*l_elem))
		return ;
	(*l_elem)->fd = fd;
	(*l_elem)->next = NULL;
	(*l_elem)->buf_line = NULL;
	(*l_elem)->buf_line_size = 0;
	if (prev)
		prev->next = *l_elem;
	else
		*lst = *l_elem;
	return ;
}

void	free_list(t_list **lst, int fd)
{
	t_list	*prev;
	t_list	*cur;

	prev = *lst;
	cur = *lst;
	while (cur)
	{
		if (cur->fd == fd)
		{
			if (cur->buf_line)
				free(cur->buf_line);
			if (prev == cur && !cur->next)
				*lst = NULL;
			else if (prev == cur)
				*lst = cur->next;
			else
				prev->next = NULL;
			free(cur);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
	return ;
}
