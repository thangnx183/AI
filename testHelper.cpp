#include "helper.h"
#include "Frame.h"
#include "Piece.h"
#include <iostream>

using std::cout;
using std::endl;

#define INPUT_DATA "input.txt"

int main(int argc, char **argv) {

    Frame *frame;
    Piece **pieces;
    int numPieces;
    cout << "Reading data.." << endl;
    parseInput(INPUT_DATA, frame, pieces, numPieces);

    cout << (*frame);
    return 0;
}
