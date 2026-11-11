#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <cmath>

namespace geometry
{
    class Vector
    {
    public:
        double x{0.0};
        double y{0.0};
        double z{0.0};

        // Vector();
        explicit Vector(double xn = 0.0, double yn = 0.0, double zn = 0.0) : x{xn}, y{yn}, z{zn} {}
        double dot(const Vector &other) const{

            return (x * other.x) +(y * other.y) +(z * other.z);
        }
        double length()const{

            return std::sqrt(x*x + y*y + z*z) ;
        }
        double magnitude()const{

            return length();
        }
        Vector cross(const Vector &other) const;

        Vector operator+(const Vector &second) const
        {
            return Vector(x + second.x , y + second.y ,  z + second.z);
        }
        Vector operator-(const Vector &second) const
         {
            return Vector(x - second.x , y - second.y ,  z - second.z);
        }
        
        double operator*(const Vector &second) const{
            return dot(second);
        } // dot product
        Vector operator*(double scalar) const;   // scalar multiplication

        friend Vector operator*(double scalar, const Vector &v); // scalar multiplication
        friend std::ostream &operator<<(std::ostream &out, const Vector &v);

    private:
       
    };

    Vector operator*(double scalar, const Vector &v); // scalar multiplication
    std::ostream &operator<<(std::ostream &out, const Vector &v);
}

#endif // VECTOR_HPP


