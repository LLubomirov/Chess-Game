Square::Square()
{
    EmptyFigure *figure = new EmptyFigure(NONE);
    this->figure = figure;
}

Square::Square(Figure *figure)
{
    this->figure = figure;
}

Figure* Square::getFigure() const
{
    return this->figure;
}

FigureColor Square::getColor() const
{
    return this->getFigure()->getColor();
}

FigureType Square::getType() const
{
    return this->getFigure()->getType();
}

void Square::setFigure(Figure *newFigure)
{
    this->figure = newFigure;
}