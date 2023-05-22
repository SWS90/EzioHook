#include <EzioHookMenus.h>
#include <SharedDataTypes.h>
#include <imgui.h>
#include <windows.h>
#include <MemoryHelpers.h>
#include <stdint.h>
void TimeOfdayAC2()
{
    if (!FreezeTimeOfDayAC2)
    {
        ImGui::SliderFloat("TimeOfDay", (float*)0x020EF7F8, 0.0f, 24.0f);
        ImGui::SameLine();
    }
    ImGui::Checkbox("PauseToD", &FreezeTimeOfDayAC2);
    if (FreezeTimeOfDayAC2)
    {
        float TimeOfDay = *((float*)0x020EF7F8);
        WRITE_MEMORY(0x020EF7F8, float, EHFrozenTime);
        FreezeTimeOfDayAC2 = true;
    }
    if (!FreezeTimeOfDayAC2)
    {
        EHFrozenTime = *((float*)0x020EF7F8);
    }
}
