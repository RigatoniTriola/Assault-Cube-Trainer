#include <Windows.h>

namespace Hooks {
	class MidFunctionHook {
		DWORD Address;
		PBYTE OrigBytes;
		PBYTE NewBytes;
		int Length;
		BOOL Status;

		void Place();
		void Remove();
	public:
		MidFunctionHook(DWORD Address, PBYTE Bytes, int Length);
		~MidFunctionHook();
		void Toggle();
	};

	class CodeCave {
		DWORD Address;
		DWORD HookFunction;
		PBYTE OrigBytes;
		int Length;
		BOOL Status;

		void Place();
		void Remove();
	public:
		CodeCave(DWORD Address, DWORD HookFunction, int Length);
		~CodeCave();
		void Toggle();
	};
}
