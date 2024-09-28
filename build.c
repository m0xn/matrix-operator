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
		int status = system("mkdir "BUILD_PATH" 2>/dev/null");
		if (status != 0) {
			// NOTE: This fucking mess is because of Termux terminal in
			// Android, which uses an 'mkdir' binary that requieres root
			// access to the phone that I don't have. Therefore, I must
			// invoke a normal sh shell to execute the mkdir, build and
			// a final echo command to inform the user that the main
			// program was built. Thank you Termux, pretty cool.
			printf("[INFO]: Failed to create "BUILD_PATH" dir, trying another method...\n");
			char *compund_cmd = (char*)malloc(1024);
			strcat(compund_cmd, "mkdir "BUILD_PATH);
			strcat(compund_cmd, "&& ");
			strcat(compund_cmd, build_cmd);
			strcat(compund_cmd, " && ");
			strcat(compund_cmd, "echo [INFO]: ");
			strcat(compund_cmd, build_cmd);
			execl("/bin/sh", "sh", "-c", compund_cmd, (char*)NULL);
			free(compund_cmd);
		}
	}

	printf("[INFO]: %s\n", build_cmd);
	system(build_cmd);
	return 0;
}
