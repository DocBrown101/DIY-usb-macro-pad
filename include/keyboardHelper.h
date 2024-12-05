#ifndef keyboardHelper_H /* include guards */
#define keyboardHelper_H

#define HID_CUSTOM_LAYOUT
#define LAYOUT_GERMAN

#include <Arduino.h>
#include "HID-Project.h"

void initKeyboard()
{
  Keyboard.begin();
}

// https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf
void vsCodeCommentCodeBlock()
{
  // Alt+Shift+A - Toggle block comment
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('a');

  delay(100);
  Keyboard.releaseAll();
}

void vsCodeFormatSelection()
{
  // keyboard.key_code('k', KEY_CTRL); // Ctrl+K
  delay(100);
  // keyboard.key_code('f', KEY_CTRL); // Ctrl+F
}

// https://support.microsoft.com/en-us/office/keyboard-shortcuts-for-microsoft-teams-2e8e2a70-e8d8-4a19-949b-4c36dd5292d2
void msTeamsToggleRaiseHand()
{
  // Ctrl+Shift+K - Raise or lower your hand
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('k');

  delay(100);
  Keyboard.releaseAll();
}

void msTeamsToggleVideo()
{
  // keyboard.key_code('o', KEY_CTRL | KEY_SHIFT); // Ctrl+Shift+O - Toggle video
}

void msTeamsToggleMute()
{
  // keyboard.key_code('m', KEY_CTRL | KEY_SHIFT); // Ctrl+Shift+M - Toggle mute
}

void msTeamsStartScreenShare()
{
  // keyboard.key_code('e', KEY_CTRL | KEY_SHIFT); // Ctrl+Shift+E - Start screen share
}

void msTeamsEndCall()
{
  // keyboard.key_code('h', KEY_CTRL | KEY_SHIFT); // Ctrl+Shift+H - End audio / video call
}

void mediaToggleMute()
{
  Keyboard.write(KEY_VOLUME_MUTE);
  // keyboard.media_control(KEY_MUTE);
}

void mediaVolumeUp()
{
  // keyboard.media_control(KEY_VOLUME_UP);
}

void mediaVolumeUpDelayed()
{
  // keyboard.media_control(KEY_VOLUME_UP);
  delay(75);
}

void mediaVolumeDown()
{
  // keyboard.media_control(KEY_VOLUME_DOWN);
}

void mediaVolumeDownDelayed()
{
  // keyboard.media_control(KEY_VOLUME_DOWN);
  delay(75);
}

void sendDropboxUrl()
{
  Keyboard.print("https://www.dropbox.com/account/plan?role=personal");
}

#endif
