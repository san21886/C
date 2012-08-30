#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * If an array is having integers/Char/special Char... Ex: "PST456DA85M2A!!23++46", find out the sum of integers. ****Note: If we find consecutive digits in array we need to treat it as number, let say 456, we need to treat it as [ four hundread and fifty six]. Write a program to get the output by summing 456+85+2+23+46..also this needs to be done in lessnumber of iterations..
 */

int get_sum_of_integers_in_array(char *);
void main(int argc, char *argv[])
{
	int sum=get_sum_of_integers_in_array(argv[1]);
	printf("%d\n", sum);
}

int get_sum_of_integers_in_array(char *arr)
{
	int str_len=strlen(arr);
	int count;
	char *num_str=(char *) malloc(1);
	num_str[0]='\0';
	int sum=0;
	for(count=0;count<=str_len-1;count++)
	{
		if(arr[count] >=48 && arr[count]<=57 && strlen(num_str)==0)
		{
			num_str=(char *) malloc(sizeof(char)*2);
			sprintf(num_str, "%c", arr[count]);
		}
		else if(arr[count] >=48 && arr[count]<=57)
		{
			int len=strlen(num_str);
			char *temp=(char *) malloc(sizeof(char)*(len+2));
			char *temp2=(char *) malloc(sizeof(char)*(2));
			sprintf(temp2, "%c", arr[count]);
			strcpy(temp, num_str);
			strcat(temp,temp2);
			num_str=temp;
			free(temp2);
		}
		else if(strlen(num_str)!=0)
		{
			int temp=atoi(num_str);	
			sum+=temp;
			free(num_str);
			char *num_str=(char *) malloc(1);
			num_str[0]='\0';
		}
	}
	return sum;
}
