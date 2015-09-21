/* 
 * File:   CBinaryHeap.cpp
 * Author: lixun
 * 
 * Created on September 20, 2015, 7:46 PM
 */

#include "CBinaryHeap.h"

CBinaryHeap::CBinaryHeap() {
}

CBinaryHeap::CBinaryHeap(int MaxHeapLength) {
    
    HeapCapacity = MaxHeapLength;
    HeapTail = 0;
    Heap = new Node_t[HeapCapacity];
    
}

CBinaryHeap::CBinaryHeap(const CBinaryHeap& orig) {
}

CBinaryHeap::~CBinaryHeap() {
    
    delete[] Heap;
}


// find the left child of node i
// if node i is the lowest leaf, return -1
int CBinaryHeap::LeftChild(int i) {
    
    i = 2 * i + 1;
    if(i >= HeapTail) return -1;  //child addressing error
    return i;
}


// find the right child of node i
// if node i is the lowest leaf, return -1
int CBinaryHeap::RightChild(int i) {
    
    i = 2 * i + 2;
    if(i >= HeapTail) return -1;
    return i;
}


// find the parent of node i
// if node i is the root, return -1
int CBinaryHeap::Parent(int i) {

    i = i - 1;
    if (i < 0) return -1;
    return i/2;
}


void CBinaryHeap::SwapNode(int i, int j) {
    
    Node_t NodeTemp;
    
    NodeTemp.Key = Heap[i].Key;
    NodeTemp.Value = Heap[i].Value;
    
    Heap[i].Key = Heap[j].Key;
    Heap[i].Value = Heap[j].Value;
    
    Heap[j].Key = NodeTemp.Key;
    Heap[j].Value = NodeTemp.Value;
}



int CBinaryHeap::Max(int i, int j) {
    int k = (i > j) ? i : j;
    return k;
}




// insert one node into the heap:
// 1. add the element to the bottom level of the heap
// 2. compare the new element against its parent, if in correct order then stop
// 3. otherwise swap the element with its parent, and goto step 2.
void CBinaryHeap::Insert(Node_t * LeafNodePushed) {
    
    // case if the heap is empty
    // NewNode will be the root of this heap
    if( HeapTail == 0 ) {
        Heap[HeapTail].Value = LeafNodePushed->Value;
        Heap[HeapTail].Key = LeafNodePushed->Key;
        HeapTail += 1;
    } else if ( HeapTail > 0 && HeapTail < HeapCapacity ) {
        Heap[HeapTail].Value = LeafNodePushed->Value;
        Heap[HeapTail].Key = LeafNodePushed->Key;
        HeapTail += 1;            
        
        int i = HeapTail - 1;
        while( Parent(i) >= 0 ) {
            if( Heap[i].Key > Heap[Parent(i)].Key ) {
                SwapNode(i, Parent(i));
                i = Parent(i);
            } else {
                break;
            }
        }
        
    }
    
    
}


// pop the root of the heap out
// 1. replace the root with the last element in the tail
// 2. compare the new root with its children, if order is correct stop
// 3. if not, swap the element with one of its children and goto step 2.
void CBinaryHeap::Extract(Node_t* RootNodePopped) {
    
    //case if the heap is empty, node popped will be NULL
    if( HeapTail == 0 ) {
        RootNodePopped = 0;
    } else if ( HeapTail > 0 && HeapTail <= HeapCapacity ) {
        RootNodePopped->Key = Heap[0].Key;
        RootNodePopped->Value = Heap[0].Value;
        
        Heap[0].Key = Heap[HeapTail-1].Key;
        Heap[0].Value = Heap[HeapTail-1].Value;
        HeapTail -= 1;
        
        int i = 0;
 
        while( LeftChild(i) >= 0 || RightChild(i) >= 0 ) {
            
            if( LeftChild(i) >= 0 && RightChild(i) >= 0 ) {
                // both children exit
                if( Heap[i].Key < Max(Heap[LeftChild(i)].Key, Heap[RightChild(i)].Key) ) {
                    if( Heap[LeftChild(i)].Key > Heap[RightChild(i)].Key ) {
                        SwapNode(i, LeftChild(i));
                        i = LeftChild(i);
                    } else {
                        SwapNode(i, RightChild(i));
                        i = RightChild(i);
                    }
                } else {
                    break;
                }
            } else if ( LeftChild(i) >= 0 && RightChild(i) < 0 ) {
                // only left child exists
                if( Heap[i].Key < Heap[LeftChild(i)].Key ) {
                    SwapNode(i, LeftChild(i));
                    i = LeftChild(i);
                } else {
                    break;
                }
            } else if ( LeftChild(i) < 0 && RightChild(i) >= 0 ) {              
                // only right child exists
                if( Heap[i].Key < Heap[RightChild(i)].Key ) {
                    SwapNode(i, RightChild(i));
                    i = RightChild(i);
                } else {
                    break;
                }
            }
        }
    }
    
}






int CBinaryHeap::GetNodeKey(int i) {
    return Heap[i].Key;
}

int CBinaryHeap::GetHeapSize(void) {
    return HeapTail;
}