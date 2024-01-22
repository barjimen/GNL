#include "get_next_line.h"
int	main(void)
{
	int fd1;
	int fd2;
	char *str;

	fd1 = open("notita.txt", O_RDONLY);
	fd2 = open("notita1.txt", O_RDONLY);
	str = get_next_line(fd1);
	printf("->%s<-", str);
	str = get_next_line(fd2);
	printf("->%s<-", str);
	str = get_next_line(fd1);
	printf("->%s<-", str);
	str = get_next_line(fd2);
	printf("->%s<-", str);	

	// while (str)
	// {
	// 	str = get_next_line(fd);
	// 	printf("->%s<-", str);
	// }

	return (0);
}