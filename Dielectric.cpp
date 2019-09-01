#include "Dielectric.hpp"

float schlick(float cosine, float ref_idx) {
  float r0 = (1.0 - ref_idx) / (1.0 + ref_idx);
  r0 = r0 * r0;
  return r0 + (1.0 - r0) * pow((1.0 - cosine), 5);
}

Dielectric::Dielectric(float ri): ref_idx(ri) {}

bool Dielectric::scatter(const Ray& r_in, const hit_record& rec, Vector3& attenuation, Ray& scattered) const {
  Vector3 outward_normal;
  Vector3 reflected = reflect(r_in.direction(), rec.normal);
  float ni_over_nt;
  attenuation = Vector3(1.0, 1.0, 1.0);
  Vector3 refracted;
  float reflect_prob;
  float cosine;

  if(dot(r_in.direction(), rec.normal) > 0) {
    outward_normal = -rec.normal;
    ni_over_nt = ref_idx;
    cosine = ref_idx * dot(r_in.direction(), rec.normal) / r_in.direction().length();
  } else {
    outward_normal = rec.normal;
    ni_over_nt = 1.0 / ref_idx;
    cosine = -dot(r_in.direction(), rec.normal) / r_in.direction().length();
  }

  if(refract(r_in.direction(), outward_normal, ni_over_nt, refracted)) {
    reflect_prob = schlick(cosine, ref_idx);
  } else {
    scattered = Ray(rec.p, reflected);
    reflect_prob = 1.0;
  }

  if(drand48() < reflect_prob) {
    scattered = Ray(rec.p, reflected);
  } else {
    scattered = Ray(rec.p, refracted);
  }

  return true;
}