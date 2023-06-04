#include <EzioHookMenus.h>
#include <SharedDataTypes.h>
#include <imgui.h>
#include <windows.h>
#include <MemoryHelpers.h>
#include <GetPointer.h>
#include <algorithm>
#include <stdint.h>
void CameraFOVAC2()
{
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
        ImGui::SliderFloat("Camera FOV", (float*)CamFOVResult, 0.001f, 3.14f, NULL, ImGuiSliderFlags_AlwaysClamp);
        float Degrees = *((float*)CamFOVResult) * (180.0f / 3.14159265359f);;
        ImGui::Text("Camera FOV (In Degrees): %f", *(float*)&Degrees);
        if (ImGui::Button("Restore default FOV"))
        {
            *((float*)CamFOVResult) = 0.8072147965f;
        }
    }
}