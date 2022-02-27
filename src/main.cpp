#include <Arduino.h>
#include <OneButton.h>
#include <vector>

#include "keyboardHelper.h"

std::vector<OneButton> buttons;

OneButton redButton(16);
OneButton greenButton(17);
OneButton blackButton(18);

OneButton leftButton(10);
OneButton middleButton(11);
OneButton rightButton(12);

void setup()
{
  redButton.attachClick(msTeamsToggleMute);
  buttons.push_back(redButton);

  greenButton.attachClick(msTeamsToggleVideo);
  buttons.push_back(greenButton);

  blackButton.attachClick(msTeamsToggleRaiseYourHand);
  blackButton.attachLongPressStart(msTeamsStartScreenShareSession);
  buttons.push_back(blackButton);

  leftButton.attachClick(msTeamsStartScreenShareSession);
  buttons.push_back(leftButton);

  middleButton.attachClick(msTeamsEndCallSession);
  buttons.push_back(middleButton);

  rightButton.attachClick(vsCodeCommentCodeBlock);
  buttons.push_back(rightButton);

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