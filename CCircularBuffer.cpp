/* 
 * File:   CCircularBuffer.cpp
 * Author: lixun
 * 
 * Created on September 19, 2015, 10:43 PM
 */

#include "CCircularBuffer.h"

CCircularBuffer::CCircularBuffer() {
}


CCircularBuffer::CCircularBuffer(int FIFO_LENGTH) {
    
    pFIFO = new CircularBufferPayload_t[FIFO_LENGTH];
    LenFIFO = FIFO_LENGTH;
    
    InstElements = 0;
    Read = 0;
    Write = 0;
    IsOverRun = false;
    IsUnderRun = false;
}



void CCircularBuffer::Reset() {
    
    InstElements = 0;
    Read = 0;
    Write = 0;
    IsOverRun = false;
    IsUnderRun = false;    
}


// return of the key for the mem pool to set availability to false
int CCircularBuffer::Push(void* value, int key) {
    
    pFIFO[Write].BlockPointer = value;
    pFIFO[Write].BlockKey = key;
    
    // write always points to the first empty place yet to be written
    Write += 1;
    if( Write >= LenFIFO ) Write = 0;
    InstElements += 1;
    if( InstElements >= LenFIFO && Write == Read ) IsOverRun = true;
    
    return key;
}


int CCircularBuffer::Pop(void** value) {
    
    int KeyAvailable = pFIFO[Read].BlockKey;
    *value = pFIFO[Read].BlockPointer;
    
    // read always points to the first filled place yet to be read
    Read += 1;
    if( Read >= LenFIFO ) Read = 0;
    InstElements -= 1;
    if( InstElements <= 0 && Read == Write ) IsUnderRun = true;
    
    return KeyAvailable;
}




CCircularBuffer::CCircularBuffer(const CCircularBuffer& orig) {
}

CCircularBuffer::~CCircularBuffer() {
    delete[] pFIFO;
}

