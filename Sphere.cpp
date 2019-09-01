#include "Sphere.hpp"
#include <math.h>

bool Sphere::hit(const Ray& r, float t_min, float t_max, hit_record& rec) const {
  Vector3 oc = r.origin() - center;
  float a = dot(r.direction(), r.direction());
  float b = dot(oc, r.direction());
  float c = dot(oc, oc) - radius * radius;
  float discriminat = b * b - a * c;

  if(discriminat > 0) {
    float temp = (-b - sqrt(discriminat)) / a;

    if(temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = r.point_at_parameter(temp);
      rec.normal = (rec.p - center) / radius;
      rec.mat_ptr = material;
      return true;
    }
    
    temp = (-b + sqrt(discriminat)) / a;
    if(temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = r.point_at_parameter(temp);
      rec.normal = (rec.p - center) / radius;
      rec.mat_ptr = material;
      return true;
    }

  }

  return false;
}