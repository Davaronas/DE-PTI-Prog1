#include <stdio.h>

int main()
{
	int i = 10000;
	while(1)
	{
		i += i;
		sleep(i);
	}

}

