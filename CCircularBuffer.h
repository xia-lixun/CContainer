/* 
 * File:   CCircularBuffer.h
 * Author: lixun
 *
 * Created on September 19, 2015, 10:43 PM
 */

#ifndef CCIRCULARBUFFER_H
#define	CCIRCULARBUFFER_H




// How to use:
// 1. construct memory pool consisting of blocks with keying from 0, 1, 2 ...
// 2. form memory pool table in array whose element is (block pointer, availability)
// 3. initialize the table with block addresses and availability as 'yes'.



typedef struct CircularBufferPayload {
    
    void * BlockPointer;
    int BlockKey;

} CircularBufferPayload_t;





class CCircularBuffer {
    
public:
    CCircularBuffer();
    CCircularBuffer(int FIFO_LENGTH);
    virtual ~CCircularBuffer();
    
    void Reset();
    int Push(void * value, int key);
    int Pop(void ** value);
    
private:
    CCircularBuffer(const CCircularBuffer& orig);
    
protected:
    CircularBufferPayload_t * pFIFO; // queue array starting address
    int LenFIFO;
    int InstElements;                // instantaneous elements in the queue
    int Read;
    int Write;
    bool IsOverRun;
    bool IsUnderRun;
};

#endif	/* CCIRCULARBUFFER_H */

