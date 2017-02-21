#include <iostream>
#include <vector>
#include <algorithm>

int* sort(int arr[], int length){
  if (length <= 2) {
    if (arr[0]<arr[1]) {
    } else{
      int c = arr[0];
      arr[0] = arr[1];
      arr[1] = c;
    }
    return arr;
  }
  int half = length/2;
  int a[half], b[length-half];
  for (size_t i = 0; i < length; i++) {
    if (i < (half)) {
      a[i] = arr[i];
    } else {
      b[i] = arr[i];
    }
  }
  int result[length];
  int *part1 = sort(a, half);
  int *part2 = sort(b, length-half);
  std::copy(part1, part1+half, result);
  std::copy(part2, part2+length-half, result+half);
  return result;
}

int main() {
  int a[] = {1, 4, 2, 6, 4, 7, 45, 6, 2, 5, 243,6};
  int *b = sort(a, 12);
  for (size_t i = 0; i < 12; i++) {
    std::cout << b[i] << std::endl;
  }
  return 0;
}
