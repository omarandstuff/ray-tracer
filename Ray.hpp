#ifndef RAYH
#define RAYH
#include "Vector3.hpp"

class Ray {
public:
  Ray() {}
  Ray(const Vector3 &a, const Vector3 &b);

  Vector3 origin() const;
  Vector3 direction() const;
  Vector3 point_at_parameter(float t) const;

  Vector3 A;
  Vector3 B;
};

#endif