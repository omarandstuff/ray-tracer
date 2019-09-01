#include <iostream>
#include <fstream>
#include <math.h>
#include <float.h>
#include "Sphere.hpp"
#include "HitableList.hpp"
#include "Camera.hpp"

Vector3 get_color(const Ray &r, Hitable *world, int depth) {
  hit_record rec;

  if(world->hit(r, 0.001, MAXFLOAT, rec)) {
    Ray scattered;
    Vector3 attenuation;

    if(depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
      return attenuation * get_color(scattered, world, depth + 1);
    } else {
      return Vector3(0.0, 0.0, 0.0);
    }
  } else {
    Vector3 unit_direction = unit_vector(r.direction());
    float t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * Vector3(1.0, 1.0, 1.0) + t * Vector3(0.5, 0.7, 1.0);
  }
}

int main() {
  int nx = 600;
  int ny = 300;
  int ns = 64;

  std::ofstream file_stream;
  file_stream.open ("render.ppm");

  file_stream << "P3\n" << nx << " " << ny << "\n255\n";

  Hitable *list[5];
  list[0] = new Sphere(Vector3(0.0, 0.0, -1.0), 0.5, new Lambertian(Vector3(0.8, 0.3, 0.3)));
  list[1] = new Sphere(Vector3(0.0, -100.5, -1.0), 100, new Lambertian(Vector3(0.4, 0.4, 0.4)));
  list[2] = new Sphere(Vector3(1.0, 0.0, -1.0), 0.5, new Metal(Vector3(1, 1, 1), 0.8));
  list[3] = new Sphere(Vector3(-1.0, 0.0, -1.0), 0.5, new Dielectric(1.5));
  list[4] = new Sphere(Vector3(-1.0, 0.0, -1.0), 0.45, new Dielectric(1.5));

  Hitable *world = new HitableList(list, 5);

  Camera cam(Vector3(0, 0.5, 0.5), Vector3(0, 0, -1), Vector3(0, 1, 0), 90, float(nx) / float(ny));

  for(int j = ny - 1; j >= 0; j--) {
    for(int i = 0; i < nx; i++) {
      Vector3 color(0.0, 0.0, 0.0);

      for(int s = 0; s < ns; s++) {
        float u = float(i + drand48()) / float(nx);
        float v = float(j + drand48()) / float(ny);

        Ray r = cam.get_ray(u, v);
        Vector3 p = r.point_at_parameter(2.0);
        color += get_color(r, world, 0);
      }

      color /= float(ns);
      color = Vector3(sqrt(color[0]), sqrt(color[1]), sqrt(color[2]));

      int ir = int(255.0 * color[0]);
      int ig = int(255.0 * color[1]);
      int ib = int(255.0 * color[2]);

      file_stream << ir << " " << ig << " " << ib << "\n";
    }
  }

  file_stream.close();
}