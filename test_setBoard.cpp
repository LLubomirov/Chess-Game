class ExtendBoard : public Board
{
    public:
        ExtendBoard() : Board(){};

        void testSetBoard()
        {
            this->setBoard();
        }

        Square getSquare(char x, char y)
        {
            int row = '8' - y;
            int column = x - 'A';
            return this->board[row][column];
        }
};

///Testing if the color of the white figures is correct
TEST_CASE("Test setBoard put white figure on A1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('A', '1').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on B1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('B', '1').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on C1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('C', '1').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on D1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('D', '1').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on E1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('E', '1').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on F1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('F', '1').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on G1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('G', '1').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on H1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('H', '1').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on A2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('A', '2').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on B2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('B', '2').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on C2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('C', '2').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on D2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('D', '2').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on E2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('E', '2').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on F2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('F', '2').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on G2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('G', '2').getColor() == WHITE);
}

TEST_CASE("Test setBoard put white figure on H2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('H', '2').getColor() == WHITE);
}

///Testing if the color of the black figures is correct
TEST_CASE("Test setBoard put black figure on A8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('A', '8').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on B8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('B', '8').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on C8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('C', '8').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on D8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('D', '8').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on E8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('E', '8').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on F8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('F', '8').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on G8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('G', '8').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on H8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('H', '8').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on A7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('A', '7').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on B7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('B', '7').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on C7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('C', '7').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on D7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('D', '7').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on E7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('E', '7').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on F7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('F', '7').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on G7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('G', '7').getColor() == BLACK);
}

TEST_CASE("Test setBoard put black figure on H7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('H', '7').getColor() == BLACK);
}

///Testing if the type of the white figures is correct
TEST_CASE("Test setBoard put rook figure on A1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('A', '1').getType() == ROOK);
}

TEST_CASE("Test setBoard put white figure on B1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('B', '1').getType() == KNIGHT);
}

TEST_CASE("Test setBoard put white figure on C1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('C', '1').getType() == BISHOP);
}

TEST_CASE("Test setBoard put white figure on D1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('D', '1').getType() == QUEEN);
}

TEST_CASE("Test setBoard put white figure on E1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('E', '1').getType() == KING);
}

TEST_CASE("Test setBoard put white figure on F1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('F', '1').getType() == BISHOP);
}

TEST_CASE("Test setBoard put white figure on G1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('G', '1').getType() == KNIGHT);
}

TEST_CASE("Test setBoard put white figure on H1")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('H', '1').getType() == ROOK);
}

TEST_CASE("Test setBoard put white figure on A2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('A', '2').getType() == PAWN);
}

TEST_CASE("Test setBoard put white figure on B2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('B', '2').getType() == PAWN);
}

TEST_CASE("Test setBoard put white figure on C2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('C', '2').getType() == PAWN);
}

TEST_CASE("Test setBoard put white figure on D2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('D', '2').getType() == PAWN);
}

TEST_CASE("Test setBoard put white figure on E2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('E', '2').getType() == PAWN);
}

TEST_CASE("Test setBoard put white figure on F2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('F', '2').getType() == PAWN);
}

TEST_CASE("Test setBoard put white figure on G2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('G', '2').getType() == PAWN);
}

TEST_CASE("Test setBoard put white figure on H2")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('H', '2').getType() == PAWN);
}

///Testing if the color of the black figures is correct
TEST_CASE("Test setBoard put black figure on A8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('A', '8').getType() == ROOK);
}

TEST_CASE("Test setBoard put black figure on B8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('B', '8').getType() == KNIGHT);
}

TEST_CASE("Test setBoard put black figure on C8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('C', '8').getType() == BISHOP);
}

TEST_CASE("Test setBoard put black figure on D8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('D', '8').getType() == QUEEN);
}

TEST_CASE("Test setBoard put black figure on E8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('E', '8').getType() == KING);
}

TEST_CASE("Test setBoard put black figure on F8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('F', '8').getType() == BISHOP);
}

TEST_CASE("Test setBoard put black figure on G8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('G', '8').getType() == KNIGHT);
}

TEST_CASE("Test setBoard put black figure on H8")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('H', '8').getType() == ROOK);
}

TEST_CASE("Test setBoard put black figure on A7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('A', '7').getType() == PAWN);
}

TEST_CASE("Test setBoard put black figure on B7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('B', '7').getType() == PAWN);
}

TEST_CASE("Test setBoard put black figure on C7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('C', '7').getType() == PAWN);
}

TEST_CASE("Test setBoard put black figure on D7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('D', '7').getType() == PAWN);
}

TEST_CASE("Test setBoard put black figure on E7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('E', '7').getType() == PAWN);
}

TEST_CASE("Test setBoard put black figure on F7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('F', '7').getType() == PAWN);
}

TEST_CASE("Test setBoard put black figure on G7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('G', '7').getType() == PAWN);
}

TEST_CASE("Test setBoard put black figure on H7")
{
    ExtendBoard b;
    b.testSetBoard();
    CHECK(b.getSquare('H', '7').getType() == PAWN);
}