/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/13 21:02:48 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next.h"


char *joiny(char *montoncito, int fd)
{
    char *buffer;

    buffer = calloc(sizeof(char), BUFFER_SIZE + 1);
    if (!montoncito)
        montoncito = calloc(sizeof(char), BUFFER_SIZE + 1);
    read(fd, buffer, BUFFER_SIZE);
    montoncito = ft_strjoin(montoncito, buffer);
    while (!ft_strchr(buffer, '\n') || !ft_strchr(buffer, '\0') )
    {
        read(fd, buffer, BUFFER_SIZE);
        montoncito = ft_strjoin(montoncito, buffer);
    }
    return(montoncito);
}

char *cutty(char *montoncito)
{
    int     cont;
    int     i;
    char    *line;

    cont = 0;
    i = 0;
    while (montoncito[cont] != '\0' && montoncito[cont] != '\n')
        cont++;
    line = ft_calloc(sizeof(char), cont);
    while (i < cont)
    {
        line[i] = montoncito[i];
        i++;
    }
    return (line);
}

char *get_next_line (int fd)
{
    static char *montoncito;
    char *line;
    montoncito = joiny(montoncito, fd); // (0\+ho+la+\nq) -> (q+ue+ta+l\n)
    line = cutty(montoncito); //((hola\n)q)
    
    printf("El valor de line es: %s\n", line);
    
    montoncito += ft_strlen(line) + 1;
    printf("El valor de montoncito es: %s\n", montoncito);
   return (line); 
}

int main(int argc, char **argv)
{
    get_next_line(open(argv[1], O_RDONLY));
    return (0);
}