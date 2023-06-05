#include <EzioHookToolTips.h>
#include <imgui.h>
void EHToolTip_HQLODSAC2()
{
	ImGui::SetTooltip("Based on Bucket5's 'Assassin's Creed 2 Visual Fixup Mod'<https://www.moddb.com/mods/assassins-creed-2-visual-fixup-mod>\nThis will force all buildings to use the highest level-of-detail models available.");
}
void EHToolTip_PlayerScaleWarning()
{
	ImGui::SetTooltip("Having a different scale other than the default of 1 when entering certain events (for example crowd blending)\nWill automatically resize the player to default.\nHowever leaving the event will resize the player to the previous set scale.\nAttemping to scale the player down after this will result in a incorrect looking/acting player.\nYou must return to the title screen and reload your save to fix this!");
}