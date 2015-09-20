/* 
 * File:   main.cpp
 * Author: lixun
 *
 * Created on September 19, 2015, 10:37 PM
 */
#include <stdio.h>
#include <cstdlib>
#include "CBinaryHeap.h"



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Node_t x[7];
    for(int i = 0; i < 7; i++) {
        x[i].Key = i;
    }
    
    CBinaryHeap BHeap(7);
    for(int i = 0; i < 7; i++) {
        BHeap.Insert(x+i);
        
        printf("Heap size: %d.    ", BHeap.GetHeapSize());
        for(int j = 0; j < BHeap.GetHeapSize(); j++) {
            printf("%d  ", BHeap.GetNodeKey(j));
        }
        printf("\n");        
    }
    
    printf("==============\n");
    Node_t Root;
    for(int i = 0; i < 7; i++) {
        BHeap.Extract(&Root);
        
        printf("Heap size: %d.    ", BHeap.GetHeapSize());
        for(int j = 0; j < BHeap.GetHeapSize(); j++) {
            printf("%d  ", BHeap.GetNodeKey(j));
        }
        printf("\n");                
    }
    

    return 0;
}

