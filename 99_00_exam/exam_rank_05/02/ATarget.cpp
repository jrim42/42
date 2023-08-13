#include "ATarget.hpp"
#include "ASpell.hpp"

// occf
ATarget::ATarget() {}

ATarget::ATarget(const std::string &type) { this->type = type; }

ATarget::ATarget(const ATarget &ref) { *this = ref; }

ATarget &ATarget::operator=(const ATarget &ref) {
  this->type = ref.type;
  return (*this);
}

ATarget::~ATarget() {}

// getter
const std::string &ATarget::getType() const { return (this->type); }

// utils
void ATarget::getHitBySpell(const ASpell &aspell_ref) const {
  std::cout << this->type << " has been " << aspell_ref.getEffects() << "!\n";
}