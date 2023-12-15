/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/15 19:49:36 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*b;

	if (!s)
		return (NULL);
	a = ft_strlen(s);
	if (start >= a)
	{
		b = ft_calloc(1, 1);
		if (!b)
			return (NULL);
		return (b);
	}
	if (len > a)
		len = a - start;
	b = ft_calloc (sizeof(char), len + 1);
	if (!b)
		return (NULL);
	b = ft_memcpy(b, &s[start], len);
	return (b);
}

char	*joiny(char *montoncito, int fd)
{
	char	*buffer;
	int		aux;
	char	*temp;

	aux = 1;
	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!montoncito)
		montoncito = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n'))
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if (aux == 0)
			break ;
		buffer[aux] = '\0';
		temp = montoncito;
		montoncito = ft_strjoin(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (montoncito);
}

char	*cutty(char *montoncito)
{
	int		cont;
	int		i;
	char	*line;

	cont = 0;
	i = 0;
	while (montoncito[cont] != '\0' && montoncito[cont] != '\n')
		cont++;
	line = ft_calloc(sizeof(char), cont + 1);
	if(!line)
		return(NULL);
	while (i < cont)
	{
		line[i] = montoncito[i];
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*montoncito;
	char		*line;
	char		*tmp;

	montoncito = joiny(montoncito, fd);
	line = cutty(montoncito);
	//printf("\nEl valor de line es: %s\n", line);
	tmp = montoncito;
	montoncito = ft_substr(montoncito, ft_strlen(line) + 1, -1);
	if (!montoncito)
		montoncito = tmp;
	else
		free(tmp);
	//printf("El valor de montoncito es: %s\n", montoncito);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	char *str;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	printf("El resultado es: %s\n", str);
	free(str);
	system("leaks -q a.out");
	str = get_next_line(fd);
	printf("El resultado es: %s\n", str);
	free(str);
	system("leaks -q a.out");

	return (0);
}