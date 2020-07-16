class ExtendedBoard : private Board
{
public:
    ExtendedBoard() : Board(){};

    void testSetBoard()
    {
        this->setBoard();
    }

    void testSetFigureOn(Figure *figure, pair<int, int> position)
    {
        int row = '8' - position.second;
        int column = position.first - 'A';

        this->setFigureOn(figure, {row, column});
    }

    bool figuresAreEqual(Figure *figure1, Figure *figure2)
    {
        return (figure1->getType() == figure2->getType() && 
                figure1->getColor() == figure2->getColor());
    }

    Square getSquare(pair<char, char> position) const
    {
        int row = '8' - position.second;
        int column = position.first - 'A';

        return this->board[row][column];
    }

    Figure *testGetFigure(pair<char, char> position) const
    {
        int row = '8' - position.second;
        int column = position.first - 'A';

        return this->getFigure({row, column});
    }
};

///Testing setBoard and more specificly if white figures are placed correctly
TEST_CASE("Test setBoard put white rook on A1")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'A', '1'});

    Rook rook(WHITE);

    CHECK(b.figuresAreEqual(&rook, figure));
}

TEST_CASE("Test setBoard put white knight on B1")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'B', '1'});

    Knight knight(WHITE);

    CHECK(b.figuresAreEqual(&knight, figure));
}

TEST_CASE("Test setBoard put white bishop on C1")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'C', '1'});

    Bishop bishop(WHITE);

    CHECK(b.figuresAreEqual(&bishop, figure));
}

TEST_CASE("Test setBoard put white queen on D1")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'D', '1'});

    Queen queen(WHITE);

    CHECK(b.figuresAreEqual(&queen, figure));
}

TEST_CASE("Test setBoard put white king on E1")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'E', '1'});

    King king(WHITE);

    CHECK(b.figuresAreEqual(&king, figure));
}

TEST_CASE("Test setBoard put white bishop on F1")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'F', '1'});

    Bishop bishop(WHITE);

    CHECK(b.figuresAreEqual(&bishop, figure));
}

TEST_CASE("Test setBoard put white knight on G1")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'G', '1'});

    Knight knight(WHITE);

    CHECK(b.figuresAreEqual(&knight, figure));
}

TEST_CASE("Test setBoard put white rook on H1")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'H', '1'});

    Rook rook(WHITE);

    CHECK(b.figuresAreEqual(&rook, figure));
}

TEST_CASE("Test setBoard put white pawn on A2")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'A', '2'});

    Pawn pawn(WHITE);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put white pawn on B2")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'B', '2'});

    Pawn pawn(WHITE);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put white pawn on C2")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'C', '2'});

    Pawn pawn(WHITE);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put white pawn on D2")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'D', '2'});

    Pawn pawn(WHITE);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put white pawn on E2")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'E', '2'});

    Pawn pawn(WHITE);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put white pawn on F2")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'F', '2'});

    Pawn pawn(WHITE);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put white pawn on G2")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'G', '2'});

    Pawn pawn(WHITE);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put white pawn on H2")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'H', '2'});

    Pawn pawn(WHITE);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

///Testing setBoard and more specificly if black figures are placed correctly
TEST_CASE("Test setBoard put black rook on A8")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'A', '8'});

    Rook rook(BLACK);

    CHECK(b.figuresAreEqual(&rook, figure));
}

TEST_CASE("Test setBoard put black knight on B8")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'B', '8'});

    Knight knight(BLACK);

    CHECK(b.figuresAreEqual(&knight, figure));
}

TEST_CASE("Test setBoard put black bishop on C8")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'C', '8'});

    Bishop bishop(BLACK);

    CHECK(b.figuresAreEqual(&bishop, figure));
}

TEST_CASE("Test setBoard put black queen on D8")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'D', '8'});

    Queen queen(BLACK);

    CHECK(b.figuresAreEqual(&queen, figure));
}

TEST_CASE("Test setBoard put black king on E8")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'E', '8'});

    King king(BLACK);

    CHECK(b.figuresAreEqual(&king, figure));
}

TEST_CASE("Test setBoard put black bishop on F8")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'F', '8'});

    Bishop bishop(BLACK);

    CHECK(b.figuresAreEqual(&bishop, figure));
}

TEST_CASE("Test setBoard put black knight on G8")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'G', '8'});

    Knight knight(BLACK);

    CHECK(b.figuresAreEqual(&knight, figure));
}

TEST_CASE("Test setBoard put black rook on H8")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'H', '8'});

    Rook rook(BLACK);

    CHECK(b.figuresAreEqual(&rook, figure));
}

TEST_CASE("Test setBoard put black pawn on A7")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'A', '7'});

    Pawn pawn(BLACK);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put black pawn on B7")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'B', '7'});

    Pawn pawn(BLACK);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put black pawn on C7")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'C', '7'});

    Pawn pawn(BLACK);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put black pawn on D7")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'D', '7'});

    Pawn pawn(BLACK);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put black pawn on E7")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'E', '7'});

    Pawn pawn(BLACK);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put black pawn on F7")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'F', '7'});

    Pawn pawn(BLACK);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put black pawn on G7")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'G', '7'});

    Pawn pawn(BLACK);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setBoard put black pawn on H7")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'H', '7'});

    Pawn pawn(BLACK);

    CHECK(b.figuresAreEqual(&pawn, figure));
}

///Testing setBoard and more specificly if on the empty squares are placed empty figures

TEST_CASE("Test setBoard put empty figure on A3")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'A', '3'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on A4")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'A', '4'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on A5")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'A', '5'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on A6")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'A', '6'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on B3")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'B', '3'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on B4")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'B', '4'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on B5")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'B', '5'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on B6")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'B', '6'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on C3")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'C', '3'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on C4")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'C', '4'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on C5")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'C', '5'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on C6")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'C', '6'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on D3")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'D', '3'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on D4")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'D', '4'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on D5")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'D', '5'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on D6")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'D', '6'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on E3")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'E', '3'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on E4")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'E', '4'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on E5")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'E', '5'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on E6")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'E', '6'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on F3")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'F', '3'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on F4")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'F', '4'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on F5")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'F', '5'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on F6")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'F', '6'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on G3")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'G', '3'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on G4")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'G', '4'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on G5")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'G', '5'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on G6")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'G', '6'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on H3")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'H', '3'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on H4")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'H', '4'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on H5")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'H', '5'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

TEST_CASE("Test setBoard put empty figure on H6")
{
    ExtendedBoard b;
    b.testSetBoard();
    Figure *figure = b.testGetFigure({'H', '6'});

    EmptyFigure empty(NONE);

    CHECK(b.figuresAreEqual(&empty, figure));
}

/// Testing setFigureOn method
TEST_CASE("Test setFigureOn to put black pawn on A1")
{
    ExtendedBoard b;
    Pawn pawn(BLACK);
    b.testSetFigureOn(&pawn, {'A', '1'});

    Figure *figure = b.testGetFigure({'A', '1'});

    CHECK(b.figuresAreEqual(&pawn, figure));
}

TEST_CASE("Test setFigureOn to put white rook on B2")
{
    ExtendedBoard b;
    Rook rook(WHITE);
    b.testSetFigureOn(&rook, {'B', '2'});

    Figure *figure = b.testGetFigure({'B', '2'});

    CHECK(b.figuresAreEqual(&rook, figure));
}

TEST_CASE("Test setFigureOn to put black knight on C3")
{
    ExtendedBoard b;
    Knight knight(BLACK);
    b.testSetFigureOn(&knight, {'C', '3'});

    Figure *figure = b.testGetFigure({'C', '3'});

    CHECK(b.figuresAreEqual(&knight, figure));
}

TEST_CASE("Test setFigureOn to put white bishop on D4")
{
    ExtendedBoard b;
    Bishop bishop(WHITE);
    b.testSetFigureOn(&bishop, {'D', '4'});

    Figure *figure = b.testGetFigure({'D', '4'});

    CHECK(b.figuresAreEqual(&bishop, figure));
}

TEST_CASE("Test setFigureOn to put white queen on E5")
{
    ExtendedBoard b;
    Queen queen(BLACK);
    b.testSetFigureOn(&queen, {'E', '5'});

    Figure *figure = b.testGetFigure({'E', '5'});

    CHECK(b.figuresAreEqual(&queen, figure));
}

TEST_CASE("Test setFigureOn to put black king on F6")
{
    ExtendedBoard b;
    King king(BLACK);
    b.testSetFigureOn(&king, {'F', '6'});

    Figure *figure = b.testGetFigure({'F', '6'});

    CHECK(b.figuresAreEqual(&king, figure));
}