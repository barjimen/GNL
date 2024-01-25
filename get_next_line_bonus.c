/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:09:24 by barjimen          #+#    #+#             */
/*   Updated: 2024/01/25 19:11:45 by barjimen         ###   ########.fr       */
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

int	readfile(int fd, char *buffer, char **stack)
{
	int	aux;

	aux = read(fd, buffer, BUFFER_SIZE);
	if (aux < 0 || !buffer)
	{
		if (aux == -1 && *stack)
		{
			free(*stack);
			*stack = NULL;
		}
	}
	else
	{
		buffer[aux] = '\0';
	}
	return (aux);
}

char	*joiny(char *stack, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		aux;
	char	*temp;

	aux = 1;
	ft_memset(&buffer, 0, BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n'))
	{
		aux = readfile(fd, buffer, &stack);
		if (aux <= 0 || !*buffer)
			break ;
		if (stack)
		{
			temp = stack;
			stack = ft_strjoin(temp, buffer);
			free(temp);
		}
		else
		{
			stack = ft_calloc(sizeof(char), aux + 1);
			ft_memcpy(stack, buffer, aux);
		}
	}
	return (stack);
}

char	*clean(char *stack)
{
	int		count;
	int		x;
	char	*tmp;

	x = 0;
	count = 0;
	while ((count == 0 || stack[count - 1] != '\n')
		&& stack[count] != '\0')
		count++;
	if (!stack[count])
	{
		free(stack);
		return (NULL);
	}
	tmp = ft_calloc(sizeof(char), ft_strlen(stack) + 2 - count);
	while (stack[count])
		tmp[x++] = stack[count++];
	free(stack);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stack[1024];
	char		*line;
	int			cont;

	cont = 0;
	if (fd != -1 || BUFFER_SIZE > 0 || BUFFER_SIZE < 2147483647)
	{
		stack[fd] = joiny(stack[fd], fd);
		if (!stack[fd])
			return (NULL);
		while ((stack)[fd][cont] != '\0'
			&& (stack)[fd][cont] != '\n')
			cont++;
		line = ft_calloc(sizeof(char), cont + 2);
		if (!line)
			return (NULL);
		ft_memcpy(line, stack[fd], cont + 1);
		stack[fd] = clean(stack[fd]);
	}
	return (line);
}
