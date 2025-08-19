/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:23:35 by herrakot          #+#    #+#             */
/*   Updated: 2024/04/30 13:05:14 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	after_newline_bonus(t_list **list)
{
	t_list			*actual_node;
	t_list			*node_2;
	int				i;
	int				x;
	char			*tmp;

	i = 0;
	x = 0;
	tmp = malloc(BUFFER_SIZE + 1);
	node_2 = malloc(sizeof(t_list));
	if (!tmp || !node_2)
		return ;
	actual_node = find_node_bonus(*list);
	while (actual_node->str[i] && actual_node->str[i] != '\n')
		++i;
	while (actual_node->str[i] && actual_node->str[++i])
		tmp[x++] = actual_node->str[i];
	tmp[x] = '\0';
	node_2->str = tmp;
	node_2->next = NULL;
	all_free_bonus(list, node_2, tmp);
}

char	*get_before_newline_bonus(t_list *list)
{
	int		str_count;
	char	*str_1;

	str_count = count_to_newline_bonus(list);
	str_1 = malloc(str_count + 1);
	if (!str_1)
		return (NULL);
	copy_bonus(list, str_1);
	return (str_1);
}

void	linking_the_list_bonus(t_list **list, char *tmp, int fd)
{
	t_list	*node_1;
	t_list	*actual_node;

	actual_node = find_node_bonus(list[fd]);
	node_1 = malloc(sizeof(t_list));
	if (!node_1)
		return ;
	if (actual_node == NULL)
		list[fd] = node_1;
	else
		actual_node->next = node_1;
	node_1->str = tmp;
	node_1->next = NULL;
}

void	create_bonus(t_list **list, int fd)
{
	int		index;
	char	*tmp;

	index = 0;
	while (!ft_strchr_list_bonus(list[fd]))
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return ;
		index = read(fd, tmp, BUFFER_SIZE);
		if (index == -1)
		{
			free(tmp);
			return ;
		}
		if (index == 0)
		{
			free(tmp);
			return ((void) NULL);
		}
		tmp[index] = '\0';
		linking_the_list_bonus(list, tmp, fd);
	}
}

char	*get_next_line(int fd)
{
	static t_list		*list[4096];
	char				*the_line;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	create_bonus(list, fd);
	if (list[fd] == NULL)
		return (NULL);
	the_line = get_before_newline_bonus(list[fd]);
	after_newline_bonus(&list[fd]);
	return (the_line);
}
