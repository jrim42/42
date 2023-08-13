#include "Fireball.hpp"

// occf
Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}
Fireball::~Fireball() {}

// utils
ASpell *Fireball::clone() const { return (new Fireball()); }