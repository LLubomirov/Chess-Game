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
        return this->figure->getFigureX();
    }

    int getFigureY() const
    {
        return this->figure->getFigureY();
    }

    FigureColor getFigureColor() const
    {
        return this->getFigure()->getColor();
    }

    FigureType getFigureType() const
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

private:
    Figure* figure;
};