# SMT IV Fiend Fixer - Checkpoint script

### Based on [Robin8bit's tool](https://gamebanana.com/tools/23039). I only converted their script.

This is a script for Checkpoint that modifies your Shin Megami Tensei IV save file to override the 1/256 check that determines if the fiends can spawn. The original tool required you to export the save to your computer and reimport it, but with Checkpoint's new scripting funcionality, it can now be done directly on the 3DS.

Requires [Checkpoint 5.0.0 or greater](https://github.com/BernardoGiordano/Checkpoint).

Tested on the first save file of the European version of the game. **Use at your own risk, and don't forget to make a backup first**. 

## Instructions
1) On your 3DS's SD card, create a folder inside `3ds/Checkpoint/scripts` with the TID of your version of the game. (For the European version, that would be `3ds/Checkpoint/scripts/0004000000141C00`).
2) Copy the `.c` file to that folder.
3) On your 3DS, having saved your game on a location where fiends can spawn, open Checkpoint and select the game on the menu. Make a backup if you want to.
4) Press `SELECT`, open the scripts menu and scroll down. You should see this script listed among the options.
5) Select which of your 2 saves you wish to modify.
6) If everything goes alright, you can close Checkpoint and boot the game. The fiends will now spawn.
