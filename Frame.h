/*
- class Frame describe Frame object.
- To-do :
        + calcAngle() -----> Thắng
*/
#ifndef FRAME_H
#define FRAME_H

#include "Dot.h"
#include <iostream>

using std::ostream;

class Frame {
  public:
    Frame();
    Frame(int numVertices, int id);
    // set coord for vectice index th
    void setCoord(int index, int x, int y);
    void setCoord(int index, const Dot&);

    void crossed( Dot* a, Dot* a2, Dot* a3,int &right, int &left);
    bool insideAngle( Dot *vertice, int &rightPoints, int &leftPoints);






    ///


    void testFrame();


    ///




    // TO-DO
    // calculate float* angles, base on Dot **vertices
    // Need to check parse data for vertices BEFORE calculae angles
    void calcAngle();



    friend ostream& operator<<(ostream &os, const Frame&);

  protected:
  //public:
    float *angles;
    Dot **vertices;
    int *squareEdge;
    int numVertices;
    int id;
};

#endif
