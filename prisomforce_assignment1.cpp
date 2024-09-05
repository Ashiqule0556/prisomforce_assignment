#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canCrossChakravyuha(int p, int a, int b, vector<int> &k) {
    int n = k.size();
    int skips = a;
    int recharges = b;
    
    for (int i = 0; i < n; ++i) {
        if (i == 3 && p < k[2] / 2) { 
            p -= k[2] / 2;
        }
        if (i == 7 && p < k[6] / 2) { 
            p -= k[6] / 2;
        }
        
        if (p >= k[i]) {
            p -= k[i]; 
        } else if (skips > 0) {
            skips--; 
        } else if (recharges > 0) {
            recharges--; 
        } else {
            return false; 
        }
    }
    return true;
}

int main() {
    // Test case 1
    int p1 = 100; 
    int a1 = 2;   
    int b1 = 2;   
    vector<int> k1 = {10, 20, 30, 25, 40, 50, 35, 60, 70, 80, 90}; 
    bool result1 = canCrossChakravyuha(p1, a1, b1, k1);
    cout << "Test case 1: " << (result1 ? "Abhimanyu Wins" : "Abhimanyu Loses") << endl;
    
    // Test case 2
    int p2 = 50;  
    int a2 = 1;   
    int b2 = 1;  
    vector<int> k2 = {5, 10, 20, 15, 25, 30, 20, 40, 50, 60, 70}; 
    bool result2 = canCrossChakravyuha(p2, a2, b2, k2);
    cout << "Test case 2: " << (result2 ? "Abhimanyu Wins" : "Abhimanyu Loses") << endl;

    return 0;
}
