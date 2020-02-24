#include <vector>
#include <windows.h>

#include <string>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include<fstream>

#include <stdio.h>
#include <atlstr.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

using namespace std;

// Keyboard
void SendInputString(vector<WORD> input)
{
	int len = input.size();
	if (len == 0) return;

	std::vector<INPUT> in(len * 2);
	ZeroMemory(&in[0], in.size() * sizeof(INPUT));

	int i = 0, idx = 0;
	while (i < len)
	{
		WORD ch = input[i++];

		if ((ch < 0xD800) || (ch > 0xDFFF))
		{
			in[idx].type = INPUT_KEYBOARD;
			in[idx].ki.wScan = ch;
			in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
			++idx;
		}
		else
		{
			in[idx].type = INPUT_KEYBOARD;
			in[idx].ki.wScan = ch;
			in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
			++idx;

			in[idx].type = INPUT_KEYBOARD;
			in[idx].ki.wScan = input[i++];
			in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
			++idx;
		}
	}

	while (i < len * 2) {
		WORD ch = input[i++ - len];

		if ((ch < 0xD800) || (ch > 0xDFFF))
		{
			in[idx] = in[idx - len];
			in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
			++idx;
		}
		else
		{
			in[idx] = in[idx - len];
			in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
			++idx;

			in[idx] = in[idx - len];
			in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
			++idx;
		}

	}

	SendInput(in.size(), &in[0], sizeof(INPUT));
}
void Ctrl_A()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'A';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'A';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_B()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'B';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'B';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_C()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;


	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'C';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'C';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_D()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'D';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'D';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_E()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'E';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'E';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_F()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'F';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'F';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_G()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'G';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'G';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_H()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'H';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'H';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_I()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'I';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'I';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_J()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'J';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'J';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_K()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'K';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'K';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_L()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'L';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'L';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_M()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'M';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'M';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_N()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'N';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'N';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_O()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'O';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'O';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_P()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'P';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'P';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_Q()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'Q';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'Q';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_R()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'R';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'R';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_S()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'S';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'S';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_T()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'T';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'T';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_U()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'U';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'U';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_V()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'V';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'V';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_W()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'W';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'W';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_X()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'X';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'X';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_Y()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'Y';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'Y';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Ctrl_Z()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'Z';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'Z';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LCONTROL;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}


void SendInputString(const std::wstring &str)
{
	int len = str.length();
	if (len == 0) return;

	std::vector<INPUT> in(len * 2);
	ZeroMemory(&in[0], in.size() * sizeof(INPUT));

	int i = 0, idx = 0;
	while (i < len)
	{
		WORD ch = (WORD)str[i++];

		if ((ch < 0xD800) || (ch > 0xDFFF))
		{
			in[idx].type = INPUT_KEYBOARD;
			in[idx].ki.wScan = ch;
			in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
			++idx;

			in[idx] = in[idx - 1];
			in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
			++idx;
		}
		else
		{
			in[idx].type = INPUT_KEYBOARD;
			in[idx].ki.wScan = ch;
			in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
			++idx;

			in[idx].type = INPUT_KEYBOARD;
			in[idx].ki.wScan = (WORD)str[i++];
			in[idx].ki.dwFlags = KEYEVENTF_UNICODE;
			++idx;

			in[idx] = in[idx - 2];
			in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
			++idx;

			in[idx] = in[idx - 2];
			in[idx].ki.dwFlags |= KEYEVENTF_KEYUP;
			++idx;
		}
	}

	SendInput(in.size(), &in[0], sizeof(INPUT));
}
//Mouse
void MouseSetup(INPUT *buffer)
{

	buffer->type = INPUT_MOUSE;
	buffer->mi.dx = (0 * (0xFFFF / SCREEN_WIDTH));
	buffer->mi.dy = (0 * (0xFFFF / SCREEN_HEIGHT));
	buffer->mi.mouseData = 0;
	buffer->mi.dwFlags = MOUSEEVENTF_ABSOLUTE;
	buffer->mi.time = 0;
	buffer->mi.dwExtraInfo = 0;
}
void MouseMoveTo(int toX, int toY)
{
	// get system information regarding screen size / resolution
	double screenRes_width = ::GetSystemMetrics(SM_CXSCREEN) - 1;
	double screenRes_height = ::GetSystemMetrics(SM_CYSCREEN) - 1;
	// scale the function inputs 'toX and 'toY' appropriately by a
	// factor of 65535
	double dx = toX*(65535.0f / screenRes_width);
	double dy = toY*(65535.0f / screenRes_height);
	// we now have variables 'dx' and 'dy' with the user-desired
	// coordinates in a form that the SendInput function can understand

	// set up INPUT Input, assign values, and move the cursor
	INPUT Input = { 0 };
	// we want to be sending a MOUSE-type input
	Input.type = INPUT_MOUSE;
	// the mouse input is of the 'MOVE ABSOLUTE' variety
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = LONG(dx);
	Input.mi.dy = LONG(dy);
	// we have given information about the magnitude of the new
	// cursor position; here we will send it
	::SendInput(1, &Input, sizeof(INPUT));
}
void MouseClickL(INPUT *buffer)
{
	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
	SendInput(1, buffer, sizeof(INPUT));

	Sleep(10);

	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
	SendInput(1, buffer, sizeof(INPUT));
}
void MouseClickR(INPUT *buffer)
{
	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTDOWN);
	SendInput(1, buffer, sizeof(INPUT));

	Sleep(10);

	buffer->mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_RIGHTUP);
	SendInput(1, buffer, sizeof(INPUT));
}
void ctrl_shift_n() {

	INPUT ctrlC[6];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LCONTROL;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = VK_LSHIFT;

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'N';

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = 'N';
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[4].type = INPUT_KEYBOARD;
	ctrlC[4].ki.wVk = VK_LSHIFT;
	ctrlC[4].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[5].type = INPUT_KEYBOARD;
	ctrlC[5].ki.wVk = VK_LCONTROL;
	ctrlC[5].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(6, ctrlC, sizeof(INPUT));
}
void ctrl_shift_a() {

	INPUT ctrla[6];
	ZeroMemory(ctrla, sizeof ctrla);

	ctrla[0].type = INPUT_KEYBOARD;
	ctrla[0].ki.wVk = VK_LCONTROL;

	ctrla[1].type = INPUT_KEYBOARD;
	ctrla[1].ki.wVk = VK_LSHIFT;

	ctrla[2].type = INPUT_KEYBOARD;
	ctrla[2].ki.wVk = 'A';

	ctrla[3].type = INPUT_KEYBOARD;
	ctrla[3].ki.wVk = 'A';
	ctrla[3].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrla[4].type = INPUT_KEYBOARD;
	ctrla[4].ki.wVk = VK_LSHIFT;
	ctrla[4].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrla[5].type = INPUT_KEYBOARD;
	ctrla[5].ki.wVk = VK_LCONTROL;
	ctrla[5].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(6, ctrla, sizeof(INPUT));
}

void Win_R()
{
	INPUT ctrlC[4];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_LWIN;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = 'R';

	ctrlC[2].type = INPUT_KEYBOARD;
	ctrlC[2].ki.wVk = 'R';
	ctrlC[2].ki.dwFlags = KEYEVENTF_KEYUP;

	ctrlC[3].type = INPUT_KEYBOARD;
	ctrlC[3].ki.wVk = VK_LWIN;
	ctrlC[3].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(4, ctrlC, sizeof(INPUT));
}
void Enter()
{
	INPUT ctrlC[2];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_RETURN;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = VK_RETURN;
	ctrlC[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(2, ctrlC, sizeof(INPUT));
}
void Back()
{
	INPUT ctrlC[2];
	ZeroMemory(ctrlC, sizeof ctrlC);

	ctrlC[0].type = INPUT_KEYBOARD;
	ctrlC[0].ki.wVk = VK_BACK;

	ctrlC[1].type = INPUT_KEYBOARD;
	ctrlC[1].ki.wVk = VK_BACK;
	ctrlC[1].ki.dwFlags = KEYEVENTF_KEYUP;

	SendInput(2, ctrlC, sizeof(INPUT));
}
void EmptyRecyclebin() {
	INPUT buffer[1];
	_sleep(1000);
	MouseSetup(buffer);
	MouseMoveTo(33, 33);
	_sleep(1000);
	MouseClickR(buffer);
	MouseMoveTo(72, 74);
	_sleep(1000);
	MouseClickL(buffer);
	_sleep(500);
	Enter();
	
}
void newfolder() {
	string name;
	cout << "Enter Folder Name" << endl;
	cin >> name;
	std::wstring foldername(name.length(), L' ');
	std::copy(name.begin(), name.end(), foldername.begin());
	INPUT buffer[1];
	_sleep(1000);
	MouseSetup(buffer);
	MouseMoveTo(191, 846);
	MouseClickL(buffer);
	_sleep(500);
	SendInputString(L"Desktop");
	_sleep(3000);
	Enter();
	_sleep(2000);
	ctrl_shift_n();
	SendInputString(foldername);
	Enter();
	_sleep(500);
	Enter();

}
void steam() {
	INPUT buffer[1];
	_sleep(1000);
	MouseSetup(buffer);
	MouseMoveTo(191, 846);
	MouseClickL(buffer);
	_sleep(500);
	SendInputString(L"steam");
	Enter();
}
void youtube() {
	system("start chrome /incognito https://www.youtube.com");
}
void gmail() {
	system("start chrome /incognito https://www.gmail.com");
}
void cpp() {

	string name;
	cout << "Enter Project Name" << endl;
	cin >> name;
	std::wstring projname(name.length(), L' ');
	std::copy(name.begin(), name.end(), projname.begin());
	cout << "Enter Source File Name" << endl;
	cin >> name;
	std::wstring srcname(name.length(), L' ');
	std::copy(name.begin(), name.end(), srcname.begin());

	INPUT buffer[1];
	_sleep(1000);
	MouseSetup(buffer);
	MouseMoveTo(191, 846);
	MouseClickL(buffer);
	_sleep(500);
	SendInputString(L"visual");
	Enter();
	_sleep(5000);
	ctrl_shift_n();
	_sleep(1000);
	MouseMoveTo(565, 614);
	_sleep(4000);
	MouseClickL(buffer);
	_sleep(4000);
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	_sleep(1000);
	SendInputString(projname);
	Enter();
	_sleep(1000);
	MouseMoveTo(908, 641);
	_sleep(1000);
	MouseClickL(buffer);
	MouseMoveTo(621, 403);
	_sleep(1000);
	MouseClickL(buffer);
	MouseMoveTo(620, 462);
	_sleep(1000);
	MouseClickL(buffer);
	MouseMoveTo(1009, 644);
	_sleep(1000);
	MouseClickL(buffer);
	_sleep(7000);
	ctrl_shift_a();
	MouseMoveTo(463, 663);
	_sleep(2000);
	MouseClickL(buffer);
	_sleep(2000);
	Back();
	Back();
	Back();
	Back();
	Back();
	Back();
	SendInputString(srcname);
	MouseMoveTo(1100, 718);
	_sleep(1000);
	MouseClickL(buffer);
	MouseMoveTo(134, 137);
	_sleep(1000);
	MouseClickL(buffer);

}
void openproj() {

}
/*wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

vector<string> get_all_files_names_within_folder(string folder)
{
	vector<string> names;
	string search_path = folder + "C:/Users/iD Student/Desktop/Devin T";
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path.c_str(), &fd);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			// read all (real) files in current folder
			// , delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
				names.push_back(fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}
	return names;
}*/
void lowercase(string & input) {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] += 32;
		}
	}
}
int main(int argc, char *argv[])
{
	cout << "List Of Commands" << endl;
	cout << "    " << endl;
	cout << "Empty Recycle bin(ERB)" << endl;
	cout << "Youtube(Y)" << endl;
	cout << "Gmail(g)" << endl;
	cout << "Create New Folder Desktop(NF)" << endl;
	cout << "Exit(E)" << endl;
	/*cout << "New C++ Project(NCP)" << endl;
	cout << "Open C++ Project(OCP" << endl;*/
	cout << "    " << endl;
	cout << "Enter Command" << endl;
	cout << "    " << endl;

	while(true) {
		string input;
		char temp[10000];
		cin.getline(temp, 10000);
		input = string(temp);

		lowercase(input);

		if (input == "nf") {
			newfolder();
		}
		else if (input == "y") {
			youtube();
		}
		else if (input == "g") {
			gmail();
		}
		else if (input == "ocp") {
			openproj();
		}
		else if (input == "erb") {
			EmptyRecyclebin();
		}
		else if (input == "e") {
			return 0;
		}
		else {
			

		}
	}
}