#include <iostream>
using namespace std;

class Rectangle2D {
private:
	double x;
	double y;
	double width;
	double height;
public:
	double getx(){
		return x;
	}
	double gety(){
		return y;
	}
	void setx(double a){
		x=a;
	}
	void sety(double a){
		y=a;
	}
	double getWidth(){
		return width;
	}
	double getHeight(){
		return height;
	}
	void setWidth(double a){
		width=a;
	}
	void setHeight(double a){
		height=a;
	}
	Rectangle2D (){
		x=0;
		y=0;
		width=1;
		height=1;
	}
	Rectangle2D(double a, double b, double c, double d){
		x=a;
		y=b;
		width=c;
		height=d;
	}
	double getArea(){
		return (width*height);
	}
	double getPerimeter(){
		return ((width*2)+(height*2));
	}
	const bool contains (double a, double b){
		bool xposs=false, yposs=false;
		if (a>(x-(width/2)) && a<(x+(width/2)))
			xposs=true;
		if (b>(y-(height/2)) && b<(y+(height/2)))
			yposs=true;
		if (xposs && yposs)
			return true;
		else
			return false;
	}
	const bool contains (const Rectangle2D &r){
		bool xposs=false, yposs=false;
		if ((r.x-(r.width/2))>(x-(width/2)) && (r.x+(r.width/2))<(x+(width/2)))
			xposs=true;
		if ((r.y-(r.height/2))>(y-(height/2)) && (r.y+(r.height/2))<(x+(height/2)))
			yposs=true;
		if (xposs && yposs)
			return true;
		else
			return false;
	}
	const bool overlaps (const Rectangle2D &r){
		double xleft=(r.x-(r.width/2));
		double ybot=(r.y-(r.height/2));
		double xright=(r.x+(r.width/2));
		double ytop=(r.y+(r.height/2));
		bool test=false;
		if (contains(xleft,ytop) && !contains(xright, ybot))
			test=true;
		if (contains(xright,ytop) && !contains(xleft, ybot))
			test=true;
		if (contains(xleft,ybot) && !contains(xright, ytop))
			test=true;
		if (contains(xright,ybot) && !contains(xleft, ytop))
			test=true;
		if (test)
			return true;
		else
			return false;
	}
};

int main (){
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);
	cout << "r1 area: " << r1.getArea() << endl;
	cout << "r1 perimeter: " << r1.getPerimeter() << endl;
	cout << r1.contains(3,3) << endl;
	cout << r1.contains(r2) << endl;
	cout << r1.overlaps(r3) << endl;
	return 0;
}