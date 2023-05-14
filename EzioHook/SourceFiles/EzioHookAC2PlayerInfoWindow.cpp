#include <imgui.h>
#include <GetPointer.h>
#include <Windows.h>
#include <EzioHookPlayerInfo.h>
void EzioHookAC2PlayerInfoWindow()
{
	ImGui::Begin("PlayerInfoAC2", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
	PlayerPosAC2();
}