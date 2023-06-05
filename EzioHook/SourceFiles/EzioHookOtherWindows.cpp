#include <imgui.h>
#include <GetPointer.h>
#include <Windows.h>
#include <EzioHookPlayerInfo.h>
#include <SharedDataTypes.h>
#include <EzioHookOtherWindows.h>
#include <algorithm>
float EHWindowAlpha = 0.725f;
float EHCornerRounding = 0.0f;
float EHScrollAmount = 0.25f;
int EHPlayerMoneyAdjustAmount = 1;
int EHPlayerMoneyAdjustAmountFast = 10;
bool ShowEHCreditsWindow;
void EHAC2PlayerInfoWindow()
{
	ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
	ImGui::Begin("PlayerInfoAC2", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize);
	PlayerPosAC2();
	PlayerSpeedAC2();
	ImGui::End();
}
void EHPlayerInventoryAdjustAmountWindow()
{
	ImGui::InputInt("Money Adjustment Amount (Slow)", &EHPlayerMoneyAdjustAmount, 1, 10);
	ImGui::InputInt("Money Adjustment Amount (Fast)", &EHPlayerMoneyAdjustAmountFast, 1, 10);
	EHPlayerMoneyAdjustAmount = std::clamp(EHPlayerMoneyAdjustAmount, 1, 2000000000);
	EHPlayerMoneyAdjustAmountFast = std::clamp(EHPlayerMoneyAdjustAmountFast, 10, 2000000000);
}
void EHConfig()
{
	ImGui::GetStyle().WindowRounding = EHCornerRounding - 2.0f;
	ImGui::GetStyle().FrameRounding = EHCornerRounding; 
	ImGui::GetStyle().GrabRounding = EHCornerRounding; 
	ImGui::SliderFloat("Window Transparency ", &EHWindowAlpha, 0.0f, 1.0f, NULL, ImGuiSliderFlags_AlwaysClamp);
	ImGui::SliderFloat("Corner Rounding", &EHCornerRounding, 0.0f, 12.0f, NULL, ImGuiSliderFlags_AlwaysClamp);
	ImGui::SliderFloat("Scroll Amount", &EHScrollAmount, 0.1f, 1.0f, NULL, ImGuiSliderFlags_AlwaysClamp);

	if (ImGui::Button("Restore Defaults"))
	{
		EHWindowAlpha = 0.725f;
		EHCornerRounding = 0.0f;
		EHScrollAmount = 0.25f;
	}
}