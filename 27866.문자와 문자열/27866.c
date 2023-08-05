#include <stdio.h>

int main(int argc, char const *argv[])
{
	char str[1000]; int i;
	scanf("%s %d", str, &i);
	printf("%c\n", str[i-1]);
	return 0;
}