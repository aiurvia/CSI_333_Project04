/*	CSI 333. Programming at the Hardware-Software Interface
	Spring 2019
	Dr. Kuperman
	ZR1703
	2017215158
	Gao Chang
	& co-partner
	2017215156
	Zhang Wenhan
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
	char save[MAXLEN];
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
			char* data = strstr(line, ".data");
			int count = 0;

			if (data != NULL)
			{
				while (fgets(line, MAXLEN, finp) != NULL)
				{
					char* text = strstr(line, ".text");
					char* colon = strstr(line, ":");
					
					if (colon != NULL)
					{
						for (int i = 0; line[i] != ':'; i++)
						{
							save[count] = line[i];
							count++;
						}
						
						save[count] = '\n';
						count++;
					}
					
					if (text != NULL)
					{
						char* temp;
						save[count] = '\0';
						temp = strtok(save, "\n");

						while (temp!= NULL)
						{
							int point = ftell(finp);
							fputs("Variable ID --", foutp);
							fputs(temp, foutp);
							fputs("--\n", foutp);
							
							while (fgets(line, MAXLEN, finp) != NULL)
							{
								char* findV = strstr(line, temp);

								if (findV != NULL)
								{
									fputs(line, foutp);
								}
							}
							
							temp = strtok(NULL, "\n");
							fseek(finp, point, SEEK_SET);
						}
					}
				}
			}
			
			
		}

		if (arg_f == 0)
		{
			char* text = strstr(line, ".text");

			if (text != NULL)
			{
				while (fgets(line, MAXLEN, finp) != NULL)
				{
					char* colon = strstr(line, ":");
					char* beq = strstr(line, "beq");
					char* blt = strstr(line, "blt");
					char* ble = strstr(line, "ble");
					char* bgt = strstr(line, "bgt");
					char* bge = strstr(line, "bge");
					char* bne = strstr(line, "bne");
					char* jr = strstr(line, "jr");
					char* jal = strstr(line, "jal");
					
					if (colon != NULL)
					{
						fputs("Flow Control ID --", foutp);
						char temp[MAXLEN];
						
						for (int i = 0; line[i] != ':'; i++)
						{
							temp[i] = line[i];
							temp[i + 1] = '\0';
						}
						
						fputs(temp, foutp);
						fputs("--\n", foutp);
					}
					else if (beq != NULL)
					{
						fputs(line, foutp);
					}
					else if (blt != NULL)
					{
						fputs(line, foutp);
					}
					else if (ble != NULL)
					{
						fputs(line, foutp);
					}
					else if (bgt != NULL)
					{
						fputs(line, foutp);
					}
					else if (bge != NULL)
					{
						fputs(line, foutp);
					}
					else if (bne != NULL)
					{
						fputs(line, foutp);
					}
					else if (jr != NULL)
					{
						fputs(line, foutp);
					}
					else if (jal != NULL)
					{
						fputs(line, foutp);
					}
				}
			}
		}

		if (arg_b == 0)
		{
			int point1 = ftell(finp);
			char* data = strstr(line, ".data");
			int count = 0;

			if (data != NULL)
			{
				while (fgets(line, MAXLEN, finp) != NULL)
				{
					char* text = strstr(line, ".text");
					char* colon = strstr(line, ":");

					if (colon != NULL)
					{
						for (int i = 0; line[i] != ':'; i++)
						{
							save[count] = line[i];
							count++;
						}
						
						save[count] = '\n';
						count++;
					}

					if (text != NULL)
					{
						char* temp;
						save[count] = '\0';
						temp = strtok(save, "\n");

						while (temp != NULL)
						{
							int point2 = ftell(finp);
							fputs("Flow Control ID --", foutp);
							fputs(temp, foutp);
							fputs("--\n", foutp);

							while (fgets(line, MAXLEN, finp) != NULL)
							{
								char* findV = strstr(line, temp);

								if (findV != NULL)
								{
									fputs(line, foutp);
								}
							}

							temp = strtok(NULL, "\n");
							fseek(finp, point2, SEEK_SET);
						}
					}
				}
			}
			
			fseek(finp, point1, SEEK_SET);
			char* text = strstr(line, ".text");

			if (text != NULL)
			{
				while (fgets(line, MAXLEN, finp) != NULL)
				{
					char* colon = strstr(line, ":");
					char* beq = strstr(line, "beq");
					char* blt = strstr(line, "blt");
					char* ble = strstr(line, "ble");
					char* bgt = strstr(line, "bgt");
					char* bge = strstr(line, "bge");
					char* bne = strstr(line, "bne");
					char* jr = strstr(line, "jr");
					char* jal = strstr(line, "jal");

					if (colon != NULL)
					{
						fputs("Flow Control ID --", foutp);
						char temp[MAXLEN];
						
						for (int i = 0; line[i] != ':'; i++)
						{
							temp[i] = line[i];
							temp[i + 1] = '\0';
						}
						
						fputs(temp, foutp);
						fputs("--\n", foutp);
					}
					else if (beq != NULL)
					{
						fputs(line, foutp);
					}
					else if (blt != NULL)
					{
						fputs(line, foutp);
					}
					else if (ble != NULL)
					{
						fputs(line, foutp);
					}
					else if (bgt != NULL)
					{
						fputs(line, foutp);
					}
					else if (bge != NULL)
					{
						fputs(line, foutp);
					}
					else if (bne != NULL)
					{
						fputs(line, foutp);
					}
					else if (jr != NULL)
					{
						fputs(line, foutp);
					}
					else if (jal != NULL)
					{
						fputs(line, foutp);
					}
				}
			}
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