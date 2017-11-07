#include "helper.h"
#include "Frame.h"
#include "Piece.h"
#include <iostream>

using std::cout;
using std::endl;

#define INPUT_DATA "demo.txt"

int main(int argc, char **argv) {

    Frame *frame;
    Piece **pieces;
    int numPieces;
    cout << "Reading data.." << endl;
    parseInput(INPUT_DATA, frame, pieces, numPieces);

    cout << (*frame);
    frame->testFrame();
    //pieces[2]->testFrame();
    for(int i = 0; i < numPieces;i ++){
      cout<<"*******   "<<i<<"   ****"<<endl;
      pieces[i]->testFrame();
    }
    return 0;
}
