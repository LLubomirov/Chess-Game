#include "figure.cpp"

class Square
{
public:

    Square()
    {
        Figure *_figure;
        figure = _figure;
    }

    Square(Figure *_figure)
    {
        this->figure = _figure;
    }

    Figure *getFigure() const
    {
        return this->figure;
    }

    int getFigureX() const
    {
        return this->figure->getX();
    }

    int getFigureY() const
    {
        return this->figure->getY();
    }

    FigureColor getFigureColor() const
    {
        return this->getFigure()->getColor();
    }

    FigureType getFigureType() const
    {
        return this->getFigure()->getType();
    }

    void setFigurePosition(int newX, int newY)
    {
        this->figure->setPosition(newX, newY);
    }

    void setFigure(Figure *newFigure)
    {
        this->figure = newFigure;
    }

private:
    Figure* figure;
};