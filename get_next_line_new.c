/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:33:09 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/28 18:47:07 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *joiny(char *montoncito, int fd)
{
    char    buffer[BUFFER_SIZE + 1];
    int     aux;
    
	aux = 1;
	buffer[aux] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if(aux == 0)
			break;
		
	}
	
}
char    *clean()
{
    
}

char    *cutty()
{
    
}

char	*get_next_line(int fd)
{
	static char	*montoncito;
	char		*line;

	line = NULL;
	if (fd != -1 || BUFFER_SIZE > 0)
	{
		montoncito = joiny(montoncito, fd);
		if (!montoncito)
			return (NULL);
		line = cutty(&montoncito);
	}
	return (line);
}