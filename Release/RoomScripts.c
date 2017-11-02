/**
 * Maniac Mansion: Retail
 *
 * Room Entry/Exit Scripts
 */

#include "zxscumm.h"
#include "MM.h"

int VAR_RESULT;

// TEMPORAL
int Var[255];

// Dummy function for rooms without Entry or Exit functions.
void R000_nothing (){

}

/**
 * Room 1: Front of Mansion
 */

void R001_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopSound(32);                                                       // Alarm 1
    /*[0004]*/ VAR_RESULT = isScriptRunning(58);                                    // is 'Cutscene: Win Game' running
    /*[0007]*/ if (VAR_RESULT == 0) {
    /*[000C]*/   startScript(52);                                                   // No? start 'Repeat Outside Sound'
    /*[000E]*/ }
    /*[000E]*/ stopObjectCode();
}

void R001_Exit(){
    /*[0000]*/ stopScript(52);                                                      // stop 'Repeat Outside Sound'
    /*[0002]*/ stopSound(38);
    /*[0004]*/ if (getState08(25)) {                                                // if Envelope in mailbox
    /*[0008]*/   if (Var[64] == 1) {                                                //  if Envelope Stamped
    /*[000D]*/     if (Var[85] == 1) {                                              //   if Envelope: Addressed
    /*[0012]*/       if (!getState08(17)) {                                         //    mailbox closed
    /*[0016]*/         if (getState08(18)) {                                        //     flag raised
    /*[001A]*/           VAR_RESULT = isScriptRunning(100);
    /*[001D]*/           if (VAR_RESULT == 0) {                                     //     if trigger not running
    /*[0022]*/             startScript(100);                                        //      start Cutscene: 3 Guys Who Pub Anything: Receive Mail Trigger
    /*[0024]*/           }
    /*[0024]*/         }
    /*[0024]*/       }
    /*[0024]*/     }
    /*[0024]*/   }
    /*[0024]*/ }
    /*[0024]*/ VAR_RESULT = isScriptRunning(6);                                     // Game: Meltdown Timer running
    /*[0027]*/ if (VAR_RESULT == 1) {                                               // if Game: Meltdown Timer running
    /*[002C]*/   startSound(32);                                                    //  start Alarm 1
    /*[002E]*/ }
    /*[002E]*/ stopObjectCode();
}


/**
 * Room 2: Bottom of Pool
 */

void R002_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopSound(32);                                                       // stop Alarm 1
    /*[0004]*/ loadSound(27);
    /*[0006]*/ stopObjectCode();
}

void R002_Exit(){
    /*[0000]*/ VAR_RESULT = isScriptRunning(6);                                     // if Game: Meltdown Timer running
    /*[0003]*/ if (VAR_RESULT == 1) {
    /*[0008]*/   startSound(32);                                                    //  start Alarm 1
    /*[000A]*/ }
    /*[000A]*/ stopObjectCode();
}


/**
 * Room 3: Downstairs Lounge Room
 */

void R003_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ VAR_RESULT = isScriptRunning(15);
    /*[0005]*/ if (VAR_RESULT == 1) {                                               // if Cassette: Play, Break Windows/Free Key running
    /*[000A]*/   startSound(25);                                                    //  Play Tentacle Mating Call
    /*[000C]*/ }
    /*[000C]*/ if (getState08(207)) {                                               // if Cassette Player is playing
    /*[0010]*/   if (Var[13] == 44) {                                               //  if Tape Contents == Melody Stinks
    /*[0015]*/     startSound(44);                                                  //   Play Bad Melody
    /*[0017]*/   }
    /*[0017]*/ }
    /*[0017]*/ if (Var[29] == 1) {                                                  // if Radio On
    /*[001C]*/   startSound(20);                                                    //  sound Radio Static
    /*[001E]*/ }
    /*[001E]*/ stopObjectCode();
}

void R003_Exit(){
    /*[0000]*/ stopSound(25);
    /*[0002]*/ stopSound(20);                                                       //  sound Radio Static
    /*[0004]*/ stopSound(29);
    /*[0006]*/ stopSound(44);
    /*[0008]*/ stopMusic();
    /*[0009]*/ stopObjectCode();
}


/**
 * Room 4: Dungeon
 */

void R004_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 5: Library
 */

void R005_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}

void R005_Exit(){
    /*[0000]*/ stopSound(24);                                                       // stop sound Library Phone Ring
    /*[0002]*/ stopSound(21);
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 6: Pool Area
 */
void R006_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopSound(32);                                                       // stop sound Alarm 1
    /*[0004]*/ stopObjectCode();
}

void R006_Exit(){
    /*[0000]*/ VAR_RESULT = isScriptRunning(6);                                     // Game: Meltdown Timer running
    /*[0003]*/ if (VAR_RESULT == 1) {
    /*[0008]*/   startSound(32);                                                    // start sound Alarm 1
    /*[000A]*/ }
    /*[000A]*/ stopObjectCode();
}


/**
 * Room 7: Kitchen
 */

void R007_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ if (!getState08(55)) {                                               // if Faucet On
    /*[0006]*/   startSound(17);                                                    //  sound Sink On
    /*[0008]*/ }
    /*[0008]*/ startScript(76);                                                     // start Jar / Envelop: Name
    /*[000A]*/ stopObjectCode();
}

void R007_Exit(){
    /*[0000]*/ stopSound(17);                                                       // sound Sink off
    /*[0002]*/ unlockScript(30);
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 8: Basement
 */

void R008_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ startScript(149);                                                    // start  -= Does Nothing =-
    /*[0004]*/ stopObjectCode();
}

void R008_Exit(){
    /*[0000]*/ stopScript(149);                                                     // stop  -= Does Nothing =-
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 9: Attic (Above Nurse Edna's Room)
 */

void R009_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 10: Main Entry
 */

void R010_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ startScript(18);                                                     // start Clock: Repeating Tick Sound
    /*[0004]*/ loadSound(28);
    /*[0006]*/ stopObjectCode();
}

void R010_Exit(){
    /*[0000]*/ stopScript(18);                                                      // stop Clock: Repeating Tick Sound
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 11: Top of Main Entry
 */

void R011_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 12: Level 2 Stairs to Level 3
 */

void R012_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ if (Var[80] == 0) {                                                  // if Green Tentacle: Has drank
    /*[0007]*/   if (Var[86] == 0) {                                                //  if Kid not in Level 2 - Level 3 hallway
    /*[000C]*/     putActorInRoom(14,12);                                           //   Put Green Tentacle
    /*[000F]*/     putActor(14,17,52);                                              //   Position Green Tentacle
    /*[0013]*/   }
    /*[0013]*/   VAR_RESULT = getActorRoom(ACT_Weird_Ed);
    /*[0016]*/   if (VAR_RESULT != 12) {                                            //   If Weird-Ed is not in 'Level 2 Stairs to Level 3'
    /*[001B]*/     startScript(45);                                                 //      start Green Tentacle: Block until player feeds
    /*[001D]*/   }
    /*[001D]*/ }
    /*[001D]*/ stopObjectCode();
}

void R012_Exit(){
    /*[0000]*/ stopScript(45);                                                      // stop Green Tentacle: Block until player feeds
    /*[0002]*/ stopScript(158);                                                     // stop Green Tentacle: Block player passing
    /*[0004]*/ if (Var[80] == 1) {                                                  // if Green Tentacle: Has drank == Yes
    /*[0009]*/   putActorInRoom(14,20);                                             // Put green tentacle in his room
    /*[000C]*/   putActor(14,68,58);
    /*[0010]*/   Var[86] = 0;                                                       // Kid is in Level 2 - Level 3 hallway = No
    /*[0013]*/ }
    /*[0013]*/ stopObjectCode();
}


/**
 * Room 13: Level 2 Main Hallway
 */

void R013_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 14: Portrait Painting
 */

void R014_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 15: Electrical Wiring
 */

void R015_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 16: Garage
 */

void R016_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopSound(32);
    /*[0004]*/ stopObjectCode();
}

void R160_Exit(){
    /*[0000]*/ VAR_RESULT = isScriptRunning(6);                                     // Game: Meltdown Timer running
    /*[0003]*/ if (VAR_RESULT == 1) {
    /*[0008]*/   startSound(32);                                                    // sound Alarm 1
    /*[000A]*/ }
    /*[000A]*/ stopObjectCode();
}


/**
 * Room 17: Music
 */

void R017_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ if (Var[23] == 1) {                                                  // if Victrola Playing
    /*[0007]*/   if (Var[75] == 25) {                                               //  and Record on Victrola == Tentacle Mating Call
    /*[000C]*/     startSound(25);                                                  //   sound Tentacle Mating Call
    /*[000E]*/   } else {                                                           // -
    /*[0011]*/     startSound(44);                                                  //   sound Bad Melody
    /*[0013]*/   }
    /*[0013]*/ }
    /*[0013]*/ stopObjectCode();
}

void R017_Exit(){
    /*[0000]*/ stopSound(25);                                                       // stop sound Tentacle Mating Call
    /*[0002]*/ stopSound(44);                                                       // stop sound Bad Melody
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 18: Video Game
 */

void R018_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 19: Nurse Edna's
 */

void R019_Entry(){
    /*[0000]*/ VAR_RESULT = getActorRoom(10);
    /*[0003]*/ if (VAR_RESULT == 19) {                                              // if nurse edna in her room
    /*[0008]*/   setBitVar(4,1,0);                                                  //  Lights on
    /*[000C]*/ }
    /*[000C]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[000E]*/ VAR_RESULT = isScriptRunning(25);
    /*[0011]*/ if (VAR_RESULT == 1) {                                               // if Phone: Ringing
    /*[0016]*/   startScript(25);                                                   //  start Phone: Ringing
    /*[0018]*/ }
    /*[0018]*/ stopObjectCode();
}


/**
 * Room 20: Green Tentacle's
 */

void R020_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ if (Var[80] == 1) {                                                  // if Green Tentacle: Has drank == Yes
    /*[0007]*/   startScript(103);                                                  //  start Green Tentacle: So Depressed
    /*[0009]*/ }
    /*[0009]*/ stopObjectCode();
}

void R020_Exit(){
    /*[0000]*/ stopScript(105);                                                     // stop Contract: Given to actor
    /*[0002]*/ stopScript(103);                                                     // stop Green Tentacle: So Depressed
    /*[0004]*/ clearState08(131);                                                   // turn off Mondo Stereo
    /*[0006]*/ stopSound(25);                                                       // stop sound Tentacle Mating Call
    /*[0008]*/ stopSound(20);                                                       // stop sound
    /*[000A]*/ stopSound(44);                                                       // stop sound Bad Melody
    /*[000C]*/ stopMusic();
    /*[000D]*/ stopObjectCode();
}


/**
 * Room 21: Radio
 */

void R021_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ if (Var[28] == 1) {                                                  // if Radio (Room 21) == On
    /*[0007]*/   startSound(20);                                                    //  start sound radio static
    /*[0009]*/ }
    /*[0009]*/ stopObjectCode();
}

void R021_Exit(){
    /*[0000]*/ stopSound(20);                                                       //  stop sound radio static
    /*[0002]*/ stopSound(29);
    /*[0004]*/ stopObjectCode();
}

/**
 * Room 22: Medical
 */

void R022_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 23: Darkroom
 */

void R023_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ startScript(78);                                                     // start DeveloperTray: Name
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 24: Gym Bathroom
 */

void R024_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}

void R024_Exit(){
    /*[0000]*/ stopSound(18);                                                       // stop sound
    /*[0002]*/ stopSound(17);                                                       // stop sound Sink On
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 25: Gym
 */

void R025_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ loadSound(30);
    /*[0004]*/ loadSound(31);
    /*[0006]*/ stopObjectCode();
}


/**
 * Room 26: Weird Ed's
 */

void R026_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}

void R026_Exit(){
    /*[0000]*/ VAR_RESULT = isScriptRunning(91);
    /*[0003]*/ if (VAR_RESULT == 1) {                                               // if Weird Ed: Help Find Plans running
    /*[0008]*/   setActorBitVar(Var[94],8,1);                                       //  Current kid is Eds' Enemy (kActorMiscFlagEdsEnemy)
    /*[000C]*/ }
    /*[000C]*/ stopScript(91);                                                      // stop Weird Ed: Help Find Plans
    /*[000E]*/ stopScript(111);                                                     // stop Weird Ed. Handle Object Interactions
    /*[0010]*/ VAR_RESULT = getActorRoom(ACT_Weird_Ed);
    /*[0013]*/ if (VAR_RESULT == 26) {                                              // if weird ed in his room
    /*[0018]*/   stopScript(86);                                                    //  stop Weird Ed: Check for fri}ly actors
    /*[001A]*/ }
    /*[001A]*/ stopObjectCode();
}


/**
 * Room 27: Typewriter
 */

void R027_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ if (Var[30] != 255) {                                                // if plant not dead
    /*[0007]*/   putActorInRoom(19,27);                                             //  Put Plant
    /*[000A]*/   putActor(19,33,44);                                                //  Position Plant
    /*[000E]*/   VAR_RESULT = isScriptRunning(48);                                  //  is Plant: Give Pepsi running
    /*[0011]*/   if (VAR_RESULT == 0) {
    /*[0016]*/     startScript(46);                                                 // start Plant Size
    /*[0018]*/   } else {
    /*[001B]*/     startScript(49);                                                 // start Plant: Burp
    /*[001D]*/   }
    /*[001D]*/   if (Var[30] == 0) {                                                // if Plant Size is small
    /*[0022]*/     animateActor(19,4,1);                                            // Plant
    /*[0026]*/   }
    /*[0026]*/   if (Var[30] == 1) {                                                // if Plant Size is medium
    /*[002B]*/     animateActor(19,5,1);                                            // Plant
    /*[002F]*/   }
    /*[002F]*/   if (Var[30] == 2) {                                                // if Plant Size is large
    /*[0034]*/     animateActor(19,6,1);                                            // Plant
    /*[0038]*/   }
    /*[0038]*/ }
    /*[0038]*/ stopObjectCode();
}

void R027_Exit(){
    /*[0000]*/ stopScript(46);                                                      // stop Plant Size
    /*[0002]*/ stopScript(49);                                                      // stop Plant: Burp
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 28: Telescope
 */

void R028_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 29: Underhouse
 */

void R029_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}

void R029_Exit(){
    /*[0000]*/ stopSound(18);
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 30: Lab: Zom-b-Matic
 */

void R030_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ putActorInRoom(23,30);                                               // Sandy (Lab) enters Lab: Zom-b-Matic
    /*[0005]*/ putActor(23,36,60);
    /*[0009]*/ animateActor(23,0,1);                                                // Sandy face camera (still)
    /*[000D]*/ animateActor(23,254,1);                                              // Sandy has mouth open
    /*[0011]*/ putActorInRoom(9,30);                                                // Dr Fred Enters Lab: Zom-b-Matic
    /*[0014]*/ putActor(9,38,66);
    /*[0018]*/ if (!getState08(143)) {                                              // if Switch on
    /*[001C]*/   startSound(59);
    /*[001E]*/ }
    /*[001E]*/ if (Var[89] == 1) {                                                  // Meteor Locked
    /*[0023]*/   startScript(122);                                                  //  start Dr Fred: Walk back and forth
    /*[0025]*/ }
    /*[0025]*/ if (Var[89] == 2) {                                                  // Meteor Loose
    /*[002A]*/   startScript(122);                                                  //  start Dr Fred: Walk back and forth
    /*[002C]*/ }
    /*[002C]*/ VAR_RESULT = isScriptRunning(37);
    /*[002F]*/ if (VAR_RESULT == 0) {                                               // if not running Cutscene: Meteor Police Arrived in Dungeon
    /*[0034]*/   startScript(124);                                                  // start Wait for actor finish walk. Activate sandy
    /*[0036]*/   if (Var[89] == 0) {
    /*[003B]*/     Var[89] = 1;                                                     // Meteor Locked
    /*[003E]*/     loadScript(118);                                                 // load Nuclear Meltdown Countdown
    /*[0040]*/     startScript(120);                                                // start Dr Fred: Entered Lab
    /*[0042]*/   }
    /*[0042]*/ }
    /*[0042]*/ loadSound(54);
    /*[0044]*/ stopObjectCode();
    }

void R030_Exit(){
    /*[0000]*/ stopScript(122);                                                     // stop Dr Fred: Entered Lab
    /*[0002]*/ stopScript(124);                                                     // Wait for actor finish walk. Activate sandy
    /*[0004]*/ stopSound(59);                                                       // stop sound
    /*[0006]*/ stopObjectCode();
}


/**
 * Room 31: Lab: Entry
 */

void R031_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}

void R031_Exit(){
    /*[0000]*/ unlockScript(43);
    /*[0002]*/ unlockSound(63);
    /*[0004]*/ stopScript(112);                                                     // stop Purple Tentacle: Check Actor X > 20; print "What are you doing here?"
    /*[0006]*/ stopScript(110);                                                     // stop Green Tentacle: Storm Dr. Freds Lab
    /*[0008]*/ stopScript(94);                                                      // stop Weird Ed: Storm Dr. Freds Lab
    /*[000A]*/ stopObjectCode();
}


/**
 * Room 32: Meteor Police
 */

void R032_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 33: Mansion At Distance (Lights Off)
 */

void R033_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}

void R033_Exit(){
    /*[0000]*/ stopSound(56);                                                       // stop sound Intro Comet
    /*[0002]*/ stopSound(57);
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 36: Storage / Leading out to pool
 */

void R036_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ loadSound(10);                                                       // sound Piggy Bank Break
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 37: Dining
 */

void R037_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 38: Level 3 Hallway
 */

void R038_Entry(){
    /*[0000]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 39: Video Game: High Scores
 */

void R039_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 40: 3 Guys who publish anything (TV)
 */

void R040_Entry(){
    /*[0000]*/ setState08(249);                                                     // < No Name >
    /*[0002]*/ lights(2);                                                           // Normal Lights
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 41: 3 Guys who publish anything (Office)
 */

void R041_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}

void R041_Exit(){
    /*[0000]*/ stopSound(25);                                                       // stop sound Tentacle Mating Call
    /*[0002]*/ stopSound(44);                                                       // stop sound Bad Melody
    /*[0004]*/ stopMusic();                                                         // stop music
    /*[0005]*/ VAR_RESULT = isScriptRunning(6);                                     // Game: Meltdown Timer running
    /*[0008]*/ if (VAR_RESULT == 1) {
    /*[000D]*/   startSound(32);                                                    // sound Alarm 1
    /*[000F]*/ }
    /*[000F]*/ stopObjectCode();
}


/**
 * Room 42: TV Show
 **/
void R042_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 43: Keypad
 */

void R043_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ loadSound(19);
    /*[0004]*/ stopObjectCode();
}


/**
 * Room 44: Welcome to Mansion
 */

void R044_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopSound(32);                                                       // stop sound Alarm 1
    /*[0004]*/ startScript(52);                                                     // start Repeat Outside Sound
    /*[0006]*/ stopObjectCode();
}

void R044_Exit(){
    /*[0000]*/ stopScript(52);                                                      // stop Repeat Outside Sound
    /*[0002]*/ stopSound(38);
    /*[0004]*/ VAR_RESULT = isScriptRunning(6);                                     // is Game: Meltdown Timer running
    /*[0007]*/ if (VAR_RESULT == 1) {
    /*[000C]*/   startSound(32);                                                    // sound Alarm 1
    /*[000E]*/ }
    /*[000E]*/ stopObjectCode();
}


/**
 * Room 45: Kid Selection
 */

void R045_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ Var[92] = 1;                                                         // Kid Select: Number Selected = 1 (Dave)
    /*[0005]*/ loadSound(54);
    /*[0007]*/ loadScript(109);                                                     // load script Intro: Kid Selection: Update Var States
    /*[0009]*/ stopObjectCode();
}



/**
 * Room 46: Top of mansion (Edsel)
 */

void R046_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}



/**
 * Room 47: Mansion At Distance (Lights On)
 */

void R047_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopSound(32);                                                       // stop sound Alarm 1
    /*[0004]*/ stopSound(33);                                                       // stop sound Alarm 2
    /*[0006]*/ stopObjectCode();
}

/**
 * Room 48: Edsel in Space
 */
void R048_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 49: "MANIAC MANSION" Scrolling
 */
void R049_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopObjectCode();
}


/**
 * Room 50: Load / Save Screen
 */
void R050_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ loadSound(19);                                                       // load sound Light Beep
    /*[0004]*/ stopSound(32);                                                       // stop sound Alarm 1
    /*[0006]*/ stopObjectCode();
}

void R050_Exit(){
    /*[0000]*/ VAR_RESULT = isScriptRunning(6);                                     // Game: Meltdown Timer running
    /*[0003]*/ if (VAR_RESULT == 1) {
    /*[0008]*/   startSound(32);                                                    // sound Alarm 1
    /*[000A]*/ }
    /*[000A]*/ stopObjectCode();
}


/**
 * Room 51: Lab: Meteor
 */

void R051_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ loadScript(121);
    /*[0004]*/ if (Var[18] == 0) {                                                  // if Meteor Location == Meteor Room
    /*[0009]*/   putActorInRoom(16,51);                                             // put meteor in meteor room
    /*[000C]*/   putActor(16,40,50);
    /*[0010]*/   animateActor(16,0,1);
    /*[0014]*/   VAR_RESULT = isScriptRunning(37);
    /*[0017]*/   if (VAR_RESULT == 0) {                                             // if not running Cutscene: Meteor Police Arrived in Dungeon
    /*[001C]*/     loadCostume(20);
    /*[001E]*/     lockCostume(20);
    /*[0020]*/     startScript(123);                                                // start Meteor: Fire Radiation
    /*[0022]*/   }
    /*[0022]*/ }
    /*[0022]*/ if (!getState08(143)) {                                              // if Switch switched
    /*[0026]*/   startSound(59);                                                    //  sound Machine power down
    /*[0028]*/   loadScript(121);                                                   //  start Dr Fred: Free of machines control
    /*[002A]*/ }
    /*[002A]*/ loadScript(123);                                                     // start Meteor: Fire Radiation
    /*[002C]*/ stopObjectCode();
}

void R051_Exit(){
    /*[0000]*/ stopSound(59);
    /*[0002]*/ putActorInRoom(20,0);                                                // Meteor Radiation leaves room
    /*[0005]*/ putActor(20,0,0);
    /*[0009]*/ stopScript(123);                                                     // stop Meteor: Fire Radiation
    /*[000B]*/ stopObjectCode();
}


/**
 * Room 52: Garage Destroyed
 */

void R052_Entry(){
    /*[0000]*/ lights(2);                                                           // Normal Lights
    /*[0002]*/ stopSound(32);                                                       // stop sound Alarm 1
    /*[0004]*/ stopObjectCode();
}

void R052_Exit(){
    /*[0000]*/ VAR_RESULT = isScriptRunning(6);                                     // Game: Meltdown Timer running
    /*[0003]*/ if (VAR_RESULT == 1) {
    /*[0008]*/   startSound(32);                                                    // soumd Alarm 1
    /*[000A]*/ }
    /*[000A]*/ stopObjectCode();
}
