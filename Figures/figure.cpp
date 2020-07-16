Figure::Figure(FigureColor color)
{
    this->color = color;
}

bool Figure::isWhite() const
{
    return this->color == WHITE;
}

bool Figure::isBlack() const
{
    return this->color == BLACK;
}

bool Figure::isEmpty() const
{
    return this->color == NONE;
}

FigureColor Figure::getColor() const
{
    return this->color;
}

FigureType Figure::getType() const
{
    return this->type;
}