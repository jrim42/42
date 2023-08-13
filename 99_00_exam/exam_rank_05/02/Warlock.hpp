#pragma once

#include <iostream>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock {
 private:
  std::string name;
  std::string title;
  SpellBook book;

  Warlock();
  Warlock(Warlock const &ref);
  Warlock &operator=(Warlock const &ref);

 public:
  Warlock(std::string const &name, std::string const &title);
  ~Warlock();

  std::string const &getName() const;
  std::string const &getTitle() const;

  void setTitle(std::string const &title);

  void introduce() const;

  void learnSpell(ASpell *aspell_ptr);
  void forgetSpell(std::string spell_name);
  void launchSpell(std::string spell_name, ATarget const &atarget_ref);
};