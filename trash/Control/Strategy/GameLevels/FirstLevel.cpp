#include "FirstLevel.h"

Field *FirstLevel::generate_level(int width, int height) {
    FieldGenerator<RuleSpawnKeys<22>,
                   RuleSpawnPlayer<5, 5>,
                   RuleSpawnEventField<SetWalls, 4>,
                   RuleSpawnWalls<13>,
                   RuleSpawnTrap<14, 1, 5>,
                   RuleSpawnEventPlayer<Box, 66>,
                   RuleSpawnEventPlayer<Heal, 17>> gen;

    return gen.fill(width, height);
}
