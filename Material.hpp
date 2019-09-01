#ifndef MATERIALH
#define MATERIALH

#include "Ray.hpp"
#include <stdlib.h>
#include <math.h>

struct hit_record;

class Material {
public:
  virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3& attenuation, Ray& scattered) const = 0;
};

struct hit_record {
  float t;
  Vector3 p;
  Vector3 normal;
  Material *mat_ptr;
};

Vector3 random_in_unit_sphere();

bool refract(const Vector3& v, const Vector3& n, float ni_over_nt, Vector3& refracted);
Vector3 reflect(const Vector3& v, const Vector3& n);


#endif