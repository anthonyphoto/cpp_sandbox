#include <iostream>

void moveDisk(int disk, char source, char destination) {
    std::cout << "Move disk " << disk << " from " << source << " to " << destination << std::endl;
}

void solveTowersOfHanoi(int disks, char source, char auxiliary, char destination) {
    if (disks == 1) {
        moveDisk(disks, source, destination);
    } else {
        solveTowersOfHanoi(disks - 1, source, destination, auxiliary);
        moveDisk(disks, source, destination);
        solveTowersOfHanoi(disks - 1, auxiliary, source, destination);
    }
}

int main() {
    int numDisks = 3;
    char sourceRod = 'A';
    char auxiliaryRod = 'B';
    char destinationRod = 'C';

    solveTowersOfHanoi(numDisks, sourceRod, auxiliaryRod, destinationRod);

    return 0;
}