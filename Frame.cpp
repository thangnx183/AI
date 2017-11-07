#include "Frame.h"
#include <cassert>
#include <iostream>
#include <cstddef>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
using std::endl;
using namespace std;
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

// duong bat ki 0.333(x - a.x) + 0.454(y - a.y) = 0

void Frame::crossed(Dot* a, Dot* a2, Dot* a3,int &right, int &left){

  //std::cout<<endl<<"calculating..."<<endl;
  //std::cout<<"croes_check"<<(0.333*a->x +0.454*a->y -0.333*a2->x - 0.454*a2->y)*(0.333*a->x + 0.454*a->y - 0.333*a3->x - 0.454*a3->y)<<endl;
  //cout<<endl<<"("<<a2->x<<","<<a2->y<<")";
  //cout<<endl<<"("<<a3->x<<","<<a3->y<<")";
  if((0.333*a2->x +0.454*a2->y - 0.333*a->x - 0.454*a->y)*(0.333*a3->x + 0.454*a3->y - 0.333*a->x - 0.454*a->y) > 0){
    //cout<<"ko cat"<<endl;
    return;
  }

//  std::cout<<"crossed"<<endl;

  //std::cout<<endl<<"*********************"<<endl;
  double x;
  //std::cout<<a2->y-a3->y<<endl;
  //getchar();

  if(a2->x-a3->x == 0){
    x = a2->x;
  }else{
    //y = (-(-0.333*a->x - 0.454*a->y)/ 0.333 + (a2->x*a3->y - a2->y*a3->x)/(a2->y-a3->y)) / (0.454/0.333 + (a2->x - a3->x)/(a2->y-a3->y));
    double n = a2->y - a3->y;
    double m = a2->x - a3->x;

    x = (a->y - a2->y + a2->x*(n/m) + (0.333/0.454)*a->x )/(n/m + 0.333/0.454);
  }

  //y = (-(-0.333*a->x - 0.454*a->y)/ 0.333 + (a2->x*a3->y - a2->y*a3->x)/(a2->y-a3->y)) / (0.454/0.333 + (a2->x - a3->x)/(a2->y-a3->y));
  //x = (-0.454*y + 0.333*a->x + 0.454*a->y)/0.333;
  //cout<<x<<" , "<<endl;
  //cout<<"--------------------------"<<endl;
  //std::cout<<"x = "<<x<<endl;
  //std::cout<<"y = "<<y<<endl;
  //getchar();
    if(x > a->x){
      right ++;
      return;
    }

    left ++;
    return;
}

bool Frame::insideAngle( Dot *vertice, int &rightPoints, int &leftPoints){
    Dot* firstPoint;
    Dot* secondPoint;
    //int rightPoints = 0;
    //int leftPoints = 0;
    rightPoints = 0;
    leftPoints = 0;

    int j ;
    //getchar();
    for (int i = 0; i < numVertices ; i ++){
      j = i;
      if(this->vertices[i]->x == vertice->x && this->vertices[i]->y == vertice->y){
          j ++;
          //std::cout<<"i = "<<i<<endl;
      }
      firstPoint = this->vertices[j];
      //std::cout<<"( "<<j<<" ";

      if(j < this->numVertices - 1){
        if(this->vertices[j+1]->x == vertice->x && this->vertices[j+1]->y == vertice->y){
          j ++;
        }
        if(j == this->numVertices - 1){
          secondPoint = this->vertices[0];
          //std::cout<<0;
        }else{
          secondPoint = this->vertices[j+1];
          //std::cout<<j+1;
        }
      }else if (this->vertices[0]->x == vertice->x && this->vertices[0]->y == vertice->y){
        //j = 0;
        secondPoint = this->vertices[1];
        //std::cout<<1;
      }else{
        secondPoint = this->vertices[0];
      //  std::cout<<0;
      }
      //std::cout<<")";

      //secondPoint = this->vertices[j+1];
      //std::cout<<j<<endl;
    //  getchar();
      crossed(vertice,firstPoint,secondPoint,rightPoints,leftPoints);
      //std::cout<<"right = "<<rightPoints<<endl;
      //std::cout<<"left = "<<leftPoints<<endl;
      //std::cout<<"calculated"<<endl;

      //getchar();
      i = j;
      //std::cout<<i<<endl;
    }

    if(rightPoints %2 == 0 && leftPoints % 2 ==0 ){
      return true;
    }

    return false;
}

void Frame::testFrame(){
  for(int i = 0;i < numVertices; i ++){
    std::cout<<"points " <<this->vertices[i]->x<<" , "<<this->vertices[i]->y;
    //getchar();
    int right = 0;
    int left = 0;

    bool b = insideAngle(this->vertices[i],right,left);
    //std::cout<<endl;
    //std::cout<<"("<<this->vertices[i]->x<<" , "<<this->vertices[i]->y<<")";
    std::cout<<"///////////////"<<b<<" "<<right<<" "<<left<<endl;
  }


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



ostream& operator<<(ostream &os,const Frame &frame) {

    os << "ID : " << frame.id << endl;
    os << "#vertices : " << frame.numVertices << endl;

    for (int i = 0; i < frame.numVertices; i++) {

        os << "(" << frame.vertices[i]->x << ", " << frame.vertices[i]->y << "); ";
    }
    os << endl;

//    for(int i = 0;i < frame.numVertices; i ++){
//      os<<frame.insideAngle(frame.vertices[i])<<endl;
//    }

    return os;
}
