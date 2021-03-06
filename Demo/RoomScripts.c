/**
 * Maniac Mansion: Demo
 *
 * Room Entry/Exit Scripts
 */


/**
 * Room 1: Front of Mansion
 */

Entry-1 {
    [0000] lights(2);                                                           // Normal Lights
    [0002] startScript(20);                                                     // start Repeat Outside Sound
    [0004] stopObjectCode();
}

Exit-1 {
    [0000] stopScript(20);                                                      // stop Repeat Outside Sound
    [0002] stopSound(25);                                                       // stop sound
    [0004] stopObjectCode();
}


/**
 * Room 3: Downstairs Lounge Room
 */

Entry-3 {
    [0000] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0002] if (getState08(207)) {                                               // is Cassette Player is playing
    [0006]   startScript(48);                                                   //  start Demo: Advertisement Recording
    [0008] }
    [0008] if (Var[29] == 1) {                                                  // if Radio On
    [000D]   startSound(16);                                                    //  Play Music
    [000F] }
    [000F] stopObjectCode();
}

Exit-3 {
    [0000] stopSound(16);                                                       //
    [0002] stopSound(23);                                                       //
    [0004] stopScript(48);                                                      // stop Demo: Advertisement Recording
    [0006] stopObjectCode();
}


/**
 * Room 5: Library
 */

Entry-5 {
    [0000] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0002] if (Var[136] == 1) {                                                 // if On Phone
    [0007]   startScript(48);                                                   //  start Demo: Advertisement Recording
    [0009] }
    [0009] stopObjectCode();
}

Exit-5 {
    [0000] stopSound(17);                                                       // stop sound Library Phone Ring
    [0002] stopScript(48);                                                      // stop Tape Player: Play Tape
    [0004] stopObjectCode();
}


/**
 * Room 6: Pool Area
 */

Entry-6 {
    [0000] lights(2);                                                           // Normal Lights
    [0002] stopObjectCode();
}


/**
 * Room 7: Kitchen
 */

Entry-7 {
    [0000] startScript(19);                                                     // Room Lights: Check for flashlight / room light status
    [0002] if (!getState08(55)) {                                               // if Faucet On
    [0006]   startSound(14);                                                    //  sound Sink On
    [0008] }
    [0008] startScript(39);                                                     // start Sponge: Name
    [000A] stopObjectCode();
}

Exit-7 {
    [0000] stopSound(14);                                                       // sound Sink off
    [0002] stopObjectCode();
}


/**
 * Room 8: Basement
 */

Entry-8 {
    [0000] startScript(19);                                                     // Room Lights: Check for flashlight / room light status
    [0002] stopObjectCode();
}


/**
 * Room 10: Main Entry
 */

Entry-10 {
    [0000] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0002] startScript(11);                                                     // start Clock: Repeating Tick Sound
    [0004] loadSound(22);
    [0006] stopObjectCode();
}

Exit-10 {
    [0000] stopScript(11);                                                      // stop Clock: Repeating Tick Sound
    [0002] stopObjectCode();
}

/**
 * Room 31: Lab: Entry
 */

Entry-31 {
    [0000] lights(2);                                                           // Normal Lights
    [0002] stopObjectCode();
}

Exit-31 {
    [0000] unlockSound(34);
    [0002] stopObjectCode();
}


/**
 * Room 33: Mansion At Distance (Lights Off)
 */
Entry-33 {
    [0000] lights(2);                                                           // Normal Lights
    [0002] stopObjectCode();
}

Exit-33 {
    [0000] stopSound(31);
    [0002] stopSound(32);
    [0004] stopObjectCode();
}

/**
 * Room 36: Storage / Leading out to pool
 */
Entry-36 {
    [0000] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0002] loadSound(9);
    [0004] stopObjectCode();
}

/**
 * Room 37: Dining
 */
Entry-37 {
    [0000] startScript(19);                                                     // start Room Lights: Check for flashlight / room light status
    [0002] stopObjectCode();
}

/**
 * Room 43: Keypad
 */
Entry-43 {
    [0000] lights(2);                                                           // Normal Lights
    [0002] loadSound(15);
    [0004] stopObjectCode();
}

/**
 * Room 45: Kid Selection
 */
Entry-45 {
    [0000] lights(2);                                                           // Normal Lights
    [0002] loadSound(29);
    [0004] stopObjectCode();
}

/**
 * Room 49: "MANIAC MANSION" Scrolling
 */
Entry-49 {
    [0000] lights(2);                                                           // Normal Lights
    [0002] stopObjectCode();
}
