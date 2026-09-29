/* Vita build only: the 32-bit sidecar layout assumes these struct sizes. */
#if defined(__vita__)
#include <ultra64.h>
#include <bondtypes.h>
#include "bg.h"
#include "objecthandler.h"

_Static_assert(sizeof(bg_portal_data_entry) == 8, "bg portal entry");
_Static_assert(sizeof(stagesetup) == 40, "stagesetup");
_Static_assert(sizeof(PadRecord) == 44, "PadRecord");
_Static_assert(sizeof(BoundPadRecord) == 68, "BoundPadRecord");
_Static_assert(sizeof(waypoint) == 16, "waypoint");
_Static_assert(sizeof(waygroup) == 12, "waygroup");
_Static_assert(sizeof(PathRecord) == 8, "PathRecord");
_Static_assert(sizeof(AIListRecord) == 8, "AIListRecord");
_Static_assert(sizeof(ObjectRecord) == 128, "ObjectRecord");
_Static_assert(sizeof(DoorRecord) == 256, "DoorRecord");
_Static_assert(sizeof(KeyRecord) == 132, "KeyRecord");
_Static_assert(sizeof(GuardRecord) == 28, "GuardRecord");
_Static_assert(sizeof(SetupIntroCamera) == 40, "SetupIntroCamera");
_Static_assert(sizeof(MonitorObjRecord) == 256, "MonitorObjRecord");
_Static_assert(sizeof(MultiMonitorObjRecord) == 596, "MultiMonitorObjRecord");
_Static_assert(sizeof(VehichleRecord) == 176, "VehichleRecord");
_Static_assert(sizeof(TankRecord) == 224, "TankRecord");
_Static_assert(sizeof(Gfx) == 16, "Gfx slot");
/* Model records: must match recSize() in pcconv_models.c (32-bit column). */
_Static_assert(sizeof(struct ModelNode) == 24, "ModelNode");
_Static_assert(sizeof(struct ModelRoData_HeaderRecord) == 16, "op1");
_Static_assert(sizeof(struct ModelRoData_GroupRecord) == 28, "op2/3");
_Static_assert(sizeof(struct ModelRoData_DisplayListRecord) == 20, "op4");
_Static_assert(sizeof(struct ModelRoData_LODRecord) == 16, "op8");
_Static_assert(sizeof(struct ModelRoData_BSPRecord) == 36, "op9");
_Static_assert(sizeof(struct ModelRoData_BoundingBoxRecord) == 28, "op10");
_Static_assert(sizeof(struct ModelRoData_GunfireRecord) == 40, "op12");
_Static_assert(sizeof(struct ModelRoData_ShadowRecord) == 32, "op13");
_Static_assert(sizeof(struct ModelRoData_InterlinkageRecord) == 28, "op15");
_Static_assert(sizeof(struct ModelRoData_SwitchRecord) == 8, "op18");
_Static_assert(sizeof(struct ModelRoData_GroupSimpleRecord) == 20, "op21");
_Static_assert(sizeof(struct ModelRoData_DisplayListPrimaryRecord) == 16, "op22");
_Static_assert(sizeof(struct ModelRoData_HeadPlaceholderRecord) == 2, "op23");
_Static_assert(sizeof(struct ModelRoData_DisplayList_CollisionRecord) == 32, "op24");
_Static_assert(sizeof(MENU) == 4, "MENU (libultra.c reads it as int)");
_Static_assert(sizeof(struct fontchar) == 24 && sizeof(struct font) == 2932, "font");
_Static_assert(__builtin_offsetof(Gfx, dma.addr) == __builtin_offsetof(Gfx, words.w1), "Gfx dma.addr");
/* Model slot pun must line up with struct Model. */
_Static_assert(sizeof(Model) == 0xBC, "Model");
_Static_assert(sizeof(struct AnimModelSlot) >= sizeof(Model), "AnimModelSlot holds a Model");
_Static_assert(__builtin_offsetof(struct AnimModelSlot, unk02) == __builtin_offsetof(Model, rwdatalen), "slot rwdatalen");
_Static_assert(__builtin_offsetof(struct AnimModelSlot, unk08) == __builtin_offsetof(Model, obj), "slot in-use flag");
_Static_assert(__builtin_offsetof(struct AnimModelSlot, unk10) == __builtin_offsetof(Model, datas), "slot rwdata pool");
_Static_assert(__builtin_offsetof(struct ModelSlot, unk08) == __builtin_offsetof(Model, obj), "mslot in-use flag");
_Static_assert(__builtin_offsetof(struct ModelSlot, unk10) == __builtin_offsetof(Model, datas), "mslot rwdata pool");
_Static_assert(__builtin_offsetof(Model, anim_translation_scale) == 0xB8, "Model.anim_translation_scale");
#endif
