#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 128

void HandleCP(int argc, char *args[]){
	int source_fd = open(args[1], O_RDONLY);
	if(source_fd < 0){
		printf("%s: cannot stat '%s': No such file or directory\n", args[0], args[1]);
		return;
	}
	int target_fd = open(args[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(target_fd < 0){
		printf("Destination error", args[0]);
		return;
	}
	char buffer[BUFFER_SIZE];
	size_t b_read;
	while((b_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
		write(target_fd, buffer, b_read);

	close(source_fd);
	close(target_fd);
}

int main(int argc, char *args[]){
	if(argc == 1){
		printf("%s: missing file operand\n", args[0]);
		return 1;
	} if(argc == 2){
		printf("%s: missing destination file operand after '%s'\n", args[0], args[1]);
		return 1;
	}

	if(argc >= 3){
		HandleCP(argc, args);
	}

	return 0;
}

