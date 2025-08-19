/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:15:43 by herrakot          #+#    #+#             */
/*   Updated: 2024/04/26 14:42:48 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				create(t_list **list, int fd);
void				linking_the_list(t_list **list, char *tmp);
char				*get_before_newline(t_list *list);
void				after_newline(t_list **list);
void				all_free(t_list **list, t_list *node_2, char *tmp);
int					ft_strchr_list(t_list *list);
void				copy_to_firstpart(t_list *list, char *str_1);
int					count_to_newline(t_list *list);
t_list				*find_node(t_list *list);

#endif
