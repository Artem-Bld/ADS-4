// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] > value) break;
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) {
        count++;
        while (j > i && arr[j] == arr[j-1]) {
          if (arr[i] + arr[j-1] == value) {
            count++;
          }
          j--;
        }
        break;
      } else if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] > value) break;
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] == target) {
        count++;
        int j = mid - 1;
        while (j > i && arr[j] == target) {
          count++;
          j--;
        }
        j = mid + 1;
        while (j < len && arr[j] == target) {
          count++;
          j++;
        }
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  return count;
}
