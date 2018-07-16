#include "mnkcalculator.h"
#include <QtCore/qmath.h>


QString MnkCalculator::Calculating(SourceData data)
{
    qreal a,b,xsr,ysr,xysr,x2sr;
    int hs=data.xy.size()/2; //setting Loop count
    int i=0;
    while (i<hs){
        xsr=xsr+(data.xy[2*i])/hs;  //x average
        ysr=ysr+(data.xy[2*i+1])/hs; //y average
        xysr=xysr+(data.xy[2*i]*data.xy[2*i+1])/hs; //x*y average
        x2sr=x2sr+(qPow(data.xy[2*i],2))/hs; //x^2 average
        i++;
    }
    a=(xysr-xsr*ysr)/(x2sr-qPow(xsr,2));  //a parameter
    b=ysr-a*xsr; //b parameter
    return "a="+QString::number(a)+",  b="+QString::number(b)+"\n"+     // returns string with answer
           "y="+QString::number(a)+"*x+("+QString::number(b)+")";       //
}
