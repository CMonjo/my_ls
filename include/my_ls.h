/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** Définition fonctions
*/
#ifndef _MY_LS_
	#define _MY_LS_
	#include "struct.h"
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
	void my_type_2(struct stat sb);
	void my_type(struct stat sb);
	char *my_time(char *mytime, struct stat sb);
	void my_right(struct stat sb, char *mytime);
	int flag_l(char *my_path);
	int flag_r(char *my_path);
	int without_flag(char *my_path);
	void which_flag(char **av, char *my_path, char *my_flag, int nbr_flags);
	char *ls_flags(char *av, char *my_flag);
	int nbr_of_path(char **av, int count);
	int nbr_of_flags(char **av, int count);
	char *paths(char **av, int *count);
	int calculate_flags(int ac, char **av);
	int calculate_path(int ac, char **av, char *my_flag);
	int flag_a(char *my_path);
#endif
