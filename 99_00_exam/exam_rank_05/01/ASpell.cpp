#include "ASpell.hpp"

#include "ATarget.hpp"

// occf
ASpell::ASpell() {}

ASpell::ASpell(const std::string &name, const std::string &effects) {
  this->name = name;
  this->effects = effects;
}

ASpell::ASpell(const ASpell &ref) { *this = ref; }

ASpell::~ASpell() {}

ASpell &ASpell::operator=(const ASpell &ref) {
  this->name = ref.name;
  this->effects = ref.effects;
  return (*this);
}

// getter
const std::string &ASpell::getName() const { return (this->name); }
const std::string &ASpell::getEffects() const { return (this->effects); }

// utils
void ASpell::launch(const ATarget &atarget_ref) const {
  atarget_ref.getHitBySpell((*this));
}