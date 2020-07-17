class ExtendedSquare : public Square 
{
public:
    void setFigure(Figure *figure)
    {
        Square::setFigure(figure);
    }

    bool figuresAreEqual(Figure *figure1, Figure *figure2)
    {
        return (figure1->getType() == figure2->getType() && 
                figure1->getColor() == figure2->getColor());
    }
};

TEST_CASE("Test setFigure black queen")
{
    Queen queen(BLACK);
    ExtendedSquare square;

    square.setFigure(&queen);
    Figure *squareFigure = square.getFigure();

    CHECK(square.figuresAreEqual(&queen, squareFigure));
}

TEST_CASE("Test setFigure white rook")
{
    Rook rook(WHITE);
    ExtendedSquare square;

    square.setFigure(&rook);
    Figure *squareFigure = square.getFigure();

    CHECK(square.figuresAreEqual(&rook, squareFigure));
}

TEST_CASE("Test setFigure black bishop")
{
    Bishop bishop(BLACK);
    ExtendedSquare square;

    square.setFigure(&bishop);
    Figure *squareFigure = square.getFigure();

    CHECK(square.figuresAreEqual(&bishop, squareFigure));
}

TEST_CASE("Test Square() puts EmptyFigure")
{
    ExtendedSquare square;
    Figure *squareFigure = square.getFigure();
    EmptyFigure empty(NONE);

    CHECK(square.figuresAreEqual(&empty, squareFigure));
}