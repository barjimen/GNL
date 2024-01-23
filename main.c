/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barjimen <barjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:17:31 by barjimen          #+#    #+#             */
/*   Updated: 2024/01/23 21:17:32 by barjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// void leaks(){
// 	system("leaks -q a.out");
// }
// int	main(void)
// {
// 	int fd1;
// 	int fd2;
// 	char *str;

// 	fd1 = open("notita.txt", O_RDONLY);
// 	fd2 = open("notita1.txt", O_RDONLY);
// 	str = get_next_line(fd1);
// 	printf("->%s<-", str);
// 	str = get_next_line(fd2);
// 	printf("->%s<-", str);
// 	str = get_next_line(fd1);
// 	printf("->%s<-", str);
// 	str = get_next_line(fd2);
// 	printf("->%s<-", str);	
// 	// atexit(leaks);

// 	return (0);
// }
