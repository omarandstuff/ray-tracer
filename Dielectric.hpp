#ifndef DIELECTRICH
#define DIELECTRICH

#include "Material.hpp"

class Dielectric: public Material {
public:
  Dielectric(float ri);
  virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3& attenuation, Ray& scattered) const;

  float ref_idx;
};

#endif