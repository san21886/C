#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void usage(char *);
char * find_repeating_sting(char *);

void main(int argc, char *argv[])
{
	if(argc==1)
	{
		usage(argv[0]);
		exit(1);
	}
	char *substr=find_repeating_sting(argv[1]);
	printf("substring: %s\n", substr);
}

void usage(char *script_name)
{
	fprintf(stderr, "usage:\n %s <input_string>\n", script_name);
}

char * find_repeating_sting(char *str)
{
	int str_len=strlen(str);
	int sub_str_size=1;
	int offset=1;
	if(str_len%2!=0)
		offset=2;
	int repeting_string_found=1;
	while(str_len/sub_str_size>1)
	{
		int start_index=0;
		repeting_string_found=1;
		while((start_index+(2*sub_str_size-1))<=str_len-1)
		{
			if(strncmp((str+start_index), str+start_index+sub_str_size,sub_str_size)!=0)	
			{
				repeting_string_found=0;
				break;
			}
			start_index++;
		}
		if(repeting_string_found)
			break;
		sub_str_size+=offset;
	}
	if(repeting_string_found)
	{
		char *substr=(char *) malloc(sizeof(char)*(sub_str_size+1));
		strncpy(substr,str,sub_str_size);
		return substr;
	}
	else
	{
		return NULL;
	}
}
