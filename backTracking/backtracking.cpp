#include <iostream>


void bt(char * permStr, int k)
{
	static bool test[5]{0};
	static char perm[6];
	static int a = 0;
	if(k == 5)
	{
		perm[k] = '\0';
		++a;
		std::cout << a << ": " << perm << "\n";
	}
	else 
	{   
		for(int i = 0; i < 5; i++)
		{
			if(test[i] == 0)
			{
				perm[k] = permStr[i];
				test[i] = 1;
				bt(permStr, k+1);
				test[i] = 0;
			}
		}
	}
}

int main()
{
	system("clear");
	char play[]{'1','2','3','4','5'};
	bt(play,0);
	return 0;
}