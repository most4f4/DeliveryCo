#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "math.h"
#include "G5MS6.h"

double validSizes[3] = { QUARTER_CUBIC_METER, HALF_CUBIC_METER, ONE_CUBIC_METER };

struct Map populateMap()
{
	struct Map result = {
		//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
		//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
		{
		{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
		{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
		{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
		{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
		{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
		{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
		{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
		{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
		},
		MAP_ROWS, MAP_COLS
	};
	return result;
}

/// <summary>
/// Program debugged
/// </summary>
/// <param name="map"></param>
/// <param name="route">
/// List of Changes:
/// -Will make sure that pathways are interconnected
/// -Will reject negative number coordinates
/// -Will now inspect that symbol is not out of range
/// </param>
/// <returns>
/// If any errors detected a error message will be printed
/// out and the map structure will be returned unmodified
/// to show no changes.</returns>
struct Map addRoute(const struct Map* map, const struct Route* route)
{
	int r, c;
	struct Map result = { {0}, 0 };
	int i = 0, a = 1, detector = 0;

	for (r = 0; r < map->numRows; r++)
	{
		for (c = 0; c < map->numCols; c++)
		{
			result.squares[r][c] = map->squares[r][c];
		}
	}
	result.numRows = map->numRows;
	result.numCols = map->numCols;

	for (r = 0; r < route->numPoints; r++)
	{
		result.squares[route->points[r].row][route->points[r].col] += route->routeSymbol;
	}

	return result;
}
/**
* Add a point to a route
* @param route - the route to which the point should be added
* @param point - the point to add to the route.
*/
void addPtToRoute(struct Route* route, struct Point pt)
{
	route->points[route->numPoints++] = pt;
}

int getNumRows(const struct Map* map)
{
	return map->numRows;
}

int getNumCols(const struct Map* map)
{
	return map->numCols;
}

void printMap(const struct Map* map, const int base1, const int alphaCols)
{
	//              01234567890123456
	//              1248F
	char sym[] = { " XB?G?.?Y?-?*?+?P" };
	int r, c, rowMax;

	rowMax = map->numRows + base1;

	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++)
	{
		if (alphaCols) printf("%c", 'A' + c);
		else printf("%d", c % 10);
	}
	printf("\n");
	printf("%4s", " ");
	for (c = 0; c < map->numCols; c++)
	{
		printf("-");
	}
	printf("\n");

	for (r = base1; r < rowMax; r++)
	{
		printf("%3d|", r);
		for (c = 0; c < map->numCols; c++)
		{
			printf("%c", sym[map->squares[r - base1][c]]);
		}
		printf("\n");
	}
}

struct Route getBlueRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
			{5, 9},
			{6, 9},
			{7, 9},
			{8, 9},
			{9, 9},
			{10, 9},{10, 10},
			{11, 10},
			{12, 10},
			{13, 10},
			{14, 10},
			{15, 10},
			{16, 10},
			{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
				{17, 21},{17, 22},{17, 23},{17, 24},
		},
			42, BLUE
	};
	return result;
}

struct Route getGreenRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},{4, 10},{4, 11},
			{3, 11},
			{2, 11},
			{1, 11},
			{0, 11},{0, 12},{0, 13},{0, 14},{0, 15},{0, 16},{0, 17},{0, 18},{0, 19},
			{1, 19},
			{2, 19},
			{3, 19},
			{4, 19},
			{5, 19},
			{6, 19},
			{7, 19},
			{8, 19},
			{9, 19},{9, 20},{9, 21},{9, 22},{9, 23},{9, 24}

		},
			42, GREEN
	};
	return result;
}

struct Route getYellowRoute()
{
	struct Route result = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
	};
	return result;
}

int validateWeight(int weight) {
	if (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT)
	{
		return 1;
	}

	return 0;
}

int validateBoxSize(double boxSize) {
	for (int i = 0; i < NUM_VALID_SIZES; i++) {
		if (boxSize == validSizes[i]) {
			return 1;
		}
	}
	return 0;
}

int validateVolume(const struct Truck* truck) {
	if (truck->totalVolume < MAX_VOLUME)
	{
		return 1;
	}
	return 0;
}

double calculateLimitingFactor(const struct Truck* truck) {
	double weightPercentage = (double)truck->totalWeight / MAX_WEIGHT;
	double volumePercentage = truck->totalVolume / MAX_VOLUME;

	double limitingFactor;
	if (weightPercentage > volumePercentage) {
		limitingFactor = weightPercentage;
	}
	else {
		limitingFactor = volumePercentage;
	}

	return limitingFactor * 100.0;
}

/*
 * Validates the location on the grid.
 * This function checks if the given destination point is a valid location within the provided map's boundaries.
 * @param map - The map structure representing the grid.
 * @param map - The map structure representing the grid.
 * @param destination - The destination point to validate.
 * @returns 1 (True) if the destination point is within the map's boundaries, False otherwise.
 */
int validateLocation(struct Map* map, struct Point* destination) {

	if (map->squares[destination->col][destination->row] == 1)
	{
		return 0;
	}

	if ((destination->col < 0) || (destination->col > (map->numCols - 1)))
	{
		return 0;

	}

	if ((destination->row < 0) || (destination->row > (map->numRows - 1)))
	{
		return 0;

	}


	return 1;
}

/*
 * Find an available truck for the shipment.
 * @param input - The input struct containing the map and trucks.
 * @param weight - The weight of the shipment in kilograms.
 * @param size - The size of the box required in cubic meters.
 * @return - Returns the index of the truck that meets the requirement.
 */
int findAvailableTruck(struct Input* input, int weight, double size) {

	int index = -1, i = 0, flag = 0;

	if ((weight >= 0) && (size >= 0))
	{
		while ((flag == 0) && (i < input->numTrucks))
		{
			if ((input->trucks[i].totalVolume >= 0) && (input->trucks[i].totalWeight >= 0))
			{
				double dummyVolume = input->trucks[i].totalVolume + size;
				if (!(dummyVolume > MAX_VOLUME))
				{
					int dummyWeight = input->trucks[i].totalWeight + weight;
					if (!(dummyWeight > MAX_WEIGHT))
					{
						index = i;
						flag = 1;
					}
				}
			}
			i++;
		}
	}

	return index;
}

void getUserInput() {
	int weight;
	double size;
	struct Point dest;
	printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
	scanf("%d %lf %2s %c", &weight, &size, dest.row, &dest.col); // Use %2s to read two characters into dest.row
	// Stops taking input when 0 0 x is entered.
	if (weight != 0 && size != 0.0 && dest.row != 'x') {
		printf("Weight is: %d\nSize: %.2lf\nDest: %s%c\n", weight, size, dest.row, dest.col);
	}
}

/**
* Add a point to a route
* @param route - the route to which the point should be added
* @param point - the point to add to the route.
*/
void addPointToRoute(struct Route* route, int row, int col)
{
	struct Point pt = { row, col };
	if (((pt.row >= route->points[route->numPoints - 1].row + 2) || (pt.col >= route->points[route->numPoints - 1].col + 2)))
	{
		printf("Invalid Coordinates. Not connected to current path.\n");
	}
	else if ((pt.row == route->points[route->numPoints - 1].row) && (pt.col == route->points[route->numPoints - 1].col))
	{
		printf("Invalid Coordinates. Already entered.\n");
	}
	else if ((pt.row == route->points[route->numPoints - 1].row + 1) || (pt.col == route->points[route->numPoints - 1].col + 1))
	{
		if ((pt.row > 0) && (pt.col > 0))
		{
			addPtToRoute(route, pt);
		}
	}
}

/**
* Add a point to a route if it is not equal to another point.
* @param route - the route to which the point should be added
* @param row - the row of the point to add to the route.
* @param col - the column of the point to add to the route.
* @param notThis - the point will be added to the route ONLY if it is not equal to this point.
*/
void addPointToRouteIfNot(struct Route* route, const int row, const int col, const struct Point notThis)
{
	struct Point pt = { row, col };
	if (notThis.row != row || notThis.col != col) addPtToRoute(route, pt);
}

/**
* Compare two points for equality.
* @param p1 - the first point
* @param p2 - the second point
* @returns - true if p1 is equal to p2
*/
int eqPt(const struct Point p1, const struct Point p2)
{
	return p1.row == p2.row && p1.col == p2.col;
}

double distance(const struct Point* p1, const struct Point* p2)
{
	int deltaRow = p2->row - p1->row;
	int deltaCol = p2->col - p1->col;

	return sqrt((double)(deltaRow * deltaRow + deltaCol * deltaCol));
}

struct Route shortestPath(const struct Map* map, const struct Point start, const struct Point dest)
{
	struct Route result = { {0,0}, 0, DIVERSION };
	struct Point last = { -1, -1 };
	struct Point current = start;
	struct Route possible = { {0,0},0,0 };
	int close = 0;

	while (!eqPt(current, dest) && close >= 0)
	{
		possible = getPossibleMoves(map, current, last);
		close = getClosestPoint(&possible, dest);
		if (close >= 0)
		{
			last = current;
			current = possible.points[close];
			addPtToRoute(&result, current);
		}
	}
	return result;
}

struct Route getPossibleMoves(const struct Map* map, const struct Point p1, const struct Point backpath)
{
	struct Route result = { {0,0}, 0, DIVERSION };

	if (p1.row > 0)
	{
		if (map->squares[p1.row - 1][p1.col] != 1)
		{
			addPointToRouteIfNot(&result, p1.row - 1, p1.col, backpath);	// square above
		}
		if (p1.col > 0 && map->squares[p1.row - 1][p1.col - 1] != 1)
		{
			addPointToRouteIfNot(&result, p1.row - 1, p1.col - 1, backpath);	// top left
		}
		if (p1.col < (map->numCols - 1) && map->squares[p1.row - 1][p1.col + 1] != 1)
		{
			addPointToRouteIfNot(&result, p1.row - 1, p1.col + 1, backpath);	// top right
		}

	}
	if (p1.col > 0 && map->squares[p1.row][p1.col - 1] != 1)
	{
		addPointToRouteIfNot(&result, p1.row, p1.col - 1, backpath);// left
	}
	if (p1.col < (map->numCols - 1) && map->squares[p1.row][p1.col + 1] != 1)
	{
		addPointToRouteIfNot(&result, p1.row, p1.col + 1, backpath);	// right
	}
	if (p1.row < (map->numRows - 1))
	{
		if (map->squares[p1.row + 1][p1.col] != 1)
		{
			addPointToRouteIfNot(&result, p1.row + 1, p1.col, backpath);	// square below
		}
		if (p1.col > 0 && map->squares[p1.row + 1][p1.col - 1] != 1)
		{
			addPointToRouteIfNot(&result, p1.row + 1, p1.col - 1, backpath);	// bot left
		}
		if (p1.col < (map->numCols - 1) && map->squares[p1.row + 1][p1.col + 1] != 1)
		{
		}
	}
	return result;
}

int getClosestPoint(const struct Route* route, const struct Point pt)
{
	int i, closestIdx = -1;
	double closestDist = 999999.9, dist;

	for (i = 0; i < route->numPoints; i++)
	{
		dist = distance(&pt, &route->points[i]);
		if (dist < closestDist)
		{
			closestDist = dist;
			closestIdx = i;
		}
	}
	return closestIdx;
}


int main(void)
{
	struct Point goTo = { 3,0 };
	struct Box package = { 500,1.0,goTo };
	struct Truck truckA = { {package},3, 10.0, 10, 0.0 };
	struct Truck truckB = { {package},3, 0.0, 10203293029302930,0.0 };
	struct Truck truckC = { {package},3, 90232.0, 0,0.0 };
	struct Map landScape = {
		{
		{0, 0, 0, 0, 1},	//0
		{0, 1, 1, 0, 1},	//1
		{0, 1, 1, 0, 1},	//2
		{0, 0, 0, 0, 0},	//3
		{0, 0, 0, 0, 0},	//4
		{0, 0, 0, 0, 0}	//5
		},
		5,5
	};
	struct Route testRoute =
	{
			{
			{0,0},
			{1,0},
			{2,0}

			},
				3, 2
	};
	struct Map expectedMap = {
			{
		{2, 0, 0, 0, 1},	//0
		{2, 1, 1, 0, 1},	//1
		{2, 1, 1, 0, 1},	//2
		{16, 0, 0, 0, 0},	//3
		{0, 0, 0, 0, 0},	//4
		{0, 0, 0, 0, 0}	//5
		},
		5,5
	};

	struct Point start = { 0,0 };
	start.row = getClosestPoint(&testRoute, goTo);
	struct Route pathToUse = shortestPath(&landScape, start, goTo);
	struct Input testData = { {truckA,truckB,truckC},3,landScape };
	struct Truck* truckToDeploy;
	struct Map outcomeMap;
	int index = 0;

	outcomeMap = addRoute(&landScape, &testRoute);
	truckA.limitingFactor = calculateLimitingFactor(&truckA);

	if (1 == validateWeight(package.weight))
	{
		if (1 == validateBoxSize(package.size))
		{
			if (1 == validateLocation(&landScape, &package.destination))
			{
				index = findAvailableTruck(&testData, package.weight, package.size, package.destination, &truckToDeploy);
				truckToDeploy = &testData.trucks[index];
				outcomeMap = addRoute(&outcomeMap, &pathToUse);
			}
		}
	}

	printMap(&outcomeMap, 0, 0);

	return 0;
}

