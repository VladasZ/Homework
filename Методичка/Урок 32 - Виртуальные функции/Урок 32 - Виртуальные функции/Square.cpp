
class Square{
public:
	virtual float square() = 0;
};

class Rectangle: public Square{
public:
	int high;
	int length;
	Rectangle(int high, int length) : high(high), length(length){}
	virtual float square(){
		return high*length;
	}
};

class Circle : public Square{
public:
	int radius;
	Circle(int radius):radius(radius){}
	virtual float square(){
		return radius*radius*3.14159262358;
	}
};

class RightTriangle : public Square{
public:
	int high;
	int length;
	RightTriangle(int high, int length) : high(high), length(length){}
	virtual float square(){
		return high*length/2;
	}
};

class Trapeze : public Square{
public:
	int high;
	int topSide;
	int bottomSide;

	Trapeze(int high, int topSide, int bottomSide) 
		: high(high), topSide(topSide), bottomSide(bottomSide)
	{}
	virtual float square(){
		return (topSide+bottomSide)*high / 2;
	}
};
