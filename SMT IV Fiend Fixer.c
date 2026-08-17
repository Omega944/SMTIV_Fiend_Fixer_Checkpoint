#include <checkpoint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* SMT IV Fiend Fixer - Original tool and research made by Robin8bit, ported by Omega944 */

/* This Checkpoint script modifies the chosen save file to force fiends to spawn, bypassing the 1/256 chance of them appearing. */

/* Tested on the European version of Shin Megami Tensei IV (TID 0004000000141C00) */

int main(int argc, char** argv)
{
 	char* data;
    int size;
    int handle;
    int res;
    int sav_opt;
    char* sav_rel_path[2];
    char* sav_name[2];

    sav_rel_path[0] = "/sdds4game1.sav";
    sav_rel_path[1] = "/sdds4game2.sav";
    sav_name[0] = "Save 1";
    sav_name[1] = "Save 2";

    handle = sav_open(title_find(argv[0]), 0);
    if (handle < 0) {
        printf("Couldn't access the save files: %d\n", handle);
        gui_message("Couldn't access the save files.");
        return -1;
    }

    sav_opt = gui_pick_one("Choose the save file you wish to modify:", sav_name, 2);

    res = sav_read(handle, sav_rel_path[sav_opt], &data, &size);
    if (res != 0 || size < 4) {
        printf("Couldn't read the selected save file: %d\n", res);
        gui_message("Couldn't access the save file. Does it exist?.");
        sav_close(handle);
        return -1;
    }

    /* Forcing fiend RNG: */
    data[0xBAD2] = 0xFF;
    data[0xBAD3] = 0xFF;

    res = sav_write(handle, sav_rel_path[sav_opt], data, size);
    if (res == 0) {
        res = sav_commit(handle);
    } else {
    	printf("Couldn't write to the selected save file: %d\n", res);
    }

    free(data);
    free(sav_rel_path);
    free(sav_name);
    sav_close(handle);
    if(!res) gui_message("Fiend spawn forced succesfully.\nGood luck!");
    else gui_message("Something went wrong. No changes have been made.");
    return res;
}