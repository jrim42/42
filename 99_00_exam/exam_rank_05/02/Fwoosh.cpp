#include "Fwoosh.hpp"

// occf
Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

// utils
ASpell *Fwoosh::clone() const {
    return (new Fwoosh());
}