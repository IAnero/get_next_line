/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:15:35 by herrakot          #+#    #+#             */
/*   Updated: 2024/04/19 14:46:56 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int count_to_newline(t_list list)
{
    int i;
    int count;

    count = 0;
    while (*list)
    {
        i = 0;
        while (list ->str[i])
        {
            if (list ->str[i] == '\n')
            {
                ++len;
                return (len);
            }
            i++;
        }
        list = list ->next;
    }
    return (len);
}

void    copy_to_firstpart(t_list list, char *str_1)
{
    int i;
    int x;

    count = 0;
    while (*list)
    {
        i = 0;
        while (list ->str[i])
        {
            if (list ->str[i] == '\n')
            {
                str_1[x++] = '\n';
                str_1[x] = '\0';
                return;
            }
            str_1[x++] = list ->str[i++];
        }
        list = list ->next;
    }
    str_1[x] = '\0';
}
char	*ft_strchr(char *s)
{
	int		x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == '\n')
		{
			return (s + x);
		}
		x++;
	}
	return (NULL);
}

/*void    All_free(t_list **list, t_list *node_2, char *tmp)
{

}*/