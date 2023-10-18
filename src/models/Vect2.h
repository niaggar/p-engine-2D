#ifndef P_ENGINE_2D_VECT2_H
#define P_ENGINE_2D_VECT2_H


class Vect2 {
public:
    float x;
    float y;

    Vect2();
    Vect2(float x, float y);
    Vect2(const Vect2 &vect2);

    Vect2 operator+(const Vect2 &vect2) const;
    Vect2 operator-(const Vect2 &vect2) const;
    Vect2 operator*(const float &scalar) const;
    Vect2 operator/(const float &scalar) const;
    Vect2& operator+=(const Vect2& other);
    Vect2& operator-=(const Vect2& other);
    Vect2& operator*=(const float& scalar);
    Vect2& operator/=(const float& scalar);
};


#endif //P_ENGINE_2D_VECT2_H
