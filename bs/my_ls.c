/*
** EPITECH PROJECT, 2017
** my_ls bootstrap
** File description:
** .c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"

char *my_find_name(char *str)
{
	char* tmp = malloc(sizeof(char) * my_strlen(str));
	int i = 0;

	if (tmp == NULL)
		exit (84);
	my_revstr(str);
	while (str[i] != '/') {
		tmp[i] = str[i];
		i++;
	}
	my_revstr(tmp);
	free(tmp);
	return (tmp);
}

void my_type_2(struct stat sb)
{
	switch (sb.st_mode & S_IFMT) {
		case S_IFIFO:
			my_printf("p\n");
			break;
		case S_IFLNK:
			my_printf("l\n");
			break;
		case S_IFREG:
			my_printf("-\n");
			break;
		case S_IFSOCK:
			my_printf("s\n");
			break;
	}
}

void my_type(struct stat sb)
{
	switch (sb.st_mode & S_IFMT) {
		case S_IFBLK:
			my_printf("b\n");
			break;
		case S_IFCHR:
			my_printf("c\n");
			break;
		case S_IFDIR:
			my_printf("d\n");
			break;
	}
	my_type_2(sb);
}

void my_display(struct stat sb, char *av[])
{
	my_printf("Name: %s\n", my_find_name(av[1]));
	my_printf("Type: ");
	my_type(sb);
	my_printf("Inode: %ld\n", (long long int)sb.st_ino);
	my_printf("Hard Link: %ld\n", (long) sb.st_nlink);
	my_printf("Size: %lld\n", (long long) sb.st_size);
	my_printf("Allocated space: %lld O\n", (long long)sb.st_blocks);
	my_printf("Minor: %d\n", minor(sb.st_dev));
	my_printf("Major: %d\n", major(sb.st_dev));
	my_printf("UID: %ld\n", (long)sb.st_uid);
	my_printf("GID: %ld\n", (long)sb.st_gid);
}

int main(int ac, char *av[])
{
	struct stat sb;

	if (ac != 2) {
		my_printf("Usage: %s <pathname>\n", av[0]);
		return (84);
	}
	if (stat(av[1], &sb) == -1) {
		perror("stat");
		return (0);
	}
	my_display(sb, av);
	return (0);
}
