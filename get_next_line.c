/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:23:35 by herrakot          #+#    #+#             */
/*   Updated: 2024/05/11 12:07:43 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	after_newline(t_list **list)
{
	t_list	*actual_node;
	t_list	*node_2;
	int		i;
	int		x;
	char	*tmp;

	i = 0;
	x = 0;
	tmp = malloc(BUFFER_SIZE + 1);
	node_2 = malloc(sizeof(t_list));
	if (!tmp || !node_2)
		return ;
	actual_node = find_node(*list);
	while (actual_node->str[i] && actual_node->str[i] != '\n')
		i++;
	while (actual_node->str[i] && actual_node->str[i++])
		tmp[x++] = actual_node->str[i];
	tmp[x] = '\0';
	node_2->str = tmp;
	node_2->next = NULL;
	all_free(list, node_2, tmp);
}

char	*get_before_newline(t_list *list)
{
	int		str_count;
	char	*str_1;

	if (list == NULL)
		return (NULL);
	str_count = count_to_newline(list);
	str_1 = malloc(str_count + 1);
	if (!str_1)
		return (NULL);
	copy_to_firstpart(list, str_1);
	return (str_1);
}

void	linking_the_list(t_list **list, char *tmp)
{
	t_list	*node_1;
	t_list	*actual_node;

	if (list == NULL)
		return ;
	actual_node = find_node(*list);
	node_1 = malloc(sizeof(t_list));
	if (!node_1)
		return ;
	if (actual_node == NULL)
		*list = node_1;
	else
		actual_node->next = node_1;
	node_1->str = tmp;
	node_1->next = NULL;
}

void	create(t_list **list, int fd)
{
	int		index;
	char	*tmp;

	if (list == NULL)
		return ;
	index = 0;
	while (!ft_strchr_list(*list))
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
		linking_the_list(list, tmp);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*the_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create(&list, fd);
	if (list == NULL)
		return (NULL);
	the_line = get_before_newline(list);
	after_newline(&list);
	return (the_line);
}
