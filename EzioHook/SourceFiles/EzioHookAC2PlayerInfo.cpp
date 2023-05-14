#include <ImGui.h>
#include <Windows.h>
#include <GetPointer.h>
#include <SharedBools.h>
void PlayerPosAC2()
{
	size_t PlayerPosBaseAddr = 0x022133FC;
	size_t PlayerXPosOffsets[] = { 0x04, 0x04, 0x10, 0x40, 0x00, 0x40 };
	size_t PosXResult = GetPointer(PlayerPosBaseAddr, PlayerXPosOffsets, _countof(PlayerXPosOffsets));
	float* PlayerPos = (float*)GetPointer(PlayerPosBaseAddr, PlayerXPosOffsets, _countof(PlayerXPosOffsets));
	if (PosXResult == 0)
	{
		ImGui::Text("Cannot currently read Player Position Info.");
	}
	if (PosXResult != 0)
	{
		ImGui::Text("Player Position(X,Y,Z) %.3f %.3f %.3f", PlayerPos[0], PlayerPos[1], PlayerPos[2]);
	}
	ImGui::End();
}