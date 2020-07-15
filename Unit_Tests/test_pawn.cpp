/// Testing white pawns

TEST_CASE("Test pawn generating path: (3, 3) -> (4, 3)")
{
    Pawn pawn(EMPTY, WHITE);

    pair<int, int> start = {3, 3};
    pair<int, int> destination = {4, 3};

    vector<pair<int, int>> generatedPath;
    generatedPath = pawn.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({4, 3});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test pawn generating path: (5, 1) -> (4, 1)")
{
    Pawn pawn(EMPTY, WHITE);

    pair<int, int> start = {5, 1};
    pair<int, int> destination = {4, 1};

    vector<pair<int, int>> generatedPath;
    generatedPath = pawn.generatePath(start, destination);

    vector<pair<int, int>> correctPath;
    correctPath.push_back({4, 1});

    CHECK(generatedPath == correctPath);
}

TEST_CASE("Test pawn not generating path: (3, 1) -> (4, 0)")
{
    Pawn pawn(EMPTY, WHITE);

    pair<int, int> start = {3, 1};
    pair<int, int> destination = {4, 0};

    vector<pair<int, int>> generatedPath;
    generatedPath = pawn.generatePath(start, destination);

    CHECK(generatedPath.empty());
}

TEST_CASE("Test pawn can access: (1, 4) -> (0, 4)")
{
    Pawn pawn(EMPTY, WHITE);

    pair<int, int> start = {1, 4};
    pair<int, int> destination = {0, 4};
    CHECK(pawn.isAccessible(start, destination));
}

TEST_CASE("Test pawn can access: (4, 6) -> (3, 6)")
{
    Pawn pawn(EMPTY, WHITE);

    pair<int, int> start = {4, 6};
    pair<int, int> destination = {3, 6};
    CHECK(pawn.isAccessible(start, destination));
}

TEST_CASE("Test pawn cannot access: (1, 3) -> (1, 4)")
{
    Pawn pawn(EMPTY, WHITE);

    pair<int, int> start = {1, 3};
    pair<int, int> destination = {1, 4};
    CHECK(pawn.isAccessible(start, destination) == false);
}