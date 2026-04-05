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
  int left = 0;
  int right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int l_val = arr[left];
        int r_val = arr[right];
        int l_cnt = 0;
        int r_cnt = 0;
        while (left <= right && arr[left] == l_val) {
          l_cnt++;
          left++;
        }
        while (right >= left && arr[right] == r_val) {
          r_cnt++;
          right--;
        }
        count += l_cnt * r_cnt;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int binarySearch(int* arr, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return -1;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] > value) break;
    
    int target = value - arr[i];
    
    int left = i + 1;
    int right = len - 1;
    int firstIndex = -1;
    
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        firstIndex = mid;
        right = mid - 1;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    
    if (firstIndex != -1) {
      left = firstIndex;
      right = len - 1;
      int lastIndex = firstIndex;
      
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
          lastIndex = mid;
          left = mid + 1;
        } else if (arr[mid] < target) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
      
      count += (lastIndex - firstIndex + 1);
    }
  }
  return count;
}
