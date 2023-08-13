#include "Dummy.hpp"

// occf
Dummy::Dummy(): ATarget("Target Practice Dummy") {}
Dummy::~Dummy() {}

// utils
ATarget *Dummy::clone() const { return (new Dummy()); }