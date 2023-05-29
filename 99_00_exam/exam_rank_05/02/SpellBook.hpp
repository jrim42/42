#pragma once

#include <map>

#include "ASpell.hpp"

class SpellBook {
 private:
  std::map<std::string, ASpell *> spell_map;

  SpellBook(SpellBook const &ref);
  SpellBook &operator=(SpellBook const &ref);

 public:
  SpellBook();
  ~SpellBook();

  void learnSpell(ASpell *aspell_ptr);
  void forgetSpell(std::string const &name);
  ASpell *createSpell(std::string const &name);
};