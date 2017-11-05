#include "Frame.h"
#include <cassert>
#include <iostream>
#include <cstddef>
#include <cmath>

using std::endl;

Frame::Frame(int numVertices, int id) {

    this->numVertices = numVertices;
    this->angles = new float[numVertices];
    this->vertices = new Dot*[numVertices];
    this->squareEdge = new int[numVertices];
    this->id = id;

    for (int i = 0; i < numVertices; i++) {
        this->vertices[i] = new Dot();
    }
}

Frame::Frame(){

}
void Frame::calcAngle(){


}

// duong bat ki 0.333(x - a) + 0.444(y - b) = 0

bool insideAngle(Dot *vertice){
    Dot* firstPoint;
    Dot* secondPoint;
    int rightPoints = 0;
    int leftPoints = 0;
    int j ;
    for (int i = 0; i < numVertices ; i ++){
      j = i;
      if(this->vertices[i].x == vertice->x && this->vertices[i].y == vertice->y){
          j ++;
      }
      firstPoint = this->vertices[j];

      if(j < this->numVertices - 1){
        if(this->vertices[j+1].x == vertice.x && this->vertices[j+1].y == vertice.y){
          j ++;
        }
      }else{
        j = 0;
      }

      secondPoint = this.vertices[j+1];

      Crossed(vertice,firstPoint,secondPoint,rightPoints,leftPoints);

      i = j;
    }

    if(rightPoints %2 == 0 && leftPoints % 2 ==0 ){
      return true;
    }

    return false;
}

// line : 0.333(x-a) + 0.444(y-b) = 0


void crossed(Dot* a, Dot* a2, Dot* a3,int &right, int &left){
  if((0.333*a->x +0.444*a->y -0.333*a2->x - 0.444*a2->y)*(0.333*a->x + 0.444*a->y - 0.333*a3->x - 0.444*a3->y) > 0){
    return;
  }


  double x,y;

  y = (-(-0.333*a->x - 0.444*a->y)/ 0.333 + (a2->x*a3->y - a2->y*a3->x)/(a2->y-a3->y)) : (0.444/0.333 + (a2->x - a3->x)/(a2->y-a3->y));
  x = (-0.444*y + 0.333*a->x + 0.444*a->y)/0.333;

    if(x > a.x){
      right ++;
      return;
    }

    left ++;
    return;
}



void Frame::setCoord(int index, int x, int y) {

    assert(this->numVertices > 0 && this->vertices != NULL);
    this->vertices[index]->x = x;
    this->vertices[index]->y = y;
}

void Frame::setCoord(int index, const Dot &coord) {

    assert(this->numVertices > 0 && this->vertices != NULL);
    this->vertices[index]->x = coord.x;
    this->vertices[index]->y = coord.y;
}

ostream& operator<<(ostream &os, const Frame &frame) {

    os << "ID : " << frame.id << endl;
    os << "#vertices : " << frame.numVertices << endl;

    for (int i = 0; i < frame.numVertices; i++) {

        os << "(" << frame.vertices[i]->x << ", " << frame.vertices[i]->y << "); ";
    }
    os << endl;

    return os;
}
