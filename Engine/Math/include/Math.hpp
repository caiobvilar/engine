#ifndef MATH_HPP
#define MATH_HPP
#include <glm/glm.hpp>

class Vec2D
{
  public:
    Vec2D();
    ~Vec2D();

    void
    SetVec2(float, float);
    glm::vec2
    GetVec2() const;

    void
    operator+=(const Vec2D& other);
    void
    operator-=(const Vec2D& other);
    Vec2D
    operator+(const Vec2D& other) const;
    Vec2D
    operator-(const Vec2D& other) const;
    Vec2D
    operator*(float scalar) const;
    Vec2D
    operator/(float scalar) const;
    void
    operator*=(float scalar);
    void
    operator/=(float scalar);
    void
    normalize();
    float
    GetLength() const;

  private:
    glm::vec2 vec;
};
#endif // MATH_HPP