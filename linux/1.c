//父进程读取子进程写在文件中的信息
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
    int SIZE = 8192;
    int fd, n_chars;
    char buf[SIZE];   
 
    
     
    int pid =  fork();
    if (pid) {
        while (1) {
            sleep(3);
            if ((fd = open("/tmp/temp1", O_RDONLY|O_CREAT,0644)) == -1) {   
                perror("Open error!");
                exit(1);
            }
            
            n_chars = read(fd, buf, SIZE);
            
            if (n_chars > 0) {
                printf("父进程读到数据啦：%s\n",buf,strlen(buf));
            } else {
                printf("父进程没有读到数据!\n");
            }
            close(fd);
        }
    } else {
        int i = 0;        
        while (1) {
            if ((fd = open("/tmp/temp1", O_WRONLY|O_APPEND|O_CREAT,0644)) == -1) {   
                perror("Open error!");
                exit(1);
            }
            
            if (write(fd, "t", 1 )!= 1) {
                perror("Write error!");
                exit(1);
            }
            
            close(fd);
            sleep(1);
        }
    }
     
    return 0;
}
