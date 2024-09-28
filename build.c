#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>

#define SRC_PATH "src"
#define BUILD_PATH "target"

int main(int argc, char **argv)
{
	bool debug = argv[1] != NULL && strcmp(argv[1], "debug") == 0;
	char *build_cmd = debug 
		? "clang -g "SRC_PATH"/main.c -o "BUILD_PATH"/main"
		: "clang "SRC_PATH"/main.c -o "BUILD_PATH"/main";

	DIR *target_dir = opendir(BUILD_PATH);
	if (!target_dir) {
		printf("[INFO]: "BUILD_PATH" dir not found, making dir...\n");
		int status = system("mkdir "BUILD_PATH);
		if (status != 0) {
			printf("[INFO]: Failed to create "BUILD_PATH" dir, trying another method...");
			char *compund_cmd = "mkdir "BUILD_PATH;
			strcat(compund_cmd, "&& ");
			strcat(compund_cmd, build_cmd);
			execl("/bin/sh", "sh", "-c", compund_cmd, (char*)NULL);
		}
	}

	printf("[INFO]: %s\n", build_cmd);
	system(build_cmd);
	return 0;
}
