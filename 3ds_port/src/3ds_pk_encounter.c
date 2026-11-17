/*
 * PK ENCOUNTER, the game's side (include/3ds_pk_encounter.h): the two
 * settings, the chosen Pokemon and the OPTIONS cell that steps through them.
 * Both settings are read straight from settings.txt, so it is all off until
 * the player turns it on.
 */
#include "global.h"
#include "data.h"
#include "pokemon.h"
#include "string_util.h"
#include "constants/species.h"
#include "3ds_platform.h"
#include "3ds_randomizer.h"
#include "3ds_pk_encounter.h"

#define PK_ENC_KEY "pk_enc"
#define PK_SPECIES_KEY "pk_species"

bool CtrPkEncounter_Enabled(void)
{
    return CtrSettings_GetInt(PK_ENC_KEY, 0) == 1;
}

uint16_t CtrPkEncounter_Species(void)
{
    int species = CtrSettings_GetInt(PK_SPECIES_KEY, SPECIES_TREECKO);

    if (species > 0 && species <= SPECIES_CHIMECHO && CtrRandomizer_SpeciesEligible((uint16_t)species))
        return (uint16_t)species;
    return SPECIES_TREECKO;
}

/* One Pokemon forward or back, in the game's own order (the first two
 * generations, then Hoenn's), skipping ids that are not real species (the
 * old Unown block), and wrapping round. */
void CtrPkEncounter_Step(int direction)
{
    uint16_t species = CtrPkEncounter_Species();

    for (uint16_t tries = 0; tries <= SPECIES_CHIMECHO; tries++)
    {
        if (direction < 0)
            species = species <= 1 ? SPECIES_CHIMECHO : species - 1;
        else
            species = species >= SPECIES_CHIMECHO ? 1 : species + 1;
        if (CtrRandomizer_SpeciesEligible(species))
            break;
    }
    CtrSettings_SetInt(PK_SPECIES_KEY, species);
}

/* The chosen Pokemon's name, in the game's characters. */
const uint8_t *CtrPkEncounter_Text(void)
{
    static u8 name[POKEMON_NAME_LENGTH + 1];

    StringCopy(name, gSpeciesNames[CtrPkEncounter_Species()]);
    return name;
}
