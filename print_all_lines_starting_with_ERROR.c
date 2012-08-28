#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void extract_all_lines_starting_with_ERROR(char *);
void main(int argc, char *argv[])
{
	if(argc==1)
	{
		fprintf(stderr, "please provide file name as CLA\n");
		exit(1);
	}
	extract_all_lines_starting_with_ERROR(argv[1]);
}

void extract_all_lines_starting_with_ERROR(char *filename)
{
	FILE *file=fopen(filename, "r");
	if(file==NULL)
	{
		fprintf(stderr, "file:%s doesn't exist\n", filename);
		exit(1);
	}
	char c;
	int line_begin=1;
	int print_line=0;
	while((c=fgetc(file))!=EOF)
	{
		if(line_begin)
		{
			if(c=='\n') //empty line
				continue;

			char word[6]={'\0'};
			word[0]=c;
			int count=1;
			while(count<5 && (c=fgetc(file))!=EOF && c!='\n')
			{
				word[count]=c;
				count++;
			}
			if(strcmp(word, "ERROR")==0)
			{
				print_line=1;
				printf("%s", word);
			}
			else
				print_line=0;
			if(c!='\n')
				line_begin=0;
			continue;
		}
		else if(c=='\n')
			line_begin=1;

		if(print_line)
			printf("%c", c);
	}
}
