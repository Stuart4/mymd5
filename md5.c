#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * expand(char * message) {
	int messageSize = strlen(message);
	int newSize = 448 - messageSize % 512 + messageSize + 4;
	char * new = realloc(message, newSize);
	if (messageSize < newSize - 5) {
		new[messageSize++] = 0x80;
	}
	while (messageSize < newSize - 4) {
		new[messageSize++] = 0x00;
	}
	//TODO end 64bit num representing original string
	return new;
}

int main(int argc, char ** argv) {
	if (argc != 2) {
		printf("usage ./md5 \"message\"\n");
		exit(1);
	}

	char * new = expand(strdup(argv[1]));

	return 0;

}
