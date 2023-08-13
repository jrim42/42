#include "Polymorph.hpp"

// occf
Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}
Polymorph::~Polymorph() {}

// utils
ASpell *Polymorph::clone() const { return (new Polymorph()); }