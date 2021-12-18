/*
 ============================================================================
 Name        : LongesPassword.c
 Author      : Hakan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
it has to contain only alphanumerical characters (a−z, A−Z, 0−9);
there should be an even number of letters; **çift
there should be an odd number of digits. --tek

Example:"test 5 a0A pass007 ?xy1"
bunlar arasında geçerli olanlar 5, a0A, pass007 : En uzun olan pass007 sayısnı yani 7 karakter oldugu icin 7 doner
Hiç yoksa  -1 donmeli
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int returnPassword(char *S);

char sS[]="W i k ? 5 + a";
int main(void) {

	char * S=sS;
	int longestPassword=0;

	//	return result;
	longestPassword = returnPassword(S);

	printf("Hello");
	printf("Longest Password Size : %d\n\r",longestPassword);

	return EXIT_SUCCESS;
}

int returnPassword(char *S)
{
	int digit=0;
	int letter=0;
	int invalidRange=0;
	int alpha_numerical,check =0;
	int result=-1;
	int i=0,cnt;

	while(*S != '\0') //String sonu
	{
		while( (*S != ' ') && ( *S !='\0')) //kelime
		{

			if(isalnum(*S)) //aralık dogru mu
			{
				if(isdigit(*S) )//number of digit character
				{
					digit +=1;
				}
				if(isalpha(*S))
				{
					letter+=1;//number of letter chracter
				}

				i++;
				S++;
			}
			else if(isalnum(*S) == 0 )
			{
				invalidRange++;
				S++;

			}

		}

		if(( digit %2 != 0) && (letter % 2 == 0) && (invalidRange == 0))
		{
			if(result < i)
				result=i;
		}

		i=0;
		invalidRange=0;
		digit =0;
		letter=0;
		S++;

	}

	return result;

}
