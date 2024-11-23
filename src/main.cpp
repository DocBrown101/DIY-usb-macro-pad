#include <Arduino.h>
#include <OneButton.h>
#include <vector>
#include "keyboardHelper.h"

std::vector<OneButton> buttons;

/*
Physical layout of the USB Macro Pad with button functions:

+-----------------------------------+------------------------------------+-----------------------------------+
| btn3 (black)                      | btn2 (green)                       | btn1 (red)                        |
| Pin: 18                           | Pin: 17                            | Pin: 16                           |
| Click: mediaToggleMute            | Click: msTeamsToggleVideo          | Click: msTeamsToggleMute          |
| LongPress: msTeamsToggleRaiseHand | LongPress: msTeamsStartScreenShare | LongPress: msTeamsEndCall         |
+-----------------------------------+------------------------------------+-----------------------------------+
| btn4 (left)                       | btn5 (middle)                      | btn6 (right)                      |
| Pin: 10                           | Pin: 11                            | Pin: 12                           |
| Click: mediaVolumeUp              | Click: mediaVolumeDown             | Click: vsCodeCommentCodeBlock     |
| Hold: mediaVolumeUpDelayed        | Hold: mediaVolumeDownDelayed       | LongPress: vsCodeFormatSelection  |
+-----------------------------------+------------------------------------+-----------------------------------+
*/
OneButton btn1(16);
OneButton btn2(17);
OneButton btn3(18);
OneButton btn4(10);
OneButton btn5(11);
OneButton btn6(12);

void setup()
{
  btn1.attachClick(msTeamsToggleMute);
  btn2.attachClick(msTeamsToggleVideo);
  btn3.attachClick(mediaToggleMute);
  btn4.attachClick(mediaVolumeUp);
  btn5.attachClick(mediaVolumeDown);
  btn6.attachClick(vsCodeCommentCodeBlock);

  btn1.attachLongPressStart(msTeamsEndCall);
  btn2.attachLongPressStart(msTeamsStartScreenShare);
  btn3.attachLongPressStart(msTeamsToggleRaiseHand);
  btn6.attachLongPressStart(vsCodeFormatSelection);

  btn4.attachDuringLongPress(mediaVolumeUpDelayed);
  btn5.attachDuringLongPress(mediaVolumeDownDelayed);

  buttons.push_back(btn1);
  buttons.push_back(btn2);
  buttons.push_back(btn3);
  buttons.push_back(btn4);
  buttons.push_back(btn5);
  buttons.push_back(btn6);

  for (uint i = 0; i < buttons.size(); i++)
  {
    buttons.at(i).setDebounceMs(40);
    buttons.at(i).setClickMs(150);
  }
}

void loop()
{
  for (uint i = 0; i < buttons.size(); i++)
  {
    buttons.at(i).tick();
  }
}
