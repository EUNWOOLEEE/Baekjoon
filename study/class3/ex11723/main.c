#include <stdio.h>
#include <string.h>

int s[20] = {0,};

int is_zero()
{
	for(int i = 0; i < 20; i++)
	{
		if(!s[i])
			return i;
	}
	return -1;
}

int is_x(int x)
{
	for(int i = 0; i < 20; i++)
	{
		if(s[i] == x)
			return i;
	}
	return -1;
}

int check(int x)
{
	for(int i = 0; i < 20; i++)
		if(s[i] == x)
			return 1;
	return 0;
}

void add(int x)
{
	int pos;

	if(!check(x))
	{
		pos = is_zero();
		s[pos] = x;
	}
}

void remove_x(int x)
{
	int pos;

	if(check(x))
	{
		pos = is_x(x);
		s[pos] = 0;
	}
}

void toggle(int x)
{
	if(check(x))
		remove_x(x);
	else
		add(x);
}

void all()
{
	int num = 1;
	for(int i = 0; i < 20; i++)
		s[i] = num++;
}

void empty()
{
	for(int i = 0; i < 20; i++)
		s[i] = 0;
}

int main()
{
	int m;
	scanf("%d", &m);

	char cmd[7] = {0,};
	int x;
	for(int i = 0; i < m; i++)
	{
		scanf("%s %d", cmd, &x);

		if(!strcmp(cmd, "add"))
			add(x);
		else if(!strcmp(cmd, "remove"))
			remove_x(x);
		else if(!strcmp(cmd, "check"))
			printf("%d\n", check(x));
		else if(!strcmp(cmd, "toggle"))
			toggle(x);
		else if(!strcmp(cmd, "all"))
			all();
		else if(!strcmp(cmd, "empty"))
			empty();
	}
}