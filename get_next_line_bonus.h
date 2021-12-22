/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coskelet <coskelet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:36:52 by coskelet          #+#    #+#             */
/*   Updated: 2021/11/30 19:14:46 by coskelet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list {
	int				fd;
	ssize_t			buf_line_size;
	char			*buf_line;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	get_list_elem(const int fd, t_list **lst, t_list **l_elem);
void	free_list(t_list **lst, int fd);

#endif
