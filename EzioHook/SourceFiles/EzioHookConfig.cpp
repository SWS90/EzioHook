#include <EzioHookConfig.h>
#include <imgui.h>
float EHWindowAlpha = 0.725f;
int EHPlayerMoneyAdjustAmount = 1;
int EHPlayerMoneyAdjustAmountFast = 10;
void EzioHookConfig()
{
	ImGui::SliderFloat("EzioHook Transparency ", &EHWindowAlpha, 0.0f, 1.0f);
}