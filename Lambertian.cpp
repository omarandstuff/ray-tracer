#include "Lambertian.hpp"

Lambertian::Lambertian(const Vector3 a): albedo(a) {}

bool Lambertian::scatter(const Ray& r_in, const hit_record& rec, Vector3& attenuation, Ray& scattered) const {
  Vector3 target = rec.p + rec.normal + random_in_unit_sphere();

  scattered = Ray(rec.p, target - rec.p);
  attenuation = albedo;

  return true;
}