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
#define MAXLEN 81
/* Symbolic constants associated with command line parameters.*/
#define NUMARG 4
#define FLAG_ARG 1
#define IN_FILE_ARG 2
#define OUT_FILE_ARG 3

int main(int argc, char* argv[])
{
	char line[MAXLEN];		/* To hold each line of the input file. */
	FILE* finp, * foutp;	/* Pointers for input and output files. */

	if (argc != NUMARG)
	{
		printf("Usage: CSI_333_Project04 flag infile outfile \n");
		fflush(stdout);
		exit(1);
	}

	if (argv[FLAG_ARG] != "-f" || "-v" || "-b")
	{
		printf("Usage: CSI_333_Project04 flag infile outfile \n");
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
		printf("");
	}

}