#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock {
 private:
  std::string name;
  std::string title;

  Warlock();
  Warlock(const Warlock &ref);
  Warlock &operator=(const Warlock &ref);

  std::map<std::string, ASpell *> spell_map;

 public:
  Warlock(const std::string &name, const std::string &title);
  ~Warlock();

  const std::string &getName() const;
  const std::string &getTitle() const;

  void setTitle(const std::string &title);

  void introduce() const;

  void learnSpell(ASpell *aspell_ptr);
  void forgetSpell(std::string spell_name);
  void launchSpell(std::string spell_name, const ATarget &atarget_ref);
};

#endif