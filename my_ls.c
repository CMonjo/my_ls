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
#include <h>
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

int my_right(char *av[])
{
	struct stat sb;
	struct gu

	if (stat(av[0], &sb) == -1) {
		return (84);
	}
	my_type(sb);
	//my_printf("%d", sb.st_mode % 512);
	my_printf((sb.st_mode & S_IRUSR) ? "r" : "-");//USR
	my_printf((sb.st_mode & S_IWUSR) ? "w" : "-");//USR
	my_printf((sb.st_mode & S_IXUSR) ? "x" : "-");//USR
	my_printf((sb.st_mode & S_IRGRP) ? "r" : "-");//GPR
	my_printf((sb.st_mode & S_IWGRP) ? "w" : "-");//GPR
	my_printf((sb.st_mode & S_IXGRP) ? "x" : "-");//GPR
	my_printf((sb.st_mode & S_IROTH) ? "r" : "-");//OTH
	my_printf((sb.st_mode & S_IWOTH) ? "w" : "-");//OTH
	my_printf((sb.st_mode & S_IXOTH) ? "x" : "-");//OTH
	my_printf(" %ld ", (long)sb.st_nlink);
	my_printf("%s ", ctime(&sb.st_mtime));
	//printf("Nom group ");
	//printf("SIZE : %lld bytes ", sb.st_size);
	return (0);
}

//TYPE - DROITS - HARD LINK - NOM PROPRIO - NOM GROUP - TAILLE OCTET - LAST MODIF - NOME FICHIER
int flag_l(DIR *dir, struct dirent *file, char *av[])
{
	dir = opendir(av[2]);
	if (dir == NULL)
		return (84);
	my_printf("total\n");
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.') {
			my_right(av);
			//my_printf("%s", file->d_name);
		}
	}
	closedir(dir);
	return (0);
}

int without_flag(DIR *dir, struct dirent *file)
{
	dir = opendir(".");
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.')
			my_printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}

int flag_a(DIR *dir, struct dirent *file)
{
	dir = opendir(".");
	if (dir == NULL)
		return (84);
	while ((file = readdir(dir)) != NULL) {
			my_printf("%s\n", file->d_name);
	}
	closedir(dir);
	return (0);
}

int main(int ac, char **av)
{
	DIR *dir = NULL;
	struct dirent *file = NULL;
	char *str = malloc(sizeof(char *) * ac);
	// struct stat sb;
        //
	// if (stat(av[0], &sb) == -1) {
	// 	//perror("ls");
	// 	return (0);
	// }
	if (str == NULL)
		return (84);
	if (ac == 1 || av[1][0] == '.')
		without_flag(dir, file);
	else if (av[1][0] == '-' && av[1][1] == 'a')
		flag_a(dir, file);
	else if (av[1][0] == '-' && av[1][1] == 'l')
		flag_l(dir, file, av);
	return 0;
}
