#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "math.h"
#include "MS3.h"

double validSizes[3] = { QUARTER_CUBIC_METER, HALF_CUBIC_METER, ONE_CUBIC_METER };


int validateWeight(int weight) {
    return (weight >= MIN_WEIGHT && weight <= MAX_WEIGHT);
}

int validateBoxSize(double boxSize)  {
    for (int i = 0; i < NUM_VALID_SIZES; i++) {
        if (boxSize == validSizes[i]) {
            return true;
        }
    }
    return false;
}

int validateVolume(const struct Truck* truck) {
    return (truck->totalVolume <= MAX_VOLUME);
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

int validateLocation(const struct Map* map, const struct Point* destination) {
    return 1;
}


void getUserInput() {

}

struct Truck* findAvailableTruck(struct Input* input, int weight, double size, struct Point destination) {
    return NULL;
}



