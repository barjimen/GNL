/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:09:31 by barjimen          #+#    #+#             */
/*   Updated: 2024/01/22 20:03:49 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h"
# include "unistd.h"
# include "fcntl.h"
# include "string.h"
# include "stdlib.h"

//END LIB;
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif // BUFFER_SIZE
# if BUFFER_SIZE > 8000000
#  undef BUFFER_SIZE 
# define BUFFER_SIZE 1
# endif

//FUNCTIONS

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif