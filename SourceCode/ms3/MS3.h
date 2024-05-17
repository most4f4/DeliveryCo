#pragma once
#ifndef MS3_H
#define MS3_H

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

// Define boolean type and values
typedef int bool;
#define true 1
#define false 0

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


/*
 * Validates the weight value.
 * This function checks if the given weight value falls within the acceptable range.
 * @param weight - The weight value entered by the user to validate.
 * @returns 1 (True) if the weight is within the valid range [MIN_WEIGHT, MAX_WEIGHT], False otherwise.
 */
int validateWeight(int weight);

/*
 * Validates the box size.
 * This function verifies if the provided box size is valid based on predefined valid sizes.
 * @param boxSize - The size of the box entered by the user to validate.
 * @returns 1 (True) if the box size is one of the valid sizes [QUARTER_CUBIC_METER, HALF_CUBIC_METER, ONE_CUBIC_METER], False otherwise.
 */
int validateBoxSize(double boxSize);

/*
 * Validates the location on the grid.
 * This function checks if the given destination point is a valid location within the provided map's boundaries.
 * @param map - The map structure representing the grid.
 * @param map - The map structure representing the grid.
 * @param destination - The destination point to validate.
 * @returns 1 (True) if the destination point is within the map's boundaries, False otherwise.
 */
int validateLocation(const struct Map* map, const struct Point* destination);//Function needs to be implemented.

 /*
  * Validates the volume of a truck.
  * @param truck - The truck structure containing the boxes.
  * @returns 1 (True) if the truck's volume is within the valid range, False otherwise.
  */
int validateVolume(const struct Truck* truck);

/**
 * Calculates the limiting factor for a truck.
 * @param truck - The truck structure for which to calculate the limiting factor.
 * @return The limiting factor as a percentage (weight or volume).
 */
double calculateLimitingFactor(const struct Truck* truck);

/*
 * Gets user input for shipment weight, box size, and destination.
 * Validates the input using the defined validation functions.
 * Prompts for re-entry if invalid data is entered.
 * Stops taking input when 0 0 x is entered.
 */
 void getUserInput();//Function needs to be implemented.

 /*
  * Find an available truck for the shipment.
  * @param input - The input struct containing the map and trucks.
  * @param weight - The weight of the shipment in kilograms.
  * @param size - The size of the box required in cubic meters.
  * @param destination - The destination of the box as a Point (row, col).
  * @return - A pointer to the available truck, or NULL if no truck is available.
  */
  struct Truck* findAvailableTruck(struct Input* input, int weight, double size, struct Point destination);//Function needs to be implemented.



#endif
