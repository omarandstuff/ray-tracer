#ifndef HITABLEH
#define HITABLEH
#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Dielectric.hpp"

class Hitable {
public:
  virtual bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif