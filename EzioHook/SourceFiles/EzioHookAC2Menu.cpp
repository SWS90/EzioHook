#include <imgui.h>
#include <Windows.h>
#include <string>
#include <EzioHookMenus.h>
#include <SharedDataTypes.h>
#include <Console.h>
#include <EzioHookPlayerInfo.h>
#include <EzioHookOtherWindows.h>

void EzioHookAC2Menu()
{
    ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
    ImGui::SetNextWindowSize(ImVec2(635, 560), ImGuiCond_FirstUseEver);
    if (ImGui::Begin("EzioHook: Assassins Creed II - (INSERT-Show/Hide)", NULL, ImGuiWindowFlags_MenuBar))
    {
        if (ShowEHCreditsWindow)
        { 
            ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
            ImGui::Begin("EzioHookCredits", &ShowEHCreditsWindow, ImGuiWindowFlags_AlwaysAutoResize);
            EzioHookCredits(&ShowEHCreditsWindow);
        }
        
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("View"))
            {
                if (ImGui::BeginMenu("Config"))
                {
                    EzioHookConfig();
                    ImGui::EndMenu();
                }
                ImGui::Separator();
                ImGui::MenuItem("Credits", NULL, &ShowEHCreditsWindow);
                ImGui::EndMenu();
            }
        }
        ImGui::EndMenuBar();
    }
    
    if (ImGui::CollapsingHeader("Graphics"))
    {
        ImGui::TreePush("GraphicsTree"); 
        int ShadowResValue = *((int*)0x021D0278);
        ImGui::Text("Shadow Resolution: %d", ShadowResValue);
        HQLODSAC2();
        TimeOfdayAC2();
        ShadowResolutionAC2();
        ImGui::TreePop();
    }

    if (ImGui::CollapsingHeader("Camera"))
    {
        ImGui::TreePush("CameraTree");
        CameraFOVAC2();
        ImGui::TreePop();
    }
    
    if (ImGui::CollapsingHeader("Player"))
    {
        ImGui::TreePush("PlayerTree"); 
        ImGui::Checkbox("Show separate Player Info window.", &ShowPlayerInfoWindowAC2);
        if (!ShowPlayerInfoWindowAC2)
        {
            PlayerPosAC2();
            PlayerSpeedAC2();
        }
        PlayerScaleAC2();
        ImGui::TreePop();
    }

    if (ImGui::CollapsingHeader("Inventory"))
    {
        ImGui::TreePush("InventoryTree");
        InventoryAC2();
        ImGui::TreePop();

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Inventory Adjustment Amount"))
            {
                EHPlayerInventoryAdjustAmountWindow();
                ImGui::EndMenu();
            }
        }
        ImGui::EndMenuBar();
    }
    ImGui::End();
}