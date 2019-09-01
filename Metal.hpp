#ifndef METALH
#define METALH

#include "Material.hpp"

class Metal: public Material {
public:
  Metal(const Vector3& a, float f);
  virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3& attenuation, Ray& scattered) const;

  Vector3 albedo;
  float fuzz;
};

#endif