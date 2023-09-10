#include <iostream>
#include <vector>
using namespace std;

int calculate_similarity(vector<int>& arr1, vector<int>& arr2) {
    int similarity = 0;
    int min_length = min(arr1.size(), arr2.size());
    for (int i = 0; i < min_length; ++i) {
        if (arr1[i] == arr2[i]) {
            similarity += 1;
        } else {
            break;
        }
    }
    return similarity;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arrays;

    for (int i = 0; i < n; ++i) {
        int k_i;
        cin >> k_i;
        vector<int> a_i(k_i);
        for (int j = 0; j < k_i; ++j) {
            cin >> a_i[j];
        }
        arrays.push_back(a_i);
    }

    int total_similarity = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            total_similarity += calculate_similarity(arrays[i], arrays[j]);
        }
    }

    cout << total_similarity << endl;

    return 0;
}
