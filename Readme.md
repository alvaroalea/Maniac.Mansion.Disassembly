# Maniac Mansion for ZX Spectrum

The idea is to reuse the awesome work of Robert Crossfield to create a version of the game for ZX Spectrum (problably for +3 or DivIde)

This is "work in progress" and probably never finished.

## ROADMAP / TASKs

The main idea it's not use a VM (SCUMM) but a compiled version.
creating a library with the scumm core and convert the information from Robert to compilable files
the create several routines for mouse/graphics, and glue everything together.

The best way is to make something in pure C, compiled on a PC, and after it work, move to spectrum
With a bit of lucky using conditional compilation can reuse most of the code.

### Mouse driver
Create some code to manage the mouse and keyboard, I will like to include suport for:
- AMX mouse
- Kempston/Genious mouse
- Amiga/Atari mouse on kempston joystick interface
- OPQA and Space (no there will not be a option for QAOP, sorry folks)

There is a routine in microhobby magazine that can be usefull, also velesoft has a lot of information.

### Screen scenery / room graphics

Ripped graphics from PC game show a maximun of 1024x128 pixels for each room.
Using gimp filters, can be comverted to monocrome bitmaps.
This is a maximun of 16Kb, the general idea is to store each room in a file and load from disk as needed.


Screen organization will be:
128 pixels for the room
8 pixels for the messages and generation of phrases
56 pixels for the icons and other things. 

Room graphics will be stored compressed, my idea is organiced it in chunks of 8 pixel wide columns, with the adecuate routine of horizontal scroll this will allow a fast scroll of the entire room.

relative position of the room an mouse position on clicks will be managed to return a absolute position of mouse in the room for use in the scripts, etc...

### Scumm

The "code" of the game it's split in three posibilities:
- Code that execute on enter and exit of rooms.
- Code that execute on interaction with objets.
- Scripts or Subroutines that are called from (I don't know).

As far as I know, first two have not problem and can be compiled
But Scripts are executed in thread along the game (I think a maximun of 8 thread)
This need to be investigated in deep. 

excel file need to be translated to a junk of .h include files and general data for use with the game.


## Some interesting references
http://wiki.scummvm.org/index.php/About
http://wiki.scummvm.org/index.php/SCUMM/Virtual_Machine
http://wiki.scummvm.org/index.php/SCUMM/Technical_Reference

https://github.com/juj/emscripten-scummvm
https://github.com/jamesu/scummc

https://bitbucket.org/jestar_jokin/scummpacker
http://www.jestarjokin.net/apps/scummimg/



# NOW, The original readme.md:

# Maniac Mansion v0 Demo / Retail Disassembly
## About

Commented disassembly of game scripts, and spreadsheets which detail room objects, variables and their usage for both the demo and the retail release.


## Notes

* This is not meant to be recompilable.
* Files are .c for preview highlighting purposes

## Files

### Generic

File | Purpose
---- | -------
V0_Room_Map_Tree.png | V0 - Connections
V0_Room_Map.png | V0
V2_Room_Map.png | V2


### Demo/Release Specific Files

File | Purpose
---- | -------
ManiacMansion.xlsx | Lists of Actors, Objects, Variables, Sounds, Scripts and their Names, States, Purposes.
Scripts.c | Disassembly of Global scripts
RoomScripts.c | Disassembly of Room Entry/Exit scripts
ObjectScripts.c | Disassembly of Object scripts
