#include <stdio.h>

void Init()
{

}

int main(void)
{

	Init();
	while (1)
	{
		Update();
		Render();
	}
	Release();

	return 0;
}