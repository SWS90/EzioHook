#include <ImGui.h>
#include <Windows.h>
#include <GetPointer.h>
#include <SharedDataTypes.h>
#include <corecrt_math.h>
#include <algorithm>
void PlayerPosAC2()
{
	size_t PlayerPosBaseAddr = 0x022133FC;
	size_t PlayerXPosOffsets[] = { 0x04, 0x04, 0x10, 0x40, 0x00, 0x40 };
	size_t PosXResult = GetPointer(PlayerPosBaseAddr, PlayerXPosOffsets, _countof(PlayerXPosOffsets));
	float* PlayerPos = (float*)GetPointer(PlayerPosBaseAddr, PlayerXPosOffsets, _countof(PlayerXPosOffsets));
	if (PosXResult == 0)
	{
		ImGui::BeginDisabled(true); 
		ImGui::Text("Player Position(X,Y,Z): ???");
		ImGui::Separator();
		ImGui::EndDisabled();
	}
	if (PosXResult != 0)
	{
		ImGui::BeginDisabled(false); 
		ImGui::Text("Player Position(X,Y,Z): %.3f %.3f %.3f", PlayerPos[0], PlayerPos[1], PlayerPos[2]);
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
		ImGui::BeginDisabled(true); 
		ImGui::Text("Player Speed (X,Y,Z): ???");
		ImGui::Separator();
		ImGui::Text("Overall Player Speed: ???");
		ImGui::EndDisabled();
	}
	if (PlayerSpeedResult != 0)
	{
		ImGui::BeginDisabled(false); 
		ImGui::Text("Player Speed (X,Y,Z): %.3f %.3f %.3f", PlayerSpeed[0], PlayerSpeed[1], PlayerSpeed[2]);
		ImGui::Separator();
		ImGui::Text("Overall Player Speed: %.3f", sqrtf(PlayerSpeed[0] * PlayerSpeed[0] + PlayerSpeed[1] * PlayerSpeed[1] + PlayerSpeed[2] * PlayerSpeed[2]));
	}
}
void PlayerScaleAC2()
{
	size_t PlayerScaleXYBaseAddr = 0x02213560;
	size_t PlayerScaleZBaseAddr = 0x022110CC;
	size_t PlayerScaleXYOffsets[] = { 0x08, 0x4C, 0x04, 0x00, 0x08, 0xB8, 0xB4 };
	size_t PlayerScaleZOffsets[] = { 0x34, 0x28, 0x2C, 0x08, 0x18, 0xC4, 0x00, 0x7C };
	size_t PlayerScaleXYResult = GetPointer(PlayerScaleXYBaseAddr, PlayerScaleXYOffsets, _countof(PlayerScaleXYOffsets));
	size_t PlayerScaleZResult = GetPointer(PlayerScaleZBaseAddr, PlayerScaleZOffsets, _countof(PlayerScaleZOffsets));
	if (PlayerScaleXYResult == 0 || PlayerScaleZResult == 0)
	{
		ImGui::BeginDisabled(true); 
		ImGui::Separator();
		ImGui::Checkbox("Show separate Player Scale Sliders", &ShowSeparatePlayerScaleSlidersAC2);
		ImGui::SliderFloat("Player Scale X/Y", &EHFloatCannotRead, 0.1f, 10.0f);
		ImGui::SliderFloat("Player Scale Z", &EHFloatCannotRead, 0.1f, 10.0f);
		ImGui::Button("Restore default Player Scale");
		ImGui::EndDisabled();
	}
	if (PlayerScaleXYResult != 0 && PlayerScaleZResult !=0)
	{
		ImGui::BeginDisabled(false); 
		ImGui::Separator();
		ImGui::Checkbox("Show separate Player Scale Sliders", &ShowSeparatePlayerScaleSlidersAC2);
		if (ShowSeparatePlayerScaleSlidersAC2)
		{
			ImGui::SliderFloat("Player Scale X/Y", (float*)PlayerScaleXYResult, 0.1f, 10.0f);
			ImGui::SliderFloat("Player Scale Z", (float*)PlayerScaleZResult, 0.1f, 10.0f);
			*((float*)PlayerScaleXYResult) = std::clamp(*(float*)PlayerScaleXYResult, 0.1f, 10.0f);
			*((float*)PlayerScaleZResult) = std::clamp(*(float*)PlayerScaleZResult, 0.1f, 10.0f);
		}
		if (!ShowSeparatePlayerScaleSlidersAC2)
		{
			ImGui::SliderFloat("Player Scale", (float*)PlayerScaleXYResult, 0.1f, 10.0f);
			*(float*)PlayerScaleZResult = *((float*)PlayerScaleXYResult);
			*((float*)PlayerScaleXYResult) = std::clamp(*(float*)PlayerScaleXYResult, 0.1f, 10.0f);
			*((float*)PlayerScaleZResult) = std::clamp(*(float*)PlayerScaleZResult, 0.1f, 10.0f);
		}
		if (ImGui::Button("Restore default Player Scale"))
		{
			*((float*)PlayerScaleXYResult) = 1.0f;
			*((float*)PlayerScaleZResult) = 1.0f;
		}
	}
}