/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:15:43 by herrakot          #+#    #+#             */
/*   Updated: 2024/04/30 13:04:32 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list_bonus
{
	char				*str;
	struct s_list_bonus	*next;
}					t_list;

char				*get_next_line(int fd);
void				create_bonus(t_list **list, int fd);
void				linking_the_list_bonus(t_list **list, char *tmp, int fd);
char				*get_before_newline_bonus(t_list *list);
void				after_newline_bonus(t_list **list);
void				all_free_bonus(t_list **list, t_list *node_2, char *tmp);
int					ft_strchr_list_bonus(t_list *list);
void				copy_bonus(t_list *list, char *str_1);
int					count_to_newline_bonus(t_list *list);
t_list				*find_node_bonus(t_list *list);

#endif
