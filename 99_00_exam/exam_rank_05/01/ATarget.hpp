#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>

class ASpell;

class ATarget {
 private:
  std::string type;

 public:
  ATarget();
  ATarget(const std::string &type);
  ATarget(const ATarget &ref);
  virtual ~ATarget();

  ATarget &operator=(const ATarget &ref);

  const std::string &getType() const;

  void getHitBySpell(const ASpell &aspell_ref) const;

  virtual ATarget *clone() const = 0;
};

#endif
