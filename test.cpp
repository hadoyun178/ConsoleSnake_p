/*
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
	MySetConsoleCursorPosition(x, y);
	cout << letter;
}

void PrintAt(SHORT x, SHORT y, const char* str)
{
	MySetConsoleCursorPosition(x, y);
	cout << str;
}

int main()
{
	g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	PrintAt(6, 4, '$');
	PrintAt(4, 2, '@');
	PrintAt(1, 7, '$');
	PrintAt(10, 3, "test");

	MySetConsoleCursorPosition(0, 10);

	system("pause");

	return 0;
}*/