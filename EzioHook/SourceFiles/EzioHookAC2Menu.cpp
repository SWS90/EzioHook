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
        if (ShowEzioConfigWindow) 
        { 
            ImGui::SetNextWindowBgAlpha(EHWindowAlpha); 
            ImGui::Begin("EzioHookConfig", &ShowEzioConfigWindow, ImGuiWindowFlags_AlwaysAutoResize);
            EzioHookConfig(&ShowEzioConfigWindow);
        }
        if (ShowEzioCreditsWindow) 
        { 
            ImGui::SetNextWindowBgAlpha(EHWindowAlpha);
            ImGui::Begin("EzioHookCredits", &ShowEzioCreditsWindow, ImGuiWindowFlags_AlwaysAutoResize);
            EzioHookCredits(&ShowEzioCreditsWindow);
        }
        
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("View"))
            {
                ImGui::MenuItem("Config", NULL, &ShowEzioConfigWindow);
                ImGui::Separator();
                ImGui::MenuItem("Credits", NULL, &ShowEzioCreditsWindow);
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
    }
    ImGui::End();
}