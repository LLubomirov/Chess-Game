class ExtendedFigure : public Figure
{
public:
    ExtendedFigure(FigureColor color) :
        Figure(color){};

    char print()
    {
        return ' ';
    }

    vector<pair<int, int>> generatePath(pair<int, int> start, pair<int, int> destination)
    {
        vector<pair<int, int>> path;
        return path;
    }
};

TEST_CASE("Test figure is white")
{   
    ExtendedFigure efigure(WHITE);
    CHECK(efigure.isWhite());
}

TEST_CASE("Test figure is not white")
{
    ExtendedFigure efigure(NONE);
    CHECK(efigure.isWhite() == false);
}

TEST_CASE("Test figure is not white")
{
    ExtendedFigure efigure(BLACK);
    CHECK(efigure.isWhite() == false);
}

TEST_CASE("Test figure is black")
{
    ExtendedFigure efigure(BLACK);
    CHECK(efigure.isBlack());
}

TEST_CASE("Test figure is not black")
{
    ExtendedFigure efigure(NONE);
    CHECK(efigure.isBlack() == false);
}

TEST_CASE("Test figure is not black")
{
    ExtendedFigure efigure(WHITE);
    CHECK(efigure.isBlack() == false);
}
