#include <imgui.h>
#include <GetPointer.h>
#include <Windows.h>
#include <EzioHookPlayerInfo.h>
#include <SharedDataTypes.h>
void EzioHookAC2PlayerInfoWindow()
{
	ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
	ImGui::Begin("PlayerInfoAC2", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
	PlayerPosAC2();
	PlayerSpeedAC2();
	ImGui::End();
}