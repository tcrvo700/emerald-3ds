#ifndef CTR_PK_ENCOUNTER_H
#define CTR_PK_ENCOUNTER_H

/*
 * PK ENCOUNTER (OPTIONS, MODES): pick one Pokemon and, while the switch is ON,
 * every wild Pokemon the game generates is that one (grass, caves, surfing,
 * fishing, the visible wild ones, the encounter previews). OFF: the game's own
 * encounters, exactly as before; the chosen Pokemon is only remembered.
 *
 * Two settings.txt keys, both optional:
 *   pk_enc       0 (default) or 1
 *   pk_species   the game's internal species id (default 277, Treecko)
 *
 * The hook is CtrRandomizer_Species (src/3ds_randomizer.c): the game already
 * asks it for the species of every wild Pokemon of the map's tables.
 *
 * SDK-free: only plain integers cross this header.
 */
#include <stdbool.h>
#include <stdint.h>

/* Whether the switch is ON. */
bool CtrPkEncounter_Enabled(void);
/* The chosen species; always a real one (Treecko if the setting is not). */
uint16_t CtrPkEncounter_Species(void);

/* For the OPTIONS cell of the chosen Pokemon (include/3ds_pk_encounter_extras.inc). */
void CtrPkEncounter_Step(int direction);
const uint8_t *CtrPkEncounter_Text(void);

#endif // CTR_PK_ENCOUNTER_H
