#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void newgame(int * f);
char chose(void);
int up(int * f);
int down(int * f);
int left(int * f);
int right(int * f);
int ifwin(int * f);
int islose(int * f);
void add(int *  f);

int main(void)
{
	int data[4][4] =
	{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}

	};
	int flag = 0;
	int movesucc = 0;

	newgame(data[0]);
	
	while(1)
	{
		system("clear");
		puts("Now It's\n");
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
				printf("%5d", data[i][j]);
			putchar('\n');
		}
		while(1)
		{
			puts("\nDo you want them up(u), down(d), left(l) or right(r)?");

			switch(chose())
			{
				case 'u':
					movesucc = up(data[0]);
					break;
				case 'd':
					movesucc = down(data[0]);
					break;
				case 'l':
					movesucc = left(data[0]);
					break;
				case 'r':
					movesucc = right(data[0]);
					break;
			}

			if(movesucc == 1)
			{
				movesucc = 0;
				break;
			}
			else
				continue;
		}
		if(flag != 1)
			flag = ifwin(data[0]);
		if(flag == 0)
		{
			puts("You Win.");
			return 0;
		}

		add(data[0]);
		
		if(islose(data[0]) == 1)
		{
			puts("You lost.");
			return 0;
		}
	}
}

void newgame(int * f)
{
	int p[2] = {0,0}, d[2] = {0,0};
	unsigned int t = (unsigned)time(NULL);
	while(p[0] == p[1])
	{
		for(int i = 0; i < 2; i++)
		{
			srand(t);
			p[i] = rand() % 16;
			t++;
	
			srand(t);
			d[i] = ((rand() % 2) + 1) * 2;
			t++;
		}
	}

	*(f + p[0]) = d[0];
	*(f + p[1]) = d[1];
	
	return;
}

char chose(void)
{
	char c;

	puts("Input your chose:");

	while(1)
	{
		if(1 != scanf("%c",&c))
		{	
			puts("Please input u, d, l or r");
			while(getchar() != '\n')
				continue;
			continue;
		}

		switch(c)
		{
			case 'u':
			case 'd':
			case 'l':
			case 'r':
				while(getchar() != '\n')
					continue;
				return c;
			default:
				puts("Please input u, d, l or r");
				while(getchar() != '\n')
					continue;
		}	
	}
}

int up(int * f)
{
	int x, a = 0;

	for(int i = 0; i < 4; i++)
	{
		if(*(f + i) == 0)
			if( (*(f + 4 + i) != 0) || (*(f + 8 + i) != 0) || (*(f + 12 + i) != 0))
				a = 1;
		if(*(f + 4 + i) == 0)
			if( (*(f + 8 + i) != 0) || (*(f + 12 + i) != 0))
				a = 1;
		if(*(f + 8 + i) == 0)
			if( (*(f + 12 + i) != 0))
				a = 1;
		if( ((*(f + i)) == (*(f + 4 + i))) && ((*(f + i) != 0)))
			a = 1;
		if( ((*(f + 4 + i)) == (*(f + 8 + i))) && ((*(f + 4 + i)) != 0))
			a = 1;
		if( ((*(f + 8 + i)) == (*(f + 12 + i))) && ((*(f + 8 + i) != 0)))
			a = 1;
	}


	for(x = 0; x < 4; x++)
	{
		for(int i = 0; i < 3; i++)
		{
			if(*(f + x) == 0)
		 	{
				*(f + x) = *(f + 4 + x);
				*(f + 4 + x) = *(f + 8 + x);
				*(f + 8 + x) = *(f + 12 + x);
				*(f + 12 + x) = 0;
		 	}
	
			 if(*(f + 4 + x) == 0)
			 {
				*(f + 4 + x) = *(f + 8 + x);
				*(f + 8 + x) = *(f + 12 + x);
				*(f + 12 + x) = 0;
			 }
	
			 if(*(f + 8 + x) == 0)
			 {
				*(f + 8 + x) = *(f + 12 + x);
				*(f + 12 + x) = 0;
			 }
		}
	}

	for(x = 0; x < 4; x++)
	{
		if(*(f + x) == *(f + 4 + x))
		{
			*(f + x) += *(f + 4 + x);
			*(f + 4 + x) = *(f + 8 + x);
			*(f + 8 + x) = *(f + 12 + x);
			*(f + 12 + x) = 0;
		}

		if(*(f + 4 + x) == *(f + 8 + x))
		{
			*(f + 4 + x) += *(f + 8 + x);
			*(f + 8 + x) = *(f + 12 + x);
			*(f + 12 + x) = 0;
		}

		if(*(f + 8 + x) == *(f + 12 + x))
		{
			*(f + 8 + x) += *(f + 12 + x);
			*(f + 12 + x) = 0;
		}
		for(int i = 0; i < 2; i++)
		{
			 if(*(f + x) == 0)
			 {
				*(f + x) = *(f + 4 + x);
				*(f + 4 + x) = *(f + 8 + x);
				*(f + 8 + x) = *(f + 12 + x);
				*(f + 12 + x) = 0;
			 }
	
			 if(*(f + 4 + x) == 0)
			 {
				*(f + 4 + x) = *(f + 8 + x);
				*(f + 8 + x) = *(f + 12 + x);
				*(f + 12 + x) = 0;
			 }
	
			 if(*(f + 8 + x) == 0)
			 {
				*(f + 8 + x) = *(f + 12 + x);
				*(f + 12 + x) = 0;
			}
		}
	}
	return a;
}

int down(int * f)
{
	int x, a = 0;

	for(int i = 0; i < 4; i++)
	{
		if(*(f + 12 + i) == 0)
			if( (*(f + 8 + i) != 0) || (*(f + 4 + i) != 0) || (*(f + i) != 0))
				a = 1;
		if(*(f + 8 + i) == 0)
			if( (*(f + 4 + i) != 0) || (*(f + i) != 0))
				a = 1;
		if(*(f + 4 + i) == 0)
			if( (*(f + i) != 0))
				a = 1;
		if( ((*(f + 12 + i)) == (*(f + 8 + i))) && ((*(f + 12 + i) != 0)))
			a = 1;
		if( ((*(f + 8 + i)) == (*(f + 4 + i))) && ((*(f + 8 + i) != 0)))
			a = 1;
		if( ((*(f + 4 + i)) == (*(f + i))) && ((*(f + 4 + i) != 0)))
			a = 1;
	}

	for(x = 0; x < 4; x++)
	{
		for(int i = 0; i < 3; i++)
		{
	   		if(*(f + 12 + x) == 0)
			 {
				*(f + 12 + x) = *(f + 8 + x);
				*(f + 8 + x) = *(f + 4 + x);
				*(f + 4 + x) = *(f + x);
				*(f + x) = 0;
			 }
	
			 if(*(f + 8 + x) == 0)
			 {
				*(f + 8 + x) = *(f + 4 + x);
				*(f + 4 + x) = *(f + x);
				*(f + x) = 0;
			 }
	
			 if(*(f + 4 + x) == 0)
			 {
				*(f + 4 + x) = *(f + x);
				*(f + x) = 0;
			 }
		}	
	}

	for(x = 0; x < 4; x++)
	{
		if(*(f + 12 + x) == *(f + 8 + x))
		{
			*(f + 12 + x) += *(f + 8 + x);
			*(f + 8 + x) = *(f + 4 + x);
			*(f + 4 + x) = *(f + x);
			*(f + x) = 0;
		}

		if(*(f + 8 + x) == *(f + 4 + x))
		{
			*(f + 8 + x) += *(f + 4 + x);
			*(f + 4 + x) = *(f + x);
			*(f + x) = 0;
		}

		if(*(f + 4 + x) == *(f + x))
		{
			*(f + 4 + x) += *(f + x);
			*(f + x) = 0;
		}
		
		for(int i = 0; i < 2; i++)
		{
			 if(*(f + 12 + x) == 0)
			 {
				*(f + 12 + x) = *(f + 8 + x);
				*(f + 8 + x) = *(f + 4 + x);
				*(f + 4 + x) = *(f + x);
				*(f + x) = 0;
			 }
	
			 if(*(f + 8 + x) == 0)
			 {
				*(f + 8 + x) = *(f + 4 + x);
				*(f + 4 + x) = *(f + x);
				*(f + x) = 0;
			 }
	
			 if(*(f + 4 + x) == 0)
			 {
				*(f + 4 + x) = *(f + x);
				*(f + x) = 0;
			 }
		}
	}
	return a;
}

int left(int * f)
{
	int y, a = 0;

	for(int i = 0; i < 4; i++)
	{
		if(*(f + 4 * i) == 0)
			if( (*(f + 1 + 4 * i) != 0) || (*(f + 2 + 4 * i) != 0) || (*(f + 3 + 4 * i) != 0))
				a = 1;
		if(*(f + 1 + 4 * i) == 0)
			if( (*(f + 2 + 4 * i) != 0) || (*(f + 3 + 4 * i) != 0))
				a = 1;
		if(*(f + 2 + 4 * i) == 0)
			if( (*(f + 3 + 4 * i) != 0))
				a = 1;
		if( ((*(f + 4 * i)) == (*(f + 1 + 4 * i))) && ((*(f + 4 * i)) != 0))
			a = 1;
		if( ((*(f + 1 + 4 * i)) == (*(f + 2 + 4 * i))) && ((*(f + 1 + 4 * i)) != 0))
			a = 1;
		if( ((*(f + 2 + 4 * i)) == (*(f + 3 + 4 * i))) && ((*(f + 2 + 4 * i)) != 0))
			a = 1;
	}

	for(y = 0; y < 4; y++)
	{
		for(int i = 0; i < 3; i++)
		{
			if(*(f + 4 * y) == 0)
			 {
				*(f + 4 * y) = *(f + 1 + 4 * y);
				*(f + 1 + 4 * y) = *(f + 2 + 4 * y);
				*(f + 2 + 4 * y) = *(f + 3 + 4 * y);
				*(f + 3 + 4 * y) = 0;
			 }
	
			 if(*(f + 1 + 4 * y) == 0)
			 {
				*(f + 1 + 4 * y) = *(f + 2 + 4 * y);
				*(f + 2 + 4 * y) = *(f + 3 + 4 * y);
				*(f + 3 + 4 * y) = 0;
			 }
	
			 if(*(f + 2 + 4 * y) == 0)
			 {
				*(f + 2 + 4 * y) = *(f + 3 + 4 * y);
				*(f + 3 + 4 * y) = 0;
			 }
		}
	}

	for(y = 0; y < 4; y++)
	{
		if(*(f + 4 * y) == *(f + 1 + 4 * y))
		{
			*(f + 4 * y) += *(f + 1 + 4 * y);
			*(f + 1 + 4 * y) = *(f + 2 + 4 * y);
			*(f + 2 + 4 * y) = *(f + 3 + 4 * y);
			*(f + 3 + 4 * y) = 0;
		}

		if(*(f + 1 + 4 * y) == *(f + 2 + 4 * y))
		{
			*(f + 1 + 4 * y) += *(f + 2 + 4 * y);
			*(f + 2 + 4 * y) = *(f + 3 + 4 * y);
			*(f + 3 + 4 * y) = 0;
		}

		if(*(f + 2 + 4 * y) == *(f + 3 + 4 * y))
		{
			*(f + 2 + 4 * y) += *(f + 3 + 4 * y);
			*(f + 3 + 4 * y) = 0;
		}

		for(int i = 0; i < 2; i++)\
		{
			if(*(f + 4 * y) == 0)
			 {
				*(f + 4 * y) = *(f + 1 + 4 * y);
				*(f + 1 + 4 * y) = *(f + 2 + 4 * y);
				*(f + 2 + 4 * y) = *(f + 3 + 4 * y);
				*(f + 3 + 4 * y) = 0;
			 }
	
			 if(*(f + 1 + 4 * y) == 0)
			 {
				*(f + 1 + 4 * y) = *(f + 2 + 4 * y);
				*(f + 2 + 4 * y) = *(f + 3 + 4 * y);
				*(f + 3 + 4 * y) = 0;
			 }
	
			 if(*(f + 2 + 4 * y) == 0)
			 {
				*(f + 2 + 4 * y) = *(f + 3 + 4 * y);
				*(f + 3 + 4 * y) = 0;
			 }
		}
	}
	return a;
}

int right(int * f)
{
	int y, a = 0;

	for(int i = 0; i < 4; i++)
	{
		if(*(f + 3 + 4 * i) == 0)
			if( (*(f + 2 + 4 * i) != 0) || (*(f + 1 + 4 * i) != 0) || (*(f + 4 * i) != 0))
				a = 1;
		if(*(f + 2 + 4 * i) == 0)
			if( (*(f + 1 + 4 * i) != 0) || (*(f + 4 * i) != 0))
				a = 1;
		if(*(f + 1 + 4 * i) == 0)
			if( (*(f + 4 * i) != 0))
				a = 1;
		if( ((*(f + 3 + 4 * i)) == (*(f + 2 + 4 * i))) && ((*(f + 3 + 4 * i)) != 0))
			a = 1;
		if( ((*(f + 2 + 4 * i)) == (*(f + 1 + 4 * i))) && ((*(f + 2 + 4 * i)) != 0))
			a = 1;
		if( ((*(f + 1 + 4 * i)) == (*(f + 4 * i))) && ((*(f + 1 + 4 * i)) != 0))
			a = 1;
	}

	for(y = 0; y < 4; y++)
	{
		for(int i = 0; i < 3; i++)
		{
			if(*(f + 3 + 4 * y) == 0)
			 {
				*(f + 3 + 4 * y) = *(f + 2 + 4 * y);
				*(f + 2 + 4 * y) = *(f + 1 + 4 * y);
				*(f + 1 + 4 * y) = *(f + 4 * y);
				*(f + 4 * y) = 0;
			 }
	
			 if(*(f + 2 + 4 * y) == 0)
			 {
				*(f + 2 + 4 * y) = *(f + 1 + 4 * y);
				*(f + 1 + 4 * y) = *(f + 4 * y);
				*(f + 4 * y) = 0;
			 }
			
			 if(*(f + 1 + 4 * y) == 0)
			 {
				*(f + 1 + 4 * y) = *(f + 4 * y);
				*(f + 4 * y) = 0;
			 }
		}
	}

	for(y = 0; y < 4; y++)
	{
		if(*(f + 3 + 4 * y) == *(f + 2 + 4 * y))
		{
			*(f + 3 + 4 * y) += *(f + 2 + 4 * y);
			*(f + 2 + 4 * y) = *(f + 1 + 4 * y);
			*(f + 1 + 4 * y) = *(f + 4 * y);
			*(f + 4 * y) = 0;
		}

		if(*(f + 2 + 4 * y) == *(f + 1 + 4 * y))
		{
			*(f + 2 + 4 * y) += *(f + 1 + 4 * y);
			*(f + 1 + 4 * y) = *(f + 4 * y);
			*(f + 4 * y) = 0;
		}

		if(*(f + 1 + 4 * y) == *(f + 4 * y))
		{
			*(f + 1 + 4 * y) += *(f + 4 * y);
			*(f + 4 * y) = 0;
		}

		for(int i = 0; i < 2; i++)
		{
			if(*(f + 3 + 4 * y) == 0)
		 	{
				*(f + 3 + 4 * y) = *(f + 2 + 4 * y);
				*(f + 2 + 4 * y) = *(f + 1 + 4 * y);
				*(f + 1 + 4 * y) = *(f + 4 * y);
				*(f + 4 * y) = 0;
			 }
	
			 if(*(f + 2 + 4 * y) == 0)
			 {
				*(f + 2 + 4 * y) = *(f + 1 + 4 * y);
				*(f + 1 + 4 * y) = *(f + 4 * y);
				*(f + 4 * y) = 0;
			 }
	
			 if(*(f + 1 + 4 * y) == 0)
			 {
				*(f + 1 + 4 * y) = *(f + 4 * y);
				*(f + 4 * y) = 0;
		 	}
		}
	}
	return a;
}

int ifwin(int * f)
{
	char a;
	
	for(int i = 0; i < 16; i++)
	{
		if(*(f + i) == 2048)
		{
			puts("You Got 2048,Do you want to continue?");

			while(1)			
			{
				scanf("%c",&a);
				
				while(getchar() != '\n')
					continue;

				if(a != 'y' || a != 'n')
					puts("Please input y or n.");
				else
					break;
			}
			return (a = 'y')?0:1;
		}
	}

	return -1;
}

int islose(int * f)
{
	for(int i = 0; i < 16; i++)
	{
		if(*(f + i) == 0)
			return 0;
	}

	for(int i = 0; i < 12; i++)
	{
		if(*(f + i) == *(f + 4 + i))
			return 0;
	}

	for(int i = 0; i < 3; i++)
	{
		if(*(f + i) == *(f + 1 + i))
			return 0;
	}

	for(int i = 4; i < 7; i++)
	{
		if(*(f + i) == *(f + 1 + i))
			return 0;
	}

	for(int i = 8; i < 11; i++)
	{
		if(*(f + i) == *(f + 1 + i))
			return 0;
	}

	for(int i = 12; i < 15; i++)
	{
		if(*(f + i) == *(f + 1 + i))
			return 0;
	}

	return 1;
}


void add(int *  f)
{
	int j = 0;
	for(int i = 0; i < 16; i ++)
		j += (*(f + i) != 0)?1:0;
	if(j == 16)
		return;
	
	int p = 0, d = 0;
	unsigned int t;
	t = (unsigned)time(NULL);

	while(1)
	{
		srand(t);
		p = rand() % 16;

		if(*(f + p) == 0)
		{
			t++;
			srand(t);
			d = (((rand() % 2) + 1) * 2);
			break;
		}
		else
		{
			t++;
			continue;
		}
	}
	*(f + p) = d;
	return;
}
