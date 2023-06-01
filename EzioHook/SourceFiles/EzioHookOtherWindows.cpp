#include <imgui.h>
#include <GetPointer.h>
#include <Windows.h>
#include <EzioHookPlayerInfo.h>
#include <SharedDataTypes.h>
#include <EzioHookOtherWindows.h>
#include <algorithm>
float EHWindowAlpha = 0.725f;
float EHCornerRounding = 0.0f;
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
	ImGui::GetStyle().WindowRounding = EHCornerRounding - 2.0f;
	ImGui::GetStyle().FrameRounding = EHCornerRounding; 
	ImGui::GetStyle().GrabRounding = EHCornerRounding; 
	ImGui::SliderFloat("EzioHook Transparency ", &EHWindowAlpha, 0.0f, 1.0f);
	ImGui::SliderFloat("Corner Rounding", &EHCornerRounding, 0.0f, 12.0f);

	EHWindowAlpha = std::clamp(EHWindowAlpha, 0.0f, 1.0f);
	ImGui::GetStyle().WindowRounding = std::clamp(ImGui::GetStyle().WindowRounding, 0.0f, 12.0f);
	EHCornerRounding = std::clamp(EHCornerRounding, 0.0f, 12.0f);

	if (ImGui::Button("Restore Defaults"))
	{
		EHWindowAlpha = 0.725f;
		EHCornerRounding = 0.0f;
	}
	ImGui::End();
}