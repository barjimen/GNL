/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:09:24 by barjimen          #+#    #+#             */
/*   Updated: 2024/01/23 21:09:25 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*i;
	int		cont;

	cont = 0;
	i = (char *)b;
	while (len)
	{
		i[cont] = c;
		cont++;
		len--;
	}
	return ((void *)i);
}

int	readfile(int fd, char *buffer, char **montoncito)
{
	int	aux;

	aux = read(fd, buffer, BUFFER_SIZE);
	if (aux < 0 || !buffer)
	{
		if (aux == -1 && *montoncito)
		{
			free(*montoncito);
			*montoncito = NULL;
		}
	}
	else
	{
		buffer[aux] = '\0';
	}
	return (aux);
}

char	*joiny(char *montoncito, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		aux;
	char	*temp;

	aux = 1;
	ft_memset(&buffer, 0, BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n'))
	{
		aux = readfile(fd, buffer, &montoncito);
		if (aux <= 0 || !*buffer)
			break ;
		if (montoncito)
		{
			temp = montoncito;
			montoncito = ft_strjoin(temp, buffer);
			free(temp);
		}
		else
		{
			montoncito = ft_calloc(sizeof(char), aux + 1);
			ft_memcpy(montoncito, buffer, aux);
		}
	}
	return (montoncito);
}

char	*clean(char *montoncito)
{
	int		count;
	int		x;
	char	*tmp;

	x = 0;
	count = 0;
	while ((count == 0 || montoncito[count - 1] != '\n')
		&& montoncito[count] != '\0')
		count++;
	if (!montoncito[count])
	{
		free(montoncito);
		return (NULL);
	}
	tmp = ft_calloc(sizeof(char), ft_strlen(montoncito) + 2 - count);
	while (montoncito[count])
		tmp[x++] = montoncito[count++];
	free(montoncito);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*montoncito[1024];
	char		*line;
	int			cont;

	cont = 0;
	if (fd != -1 || BUFFER_SIZE > 0 || BUFFER_SIZE < 2147483647)
	{
		montoncito[fd] = joiny(montoncito[fd], fd);
		if (!montoncito[fd])
			return (NULL);
		while ((montoncito)[fd][cont] != '\0'
			&& (montoncito)[fd][cont] != '\n')
			cont++;
		line = ft_calloc(sizeof(char), cont + 2);
		if (!line)
			return (NULL);
		ft_memcpy(line, montoncito[fd], cont + 1);
		montoncito[fd] = clean(montoncito[fd]);
	}
	return (line);
}
