/*	CSI 333. Programming at the Hardware-Software Interface
	Spring 2019
	Dr. Kuperman
	ZR1703
	2017215158
	Gao Chang
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum line length. */
#define MAXLEN 80
/* Symbolic constants associated with command line parameters.*/
#define NUMARG 4
#define FLAG_ARG 1
#define IN_FILE_ARG 2
#define OUT_FILE_ARG 3

int main(int argc, char* argv[])
{
	char line[MAXLEN];
	FILE* finp, * foutp;
	int arg_v = strcmp(argv[FLAG_ARG], "-v");
	int arg_f = strcmp(argv[FLAG_ARG], "-f");
	int arg_b = strcmp(argv[FLAG_ARG], "-b");

	if (argc != NUMARG)
	{
		printf("Usage: CSI_333_Project04 flag infile outfile \n");
		fflush(stdout);
		exit(1);
	}

	if (arg_v * arg_f * arg_b != 0)
	{
		printf("Usage: -v -f -b");
		fflush(stdout);
		exit(1);
	}

	if ((finp = fopen(argv[IN_FILE_ARG], "r")) == NULL)
	{
		printf("Could not open file %s for reading.\n", argv[IN_FILE_ARG]);
		fflush(stdout);
		exit(1);
	}

	if ((foutp = fopen(argv[OUT_FILE_ARG], "w")) == NULL)
	{
		printf("Could not open file %s for writing.\n", argv[OUT_FILE_ARG]);
		fflush(stdout);
		exit(1);
	}

	while (fgets(line, MAXLEN, finp) != NULL)
	{
		if (arg_v == 0)
		{
			printf("V");
		}

		if (arg_f == 0)
		{
			printf("F");
		}

		if (arg_b == 0)
		{
			printf("B");
		}
	}
	
	if (fclose(finp) == EOF) {
		printf("Error in closing input file.\n");
		fflush(stdout);
	}

	if (fclose(foutp) == EOF) {
		printf("Error in closing output file.\n");
		fflush(stdout);
	}

	printf("Finished.\n");
	fflush(stdout);

	return 0;
}