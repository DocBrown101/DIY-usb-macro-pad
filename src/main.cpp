#include <Arduino.h>
#include <OneButton.h>
#include <vector>
#include "keyboardHelper.h"

std::vector<OneButton> buttons;

OneButton btn1(16); // red
OneButton btn2(17); // green
OneButton btn3(18); // black
OneButton btn4(10); // left
OneButton btn5(11); // middle
OneButton btn6(12); // right

void setup()
{
  btn1.attachClick(msTeamsToggleMute);              // red
  btn2.attachClick(msTeamsToggleVideo);             // green
  btn3.attachClick(mediaToggleMute);                // black
  btn4.attachClick(mediaVolumeUp);                  // left
  btn5.attachClick(mediaVolumeDown);                // middle
  btn6.attachClick(vsCodeCommentCodeBlock);         // right

  btn1.attachLongPressStart(msTeamsEndCallSession);           // red
  btn2.attachLongPressStart(msTeamsStartScreenShareSession);  // green
  btn3.attachLongPressStart(msTeamsToggleRaiseYourHand);      // black
  btn6.attachLongPressStart(vsCodeFormatSelection);           // right

  btn4.attachDuringLongPress(mediaVolumeUpDelayed);           // left
  btn5.attachDuringLongPress(mediaVolumeDownDelayed);         // middle

  buttons.push_back(btn1);
  buttons.push_back(btn2);
  buttons.push_back(btn3);
  buttons.push_back(btn4);
  buttons.push_back(btn5);
  buttons.push_back(btn6);

  for (uint i = 0; i < buttons.size(); i++)
  {
    buttons.at(i).setDebounceTicks(40);
    buttons.at(i).setClickTicks(150);
  }
}

void loop()
{
  for (uint i = 0; i < buttons.size(); i++)
  {
    buttons.at(i).tick();
  }
}
