#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "catan.hpp"


using namespace ariel;
using namespace std;

TEST_CASE("Land Class Tests") {
    SUBCASE("Test Land Construction and Getters") {
        vector<Land> neighbors;
        Land land1("Forest", 5, neighbors);
        Land land2("Mountains", 3);

        CHECK(land1.getType() == "Forest");
        CHECK(land1.getNumber() == 5);
        CHECK(land1.getMaterial() == "wood");

        CHECK(land2.getType() == "Mountains");
        CHECK(land2.getNumber() == 3);
        CHECK(land2.getMaterial() == "iron");
    }

    SUBCASE("Test Land Neighbors") {
        vector<Land> neighbors;
        Land land1("Forest", 5, neighbors);
        Land land2("Mountains", 3);

        neighbors.push_back(land1);
        neighbors.push_back(land2);

        Land land3("Hills", 7, neighbors);

        CHECK(land3.numOfNeighbors() == 2);
        CHECK(land3.isNeighbor(land1));
        CHECK(land3.isNeighbor(land2));
    }
}

TEST_CASE("Settelment Class Tests") {
    SUBCASE("Test Settelment Construction and Getters") {
        vector<Land> landsAround;
        Land land1("Forest", 5);
        Land land2("Mountains", 3);

        landsAround.push_back(land1);
        landsAround.push_back(land2);

        Settelment settelment1("City", landsAround);
        Settelment settelment2("Village", landsAround);

        CHECK(settelment1.getName() == "City");
        CHECK(settelment1.getLandsAround().size() == 2);
        CHECK(settelment2.getName() == "Village");
        CHECK(settelment2.getLandsAround().size() == 2);
    }

    SUBCASE("Test Settelment City Status") {
        vector<Land> landsAround;
        Land land1("Forest", 5);
        landsAround.push_back(land1);

        Settelment settelment("Village", landsAround);

        CHECK(settelment.get_city() == false);
        settelment.setCity(true);
        CHECK(settelment.get_city());
    }
}

TEST_CASE("Board Class Tests") {
    SUBCASE("Test Board Construction and Getters") {
        vector<Land> lands;
        vector<Settelment> settelments;
        vector<Road> roads;

        Land land1("Forest", 5);
        Land land2("Mountains", 3);
        lands.push_back(land1);
        lands.push_back(land2);

        Board board(lands, settelments, roads);

        auto boardLands = board.getLands();
        CHECK(boardLands.size() == 2);
        CHECK(boardLands[0].getType() == "Forest");
        CHECK(boardLands[1].getType() == "Mountains");
    }

    SUBCASE("Test Board Place Settelment") {
        vector<Land> lands;
        vector<Settelment> settelments;
        vector<Road> roads;

        Land land1("Forest", 5);
        Land land2("Mountains", 3);
        lands.push_back(land1);
        lands.push_back(land2);

        Board board(lands, settelments, roads);

        vector<Land> crossRoad = {land1, land2};
        board.placeSettelmentOnBoard(crossRoad);

        auto boardSettelments = board.getSettelments();
        CHECK(boardSettelments.size() == 1);
        CHECK(boardSettelments[0].getLandsAround().size() == 2);
    }

    // SUBCASE("Test Board Place Road") {
    //     vector<Land> lands;
    //     vector<Settelment> settelments;
    //     vector<Road> roads;

    //     Land land1("Forest", 5);
    //     Land land2("Mountains", 3);
    //     lands.push_back(land1);
    //     lands.push_back(land2);

    //     Board board(lands, settelments, roads);

    //     Settelment settelment("Village", {land1});
    //     board.placeRoadOnBoard(settelment);

    //     auto boardRoads = board.getRoads();
    //     CHECK(boardRoads.size() == 1);
    //     CHECK(boardRoads[0].getName() == "Main Road");
    // }
}

TEST_CASE("Catan Class Tests") {
    // SUBCASE("Test Choose Starting Player") {
    //     Player p1("Player1"), p2("Player2"), p3("Player3");
    //     Catan catanGame(p1, p2, p3);

    //     Player startingPlayer = catanGame.chooseStartingPlayer();

    //     CHECK(startingPlayer.getName() == p1.getName());
    //     CHECK(startingPlayer.getName() == p2.getName());
    //     CHECK(startingPlayer.getName() == p3.getName());
    //     cout << "Starting Player: " << startingPlayer.getName() << std::endl;
    // }

    SUBCASE("Test Print Winner Function") {
        Player p1("Player1"), p2("Player2"), p3("Player3");
        Catan catanGame(p1, p2, p3);

        // Simulate a game scenario where players accumulate points or resources
        // Example:
        // p1.addPoints(10);
        // p2.addPoints(8);
        // p3.addPoints(12);

        // catanGame.printWinner();
        // Implement assertions to check correct winner printing based on game logic
    }
}
