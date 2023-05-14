#include <imgui.h>
#include <MemoryHelpers.h>
#include <Windows.h>
#include <string>
#include <EzioHookMenus.h>
#include <SharedBools.h>
#include <Console.h>
#include <algorithm>
#include <GetPointer.h>
#include <EzioHookPlayerInfo.h>
float EHWindowAlpha = 0.725f;
bool ForceHQLODS = false;
bool ForceHQLODSActive = false;
static float FrozenTime = 0;
static int ShadowResItemOptions = 0;
const char* ShadowResOptions[] = { "512 (Game Low/Med)", "1024 (Game High)", "2048", "3072","4096","Custom"};
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
            ImGui::Checkbox("Force HQ LODs", &ForceHQLODS);
            ImGui::SameLine();
            ImGui::Text("(?)");
            if (ImGui::IsItemHovered()){ ImGui::SetTooltip("Based on Bucket5's 'Assassin's Creed 2 Visual Fixup Mod'<https://www.moddb.com/mods/assassins-creed-2-visual-fixup-mod>\nThis will force all buildings to use the highest level-of-detail models available."); }
               
            if (ForceHQLODS && !ForceHQLODSActive)
            {
                // Force LOD0 buildings etc...
                WRITE_MEMORY(0x015BFE8C, uint8_t, 0x31, 0xC0);
                WRITE_NOP(0x015BFE8E, 1);
                // Disable LOD transitions
                WRITE_MEMORY(0x015BFD89, uint8_t, 0xB8, 0xFF, 0x00, 0x00, 0x00); 
                WRITE_NOP(0x015BFD8E, 1);
                WRITE_NOP(0x015BFD8F, 1);
                WRITE_NOP(0x015BFD90, 1);
                WRITE_NOP(0x015BFD91, 1);
                ForceHQLODSActive = true;
            }
            if (!ForceHQLODS && ForceHQLODSActive)
            {
                // Revert "Force LOD0 buildings etc...
                WRITE_MEMORY(0x015BFE8C, byte, 0x8B,0x45,0xF0);
                WRITE_MEMORY(0x015BFE8F, byte, 0x8A,0x4B,0x28);
                // Revert "Disable LOD transitions"
                WRITE_MEMORY(0x015BFD89, uint8_t, 0x25, 0xFF, 0x3F, 0x00, 0x00);
                WRITE_MEMORY(0x015BFD8E, uint8_t, 0x0F, 0xB6, 0x04, 0x10); 
                WRITE_MEMORY(0x015BFD92, uint8_t, 0x85, 0xC0);
                WRITE_MEMORY(0x015BFD94, uint8_t, 0x89, 0x45, 0xD8);
                WRITE_MEMORY(0x015BFD97, uint8_t, 0x0F, 0x84, 0x9C, 0x00, 0x00, 0x00);
                ForceHQLODSActive = false;
            }
            if (!FreezeTimeOfDayAC2)
            {
                ImGui::SliderFloat("TimeOfDay", (float*)0x020EF7F8, 0.0f, 24.0f);
                ImGui::SameLine();
            }
            ImGui::Checkbox("PauseToD", &FreezeTimeOfDayAC2);
            if (FreezeTimeOfDayAC2)
            {
                float TimeOfDay = *((float*)0x020EF7F8);
                WRITE_MEMORY(0x020EF7F8, float, FrozenTime);
                FreezeTimeOfDayAC2 = true;
            }
            if (!FreezeTimeOfDayAC2)
            {
                FrozenTime = *((float*)0x020EF7F8);
            }
            ImGui::Combo("Shadow Resolution", &ShadowResItemOptions, ShadowResOptions, IM_ARRAYSIZE(ShadowResOptions));
            if (ShadowResItemOptions == 0) // 512 (Game Low/Med)
            {
                WRITE_MEMORY(0x021D0278, int, 512); // Shadow Res 1
                WRITE_MEMORY(0x02243CF0, int, 512); // Shadow Res 2
                WRITE_MEMORY(0x022441D0, int, 512); // Shadow Res 3
            }
            if (ShadowResItemOptions == 1) // 1024 (Game High)
            {
                WRITE_MEMORY(0x021D0278, int, 1024); // Shadow Res 1
                WRITE_MEMORY(0x02243CF0, int, 1024); // Shadow Res 2
                WRITE_MEMORY(0x022441D0, int, 1024); // Shadow Res 3
            }
            else if (ShadowResItemOptions == 2) // 2048
            {
                WRITE_MEMORY(0x021D0278, int, 2048); // Shadow Res 1
                WRITE_MEMORY(0x02243CF0, int, 2048); // Shadow Res 2
                WRITE_MEMORY(0x022441D0, int, 2048); // Shadow Res 3
            }
            else if (ShadowResItemOptions == 3) // 3072
            {
                WRITE_MEMORY(0x021D0278, int, 3072); // Shadow Res 1
                WRITE_MEMORY(0x02243CF0, int, 3072); // Shadow Res 2
                WRITE_MEMORY(0x022441D0, int, 3072); // Shadow Res 3
            }
            else if (ShadowResItemOptions == 4) // 4096
            {
                WRITE_MEMORY(0x021D0278, int, 4096); // Shadow Res 1
                WRITE_MEMORY(0x02243CF0, int, 4096); // Shadow Res 2
                WRITE_MEMORY(0x022441D0, int, 4096); // Shadow Res 3
            }
            else if (ShadowResItemOptions == 5) // Custom
            {
                ImGui::SliderInt("Custom Shadow Resolution", &ShadowResValue, 1, 4096);
                ShadowResValue = std::clamp(ShadowResValue, 1, 4096);
                WRITE_MEMORY(0x021D0278, int, ShadowResValue); // Shadow Res 1
                WRITE_MEMORY(0x02243CF0, int, ShadowResValue); // Shadow Res 2
                WRITE_MEMORY(0x022441D0, int, ShadowResValue); // Shadow Res 3
            }
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
                ImGui::Text("Cannot currently read CameraFOV value.");
            }
            if (CamFOVResult != 0)
            {
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
            ImGui::SetWindowSize(ImVec2(440, 120));
            ImGui::BeginChild("EH_PlayerChild");
            ImGui::Checkbox("Show seperate Player Info window.", &ShowPlayerInfoAC2);
            PlayerPosAC2();
        }
        
        if (ImGui::BeginTabItem("EzioHook Credits"))
        {
            EzioHookCredits();
        }
    }
    ImGui::End();
}
