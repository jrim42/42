#pragma once

#include <map>

#include "ATarget.hpp"

class TargetGenerator {
 private:
  std::map<std::string, ATarget *> target_map;

  TargetGenerator(TargetGenerator const &ref);
  TargetGenerator &operator=(TargetGenerator const &ref);

 public:
  TargetGenerator();
  ~TargetGenerator();

  void learnTargetType(ATarget *target_ptr);
  void forgetTargetType(std::string const &name);
  ATarget *createTarget(std::string const &name);
};