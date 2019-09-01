#ifndef LAMBERTIANH
#define LAMBERTIANH

#include "Material.hpp"

class Lambertian: public Material {
public:
  Lambertian(const Vector3 a);
  virtual bool scatter(const Ray& r_in, const hit_record& rec, Vector3& attenuation, Ray& scattered) const;

  Vector3 albedo;
};

#endif
