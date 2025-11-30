#include <bits/stdc++.h>
using namespace std;

struct Job
{
  char id;
  int deadline;
  int profit;
};

void job_sequencing(vector<Job> jobs)
{
  sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b)
       { return a.profit > b.profit; });

  int max_deadline = 0;
  for (auto j : jobs)
  {
    if (j.deadline > max_deadline)
      max_deadline = j.deadline;
  }

  vector<char> slot(max_deadline + 1, '_');

  int total_profit = 0;
  for (const auto &j : jobs)
  {
    for (size_t i = j.deadline; i > 0; i--)
    {
      if (slot[i] == '_')
      {
        slot[i] = j.id;
        total_profit += j.profit;
        break;
      }
    }
  }

  slot.erase(slot.begin());

  cout << "Job done: ";
  for (auto i : slot)
  {
    cout << i << " ";
  }

  cout << endl
       << "Total Profit: " << total_profit << endl;
}

int main()
{
  vector<Job> jobs = {
      {'A', 2, 300},
      {'B', 1, 100},
      {'C', 2, 50},
      {'D', 1, 20},
      {'E', 3, 10},
      {'F', 2, 40},
      {'G', 3, 200}};

  job_sequencing(jobs);

  return 0;
}