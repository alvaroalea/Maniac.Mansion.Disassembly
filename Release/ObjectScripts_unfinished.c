/**
 * Room 15: Electrical Wiring
 */

/** Hatch **/
//roomobj-15-202.dmp
      case 202:
		 switch (action){

		    case VER_Open:
    /*[001F]*/ startScript(4);                                                      // start Door: Open
    /*[0021]*/ setState08(69);                                                      // Open Door (Typewriter)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0024]*/ startScript(5);                                                      // start Door: Close
    /*[0026]*/ clearState08(69);                                                    // Close Door (Typewriter)
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Pull:
    /*[0029]*/ if (getState08(activeObject)) {                                      // If Door open
    /*[002C]*/   startScript(5);                                                    //  start Door: Close
    /*[002E]*/ } else {                                                             // -
    /*[0031]*/   startScript(4);                                                    //  start Door: Open
    /*[0033]*/ }
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0034]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0037]*/   loadRoomWithEgo(69,27);                                            //  Enter Typewriter
    /*[003A]*/ }
    /*[003A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Wires **/
//roomobj-15-204.dmp
      case 204:
		 switch (action){

Fix.		    case VER_Use:
    /*[0027]*/ if (!getState08(activeObject)) {                                     // If Wires Broken
    /*[002A]*/   if (getState08(124)) {                                             //  If Power Off
    /*[002E]*/     if (activeObject2 == 119) {                                      //   if using with Tools
    /*[0032]*/       VAR_RESULT = getObjectOwner(51);
    /*[0035]*/       if (VAR_RESULT == VAR_EGO) {                                   //    if Player owns Flashlight?
    /*[003A]*/         if (Var[12] == 1) {                                          //     if Flashlight Status == On
    /*[003F]*/           setState08(activeObject);                                              //      Wires fixed
    /*[0040]*/           printEgo("There, that should do it.");
    /*[0057]*/           startScript(96);                                           //      start Dr Fred: Play Meteor Mess
    /*[0059]*/         } else {                                                     // -
    /*[005F]*/           goto 0086;
    /*[0062]*/         }
    /*[0062]*/       }
    /*[0062]*/       printEgo("It's kind of dark,/but I think I fixed it.");
    /*[0086]*/     }
    /*[0086]*/   } else {                                                           // -
    /*[0089]*/     doSentence(1,204,0);                                             // Open Wires
    /*[008D]*/   }
    /*[008D]*/ }
    /*[008D]*/ //stopObjectCode();                                                    // --
		break;


Open.Close.TurnOn.TurnOff.		case Push:Pull.		    case VER_PickUp:
    /*[008E]*/ if (!getState08(activeObject)) {                                     // If wires broken
    /*[0091]*/   if (!getState08(124)) {                                            //  If power on
    /*[0095]*/     printEgo("YOWL!!!");
    /*[009E]*/     startSound(27);                                                  //   Sound Zapp
    /*[00A0]*/   } else {                                                           // -
    /*[00A3]*/     printEgo("I can't fix it with my bare hands!");
    /*[00C0]*/   }
    /*[00C0]*/ }
    /*[00C0]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Boarded up Window **/
//roomobj-15-399.dmp
      case 399:
		 switch (action){
/* Events:
  Open - 0029
   Fix - 0040
  Pull - 0029
   Use - 0040
*/
		case VER_Open:
		case VER_Pull:
    /*[0029]*/ printEgo("The boards won't budge.");                                 //
    /*[003F]*/ //stopObjectCode();                                                    // --
		break;


Fix.		    case VER_Use:
    /*[0040]*/ if (activeObject2 == 119) {                                          // If use with Tools
    /*[0044]*/   printEgo("Hmm. I don't have the right tool.");
    /*[0061]*/ }
    /*[0061]*/ //stopObjectCode();                                                    // --
		break;

        }       // end switch_action 386
        break;  // end obj 386



/** Light **/
//roomobj-15-401.dmp
      case 401:
		 switch (action){

		case VER_TurnOn:
    /*[0019]*/ startSound(12);                                                      // sound Light Switch
    /*[001B]*/ setBitVar(VAR_ROOM,1,0);                                             // Light On
    /*[001F]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0022]*/ startSound(12);                                                      // sound Light Switch
    /*[0024]*/ setBitVar(VAR_ROOM,1,1);                                             // Light Off
    /*[0028]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Wires **/
//roomobj-15-415.dmp




/**
 * Room 16: Garage
 */


/** < Unnamed > **/
//roomobj-16-101.dmp



/** Gate **/
//roomobj-16-110.dmp
      case 110:
		 switch (action){

Open.		    case VER_Pull:
    /*[001E]*/ if (!getState04(activeObject)) {                                     // If gate is unlocked
    /*[0021]*/   startScript(116);                                                  //  start Verb: Generic: Open Door
    /*[0023]*/   setState08(105);                                                   //  Open Gate (Pool Area)
    /*[0025]*/ } else {                                                             // -
    /*[0028]*/   printEgo("It's locked.");
    /*[0035]*/ }
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;


Close.		    case VER_Push:
    /*[0036]*/ startScript(117);                                                    // start Verb: Generic: Close Door
    /*[0038]*/ clearState08(105);                                                   // Close Gate (Pool Area)
    /*[003A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[003B]*/ if (getState08(activeObject)) {                                      // If gate is open
    /*[003E]*/   loadRoomWithEgo(105,6);                                            // Enter Pool Area
    /*[0041]*/ }
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;

        }       // end switch_action 386
        break;  // end obj 386



/** Garage Door **/
//roomobj-16-111.dmp
      case 111:
		 switch (action){

Open.		    case VER_Pull:
    /*[0021]*/ Var[90] = getActorBitVar(VAR_EGO,1);                                 // Current Actor Flag kActorMiscFlagStrong
    /*[0025]*/ if (Var[90] == 1) {                                                  // Kid is strong?
    /*[002A]*/   startScript(8);                                                    //  start Garage Door Open
    /*[002C]*/ } else {                                                             // -
    /*[002F]*/   printEgo("Ugh! I can't budge it!");
    /*[0043]*/ }
    /*[0043]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[0044]*/ printEgo("It's stuck.");                                             // Unlock
    /*[0050]*/ //stopObjectCode();                                                    // --
		break;

        }       // end switch_action 386
        break;  // end obj 386




/** Garage Door **/
//roomobj-16-112.dmp
      case 112:
		 switch (action){

Open.		    case VER_Pull:
    /*[0021]*/ doSentence(1,111,0);                                                 // Open Garage Door
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[0026]*/ doSentence(8,111,0);                                                 // Unlock Garage Door
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Garage Door **/
//roomobj-16-113.dmp
      case 113:
		 switch (action){

		    case VER_Open:
    /*[0021]*/ doSentence(1,111,0);                                                 // Open Garage Door
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[0026]*/ doSentence(8,111,0);                                                 // Unlock Garage Door
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Garage Door **/
//roomobj-16-114.dmp
      case 114:
		 switch (action){

Open.		    case VER_Pull:
    /*[0021]*/ doSentence(1,111,0);                                                 // Open Garage Door
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[0026]*/ doSentence(8,111,0);                                                 // Unlock Garage Door
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Garage Door **/
//roomobj-16-115.dmp
      case 115:
		 switch (action){

Open.		    case VER_Pull:
    /*[0021]*/ doSentence(1,111,0);                                                 // Open Garage Door
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[0026]*/ doSentence(8,111,0);                                                 // Unlock Garage Door
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Garage Door **/
//roomobj-16-116.dmp
      case 116:
		 switch (action){

Open.		    case VER_Pull:
    /*[0021]*/ doSentence(1,111,0);                                                 // Open Garage Door
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[0026]*/ doSentence(8,111,0);                                                 // Unlock Garage Door
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Garage Door **/
//roomobj-16-117.dmp
      case 117:
		 switch (action){

		    case VER_Open:
    /*[0023]*/ if (getState08(116)) {                                               // If Door Open
    /*[0027]*/   doSentence(1,111,0);                                               //  Open Garage Door
    /*[002B]*/ } else {                                                             // -
    /*[002E]*/   printEgo("It's already opened.");
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0043]*/ if (!getState08(116)) {                                              // If Door is open
    /*[0047]*/   printEgo("It's too high to reach.");
    /*[005C]*/ } else {                                                             // -
    /*[005F]*/   printEgo("It's already closed.");
    /*[0073]*/ }
    /*[0073]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Pull:
    /*[0074]*/ if (getState08(116)) {                                               // If door is closed
    /*[0078]*/   doSentence(1,111,0);                                               //  Open Garage Door
    /*[007C]*/ } else {                                                             // -
    /*[007F]*/   printEgo("It's too high to reach.");
    /*[0094]*/ }
    /*[0094]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[0095]*/ doSentence(8,111,0);                                                 // Unlock Garage Door
    /*[0099]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Trunk **/
//roomobj-16-118.dmp
      case 118:
		 switch (action){

		    case VER_Open:
    /*[001F]*/ if (!getState08(activeObject)) {                                     // If trunk locked
    /*[0022]*/   printEgo("The trunk is locked.");
    /*[0035]*/ }
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;


Close.		case VER_Lock:
    /*[0036]*/ clearState08(activeObject);                                                      // Lock Trunk
    /*[0037]*/ stopSound(68);
    /*[0039]*/ startSound(9);                                                       // sound Door Closing
    /*[003B]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[003C]*/ if (!getState08(activeObject)) {                                     // If trunk locked
    /*[003F]*/   if (activeObject2 == 194) {                                        //  if use with Yellow Key
    /*[0043]*/     setState08(activeObject);                                                    //  Unlock Trunk
    /*[0044]*/     startSound(8);                                                   //  sound Door Opening
    /*[0046]*/     if (Var[18] == 2) {                                              //  if Meteor Location == Edsel
    /*[004B]*/       startScript(123);                                              //   start Meteor: Fire Radiation
    /*[004D]*/     }
    /*[004D]*/   } else {                                                           // -
    /*[0050]*/     printEgo("It doesn't work.");
    /*[0060]*/   }
    /*[0060]*/ }
    /*[0060]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0061]*/ if (activeObject2 == 252) {                                          // if use with Meteor
    /*[0065]*/   stopScript(129);                                                   //  stop Radiation Suit: Enable Speaking Flag
    /*[0067]*/   animateActor(VAR_EGO,253,1);                                       //  Open Mouth of actor
    /*[006B]*/   setOwnerOf(252,0);                                                 //  Meteor owned by no-one
    /*[006E]*/   setState08(12);                                                    //  Meteor locked
    /*[0070]*/   clearState02(12);                                                  //  Meteor Hidden
    /*[0072]*/   Var[18] = 2;                                                       //  Meteor Location == Edsel
    /*[0075]*/   startSound(68);
    /*[0077]*/ } else {                                                             // -
    /*[007A]*/   doSentence(8,118,255);                                             // Unlock Trunk
    /*[007E]*/ }
    /*[007E]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Tools **/
//roomobj-16-119.dmp
      case 119:
		 switch (action){

		    case VER_PickUp:
    /*[0019]*/ pickupObject(0);                                                     // Pick object
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[001C]*/ if (activeObject2 == 103) {                                          // Use with Phone
    /*[0020]*/   doSentence(6,103,119);                                             // Fix Phone with Tools
    /*[0024]*/ } else {                                                             // -
    /*[0027]*/   doSentence(11,255,254);                                            // Use _cmdObject2 with _cmdObject
    /*[002B]*/ }
    /*[002B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Meteor **/
//roomobj-16-12.dmp
      case 12:
		 switch (action){

		    case VER_PickUp:
    /*[0018]*/ printEgo("No way!");                                                 // Pick-up Meteor
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Water Faucet **/
//roomobj-16-120.dmp
      case 120:
		 switch (action){

		    case VER_PickUp:
    /*[0027]*/ pickupObject(0);                                                     // Pick object
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[002A]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** < Not Named > **/
//roomobj-16-153.dmp
      case 153:
		 switch (action){
        }       // end switch_action 386
        break;  // end obj 386



/** Cement Slab **/
//roomobj-16-26.dmp
      case 26:
		 switch (action){

		case VER_Open:
		case VER_Pull:
    /*[0023]*/ printEgo("It won't budge.");                                         // Open
    /*[0032]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0033]*/ if (!getState08(activeObject)) {                                     // If Cement Slab closed
    /*[0036]*/   printEgo("It's already closed.");
    /*[004A]*/ } else {                                                             // -
    /*[004D]*/   printEgo("I can't.");
    /*[0056]*/ }
    /*[0056]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0057]*/ if (getState08(activeObject)) {                                      // If Cement Slab opened
    /*[005A]*/   loadRoomWithEgo(144,51);                                           //  Enter Lab: Meteor
    /*[005D]*/ }
    /*[005D]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** License Plate **/
//roomobj-16-268.dmp
      case 268:
		 switch (action){

		    case VER_Read:
    /*[001F]*/ printEgo("THX 1138");                                                // Read
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;

        }       // end switch_action 386
        break;  // end obj 386




/** Weird Edsel **/
//roomobj-16-330.dmp
      case 330:
		 switch (action){

		    case VER_Use:
    /*[001D]*/ if (activeObject2 == 194) {                                          // use with Yellow Key
    /*[0021]*/   if (getState08(118)) {                                             // If trunk is open
    /*[0025]*/     printEgo("I'd better close the trunk first.");                   //
    /*[0043]*/     doSentence(11,74,194);                                           //  Use Weird Edsel with Yellow Key
    /*[0047]*/     doSentence(2,118,0);                                             //  Close Trunk
    /*[004B]*/   } else {                                                           // -
    /*[004E]*/     if (getState08(12)) {                                            // If Meteor Locked
    /*[0052]*/       stopScript(118);                                               //  stop Nuclear Meltdown Countdown
    /*[0054]*/     }
    /*[0054]*/     startScript(125);                                                // start Edsel: Active Rocket Engine
    /*[0056]*/   }
    /*[0056]*/ } else {                                                             // -
    /*[0059]*/   printEgo("I can't start it with that.");
    /*[0071]*/ }
    /*[0071]*/ //stopObjectCode();                                                    // --
		break;

        }       // end switch_action 386
        break;  // end obj 386




/** Modified Rocket Engine **/
//roomobj-16-331.dmp
      case 331:
		 switch (action){

		    case VER_Use:
    /*[0028]*/ doSentence(11,74,255);                                               // Use Weird Edsel with _cmdObject2
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Modified Rocket Engine **/
//roomobj-16-332.dmp
      case 332:
		 switch (action){

		    case VER_Use:
    /*[0028]*/ doSentence(11,74,255);                                               // Use Weird Edsel with _cmdObject2
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Sign **/
//roomobj-16-333.dmp
      case 333:
		 switch (action){

		    case VER_Read:
    /*[0016]*/ printEgo("Tentacle on board!");                                      // Read
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Bumper Sticker **/
//roomobj-16-334.dmp
      case 334:
		 switch (action){

		    case VER_Read:
    /*[0020]*/ printEgo("I heart Weird Ed.");                                       // Read
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Shelf **/
//roomobj-16-335.dmp




/**
 * Room 17: Music
 */


/** Door **/
//roomobj-17-152.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(148);                                                     // Open Door (Top of Main Entry)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(148);                                                   // Close Door (Top of Main Entry)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If door open
    /*[0027]*/   loadRoomWithEgo(148,11);                                           //  Enter Top of Main Entry
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Vase **/
//roomobj-17-154.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0016]*/ if (!getState08(activeObject)) {                                     // If not broken
    /*[0019]*/   printEgo("I'd better not%/%it's obviously a valuable antique!");
    /*[0048]*/ } else {                                                             // -
    /*[004B]*/   printEgo("Ouch!");                                                 //
    /*[0052]*/ }
    /*[0052]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386



/** Old Record **/
//roomobj-17-155.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[001E]*/ pickupObject(0);                                                     // Pick object
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0021]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** TV **/
//roomobj-17-157.dmp
      case 37:
		 switch (action){

TurnOn.		    case VER_Use:
    /*[0018]*/ if (!getState08(124)) {                                              // Is Power On
    /*[001C]*/   if (!getState08(activeObject)) {                                   //  Is Tv Off
    /*[001F]*/     setState08(activeObject);                                                    //   TV On
    /*[0020]*/     startScript(107);                                                //   3 Guys who Pub Anything: TV Commercial
    /*[0022]*/   }
    /*[0022]*/ } else {                                                             // -
    /*[0025]*/   printEgo("The power is off.");
    /*[0035]*/ }
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0036]*/ if (getState08(activeObject)) {                                      // Is Tv On
    /*[0039]*/   clearState08(activeObject);                                                    //  Tv Off
    /*[003A]*/ }
    /*[003A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Cassette Recorder **/
//roomobj-17-158.dmp
      case 37:
		 switch (action){

		case VER_TurnOn:
    /*[0027]*/ if (!getState08(159)) {                                              // Is Recorder off
    /*[002B]*/   if (!getState08(124)) {                                            //  Is Power On
    /*[002F]*/     setState08(activeObject);                                                    //   Recorder On
    /*[0030]*/     printEgo("Ok, it's recording.");
    /*[0043]*/     if (Var[23] == 1) {                                              //   if Victrola Playing
    /*[0048]*/       Var[13] = Var[75];                                             //    Tape Contents = Record on Victrola
    /*[004B]*/     }
    /*[004B]*/   }
    /*[004B]*/ } else {                                                             // -
    /*[004E]*/   printEgo("There's no tape in the recorder.");
    /*[006B]*/ }
    /*[006B]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[006C]*/ if (getState08(activeObject)) {                                      // If Recording
    /*[006F]*/   printEgo("It stopped recording.");
    /*[0084]*/   clearState08(158);                                                 //  Stop Recording
    /*[0086]*/ }
    /*[0086]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0087]*/ if (activeObject2 == 156) {                                          // if use with Cassette Tape
    /*[008B]*/   if (Var[13] == 52) {                                               //  if Tape Contents == 52 = Green Tentacle
    /*[0090]*/     printEgo("I can't record on this tape.");
    /*[00A9]*/   } else {                                                           // -
    /*[00AC]*/     clearState08(159);                                               // Stop Recorder
    /*[00AE]*/     clearState02(159);                                               // Stop Recorder
    /*[00B0]*/     setOwnerOf(156,14);                                              // Set owner of tape to Green Tentacle
    /*[00B3]*/   }
    /*[00B3]*/ }
    /*[00B3]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Cassette Tape **/
//roomobj-17-159.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0023]*/ if (getState08(158)) {                                               // if Recorder On
    /*[0027]*/   printEgo("It's still recording!");
    /*[003C]*/ } else {                                                             // -
    /*[003F]*/   setOwnerOf(156,VAR_EGO);                                           // Take Cassette Tape
    /*[0042]*/   setState08(activeObject);                                                      // Tape locked
    /*[0043]*/   setState02();                                                      // Tape Locked
    /*[0044]*/ }
    /*[0044]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[0045]*/ if (!getState08(activeObject)) {                                     // If Tape unlocked
    /*[0048]*/   doSentence(4,158,0);                                               //  Turn on Recorder
    /*[004C]*/ }
    /*[004C]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[004D]*/ if (!getState08(activeObject)) {                                     // If Tape unlocked
    /*[0050]*/   doSentence(5,158,0);                                               // Turn off Recorder
    /*[0054]*/ }
    /*[0054]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Record on Victrola **/
//roomobj-17-231.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[001C]*/ if (Var[23] == 1) {                                                  // if Victrola On
    /*[0021]*/   printEgo("It's still playing!");
    /*[0034]*/ } else {                                                             // -
    /*[0037]*/   setState08(231);                                                   // Victrola On
    /*[0039]*/   setState02(231);                                                   // Victrola On
    /*[003B]*/   if (Var[75] == 25) {                                               // If Record on Victrola
    /*[0040]*/     setOwnerOf(235,VAR_EGO);                                         //  Kid owns record
    /*[0043]*/   } else {                                                           // -
    /*[0046]*/     setOwnerOf(155,VAR_EGO);                                         //  Kid owns Old Record
    /*[0049]*/   }
    /*[0049]*/ }
    /*[0049]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[004A]*/ if (!getState08(activeObject)) {                                     // If Victrola Off
    /*[004D]*/   doSentence(4,102,0);                                               //  Turn On Victrola
    /*[0051]*/ }
    /*[0051]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0052]*/ if (!getState08(activeObject)) {                                     // If Victrola Off
    /*[0055]*/   doSentence(5,102,0);                                               //  Turn Off Victrola
    /*[0059]*/ }
    /*[0059]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Piano Bench **/
//roomobj-17-356.dmp



/** Piano **/
//roomobj-17-357.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0017]*/ if (VAR_EGO <= 2) {                                                  // if Syd Or Razor
    /*[001C]*/   startScript(95);                                                   //  start Play Piano
    /*[001E]*/ } else {                                                             // -
    /*[0021]*/   printEgo("I can't play that thing!");
    /*[0037]*/ }
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Victrola **/
//roomobj-17-358.dmp
      case 37:
		 switch (action){

		case VER_TurnOn:
    /*[001E]*/ if (!getState08(231)) {                                              // if Record On Victrola
    /*[0022]*/   if (Var[23] == 0) {                                                //  If Victrola Not Playing
    /*[0027]*/     Var[23] = 1;                                                     //   Victrola Playing
    /*[002A]*/     if (getState08(158)) {                                           //   State of Casette Recorder
    /*[002E]*/       Var[13] = Var[75];                                             //    Tape Contents = Record on Victrola
    /*[0031]*/     }
    /*[0031]*/     if (Var[75] == 25) {                                             // If Record on Victrola is Tentacle Mating Call
    /*[0036]*/       startScript(14);                                               //  start Record: Tentacle Mating Call
    /*[0038]*/     } else {                                                         // -
    /*[003B]*/       startSound(44);                                                // sound
    /*[003D]*/     }
    /*[003D]*/   }
    /*[003D]*/ } else {                                                             // -
    /*[0040]*/   printEgo("There's no record on the Victrola.");
    /*[005F]*/ }
    /*[005F]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0060]*/ Var[23] = 0;                                                         // Victrola = Off
    /*[0063]*/ stopSound(25);
    /*[0065]*/ stopSound(44);
    /*[0067]*/ stopScript(14);                                                      // start Record: Tentacle Mating Call
    /*[0069]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[006A]*/ if (!getState08(231)) {                                              // If Record On Victrola
    /*[006E]*/   printEgo("There's already a record here.");
    /*[008A]*/ } else {                                                             // -
    /*[008D]*/   if (activeObject2 == 235) {                                        // use with Record
    /*[0091]*/     clearState08(231);                                               //  Lock Record
    /*[0093]*/     clearState02(231);                                               //  Lock Record
    /*[0095]*/     setOwnerOf(235,14);                                              //  Green Tentacle owns record
    /*[0098]*/     Var[75] = 25;                                                    //  Record on Victrola = Tentacle Mating Call
    /*[009B]*/   }
    /*[009B]*/   if (activeObject2 == 155) {                                        // use with Old Record
    /*[009F]*/     clearState08(231);                                               //  Lock Record
    /*[00A1]*/     clearState02(231);                                               //  Lock Record
    /*[00A3]*/     setOwnerOf(155,14);                                              //  Green Tentacle owns Record
    /*[00A6]*/     Var[75] = 44;                                                    //  Record on Victrola = Melody Stinks
    /*[00A9]*/   }
    /*[00A9]*/ }
    /*[00A9]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Speaker **/
//roomobj-17-359.dmp



/**
 * Room 18: Video Game
 */


/** Door **/
//roomobj-18-168.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(163);                                                     // Open Door (Level 2 Main Hallway)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(163);                                                   // Close Door (Level 2 Main Hallway)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if Door Open
    /*[0027]*/   loadRoomWithEgo(163,13);                                           // Enter Level 2 Main Hallway
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Video Fever **/
//roomobj-18-169.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   doSentence(11,175,200);                                            //  Use Game with Quater                                    //  Use Game with Quater
    /*[002E]*/ }
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[002F]*/ startScript(19);                                                     // start Power Off??
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0032]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;





/** Disco Crazy **/
//roomobj-18-170.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   doSentence(11,176,200);                                            //  Use Game with Quater                                    //  Use Game with Quater
    /*[002E]*/ }
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[002F]*/ startScript(19);                                                     // start Power Off??
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0032]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;




/** Alien Slime **/
//roomobj-18-171.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   doSentence(11,177,200);                                            //  Use Game with Quater                                    //  Use Game with Quater
    /*[002E]*/ }
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[002F]*/ startScript(19);                                                     // start Power Off??
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0032]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;




/** Die Enemy Die **/
//roomobj-18-172.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0028]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002C]*/   doSentence(11,178,200);                                            //  Use Game with Quater
    /*[0030]*/ }
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[0031]*/ startScript(19);                                                     // start Power Off??
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0034]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;





/** Meteor Mess **/
//roomobj-18-173.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   doSentence(11,179,200);                                            //  Use Game with Quater
    /*[002E]*/ }
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[002F]*/ startScript(19);                                                     // start Power Off??
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0032]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;





/** Kil Thrill **/
//roomobj-18-174.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   doSentence(11,180,200);                                            //  Use Game with Quater
    /*[002E]*/ }
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[002F]*/ startScript(19);                                                     // start Power Off??
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0032]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;




/** Coin Box **/
//roomobj-18-215.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0024]*/ if (!getState08(221)) {                                              // If Quarter in coinbox
    /*[0028]*/   doSentence(14,221,0);                                              //  Pickup Quater
    /*[002C]*/ } else {                                                             // -
    /*[002F]*/   startScript(20);                                                   // start It Looks off / cant find a switch
    /*[0031]*/ }
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0032]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[0036]*/   doSentence(11,175,200);                                            //  Use Game with Quater
    /*[003A]*/ }
    /*[003A]*/ if (activeObject2 == 74) {                                           // Use with small key
    /*[003E]*/   doSentence(8,215,74);                                              //  unlock coinbox with small key                                       // unlock coinbox with small key                                        //
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Open:
    /*[0043]*/ if (!getState08(activeObject)) {                                     // if game is locked
    /*[0046]*/   startScript(60);                                                   //  Print "The machine is locked"
    /*[0048]*/ }
    /*[0048]*/ //stopObjectCode();                                                    // --
		break;


Close.		case VER_Lock:
    /*[0049]*/ if (getState08(activeObject)) {                                      // if game is unlocked
    /*[004C]*/   clearState08(activeObject);                                                    //  Lock Game
    /*[004D]*/   setState04();                                                      //  Lock Game
    /*[004E]*/ }
    /*[004E]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[004F]*/ if (activeObject2 == 74) {                                           // if use with small key
    /*[0053]*/   clearState04();                                                    //  Lock Game
    /*[0054]*/   setState08(activeObject);                                                      //  Lock Gmae
    /*[0055]*/ } else {                                                             // -
    /*[0058]*/   startScript(61);                                                   //  start Print "It must require a special key"
    /*[005A]*/ }
    /*[005A]*/ //stopObjectCode();                                                    // --
		break;





/** Coin Box **/
//roomobj-18-216.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0024]*/ if (!getState08(222)) {                                              // If Quarter in coinbox
    /*[0028]*/   doSentence(14,222,0);                                              //  Pickup Quater
    /*[002C]*/ } else {                                                             // -
    /*[002F]*/   startScript(20);                                                   // start It Looks off / cant find a switch
    /*[0031]*/ }
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0032]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[0036]*/   doSentence(11,176,200);                                            //  Use Game with Quater
    /*[003A]*/ }
    /*[003A]*/ if (activeObject2 == 74) {                                           // Use with small key
    /*[003E]*/   doSentence(8,216,74);                                              //  unlock coinbox with small key
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Open:
    /*[0043]*/ if (!getState08(activeObject)) {                                     // if game is locked
    /*[0046]*/   startScript(60);                                                   //  Print "The machine is locked"
    /*[0048]*/ }
    /*[0048]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0049]*/ if (getState08(activeObject)) {                                      // if game is unlocked
    /*[004C]*/   clearState08(activeObject);                                                    //  Lock Game
    /*[004D]*/   setState04();                                                      //  Lock Game
    /*[004E]*/ }
    /*[004E]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[004F]*/ if (activeObject2 == 74) {                                           // if use with small key
    /*[0053]*/   clearState04();                                                    //  Lock Game
    /*[0054]*/   setState08(activeObject);                                                      //  Lock Gmae
    /*[0055]*/ } else {                                                             // -
    /*[0058]*/   startScript(61);                                                   //  start Print "It must require a special key"
    /*[005A]*/ }
    /*[005A]*/ //stopObjectCode();                                                    // --
		break;




/** Coin Box **/
//roomobj-18-217.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0024]*/ if (!getState08(223)) {                                              // If Quarter in coinbox
    /*[0028]*/   doSentence(14,223,0);                                              //  Pickup Quater
    /*[002C]*/ } else {                                                             // -
    /*[002F]*/   startScript(20);                                                   // start It Looks off / cant find a switch
    /*[0031]*/ }
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0032]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[0036]*/   doSentence(11,177,200);                                            //  Use Game with Quater
    /*[003A]*/ }
    /*[003A]*/ if (activeObject2 == 74) {                                           // Use with small key
    /*[003E]*/   doSentence(8,217,74);                                              //  unlock coinbox with small key
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Open:
    /*[0043]*/ if (!getState08(activeObject)) {                                     // if game is locked
    /*[0046]*/   startScript(60);                                                   //  Print "The machine is locked"
    /*[0048]*/ }
    /*[0048]*/ //stopObjectCode();                                                    // --
		break;


Close.		case VER_Lock:
    /*[0049]*/ if (getState08(activeObject)) {                                      // if game is unlocked
    /*[004C]*/   clearState08(activeObject);                                                    //  Lock Game
    /*[004D]*/   setState04();                                                      //  Lock Game
    /*[004E]*/ }
    /*[004E]*/ //stopObjectCode();                                                    // --
		break;

Un		case VER_Lock:
    /*[004F]*/ if (activeObject2 == 74) {                                           // if use with small key
    /*[0053]*/   clearState04();                                                    //  Lock Game
    /*[0054]*/   setState08(activeObject);                                                      //  Lock Gmae
    /*[0055]*/ } else {                                                             // -
    /*[0058]*/   startScript(61);                                                   //  start Print "It must require a special key"
    /*[005A]*/ }
    /*[005A]*/ //stopObjectCode();                                                    // --
		break;





/** Coin Box **/
//roomobj-18-218.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0024]*/ if (!getState08(224)) {                                              // If Quarter in coinbox
    /*[0028]*/   doSentence(14,224,0);                                              //  Pickup Quater
    /*[002C]*/ } else {                                                             // -
    /*[002F]*/   startScript(20);                                                   // start It Looks off / cant find a switch
    /*[0031]*/ }
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0032]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[0036]*/   doSentence(11,178,200);                                            //  Use Game with Quater
    /*[003A]*/ }
    /*[003A]*/ if (activeObject2 == 74) {                                           // Use with small key
    /*[003E]*/   doSentence(8,218,74);                                              //  unlock coinbox with small key
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Open:
    /*[0043]*/ if (!getState08(activeObject)) {                                     // if game is locked
    /*[0046]*/   startScript(60);                                                   //  Print "The machine is locked"
    /*[0048]*/ }
    /*[0048]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0049]*/ if (getState08(activeObject)) {                                      // if game is unlocked
    /*[004C]*/   clearState08(activeObject);                                                    //  Lock Game
    /*[004D]*/   setState04();                                                      //  Lock Game
    /*[004E]*/ }
    /*[004E]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[004F]*/ if (activeObject2 == 74) {                                           // if use with small key
    /*[0053]*/   clearState04();                                                    //  Lock Game
    /*[0054]*/   setState08(activeObject);                                                      //  Lock Gmae
    /*[0055]*/ } else {                                                             // -
    /*[0058]*/   startScript(61);                                                   //  start Print "It must require a special key"
    /*[005A]*/ }
    /*[005A]*/ //stopObjectCode();                                                    // --
		break;




/** Coin Box **/
//roomobj-18-219.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0024]*/ if (!getState08(225)) {                                              //   // If Quarter in coinbox
    /*[0028]*/   doSentence(14,225,0);                                              // Pickup Quater
    /*[002C]*/ } else {                                                             //
    /*[002F]*/   startScript(20);                                                   //  start It Looks off / cant find a switch
    /*[0031]*/ }                                                                    //
    /*[0031]*/ stopObjectCode();                                                    //  --
}

		    case VER_Use:
    /*[0032]*/ if (activeObject2 == 200) {                                          //  if use with Quarter
    /*[0036]*/   doSentence(11,179,200);                                            //   Use Game with Quater
    /*[003A]*/ }                                                                    //
    /*[003A]*/ if (activeObject2 == 74) {                                           //  Use with small key
    /*[003E]*/   doSentence(8,219,74);                                              //   unlock coinbox with small key
    /*[0042]*/ }                                                                    //
    /*[0042]*/ stopObjectCode();                                                    //  --
}

		    case VER_Open:
    /*[0043]*/ if (!getState08(activeObject)) {                                     //  if game is locked
    /*[0046]*/   startScript(60);                                                   //   Print "The machine is locked"
    /*[0048]*/ }                                                                    //
    /*[0048]*/ stopObjectCode();                                                    //  --
}

		    case VER_Close:
    /*[0049]*/ if (getState08(activeObject)) {                                      //  if game is unlocked
    /*[004C]*/   clearState08(activeObject);                                                    //   Lock Game
    /*[004D]*/   setState04();                                                      //   Lock Game
    /*[004E]*/ }                                                                    //
    /*[004E]*/ stopObjectCode();                                                    //  --
}

Un		case VER_Lock:
    /*[004F]*/ if (activeObject2 == 74) {                                           //  if use with small key
    /*[0053]*/   clearState04();                                                    //   Lock Game
    /*[0054]*/   setState08(activeObject);                                                      //   Lock Gmae
    /*[0055]*/ } else {                                                             //  -
    /*[0058]*/   startScript(61);                                                   //   start Print "It must require a special key"
    /*[005A]*/ }                                                                    //
    /*[005A]*/ stopObjectCode();                                                    //    --
}



/** Coin Box **/
//roomobj-18-220.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0024]*/ if (!getState08(226)) {                                              // If Quarter in coinbox
    /*[0028]*/   doSentence(14,226,0);                                              //  Pickup Quater
    /*[002C]*/ } else {                                                             // -
    /*[002F]*/   startScript(20);                                                   // start It Looks off / cant find a switch
    /*[0031]*/ }
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0032]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[0036]*/   doSentence(11,180,200);                                            //  Use Game with Quater
    /*[003A]*/ }
    /*[003A]*/ if (activeObject2 == 74) {                                           // Use with small key
    /*[003E]*/   doSentence(8,220,74);                                              //  unlock coinbox with small key
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Open:
    /*[0043]*/ if (!getState08(activeObject)) {                                     // if game is locked
    /*[0046]*/   startScript(60);                                                   //  Print "The machine is locked"
    /*[0048]*/ }
    /*[0048]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0049]*/ if (getState08(activeObject)) {                                      // if game is unlocked
    /*[004C]*/   clearState08(activeObject);                                                    //  Lock Game
    /*[004D]*/   setState04();                                                      //  Lock Game
    /*[004E]*/ }
    /*[004E]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[004F]*/ if (activeObject2 == 74) {                                           // if use with small key
    /*[0053]*/   clearState04();                                                    //  Lock Game
    /*[0054]*/   setState08(activeObject);                                                      //  Lock Gmae
    /*[0055]*/ } else {                                                             // -
    /*[0058]*/   startScript(61);                                                   //  start Print "It must require a special key"
    /*[005A]*/ }
    /*[005A]*/ //stopObjectCode();                                                    // --
		break;





/** Quater **/
//roomobj-18-221.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0019]*/ setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    /*[001C]*/ setState02(221);                                                     // Coin Locked
    /*[001E]*/ setState08(221);                                                     // Coin Locked
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;




/** Quater **/
//roomobj-18-222.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0019]*/ setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    /*[001C]*/ setState02(222);                                                     // Coin Locked
    /*[001E]*/ setState08(222);                                                     // Coin Locked
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;





/** Quater **/
//roomobj-18-223.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0019]*/ setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    /*[001C]*/ setState02(223);                                                     // Coin Locked
    /*[001E]*/ setState08(223);                                                     // Coin Locked
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;




/** Quater **/
//roomobj-18-224.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0019]*/ setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    /*[001C]*/ setState02(224);                                                     // Coin Locked
    /*[001E]*/ setState08(224);                                                     // Coin Locked
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;





/** Quater **/
//roomobj-18-225.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0019]*/ setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    /*[001C]*/ setState02(225);                                                     // Coin Locked
    /*[001E]*/ setState08(225);                                                     // Coin Locked
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;





/** Quater **/
//roomobj-18-226.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0019]*/ setOwnerOf(200,VAR_EGO);                                             // Kid owns Quarter
    /*[001C]*/ setState02(226);                                                     // Coin Locked
    /*[001E]*/ setState08(226);                                                     // Coin Locked
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;





/** Air Hockey Table **/
//roomobj-18-367.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0022]*/ printEgo("This game is broken.");                                    // use
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;





/** Star Wars Poster **/
//roomobj-18-368.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[0022]*/ printEgo("A Lucasfilm Ltd. Production.");                            // Read
    /*[003D]*/ //stopObjectCode();                                                    // --
		break;




/** Video Fever **/
//roomobj-18-431.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   if (getState08(204)) {                                             //  if Wires Fixed
    /*[002E]*/     setState08(169);                                                 //   Video Game On
    /*[0030]*/     clearState02(221);                                               //   Quater Gone
    /*[0032]*/     clearState08(221);                                               //    Quater Gone
    /*[0034]*/     startScript(22);                                                 //    start Video Game: Die Enemy Die
    /*[0036]*/   } else {                                                           // -
    /*[0039]*/     startScript(59);                                                 //  Print "It seems to be turned off"
    /*[003B]*/   }
    /*[003B]*/ }
    /*[003B]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[003C]*/ startScript(19);                                                     // start Power Off??
    /*[003E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[003F]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;





/** Disco Crazy **/
//roomobj-18-432.dmp
      case 37:
		 switch (action){
Events:
TurnOn - 003C
TurnOff- 003F
   Use - 0026

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   if (getState08(204)) {                                             //  if Wires Fixed
    /*[002E]*/     setState08(170);                                                 //   Video Game On
    /*[0030]*/     clearState02(222);                                               //   Quater Gone
    /*[0032]*/     clearState08(222);                                               //    Quater Gone
    /*[0034]*/     startScript(22);                                                 //    start Video Game: Die Enemy Die
    /*[0036]*/   } else {                                                           // -
    /*[0039]*/     startScript(59);                                                 //  Print "It seems to be turned off"
    /*[003B]*/   }
    /*[003B]*/ }
    /*[003B]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[003C]*/ startScript(19);                                                     // start Power Off??
    /*[003E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[003F]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;





/** Alien Slime **/
//roomobj-18-433.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   if (getState08(204)) {                                             //  if Wires Fixed
    /*[002E]*/     setState08(171);                                                 //   Video Game On
    /*[0030]*/     clearState02(223);                                               //   Quater Gone
    /*[0032]*/     clearState08(223);                                               //    Quater Gone
    /*[0034]*/     startScript(22);                                                 //    start Video Game: Die Enemy Die
    /*[0036]*/   } else {                                                           // -
    /*[0039]*/     startScript(59);                                                 //  Print "It seems to be turned off"
    /*[003B]*/   }
    /*[003B]*/ }
    /*[003B]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[003C]*/ startScript(19);                                                     // start Power Off??
    /*[003E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[003F]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;





/** Die Enemy Die **/
//roomobj-18-434.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0028]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002C]*/   if (getState08(204)) {                                             //  if Wires Fixed
    /*[0030]*/     setState08(172);                                                 //   Video Game On
    /*[0032]*/     clearState02(224);                                               //   Quater Gone
    /*[0034]*/     clearState08(224);                                               //    Quater Gone
    /*[0036]*/     startScript(22);                                                 //    start Video Game: Die Enemy Die
    /*[0038]*/   } else {                                                           // -
    /*[003B]*/     startScript(59);                                                 //  Print "It seems to be turned off"
    /*[003D]*/   }
    /*[003D]*/ }
    /*[003D]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[003E]*/ startScript(19);                                                     // start Power Off??
    /*[0040]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0041]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0043]*/ //stopObjectCode();                                                    // --
		break;





/** Meteor Mess **/
//roomobj-18-435.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   if (getState08(204)) {                                             //  if Wires Fixed
    /*[002E]*/     setState08(173);                                                 //   Video Game On
    /*[0030]*/     clearState02(225);                                               //   Quater Gone
    /*[0032]*/     clearState08(225);                                               //    Quater Gone
    /*[0034]*/     setOwnerOf(200,14);                                              //    start Video Game: Die Enemy Die
    /*[0037]*/     startSound(11);                                                  // Sound CoinSlot                                         // -
    /*[0039]*/     startScript(21);                                                 //  Print "It seems to be turned off"
    /*[003B]*/   } else {
    /*[003E]*/     startScript(59);
    /*[0040]*/   }                                                                  // --
    /*[0040]*/ }                                                                    // start Power Off??
    /*[0040]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[0041]*/ startScript(19);                                                     // start It Looks off / cant find a switch
    /*[0043]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0044]*/ startScript(20);
    /*[0046]*/ stopObjectCode();
}



/** Kill Thrill **/
//roomobj-18-436.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[002A]*/   if (getState08(204)) {                                             //  if Wires Fixed
    /*[002E]*/     setState08(174);                                                 //   Video Game On
    /*[0030]*/     clearState02(226);                                               //   Quater Gone
    /*[0032]*/     clearState08(226);                                               //    Quater Gone
    /*[0034]*/     startScript(22);                                                 //    start Video Game: Die Enemy Die
    /*[0036]*/   } else {                                                           // -
    /*[0039]*/     startScript(59);                                                 //  Print "It seems to be turned off"
    /*[003B]*/   }
    /*[003B]*/ }
    /*[003B]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[003C]*/ startScript(19);                                                     // start Power Off??
    /*[003E]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[003F]*/ startScript(20);                                                     // start It Looks off / cant find a switch
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 19: Nurse Edna's
 */


/** Door **/
//roomobj-19-210.dmp
      case 37:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ setState08(196);                                                     // Open Hatch
    /*[001A]*/ loadRoomWithEgo(196,9);                                              // Enter Attic (Above Nurse Edna's Room)
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;





/** Desk **/
//roomobj-19-294.dmp



/** Cracked Mirro **/
//roomobj-19-295.dmp



/** Mirror **/
//roomobj-19-296.dmp



/** Light **/
//roomobj-19-297.dmp
      case 37:
		 switch (action){

		case VER_TurnOn:
    /*[0019]*/ startSound(12);                                                      // sound Light Switch
    /*[001B]*/ setBitVar(VAR_ROOM,1,0);                                             // Light On
    /*[001F]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0022]*/ startSound(12);                                                      // sound Light Switch
    /*[0024]*/ setBitVar(VAR_ROOM,1,1);                                             // Light Off
    /*[0028]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;




/** Bed **/
//roomobj-19-298.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0015]*/ printEgo("No way!!!");
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;





/** Picture of Dr. Fred **/
//roomobj-19-299.dmp
      case 37:
		 switch (action){

Open.		    case VER_Pull:
    /*[0027]*/ startScript(62);                                                     // start Print "Its firmly attached to the wall"
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;





/** Plant **/
//roomobj-19-301.dmp



/** Plant **/
//roomobj-19-302.dmp



/** Perfume **/
//roomobj-19-437.dmp



/** Pillow **/
//roomobj-19-438.dmp



/** Door **/
//roomobj-19-70.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(185);                                                     // Open Door (Door: Nurse Edna)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(185);                                                   // Close Door (Door: Nurse Edna)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {
    /*[0027]*/   loadRoomWithEgo(185,38);                                           // Enter Level 3 Hallway
    /*[002A]*/   cursorCommand( kModeNormal )                                       // Cutscene Mode Normal
    /*[002C]*/ }
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;




/** Phone **/
//roomobj-19-72.dmp



/** Small Key **/
//roomobj-19-74.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[001D]*/ pickupObject(0);                                                     // Pick object
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0020]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 20: Green Tentacle's
 */


/** Mondo Stereo **/
//roomobj-20-131.dmp
      case 37:
		 switch (action){

		case VER_TurnOn:
    /*[0022]*/ if (!getState08(124)) {                                              // if Power On
    /*[0026]*/   setState08(131);                                                   //  Mondo Stereo = On
    /*[0028]*/   if (!getState08(195)) {                                            //   Cassette Tape not playing
    /*[002C]*/     startScript(104);                                                //    start Tape Player: Play Tape
    /*[002E]*/   } else {                                                           // -
    /*[0031]*/     startSound(20);                                                  //
    /*[0033]*/   }
    /*[0033]*/ }
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0034]*/ if (getState08(131)) {                                               // If stereo on
    /*[0038]*/   clearState08(131);                                                 //  Stereo turn off
    /*[003A]*/   stopSound(25);                                                     //
    /*[003C]*/   stopSound(20);                                                     //
    /*[003E]*/   stopSound(44);                                                     //
    /*[0040]*/   stopMusic();                                                       // Stop Music
    /*[0041]*/ }
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[0042]*/ if (activeObject2 == 156) {                                          // if Cassette Tape
    /*[0046]*/   clearState08(195);                                                 //  Free Tape
    /*[0048]*/   clearState02(195);                                                 //  Free Tape
    /*[004A]*/   setOwnerOf(156,14);                                                //  Tape owned by Green Tentac;e
    /*[004D]*/   stopSound(20);
    /*[004F]*/   if (getState08(131)) {
    /*[0053]*/     doSentence(4,131,0);                                             // Turn On Mondo Stereo
    /*[0057]*/   }
    /*[0057]*/ }
    /*[0057]*/ if (activeObject2 == 155) {                                          // use with Old Record
    /*[005B]*/ } else {                                                             // -
    /*[005E]*/   unless (activeObject2 == 235) goto 0076;                           // or Record
    /*[0062]*/ }
    /*[0062]*/ printEgo("Hey, it's a CD player!");
    /*[0076]*/ //stopObjectCode();                                                    // --
		break;





/** Hatch **/
//roomobj-20-192.dmp
      case 37:
		 switch (action){

Open.		    case VER_PickUp:
    /*[001F]*/ startScript(4);                                                      // start Door: Open
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0022]*/ startScript(5);                                                      // start Door: Close
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Pull:
    /*[0025]*/ if (getState08(activeObject)) {
    /*[0028]*/   startScript(5);                                                    // start Door: Close
    /*[002A]*/ } else {                                                             // -
    /*[002D]*/   startScript(4);                                                    // start Door: Open
    /*[002F]*/ }
    /*[002F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0030]*/ if (getState08(activeObject)) {                                      // If door open
    /*[0033]*/   loadRoomWithEgo(214,21);                                           // Enter Radio
    /*[0036]*/ }
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;





/** Yellow Key **/
//roomobj-20-194.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[001E]*/ pickupObject(0);                                                     // Pick object
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0021]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;





/** Cassette Tape **/
//roomobj-20-195.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0023]*/ if (getState08(131)) {                                               // if Mondo Stereo on
    /*[0027]*/   stopSound(25);                                                     //  stop sound
    /*[0029]*/   stopMusic();                                                       //  stop music
    /*[002A]*/   startSound(20);
    /*[002C]*/ }
    /*[002C]*/ setOwnerOf(156,VAR_EGO);                                             // Kid owns Tape
    /*[002F]*/ setState08(activeObject);
    /*[0030]*/ setState02();
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[0032]*/ if (!getState08(activeObject)) {                                     // playing?
    /*[0035]*/   doSentence(4,131,0);                                               //  Turn on Mondo Stereo
    /*[0039]*/ }
    /*[0039]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[003A]*/ if (!getState08(activeObject)) {                                     // playing?
    /*[003D]*/   doSentence(5,131,0);                                               // Turn off Mondo Stereo
    /*[0041]*/ }
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;





/** Record **/
//roomobj-20-235.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[001C]*/ pickupObject(0);                                                     // Pick object
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[001F]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[0024]*/ printEgo("Tentacle mating calls.");
    /*[003A]*/ //stopObjectCode();                                                    // --
		break;





/** Demo Tape **/
//roomobj-20-238.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[001B]*/ setState08(activeObject);                                                        // Tape Locked
    /*[001C]*/ setState02();                                                        // Tape Hidden
    /*[001D]*/ setOwnerOf(156,VAR_EGO);                                             // Tape owned by Kid
    /*[0020]*/ setObjectName(156,"demo tape");
    /*[002C]*/ Var[13] = 52;                                                        // Tape Contents = Green Tentacle
    /*[002F]*/ //stopObjectCode();                                                    // --
		break;





/** Left Speaker **/
//roomobj-20-393.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[001E]*/ printEgo("THX Sound");                                               // Read
    /*[0028]*/ stopObjectCode();                                                    // --
    }




/** Right Speaker **/
//roomobj-20-394.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[001F]*/ printEgo("THX Sound");                                               // Read
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;




/** Poster **/
//roomobj-20-396.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[0018]*/ printEgo("See Ron Gilbert Live at the Forum!");                      // Read
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;





/** Poster **/
//roomobj-20-397.dmp



/** Bed **/
//roomobj-20-398.dmp



/** Picture **/
//roomobj-20-439.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[0019]*/ printEgo("To my slimiest son, love MOM");                            // Read
    /*[0032]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 21: Radio
 */


/** Door **/
//roomobj-21-189.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(184);                                                     // Open Door (Level 3 Hallway)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(184);                                                   // Close Door (Level 3 Hallway)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // is door open
    /*[0027]*/   loadRoomWithEgo(184,38);                                           //  Enter Level 3 Hallway
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Dime **/
//roomobj-21-190.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[0018]*/ pickupObject(0);                                                     // Pick object
    /*[001A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[001B]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;





/** Radio Tube **/
//roomobj-21-191.dmp
      case 37:
		 switch (action){

		    case VER_PickUp:
    /*[001C]*/ setOwnerOf(40,VAR_EGO);                                              // Kid owns Radio Tube
    /*[001F]*/ setState08(activeObject);                                                        // Lock Tube
    /*[0020]*/ setState02();                                                        // Hide Tube
    /*[0021]*/ Var[28] = 0;                                                         // Radio (Room 21) = off
    /*[0024]*/ stopSound(20);
    /*[0026]*/ stopSound(29);
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;




/** Ladder **/
//roomobj-21-214.dmp
      case 37:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ setState08(192);                                                     // Open Hatch
    /*[001A]*/ loadRoomWithEgo(192,20);                                             // Enter Green Tentacle's
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;





/** Picture of Nurse Edna **/
//roomobj-21-388.dmp
      case 37:
		 switch (action){

Open.		    case VER_Pull:
    /*[0029]*/ startScript(62);                                                     // start Print "Its firmly attached to the wall"
    /*[002B]*/ //stopObjectCode();                                                    // --
		break;





/** Water Poster **/
//roomobj-21-389.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[001F]*/ startScript(47);                                                     // start Meteor Police Poster (Read Number)
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;





/** Tube Socket **/
//roomobj-21-390.dmp
      case 37:
		 switch (action){

Fix.		    case VER_Use:
    /*[001F]*/ if (VAR_EGO == 5) {                                                  // If Bernard
    /*[0024]*/   if (activeObject2 == 40) {                                         //  if use with Radio Tube
    /*[0028]*/     setOwnerOf(40,14);                                               //   Green Tentacle owns tube
    /*[002B]*/     clearState08(191);                                               //   Clear State
    /*[002D]*/     clearState02(191);                                               //   Clear State
    /*[002F]*/   } else if (getState08(191)) {
    /*[0036]*/     printEgo("That doesn't seem to work.");
    /*[004E]*/   }
    /*[004E]*/ } else {                                                             // -
    /*[0051]*/   printEgo("I don't know how!");
    /*[0061]*/ }
    /*[0061]*/ //stopObjectCode();                                                    // --
		break;




/** Radio **/
//roomobj-21-391.dmp
      case 37:
		 switch (action){

Fix {
    /*[001D]*/ if (activeObject2 == 40) {                                           // Fix with Radio Tube
    /*[0021]*/   doSentence(6,134,0);                                               // use tube with Tube Socket
    /*[0025]*/ }
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[0026]*/ if (!getState08(191)) {                                              //  is Radio Tube in
    /*[002A]*/   if (!getState08(124)) {                                            //   is power on
    /*[002E]*/     if (Var[28] == 0) {                                              //    if Radio (Room 21) == off
    /*[0033]*/       Var[28] = 1;                                                   //     Radio (Room 21) = on
    /*[0036]*/       startSound(20);                                                //     sound radio static
    /*[0038]*/     }
    /*[0038]*/   }
    /*[0038]*/ } else if (VAR_EGO == 5) {                                           // is Bernard
    /*[0040]*/   printEgo("It's missing a type W-88 vacuum tube.");
    /*[0061]*/ } else {                                                             // -
    /*[0064]*/   printEgo("I can't get it to work./It might be missing a part.");
    /*[008F]*/ }
    /*[008F]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0090]*/ if (Var[28] == 0) {                                                  // if Radio (Room 21) == off
    /*[0095]*/   printEgo("It wasn't on.");                                         //
    /*[00A2]*/ } else {                                                             // -
    /*[00A5]*/   Var[28] = 0;                                                       //  Radio = Off
    /*[00A8]*/   stopSound(20);                                                     //  stop sound radio static
    /*[00AA]*/   stopSound(29);                                                     //  stop sound
    /*[00AC]*/ }
    /*[00AC]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[00AD]*/ if (Var[28] == 0) {                                                  // Radio (Room 21) == off
    /*[00B2]*/   printEgo("It's not turned on.");
    /*[00C4]*/ } else if (Var[18] == 3) {                                           // Meteor Location == Gone
    /*[00CC]*/   printEgo("The meteor was already picked up.");
    /*[00EA]*/ } else {                                                             // -
    /*[00ED]*/   VAR_RESULT = isScriptRunning(131);
    /*[00F0]*/   if (VAR_RESULT == 0) {                                             // Script Meteor Police: Timer until arrival not running
    /*[00F5]*/     startScript(35);                                                 //  start Pin: Entry - Radio (Meteor Police)
    /*[00F7]*/   } else {                                                           // -
    /*[00FA]*/     printEgo("The police are on their way.");
    /*[0113]*/   }
    /*[0113]*/ }
    /*[0113]*/ stopObjectCode();                                                    // --



/** Bed **/
//roomobj-21-392.dmp



/**
 * Room 22: Medical
 */


/** Door **/
//roomobj-22-175.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(162);                                                     // Open Door (Level 2 Main Hallway)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(162);                                                   // Close Door (Level 2 Main Hallway)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If door open
    /*[0027]*/   loadRoomWithEgo(162,13);                                           //  Enter Level 2 Main Hallway
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Desk **/
//roomobj-22-176.dmp
      case 37:
		 switch (action){

Open.		    case VER_Pull:
    /*[001C]*/ setState08(activeObject);                                                        // Open Draw
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;


Close.		    case VER_Push:
    /*[001E]*/ clearState08(activeObject);                                                      // Close Draw
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;





/** Manuscript **/
//roomobj-22-177.dmp
      case 37:
		 switch (action){

Fix {
    /*[0022]*/ if (activeObject2 == 153) {                                          // Use with Typewriter
    /*[0026]*/   startScript(10);                                                   //  start Memoir: Writing
    /*[0028]*/ } else {                                                             // -
    /*[002B]*/   printEgo("I can't fix it with that!");
    /*[0041]*/ }
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_PickUp:
    /*[0042]*/ pickupObject(0);                                                     // Pick object
    /*[0044]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[0045]*/ startScript(9);                                                      //  start Memoir: Reading
    /*[0047]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0048]*/ if (activeObject2 == 153) {
    /*[004C]*/   doSentence(6,177,153);                                             // Use with Typewriter
    /*[0050]*/ } else {                                                             // -
    /*[0053]*/   doSentence(11,255,254);                                            // Use _cmdObject2 with _cmdObject
    /*[0057]*/ }
    /*[0057]*/ //stopObjectCode();                                                    // --
		break;




/** Mail-A-Med Degree **/
//roomobj-22-369.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[0024]*/ printEgo("Presented to Doctor Fred.");
    /*[003C]*/ //stopObjectCode();                                                    // --
		break;




/** Docs 'R Us Diploma **/
//roomobj-22-370.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[0024]*/ printEgo("Degree for mumifying and bandaging.");
    /*[0045]*/ //stopObjectCode();                                                    // --
		break;





/** Desk Lamp **/
//roomobj-22-371.dmp
      case 37:
		 switch (action){

		case VER_TurnOn:
    /*[001D]*/ startSound(12);                                                      // sound Light Switch
    /*[001F]*/ setBitVar(VAR_ROOM,1,0);                                             // Light On
    /*[0023]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0026]*/ startSound(12);                                                      // sound Light Switch
    /*[0028]*/ setBitVar(VAR_ROOM,1,1);                                             // Light Off
    /*[002C]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;





/** Desk **/
//roomobj-22-372.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[0018]*/ setState08(176);                                                     // Open Draw
    /*[001A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001B]*/ clearState08(176);                                                   // Open Draw
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;





/** Black Board **/
//roomobj-22-373.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[001D]*/ printEgo("It looks like formulas%/%describing the structure of a meteor!/That's strange.");
    /*[0064]*/ //stopObjectCode();                                                    // --
		break;





/** Examination **/
//roomobj-22-374.dmp
      case 37:
		 switch (action){

		case Push:		    case VER_Pull:
    /*[0025]*/ startScript(65);                                                     // start Print "Its too Heavy"
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;





/** Real Skeleton **/
//roomobj-22-375.dmp
      case 37:
		 switch (action){

		case VER_WhatIs:
    /*[001F]*/ printEgo("Oooh! That's scary!");
    /*[0032]*/ //stopObjectCode();                                                    // --
		break;





/** Medical Diagram **/
//roomobj-22-376.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[0021]*/ printEgo("Chewy carmel center.");
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;





/** Medical Cabinet **/
//roomobj-22-377.dmp
      case 37:
		 switch (action){

Open.Un		case VER_Lock:
    /*[0023]*/ startScript(61);                                                     // start Print "It must require a special key"
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;





/** Medical Chart **/
//roomobj-22-412.dmp
      case 37:
		 switch (action){

		    case VER_Read:
    /*[001F]*/ if (VAR_EGO == 2) {                                                  // if Razor
    /*[0024]*/   printEgo("WOW! That's neat!!");
    /*[0036]*/ } else {                                                             // -
    /*[0039]*/   printEgo("Yuck. That's disgusting!");
    /*[0051]*/ }
    /*[0051]*/ //stopObjectCode();                                                    // --
		break;






/**
 * Room 23: Darkroom
 */


/** Door **/
//roomobj-23-182.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(181);                                                     // Open Door (Level 2 Stairs to Level 3)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(181);                                                   // Close Door (Level 2 Stairs to Level 3)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   loadRoomWithEgo(181,12);                                           //  Enter Level 2 Stairs to Level 3
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Enlarger **/
//roomobj-23-382.dmp



/** Developer Tray **/
//roomobj-23-383.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0023]*/ if (activeObject2 == 23) {                                           // if Undeveloped Film
    /*[0027]*/   startScript(72);                                                   //  start Film: Develop
    /*[0029]*/ } else {                                                             // -
    /*[002C]*/   if (activeObject2 == 90) {                                         // if Sponge
    /*[0030]*/     if (Var[27] == 0) {                                              //  if Developer Tray Contents == Empty
    /*[0035]*/       Var[27] = Var[24];                                             //   Developer Tray Contents = Sponge Contents
    /*[0038]*/       Var[24] = 0;                                                   //   Sponge Contents = empty
    /*[003B]*/     } else {                                                         //  -
    /*[003E]*/       Var[24] = Var[27];                                             //   Sponge Contents = Developer Tray Contents
    /*[0041]*/       Var[27] = 0;                                                   //   Developer Tray Contents = empty
    /*[0044]*/     }
    /*[0044]*/     startScript(75);                                                 //  start Sponge: Name
    /*[0046]*/   }
    /*[0046]*/   if (activeObject2 == 99) {                                         // if Glass Jar
    /*[004A]*/     startSound(41);                                                  //  sound Liquid - Developer Tray
    /*[004C]*/     if (Var[27] == 0) {                                              //  if Developer Tray Contents == Empty
    /*[0051]*/       Var[27] = Var[22];                                             //   Developer Tray Contents = Glass Jar Contents
    /*[0054]*/       Var[22] = 0;                                                   //   Glass Jar Contents = Empty
    /*[0057]*/     } else if (Var[22] == 0) {                                       //  -
    /*[005F]*/       Var[22] = Var[27];                                             //   Glass Jar Contents = Developer Tray Contents
    /*[0062]*/       Var[27] = 0;                                                   //   Developer Tray Contents = Empty
    /*[0065]*/     } else {                                                         // -
    /*[0068]*/       stopSound(41);
    /*[006A]*/       printEgo("The tray is already full.");
    /*[0081]*/     }
    /*[0081]*/     startScript(74);                                                 // start Glass Jar: Name
    /*[0083]*/   }
    /*[0083]*/   startScript(78);                                                   // start DeveloperTray: Name
    /*[0085]*/ }
    /*[0085]*/ //stopObjectCode();                                                    // --
		break;




/** Desk **/
//roomobj-23-384.dmp



/** File Drawers **/
//roomobj-23-385.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[0020]*/ printEgo("They're locked.");
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;


Un		case VER_Lock:
    /*[0031]*/ printEgo("I don't have a key for this.");
    /*[0049]*/ //stopObjectCode();                                                    // --
		break;





/** Red Light **/
//roomobj-23-413.dmp
      case 37:
		 switch (action){

		case VER_TurnOn:
    /*[001D]*/ startSound(12);                                                      // sound Light Switch
    /*[001F]*/ setBitVar(VAR_ROOM,1,0);                                             // Light On
    /*[0023]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0026]*/ startSound(12);                                                      // sound Light Switch
    /*[0028]*/ setBitVar(VAR_ROOM,1,1);                                             // Light Off
    /*[002C]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 24: Gym Bathroom
 */


/** Water Faucet **/
//roomobj-24-212.dmp
      case 37:
		 switch (action){

		    case VER_Use:
    /*[0017]*/ if (!getState08(activeObject)) {                                     // Tap turned on?
    /*[001A]*/   startScript(73);                                                   //  start Facet: Fill Gar/Sponge with Water
    /*[001C]*/ }
    /*[001C]*/ //stopObjectCode();                                                    // --
		break;





/** Sink **/
//roomobj-24-233.dmp

		case VER_TurnOn:
    /*[001A]*/ clearState08(activeObject);                                                      // Turn On
    /*[001B]*/ startSound(17);                                                      // Sound Sink On
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[001E]*/ setState08(activeObject);                                                        // Turn off
    /*[001F]*/ stopSound(17);                                                       // Sound Sink Off
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0022]*/ if (!getState08(activeObject)) {                                     // Sink turned on?
    /*[0025]*/   startScript(73);                                                   //  start Facet: Fill Gar/Sponge with Water
    /*[0027]*/ }
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;





/** <No Name> **/
//roomobj-24-239.dmp



/** Shower Curtain **/
//roomobj-24-266.dmp

		    case VER_Open:
    /*[0024]*/ startScript(12);                                                     // start Ted: Open Curtain
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0027]*/ startScript(13);                                                     // start Ted: Close Curtain
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Pull:
    /*[002A]*/ if (getState08(82)) {                                                // if Shower Curtain closed
    /*[002E]*/   startScript(12);                                                   //  start Ted: Open Curtain
    /*[0030]*/ } else {                                                             // -
    /*[0033]*/   startScript(13);                                                   //  start Ted: Close Curtain
    /*[0035]*/ }
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;




/** Cracked Mirror **/
//roomobj-24-309.dmp



/** Toilet **/
//roomobj-24-311.dmp

		    case VER_Open:
    /*[001C]*/ doSentence(1,81,0);                                                  // Open Toilet Lid
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0021]*/ doSentence(2,81,0);                                                  // Close Toilet Lid
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0026]*/ animateActor(VAR_EGO,6,1);                                           // kid face Camera
    /*[002A]*/ printEgo("I'd like a little more privacy for that!");
    /*[004D]*/ //stopObjectCode();                                                    // --
		break;





/** Pull Chain **/
//roomobj-24-312.dmp

Pull.		    case VER_Use:
    /*[001E]*/ startSound(7);                                                       // sound Toilet Flush
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;





/** Toilet **/
//roomobj-24-313.dmp



/** Door **/
//roomobj-24-80.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(79);                                                      // Open Door (Gym)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(79);                                                    // Close Door (Gym)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   loadRoomWithEgo(79,25);                                            //  Enter Gym
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;




/** Toilet Lid **/
//roomobj-24-81.dmp

		    case VER_Open:
    /*[001E]*/ setState08(activeObject);                                                        // Open Lid
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0020]*/ clearState08(activeObject);                                                      // Close Lid
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;





/** Shower Curtain **/
//roomobj-24-82.dmp

Open.		    case VER_Pull:
    /*[0024]*/ startScript(12);                                                     // start Ted: Open Curtain
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0027]*/ startScript(13);                                                     // stop Ted: Close Curtain
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;





/** Shower Curtain **/
//roomobj-24-83.dmp

Open.		    case VER_Pull:
    /*[0024]*/ startScript(12);                                                     // start Ted: Open Curtain
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0027]*/ startScript(13);                                                     // stop Ted: Close Curtain
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;




/** Shower Curtain **/
//roomobj-24-84.dmp

Open.		    case VER_Pull:
    /*[0024]*/ startScript(12);                                                     // start Ted: Open Curtain
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0027]*/ startScript(13);                                                     // stop Ted: Close Curtain
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;





/** Water Faucet **/
//roomobj-24-85.dmp

Open.		case VER_TurnOn:
    /*[0028]*/ if (!getState08(activeObject)) {                                     // If Faucet Has Handle
    /*[002B]*/   startSound(18);                                                    // Sound Shower
    /*[002D]*/   setState08(212);                                                   // Water Faucet Off
    /*[002F]*/   clearState02(212);                                                 // Lock Water Faucet
    /*[0031]*/   clearState08(239);                                                 // Hide <no name> (Running Water)
    /*[0033]*/   walkActorTo(12,24,48);                                             // Dead Cousin Ted
    /*[0037]*/   if (Var[116] == 0) {                                               // if Ednas Phone Number has not been exposed
    /*[003C]*/     Var[116] = 1;                                                    //  Ednas Phone Number exposed = Yes
    /*[003F]*/     startScript(139);                                                //  start Cutscene: Weird Ed & Dr. Fred Trigger #1
    /*[0041]*/   }
    /*[0041]*/ } else {                                                             // -
    /*[0044]*/   printEgo("The handle's missing.");
    /*[0059]*/ }
    /*[0059]*/ //stopObjectCode();                                                    // --
		break;


Close.		case VER_TurnOff:
    /*[005A]*/ if (!getState08(activeObject)) {
    /*[005D]*/   stopSound(18);                                                     // stop Sound Shower
    /*[005F]*/   clearState08(212);                                                 // Water Faucet On
    /*[0061]*/   setState02(212);                                                   // UnLock Water Faucet
    /*[0063]*/ }
    /*[0063]*/ //stopObjectCode();                                                    // --
		break;

Fix.		    case VER_Use:
    /*[0064]*/ if (activeObject2 == 120) {                                          // if Water Faucet Handle
    /*[0068]*/   clearState08(activeObject);                                                    //  Facet Has Handle
    /*[0069]*/   setOwnerOf(120,0);                                                 //  Facet Handle has no owner
    /*[006C]*/ } else {                                                             // -
    /*[006F]*/   printEgo("That doesn't make sense.");
    /*[0086]*/ }
    /*[0086]*/ //stopObjectCode();                                                    // --
		break;




/** <No Name> **/
//roomobj-24-86.dmp



/** <No Name> **/
//roomobj-24-87.dmp



/** <No Name> **/
//roomobj-24-88.dmp



/** <No Name> **/
//roomobj-24-89.dmp



/** Sponge **/
//roomobj-24-90.dmp

		    case VER_PickUp:
    /*[002B]*/ pickupObject(0);                                                     // Pick object
    /*[002D]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[002E]*/ if (activeObject2 == 99) {                                           // use with Glass Jar
    /*[0032]*/   Var[24] = Var[22];                                                 //  Sponge Contents = Glass Jar Contents
    /*[0035]*/   Var[22] = 0;                                                       //  Glass Jar Contents = 0
    /*[0038]*/   startScript(75);                                                   //  Sponge: Name
    /*[003A]*/   startScript(74);                                                   //  Glass Jar: Name
    /*[003C]*/ } else {                                                             // -
    /*[003F]*/   doSentence(11,255,254);                                            //  Use _cmdObject2 with _cmdObject
    /*[0043]*/ }
    /*[0043]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0044]*/ if (VAR_ACTIVE_ACTOR == 19) {                                        // Give to Plant
    /*[0049]*/   doSentence(11,36,90);                                              //  Use  with Plant
    /*[004D]*/ }
    /*[004D]*/ if (VAR_ACTIVE_ACTOR < 8) {
    /*[0052]*/   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    // Give to Kid
    /*[0055]*/ }
    /*[0055]*/ //stopObjectCode();                                                    // --
		break;




/**
 * Room 25: Gym
 */


/** TV **/
//roomobj-25-304.dmp

		case VER_TurnOn:
    /*[0014]*/ if (VAR_EGO == 5) {                                                  // If Bernard
    /*[0019]*/   printEgo("It doesn't work, cable's not hooked up.");
    /*[003C]*/ } else {                                                             // -
    /*[003F]*/   printEgo("All I get is fuzz.");
    /*[004F]*/ }
    /*[004F]*/ //stopObjectCode();                                                    // --
		break;




/** Pillow **/
//roomobj-25-305.dmp



/** Playboy Calar **/
//roomobj-25-306.dmp

		    case VER_Read:
    /*[0026]*/ printEgo("May 1972, and Ted's Deathday is circled!");                // Read
    /*[004A]*/ //stopObjectCode();                                                    // --
		break;


Pull.		    case VER_PickUp:
    /*[004B]*/ printEgo("It's nailed, stapled,/and glued to the wall.");            // Pull/Pick Up
    /*[0073]*/ //stopObjectCode();                                                    // --
		break;





/** Poster **/
//roomobj-25-307.dmp

		    case VER_Read:
    /*[0018]*/ printEgo("Miss Mummy of 982 BC.");                                   // Read
    /*[002B]*/ //stopObjectCode();                                                    // --
		break;





/** Surplus Body **/
//roomobj-25-308.dmp

		case VER_WhatIs:
    /*[0024]*/ printEgo("Yuck!");                                                   // What Is
    /*[002B]*/ //stopObjectCode();                                                    // --
		break;





/** Door **/
//roomobj-25-76.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(187);                                                     // Open Door (Level 3 Hallway)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(187);                                                   // Close Door (Level 3 Hallway)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if Door open
    /*[0027]*/   loadRoomWithEgo(187,38);                                           //  Enter Level 3 Hallway
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Sarcophagus **/
//roomobj-25-77.dmp

		    case VER_Open:
    /*[001F]*/ setState08(activeObject);                                                        // Open
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0021]*/ clearState08(activeObject);                                                      // Close
    /*[0022]*/ //stopObjectCode();                                                    // --
		break;





/** Hunk-O-Matic **/
//roomobj-25-78.dmp

		    case VER_Use:
    /*[002B]*/ startScript(23);                                                     // start Gym: Get Stronger
    /*[002D]*/ //stopObjectCode();                                                    // --
		break;





/** Door **/
//roomobj-25-79.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(80);                                                      // Open Door (Gym Bathroom)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(80);                                                    // Close Door (Gym Bathroom)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   if (!getState08(212)) {                                            //  if Water Faucet Off
    /*[002B]*/     putActorInRoom(12,24);                                           //   Put Ted in front of phone number
    /*[002E]*/     putActor(12,30,48);
    /*[0032]*/   } else {                                                           // -
    /*[0035]*/     putActorInRoom(12,24);                                           //   Put Ted to left of phone number
    /*[0038]*/     putActor(12,24,48);
    /*[003C]*/   }
    /*[003C]*/   loadRoomWithEgo(80,24);                                            //  Enter Gym Bathroom
    /*[003F]*/ }
    /*[003F]*/ //stopObjectCode();                                                    // --
		break;




/**
 * Room 26: Weird Ed's
 */


 /** Hamster **/
//roomobj-26-1.dmp

		    case VER_PickUp:
    /*[001D]*/ Var[87] = 0;                                                         // Weird Ed: Looking for plans = 0
    /*[0020]*/ startScript(111);                                                    // start Weird Ed. Handle Object Interactions
    /*[0022]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Use:
    /*[0023]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0028]*/ startScript(89);                                                     // start Give Hamster
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Piggy Bank **/
//roomobj-26-2.dmp

		    case VER_PickUp:
    /*[0022]*/ if (getState08(activeObject)) {                                      // If Piggy Bank broken
    /*[0025]*/   printEgo("Ouch!");
    /*[002C]*/   Var[107] = 2;                                                      //  Give Script: Object-ID = Piggy Bank
    /*[002F]*/   startScript(111);                                                  //  start Weird Ed. Handle Object Interactions
    /*[0031]*/ } else {                                                             // -
    /*[0034]*/   printEgo("It's nailed and glued to the table.");                   //
    /*[0053]*/ }
    /*[0053]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Open:
    /*[0054]*/ if (!getState08(activeObject)) {                                     // If Pibby Bank Not broken
    /*[0057]*/   Var[107] = 2;                                                      //  Give Script: Object-ID
    /*[005A]*/   startScript(111);                                                  //  start Weird Ed. Handle Object Interactions
    /*[005C]*/ }
    /*[005C]*/ //stopObjectCode();                                                    // --
		break;


Close.Fix {
    /*[005D]*/ if (getState08(activeObject)) {                                      // If Piggy Bank Broken
    /*[0060]*/   printEgo("It looks hopeless!");
    /*[0072]*/   Var[107] = 2;                                                      // Give Script: Object-ID
    /*[0075]*/   startScript(111);                                                  // start Weird Ed. Handle Object Interactions
    /*[0077]*/ }
    /*[0077]*/ //stopObjectCode();                                                    // --
		break;





/** Penant **/
//roomobj-26-257.dmp

		    case VER_Read:
    /*[0019]*/ printEgo("L.F.L.U. Rah!");                                           // Read
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;





/** Fighter Jet **/
//roomobj-26-258.dmp



/** X-Wing Model **/
//roomobj-26-259.dmp



/** Strategic Plan **/
//roomobj-26-260.dmp

		    case VER_Read:
    /*[002A]*/ printEgo("Hmm. It doesn't make any sense.");                         // Read
    /*[0046]*/ //stopObjectCode();                                                    // --
		break;





/** Bed **/
//roomobj-26-261.dmp



/** Window **/
//roomobj-26-262.dmp



/** Dime **/
//roomobj-26-3.dmp

		    case VER_PickUp:
    /*[0018]*/ startScript(111);                                                    // start Weird Ed. Handle Object Interactions
    /*[001A]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Use:
    /*[001B]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;




/** Dime **/
//roomobj-26-4.dmp

		    case VER_PickUp:
    /*[0018]*/ startScript(111);                                                    // start Weird Ed. Handle Object Interactions
    /*[001A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[001B]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;





/** Dime **/
//roomobj-26-5.dmp

		    case VER_PickUp:
[0018]*/ startScript(111);                                                        // start Weird Ed. Handle Object Interactions
[001A]*/ stopObjectCode();                                                        // --
}

		    case VER_Use:
[001B]*/ doSentence(11,255,254);                                                  // Use _cmdObject2 with _cmdObject
[001F]*/ stopObjectCode();                                                        // --
}




/** Door **/
//roomobj-26-6.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(186);                                                     // Open Door (Level 3 Hallway)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(186);                                                   // Close Door (Level 3 Hallway)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   loadRoomWithEgo(186,38);                                           //  Enter Level 3 Hallway
    /*[002A]*/   cursorCommand( kModeNormal )                                       //  Cutscene Mode Normal
    /*[002C]*/ }
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;





/** Card Key **/
//roomobj-26-71.dmp

		    case VER_PickUp:
    /*[001E]*/ pickupObject(0);                                                     // Pick object
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[0021]*/ printEgo("This side up.");                                           // Read
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[002F]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 27: Typewriter
 */


/** Door **/
//roomobj-27-211.dmp

		    case VER_Use:
    /*[0024]*/ doSentence(11,36,255);                                               // Use Pot for plant with _cmdObject2
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		case VER_WhatIs:
    /*[0029]*/ printEgo("It bit me!");                                              //
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;





/** Fireplace **/
//roomobj-27-290.dmp



/** Family Portrait **/
//roomobj-27-291.dmp

Open.		    case VER_Pull:
    /*[0023]*/ startScript(62);
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;





/** Pot for plant **/
//roomobj-27-292.dmp

		    case VER_Use:
    /*[001F]*/ if (activeObject2 == 90) {                                           // Use with Sponge
    /*[0023]*/   if (Var[24] == 2) {                                                //  if Sponge Contents == Radioactive water
    /*[0028]*/     Var[24] = 0;                                                     //   Sponge Contents = Empty
    /*[002B]*/     Var[30]++;                                                       //   Plant Size++
    /*[002D]*/   }
    /*[002D]*/   if (Var[24] == 3) {                                                //  if Sponge Contents == Developer
    /*[0032]*/     Var[24] = 0;                                                     //   Sponge Contents = Empty
    /*[0035]*/     Var[30] = 255;                                                   //   Plant Size = Dead
    /*[0038]*/   }
    /*[0038]*/   startScript(75);                                                   // start Sponge: Name
    /*[003A]*/ }
    /*[003A]*/ if (activeObject2 == 99) {                                           // Use with Jar
    /*[003E]*/   if (Var[22] == 2) {                                                //  if Jar Contents == Radioactive water
    /*[0043]*/     Var[22] = 0;                                                     //   Jar Contents = Empty
    /*[0046]*/     Var[30]*/ += 2;                                                    //   Plant Size+=2
    /*[0049]*/   }
    /*[0049]*/   if (Var[22] == 3) {                                                //  if Jar Contents == Developer
    /*[004E]*/     Var[22] = 0;                                                     //   Jar Contents = Empty
    /*[0051]*/     Var[30] = 255;                                                   //   Plant Size = Dead
    /*[0054]*/   }
    /*[0054]*/   startScript(74);                                                   // start Sponge: Name
    /*[0056]*/ }
    /*[0056]*/ if (Var[30] == 255) {                                                // if Plant Size == Dead
    /*[005B]*/   printEgo("I killed it!");
    /*[0067]*/ } else if (Var[30] >= 3) {                                           // -
    /*[006F]*/   Var[30] = 2;                                                       //  Plant Size = Full Size
    /*[0072]*/ }
    /*[0072]*/ if (activeObject2 == 60) {
    /*[0076]*/   startScript(48);
    /*[0078]*/ }
    /*[0078]*/ //stopObjectCode();                                                    // --
		break;




/** Typewriter **/
//roomobj-27-409.dmp

Fix {
    /*[001E]*/ if (activeObject2 == 177) {                                          // Fix with Manuscript
    /*[0022]*/   startScript(10);                                                   // start Memoir: Writing
    /*[0024]*/ } else {                                                             // -
    /*[0027]*/   printEgo("That's ridiculous!");
    /*[003A]*/ }
    /*[003A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[003B]*/ if (activeObject2 == 177) {                                          // Use with manuscript
    /*[003F]*/   startScript(10);                                                   // start Memoir: Writing
    /*[0041]*/ }
    /*[0041]*/ if (activeObject2 == 201) {                                          // Use with Sealed Envelope
    /*[0045]*/   VAR_RESULT = getActorBitVar(VAR_EGO,4);
    /*[0049]*/   if (VAR_RESULT == 1) {                                             // if kid has kActorMiscFlagWatchedTV
    /*[004E]*/     if (Var[85] == 0) {                                              //  if Envelope: Addressed == 0
    /*[0053]*/       printEgo("Ok, I'll type the publisher's address.");
    /*[0076]*/       startScript(108);                                              //   start Typewriter: Actor Using
    /*[0078]*/       Var[85] = 1;                                                   //   Envelope: Addressed = 1
    /*[007B]*/     } else {                                                         // -
    /*[007E]*/       printEgo("It's already addressed.");
    /*[0095]*/     }
    /*[0095]*/   } else {                                                           // -
    /*[0098]*/     printEgo("I don't know what to type on it!");
    /*[00B3]*/   }
    /*[00B3]*/ }
    /*[00B3]*/ //stopObjectCode();                                                    // --
		break;




/** Desk **/
//roomobj-27-410.dmp



/** Plant **/
//roomobj-27-411.dmp



/** Door **/
//roomobj-27-66.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(188);                                                     // Open Door (Typewriter)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(188);                                                   // Close Door (Typewriter)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If door open
    /*[0027]*/   loadRoomWithEgo(188,38);                                           //  Enter Level 3 Hallway
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Man-eating plant **/
//roomobj-27-67.dmp

		    case VER_Use:
    /*[0024]*/ doSentence(11,36,255);                                               // Use Pot for plant with _cmdObject2
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_WalkTo:
    /*[0029]*/ loadRoomWithEgo(232,28);                                             // Enter Telescope
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;





/** Paint Blotch **/
//roomobj-27-68.dmp

		    case VER_Use:
    /*[001E]*/ if (activeObject2 == 167) {                                          // if Use with Paint Remover
    /*[0022]*/   setOwnerOf(167,14);                                                //  Green owns paint Remover
    /*[0025]*/   setState08(68);                                                    //  Lock Blotch
    /*[0027]*/   setState02(68);                                                    //  Hide Blotch
    /*[0029]*/ }
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;




/** Door **/
//roomobj-27-69.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(202);                                                     // Open Door (Electrical Wiring)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(202);                                                   // Close Door (Electrical Wiring)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if hatch open
    /*[0027]*/   loadRoomWithEgo(202,15);                                           //  Enter Electrical Wiring
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 28: Telescope
 */


/** Hole **/
//roomobj-28-232.dmp

		    case VER_WalkTo:
    /*[0016]*/ if (Var[30] == 255) {                                                // if Plant Size == Dead
    /*[001B]*/   printEgo("The plant's gone. I'm stuck here!");
    /*[0039]*/ } else {                                                             // -
    /*[003C]*/   VAR_RESULT = isScriptRunning(48);
    /*[003F]*/   if (VAR_RESULT == 0) {                                             // If script Plant: Give Pepsi not running
    /*[0044]*/     Var[76] = 6;                                                     //  Death Method = Eaten by plant
    /*[0047]*/     startScript(56);                                                 //  Cutscene: Kid Dies
    /*[0049]*/   } else {                                                           // -
    /*[004C]*/     loadRoomWithEgo(67,27);                                          //  Enter Typewriter
    /*[004F]*/   }
    /*[004F]*/ }
    /*[004F]*/ //stopObjectCode();                                                    // --
		break;




/** Astronomy Chart **/
//roomobj-28-402.dmp

		    case VER_Read:
    /*[0021]*/ printEgo("It shows the trajectory of a meteorite%/%impacting Earth.");
    /*[0055]*/ //stopObjectCode();                                                    // --
		break;




/** Control Panel **/
//roomobj-28-403.dmp

		    case VER_Read:
    /*[001F]*/ printEgo("Insert dime.");                                            // Read
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;



/** Left Button **/
//roomobj-28-404.dmp

		    case VER_Read:
    /*[001F]*/ printEgo("Rotate left.");                                            // Read
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Push:
    /*[002D]*/ if (Var[26]*/ != 0) {                                                  // if Telescope: Dimes Available
    /*[0032]*/   Var[20] -= 1;                                                      //  Move Screen Left
    /*[0035]*/   if (Var[20] == 255) {                                              //  Overflow?
    /*[003A]*/     startSound(12);                                                  //   sound Light Switch
    /*[003C]*/     Var[20] = 0;                                                     //   Screen 0
    /*[003F]*/   } else {                                                           // -
    /*[0042]*/     Var[26] -= 1;                                                    // Telescope: Dimes Available -= 1
    /*[0045]*/     startScript(16);                                                 // start Telescope: Rotate
    /*[0047]*/   }
    /*[0047]*/ } else {                                                             // -
    /*[004A]*/   printEgo("It's not rotating.");
    /*[005C]*/   startSound(11);                                                    // Sound CoinSlot
    /*[005E]*/ }
    /*[005E]*/ stopObjectCode();                                                    // --
  }


/** Right Button **/
//roomobj-28-405.dmp

		    case VER_Read:
    /*[0020]*/ printEgo("Rotate right.");
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Push:
    /*[002F]*/ if (Var[26]*/ != 0) {                                                  // if Telescope: Dimes Available
    /*[0034]*/   Var[20]++;                                                         //  Telescope Room ++
    /*[0036]*/   if (Var[20] == 4) {                                                //  if Telescope Room reached max?
    /*[003B]*/     startSound(12);                                                  //   sound Light Switch
    /*[003D]*/     Var[20] = 3;                                                     //   Back to previous
    /*[0040]*/   } else {                                                           // -
    /*[0043]*/     Var[26] -= 1;                                                    //  Telescope: Dimes Available -= 1
    /*[0046]*/     startScript(16);                                                 //  start Telescope: Rotate
    /*[0048]*/   }
    /*[0048]*/ } else {                                                             // -
    /*[004B]*/   printEgo("It's not rotating.");
    /*[005D]*/   startSound(11);                                                    // Sound CoinSlot
    /*[005F]*/ }
    /*[005F]*/ //stopObjectCode();                                                    // --
		break;




/** Really Powerful Telescope **/
//roomobj-28-406.dmp

		    case VER_Use:
    /*[002B]*/ startScript(17);                                                     // start Telescope: Look
    /*[002D]*/ //stopObjectCode();                                                    // --
		break;




/** Coin Slot **/
//roomobj-28-407.dmp

		    case VER_Read:
    /*[001D]*/ printEgo("Donations kindly accepted.");
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0038]*/ if (activeObject2 == 3) {                                            // if Dime
    /*[003C]*/   setOwnerOf(3,0);                                                   //  Remove Dime
    /*[003F]*/   goto 0066;
    /*[0042]*/ } else if (activeObject2 == 4) {                                     // if Dime
    /*[0049]*/   setOwnerOf(4,0);                                                   //  Remove Dime
    /*[004C]*/   goto 0066;
    /*[004F]*/ } else if (activeObject2 == 5) {                                     // if Dime
    /*[0056]*/   setOwnerOf(5,0);                                                   //  Remove Dime
    /*[0059]*/   goto 0066;
    /*[005C]*/ } else if (activeObject2 == 190) {                                   // if Dime
    /*[0063]*/   setOwnerOf(190,0);                                                 //  Remove Dime
    /*[0066]*/   Var[26]++;                                                         // ++Telescope: Dimes Available
    /*[0068]*/   startSound(11);                                                    // Sound CoinSlot
    /*[006A]*/ } else {                                                             // -
    /*[006D]*/   printEgo("It doesn't fit.");
    /*[007C]*/ }
    /*[007C]*/ //stopObjectCode();                                                    // --
		break;




/**
 * Room 29: Underhouse
 */

/** Grate **/
//roomobj-29-213.dmp

Open.		    case VER_Pull:
    /*[001F]*/ setState08(activeObject);                                                        // Open
    /*[0020]*/ setState08(20);                                                      // Open Grating (Front of Mansion)
    /*[0022]*/ //stopObjectCode();                                                    // --
		break;


Close.		    case VER_Push:
    /*[0023]*/ clearState08(activeObject);                                                      // Close Grating
    /*[0024]*/ clearState08(20);                                                    // Close Grating (Front of mansion)
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0027]*/ if (getState08(activeObject)) {                                      // if open
    /*[002A]*/   loadRoomWithEgo(20,1);                                             //  Enter Front of Mansion
    /*[002D]*/ }
    /*[002D]*/ //stopObjectCode();                                                    // --
		break;




/** Floor Grating **/
//roomobj-29-267.dmp

		case VER_WhatIs:
    /*[001F]*/ printEgo("I can't reach it.");                                       // What Is
    /*[002F]*/ //stopObjectCode();                                                    // --
		break;





/** Puddle of Developer **/
//roomobj-29-32.dmp

		    case VER_PickUp:
    /*[0027]*/ printEgo("I don't have anything to put it in.");
    /*[0045]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0046]*/ if (activeObject2 == 90) {                                           // use with Sponge
    /*[004A]*/   setState08(activeObject);                                                      //  Hide Puddle
    /*[004B]*/   setState02();                                                      //  Lock Puddle
    /*[004C]*/   Var[24] = 3;                                                       //  Sponge Contents = Developer
    /*[004F]*/   startScript(75);                                                   //  start Sponge: Name
    /*[0051]*/ }
    /*[0051]*/ if (activeObject2 == 99) {                                           // use with jar
    /*[0055]*/   printEgo("I can't get it in the jar.");
    /*[006B]*/ }
    /*[006B]*/ //stopObjectCode();                                                    // --
		break;




/** Water Valve **/
//roomobj-29-33.dmp


Open.		case VER_TurnOn:
    /*[0023]*/ if (!getState08(activeObject)) {                                     // if Closed
    /*[0026]*/   setState08(activeObject);                                                      //  Open
    /*[0027]*/   startScript(70);                                                   //  start Pool Water Valve
    /*[0029]*/ }
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;


Close.		case VER_TurnOff:
    /*[002A]*/ if (getState08(activeObject)) {                                      // if Open
    /*[002D]*/   clearState08(activeObject);                                                    //  Close
    /*[002E]*/   startScript(70);                                                   //  start Pool Water Valve
    /*[0030]*/ }
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 30: Lab: Zom-b-Matic
 */


/** Door **/
//roomobj-30-136.dmp

Open.		    case VER_WalkTo:
    /*[0018]*/ printEgo("It's sealed shut!");                                       // Open
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;





/** Locker **/
//roomobj-30-137.dmp

		    case VER_Open:
    /*[001A]*/ setState08(activeObject);                                                        // Open
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001C]*/ clearState08(activeObject);                                                      // Close
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;





/** Cold Can of Pepsi **/
//roomobj-30-145.dmp

		    case VER_Open:
    /*[0029]*/ printEgo("Ok, it's open.");                                          // Open
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0038]*/ printEgo("That was refreshing.");                                    // use
    /*[004C]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_PickUp:
    /*[004D]*/ pickupObject(0);                                                     // Pick object
    /*[004F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[0050]*/ printEgo("12 fluid ounces (354 ml)");
    /*[0066]*/ //stopObjectCode();                                                    // --
		break;





/** Door **/
//roomobj-30-237.dmp

		    case VER_Open:
    /*[0020]*/ if (!getState04(activeObject)) {                                     // if door unlocked
    /*[0023]*/   startScript(116);                                                  //  start Verb: Generic: Open Door
    /*[0025]*/   setState08(251);                                                   //  Open Door (Lab: Meteor))
    /*[0027]*/ } else {                                                             // -
    /*[002A]*/   printEgo("It's locked.");
    /*[0037]*/ }
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0038]*/ startScript(117);                                                    // start Verb: Generic: Close Door
    /*[003A]*/ clearState08(251);                                                   // Close Door (Lab: Meteor)
    /*[003C]*/ setState04();                                                        // Lock Door
    /*[003D]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[003E]*/ if (getState08(activeObject)) {                                      // if door open
    /*[0041]*/   loadRoomWithEgo(251,51);                                           //  Enter Lab: Meteor
    /*[0044]*/ }
    /*[0044]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Unlock:Use.		case VER_Lock:
    /*[0045]*/ doSentence(11,152,255);                                              // Use Card Slot
    /*[0049]*/ //stopObjectCode();                                                    // --
		break;





/** Radiation Suit **/
//roomobj-30-253.dmp

Use.		    case VER_PickUp:
    /*[0022]*/ putActorInRoom(8,30);                                                // Radiation Suit enters Lab: Zom-b-Matic
    /*[0025]*/ putActor(8,65,56);
    /*[0029]*/ VAR_EGO = 8;                                                         // Kid = Radiation Suit
    /*[002C]*/ animateActor(VAR_EGO,253,1);                                         // No Meteor
    /*[0030]*/ putActorInRoom(Var[100],0);                                          // Old Kid leaves room
    /*[0033]*/ putActor(Var[100],0,0);
    /*[0037]*/ Var[90] = 253;                                                       // Radiation Suit
    /*[003A]*/ VAR_RESULT = getObjectOwner(Var[90]);
    /*[003D]*/ if (VAR_RESULT == Var[100]) {                                        // Does previous kid own object
    /*[0042]*/   setOwnerOf(Var[90],8);                                             //  Radiation suit now owns object
    /*[0045]*/ }
    /*[0045]*/ Var[90] -= 1;
    /*[0048]*/ unless (Var[90] == 0) goto 003A;                                     // Loop all objects
    /*[004D]*/ cursorCommand( kModeNoNewKid )                                       // Disable New Kid verb
    /*[004F]*/ Var[97] = 0;
    /*[0052]*/ Var[98] = 0;
    /*[0055]*/ Var[99] = 0;
    /*[0058]*/ Var[90] = 7;
    /*[005B]*/ setActorBitVar(Var[90],128,1);
    /*[005F]*/ putActorInRoom(Var[90],0);
    /*[0062]*/ putActor(Var[90],0,0);
    /*[0066]*/ Var[91] = 253;                                                       // Radiation Suit
    /*[0069]*/ VAR_RESULT = getObjectOwner(Var[91]);
    /*[006C]*/ if (VAR_RESULT == Var[90]) {
    /*[0071]*/   setOwnerOf(Var[91],0);                                             // object owned by no-one
    /*[0074]*/ }
    /*[0074]*/ Var[91] -= 1;
    /*[0077]*/ unless (Var[91] == 0) goto 0069;                                     // loop all objects
    /*[007C]*/ Var[90] -= 1;
    /*[007F]*/ unless (Var[90] == 0) goto 005B;                                     // loop all kids
    /*[0084]*/ setState08(activeObject);                                                        // Lock
    /*[0085]*/ setState02();                                                        // Lock
    /*[0086]*/ actorFollowCamera(VAR_EGO);                                          // Camera follow radiation suit
    /*[0088]*/ //stopObjectCode();                                                    // --
		break;





/** Pepsi Machine **/
//roomobj-30-349.dmp

		    case VER_Read:
    /*[0021]*/ printEgo("Please insert one quarter.");
    /*[003A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[003B]*/ if (activeObject2 == 200) {                                          // if use with Quarter
    /*[003F]*/   startSound(54);                                                    // sound Keypad Buttons
    /*[0041]*/   clearState08(145);                                                 // Unlock Cold can of Pepsi
    /*[0043]*/   clearState02(145);                                                 // Unlock Cold can of Pepsi
    /*[0045]*/   setOwnerOf(200,0);
    /*[0048]*/ } else {                                                             // -
    /*[004B]*/   printEgo("It doesn't work.");
    /*[005B]*/ }
    /*[005B]*/ //stopObjectCode();                                                    // --
		break;





/** Zom-B-matic **/
//roomobj-30-350.dmp

		    case VER_Read:
    /*[001D]*/ printEgo("Please insert one kid.");
    /*[0032]*/ //stopObjectCode();                                                    // --
		break;





/** Girl Zombie **/
//roomobj-30-351.dmp



/** Boy Zombie **/
//roomobj-30-352.dmp



/** Card Slot **/
//roomobj-30-408.dmp

		    case VER_Read:
    /*[0021]*/ printEgo("Insert card key to unlock door.");
    /*[003D]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Unlock:Use.		case VER_Lock:
    /*[003E]*/ if (activeObject2 == 71) {                                           // if Card Key
    /*[0042]*/   clearState04(237);                                                 //  Open Door (Lab: Zom-b-Matic)
    /*[0044]*/   startSound(54);                                                    // sound Keypad Buttons
    /*[0046]*/   doSentence(1,237,0);                                               // Open Door
    /*[004A]*/ } else {                                                             // -
    /*[004D]*/   printEgo("It doesn't fit.");
    /*[005C]*/ }
    /*[005C]*/ //stopObjectCode();                                                    // --
		break;




/** Control Panel **/
//roomobj-30-417.dmp

		    case VER_Read:
    /*[001F]*/ printEgo("To initiate destruct sequence:/Press buttons in proper order.");
    /*[0057]*/ //stopObjectCode();                                                    // --
		break;





/** Button 1 **/
//roomobj-30-418.dmp

		    case VER_Push:
    /*[001A]*/ printEgo("Button 1 pushed.");                                        // Push
    /*[002A]*/ startSound(54);                                                      // sound Keypad Buttons
    /*[002C]*/ doSentence(13,161,0);                                                // Walk to Control Panel
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;





/** Button 2 **/
//roomobj-30-419.dmp

		    case VER_Push:
    /*[001A]*/ printEgo("Button 2 pushed.");                                        // Push
    /*[002A]*/ startSound(54);                                                      // sound Keypad Buttons
    /*[002C]*/ doSentence(13,161,0);                                                // Walk to Control Panel
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;





/** Button 3 **/
//roomobj-30-420.dmp

		    case VER_Push:
    /*[001A]*/ printEgo("Button 3 pushed.");                                        // Push
    /*[002A]*/ startSound(54);                                                      // sound Keypad Buttons
    /*[002C]*/ doSentence(13,161,0);                                                // Walk to Control Panel
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;





/** Button 4 **/
//roomobj-30-421.dmp

		    case VER_Push:
    /*[001A]*/ printEgo("Button 4 pushed.");                                        // Push
    /*[002A]*/ startSound(54);                                                      // sound Keypad Buttons
    /*[002C]*/ doSentence(13,161,0);                                                // Walk to Control Panel
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 31: Lab: Entry
 */


/** Door **/
//roomobj-31-133.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(130);                                                     // Open Door (Dungeon)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(130);                                                   // Close Door (Dungeon)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door open
    /*[0027]*/   cursorCommand( kModeNormal )                                       //  Cutscene Mode Normal
    /*[0029]*/   loadRoomWithEgo(130,4);                                            //  Enter Dungeon
    /*[002C]*/ }
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;





/** Door **/
//roomobj-31-135.dmp

		    case VER_Open:
    /*[001A]*/ VAR_RESULT = isScriptRunning(43);                                    // Purple Tentacle: Check for close actors
    /*[001D]*/ if (VAR_RESULT == 0) {                                               //  Purple not looking for actors?
    /*[0022]*/   startScript(4);                                                    //   Door: Open
    /*[0024]*/   setState08(136);
    /*[0026]*/ } else {                                                             // -
    /*[0029]*/   printEgo("It's stuck!");                                           //   Door is stuck
    /*[0035]*/ }
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0036]*/ startScript(5);                                                      // Door: Close
    /*[0038]*/ clearState08(136);
    /*[003A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[003B]*/ if (getState08(activeObject)) {
    /*[003E]*/   startScript(142);                                                  // Secret Lab: Enter Room
    /*[0040]*/ }
    /*[0040]*/ //stopObjectCode();                                                    // --
		break;





/** Control Panel **/
//roomobj-31-347.dmp



/** Periscope **/
//roomobj-31-348.dmp

		    case VER_Use:
    /*[001B]*/ printEgo("I see a heart-shaped bed.");                               // Use
    /*[0032]*/ //stopObjectCode();                                                    // --
		break;





/** Map of House **/
//roomobj-31-416.dmp



/**
 * Room 32: Meteor Police
 */


/** <No Name> **/
//roomobj-32-203.dmp



/**
 * Room 33: Mansion At Distance (Lights Off)
 */


/** <No Name> **/
//roomobj-33-10.dmp



/** <No Name> **/
//roomobj-33-11.dmp



/** <No Name> **/
//roomobj-33-7.dmp



/** <No Name> **/
//roomobj-33-73.dmp



/** <No Name> **/
//roomobj-33-8.dmp



/** <No Name> **/
//roomobj-33-9.dmp



/**
 * Room 34: Telescope looking into Room 9
 */


/** <No Name> **/
//roomobj-34-140.dmp



/** <No Name> **/
//roomobj-34-141.dmp



/** <No Name> **/
//roomobj-34-142.dmp



/** <No Name> **/
//roomobj-34-199.dmp



/**
 * Room 35: Telescope looking at Alien
 */


/** <No Name> **/
//roomobj-35-205.dmp



roomobj-35-206.dmp



/**
 * Room 36: Storage / Leading out to pool
 */


/** Shelves **/
//roomobj-36-314.dmp



/** Door **/
//roomobj-36-91.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(65);                                                      // Open Door (Dining)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(65);                                                    // Close Door (Dining)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if Door open
    /*[0027]*/   if (Var[113] == 0) {                                               //  if Storage Room Not Entered
    /*[002C]*/     Var[113] = 1;                                                    //   Storage Room Entered
    /*[002F]*/     startScript(134);                                                //   start Cutscene: Weird Ed & Nurse Edna Trigger #1
    /*[0031]*/   }
    /*[0031]*/   loadRoomWithEgo(65,37);                                            //  Enter Dining
    /*[0034]*/ }
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;





/** Door **/
//roomobj-36-92.dmp

		    case VER_Open:
    /*[0020]*/ if (!getState04(activeObject)) {                                     // if door unlocked
    /*[0023]*/   startScript(4);                                                    //  start Door: Open
    /*[0025]*/   setState08(104);                                                   //  Open Door (Pool Area)
    /*[0027]*/ } else {                                                             // -
    /*[002A]*/   startScript(64);                                                   //  start Print "The door is locked"
    /*[002C]*/ }
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[002D]*/ startScript(5);                                                      // start Door: Close
    /*[002F]*/ clearState08(104);                                                   // Close Door (Pool Area)
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Unlock:		    case VER_Use:
    /*[0032]*/ if (activeObject2 == 125) {                                          // if use with Silver Key
    /*[0036]*/   clearState04();                                                    //  Unlock Door
    /*[0037]*/   clearState04(104);                                                 //  Unlock Door (Pool Area)
    /*[0039]*/   doSentence(1,92,0);                                                //  Open Door
    /*[003D]*/ } else {                                                             // -
    /*[0040]*/   startScript(66);                                                   // start Print "I can't unlock the door with this."
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Lock:
    /*[0043]*/ setState04();                                                        // Lock Door
    /*[0044]*/ setState04(104);                                                     // Lock Door (Pool Area)
    /*[0046]*/ doSentence(2,92,0);                                                  // Close Door
    /*[004A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[004B]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[004E]*/   loadRoomWithEgo(104,6);                                            //  Enter Pool Area
    /*[0051]*/ }
    /*[0051]*/ //stopObjectCode();                                                    // --
		break;





/** Bottle of Developer **/
//roomobj-36-94.dmp

		    case VER_PickUp:
    /*[0025]*/ clearState08(98);                                                    // Grate
    /*[0027]*/ clearState08(32);                                                    // Show Puddle of Developer (underhouse)
    /*[0029]*/ clearState02(32);                                                    // Unlock Puddle of Developer (underhouse)
    /*[002B]*/ setState08(activeObject);                                                        // Lock Bottle
    /*[002C]*/ setState02();                                                        // Hide Bottle
    /*[002D]*/ startSound(10);                                                      // sound Piggy Bank Break
    /*[002F]*/ printEgo("Whoops!");
    /*[0038]*/ //stopObjectCode();                                                    // --
		break;




/** Tentacle Chow **/
//roomobj-36-95.dmp

		    case VER_PickUp:
    /*[0021]*/ pickupObject(0);                                                     // Pick object
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0024]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;





/** Canned Goods **/
//roomobj-36-96.dmp

		    case VER_PickUp:
    /*[0020]*/ pickupObject(0);                                                     // Pick object
    /*[0022]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0023]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;





/** Fruit Drinks **/
//roomobj-36-97.dmp

		    case VER_PickUp:
    /*[0020]*/ pickupObject(0);                                                     // Pick object
    /*[0022]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0023]*/ startScript(99);
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;





/** Grate **/
//roomobj-36-98.dmp

Open.Pull.		    case VER_PickUp:
    /*[001B]*/ if (!getState08(activeObject)) {                                     // if develeper smashed
    /*[001E]*/   printEgo("Yech, broken glass!");
    /*[0031]*/ } else {                                                             // -
    /*[0034]*/   printEgo("It's welded into the floor.");
    /*[004D]*/ }
    /*[004D]*/ //stopObjectCode();                                                    // --
		break;





/** Glass Jar **/
//roomobj-36-99.dmp

		    case VER_PickUp:
    /*[0026]*/ pickupObject(0);                                                     // Pick object
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0029]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[002D]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[002E]*/ if (VAR_ACTIVE_ACTOR == 19) {                                        // Give to Plant
    /*[0033]*/   doSentence(11,36,99);                                              //  Use Pot for plant with Glass Jar
    /*[0037]*/ } else if (VAR_ACTIVE_ACTOR < 8) {                                   // -
    /*[003F]*/   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Give to kid
    /*[0042]*/ } else if (Var[22]*/ > 0) {                                            // Glass Jar Contents != Empty
    /*[004A]*/   Var[134] = 1;                                                      //  Glass Jar has content = 1
    /*[004D]*/   startScript(99);                                                   //  Give: Accept Item Check 2
    /*[004F]*/ }
    /*[004F]*/ //stopObjectCode();                                                    // --
		break;




/**
 * Room 37: Dining
 */


/** Chair **/
//roomobj-37-281.dmp



/** Chair **/
//roomobj-37-282.dmp



/** Candle **/
//roomobj-37-283.dmp

		    case VER_PickUp:
    /*[0018]*/ startScript(65);                                                     // start Print "Its too Heavy"
    /*[001A]*/ //stopObjectCode();                                                    // --
		break;





/** Candle **/
//roomobj-37-284.dmp

		    case VER_PickUp:
    /*[0018]*/ startScript(65);                                                     // start Print "Its too Heavy"
    /*[001A]*/ //stopObjectCode();                                                    // --
		break;





/** Candle **/
//roomobj-37-285.dmp

		    case VER_PickUp:
    /*[0018]*/ startScript(65);                                                     // start Print "Its too Heavy"
    /*[001A]*/ //stopObjectCode();                                                    // --
		break;




/** Light **/
//roomobj-37-286.dmp

TurnOn.TurnOff.		    case VER_Use:
    /*[001B]*/ printEgo("I can't reach it.");
    /*[002B]*/ //stopObjectCode();                                                    // --
		break;





/** Gravy Stain **/
//roomobj-37-441.dmp

		    case VER_PickUp:
    /*[001D]*/ printEgo("I don't do table cloths.");
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;





/** Door **/
//roomobj-37-62.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(49);                                                      // Door Open (Kitchen)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(49);                                                    // Door Close (Kitchen)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door open
    /*[0027]*/   loadRoomWithEgo(49,7);                                             //  enter kitchen
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Old Rotting Turkey **/
//roomobj-37-63.dmp

		    case VER_PickUp:
    /*[0026]*/ pickupObject(63);                                                    // Pickup
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0029]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[002B]*/ //stopObjectCode();                                                    // --
		break;





/** Week old Roast **/
//roomobj-37-64.dmp

		    case VER_PickUp:
    /*[0022]*/ pickupObject(64);                                                    // Pickup
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0025]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;





/** Door **/
//roomobj-37-65.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(91);                                                      // Open Door (storage)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(91);                                                    // Close Door (storage)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door open
    /*[0027]*/   loadRoomWithEgo(91,36);                                            //  enter storage
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 38: Level 3 Hallway
 */


/** Door: Radio Room **/
//roomobj-38-184.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(189);
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(189);
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {
    /*[0027]*/   loadRoomWithEgo(189,21);
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Door: Nurse Edna **/
//roomobj-38-185.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(70);
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(70);
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   VAR_RESULT = getActorRoom("Nurse Edna");                           //
    /*[002A]*/   if (VAR_RESULT == 19) {                                            //  If Nurse Edna in her bedroom
    /*[002F]*/     if (Var[109] == 0) {                                             //   if Purple chased out of lab == No
    /*[0034]*/       VAR_RESULT = isScriptRunning(29);                              //
    /*[0037]*/       if (VAR_RESULT == 0) {                                         //    if Cutscene: Edna: Prank Phone Call not running
    /*[003C]*/         putActorInRoom(10,19);                                       //      Put Nurse Edna in bedroom
    /*[003F]*/         putActor(10,34,64);                                          //
    /*[0043]*/         animateActor(10,6,1);                                        //       Nurse Edna Face left
    /*[0047]*/       }
    /*[0047]*/       startScript(33);                                               //      start Nurse Edna: Return to Room (Level 3 Hallway)
    /*[0049]*/     }
    /*[0049]*/   }
    /*[0049]*/   loadRoomWithEgo(70,19);                                            // Actor enters room
    /*[004C]*/ }
    /*[004C]*/ //stopObjectCode();                                                    // --
		break;




/** Door: Weird Ed **/
//roomobj-38-186.dmp
Events:
  Open - 001A
 Close - 001F
WalkTo - 0024

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(6);                                                       //
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(6);
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {
    /*[0027]*/   VAR_RESULT = getActorRoom("Weird Ed");
    /*[002A]*/   if (VAR_RESULT == 26) {
    /*[002F]*/     startScript(86);                                                 // start Weird Ed: Check for frily actors
    /*[0031]*/   }
    /*[0031]*/   loadRoomWithEgo(6,26);                                             // Actor enters room
    /*[0034]*/ }
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;





/** Door: Gym **/
//roomobj-38-187.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(76);
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(76);
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {
    /*[0027]*/   loadRoomWithEgo(76,25);
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Door: Typewriter Room **/
//roomobj-38-188.dmp

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(66);                                                      // Open Door (Typewriter Room)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(66);                                                    // Close Door (Typewriter Room)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door open
    /*[0027]*/   loadRoomWithEgo(66,27);                                            //  Enter typewriter room
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;





/** Stairs **/
//roomobj-38-208.dmp

		    case VER_WalkTo:
    /*[0018]*/ loadRoomWithEgo(180,12);                                             // Enter Level 2 Stairs to Level 3
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;





/** Plant **/
//roomobj-38-300.dmp



/** Plant **/
//roomobj-38-303.dmp



/** Plant **/
//roomobj-38-310.dmp



/**
 * Room 39: Video Game: High Scores
 */


/** Highscore: Pin1 **/
//roomobj-39-227.dmp



/** Highscore: Pin1 **/
//roomobj-39-228.dmp



/** Highscore: Pin1 **/
//roomobj-39-229.dmp



/** Highscore: Pin1 **/
//roomobj-39-230.dmp



/**
 * Room 40: 3 Guys who publish anything (TV)
 */


/** <No Name> **/
//roomobj-40-249.dmp



/**
 * Room 41: 3 Guys who publish anything (Office)
 */


 /** <No Name> **/
//roomobj-41-242.dmp



/** <No Name> **/
//roomobj-41-274.dmp



/**
 * Room 43: Keypad
 */


/** * **/
//roomobj-43-287.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 10;                                                        // Keypad Input = 10
    /*[0017]*/ print(255,"*");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;





/** 0 **/
//roomobj-43-288.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 0;                                                         // Keypad Input = 0
    /*[0017]*/ print(255,"0");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** # **/
//roomobj-43-289.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 11;                                                        // Keypad Input = 11
    /*[0017]*/ print(255,"#");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** 1 **/
//roomobj-43-422.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 1;                                                         // Keypad Input = 1
    /*[0017]*/ print(255,"1");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** 2 **/
//roomobj-43-423.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 2;                                                         // Keypad Input = 2
    /*[0017]*/ print(255,"2");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** 3 **/
//roomobj-43-424.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 3;                                                         // Keypad Input = 3
    /*[0017]*/ print(255,"3");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** 4 **/
//roomobj-43-425.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 4;                                                         // Keypad Input = 4
    /*[0017]*/ print(255,"4");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** 5 **/
//roomobj-43-426.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 5;                                                         // Keypad Input = 5
    /*[0017]*/ print(255,"5");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** 6 **/
//roomobj-43-427.dmp

		case VER_WhatIs:
    /*[0013]*/ startSound(19);                                                      // sound Light Beep
    /*[0015]*/ Var[49] = 6;                                                         // Keypad Input = 6
    /*[0018]*/ print(255,"6");
    /*[001C]*/ //stopObjectCode();                                                    // --
		break;




/** 7 **/
//roomobj-43-428.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 7;                                                         // Keypad Input = 7
    /*[0017]*/ print(255,"7");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** 8 **/
//roomobj-43-429.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 8;                                                         // Keypad Input = 8
    /*[0017]*/ print(255,"8");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/** 9 **/
//roomobj-43-430.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(19);                                                      // sound Light Beep
    /*[0014]*/ Var[49] = 9;                                                         // Keypad Input = 9
    /*[0017]*/ print(255,"9");
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;




/**
 * Room 44: Welcome to Mansion
 */


 /** ( Exit to room 1 ) **/
//roomobj-44-241.dmp

		    case VER_WalkTo:
    /*[0012]*/ loadRoomWithEgo(240,1);                                              // Enter Front of Mansion
    /*[0015]*/ //stopObjectCode();                                                    // --
		break;





/** Sign **/
//roomobj-44-265.dmp

		    case VER_Read:
    /*[0016]*/ printEgo("WARNING!!/Trespassers will be horribly mutilated.");
    /*[0045]*/ //stopObjectCode();                                                    // --
		break;





/**
 * Room 45: Kid Selection
 */


/** Syd **/
//roomobj-45-243.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[90] = 1;                                                         // Kid Selected = Syd
    /*[0015]*/ print(255,"Syd - an aspiring musician%/%trying to start his own new-wave band.");
    /*[0051]*/ startScript(109);                                                    // Intro: Kid Selection: Update Var States
    /*[0053]*/ //stopObjectCode();                                                    // --
		break;




/** Razor **/
//roomobj-45-244.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[90] = 2;                                                         // Kid Selected = Razor
    /*[0015]*/ print(255,"Razor - lead singer for the punk band,/`Razor and the Scummettes.`");
    /*[0050]*/ startScript(109);                                                    // Intro: Kid Selection: Update Var States
    /*[0052]*/ //stopObjectCode();                                                    // --
		break;




/** Michael **/
//roomobj-45-245.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[90] = 4;                                                         // Kid Selected = Michael
    /*[0015]*/ print(255,"Michael - award winning photographer%/%for the college newspaper.");
    /*[0052]*/ startScript(109);                                                    // Intro: Kid Selection: Update Var States
    /*[0054]*/ //stopObjectCode();                                                    // --
		break;




/** Bernard **/
//roomobj-45-246.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[90] = 5;                                                         // Kid Selected = Bernard
    /*[0015]*/ print(255,"Bernard - president of the physics club%/%and winner of the college's Geek Award.");
    /*[005D]*/ startScript(109);                                                    // Intro: Kid Selection: Update Var States
    /*[005F]*/ //stopObjectCode();                                                    // --
		break;




/** Wy **/
//roomobj-45-247.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[90] = 6;                                                         // Kid Selected = Wy
    /*[0015]*/ print(255,"Wy - wants to be a famous novelist%/%and is waiting for a big break.");
    /*[0052]*/ startScript(109);                                                    // Intro: Kid Selection: Update Var States
    /*[0054]*/ //stopObjectCode();                                                    // --
		break;




/** Jeff **/
//roomobj-45-248.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[90] = 7;                                                         // Kid Selected = Jeff
    /*[0015]*/ print(255,"Jeff - usually hangs out on the beach,/responds to the name, Surfer Dude.");
    /*[0055]*/ startScript(109);                                                    // Intro: Kid Selection: Update Var States
    /*[0057]*/ //stopObjectCode();                                                    // --
		break;




/** Dave **/
//roomobj-45-387.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(54);                                                      // sound Keypad Buttons
    /*[0014]*/ print(255,"Dave - Sandy's boyfri./Organizer of the rescue effort.");
    /*[0049]*/ //stopObjectCode();                                                    // --
		break;




/** Start **/
//roomobj-45-395.dmp

		case VER_WhatIs:
    /*[0012]*/ startSound(54);                                                      // sound Keypad Buttons
    /*[0014]*/ if (Var[92]*/ < 3) {                                                   // if Kids Slected < 3
    /*[0019]*/   print(255,"  Please select two kids besides Dave.");               //
    /*[003C]*/ } else {                                                             // -
    /*[003F]*/   Var[91] = 1;                                                       // Kid Select: Game can Start = yes
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;




/**
 * Room 47: Mansion At Distance (Lights On)
 */


/** <No Name> **/
//roomobj-47-13.dmp



/** <No Name> **/
//roomobj-47-14.dmp



/** <No Name> **/
//roomobj-47-15.dmp



/** <No Name> **/
//roomobj-47-16.dmp



/**
 * Room 50: Load / Save Screen
 */


/** Load Game **/
//roomobj-50-442.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[50] = 2;                                                         // SaveLoad: Button Pressed = Load Game
    /*[0015]*/ startSound(19);                                                      // Beep
    /*[0017]*/ //stopObjectCode();                                                    // --
		break;




/** Save Game **/
//roomobj-50-443.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[50] = 1;                                                         // SaveLoad: Button Pressed = Save Game
    /*[0015]*/ startSound(19);                                                      // Beep
    /*[0017]*/ //stopObjectCode();                                                    // --
		break;




/** Continue Playing **/
//roomobj-50-444.dmp

		case VER_WhatIs:
    /*[0012]*/ Var[50] = 3;                                                         // SaveLoad: Button Pressed = Continue Playing
    /*[0015]*/ startSound(19);                                                      // Beep
    /*[0017]*/ //stopObjectCode();                                                    // --
		break;




/**
 * Room 51: Lab: Meteor
 */


/** Switch **/
//roomobj-51-143.dmp

TurnOff.		case Push:Pull.		    case VER_Use:
    /*[001E]*/ if (!getState08(activeObject)) {                                     // if not switched
    /*[0021]*/   setState08(activeObject);                                                      //  Switch
    /*[0022]*/   stopScript(120);                                                   //  stop Dr Fred: Entered Lab
    /*[0024]*/   stopSound(59);
    /*[0026]*/   startSound(61);                                                    //  start Print "It must require a special key"
    /*[0028]*/   startScript(121);                                                  //  start Dr Fred: Free of machines control
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;




/** Door **/
//roomobj-51-144.dmp

		    case VER_Open:
    /*[001A]*/ startScript(116);                                                    // Open Door
    /*[001C]*/ setState08(26);                                                      // Hide Cement Slab
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(117);                                                    // Close Door
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0022]*/ if (getState08(activeObject)) {                                      // If Door open
    /*[0025]*/   if (Var[136] == 1) {                                               //  if Garage Destroyed
    /*[002A]*/     loadRoomWithEgo(75,52);                                          //   Enter 'Garage Destroyed'
    /*[002D]*/   } else {                                                           // -
    /*[0030]*/     setOwnerOf(120,15);                                              //   Medical Diagram owned by Meteor Police ??
    /*[0033]*/     loadRoomWithEgo(120,16);                                         //   Enter 'Garage'
    /*[0036]*/   }
    /*[0036]*/ }
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;




/** Door **/
//roomobj-51-251.dmp

		    case VER_Open:
    /*[001A]*/ startScript(116);                                                    // Open Door
    /*[001C]*/ setState08(237);                                                     // Open Door (Lab: Zom-b-Matic)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(117);                                                    // Close Door
    /*[0021]*/ clearState08(237);                                                   // Close Door (Lab: Zom-b-Matic)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door open
    /*[0027]*/   loadRoomWithEgo(237,30);                                           //  Enter Lab: Zom-b-Matic
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --





/** Meteor **/
//roomobj-51-252.dmp

		    case VER_PickUp:
    /*[001A]*/ if (Var[89] == 2) {                                                  // Meteor Loose?
    /*[001F]*/   pickupObject(0);                                                   // Pick object
    /*[0021]*/   clearState08(activeObject);
    /*[0022]*/   setState02();
    /*[0023]*/   Var[18] = 1;                                                       // Meteor Location = Kids Hands
    /*[0026]*/   startScript(129);                                                  // start Radiation Suit: Enable Speaking Flag
    /*[0028]*/   putActorInRoom(16,0);                                              // Meteor Leaves
    /*[002B]*/   putActor(16,0,0);
    /*[002F]*/   stopScript(123);                                                   // stop Meteor: Fire Radiation
    /*[0031]*/   putActorInRoom(20,0);                                              // Meteor Radiation Leaves
    /*[0034]*/   putActor(20,0,0);
    /*[0038]*/ } else {                                                             // -
    /*[003B]*/   printEgo("I can't get it loose!");
    /*[004E]*/ }
    /*[004E]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Use:
    /*[004F]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0053]*/ //stopObjectCode();                                                    // --
		break;





/** Purple Slime **/
//roomobj-51-353.dmp

		    case VER_WhatIs:
    /*[001E]*/ printEgo("I'm not going to touch that slime!");                      // What is
    /*[003C]*/ //stopObjectCode();                                                    // --
		break;




/**
 * Room 52: Garage Destroyed
 */

 /** Gate **/
//roomobj-52-75.dmp

		    case VER_Open:
		    case VER_Pull:
    /*[001E]*/ if (!getState04(activeObject)) {                                     // If unlocked
    /*[0021]*/   startScript(116);                                                  //  start Verb: Generic: Open Door
    /*[0023]*/   setState08(105);                                                   //  Open Gate (Pool Area)
    /*[0025]*/ } else {                                                             // -
    /*[0028]*/   printEgo("It's locked");
    /*[0034]*/ }
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
		    case VER_Push:
    /*[0035]*/ startScript(117);                                                    // start Verb: Generic: Close Door
    /*[0037]*/ clearState08(105);                                                   // Close Gate (Pool Area)
    /*[0039]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[003A]*/ if (getState08(activeObject)) {                                      // If gate open
    /*[003D]*/   loadRoomWithEgo(105,6);                                            //  Enter Pool Area
    /*[0040]*/ }
    /*[0040]*/ //stopObjectCode();                                                    // --
		break;


