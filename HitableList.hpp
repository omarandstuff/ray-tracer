#ifndef HITABLELISTH
#define HITABLELISTH

#include "Hitable.hpp"

class HitableList: public Hitable {
public:
  HitableList() {}
  HitableList(Hitable **l, int n);
  virtual bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) const;

  Hitable** list;
  int list_size;
};

#endif