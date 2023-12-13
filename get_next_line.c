/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/13 22:54:48 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next.h"

#define JUMP  "\033[31m\\n\033[0m"
#define begin "\033[32m[\033[0m"
#define end "\033[32m] \033[0m"
void write_buffer(char *str)
{
    int i = 0;
    write(1, begin, strlen(begin));
    while (str[i])
    {
        if (str[i] == '\n')
             write(1, JUMP, strlen(JUMP));
        else
            write(1, &str[i], 1);
        i++;
    }
    write(1, end, strlen(end));
}

char *joiny(char *montoncito, int fd)
{
    char *buffer;
    int aux = 1;

    buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
    if (!montoncito)
        montoncito = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
    while (!ft_strchr(buffer, '\n'))
    {
        aux = read(fd, buffer, BUFFER_SIZE);
        if (aux == 0)
            break ;
        buffer[aux] = '\0';
        write_buffer(buffer);
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
    
    printf("\nEl valor de line es: %s\n", line);
    
    montoncito += ft_strlen(line) + 1;
    printf("El valor de montoncito es: %s\n", montoncito);
   return (line); 
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    get_next_line(fd);
    get_next_line(fd);
    
    return (0);
}