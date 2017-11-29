/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** .c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"
#include "my_ls.h"

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
			my_printf("p");
			break;
		case S_IFLNK:
			my_printf("l");
			break;
		case S_IFREG:
			my_printf("-");
			break;
		case S_IFSOCK:
			my_printf("s");
			break;
	}
}

void my_type(struct stat sb)
{
	switch (sb.st_mode & S_IFMT) {
		case S_IFBLK:
			my_printf("b");
			break;
		case S_IFCHR:
			my_printf("c");
			break;
		case S_IFDIR:
			my_printf("d");
			break;
	}
	my_type_2(sb);
}

void my_time(char *mytime, struct stat sb)
{
	mytime[0] = ctime(&sb.st_mtime)[4] + 32;
	mytime[1] = ctime(&sb.st_mtime)[5];
	mytime[2] = ctime(&sb.st_mtime)[6];
	mytime[3] = '.';
	mytime[4] = ' ';
	mytime[5] = ctime(&sb.st_mtime)[8];
	mytime[6] = ctime(&sb.st_mtime)[9];
	mytime[7] = ' ';
	mytime[8] = ctime(&sb.st_mtime)[11];
	mytime[9] = ctime(&sb.st_mtime)[12];
	mytime[10] = ':';
	mytime[11] = ctime(&sb.st_mtime)[14];
	mytime[12] = ctime(&sb.st_mtime)[15];
	mytime[13] = '\0';
}
