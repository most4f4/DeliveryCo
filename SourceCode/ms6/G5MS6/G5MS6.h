#pragma once
#ifndef G5MS6_H
#define G5MS6_H

#define NUM_TRUCKS 3

#define MIN_WEIGHT 1
#define MAX_WEIGHT 1000

#define QUARTER_CUBIC_METER 0.25
#define HALF_CUBIC_METER 0.5
#define ONE_CUBIC_METER 1.0
#define NUM_VALID_SIZES 3

#define MAX_VOLUME 36
#define MAX_BOXES 20

#define MAP_ROWS 25
#define MAP_COLS 25

#define true 1
#define false 0

#define MAX_ROUTE 100
#define MAP_ROWS 25
#define MAP_COLS 25
#define MAX_ROUTE 100
#define BLUE 2
#define GREEN 4
#define YELLOW 8
#define DIVERSION 16

extern double validSizes[3]; // = { QUARTER_CUBIC_METER, HALF_CUBIC_METER, ONE_CUBIC_METER };

struct Map
{
	int squares[MAP_ROWS][MAP_COLS];
	int numRows;
	int numCols;
};

struct Point
{
	char row;
	char col;
};

struct Box {
	int weight;
	double size;
	struct Point destination;
};

struct Truck
{
	struct Box boxes[MAX_BOXES];
	int numBoxes;
	double totalVolume;
	int totalWeight;
	double limitingFactor; // The limiting factor as a percentage (weight or volume)
};

struct Input
{
	struct Truck trucks[NUM_TRUCKS];
	int numTrucks;
	struct Map map;
};

struct Route
{
	struct Point points[MAX_ROUTE];
	int numPoints;
	char routeSymbol;
};

int validateWeight(int weight);
int validateBoxSize(double boxSize);
int validateLocation(const struct Map* map, const struct Point* destination);
int validateVolume(const struct Truck* truck);
double calculateLimitingFactor(const struct Truck* truck);
void getUserInput();//not test
int findAvailableTruck(struct Input* input, int weight, double size);

//======================================================================================================================
struct Map populateMap();
int getNumRows(const struct Map* map);//not test
int getNumCols(const struct Map* map);//not test
void printMap(const struct Map* map, const int base1, const int alphaCols);//not test
struct Map addRoute(const struct Map* map, const struct Route* route);
void addPtToRoute(struct Route* route, struct Point pt);//not test
void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis);//not test
void addPointToRoute(struct Route* route, const int row, const int col);//not test
struct Route getBlueRoute();//not test
struct Route getGreenRoute();//not test
struct Route getYellowRoute();//not test
double distance(const struct Point* p1, const struct Point* p2);//not test
struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest);
struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath);//not test
int getClosestPoint(const struct Route* route, const struct Point pt);
int eqPt(const struct Point p1, const struct Point p2);//not test

#endif