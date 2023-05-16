#include <ImGui.h>
#include <Windows.h>
#include <GetPointer.h>
#include <SharedDataTypes.h>
#include <corecrt_math.h>
void PlayerPosAC2()
{
	size_t PlayerPosBaseAddr = 0x022133FC;
	size_t PlayerXPosOffsets[] = { 0x04, 0x04, 0x10, 0x40, 0x00, 0x40 };
	size_t PosXResult = GetPointer(PlayerPosBaseAddr, PlayerXPosOffsets, _countof(PlayerXPosOffsets));
	float* PlayerPos = (float*)GetPointer(PlayerPosBaseAddr, PlayerXPosOffsets, _countof(PlayerXPosOffsets));
	if (PosXResult == 0)
	{
		ImGui::Text("Cannot currently read Player Position Info.");
		ImGui::Separator();
	}
	if (PosXResult != 0)
	{
		ImGui::Text("Player Position(X,Y,Z) %.3f %.3f %.3f", PlayerPos[0], PlayerPos[1], PlayerPos[2]);
		ImGui::Separator();
	}
}
void PlayerSpeedAC2()
{
	size_t PlayerSpeedBaseAddr = 0x02213558;
	size_t PlayerSpeedXOffsets[] = { 0xC, 0x04, 0x0, 0x64, 0xF4, 0x30, 0x90 };
	size_t PlayerSpeedResult = GetPointer(PlayerSpeedBaseAddr, PlayerSpeedXOffsets, _countof(PlayerSpeedXOffsets));
	float* PlayerSpeed = (float*)GetPointer(PlayerSpeedBaseAddr, PlayerSpeedXOffsets, _countof(PlayerSpeedXOffsets));
	if (PlayerSpeedResult == 0)
	{
		ImGui::Text("Cannot currently read Player Speed Info.");
	}
	if (PlayerSpeedResult != 0)
	{
		ImGui::Text("Player Speed (X,Y,Z) %.3f %.3f %.3f", PlayerSpeed[0], PlayerSpeed[1], PlayerSpeed[2]);
		ImGui::Separator();
		ImGui::Text("Overall Player Speed: %.3f", sqrtf(PlayerSpeed[0] * PlayerSpeed[0] + PlayerSpeed[1] * PlayerSpeed[1] + PlayerSpeed[2] * PlayerSpeed[2]));
	}
}