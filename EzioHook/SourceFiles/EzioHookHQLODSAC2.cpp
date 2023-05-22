#include <EzioHookMenus.h>
#include <SharedDataTypes.h>
#include <imgui.h>
#include <windows.h>
#include <MemoryHelpers.h>
#include <stdint.h>
void HQLODSAC2()
{
    ImGui::Checkbox("Force HQ LODs", &ForceHQLODS);
    ImGui::SameLine();
    ImGui::Text("(?)");
    if (ImGui::IsItemHovered()) { ImGui::SetTooltip("Based on Bucket5's 'Assassin's Creed 2 Visual Fixup Mod'<https://www.moddb.com/mods/assassins-creed-2-visual-fixup-mod>\nThis will force all buildings to use the highest level-of-detail models available."); }

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
        WRITE_MEMORY(0x015BFE8C, byte, 0x8B, 0x45, 0xF0);
        WRITE_MEMORY(0x015BFE8F, byte, 0x8A, 0x4B, 0x28);
        // Revert "Disable LOD transitions"
        WRITE_MEMORY(0x015BFD89, uint8_t, 0x25, 0xFF, 0x3F, 0x00, 0x00);
        WRITE_MEMORY(0x015BFD8E, uint8_t, 0x0F, 0xB6, 0x04, 0x10);
        WRITE_MEMORY(0x015BFD92, uint8_t, 0x85, 0xC0);
        WRITE_MEMORY(0x015BFD94, uint8_t, 0x89, 0x45, 0xD8);
        WRITE_MEMORY(0x015BFD97, uint8_t, 0x0F, 0x84, 0x9C, 0x00, 0x00, 0x00);
        ForceHQLODSActive = false;
    }
}