#ifndef CAMERAH
#define CAMERAH
#include "Ray.hpp"
#include <stdlib.h>

Vector3 random_in_unit_disk();

class Camera {
public:
  Camera(Vector3 lookfrom, Vector3 lookat, Vector3 vup, float vfov, float aspect);
  Ray get_ray(float u, float v);

  Vector3 origin;
  Vector3 lower_left_corner;
  Vector3 horizontal;
  Vector3 vertical;
};

#endif