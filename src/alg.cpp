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

int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] > value) break;
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int found = -1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        found = mid;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (found != -1) {
      count++;
      int j = found - 1;
      while (j > i && arr[j] == target) {
        count++;
        j--;
      }
      j = found + 1;
      while (j < len && arr[j] == target) {
        count++;
        j++;
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
      int mid = (left + right) >> 1;
      if (arr[mid] == target) {
        count++;
        for (int j = mid - 1; j > i && arr[j] == target; j--) count++;
        for (int j = mid + 1; j < len && arr[j] == target; j++) count++;
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
