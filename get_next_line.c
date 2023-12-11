/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 22:16:30 by barjimen          #+#    #+#             */
/*   Updated: 2023/12/11 19:19:57 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next.h"


char *joiny(char *montoncito, int fd)
{
    char *buffer;

    buffer = calloc(sizeof(char), BUFFER_SIZE + 1);
    if(!montoncito)
        montoncito = calloc(sizeof(char), 1);
    
    while (!ft_strchr(buffer, '\n'))
    {
        read(fd, buffer ,BUFFER_SIZE);
        ft_strjoin(montoncito, buffer);
    }
    
    
    
}

static char *save(char *buffer, int nbites)
{
    int count;
    
    count = 0;
    //calloc(buffer, nbites);
   while (buffer)
   {
        if(buffer[count] == "\n" || buffer[count] == '\0')
        {
              
        }
        else
        count++;
   }
   return(buffer); //que será el nuevo valor a unir
}

char *cutty()
{
    
}

char *get_next_line (int fd)
{
    static char *montoncito;
    montoncito = joiny(montoncito, fd);
}

int main(int argc, char **argv)
{
    int resread;
    int fd;
    int nbites;
    char *buffer;
    char *path;
    if(1)
    {
        nbites = ft_atoi(argv[2]);
        buffer = malloc(nbites + 1);
        path = argv[1];
        fd = open(path, O_RDONLY);
        resread = read(fd, buffer ,nbites);
        
        save(buffer, nbites);
        printf("el resultado de resread es %d\n", resread);
        printf("Lo que ha leido es:\n%s\n", buffer);
    }
    return(0);
}