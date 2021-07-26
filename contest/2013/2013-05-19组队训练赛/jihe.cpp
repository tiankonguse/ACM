struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operate +(Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operate -(Vector A,Vector B)
{
    return Vector(A.x-B.x,A.y-B.y);
}

