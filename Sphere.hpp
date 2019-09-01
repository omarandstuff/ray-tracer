#ifndef SPHEREH
#define SPHEREH

#include "Hitable.hpp"

class Sphere: public Hitable {
public:
  Sphere() {}
  Sphere(Vector3 cen, float r, Material* mat): center(cen), radius(r), material(mat) {};
  virtual bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) const;

  Vector3 center;
  float radius;
  Material* material;
};

#endif