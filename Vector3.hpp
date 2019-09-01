class Vector3 {
public:
  Vector3() {}
  Vector3(float e0, float e1, float e2);
  float x() const;
  float y() const;
  float z() const;
  float r() const;
  float g() const;
  float b() const;

  const Vector3& operator+() const;
  Vector3 operator-() const;
  float operator[](int i) const { return e[i]; }
  float& operator[](int i) { return e[i]; }

  Vector3& operator+=(const Vector3 &v);
  Vector3& operator-=(const Vector3 &v);
  Vector3& operator*=(const Vector3 &v);
  Vector3& operator/=(const Vector3 &v);
  Vector3& operator*=(const float t);
  Vector3& operator/=(const float t);

  float length() const;
  float squared_length() const;
  void make_unit_vetor();

  float e[3];
};

Vector3 operator+(const Vector3 &v1, const Vector3 &v2);
Vector3 operator-(const Vector3 &v1, const Vector3 &v2);
Vector3 operator*(const Vector3 &v1, const Vector3 &v2);
Vector3 operator/(const Vector3 &v1, const Vector3 &v2);
Vector3 operator*(float t, const Vector3 &v);
Vector3 operator/(const Vector3 &v, float t);
float dot(const Vector3 &v1, const Vector3 &v2);
Vector3 cross(const Vector3 &v1, const Vector3 &v2);
Vector3 unit_vector(Vector3 v);
