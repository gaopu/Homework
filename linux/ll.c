#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>

void display_single(const char *filename);

int main(int argc, char *argv[])
{
	//要显示的目录
	char path[255];
	struct dirent *pdir;
	struct stat buf;
	DIR *dir;

	//不支持指定多个目录
	if (argc == 1)
    {   
        strcpy(path,".");
    } else if (argc == 2) {
    	strcpy(path,argv[1]);
    } else {
    	printf("暂时只支持指定一个目录.\n");
    	exit(0);
    }

    //目录不存在就提示并退出
    if (lstat(path,&buf) == -1) {
		printf("\"%s\"目录不存在\n",path);
		exit(0);
	}

	//打开参数的目录
	if ((dir = opendir(path)) == NULL) {
		printf("打开\"%s\"目录错误\n",path);
		exit(0);
	}

	//循环打印每个文件的具体信息
	while ((pdir = readdir(dir)) != NULL) {
		char true_path[255] = "";
		strcat(true_path,path);

		//目录的最后没有"/"就加上"/"
		if (true_path[strlen(true_path) - 1] != '/') {
			strcat(true_path,"/");
		}

		strcat(true_path,pdir->d_name);
		display_single(true_path);
	}

	return 0;
}

void display_single(const char *filename)
{
	struct stat buf;
	struct passwd *psd;
	struct group *grp;
	char mtime[30];

	if (lstat(filename,&buf) == -1) {
		printf("%s不存在\n", filename);
		exit(0);
	}

	//显示文件类型
	if (S_ISDIR(buf.st_mode)) {
		printf("d");
	} else if (S_ISLNK(buf.st_mode)) {
		printf("l");
	} else if (S_ISSOCK(buf.st_mode)) {
		printf("s");
	} else if (S_ISFIFO(buf.st_mode)) {
		printf("p");
	} else if (S_ISREG(buf.st_mode)) {
		printf("-");
	} else if (S_ISCHR(buf.st_mode)) {
		printf("c");
	} else if (S_ISBLK(buf.st_mode)) {
		printf("b");
	}
	
	//所有者权限
	if (S_IRUSR & buf.st_mode) {
		printf("r");
	} else {
		printf("-");
	}
	if (S_IWUSR & buf.st_mode) {
		printf("w");
	} else {
		printf("-");
	}
	if (S_IXUSR & buf.st_mode) {
		printf("x");
	} else {
		printf("-");
	}

	//同组用户权限
	if (S_IRGRP & buf.st_mode) {
		printf("r");
	} else {
		printf("-");
	}
	if (S_IWGRP & buf.st_mode) {
		printf("w");
	} else {
		printf("-");
	}
	if (S_IXGRP & buf.st_mode) {
		printf("x");
	} else {
		printf("-");
	}

	//其他用户权限
	if (S_IROTH & buf.st_mode) {
		printf("r");
	} else {
		printf("-");
	}
	if (S_IWOTH & buf.st_mode) {
		printf("w");
	} else {
		printf("-");
	}
	if (S_IXOTH & buf.st_mode) {
		printf("x");
	} else {
		printf("-");
	}

	//链接数
	printf("%3d",buf.st_nlink);
	psd = getpwuid(buf.st_uid);
	grp = getgrgid(buf.st_gid);
	//用户名
	printf("%10s",psd->pw_name);
	printf(" ");
	//用户组名
	printf("%10s",grp->gr_name);
	printf(" ");

	//文件大小
	printf("%8d",buf.st_size);
	printf(" ");

	strcpy(mtime,ctime(&buf.st_mtime));
	mtime[strlen(mtime) - 1] = 0;

	//文件最后被修改的时间
	printf("%s",mtime);
	printf(" ");

	//文件名
	printf("%s\n",filename);
}