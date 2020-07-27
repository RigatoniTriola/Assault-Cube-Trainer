#include <iostream>
#include "Classes.h"
#include "Hook.h"
#include "Functions.h"

void PrintMenu() {
	using namespace std;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|        Press [NUMPAD 0] To Toggle Telekill.        |" << endl;
	cout << "|      Press [NUMPAD 1] To Toggle Infinte Ammo.      |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|  Player Name:  | Team: | HP: |       Coords:       |" << endl;
	cout << "|" << *(char*)Local.Name() << "|  " << *(bool*)Local.Team() << "  |                    |" << endl;
}

void MainFunc() {
	AllocConsole();
	AttachConsole(GetProcessId(GetCurrentProcess()));
	freopen("CONOUT$", "w", stdout);

	Hack Telekill;
	Hooks::MidFunctionHook Ammo{ (DWORD)0x004637E9, (PBYTE)"\xFF\x06", 2 };

	InitializePlayerList();

	while (true) {
		//PrintMenu();

		if (GetAsyncKeyState(VK_NUMPAD0) & 1)
			Telekill.Toggle();

		if (GetAsyncKeyState(VK_NUMPAD1) & 1)
			Ammo.Toggle();

		system("CLS");
		Sleep(10);
	}
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD dwReason, LPVOID lpReserved) {
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)MainFunc, 0, 0, 0);
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}