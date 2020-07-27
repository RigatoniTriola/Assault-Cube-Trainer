int CurPlayers = *(int*)0x0050F500;
Player Local{ (DWORD*)0x0050F4F8 };
Player PlayerList[31];

void InitializePlayerList() {
	DWORD* pBaseAddr = (DWORD*)((*(DWORD*)0x0050F4F8) + 0x4);
	for (int i = 0; i < 31; i++) { PlayerList[i].pAddress = (DWORD*)((pBaseAddr)+ 0x4 * i); };
}

bool IsValid(Player Player) {
	if (Player.pAddress == NULL || *Player.pAddress == NULL)
		return false;

	if (*(int*)Player.Health() < 0 || *(int*)Player.Health() > 100)
		return false;

	else
		return true;
}