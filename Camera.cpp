#include "Camera.hpp"
#include <math.h>

Camera::Camera(Vector3 lookfrom, Vector3 lookat, Vector3 vup, float vfov, float aspect) {
  Vector3 u, v , w;
  float theta = vfov * M_PI / 180;
  float half_height = tan(theta / 2);
  float half_width = aspect * half_height;

  origin = lookfrom;
  w = unit_vector(lookfrom - lookat);
  u = unit_vector(cross(vup, w));
  v = cross(w, u);
  lower_left_corner = origin - half_width * u - half_height * v - w;
  horizontal = 2.0 * half_width * u;
  vertical = 2.0 * half_height * v;
}

Ray Camera::get_ray(float u, float v) {
  return Ray(origin, lower_left_corner + u * horizontal + v * vertical);
}

Vector3 random_in_unit_disk() {
  Vector3 p;

  do {
    p = 2.0 * Vector3(drand48(), drand48(), 0) - Vector3(1.0, 1.0, 0.0);
  } while (dot(p, p) >= 1.0);

  return p;
}