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

    FigureColor getColor() const
    {
        return this->getFigure()->getColor();
    }

    FigureType getType() const
    {
        return this->getFigure()->getType();
    }

    void setFigure(Figure *newFigure)
    {
        this->figure = newFigure;
    }

private:
    Figure* figure;
};