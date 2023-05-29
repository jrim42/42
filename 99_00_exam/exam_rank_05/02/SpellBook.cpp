#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
  std::map<std::string, ASpell *>::iterator it_begin = this->spell_map.begin();
  std::map<std::string, ASpell *>::iterator it_end = this->spell_map.end();

  while (it_begin != it_end) {
    delete it_begin->second;
    ++it_begin;
  }
  this->spell_map.clear();
}

void SpellBook::learnSpell(ASpell *spell_ptr) {
  if (spell_ptr)
    // spell_map.insert(std::pair<std::string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
    this->spell_map[spell_ptr->getName()] = spell_ptr->clone();
}

void SpellBook::forgetSpell(std::string const &spell_name) {
  std::map<std::string, ASpell *>::iterator it = spell_map.find(spell_name);

  if (it != spell_map.end()) 
    delete it->second;
  spell_map.erase(spell_name);
}

ASpell *SpellBook::createSpell(std::string const &spell_name) {
  std::map<std::string, ASpell *>::iterator it = spell_map.find(spell_name);

  if (it != spell_map.end()) 
    return spell_map[spell_name];
  return NULL;
}
