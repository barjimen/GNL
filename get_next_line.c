/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/01/15 16:47:10 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	tmp = calloc(sizeof(char), ft_strlen(montoncito) + 2 - count);
	while (montoncito[count])
		tmp[x++] = montoncito[count++];
	free(montoncito);
	return (tmp);
}

char	*cutty(char **montoncito)
{
	int		cont;
	char	*line;

	cont = 0;
	while ((*montoncito)[cont] != '\0' && (*montoncito)[cont] != '\n')
		cont++;
	line = ft_calloc(sizeof(char), cont + 2);
	if (!line)
		return (NULL);
	ft_memcpy(line, *montoncito, cont + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*montoncito;
	char		*line;

	line = NULL;
	if (fd != -1 || BUFFER_SIZE > 0 || BUFFER_SIZE < 2147483647)
	{
		montoncito = joiny(montoncito, fd);
		if (!montoncito)
			return (NULL);
		line = cutty(&montoncito);
		montoncito = clean(montoncito);
	}
	return (line);
}

// int	main(void)
// {
// 	int fd;
// 	char *str;

// 	fd = open("notita.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("->%s<-", str);
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		printf("->%s<-", str);
// 	}

// 	return (0);
// }