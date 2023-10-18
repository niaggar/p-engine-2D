#include "Vect2.h"

Vect2::Vect2() {
    this->x = 0;
    this->y = 0;
}

Vect2::Vect2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vect2::Vect2(const Vect2 &vect2) {
    this->x = vect2.x;
    this->y = vect2.y;
}

Vect2 Vect2::operator+(const Vect2 &vect2) const {
    return {this->x + vect2.x, this->y + vect2.y};
}

Vect2 Vect2::operator-(const Vect2 &vect2) const {
    return {this->x - vect2.x, this->y - vect2.y};
}

Vect2 Vect2::operator*(const float &scalar) const {
    return {this->x * scalar, this->y * scalar};
}

Vect2 Vect2::operator/(const float &scalar) const {
    return {this->x / scalar, this->y / scalar};
}

Vect2& Vect2::operator+=(const Vect2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vect2& Vect2::operator-=(const Vect2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vect2 &Vect2::operator*=(const float &scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vect2 &Vect2::operator/=(const float &scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}
