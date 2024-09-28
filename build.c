#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SRC_PATH "src/"
#define BUILD_PATH "target/"

int main(int argc, char **argv)
{
	char *build_cmd = strcmp(argv[1], "debug") == 0
		? "clang -g "SRC_PATH"main.c -o "BUILD_PATH"main"
		: "clang "SRC_PATH"main.c -o "BUILD_PATH"main";
	printf("[INFO]: %s\n", build_cmd);
	system(build_cmd);
	return 0;
}
