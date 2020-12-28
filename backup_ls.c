#include "backup_ls.h"
int main(int argc, char **argv)
{

	if(argv[1]==NULL){
	  printf("few argumenrs");
	  return 0;
	}
		else{	
    	   dir = opendir(argv[1]);
    	while ((file = readdir(dir)) != NULL){
			  stat(file->d_name, &info);  
        if ( (stat(file->d_name, &info) ) == 0 )    {
        pwd = getpwuid(info.st_uid);
		gf = getgrgid(info.st_gid);

    }
			sprintf(buff,"%s/%s", argv[1],file->d_name);
			stat(buff, &info);
			time_t t = info.st_mtime;
            localtime_r(&t, &lt);
			strftime(timer, sizeof(timer), "%c", &lt);
			if((info.st_mode & S_IFMT)== S_IFDIR) {
               printf("d");
           		}
				else{
                   printf("-");
                }
			printf( (info.st_mode & S_IRUSR) ? "r" : "-");
       	    printf( (info.st_mode & S_IWUSR) ? "w" : "-");
        	printf( (info.st_mode & S_IXUSR) ? "x" : "-");
        	printf( (info.st_mode & S_IRGRP) ? "r" : "-");
        	printf( (info.st_mode & S_IWGRP) ? "w" : "-");
        	printf( (info.st_mode & S_IXGRP) ? "x" : "-");
        	printf( (info.st_mode & S_IROTH) ? "r" : "-");
        	printf( (info.st_mode & S_IWOTH) ? "w" : "-");
        	printf( (info.st_mode & S_IXOTH) ? "x" : "-");
			printf(" ");
			printf("%ld  %s %s %ld %s %s\n",info.st_nlink, pwd->pw_name, gf->gr_name,
			info.st_size, timer, file->d_name);
			
			}
    		closedir(dir);
	}
	return 0;
}
