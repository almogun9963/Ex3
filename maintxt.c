#include <stdio.h>
#include "txtfind.h"
#include "txtfind.c"

int main()
{

	char text;
	int i = 0;
	char word [WORD];
	char c;
	while ((text = getc( stdin )) != ' ')
	{
		word[i] = text;
		i = i + 1;
	}
	
	word[i] = '\0';
	while ((text = getc(stdin)) != '\n'){
		if (text == 'a')
			c = 'a';
		else if (text == 'b')
			c = 'b';
	}



	if(c == 'a')
	{
		print_lines (word);	
	}
	else if(c == 'b')
	{
		print_similar_words (word);
	}
	else{
		printf ("Incorrect input \n");
	}
	
	return 0;
}