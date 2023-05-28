#include <imgui.h>
#include <GetPointer.h>
#include <Windows.h>
#include <EzioHookPlayerInfo.h>
#include <SharedDataTypes.h>
#include <EzioHookConfig.h>
#include <algorithm>
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