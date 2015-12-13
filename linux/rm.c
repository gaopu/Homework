#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct stat buf;
	int i;

	if (argc < 2) {
		printf("%s: 缺少操作数\n",argv[0]);
		printf("用法: %s [文件名]\n",argv[0]);
		exit(0);
	}

	for (i = 1;i < argc;i++) {
		//文件不存在，提示不存在
	    if (lstat(argv[i],&buf) == -1) {
	        printf("%s: 无法删除\"%s\": 没有那个文件或目录\n",argv[0],argv[1]);
	        continue;
	    }

	    printf("%s：是否删除普通文件 \"%s\"？", argv[0],argv[i]);
	    char c = getchar();
	    getchar();
	    if (c == 'y' || c == 'Y') {
	    	remove(argv[i]);
	    }
	}

	return 0;
}