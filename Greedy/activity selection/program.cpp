#include <bits/stdc++.h>
using namespace std;

struct Activity
{
  string id;
  int start;
  int finish;
};

void activity_selection(vector<Activity> activities)
{
  if (activities.empty())
    return;

  sort(activities.begin(), activities.end(), [](const Activity &a, const Activity &b)
       { return a.finish < b.finish; });

  int last_finish = activities[0].finish;
  cout << "(" << activities[0].start << ", " << activities[0].finish << ")" << endl;

  for (size_t i = 1; i < activities.size(); i++)
  {
    if (activities[i].start >= last_finish)
    {
      cout << "(" << activities[i].start << ", " << activities[i].finish << ")" << endl;

      last_finish = activities[i].finish;
    }
  }
}

int main()
{
  vector<Activity> activities = {
      {"A1", 1, 2},
      {"A2", 3, 4},
      {"A3", 0, 6},
      {"A4", 5, 7},
      {"A5", 8, 9},
      {"A6", 5, 9},
  };

  activity_selection(activities);

  return 0;
}