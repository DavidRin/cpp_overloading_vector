#include "vector.hpp"
#include <cmath>



geometry::Vector geometry::Vector::cross(const Vector &other) const{
    double xs = y* other.z - z *other.y;
    double ys = z * other.x - x * other.z ;
    double zs = x* other.y - y * other.x;

    return Vector(xs,ys,zs);

}

geometry::Vector geometry::Vector::operator*(double scalar) const{
    double xs = x * scalar;
    double ys = y * scalar;
    double zs = z * scalar;

    return Vector(xs,ys,zs);

}

geometry::Vector  geometry::operator*(double scalar, const Vector &v){
    double xs = v.x * scalar;
    double ys = v.y * scalar;
    double zs = v.z * scalar;

    return Vector(xs,ys,zs);


}

 std::ostream &  geometry::operator<<(std::ostream &out, const Vector &v){
    
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";

    return out;
 }

 //./vector_test