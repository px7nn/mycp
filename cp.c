#include <stdio.h>
#include <fcntl.h>

void HandleCP(int argc, char *args[]){
	int source_fd = open(args[1], O_RDONLY);
	if(source_fd == -1){
		printf("%s: cannot stat '%s': No such file or directory\n", args[0], args[1]);
		return;
	}
	int target_fd = open(args[argc -1], O_CREAT, 0644);
	printf("T_FD: %d", target_fd);
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

