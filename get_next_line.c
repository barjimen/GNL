/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/19 22:35:58 by barjimen         ###   ########.fr       */
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
	b = ft_calloc(sizeof(char), len + 1);
	if (!b)
		return (NULL);
	b = ft_memcpy(b, &s[start], len);
	return (b);
}

char	*joiny(char *montoncito, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		aux;
	char	*temp;

	aux = 0;
	buffer[aux] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		aux = read(fd, buffer, BUFFER_SIZE);
		if ((aux == -1 || !*buffer))
		{
			return (montoncito);
		}
		if (aux == 0)
			break ;
		buffer[aux] = '\0';
		if (montoncito)
		{
			temp = montoncito;
			montoncito = ft_strjoin(temp, buffer);
			free(temp);
		}
		else
		{
			montoncito = ft_calloc(aux + 1, sizeof(char));
			ft_memcpy(montoncito, buffer, aux);
		}	
	}
	return (montoncito);
}

char	*cutty(char *montoncito)
{
	int		cont;
	char	*line;

	cont = 0;
	while (montoncito[cont] != '\n' && montoncito[cont] != '\0')
		cont++;
	if (montoncito[cont] == '\n')
		cont++;
	line = ft_calloc(sizeof(char), cont + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, montoncito, cont);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*montoncito;
	char		*line;
	char		*tmp;

	line = NULL;
	if (fd != -1 || BUFFER_SIZE > 0)
	{
		montoncito = joiny(montoncito, fd);
		if (!montoncito)
			return (NULL);
		if (!ft_strchr(montoncito, '\n'))
		{
			line = montoncito;
			montoncito = NULL;
		}
		else
		{
			line = cutty(montoncito);
			tmp = montoncito;
			montoncito = ft_substr(montoncito, ft_strlen(line), -1);
			if (!montoncito)
				montoncito = tmp;
			else
				free(tmp);
		}
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	char *str;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("-%s", str);
		str = get_next_line(fd);
		if (!str)
			break;
		free(str);
	}

	return (0);
}