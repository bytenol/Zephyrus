#include "../include/zephyrus/core/Vec2.h"

#include <math.h>

zpy::Vec2 zpy::Vec2::operator+(const Vec2 &rhs) const {
    return Vec2(x + rhs.x, y + rhs.y);
}

zpy::Vec2 zpy::Vec2::operator-(const Vec2 &rhs) const {
    return Vec2(x - rhs.x, y - rhs.y);
}

zpy::Vec2 & zpy::Vec2::operator+=(const Vec2 &rhs) {
    return *this = *this + rhs;
}

zpy::Vec2 & zpy::Vec2::operator-=(const Vec2 &rhs) {
    return *this = *this - rhs;
}

zpy::Vec2 zpy::Vec2::operator*(const float &rhs) const {
    return Vec2(x * rhs, y * rhs);
}

zpy::Vec2 & zpy::Vec2::operator*=(const float &rhs) {
    return *this = *this * rhs;
}

zpy::Vec2 zpy::Vec2::normalize() const {
    const float mag = magnitude();
    if (mag == 0.0f)
        return Vec2{ 0, 0 };
    return Vec2{ x / mag, y / mag };
}

float zpy::Vec2::dot(const Vec2 &rhs) const {
    return x * rhs.x + y * rhs.y;
}

float zpy::Vec2::magnitude() const {
    return std::hypot(x, y);
}

zpy::Vec2 zpy::Vec2::fromAngle(const float &angle) {
    constexpr float PI = 3.14159265358979323846;
    const float rad = angle * PI / 180.0f;
    const float x = std::cos(rad * angle);
    const float y = std::sin(rad * angle);
    return Vec2{ x, y };
}
