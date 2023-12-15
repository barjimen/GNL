/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:13:35 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/15 19:03:53 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h"
# include "unistd.h"
# include "fcntl.h"
# include "string.h"
# include "stdlib.h"

//END LIB

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

//FUNCTIONS

char	*get_next_line(int fd);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *str);
char	*ft_strdup(const char *s1);

#endif