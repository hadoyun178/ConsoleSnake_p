#include <iostream>
#include <Windows.h>

void DetectInput();
void PrintSprite();

constexpr int KGameSizeX{ 10 };
constexpr char KSprite{ '@' };
int g_pos_x{};

bool g_IsGameOver{ false };

int main()
{

	// 무한루프
	while (true)
	{
		system("cls");

		DetectInput();
		PrintSprite();
		

		if (g_IsGameOver == true)
		{
			break;
		}

		Sleep(30);
	}
	return 0;
}

void DetectInput()
{
	if (GetAsyncKeyState(VK_ESCAPE) < 0)
	{
		g_IsGameOver = true;
	}

	if (GetAsyncKeyState(VK_LEFT) < 0)
	{
		--g_pos_x;
		// max 매크로 -> ()안의 두개 값을 비교하여 큰값만 남음.
		g_pos_x = max(g_pos_x, 0);
	}

	if (GetAsyncKeyState(VK_RIGHT) < 0)
	{
		++g_pos_x;
		// min 매크로 -> ()안의 두개 값을 비교하여 작은 값만 남음.
		g_pos_x = min(g_pos_x, KGameSizeX);
	}
}

void PrintSprite()
{
	using namespace std;

	cout << '#';

	if (g_pos_x == 0)
	{
		cout << KSprite;
	}
	else
	{
		// for (초기화; 조건; 진행)
		for (int i = 0; i < g_pos_x; ++i) 
		{
			cout << " ";
		}
		cout << KSprite;
		
	}

	for (int i = 0; i < KGameSizeX - g_pos_x; ++i)
	{
		cout << " ";
	}
	cout << '#';
}