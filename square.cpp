#include "figure.cpp"

class Square
{
public:

    Square()
    {
        Figure *figure;
        this->figure = figure;
    }

    Square(Figure *figure)
    {
        this->figure = figure;
    }

    Figure *getFigure() const
    {
        return this->figure;
    }

    // int getX() const
    // {
    //     return this->figure->getX();
    // }

    // int getY() const
    // {
    //     return this->figure->getY();
    // }

    FigureColor getColor() const
    {
        return this->getFigure()->getColor();
    }

    FigureType getType() const
    {
        return this->getFigure()->getType();
    }

    // void setFigurePosition(int newX, int newY)
    // {
    //     this->figure->setPosition(newX, newY);
    // }

    void setFigure(Figure *newFigure)
    {
        this->figure = newFigure;
    }

private:
    Figure* figure;
};