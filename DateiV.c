#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	FILE *err;

	if (argc != 2) {
		fprintf(stderr, "usage: %s filename\n", argv[0]);
		return 2;
	}

	err = fopen_s(&err, "C:/File.txt", "w");
	if (!err) {
		fprintf_s(stderr, "opening %s: %s\n", argv[1], strerror_s(errno)); // HERE
		return 1;
	}

	// use 'fp' here...

	return 0;
}