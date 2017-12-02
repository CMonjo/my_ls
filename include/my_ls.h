/*
** EPITECH PROJECT, 2017
** Project my_ls
** File description:
** Includes file
*/

#ifndef _MY_LS_
	#define _MY_LS_
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
	#include "struct.h"
	int calculate_flags(int ac, char **av);
	int nbr_of_flags(char **av, int count);
	char *ls_flags(char *av, char *my_flag);
	int calculate_path(int ac, char **av, char *my_flag);
	int nbr_of_path(char **av, int count);
	char *paths(char **av, int *count);
	void which_flag(char *my_path, char *my_flag, int nbr_flags);
	int without_flag(char *my_path);
	int flag_R(char *my_path);
	int flag_a(char *my_path);
	int flag_l(char *my_path);
	void my_right(struct stat sb, char *mytime);
	void my_type_of_file_second(struct stat sb);
	void my_type_of_file(struct stat sb);
	char *my_time(char *mytime, struct stat sb);
#endif
