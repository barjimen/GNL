/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:13:30 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/13 19:40:56 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next.h"

int	ft_atoi(const char *str)
{
	int			x;
	long int	nb;
	int			sym;

	x = 0;
	nb = 0;
	sym = 1;
	while ((str[x] >= 9 && str[x] <= 13) || (str[x] == 32))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			sym *= -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		nb = (str[x++] - '0') + (nb * 10);
		if (nb > 2147483647 && sym == 1)
			return (-1);
		else if (nb > 2147483648 && sym == -1)
			return (0);
	}
	nb *= sym;
	return (nb);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*a;
	size_t	b;
	size_t	c;

	b = count * size;
	a = (char *) malloc(b);
	if (b < size && b < count)
	{
		return (NULL);
	}
	if (a != NULL)
	{
		c = 0;
		while (c < b)
		{
			a[c] = '\0';
			c++;
		}
	}
	return ((void *)a);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	a;
	char	*strg;

	a = (char)c;
	strg = (char *)str;
	i = 0;
	while (strg[i])
	{
		if (strg[i] == a)
			return (&strg[i]);
		i++;
	}
	if (strg[i] == a)
		return (&strg[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		m;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	m = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc(m + 1, sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[a])
	{
		s3[a] = s1[a];
		a++;
	}
	while (s2[b])
	{
		s3[a++] = s2[b++];
	}
	s3[a] = '\0';
	return (s3);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}