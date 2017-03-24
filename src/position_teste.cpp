#include <iostream>
using namespace std;

class Position {
private:
    int x;
    int y;

public:
	Position() {
		setPosition(0,0);
	}
	
    Position(int x, int y) {
        setPosition(x, y);
    }

    ~Position() {

    }

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    void operator = (const Position p) {
        this->x = p.getX();
		this->y = p.getY();
    }

    bool operator == (const Position p) {
		if(this->x == p.getX() && \
			this->y == p.getY())
			return true;
		return false;
	}
};




int main(void) {
	Position position2;
	
	
	position2.setPosition(10,4);
	
	Position position;
	
	position = position2;
	
	
	std::cout << "Position = " << position.getX() << " " << position.getY() << endl;
	position2.setPosition(5,1);
	
	if(position == position2) 
		std::cout << "ok";
	else
		std::cout << "no";
	
	return 0;
}
