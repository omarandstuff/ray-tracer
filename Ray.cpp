#include "Ray.hpp"

Ray::Ray(const Vector3 &a, const Vector3 &b) {
  A = a;
  B = b;
}

Vector3 Ray::origin() const {
  return A;
}

Vector3 Ray::direction() const {
  return B;
}

Vector3 Ray::point_at_parameter(float t) const {
  return A + t * B;
}