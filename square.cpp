#include "figure.cpp"

class Square
{
private:
    Figure* figure;

public:

    Square()
    {
        Figure *p;
        figure = p;
    }

    Square(Figure *_p)
    {
        this->figure = _p;
    }

    Figure *getFigure()
    {
        return this->figure;
    }

    int getX() const
    {
        return this->figure->getFigureX();
    }

    int getY() const
    {
        return this->figure->getFigureY();
    }

    FigureColor getColor()
    {
        return this->getFigure()->getColor();
    }

    void setPosition(int newFigureX, int newFigureY)
    {
        this->figure->setPosition(newFigureX, newFigureY);
    }

    void setFigure(Figure *newFigure)
    {
        this->figure = newFigure;
    }
};