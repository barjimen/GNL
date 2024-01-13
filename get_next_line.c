/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2024/01/13 19:42:14 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int readFile(int fd, char *buffer, char **montoncito)
{
	int aux;
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
	return aux;
}

char	*joiny(char *montoncito, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		aux;
	char	*temp;

	aux = 1;
	// buffer[aux] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		aux = readFile(fd, buffer, &montoncito);
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
	// printf("\n montoncito es: %s", montoncito);
	while ((count == 0 || montoncito[count - 1] != '\n') && montoncito[count] != '\0')
		count++;
	// if (montoncito[count] == '\n')
	//	count++;
	if (!montoncito[count])
	{
		free(montoncito);
		return (NULL);
	}
	tmp = calloc(sizeof(char), ft_strlen(montoncito) + 2 - count);
	while (montoncito[count])
	{
		tmp[x++] = montoncito[count++];
	}
	// printf("\n tmp es: %s", tmp);
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
		// printf("\n line es: %s", line);
		// printf("\n montoncito es: %s", montoncito);
		montoncito = clean(montoncito);
		// printf("montoncito es: |%s|", montoncito);
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