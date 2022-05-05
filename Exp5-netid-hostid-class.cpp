// Show Net id, Host id and Network class of the address
#include <iostream>
#include <vector>
using namespace std;

string convertDecToBin(string str)
{
  int x = stoi(str);
  string bin;
  return bin;
}

vector<int> extractNumbers(string str)
{
  vector<int> arr;
  int num = 0;
  int i = 0;
  while (i < str.length())
  {
    if (str[i] == '.')
    {
      arr.push_back(num);
      num = 0;
    }
    else if ('0' <= str[i] and str[i] <= '9')
    {
      num = num * 10 + (str[i] - '0');
    }
    else
    {
      return {-1};
    }
    i++;
  }
  if (str[str.length() - 1] != '.')
  {
    arr.push_back(num);
  }
  return arr;
}

bool IsValidInput(vector<int> &nums)
{
  if (nums.size() != 4)
    return false;
  for (int x : nums)
  {
    if (x > 255)
    {
      return false;
    }
  }
  return true;
}

void IP_net_id(string str)
{
  vector<int> nums = extractNumbers(str);
  if (!IsValidInput(nums))
  {
    cout << "Invalid input\n";
    return;
  }

  char ansClass;
  string netId, hostId;

  if (nums[0] <= 127)
  {
    ansClass = 'A';
    netId = to_string(nums[0]);
    hostId = to_string(nums[1]) + '.' + to_string(nums[2]) + '.' + to_string(nums[3]);
  }
  else if (nums[0] <= 191)
  {
    ansClass = 'B';
    netId = to_string(nums[0]) + '.' + to_string(nums[1]);
    hostId = to_string(nums[2]) + '.' + to_string(nums[3]);
  }
  else if (nums[0] <= 223)
  {
    ansClass = 'C';
    netId = to_string(nums[0]) + '.' + to_string(nums[1]) + '.' + to_string(nums[2]);
    hostId = to_string(nums[3]);
  }
  else if (nums[0] <= 239)
  {
    ansClass = 'D';
    netId = to_string(nums[0]) + '.' + to_string(nums[1]) + '.' + to_string(nums[2]) + '.' + to_string(nums[3]);
    hostId = "";
  }
  else
  {
    ansClass = 'E';
    netId = to_string(nums[0]) + '.' + to_string(nums[1]) + '.' + to_string(nums[2]) + '.' + to_string(nums[3]);
    hostId = "";
  }

  cout << "Class: " << ansClass << endl;
  cout << "Netid: " << netId << endl;
  cout << "HostId: " << hostId << endl;
}

int main()
{
  string str;
  char check = 'y';
  while (true)
  {
    cout << "\nEnter IP address in the form of string: ";
    cin >> str;
    IP_net_id(str);
    cout << "\nDo you want to enter more? (y/n): ";
    cin >> check;
    if (check == 'n' || check == 'N')
      break;
  }
}