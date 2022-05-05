// Implement Stop and wait protocol

#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

int main()
{
  srand(time(0));
  int frames = rand() % 8;
  int timeLimit = 2;
  cout << "No. of frames to send: " << frames << endl;
  cout << "The timer will run for max of: " << timeLimit << " seconds\n";
  int i = 1;

  while (frames > 0)
  {
    cout << "\n\nSending frame: " << i;
    int t = 1;
    for (t = 1; t <= timeLimit; t++)
    {
      cout << "\nWaiting for " << t << " seconds";
      Sleep(1000);
      if (rand() % 2 == 0) // if true, then ACK received
        break;
    }

    if (t > timeLimit)
    {
      cout << "\nTimeout... ";
      continue;
    }
    else
    {
      cout << "\nAck for frame " << i << " received";
      frames--;
      i++;
    }
  }
  cout << endl
       << endl;
}