#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define Length 1024
int main(){
	int fdw, fdr, len;
	char str[Length];
	char sourcename[15], targetname[20];
	printf("Please input the name of the source file");
	scanf("%s", &sourcename);
	printf("Please input the name of the target file.");
	scanf("%s", &targetname);
	fdr = open(sourcename, O_RDONLY);
	if(fdr)
		len=read(fdr, str, Length);
	else{
		printf("read file error.");
		exit(0);
	}
	fdw = open(targetname, O_CREAT|O_RDWR);
	write(fdw, str, len);
	close(fdr);
	close(fdw);
}