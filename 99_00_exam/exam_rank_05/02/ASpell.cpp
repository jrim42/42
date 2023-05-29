#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const &name, std::string const &effects) {
  this->name = name;
  this->effects = effects;
}

ASpell::ASpell(ASpell const &ref) { *this = ref; }

ASpell &ASpell::operator=(ASpell const &ref) {
  this->name = ref.name;
  this->effects = ref.effects;
  return (*this);
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const { return (this->name); }

std::string const &ASpell::getEffects() const { return (this->effects); }

void ASpell::launch(ATarget const &atarget_ref) const {
  atarget_ref.getHitBySpell((*this));
}