/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/14 20:18:52 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		temp = ft_strjoin(montoncito, buffer);
		free(montoncito);
		montoncito = temp;
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
	while (i < cont)
	{
		line[i] = montoncito[i];
		i++;
	}
	if (montoncito != NULL)
	{
		free(montoncito);
		montoncito = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*montoncito;
	char		*line;
	char		*ref;

	montoncito = joiny(montoncito, fd);
	line = cutty(montoncito);
	ref = montoncito;
	printf("\nEl valor de line es: %s\n", line);
	montoncito += ft_strlen(line) + 1;
	printf("El valor de montoncito es: %s\n", montoncito);
	free(montoncito);
	montoncito = NULL;
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return (0);
}
