#include <stdio.h>
#include <unistd.h>
#include "txtfind.h"
#include <stdlib.h>
#include <string.h>


int getLine (char s[])
{
	char temp = getc (stdin);
	int i = 0;
	while ( temp != '\n' && temp != EOF && i < LINE )
	{
		s[i] = temp;
		temp = getc (stdin);
		i = i + 1;
	}
	s[i] = temp;
	return i;
}

int getword (char w[])
{
	char temp = getc(stdin);
	int i = 0;
	while ( temp != '\n' && temp != '\t' && temp != ' ' && temp != EOF && i < WORD )
	{
		w[i] = temp;
		temp = getc (stdin);
		i = i + 1;
	}
	w[i] = '\0';
	return i;
}

int substring (char* str1 , char* str2)
{
	int wlen;
	int i = 0;
	int j = 0;
	while (*(str1 + i) != '\0')
	{
		i = i + 1;
	}
	wlen = i;
	i = 0;
	while (*(str1 + i) != '\0' && *(str2 + j) != '\0')
	{
		if (*(str1 + i) == *(str2 + j))
		{
			i = i + 1;
		}
		else
		{
			i = 0;
		}
		if (i == wlen)
		{
			return 1;
		}
		j = j + 1;
	}
	return 0;
}

int get_length (char* s)
{
	int len = 0;
	while (*(s + len) != '\0')
	{
		len = len + 1;
	}
	return len;
}

int similar (char* s , char* t , int n)
{
	int slen = get_length (s);
	int tlen = get_length (t);
	int sindex = 0;
	int tindex = 0;
	
	if (tlen-slen>n)
	{
		return 0;
	}
	else
	{
		while (*(t + tindex) != '\0')
		{
		if (*(t + tindex)) == (*(s + sindex) )
		{
			sindex = sindex + 1;
		}
		if ((*(s + sindex) == '\0'))
		{
			return 1;
		}
		if (tindex > sindex + n)
		{
			return 0;
		}
		tindex = tindex + 1;
		}
	
	}
	
	return 0;
}

void print_lines (char* str)
{
	int n = 1;
	while (n)
	{
		char row [LINE] = {'\0'};
	        n = getLine (row);
		for (int i = 0; i <= LINE - 1 ;i++)
		{
			char printLines [WORD] = {'\0'};
			int j = 0;
			while (row[i] !=  '\n' && row[i] != ' ' && row[i] != '\t' && j < WORD )
			{
				printLines[j] = row[i];
				j = j + 1;
				i = i + 1;
			}
			printLines[j] = '\0';
			if (substring (str , printLines))
			{
				printf ("%s" , row);
				break;
			}
		}
	}
}

void print_similar_words (char* str)
{
	int n = 1;
	while (n)
	{
		char similarWord[WORD] = {'\0'};
		n = getword (similarWord);
		if (similar (str , similarWord , 0) || similar (str , similarWord , 1))
		{
			printf ("%s \n" , similarWord);
		}
	}
}
