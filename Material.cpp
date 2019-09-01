#include "Material.hpp"

Vector3 random_in_unit_sphere() {
  Vector3 p;

  do {
    p = 2.0 * Vector3(drand48(), drand48(), drand48()) - Vector3(1.0, 1.0, 1.0);
  } while (p.squared_length() >= 1.0);
  
  return p;
}

bool refract(const Vector3& v, const Vector3& n, float ni_over_nt, Vector3& refracted) {
  Vector3 uv = unit_vector(v);
  float dt = dot(uv, n);
  float discriminant = 1.0 - ni_over_nt * ni_over_nt * (1.0 - dt * dt);
  if(discriminant > 0) {
    refracted = ni_over_nt * (uv - dt * n) - sqrt(discriminant) * n;
    return true;
  }

  return false;
}

Vector3 reflect(const Vector3& v, const Vector3& n) {
  return v - 2.0 * dot(v, n) * n;
}

