// Implement Sliding window protocol

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
  srand(time(0));
  int frames, windowSize;
  int transmissions = 0;
  cout << "Enter no. of frames to send: ";
  cin >> frames;
  cout << "Enter the window size: ";
  cin >> windowSize;
  int i = 1;

  while (i <= frames)
  {
    int ackFrames = 0;
    for (int j = i; j < i + windowSize and j <= frames; j++)
    {
      cout << "Sending frame: " << j << endl;
      transmissions++;
    }

    for (int j = i; j < i + windowSize and j <= frames; j++)
    {
      int flag = rand() % 2;
      if (!flag)
      {
        cout << "Acknowledgement for frame " << j << " received" << endl;
        ackFrames++;
      }
      else
      {
        cout << "Frame " << j << " not received" << endl;
        cout << "Retransmitting all frames in the window" << endl;
        break;
      }
    }
    cout << endl;
    i += ackFrames;
  }
  cout << "Total no. of transmissions: " << transmissions << endl;
}