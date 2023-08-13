#include "BrickWall.hpp"

// occf
BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}
BrickWall::~BrickWall() {}

// utils
ATarget *BrickWall::clone() const { return (new BrickWall()); }