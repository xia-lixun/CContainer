/* 
 * File:   CBinaryHeap.h
 * Author: lixun
 *
 * Created on September 20, 2015, 7:46 PM
 */

#ifndef CBINARYHEAP_H
#define	CBINARYHEAP_H


typedef struct Node {
    void * Value;
    int Key;
} Node_t;


// THIS IS A MAX HEAP!
class CBinaryHeap {

public:
    CBinaryHeap();
    CBinaryHeap(int MaxHeapLength);
    virtual ~CBinaryHeap();
    
    void Insert(Node_t * LeafNodePushed);
    void Extract(Node_t * RootNodePopped);
    int GetNodeKey(int i);
    int GetHeapSize(void);
    
private:
    CBinaryHeap(const CBinaryHeap& orig);
    
    int LeftChild(int i);
    int RightChild(int i);
    int Parent(int i);
    void SwapNode(int i, int j);
    int Max(int i, int j);
    
protected:
    Node_t * Heap;
    int HeapCapacity; // for complete binary heap, it is always 2**n-1
    int HeapTail;
};

#endif	/* CBINARYHEAP_H */

