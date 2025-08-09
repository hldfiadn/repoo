// system.c
#include<stdio.h>
#include<stdlib.h>

int main()
{
puts("Running command");
system("ps --forest");
puts("Done");
return 0;
}