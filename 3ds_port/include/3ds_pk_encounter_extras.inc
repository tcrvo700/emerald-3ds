/*
 * PK ENCOUNTER's lines of gCtrExtras (include/3ds_pk_encounter.h, src/3ds_pk_encounter.c),
 * for src/3ds_extras.c, which includes "3ds_pk_encounter.h" at its top and
 * this file inside gCtrExtras, before its terminating {0}. The OPTIONS page
 * shows them in the MODES category (3ds_bottom_options.inc, sRowsPkEncounter):
 * the ON/OFF switch, then the Pokemon (its name between the arrows).
 */
    {CTR_EXTRAS_SCREEN(CTR_EXTRAS_CHEATS, 3), CTR_TEXT("PK ENCOUNTER", "PK ENCUENTRO", "PK RENCONTRE", "PK INCONTRO", "PK ENCONTRO", "PK BEGEGNUNG", "PK エンカウント"), "pk_enc", 2, 0, gCtrExtrasOffOn, NULL, NULL, NULL},
    {CTR_EXTRAS_SCREEN(CTR_EXTRAS_CHEATS, 3), CTR_TEXT("POKEMON", "POKéMON", "POKÉMON", "POKéMON", "POKéMON", "POKéMON", "ポケモン"), "pk_species", 0, 0, NULL, NULL, CtrPkEncounter_Step, CtrPkEncounter_Text},
