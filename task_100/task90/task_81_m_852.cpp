#include <iostream>
#include <vector>

int findPeakIndex(std::vector<int>& arr) {
    int start = 0;
    int end = arr.size() - 1;
    while (start < end) {
        int middle = start + (end - start) / 2;
        if (arr[middle] < arr[middle + 1]) {
            start = middle + 1;
        } else {
            end = middle;
        }
    }
    return start;
}

int main() {
    std::vector<int> arr = {1, 3, 5, 7, 9, 10, 5, 3, 2, 0};
    int peakIndex = findPeakIndex(arr);
    std::cout << "Индекс пика: " << peakIndex << std::endl;

    return 0;
}