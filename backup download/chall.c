#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// gcc chall.c -o chall
void setup()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}


int main(int argc, char **argv)
{
	char buffer[128];
	int b = 5;

	setup();

	printf("Say Something To Me!\n> ");
	gets(buffer);

	if(strlen(buffer) > 32)
	{
		printf("HAHA, no more bufferoverflow okay\n");
		exit(0);
	}
	else if(b != 5)
	{
		system("cat flag.txt");
	}
	else
	{
		printf("Okay Thankyou!\n");
	}
	
	return 0;
}