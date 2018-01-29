//
// 20180129
// algospot MORDOR
//

// test case
//2
//3 1
//1 2 3
//0 2
//10 4
//3 9 5 6 10 8 7 1 2 4
//1 6
//4 7
//9 9
//5 8

//1
//10 4
//3 9 5 6 10 8 7 1 2 4
//1 6
//4 7
//9 9
//5 8


#include <iostream>
using namespace std;
#include <vector>

const int MAX_NUM = 987654321;
const int MIN_NUM = -987654321;
const bool GET_MAX = 0;
const bool GET_MIN = 1;

struct RMQ {
    int n;
    vector<int> rangeMin;
    vector<int> rangeMax;
    RMQ(const vector<int> & array) {
        n = (int)array.size();
        rangeMin.resize(n * 4);
        rangeMax.resize(n * 4);
        init(array, 0, n - 1, 1, GET_MAX);
        init(array, 0, n - 1, 1, GET_MIN);
    }
    int init(const vector<int> & array, int left, int right, int node, bool flag) {
        if (left == right) return rangeMax[node] = rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftVal = init(array, left, mid, node * 2, flag); // left child.
        int rightVal = init(array, mid + 1, right, node * 2 + 1, flag); // right child.
        
        if (flag == GET_MAX) return rangeMax[node] = max(leftVal, rightVal);
        else return rangeMin[node] = min(leftVal, rightVal);
    }
    int query(int left, int right, int node, int nodeLeft, int nodeRight, bool flag) {
        // get the max diff between left and right.
        if (right < nodeLeft || nodeRight < left) return flag == GET_MAX ? MIN_NUM : MAX_NUM;
        if (left <= nodeLeft && nodeRight <= right) return flag == GET_MAX ? rangeMax[node] : rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        int leftVal = query(left, right, node * 2, nodeLeft, mid, flag);
        int rightVal = query(left, right, node * 2 + 1, mid + 1, nodeRight, flag);
        if (flag == GET_MAX) return max(leftVal, rightVal);
        else return min(leftVal, rightVal);
    }
    
    int query(int left, int right) {
        int maxVal = query(left, right, 1, 0, n - 1, GET_MAX);
        int minVal = query(left, right, 1, 0, n - 1, GET_MIN);
        return maxVal - minVal;
    }
};

void driver() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int n, q;
        vector<int> arr;
        cin >> n >> q;
        arr.resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        RMQ rmq(arr); // make rmq
        int l, r;
        for (int j = 0; j < q; ++j) {
            cin >> l >> r;
            cout << rmq.query(l, r) << endl;
        }
    }
}

int main() {
    driver();
    return 0;
}


















