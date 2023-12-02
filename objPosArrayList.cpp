#include "objPosArrayList.h"
#include <algorithm> // For std::copy

objPosArrayList::objPosArrayList() {
    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0;
    aList = new objPos[sizeArray]; // Allocate array with max capacity
}

objPosArrayList::~objPosArrayList() {
    delete[] aList; // Deallocate the array to prevent memory leaks
}

int objPosArrayList::getSize() {
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos) {
    if (sizeList >= sizeArray) {
        // Handle array overflow, possibly resize the array
        return;
    }
    // Shift all elements to the right by one position
    std::copy_backward(aList, aList + sizeList, aList + sizeList + 1);
    aList[0] = thisPos;
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos) {
    if (sizeList >= sizeArray) {
        // Handle array overflow, possibly resize the array
        return;
    }
    aList[sizeList] = thisPos;
    sizeList++;
}

void objPosArrayList::removeHead() {
    if (sizeList > 0) {
        // Shift all elements to the left by one position
        std::copy(aList + 1, aList + sizeList, aList);
        sizeList--;
    }
}

void objPosArrayList::removeTail() {
    if (sizeList > 0) {
        sizeList--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos) {
    if (sizeList > 0) {
        returnPos = aList[0];
    }
}

void objPosArrayList::getTailElement(objPos &returnPos) {
    if (sizeList > 0) {
        returnPos = aList[sizeList - 1];
    }
}

void objPosArrayList::getElement(objPos &returnPos, int index) {
    if (index >= 0 && index < sizeList) {
        returnPos = aList[index];
    }
}
