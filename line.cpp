#include "line.h"
#include<QDebug>
using namespace std;
Line::Line()
{
    this->a = 0;
    this->b = 0;
    this->c = 0;
    this->x1=0;
    this->y1=0;
    this->x2=0;
    this->y2=0;
}

Line::Line(double x1, double y1, double x2, double y2)
{
    //Use (x1,y1) and (x2,y2) to construct a line ax + by + c = 0

    this->x1=x1;
    this->y1=y1;
    this->x2=x2;
    this->y2=y2;

    if(fabs(x1-x2) < 1e-8){
        //Vertical line : x = x1;
        this->a = 1;
        this->b = 0;
        this->c = (-1)*x1;
    }
    else{
        this->a = (y1-y2)/(x2-x1);
        this->b = 1;
        this->c = (-1)*(a*x1+b*y1);
    }
}

bool Line::find_intersect(Line m, Line n, double &inter_x, double &inter_y)
{
    //Use Cramer's rule to fine intersection

    if(fabs(m.x1-m.x2)<1e-8 && fabs(m.y1-m.y2)<1e-8){
        return false;//Same point;
    }
    else if(fabs(n.x1-n.x2)<1e-8 && fabs(n.y1-n.y2)<1e-8){
        return false;//Same point;
    }

    double determinant = m.a*n.b - m.b*n.a;
    //qDebug()<<"determinant = "<<determinant;

    if(fabs(determinant) < 1e-8)//no solution
        return false;

    inter_x = (n.c*m.b - m.c*n.b) / determinant;
    inter_y = (n.a*m.c - m.a*n.c) / determinant;

    return true;
}
