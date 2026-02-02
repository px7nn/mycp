#include <stdio.h>

int main(int argc, char *args[]){
	if(argc == 2){
		printf("%s: missing destination file operand after '%s'\n", args[0], args[1]);
		return 1;
	}

	return 0;
}

