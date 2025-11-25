#include "Math.hpp"

Vec2D::~Vec2D()
{
    this->vec = glm::vec2(0.0f, 0.0f);
}

Vec2D::Vec2D()
{
    this->vec = glm::vec2(0.0f, 0.0f);
}

void
Vec2D::SetVec2(float x, float y)
{
    vec = glm::vec2(x, y);
}

glm::vec2
Vec2D::GetVec2() const
{
    return vec;
}

void
Vec2D::normalize()
{
    this->vec = glm::normalize(this->vec);
}

float
Vec2D::GetLength() const
{
    return glm::length(this->vec);
}

void
Vec2D::operator+=(const Vec2D& other)
{
    this->vec += other.vec;
}

void
Vec2D::operator-=(const Vec2D& other)
{
    this->vec -= other.vec;
}

Vec2D
Vec2D::operator+(const Vec2D& other) const
{
    Vec2D result;
    result.vec = this->vec + other.vec;
    return result;
}

Vec2D
Vec2D::operator-(const Vec2D& other) const
{
    Vec2D result;
    result.vec = this->vec - other.vec;
    return result;
}

Vec2D
Vec2D::operator*(float scalar) const
{
    Vec2D result;
    result.vec = this->vec * scalar;
    return result;
}

Vec2D
Vec2D::operator/(float scalar) const
{
    Vec2D result;
    result.vec = this->vec / scalar;
    return result;
}

void
Vec2D::operator*=(float scalar)
{
    this->vec *= scalar;
}

void
Vec2D::operator/=(float scalar)
{
    this->vec /= scalar;
}