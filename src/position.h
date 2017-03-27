#ifndef POSITION_H
#define POSITION_H

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

    ~Position() { }

    void setPosition(int x, int y) {
        this->x = x;
        this->y = y;
    }

    inline int getX() const { return x; }
    inline int getY() const { return y; }

    void operator = (const Position p) {
        x = p.getX();
        y = p.getY();
    }

    bool operator == (const Position p) {
        if(x == p.getX() && y == p.getY())
            return true;
        return false;
    }

    bool operator != (const Position p) {
        if(x != p.getX() || y != p.getY())
            return true;
        return false;
    }
};

#endif // POSITION_H
