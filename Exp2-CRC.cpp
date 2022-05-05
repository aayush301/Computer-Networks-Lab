// Implement Cyclic redundancy check

#include <iostream>
using namespace std;

string XOR(string a, string b)
{
  string ans = "";
  for (int i = 0; i < a.length(); i++)
    (a[i] == b[i]) ? (ans += '0') : ans += '1';
  return ans;
}

string mod2Div(string dividend, string divisor)
{
  int n = dividend.length();
  int pos = divisor.length();
  string temp = dividend.substr(0, pos);

  while (pos <= n)
  {
    if (temp[0] == '1')
      temp = XOR(temp, divisor).substr(1) + dividend[pos];
    else
      temp = temp.substr(1) + dividend[pos];
    pos++;
  }
  return temp;
}

string CRC(string dataword, string divisor, int n, int k)
{
  string augDataword = dataword + string(n - k, '0');
  string remainder = mod2Div(augDataword, divisor);
  string codeword = dataword + remainder;
  return codeword;
}

int main()
{
  int n, k;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter k: ";
  cin >> k;

  string dataword, divisor;
  cout << "Enter dataword of size " << k << " in the form of string: ";
  cin >> dataword;
  cout << "Enter divisor of size " << n - k + 1 << " in the form of string: ";
  cin >> divisor;

  string codeword = CRC(dataword, divisor, n, k);
  cout << "The codeword produced is: " << codeword << endl;
}