//
// Created by bytenol on 12/23/25.
//

#ifndef ZEPHYRUS_VEC2_H
#define ZEPHYRUS_VEC2_H

#include <cmath>

namespace zpy {

    struct Vec2;

    Vec2 operator*(const float &lhs, const Vec2 &rhs);

    class Vec2 {
    public:
        float x, y;

        explicit Vec2(const float& x = 0, const float& y = 0) : x(x), y(y) {}

        Vec2 operator+(const Vec2& rhs) const;

        Vec2 operator-(const Vec2& rhs) const;

        Vec2& operator+=(const Vec2& rhs);

        Vec2& operator-=(const Vec2& rhs);

        Vec2 operator*(const float& rhs) const;

        Vec2& operator*=(const float& rhs);

        Vec2 normalize() const;

        float dot(const Vec2& rhs) const;

        float magnitude() const;

        static Vec2 fromAngle(const float& angle);
    };

    class MyClass {
    public:
        MyClass(int value) : value(value) {}
        void setValue(int v) { value = v; }
        int getValue() const { return value; }
    private:
        int value;
    };

}

#endif //ZEPHYRUS_VEC2_H