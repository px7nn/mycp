#include <stdio.h>

void HandleCP(int argc, char *args[]){
	printf("Source:\t");
	for(int i=1; i<argc - 1; i++)
		printf("\t%s", args[i]);
	printf("\nDesitination:\t%s\n", args[argc-1]);
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

