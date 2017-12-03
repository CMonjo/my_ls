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
#include "printf.h"
int calculate_flags(int ac, char **av);
int nbr_of_flags(char **av, int count);
char *flags_for_my_ls(char *av, char *my_flag);
void calculate_path(int ac, char **av, char *my_flag);
int nbr_of_path(char **av, int count);
char *which_paths(char **av, int *count);
void which_flag(char *my_path, char *my_flag, int nbr_flags, int nbr_path);
void which_flag_exception(char *my_path, int nbr_flags, int nbr_path);
int without_flag(char *my_path);
int flag_my_ls_R(char *my_path);
int flag_my_ls_l(char *my_path);
int flag_my_ls_a(char *my_path);
void my_right(struct stat sb, char *mytime);
void my_type_of_file_second(struct stat sb);
void my_type_of_file(struct stat sb);
char *my_time(char *mytime, struct stat sb);
#endif
