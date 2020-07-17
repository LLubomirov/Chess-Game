class ExtendedChessGame : ChessGame
{
public:

    bool isValidMove() const
    {
        return ChessGame::isValidMove();
    }

    bool figureOnTurn() const
    {
        return ChessGame::figureOnTurn();
    }

    bool landEmptyOrEnemy() const
    {
        return ChessGame::landEmptyOrEnemy();
    }

    bool isReachable() const
    {
        return ChessGame::isReachable();
    }

    bool isValidPawnAttack() const
    {
        return ChessGame::isValidPawnAttack();
    }

    std::vector<std::pair<int, int>> generateMovePath() const
    {
        return this->ChessGame::generateMovePath();
    }

    ExtendedChessGame() : ChessGame(){};

    void setExtendedBoard()
    {
        ChessGame::setChessGame();
    }

    void setFigureOn(Figure *figure, pair<char, char> position)
    {
        int row = '8' - position.second;
        int column = position.first - 'A';

        this->board.setFigureOn(figure, {row, column});
    }

    bool figuresAreEqual(Figure *figure1, Figure *figure2)
    {
        return (figure1->getType() == figure2->getType() && 
                figure1->getColor() == figure2->getColor());
    }

    Figure *getFigure(pair<char, char> position) const
    {
        int row = '8' - position.second;
        int column = position.first - 'A';

        return this->board.getFigure({row, column});
    }

    void setStart(pair<char, char> position)
    {
        int row = '8' - position.second;
        int column = position.first - 'A';

        this->start = {row, column};
    }

    void setDestination(pair<char, char> position)
    {
        int row = '8' - position.second;
        int column = position.first - 'A';

        this->destination = {row, column};
    }

    void moveFigure()
    {
        this->ChessGame::moveFigure();
    }

    void switchTurn() 
    {
        this->ChessGame::switchTurn();
    }

    FigureColor getTurn() const
    {
        return this->turn;
    }
};

TEST_CASE("Test isValidMove for white rook on D2 and black knight on D4")
{
    ExtendedChessGame game;
    game.setStart({'D', '2'});
    game.setDestination({'D', '4'});

    Rook rook(WHITE);
    game.setFigureOn(&rook, {'D', '2'});
    Knight knight(BLACK);
    game.setFigureOn(&knight, {'D', '4'});
    

    CHECK(game.isValidMove());
}

TEST_CASE("Test isValidMove for white rook on D2 and black knight on H2")
{
    ExtendedChessGame game;
    game.setStart({'D', '2'});
    game.setDestination({'H', '2'});

    Rook rook(WHITE);
    game.setFigureOn(&rook, {'D', '2'});
    Knight knight(BLACK);
    game.setFigureOn(&knight, {'H', '2'});
    

    CHECK(game.isValidMove());
}

TEST_CASE("Test isValidMove for black bishop on A1 and white king on B2")
{
    ExtendedChessGame game;
    game.switchTurn();
    game.setStart({'A', '1'});
    game.setDestination({'B', '2'});

    Bishop bishop(BLACK);
    game.setFigureOn(&bishop, {'A', '1'});
    King king(WHITE);
    game.setFigureOn(&king, {'B', '2'});
    
    CHECK(game.isValidMove());
}

TEST_CASE("Test isValidMove for black knight on A1 and white king on B2")
{
    ExtendedChessGame game;
    game.switchTurn();
    game.setStart({'A', '4'});
    game.setDestination({'B', '2'});

    Knight knight(BLACK);
    game.setFigureOn(&knight, {'A', '4'});
    King king(WHITE);
    game.setFigureOn(&king, {'B', '2'});
    
    CHECK(game.isValidMove());
}

TEST_CASE("Test figureOnTurn for white rook and correct player on turn")
{
    ExtendedChessGame game;
    game.setStart({'D', '3'});

    Rook rook(WHITE);
    game.setFigureOn(&rook, {'D', '3'});

    CHECK(game.figureOnTurn());
}

TEST_CASE("Test figureOnTurn for white bishop and white figures are on turn")
{
    ExtendedChessGame game;
    Bishop bishop(WHITE);
    game.setFigureOn(&bishop, {'F', '6'});
    game.setStart({'F', '6'});

    CHECK(game.figureOnTurn());
}

TEST_CASE("Test figureOnTurn for black rook and black figures are on turn")
{
    ExtendedChessGame game;
    game.setStart({'D', '3'});

    game.switchTurn();
    Rook rook(BLACK);
    game.setFigureOn(&rook, {'D', '3'});

    CHECK(game.figureOnTurn());
}

TEST_CASE("Test figureOnTurn == false for black rook but the white figures are on turn")
{
    ExtendedChessGame game;
    game.setStart({'D', '3'});

    Rook rook(BLACK);
    game.setFigureOn(&rook, {'D', '3'});

    CHECK(game.figureOnTurn() == false);
}

TEST_CASE("Test figureOnTurn == false for white rook but the black figures are on turn")
{
    ExtendedChessGame game;
    game.switchTurn();
    game.setStart({'D', '3'});

    Rook rook(WHITE);
    game.setFigureOn(&rook, {'D', '3'});

    CHECK(game.figureOnTurn() == false);
}

TEST_CASE("Test figureOnTurn == false for white pawn but the black figures are on turn")
{
    ExtendedChessGame game;
    game.switchTurn();
    game.setStart({'F', '2'});

    Pawn pawn(WHITE);
    game.setFigureOn(&pawn, {'F', '2'});

    CHECK(game.figureOnTurn() == false);
}

TEST_CASE("Test landEmptyOrEnemy for black queen on A2 to empty square A5")
{
    ExtendedChessGame game;
    game.setStart({'A', '2'});
    game.setDestination({'A', '5'});

    Queen queen(BLACK);
    game.setFigureOn(&queen, {'A', '2'});

    CHECK(game.landEmptyOrEnemy());
}

TEST_CASE("Test landEmptyOrEnemy for white queen on A2 to black pawn A5")
{
    ExtendedChessGame game;
    game.setStart({'A', '2'});
    game.setDestination({'A', '5'});

    Queen queen(WHITE);
    game.setFigureOn(&queen, {'A', '2'});

    Pawn pawn(BLACK);
    game.setFigureOn(&pawn, {'A', '5'});

    CHECK(game.landEmptyOrEnemy());
}

TEST_CASE("Test landEmptyOrEnemy for white queen on C2 to black rook G5")
{
    ExtendedChessGame game;
    game.setStart({'C', '2'});
    game.setDestination({'G', '5'});

    Queen queen(WHITE);
    game.setFigureOn(&queen, {'C', '2'});

    Rook rook(BLACK);
    game.setFigureOn(&rook, {'G', '5'});

    CHECK(game.landEmptyOrEnemy());
}

TEST_CASE("Test landEmptyOrEnemy == false for white queen on A2 to white bishop on A5")
{
    ExtendedChessGame game;
    game.setStart({'A', '2'});
    game.setDestination({'A', '5'});

    Queen queen(WHITE);
    game.setFigureOn(&queen, {'A', '2'});

    Bishop bishop(WHITE);
    game.setFigureOn(&bishop, {'A', '5'});

    CHECK(game.landEmptyOrEnemy() == false);
}

TEST_CASE("Test landEmptyOrEnemy == false for white queen on A2 to white bishop on C4")
{
    ExtendedChessGame game;
    game.setStart({'A', '2'});
    game.setDestination({'C', '4'});

    Queen queen(WHITE);
    game.setFigureOn(&queen, {'A', '2'});

    Bishop bishop(WHITE);
    game.setFigureOn(&bishop, {'C', '4'});

    CHECK(game.landEmptyOrEnemy() == false);
}

TEST_CASE("Test landEmptyOrEnemy == false for black knight on D1 to black rook on E3")
{
    ExtendedChessGame game;
    game.switchTurn();
    game.setStart({'D', '1'});
    game.setDestination({'E', '3'});

    Knight knight(BLACK);
    game.setFigureOn(&knight, {'D', '1'});

    Rook rook(BLACK);
    game.setFigureOn(&rook, {'E', '3'});

    CHECK(game.landEmptyOrEnemy() == false);
}

TEST_CASE("Test isReachable for black queen on A2 to A5")
{
    ExtendedChessGame game;
    game.setStart({'A', '2'});
    game.setDestination({'A', '5'});

    Queen queen(BLACK);
    game.setFigureOn(&queen, {'A', '2'});

    CHECK(game.isReachable());
}

TEST_CASE("Test isReachable for black queen on A2 to C4")
{
    ExtendedChessGame game;
    game.setStart({'A', '2'});
    game.setDestination({'C', '4'});

    Queen queen(BLACK);
    game.setFigureOn(&queen, {'A', '2'});

    CHECK(game.isReachable());
}

TEST_CASE("Test isReachable for black knight on D4 to E6")
{
    ExtendedChessGame game;
    game.setStart({'D', '4'});
    game.setDestination({'E', '6'});

    Knight knight(BLACK);
    game.setFigureOn(&knight, {'D', '4'});

    CHECK(game.isReachable());
}

TEST_CASE("Test isReachable == false for black queen on A2 to C4 with knight on B3")
{
    ExtendedChessGame game;
    game.setStart({'A', '2'});
    game.setDestination({'C', '4'});

    Queen queen(BLACK);
    game.setFigureOn(&queen, {'A', '2'});
    Knight knight(WHITE);
    game.setFigureOn(&knight, {'B', '3'});

    CHECK(game.isReachable() == false);
}

TEST_CASE("Test isReachable == false for black queen on A2 to A4 with pawn on A3")
{
    ExtendedChessGame game;
    game.setStart({'A', '2'});
    game.setDestination({'C', '4'});

    Queen queen(BLACK);
    game.setFigureOn(&queen, {'A', '2'});
    Pawn pawn(WHITE);
    game.setFigureOn(&pawn, {'B', '3'});

    CHECK(game.isReachable() == false);
}

TEST_CASE("Test isReachable == false for white bishop on F6 to D4 with pawn on E5")
{
    ExtendedChessGame game;
    game.setStart({'F', '6'});
    game.setDestination({'D', '4'});

    Bishop bishop(BLACK);
    game.setFigureOn(&bishop, {'F', '6'});
    Pawn pawn(WHITE);
    game.setFigureOn(&pawn, {'E', '5'});

    CHECK(game.isReachable() == false);
}

TEST_CASE("Test isValidPawnAttack for white pawn on B2 over black knight on C3")
{
    ExtendedChessGame game;
    game.setExtendedBoard();
    game.setStart({'B', '2'});
    game.setDestination({'C', '3'});

    Knight knight(BLACK);
    game.setFigureOn(&knight, {'C', '3'});
    bool validPawnAttack = game.isValidPawnAttack();

    CHECK(validPawnAttack);
}   

TEST_CASE("Test isValidPawnAttack for white pawn on B2 over black knight on A3")
{
    ExtendedChessGame game;
    game.setExtendedBoard();
    game.setStart({'B', '2'});
    game.setDestination({'A', '3'});

    Knight knight(BLACK);
    game.setFigureOn(&knight, {'A', '3'});
    bool validPawnAttack = game.isValidPawnAttack();

    CHECK(validPawnAttack);
} 

TEST_CASE("Test isValidPawnAttack for black pawn on B7 over black knight on C6")
{
    ExtendedChessGame game;
    game.setExtendedBoard();
    game.setStart({'B', '7'});
    game.setDestination({'C', '6'});

    Knight knight(WHITE);
    game.setFigureOn(&knight, {'C', '6'});
    bool validPawnAttack = game.isValidPawnAttack();

    CHECK(validPawnAttack);
}   

TEST_CASE("Test isValidPawnAttack for black pawn on B7 over black knight on A6")
{
    ExtendedChessGame game;
    game.setExtendedBoard();
    game.setStart({'B', '7'});
    game.setDestination({'A', '6'});

    Knight knight(WHITE);
    game.setFigureOn(&knight, {'A', '6'});
    bool validPawnAttack = game.isValidPawnAttack();

    CHECK(validPawnAttack);
}   

///generateMovePath wraps the Figure::generatePath and that is already tested
TEST_CASE("Test generateMovePath on knight B1 to A3") 
{
    ExtendedChessGame game;
    game.setExtendedBoard();
    game.setStart({'B', '1'});
    game.setDestination({'A', '3'});

    vector<pair<int, int>> path;
    path.push_back({5, 0});

    vector<pair<int, int>> generatedPath = game.generateMovePath();

    CHECK(path == generatedPath);
}

TEST_CASE("Test moveFigure white queen for D1 to A7")
{
    ExtendedChessGame game;
    game.setStart({'D', '1'});
    game.setDestination({'A', '7'});

    Queen queen(WHITE);
    EmptyFigure empty(NONE);

    game.setFigureOn(&queen, {'D', '1'});
    game.moveFigure();

    Figure *figureA7 = game.getFigure({'A', '7'});
    Figure *figureD1 = game.getFigure({'D', '1'});

    CHECK((game.figuresAreEqual(&queen, figureA7) &&
           game.figuresAreEqual(&empty, figureD1)));
}

TEST_CASE("Test moveFigure white knight for C2 to F2")
{
    ExtendedChessGame game;
    game.setStart({'C', '2'});
    game.setDestination({'F', '2'});

    Knight knight(WHITE);
    EmptyFigure empty(NONE);
    game.setFigureOn(&knight, {'C', '2'});

    game.moveFigure();

    Figure *figureF2 = game.getFigure({'F', '2'});
    Figure *figureC2 = game.getFigure({'C', '2'});

    CHECK((game.figuresAreEqual(&knight, figureF2) &&
           game.figuresAreEqual(&empty, figureC2)));
}

TEST_CASE("Test moveFigure black pawn for C3 to E4")
{
    ExtendedChessGame game;
    game.setStart({'C', '3'});
    game.setDestination({'E', '4'});

    Pawn pawn(WHITE);
    EmptyFigure empty(NONE);
    game.setFigureOn(&pawn, {'C', '3'});

    game.moveFigure();

    Figure *figureE4 = game.getFigure({'E', '4'});
    Figure *figureC3 = game.getFigure({'C', '3'});

    CHECK((game.figuresAreEqual(&pawn, figureE4) &&
           game.figuresAreEqual(&empty, figureC3)));
}

TEST_CASE("Test moveFigure black bishop for H5 to B2")
{
    ExtendedChessGame game;
    game.setStart({'H', '5'});
    game.setDestination({'B', '2'});

    Bishop bishop(WHITE);
    EmptyFigure empty(NONE);
    game.setFigureOn(&bishop, {'H', '5'});

    game.moveFigure();

    Figure *figureH5 = game.getFigure({'H', '5'});
    Figure *figureB2 = game.getFigure({'B', '2'});

    CHECK((game.figuresAreEqual(&bishop, figureB2) &&
           game.figuresAreEqual(&empty, figureH5)));
}

TEST_CASE("Test switchTurn for white to black")
{
    ExtendedChessGame game;

    game.switchTurn();
    FigureColor currentTurn = game.getTurn();

    CHECK(currentTurn == BLACK);
}

TEST_CASE("Test switchTurn for black to white")
{
    ExtendedChessGame game;

    game.switchTurn();
    game.switchTurn();
    FigureColor currentTurn = game.getTurn();

    CHECK(currentTurn == WHITE);
}