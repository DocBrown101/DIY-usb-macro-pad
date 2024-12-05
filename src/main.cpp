#include <Arduino.h>
#include <OneButton.h>
#include "keyboardHelper.h"

/*
Physical layout of the USB Macro Pad with button functions:

+-----------------------------------+------------------------------------+-----------------------------------+
| buttons[2] (black)                | buttons[1] (green)                 | buttons[0] (red)                  |
| Pin: 18                           | Pin: 17                            | Pin: 16                           |
| Click: mediaToggleMute            | Click: msTeamsToggleVideo          | Click: msTeamsToggleMute          |
| LongPress: msTeamsToggleRaiseHand | LongPress: msTeamsStartScreenShare | LongPress: msTeamsEndCall         |
+-----------------------------------+------------------------------------+-----------------------------------+
| buttons[3] (left)                 | buttons[4] (middle)                | buttons[5] (right)                |
| Pin: 10                           | Pin: 11                            | Pin: 12                           |
| Click: mediaVolumeUp              | Click: mediaVolumeDown             | Click: vsCodeCommentCodeBlock     |
| Hold: mediaVolumeUpDelayed        | Hold: mediaVolumeDownDelayed       | LongPress: vsCodeFormatSelection  |
+-----------------------------------+------------------------------------+-----------------------------------+
*/
OneButton buttons[6] = {
    OneButton(16), // Button 0
    OneButton(17), // Button 1
    OneButton(18), // Button 2
    OneButton(10), // Button 3
    OneButton(11), // Button 4
    OneButton(12)  // Button 5
};

void setup()
{
  buttons[0].attachClick(msTeamsToggleMute);
  buttons[1].attachClick(msTeamsToggleVideo);
  buttons[2].attachClick(mediaToggleMute);
  buttons[3].attachClick(mediaVolumeUp);
  buttons[4].attachClick(mediaVolumeDown);
  buttons[5].attachClick(vsCodeCommentCodeBlock);

  buttons[0].attachLongPressStart(msTeamsEndCall);
  buttons[1].attachLongPressStart(msTeamsStartScreenShare);
  buttons[2].attachLongPressStart(msTeamsToggleRaiseHand);
  buttons[5].attachLongPressStart(vsCodeFormatSelection);

  buttons[4].attachDoubleClick(sendDropboxUrl);

  buttons[3].attachDuringLongPress(mediaVolumeUpDelayed);
  buttons[4].attachDuringLongPress(mediaVolumeDownDelayed);

  for (OneButton &button : buttons)
  {
    button.setDebounceMs(40);
    button.setClickMs(150);
  }

  initKeyboard();
}

void loop()
{
  for (OneButton &button : buttons)
  {
    button.tick();
  }
}
