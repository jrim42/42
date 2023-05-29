#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>

class ATarget;

class ASpell {
 private:
  std::string name;
  std::string effects;

 public:
  ASpell();
  ASpell(const std::string &name, const std::string &effects);
  ASpell(const ASpell &ref);
  // abstract class
  virtual ~ASpell();

  ASpell &operator=(const ASpell &ref);

  const std::string &getName() const;
  const std::string &getEffects() const;

  void launch(const ATarget &atarget_ref) const;

  // pure method
  virtual ASpell *clone() const = 0;
};

#endif
