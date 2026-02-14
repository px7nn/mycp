#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int buffer_size = 128;

int main(int argc, char *args[]){
	if(argc != 3){
		printf("Usage: %s <source> <destination>", args[0]);
		return 1;
	}
	
	int fd_src = open(args[1], O_RDONLY);
	if(fd_src < 0){
		perror("Error reading source");
		return 1;
	}

	int fd_dst = open(args[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd_dst < 0){
		perror("Error reading source");
		close(fd_src);
		return 1;
	}

	char buffer[buffer_size];
	ssize_t bytesRead;
	while((bytesRead = read(fd_src, buffer, buffer_size)) > 0)
		write(fd_dst, buffer, bytesRead);

	if(bytesRead < 0){
		perror("Error reading");
	}

	close(fd_src);
	close(fd_dst);
	return 0;
}

