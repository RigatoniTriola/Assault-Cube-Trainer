#include "Hook.h"

/*Mid Function Hook*/
void Hooks::MidFunctionHook::Place() {
	DWORD dwNew, dwOld;
	VirtualProtect((LPVOID)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::Length, PAGE_EXECUTE_READWRITE, &dwOld);
	memset((void*)Hooks::MidFunctionHook::Address, 0x90, Hooks::MidFunctionHook::Length);
	memcpy((void*)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::NewBytes, Hooks::MidFunctionHook::Length);
	VirtualProtect((LPVOID)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::Length, dwOld, &dwNew);
	Hooks::MidFunctionHook::Status = true;
}

void Hooks::MidFunctionHook::Remove() {
	DWORD dwNew, dwOld;
	VirtualProtect((LPVOID)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::Length, PAGE_EXECUTE_READWRITE, &dwOld);
	memset((void*)Hooks::MidFunctionHook::Address, 0x90, Hooks::MidFunctionHook::Length);
	memcpy((void*)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::OrigBytes, Hooks::MidFunctionHook::Length);
	VirtualProtect((LPVOID)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::Length, dwOld, &dwNew);
	Hooks::MidFunctionHook::Status = false;
}

void Hooks::MidFunctionHook::Toggle() {
	if (!Hooks::MidFunctionHook::Status)
		Hooks::MidFunctionHook::Place();
	else
		Hooks::MidFunctionHook::Remove();
}

Hooks::MidFunctionHook::MidFunctionHook(DWORD Address, PBYTE Bytes, int Length) {
	this->Address = Address;
	this->Length = Length;
	Hooks::MidFunctionHook::OrigBytes = new BYTE[Length];
	Hooks::MidFunctionHook::NewBytes = new BYTE[Length];
	Hooks::MidFunctionHook::NewBytes = Bytes;
	Hooks::MidFunctionHook::Status = false;

	DWORD dwNew, dwOld;
	VirtualProtect((LPVOID)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::Length, PAGE_EXECUTE_READWRITE, &dwOld);
	memcpy((void*)Hooks::MidFunctionHook::OrigBytes, (void*)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::Length);
	VirtualProtect((LPVOID)Hooks::MidFunctionHook::Address, Hooks::MidFunctionHook::Length, dwOld, &dwNew);
}

Hooks::MidFunctionHook::~MidFunctionHook() {
	delete[] Hooks::MidFunctionHook::OrigBytes;
	delete[] Hooks::MidFunctionHook::NewBytes;
}


/*Code Cave*/
void Hooks::CodeCave::Place() {
	DWORD dwOld, dwNew, dwOffset;
	VirtualProtect((LPVOID)Hooks::CodeCave::Address, Hooks::CodeCave::Length, PAGE_EXECUTE_READWRITE, &dwOld);
	memset((LPVOID)Hooks::CodeCave::Address, 0x90, Hooks::CodeCave::Length);
	dwOffset = ((DWORD)Hooks::CodeCave::HookFunction - (DWORD)Hooks::CodeCave::Address) - 0x5;
	*(BYTE*)(Hooks::CodeCave::Address) = 0xE9;
	*(DWORD*)(Hooks::CodeCave::Address + 0x1) = dwOffset;
	VirtualProtect((LPVOID)Hooks::CodeCave::Address, Hooks::CodeCave::Length, dwOld, &dwNew);
	Hooks::CodeCave::Status = true;
}

void Hooks::CodeCave::Remove() {
	DWORD dwOld, dwNew;
	VirtualProtect((LPVOID)Hooks::CodeCave::Address, Hooks::CodeCave::Length, PAGE_EXECUTE_READWRITE, &dwOld);
	memcpy((LPVOID)Hooks::CodeCave::Address, Hooks::CodeCave::OrigBytes, Hooks::CodeCave::Length);
	VirtualProtect((LPVOID)Hooks::CodeCave::Address, Hooks::CodeCave::Length, dwOld, &dwNew);
	Hooks::CodeCave::Status = false;
}

void Hooks::CodeCave::Toggle() {
	if (!Hooks::CodeCave::Status)
		Hooks::CodeCave::Place();
	else
		Hooks::CodeCave::Remove();
}

Hooks::CodeCave::CodeCave(DWORD Address, DWORD HookFunction, int Length) {
	this->Address = Address;
	this->HookFunction = HookFunction;
	this->Length = Length;
	Hooks::CodeCave::OrigBytes = new BYTE[Length];
	Hooks::CodeCave::Status = false;

	DWORD dwNew, dwOld;
	VirtualProtect((LPVOID)Hooks::CodeCave::Address, Hooks::CodeCave::Length, PAGE_EXECUTE_READWRITE, &dwOld);
	memcpy((void*)Hooks::CodeCave::OrigBytes, (void*)Hooks::CodeCave::Address, Hooks::CodeCave::Length);
	VirtualProtect((LPVOID)Hooks::CodeCave::Address, Hooks::CodeCave::Length, dwOld, &dwNew);
}

Hooks::CodeCave::~CodeCave() {
	delete[] Hooks::CodeCave::OrigBytes;
}