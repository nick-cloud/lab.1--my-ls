#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

	DIR            *dir;
    struct dirent  *file;
    struct stat  info;
    struct tm lt;
    struct passwd *pwd;
    struct group *gf;
    char buff[512];
    char timer[80];
