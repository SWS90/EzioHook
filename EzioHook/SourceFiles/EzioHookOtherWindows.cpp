#include <imgui.h>
#include <GetPointer.h>
#include <Windows.h>
#include <EzioHookPlayerInfo.h>
#include <SharedDataTypes.h>
#include <EzioHookOtherWindows.h>
#include <algorithm>
float EHWindowAlpha = 0.725f;
int EHPlayerMoneyAdjustAmount = 1;
int EHPlayerMoneyAdjustAmountFast = 10;
bool ShowEzioConfigWindow;
bool ShowEzioCreditsWindow;
void EzioHookAC2PlayerInfoWindow()
{
	ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
	ImGui::Begin("PlayerInfoAC2", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
	PlayerPosAC2();
	PlayerSpeedAC2();
	ImGui::End();
}
void EzioHookAC2PlayerInventoryAdjustAmountWindow()
{
	ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
	ImGui::Begin("PlayerInventoryAdjustAmount", NULL, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::InputInt("Money Adjustment Amount (Slow)", &EHPlayerMoneyAdjustAmount, 1, 10);
	ImGui::InputInt("Money Adjustment Amount (Fast)", &EHPlayerMoneyAdjustAmountFast, 1, 10);
	EHPlayerMoneyAdjustAmount = std::clamp(EHPlayerMoneyAdjustAmount, 1, 2000000000);
	EHPlayerMoneyAdjustAmountFast = std::clamp(EHPlayerMoneyAdjustAmountFast, 10, 2000000000);
	ImGui::End();
}
void EzioHookConfig(bool* ShowEHConfig)
{
	ImGui::SliderFloat("EzioHook Transparency ", &EHWindowAlpha, 0.0f, 1.0f);
	ImGui::End();
}