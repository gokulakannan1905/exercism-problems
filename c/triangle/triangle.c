#include "triangle.h"
bool is_triangle(triangle_t t);
bool is_triangle(triangle_t t){
    return ((t.a + t.b > t.c) && (t.b+t.c > t.a )&& (t.a+t.c>t.b));
}

bool is_scalene(triangle_t triangle){
    if(triangle.a != triangle.b && 
    triangle.b != triangle.c &&
    triangle.c != triangle.a && is_triangle(triangle) ){
        return true;
    }
    return false;
}

bool is_equilateral(triangle_t triangle){
    if(triangle.a == triangle.b && 
    triangle.b == triangle.c &&
    triangle.c == triangle.a && triangle.a != 0 && is_triangle(triangle)){
        return true;
    }
    return false;
}

bool is_isosceles(triangle_t triangle){
    if(!is_scalene(triangle) && is_triangle(triangle)){
        return true;
    }
    return false;
}