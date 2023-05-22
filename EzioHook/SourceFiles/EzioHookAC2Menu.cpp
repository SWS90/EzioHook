#include <imgui.h>
#include <Windows.h>
#include <string>
#include <EzioHookMenus.h>
#include <SharedDataTypes.h>
#include <Console.h>
#include <algorithm>
#include <GetPointer.h>
#include <EzioHookPlayerInfo.h>
void EzioHookAC2Menu()
{
    ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
    ImGui::Begin("EzioHook: Assassins Creed II - (INSERT-Show/Hide)" , NULL, ImGuiWindowFlags_NoResize);
    if (ImGui::BeginTabBar("EH_Tabs", ImGuiTabBarFlags_None))
    {
        if (ImGui::BeginTabItem("EzioHook Options"))
        {
            ImGui::SetWindowSize(ImVec2(455, 80));
            ImGui::BeginChild("EH_OptionsChild");
            ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
            ImGui::SliderFloat("EzioHook Transparency ", &EHWindowAlpha, 0.0f, 1.0f);
            ImGui::EndChild();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Graphics"))
        {
            ImGui::SetWindowSize(ImVec2(505, 165));
            ImGui::BeginChild("EH_GraphicsChild");
            int ShadowResValue = *((int*)0x021D0278);
            ImGui::Text("Shadow Resolution: %d", ShadowResValue);
            HQLODSAC2();
            TimeOfdayAC2();
            ShadowResolutionAC2();
            ImGui::EndChild();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Camera"))
        {
            ImGui::SetWindowSize(ImVec2(440, 120));
            ImGui::BeginChild("EH_CameraChild");
            size_t CamFOVBaseAddr = 0x02210B84;
            size_t CamFOVOffsets[] = { 0x20, 0x00, 0x30 };
            size_t CamFOVResult = GetPointer(CamFOVBaseAddr, CamFOVOffsets, _countof(CamFOVOffsets));
            if (CamFOVResult == 0)
            {
                ImGui::BeginDisabled(true);
                ImGui::SliderFloat("Camera FOV", &EHFloatCannotRead, 0.001f, 3.14f);
                ImGui::Text("Camera FOV (In Degrees): ???");
                ImGui::Button("Restore default FOV");
                ImGui::EndDisabled();
            }
            if (CamFOVResult != 0)
            {
                ImGui::BeginDisabled(false);
                ImGui::SliderFloat("Camera FOV", (float*)CamFOVResult, 0.001f, 3.14f);
                *((float*)CamFOVResult) = std::clamp(*(float*)CamFOVResult, 0.001f, 3.14f);
                float Degrees = *((float*)CamFOVResult) * (180.0f / 3.14159265359f);;
                ImGui::Text("Camera FOV (In Degrees): %f", *(float*)&Degrees);
                if (ImGui::Button("Restore default FOV"))
                {
                    *((float*)CamFOVResult) = 0.8072147965f;
                }
            }
            ImGui::EndChild();
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Player"))
        {
            if (ShowPlayerInfoWindowAC2) { ImGui::SetWindowSize(ImVec2(440, 200)); }
            if (!ShowPlayerInfoWindowAC2) { ImGui::SetWindowSize(ImVec2(440, 250)); }
            if (ShowPlayerInfoWindowAC2 && ShowSeparatePlayerScaleSlidersAC2) { ImGui::SetWindowSize(ImVec2(440, 190)); }
            if (ShowPlayerInfoWindowAC2 && !ShowSeparatePlayerScaleSlidersAC2) { ImGui::SetWindowSize(ImVec2(440, 170)); }
            if (!ShowPlayerInfoWindowAC2 && ShowSeparatePlayerScaleSlidersAC2) { ImGui::SetWindowSize(ImVec2(440, 250)); }
            if (!ShowPlayerInfoWindowAC2 && !ShowSeparatePlayerScaleSlidersAC2) { ImGui::SetWindowSize(ImVec2(440, 230)); }
            ImGui::BeginChild("EH_PlayerChild");
            ImGui::Checkbox("Show separate Player Info window.", &ShowPlayerInfoWindowAC2);
            if (!ShowPlayerInfoWindowAC2)
            {
                PlayerPosAC2();
                PlayerSpeedAC2();
            }
            PlayerScaleAC2();
            ImGui::EndChild();
            ImGui::EndTabItem();
        }
        
        if (ImGui::BeginTabItem("EzioHook Credits"))
        {
            ImGui::SetWindowSize(ImVec2(615, 500)); 
            ImGui::BeginChild("EHCreditsChild");
            EzioHookCredits();
            ImGui::EndChild();
            ImGui::EndTabItem();
            ImGui::EndTabBar();
        }
    }
    ImGui::End();
}
