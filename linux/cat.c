#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int SIZE = 8192;
    int fd, n_chars;
    char buf[SIZE];

    if (argc != 2)
    {   
        fprintf(stderr, "用法: %s <文件名>\n", *argv);
        exit(1);
    }   

    if ((fd = open(argv[1], O_RDONLY)) == -1) 
    {   
        perror("Open error!");
        exit(1);
    }   

    while ((n_chars = read(fd, buf, SIZE)) > 0)
    {   
        if (write(STDOUT_FILENO, buf, n_chars) != n_chars)
        {   
            perror("Write error!");
            exit(1);
        }
    }   
    
    if (close(fd) == -1) 
        perror("Error closing files!");
    
    return 0;
}
