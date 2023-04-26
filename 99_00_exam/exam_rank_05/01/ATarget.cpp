#include "ATarget.hpp"

#include "ASpell.hpp"

// occf
ATarget::ATarget() {}

ATarget::ATarget(const std::string &type) { this->type = type; }

ATarget::ATarget(const ATarget &other) { *this = other; }

ATarget::~ATarget() {}

ATarget &ATarget::operator=(const ATarget &other) {
  this->type = other.type;
  return (*this);
}

// getter
const std::string &ATarget::getType() const { return (this->type); }

// utils
void ATarget::getHitBySpell(const ASpell &aspell_ref) const {
  std::cout << this->type << " has been " << aspell_ref.getEffects() << "!\n";
}