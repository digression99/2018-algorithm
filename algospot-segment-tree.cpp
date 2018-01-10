//
// algospot segment tree
//

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int MAX_INT = numeric_limits<int>::max();
//const int INT_MAX =

struct RMQ { // range minimum query.
    
    int n; // size of the array.
    vector<int> rangeMin; // segment tree. it saves the min val of the range.
    
    RMQ(const vector<int> & array) {
        n = (int)array.size();
        rangeMin.resize(n * 4); // size of the segment tree.
        init(array, 0, n - 1, 1);
    }
    
    int init(const vector<int> & array, int left, int right, int node) {
        if (left == right) return rangeMin[node] = array[left]; // map left to node.
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2); // recursive
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (right < nodeLeft || nodeRight < left) return MAX_INT;
        if (left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid),
                   query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
    
    int query(int left, int right) { // interface
        return query(left, right, 1, 0, n - 1);
    }
    
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if (index < nodeLeft || nodeRight < index) return rangeMin[node]; // no change.
        if (nodeLeft == nodeRight) return rangeMin[node] = newValue; // start point.
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(update(index, newValue, node * 2, nodeLeft, mid),
                                    update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }
    
    int update(int index, int newValue) { // interface
        return update(index, newValue, 1, 0, n - 1);
    }
};

struct RangeResult {
    int size;
    int mostFrequent;
    int leftNumber, leftFreq;
    int rightNumber, rightFreq;
};

RangeResult merge(const RangeResult & a, const RangeResult & b) {
    RangeResult ret;
    
    ret.size = a.size + b.size;
    ret.leftNumber = a.leftNumber;
    ret.leftFreq = a.leftFreq;
    if (a.size == a.leftFreq && a.leftNumber == b.leftNumber)
        ret.leftFreq += b.leftFreq;
    
    ret.rightNumber = b.rightNumber;
    ret.rightFreq = b.rightFreq;
    if (b.size == b.rightFreq && a.rightNumber == b.rightNumber)
        ret.rightFreq += a.rightFreq;
    
    ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);
    if (a.rightNumber == b.leftNumber)
        ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
    
    return ret;
}


int main() {
    
    return 0;
}

