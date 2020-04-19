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

    int getFigureX() const
    {
        return this->figure->getFigureX();
    }

    int getFigureY() const
    {
        return this->figure->getFigureY();
    }

    FigureColor getFigureColor() 
    {
        return this->getFigure()->getColor();
    }

    FigureType getFigureType()
    {
        return this->getFigure()->getType();
    }

    void setFigurePosition(int newFigureX, int newFigureY)
    {
        this->figure->setPosition(newFigureX, newFigureY);
    }

    void setFigure(Figure *newFigure)
    {
        this->figure = newFigure;
    }
};