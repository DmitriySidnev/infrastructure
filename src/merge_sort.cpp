#include <vector>

std::vector<int> merge(std::vector<int> v, int l, int m, int r) {
  int i = l, j = m + 1, k = l;
  std::vector<int> a(m - l + 1);
  std::vector<int> b(r - m);
  for (int m = 0; m < a.size(); m++, i++)
    a[m] = v[i];
  for (int m = 0; m < b.size(); m++, j++)
    b[m] = v[j];

  i = 0;
  j = 0;
  while (k <= r) {
    if (i < a.size() && (j >= b.size() || a[i] < b[j])) {
      v[k] = a[i];
      i++;
    } else if (j < b.size() && (i >= a.size() || b[j] <= a[i])) {
      v[k] = b[j];
      j++;
    }
    k++;
  }
  return v;
}