TEST_CASE("Test king generating path: (3, 3) -> (3, 4)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 4};

    vector<pair<int, int>> generatedPath;
    generatedPath = king.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({3, 4});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test king generating path: (3, 3) -> (2, 2)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 2};

    vector<pair<int, int>> generatedPath;
    generatedPath = king.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({2, 2});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test king not generating path: (3, 3) -> (1, 5)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {1, 5};

    vector<pair<int, int>> generatedPath;
    generatedPath = king.generatePath(start, destination);

    CHECK(generatedPath.empty());
}

TEST_CASE("Test king can access: (3, 3) -> (3, 4)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 4};
    CHECK(king.isAccessible(start, destination));
}

TEST_CASE("Test king can access: (3, 3) -> (2, 2)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 2};
    CHECK(king.isAccessible(start, destination));
}

TEST_CASE("Test king cannot access: (3, 3) -> (2, 5)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 5};
    CHECK(king.isAccessible(start, destination) == false);
}

TEST_CASE("Test king is on straight move (3, 3) -> (3, 2)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 2};
    CHECK(king.isStraightMove(start, destination));
}

TEST_CASE("Test king is on straight move (3, 3) -> (2, 3)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 3};
    CHECK(king.isStraightMove(start, destination));
}

TEST_CASE("Test king is not on straight move (3, 3) -> (3, 7)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 7};
    CHECK(king.isStraightMove(start, destination) == false);
}

TEST_CASE("Test king is on horizontal move (3, 3) -> (3, 4)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 4};
    CHECK(king.isHorizontalMove(start, destination));
}

TEST_CASE("Test king is on horizontal move (3, 3) -> (3, 2)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 2};
    CHECK(king.isHorizontalMove(start, destination));
}

TEST_CASE("Test king is not on horizontal move (3, 3) -> (3, 1)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {3, 1};
    CHECK(king.isHorizontalMove(start, destination) == false);
}

TEST_CASE("Test king is on vertical move (3, 3) -> (4, 3)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {4, 3};
    CHECK(king.isVerticalMove(start, destination));
}

TEST_CASE("Test king is on vertical move (3, 3) -> (2, 3)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 3};
    CHECK(king.isVerticalMove(start, destination));
}

TEST_CASE("Test king is not on vertical move (3, 3) -> (5, 3)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {5, 3};
    CHECK(king.isVerticalMove(start, destination) == false);
}

TEST_CASE("Test king is on diagonal move (3, 3) -> (4, 2)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {4, 2};
    CHECK(king.isDiagonalMove(start, destination));
}

TEST_CASE("Test king is on diagonal move (3, 3) -> (4, 4)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {4, 4};
    CHECK(king.isDiagonalMove(start, destination));
}

TEST_CASE("Test king is on diagonal move (3, 3) -> (2, 4)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 4};
    CHECK(king.isDiagonalMove(start, destination));
}

TEST_CASE("Test king is on diagonal move (3, 3) -> (2, 2)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {2, 2};
    CHECK(king.isDiagonalMove(start, destination));
}

TEST_CASE("Test king is not on diagonal move (3, 3) -> (5, 5)")
{
    King king(EMPTY, NONE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {5, 5};
    CHECK(king.isDiagonalMove(start, destination) == false);
}