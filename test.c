int count_path(char **argv, int cpt)
{
    int i = 0;
    while (argv[i] != NULL) {
        if (argv[i][0] != '-')
            cpt += 1;
        i += 1;
    }
    return (cpt);
}

char *find_path(char **argv, int *cpt)
{
    char *path = "e";

    while (argv[*cpt] != NULL) {
        if (argv[*cpt][0] != '-') {
            path = argv[*cpt];
            *cpt += 1;
            return (path);
        }
        else
            *cpt += 1;
    }
    return (path);
}

// void display_file(char *path)
// {
//     struct dirent *file;
//     DIR *dir;
//     dir = opendir(path);
//     file = readdir(dir);
//     while (file != NULL) {
//         if (file->d_name[0] != '.')
//             printf("%s\n", file->d_name);
//         file = readdir(dir);
//     }
// }

int main(int argc, char **argv)
{
    int *cpt = 1;
    int cpt_path = 0;
    char *path = malloc(sizeof(char) * argc * 2 + 1);

    if (argc == 1 || (argc == 2 && argv[1][0] == '-')) {
        path = ".";
        display_file(path);
    }
    else if (argc == 2) {
        path = argv[1];
        display_file(path);
    }
    else {
        cpt_path = count_path(argv, cpt_path);
        while (cpt_path > 1) {
            path = find_path(argv, &cpt);
            printf("%s:\n", path);
            display_file(path);
            cpt_path -= 1;
        }
    }
    return (0);
}
