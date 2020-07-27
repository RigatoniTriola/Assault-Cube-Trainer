#include "Classes.h"

Offsets Offset;

/*Vec3 Class*/
Vec3 Vec3::operator+ (const Vec3& Vec) {
	Vec3 Temp;
	Temp.x = this->x + Vec.x;
	Temp.y = this->y + Vec.y;
	Temp.z = this->z + Vec.z;
	return Temp;
}

Vec3 Vec3::operator- (const Vec3& Vec) {
	Vec3 Temp;
	Temp.x = this->x - Vec.x;
	Temp.y = this->y - Vec.y;
	Temp.z = this->z - Vec.z;
	return Temp;
}

Vec3 Vec3::operator* (const Vec3& Vec) {
	Vec3 Temp;
	Temp.x = this->x * Vec.x;
	Temp.y = this->y * Vec.y;
	Temp.z = this->z * Vec.z;
	return Temp;
}

Vec3 Vec3::operator/ (const Vec3& Vec) {
	Vec3 Temp;
	Temp.x = this->x / Vec.x;
	Temp.y = this->y / Vec.y;
	Temp.z = this->z / Vec.z;
	return Temp;
}


/*Player Class*/
DWORD Player::Location() {
	return (DWORD)((*Player::pAddress) + Offset.Location);
}

DWORD Player::ViewAngles() {
	return (DWORD)((*Player::pAddress) + Offset.ViewAngles);
}

DWORD Player::Health() {
	return (DWORD)((*Player::pAddress) + Offset.Health);
}

DWORD Player::Armour() {
	return (DWORD)((*Player::pAddress) + Offset.Armor);
}

DWORD Player::Grenade() {
	return (DWORD)((*Player::pAddress) + Offset.Grenade);
}

DWORD Player::Name() {
	return (DWORD)((*Player::pAddress) + Offset.Name);
}

DWORD Player::Team() {
	return (DWORD)((*Player::pAddress) + Offset.Team);
}

Player::Player() { Player::pAddress = NULL; };

Player::Player(DWORD* Address) { Player::pAddress = Address; };

/*Hack Class*/
Hack::Hack() { Hack::Status = false; };

void Hack::Toggle() { Hack::Status != Hack::Status; };