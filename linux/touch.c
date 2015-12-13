#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <utime.h>
 
int main(int argc, char *argv[])
{
    struct stat buf;
    int fd = 0;
	time_t nowTime;
	//utime更改时间的时候需要这个
	struct utimbuf timeBuf;
 
    if (argc != 2)
    {   
        fprintf(stderr, "用法: %s <文件名>\n", *argv);
        exit(1);
    }
 
    //文件不存在，就创建一个文件
    if (lstat(argv[1],&buf) == -1) {
        fd = open(argv[1],O_WRONLY|O_CREAT,0644);
        close(fd);
        exit(0);
    }
 
	//获取当前时间
    nowTime = time(NULL);
	//修改修改时间
	timeBuf.modtime = nowTime;
	//修改这个文件的修改时间
	utime(argv[1],&timeBuf);
     
    return 0;
}