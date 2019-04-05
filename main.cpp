#include <iostream>
#include <Windows.h>

HANDLE g_hConsole{}; // 디버깅 하면 켜지는 콘솔 창의 핸들.

using namespace std;

void MySetConsoleCursorPosition(SHORT x, SHORT y)
{
	COORD Position{ x ,y };
	SetConsoleCursorPosition(g_hConsole, Position);
}

void PrintAt(SHORT x, SHORT y, char letter)
{
	MySetConsoleCursorPosition( x, y );
	cout << letter;
}

void PrintAt(SHORT x, SHORT y, const char* str)
{
	MySetConsoleCursorPosition( x, y );
	cout << str;
}

int Add(int a, int b)
{
	return a + b;
}

int g_PosX{6};
int g_PosY{6};

int main()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) < 0)
		{
			return 0;
		}

		if (GetAsyncKeyState(VK_UP) < 0)
		{
			if (g_PosY > 1)
			{
				--g_PosY;
			}
		}
		if (GetAsyncKeyState(VK_DOWN) < 0)
		{
			if (g_PosY  < 11)
			{
				++g_PosY;
			}
		}

		if (GetAsyncKeyState(VK_LEFT) < 0)
		{
			if (g_PosX > 1)
			{
				--g_PosX;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) < 0)
		{
			if (g_PosX < 10)
			{
				++g_PosX;
			}
		}

		g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		PrintAt(0, 0, "############");
		for (int i = 1; i <= 11; i++)
		{
			PrintAt(0, i, "#          #");
		}
		PrintAt(0, 12, "############");

		PrintAt(g_PosX, g_PosY, '$');

		MySetConsoleCursorPosition(0, 14);

		Sleep(50);
	}
	


	system("pause");

	return 0;
}