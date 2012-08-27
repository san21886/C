#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_braces_matching(char *input_str)
{
	char *prev_str=(char *) malloc(0);	
	char *temp_str=(char *) malloc(0);	
	int count=0;
	int return_val=1;
	int opening_brace_flag=0;
	while(input_str[count]!='\0')
	{
		if(input_str[count]=='(')
		{
			if(opening_brace_flag) //nesting '('
			{
				return_val= 0;
				break;
			}
			else
			{
				free(temp_str);
				temp_str=(char *) malloc(0);
				opening_brace_flag=1;
				//temp_strlen=0;
			}
		}
		else if(input_str[count]==')')
		{
			opening_brace_flag=0;
			if(strlen(prev_str)!=0 && strcmp(temp_str,prev_str)!=0)
			{
				return_val= 0;
				break;
			}
			free(prev_str);
			prev_str=(char *) malloc((strlen(temp_str)+1)*sizeof(char));
			strcpy(prev_str, temp_str);
		}
		else
		{
			if(opening_brace_flag)	
			{
				char *temp=(char *) malloc((strlen(temp_str)+2)*sizeof(char));
				char *temp2=(char *) malloc(2*sizeof(char));
				sprintf(temp2, "%c", input_str[count]);
				strcpy(temp,temp_str);
				strcat(temp, temp2);
				temp_str=temp;
				free(temp2);
			}
		}
		count++;
	}
	return return_val;
}
