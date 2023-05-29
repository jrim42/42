#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
  std::map<std::string, ATarget *>::iterator it_begin =
      this->target_map.begin();
  std::map<std::string, ATarget *>::iterator it_end = this->target_map.end();
  while (it_begin != it_end) {
    delete it_begin->second;
    ++it_begin;
  }
  this->target_map.clear();
}

void TargetGenerator::learnTargetType(ATarget *target_ptr) {
  if (target_ptr)
    // target_map.insert(std::pair<std::string, ATarget *>(target_ptr->getType(), target_ptr->clone()));
    this->target_map[target_ptr->getType()] = target_ptr->clone();
}

void TargetGenerator::forgetTargetType(const std::string &target_name) {
  std::map<std::string, ATarget *>::iterator it = target_map.find(target_name);

  if (it != target_map.end()) 
    delete it->second;
  target_map.erase(target_name);
}

ATarget *TargetGenerator::createTarget(const std::string &target_name) {
  std::map<std::string, ATarget *>::iterator it = target_map.find(target_name);

  if (it != target_map.end())
    return target_map[target_name];
  return NULL;
}
