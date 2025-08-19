/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:15:35 by herrakot          #+#    #+#             */
/*   Updated: 2024/04/30 12:59:48 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	count_to_newline_bonus(t_list *list)
{
	int	i;
	int	x;

	x = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				++x;
				return (x);
			}
			x++;
			i++;
		}
		list = list->next;
	}
	return (x);
}

void	copy_bonus(t_list *list, char *str_1)
{
	int	i;
	int	x;

	x = 0;
	while (list)
	{
		i = 0;
		while (list->str[i])
		{
			if (list->str[i] == '\n')
			{
				str_1[x++] = '\n';
				str_1[x] = '\0';
				return ;
			}
			str_1[x++] = list->str[i++];
		}
		list = list->next;
	}
	str_1[x] = '\0';
}

int	ft_strchr_list_bonus(t_list *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->str[i] && i < BUFFER_SIZE)
		{
			if (list->str[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_list	*find_node_bonus(t_list *list)
{
	if (NULL == list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	all_free_bonus(t_list **list, t_list *node_2, char *tmp)
{
	t_list	*src;

	if (NULL == *list)
		return ;
	while (*list)
	{
		src = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = src;
	}
	*list = NULL;
	if (node_2->str[0])
		*list = node_2;
	else
	{
		free(tmp);
		free(node_2);
	}
}
