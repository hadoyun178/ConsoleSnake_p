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

	// ���ѷ���
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
		// max ��ũ�� -> ()���� �ΰ� ���� ���Ͽ� ū���� ����.
		g_pos_x = max(g_pos_x, 0);
	}

	if (GetAsyncKeyState(VK_RIGHT) < 0)
	{
		++g_pos_x;
		// min ��ũ�� -> ()���� �ΰ� ���� ���Ͽ� ���� ���� ����.
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
		// for (�ʱ�ȭ; ����; ����)
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