#ifndef WARLOCK_HPP
#define WARLOCK_HPP
// #pragma once

#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
 private:
  std::string name;
  std::string title;
  // new attribute to store the spells
  std::map<std::string, ASpell *> spell_map;

  Warlock();
  Warlock(const Warlock &ref);

  Warlock &operator=(const Warlock &ref);


 public:
  Warlock(const std::string &name, const std::string &title);
  ~Warlock();

  const std::string &getName() const;
  const std::string &getTitle() const;
  void setTitle(const std::string &title);

  void introduce() const;

  void learnSpell(ASpell *aspell_ptr);
  void forgetSpell(std::string name);
  void launchSpell(std::string name, const ATarget &atarget_ref);
};

#endif