#include <Windows.h>

struct Vec3 {
public:
	float x;
	float y;
	float z;

	Vec3 operator+ (const Vec3& Vec);
	Vec3 operator- (const Vec3& Vec);
	Vec3 operator* (const Vec3& Vec);
	Vec3 operator/ (const Vec3& Vec);
};

struct Offsets {
	DWORD Location = 0x34;
	DWORD ViewAngles = 0x40;
	DWORD Health = 0xF8;
	DWORD Armor = 0xFC;
	DWORD Grenade = 0x158;
	DWORD Name = 0x225;
	DWORD Team = 0x32C;
};

class Player {
public:
	DWORD* pAddress;
	DWORD Location(); //Vec3.
	DWORD ViewAngles(); //Vec3.
	DWORD Health(); //Integer.
	DWORD Armour(); //Integer.
	DWORD Grenade(); //Integer.
	DWORD Name(); //String.
	DWORD Team(); //Integer.

	Player();
	Player(DWORD* Address);
};

class Hack {
public:
	bool Status;
	Hack();
	void Toggle();
};