/**
 * Maniac Mansion: Retail
 *
 * Room Object Scripts
 */
#include "zxscumm.h"
#include "MM.h"

int VAR_RESULT;
int VAR_ACTIVE_ACTOR;  // actor resultado de la frase.
int VAR_ROOM;  // habitacion actual
 
void objectScripts (int action, int activeObject, int activeObject2){
   switch (activeObject){
/**
 * Room 1: Front of Mansion
 */
/** Stamps **/
//roomobj-1-132.dmp
      case 132:
         switch (action){
            case VER_Pull:
		    case VER_PickUp:                                     

	/*[001C]*/ pickupObject(0);                                                     // Pick object
    /*[001E]*/ printEgo("Hmm, they're uncanceled.");
    /*[0036]*/ Var[81] = 1;                                                         // Stamps Taken = Taken
    /*[0039]*/ //stopObjectCode();                                                    // --
			   break;

            case VER_Use:
    /*[003A]*/ //if (activeObject2 == 234) {                                          // if Use with Sealed Envelope (room7)
    /*[003E]*/ //} else {                                                             // -
    /*[0041]*/ //unless (activeObject2 == 201) goto 0067;                             //  or Use with Sealed Envelope (room9)
    /*[0045]*/ //}
               if ((activeObject2 == 234) || (activeObject2 == 201)){
    /*[0045]*/    if (Var[62] == 1) {                                                  // if Stamp Stickyness == Sticky
    /*[004A]*/       Var[64] = 1;                                                       //  Envelop Stamped = Yes
    /*[004D]*/       printEgo("They stick!");
    /*[0059]*/       startScript(79);                                                   //  start Envelope: Name
    /*[005B]*/       setOwnerOf(0,0);                                                   //  Remove Stamps
    /*[005E]*/     } else {                                                             //  Use with other objects
    /*[0067]*/       printEgo("They won't stick.");
    /*[0078]*/     }
               }
    /*[0078]*/ //stopObjectCode();                                                    // --
		       break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Mailbox **/
//roomobj-1-17.dmp
      case 17:
		 switch (action){
		    case VER_Open:
    /*[001D]*/ setState08(activeObject);                                                        // Open mailbox
    /*[001E]*/ //stopObjectCode();                                                    // --
               break;
            case VER_Close:
    /*[001F]*/ clearState08(activeObject);                                                      // Close mailbox
    /*[0020]*/ //stopObjectCode();                                                    // --
               break;
            case VER_Use:
    /*[0021]*/ doSentence(11,255,263);                                              // Use _cmdObject2 with Mailbox
    /*[0025]*/ //stopObjectCode();                                                    // --
               break; 
            }       // end switch_action 17
            break;  // end obj 17 

/** Mailbox Flag **/
//roomobj-1-18.dmp
      case 18:
		 switch (action){
		    case VER_Open:
    /*[001E]*/ doSentence(1,254,255);                                               // Open _cmdObject with _cmdObject2
    /*[0022]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Close:
    /*[0023]*/ doSentence(2,254,255);                                               // Close _cmdObject with _cmdObject2
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Pull:
    /*[0028]*/ setState08(activeObject);                                                        // Raise Flag
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Push:
    /*[002A]*/ clearState08(activeObject);                                                      // Lower Flag
    /*[002B]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Use:
    /*[002C]*/ if (getState08(activeObject)) {                                      // If Flag Up
    /*[002F]*/   clearState08(activeObject);                                                    //  Lower Flag
    /*[0030]*/ } else {                                                             // -
    /*[0033]*/   setState08(activeObject);                                                      //  Raise Flag
    /*[0034]*/ }
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Bushes **/
//roomobj-1-19.dmp
      case 19:
		 switch (action){
		    case VER_Open:
		    case VER_Pull:
		    case VER_PickUp:                                     

    /*[001C]*/ setState08(activeObject);                                                        // Remove Bushes
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Grating **/
//roomobj-1-20.dmp
      case 20:
		 switch (action){
		    case VER_Open:
    /*[0027]*/ //if (getState04(activeObject)) {                                      // Has grate been fixed?
    /*[002A]*/ //  VAR_RESULT = getActorBitVar(VAR_EGO,1);  //FIXME: perhaps VAR_ACTIVE_ACTOR?? // No. Check Kid
    /*[002E]*/ //  if (VAR_RESULT == 1) {                                             // Kid has kActorMiscFlagStrong?
    /*[0033]*/ //    printEgo("Easy!");
    /*[003A]*/ //    goto 0062;
    /*[003D]*/ //  } else {                                                           // -
    /*[0040]*/ //    printEgo("I can't budge it. It's rusted shut.");
    /*[005F]*/ //  }
    /*[005F]*/ //} else {                                                             // -
    /*[0062]*/ //  setState08(activeObject);                                                      // Grate is open
    /*[0063]*/ //  setState08(213);                                                   // Grate is open
    /*[0065]*/ //  startSound(8);                                                     // Sound Door Open
    /*[0067]*/ //}
    /*[0067]*/ //stopObjectCode();                                                    // --

              VAR_RESULT = getActorBitVar(VAR_EGO,1);  //FIXME: perhaps VAR_ACTIVE_ACTOR??  // actor strong 
              if (VAR_RESULT == 1)  printEgo("Easy!");
              if ( (VAR_RESULT == 1) || getState04(activeObject) ) {                       // actor strong or grate fixed                      
                 setState08(activeObject);                                          // Grate is open
                 setState08(213);                                                   // Grate is open
                 startSound(8);                                                     // Sound Door Open
	          } else {
                 printEgo("I can't budge it. It's rusted shut.");
              }
		      break;

		    case VER_Close:
    /*[0068]*/ clearState08(activeObject);                                                      // Grate is closed
    /*[0069]*/ clearState08(213);                                                   // Grate is closed
    /*[006B]*/ //stopObjectCode();                                                    // --
		break;

			case VER_Push:
		    case VER_Pull:
    /*[006C]*/ if (!getState08(activeObject)) {                                     // Push
    /*[006F]*/   doSentence(1,20,0);                                                //  Open Grating
    /*[0073]*/ } else {                                                             // -
    /*[0076]*/   doSentence(2,20,0);                                                //  Close Grating
    /*[007A]*/ }
    /*[007A]*/ //stopObjectCode();                                                    // --
		break;

			case VER_Fix:
			case VER_Unlock:
		    case VER_Use:
    /*[007B]*/ if (activeObject2 == 119) {                                          // Use Tools with Grate
    /*[007F]*/   clearState04(activeObject);                                                    // Grate can be opened by anyone
    /*[0080]*/   doSentence(1,20,0);
    /*[0084]*/ }
    /*[0084]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_WalkTo:
    /*[0085]*/ if (getState08(activeObject)) {                                      // Walk To
    /*[0088]*/   loadRoomWithEgo(213,29);                                           // Enter room Underhouse
    /*[008B]*/ }
    /*[008B]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Door mat **/
//roomobj-1-21.dmp
      case 21:
		 switch (action){
			case VER_Pull:
			case VER_PickUp:                                     

    /*[001E]*/ if (getState08(activeObject)) {                                      // Pull/Pickup
    /*[0021]*/   printEgo("I'll leave it here.");
    /*[0033]*/ } else {                                                             // -
    /*[0036]*/   setState08(activeObject);                                                      //  Move Doormat
    /*[0037]*/ }
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Push:
    /*[0038]*/ clearState08(activeObject);                                                      // Move doormat back
    /*[0039]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Front Door Key **/
//roomobj-1-22.dmp
      case 22:
		 switch (action){
			case VER_PickUp:                                     

    /*[0017]*/ pickupObject(0);                                                     // Pickup Key
    /*[0019]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Use:
    /*[001A]*/ if (activeObject2 == 28) {                                           // Use key with Front Door
    /*[001E]*/   clearState04(28);                                                  //  Unlock Front Door
    /*[0020]*/   doSentence(1,28,0);                                                //  Open Front Door
    /*[0024]*/ } else {                                                             // -
    /*[0027]*/   printEgo("It doesn't work.");
    /*[0037]*/ }
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Undeveloped Film **/
//roomobj-1-23.dmp
      case 23:
		 switch (action){
		    case VER_PickUp:                                     

    /*[002A]*/ pickupObject(0);                                                     // Pickup Undeveloped Film
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Open:
    /*[002D]*/ VAR_RESULT = isScriptRunning(71);
    /*[0030]*/ if (VAR_RESULT == 0) {                                               // is script Film: Expose not running
    /*[0035]*/   startScript(71);                                                   //  start Film: Expose
    /*[0037]*/ }
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Use:
    /*[0038]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[003C]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Read:
    /*[003D]*/ if (Var[11] < 2) {                                                   // if Film Exposed < Ruined Prints
    /*[0042]*/   printEgo("Kodak.");
    /*[004A]*/ } else {                                                             // -
    /*[004D]*/   printEgo("Looks like photographs of Ed's plans.");
    /*[006F]*/ }
    /*[006F]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Give:
    /*[0070]*/ if (VAR_ACTIVE_ACTOR < 8) {                                          // Give to Kid
    /*[0075]*/   setOwnerOf(0,VAR_ACTIVE_ACTOR);
    /*[0078]*/ }
    /*[0078]*/ if (VAR_ACTIVE_ACTOR == 11) {                                        // Give to Weird Ed?
    /*[007D]*/   if (Var[11] < 2) {                                                 //  if Film Exposed < Ruined Prints
    /*[0082]*/     print(11,"No! No! You have to develop it for me!");
    /*[00A3]*/   } else {                                                           // -
    /*[00A6]*/     startScript(88);                                                 //  start Weird Ed: Accepts Prints
    /*[00A8]*/   }
    /*[00A8]*/ }
    /*[00A8]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Package **/
//roomobj-1-24.dmp
      case 24:
		 switch (action){
		    case VER_PickUp:                                     

    /*[0021]*/ pickupObject(0);                                                     // Pickup Package
    /*[0023]*/ if (Var[81] == 0) {                                                  // if Stamps Taken == No
    /*[0028]*/   pickupObject(132);                                                 //  Pickup Stamps
    /*[002A]*/   setOwnerOf(132,14);                                                //  Set owner of stamps to Green Tentacle
    /*[002D]*/ }
    /*[002D]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Give:
    /*[002E]*/ if (VAR_ACTIVE_ACTOR < 8) {                                          // Give
    /*[0033]*/   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  To Kid
    /*[0036]*/ }
    /*[0036]*/ if (VAR_ACTIVE_ACTOR == 11) {                                        //  To Weird Ed
    /*[003B]*/   startScript(87);                                                   //   start Weird Ed: Accept Commando Package
    /*[003D]*/ }
    /*[003D]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Read:
    /*[003E]*/ printEgo("To: Weird Ed");                                            // Read
    /*[004A]*/ //stopObjectCode();                                                    // --
		break;

			case VER_Open:
		    case VER_Pull:
    /*[004B]*/ if (Var[81] == 0) {                                                  // if Stamps Taken == No
    /*[0050]*/   if (getState08(activeObject)) {                                    //  if Package available
    /*[0053]*/     setOwnerOf(132,VAR_EGO);                                         //   Kid owns Stamps
    /*[0056]*/   } else {                                                           // -
    /*[0059]*/     pickupObject(132);                                               // Pickup Package
    /*[005B]*/   }
    /*[005B]*/   printEgo("Some uncanceled stamps came off!");
    /*[0079]*/   Var[81] = 1;                                                       // Stamps Taken = Yes
    /*[007C]*/ } else {                                                             // -
    /*[007F]*/   printEgo("That would be illegal.");
    /*[0094]*/ }
    /*[0094]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Exit to Room 44 **/
//roomobj-1-240.dmp
      case 240:
		 switch (action){
		    case VER_WalkTo:
    /*[0012]*/ loadRoomWithEgo(241,44);                                             // Enter room 'Welcome to Mansion'
    /*[0015]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Envelope **/
//roomobj-1-25.dmp
      case 25:
		 switch (action){
		    case VER_Read:
    /*[001C]*/ if (Var[85] == 0) {                                                  // Envelope: Addressed == No
    /*[0021]*/   printEgo("It's a blank envelope.");
    /*[0036]*/ } else {                                                             // -
    /*[0039]*/   printEgo("It's addressed to: 222 Skyscraper Way.");
    /*[005C]*/ }
    /*[005C]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_PickUp:                                     

    /*[005D]*/ setState02(25);                                                      // Hide Envelope
    /*[005F]*/ clearState08(25);                                                    // Hide Envelope
    /*[0061]*/ setOwnerOf(201,VAR_EGO);                                             // Sealed Envelope owned by kid
    /*[0064]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Mailbox **/
//roomobj-1-263.dmp
      case 263:
		 switch (action){
		    case VER_Open:
    /*[001F]*/ setState08(17);                                                      // Open
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Close:
    /*[0022]*/ clearState08(17);
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Use:
    /*[0025]*/ if (activeObject2 == 201) {                                          // Use Mailbox with Sealed Envelope
    /*[0029]*/   if (getState08(17)) {                                              // Is mailbox open
    /*[002D]*/     if (Var[85] == 0) {                                              // If Envelope: Addressed == No
    /*[0032]*/       printEgo("There is no address on it.");
    /*[0049]*/     } else if (Var[64] == 0) {                                       // or Envelope Stamped == No
    /*[0051]*/       printEgo("There's no stamp on it.");
    /*[0066]*/     } else {
    /*[0069]*/       setOwnerOf(201,14);                                            // Otherwise, Green Tentacle owners envelope
    /*[006C]*/       clearState02(25);                                              // Envelope Unavailable
    /*[006E]*/       setState08(25);                                                // Envelope Unavailable
    /*[0070]*/     }
    /*[0070]*/   }
    /*[0070]*/ }
    /*[0070]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Read:
    /*[0071]*/ printEgo("Solicitors will be eaten.");
    /*[0089]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 263
            break;  // end obj 263 

/** Bushes **/
//roomobj-1-264.dmp

/** Contract **/
//roomobj-1-27.dmp
      case 27:
		 switch (action){

		    case VER_PickUp:                                     

    /*[001E]*/ pickupObject(0);
    /*[0020]*/ clearState08(activeObject);
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Read:
    /*[0022]*/ startScript(127);                                                    // start Contract: Read State
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Give:
    /*[0025]*/ startScript(105);                                                    // start Contract: Given to actor
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Front Door **/
//roomobj-1-28.dmp
      case 28:
		 switch (action){
		    case VER_Open:
    /*[0026]*/ if (!getState04(activeObject)) {                                     // Is Door unlocked
    /*[0029]*/   startScript(4);                                                    //  start Door: Open
    /*[002B]*/   setState08(34);                                                    //  Open Front Door (from room 10)
    /*[002D]*/ } else {                                                             // else
    /*[0030]*/   startScript(64);                                                   //  start Print "The door is locked"
    /*[0032]*/ }
    /*[0032]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Close:
    /*[0033]*/ startScript(5);                                                      // start Door: Close
    /*[0035]*/ clearState08(34);                                                    // close Front Door (from room 10)
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;

			case VER_Unlock:
			case VER_Use:
    /*[0038]*/ if (activeObject2 == 22) {                                           // if using Key
    /*[003C]*/   clearState04(activeObject);                                                    //  Unlock Front door
    /*[003D]*/   doSentence(1,28,0);                                                //  Open Front Door
    /*[0041]*/ } else {                                                             // -
    /*[0044]*/   startScript(66);                                                   // start Print "I can't unlock the door with this."
    /*[0046]*/ }
    /*[0046]*/ //stopObjectCode();                                                    // --
		break;

			case VER_Lock:
    /*[0047]*/ setState04(activeObject);                                                        //  Lock
    /*[0048]*/ doSentence(2,28,0);                                                  //  Close Front Door
    /*[004C]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_WalkTo:
    /*[004D]*/ if (getState08(activeObject)) {                                      // if front-door is open
    /*[0050]*/   if (Var[122] == 0) {                                               //  if Dr. Fred / Sandy Cutscene #1 Triggered == 0
    /*[0055]*/     Var[122] = 1;                                                    //   Dr. Fred / Sandy Cutscene #1 Triggered = 1
    /*[0058]*/     startScript(143);                                                //   start Cutscene: Dr. Fred / Sandy #1
    /*[005A]*/     putActorInRoom(10,7);                                            //   Nurse Edna enters Kitchen
    /*[005D]*/     putActor(10,62,56);                                              //   Put Nurse Edna at Refridgerator
    /*[0061]*/     animateActor(10,7,1);                                            //   Nurse Edna faces away
    /*[0065]*/     setState08(56);                                                  //   Open Refridgerator
    /*[0067]*/     startScript(147);                                                //   start Nurse Edna: In Kitchen Monitor
    /*[0069]*/   }
    /*[0069]*/   loadRoomWithEgo(34,10);                                            //  Kid enters Room 10 at Front Door
    /*[006C]*/ }
    /*[006C]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Tombstone **/
//roomobj-1-29.dmp
      case 29:
		 switch (action){
		    case VER_Read:
    /*[001B]*/ printEgo("And good riddance!");
    /*[002D]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Tombstone **/
//roomobj-1-30.dmp
      case 30:
		 switch (action){
		    case VER_Read:
    /*[001B]*/ printEgo("Another one bites the dust!");
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 132
            break;  // end obj 132 

/** Tombstone **/
//roomobj-1-31.dmp

/** Doorbell **/
//roomobj-1-386.dmp
      case 386:
		 switch (action){
			case VER_Push:
		    case VER_Use:
    /*[001E]*/ startSound(39);
    /*[0020]*/ if (Var[73] == 0) {                                                  // Door Bell Triggers Ed == Yes
    /*[0025]*/   VAR_RESULT = isScriptRunning(82);                                  // is Weird Ed: Leave Room running
    /*[0028]*/   if (VAR_RESULT == 0) {
    /*[002D]*/     VAR_RESULT = getActorRoom(ACT_Weird_Ed);
    /*[0030]*/     if (VAR_RESULT == 26) {
    /*[0035]*/       Var[127] = 1;                                                  // Weird Ed Trigger = DoorBell
    /*[0038]*/       startScript(82);                                               // start Weird Ed: Leave Room running
    /*[003A]*/     }
    /*[003A]*/   } else {                                                           // -
    /*[003D]*/     startScript(92);                                                 // start Weird Ed: Respond to Door Bell
    /*[003F]*/   }
    /*[003F]*/ }
    /*[003F]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Read:
    /*[0040]*/ printEgo("This is the home of Dr. Fred,/Nurse Edna, Weird Ed, Dead Cousin Ted,/Green Tentacle and Purple Tentacle.");
    /*[009A]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386


/**
 * Room 2: Bottom of Pool
 */

/** Glowing Key **/
//roomobj-2-108.dmp
      case 108:
		 switch (action){

		    case VER_PickUp:
    /*[001F]*/ pickupObject(0);                                                     // Pickup Key
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0022]*/ doSentence(11,255,254);                                              // Use Key in _cmdOjbect2
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386

/** Radio **/
//roomobj-2-109.dmp
      case 109:
		 switch (action){

		    case VER_PickUp:
    /*[001D]*/ pickupObject(0);                                                     // Pickup Radio
    /*[001F]*/ pickupObject(134);                                                   // Pickup Batteries
    /*[0021]*/ setOwnerOf(134,14);                                                  // Green Tentacle owns Batteries
    /*[0024]*/ setState08(107);                                                     // Radio in Pool Area hidden
    /*[0026]*/ setState02(107);                                                     // Radio in Pool Area hidden
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Open:
    /*[0029]*/ if (!getState08(109)) {                                              // Radio Not Taken?
    /*[002D]*/   doSentence(1,109,0);
    /*[0031]*/   doSentence(14,109,0);
    /*[0035]*/ } else {                                                             // -
    /*[0038]*/   VAR_RESULT = getObjectOwner(134);
    /*[003B]*/   if (VAR_RESULT == 14) {                                            // If green tentacle still owns batteries
    /*[0040]*/     printEgo("Batteries!");
    /*[004C]*/     setOwnerOf(134,VAR_EGO);                                         // kid owns batteries
    /*[004F]*/     stopSound(20);
    /*[0051]*/   }
    /*[0051]*/ }
    /*[0051]*/ //stopObjectCode();                                                    // --
		break;

		case VER_TurnOn:
    /*[0052]*/ VAR_RESULT = getObjectOwner(134);
    /*[0055]*/ if (VAR_RESULT == 14) {                                              // if green tentacle still owns batties
    /*[005A]*/   startSound(20);                                                    //  turn on radio
    /*[005C]*/ }
    /*[005C]*/ //stopObjectCode();                                                    // --
		break;

		case VER_TurnOff:
    /*[005D]*/ stopSound(20);                                                       // turn off radio
    /*[005F]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386

/** Batteries **/
//roomobj-2-134.dmp
      case 134:
		 switch (action){
		    case VER_Use:
    /*[001B]*/ if (activeObject2 == 51) {                                           // Flashlight?
    /*[001F]*/   Var[31] = 2;                                                       // Flashlight has Battery = Full
    /*[0022]*/   setOwnerOf(134,0);                                                 // Remove Batteries
    /*[0025]*/ }
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386

/** Ladder **/
//roomobj-2-138.dmp
      case 138:
		 switch (action){
		    case VER_WalkTo:
    /*[0018]*/ loadRoomWithEgo(139,6);                                              // Enter Pool Area at Ladder
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386

/** Red Button **/
//roomobj-2-275.dmp
      case 275:
		 switch (action){
		case VER_Push:
	    case VER_Use:
    /*[0020]*/ startSound(27);                                                      // Beep
    /*[0022]*/ startScript(57);                                                     // start Cutscene: Game Over
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_Read:
    /*[0025]*/ printEgo("DO NOT PRESS UNDER ANY CIRCUMSTANCES!");                   // Read
    /*[0047]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386

/** Pool Chair **/
//roomobj-2-326.dmp
      case 326:
		 switch (action){
		    case VER_PickUp:
    /*[001C]*/ startScript(65);                                                     // start Print "Its too Heavy"
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386

/** Drain **/
//roomobj-2-327.dmp

/** Exposed cooling rods **/
//roomobj-2-328.dmp
      case 328:
		 switch (action){
		    case VER_WalkTo:
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		case VER_WhatIs:
    /*[0029]*/ printEgo("I'm not going to touch cooling rods!");                    // Walk To
    /*[0049]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386

/** Radioactive **/
//roomobj-2-329.dmp
      case 329:
		 switch (action){
		case VER_WhatIs:
    /*[0023]*/ printEgo("I'm not going to touch that goo!");                        // What is
    /*[003F]*/ //stopObjectCode();                                                    // --
		break;
            }       // end switch_action 386
            break;  // end obj 386

/**
 * Room 3: Downstairs Lounge Room
 */

/** Cassette Player **/
//roomobj-3-207.dmp
      case 207:
		 switch (action){
		case VER_TurnOn:
    /*[0025]*/ if (!getState08(47)) {                                               // if Cassette Tape Not In Player
    /*[0029]*/   if (!getState08(124)) {                                            //  if Circuit Breaker == Power On
    /*[002D]*/     setState08(207);                                                 //   set Cassette Player has tape
    /*[002F]*/     startScript(104);                                                //   start Tape Player: Play Tape
    /*[0031]*/     if (Var[13] == 25) {                                             //   Tape Contents == Tentacle Mating Call
    /*[0036]*/       startScript(15);                                               //    start Cassette: Play, Break Windows/Free Key
    /*[0038]*/     }
    /*[0038]*/   }
    /*[0038]*/ } else {                                                             // -
    /*[003B]*/   printEgo("There's no tape in the player.");
    /*[0056]*/ }
    /*[0056]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0057]*/ if (getState08(207)) {                                               //   Cassette Player has tape?
    /*[005B]*/   clearState08(207);                                                 //    Remove Tape
    /*[005D]*/   stopSound(25);
    /*[005F]*/   stopSound(44);
    /*[0061]*/   stopMusic();                                                       //    stop music
    /*[0062]*/   stopScript(15);                                                    //    stop Cassette: Play, Break Windows/Free Key
    /*[0064]*/ }
    /*[0064]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0065]*/ if (activeObject2 == 156) {                                          // Use Cassette Tape with Cassette Player
    /*[0069]*/   setOwnerOf(156,14);                                                // Green Tentacle owns Tape
    /*[006C]*/   clearState08(47);                                                  // Tape Hidden
    /*[006E]*/   clearState02(47);                                                  // Tape Hidden
    /*[0070]*/ }
    /*[0070]*/ //stopObjectCode();                                                    // --
		break;
       }       // end switch_action 207
       break;  // end obj 207

/** Couch **/
//roomobj-3-273.dmp
      case 273:
		 switch (action){

		case VER_Push:
		case VER_Pull:
    /*[0019]*/ printEgo("I can't budge it.");                                       // Push Couch
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/**Door **/
//roomobj-3-38.dmp
      case 38:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(37);                                                      // Open Door (in room 10)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(37);                                                    // Close Door (in room 10)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   loadRoomWithEgo(37,10);                                            //  Enter Room 10 at Door
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/** Old Fashioned Radio **/
//roomobj-3-39.dmp
      case 39:
		 switch (action){

		    case VER_Open:
    /*[002D]*/ setState08(activeObject);                                                        // Open Radio
    /*[002E]*/ Var[29] = 0;
    /*[0031]*/ stopSound(20);
    /*[0033]*/ stopSound(29);
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0036]*/ clearState08(activeObject);                                                      // Close Radio
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Fix:
    /*[0038]*/ if (activeObject2 == 40) {                                           // Fix Radio with Radio Tube
    /*[003C]*/   clearState08(40);                                                  //  Show radio tube
    /*[003E]*/   clearState02(40);                                                  //  Show radio tube
    /*[0040]*/   setOwnerOf(40,0);                                                  //  Radio tube has no owner
    /*[0043]*/ } else if (getState08(40)) {
    /*[004A]*/   printEgo("That doesn't seem to work.");
    /*[0062]*/ }
    /*[0062]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[0063]*/ clearState08(activeObject);                                                      // Close Radio
    /*[0064]*/ if (!getState08(40)) {                                               // Radio Tube
    /*[0068]*/   if (!getState08(124)) {                                            // Power is on?
    /*[006C]*/     if (Var[29] == 0) {
    /*[0071]*/       Var[29] = 1;                                                   // Radio On
    /*[0074]*/       startSound(20);
    /*[0076]*/     }
    /*[0076]*/   }
    /*[0076]*/ } else {                                                             // -
    /*[0079]*/   printEgo("I can't get it to work.");
    /*[008D]*/ }
    /*[008D]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[008E]*/ clearState08(activeObject);
    /*[008F]*/ if (Var[29] == 0) {                                                  // Radio == Off?
    /*[0094]*/   printEgo("It wasn't on.");
    /*[00A1]*/ } else {                                                             // -
    /*[00A4]*/   Var[29] = 0;                                                       // Radio = Off
    /*[00A7]*/   stopSound(20);
    /*[00A9]*/   stopSound(29);
    /*[00AB]*/ }
    /*[00AB]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[00AC]*/ clearState08(activeObject);
    /*[00AD]*/ if (Var[29] == 0) {                                                  // Radio == off
    /*[00B2]*/   printEgo("It's not turned on.");
    /*[00C4]*/ } else {                                                             // -
    /*[00C7]*/   startSound(29);
    /*[00C9]*/ }
    /*[00C9]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Radio Tube **/
//roomobj-3-40.dmp
      case 40:
		 switch (action){

		    case VER_PickUp:
    /*[001E]*/ if (VAR_EGO == 5) {                                                  // If kid == Bernard
    /*[0023]*/   pickupObject(0);                                                   //  Pickup
    /*[0025]*/ } else {                                                             // -
    /*[0028]*/   printEgo("I don't know how this stuff works!");
    /*[0046]*/ }
    /*[0046]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0047]*/ doSentence(6,255,254);                                               // Fix _cmdObject with _cmdObject2
    /*[004B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/** Glass Chandelier **/
//roomobj-3-41.dmp



/** Broken Chandelier **/
//roomobj-3-42.dmp



/** Old Rusty Key **/
//roomobj-3-43.dmp
      case 43:
		 switch (action){

		    case VER_PickUp:
    /*[0021]*/ pickupObject(0);                                                     // Pickup
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0024]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/** Cabinet Door **/
//roomobj-3-44.dmp
      case 44:
		 switch (action){

		    case VER_Open:
    /*[0020]*/ startScript(4);                                                      // start Door: Open
    /*[0022]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0023]*/ startScript(5);                                                      // start Door: Close
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Key **/
//roomobj-3-445.dmp
      case 445:
		 switch (action){

			case VER_Pull:
		    case VER_PickUp:
    /*[0017]*/ printEgo("I can't reach it.");
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Window **/
//roomobj-3-45.dmp



/** Window **/
//roomobj-3-46.dmp



/** Cassette Tape **/
//roomobj-3-47.dmp
      case 47:
		 switch (action){

		    case VER_PickUp:
    /*[0023]*/ if (getState08(207)) {                                               // Cassette Player is playing?
    /*[0027]*/   printEgo("It's still playing!");
    /*[003A]*/ } else {                                                             // -
    /*[003D]*/   setOwnerOf(156,VAR_EGO);                                           // Kid owns Tape
    /*[0040]*/   setState08(activeObject);                                                      // Tape Taken
    /*[0041]*/   setState02(activeObject);                                                      // Tape Taken
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();
			break;

		case VER_TurnOn:
    /*[0043]*/ if (!getState08(activeObject)) {                                     // If Casette Player Off
    /*[0046]*/   doSentence(4,207,0);                                               //  Turn On Cassette Player
    /*[004A]*/ }
    /*[004A]*/ //stopObjectCode();
			break;

		case VER_TurnOff:
    /*[004B]*/ if (!getState08(activeObject)) {                                     // If Casette Player Off
    /*[004E]*/   doSentence(5,207,0);                                               //  Turn Off Cassette Player
    /*[0052]*/ }
    /*[0052]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Door **/
//roomobj-3-93.dmp
      case 93:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(102);                                                     // Door Open (other side)
    /*[001E]*/ //stopObjectCode();
			break;

		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(102);                                                   // Door Close (other side)
    /*[0023]*/ //stopObjectCode();
			break;

		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // Door is open?
    /*[0027]*/   loadRoomWithEgo(102,5);                                            //  Kid enters Library at Door
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386


/**
 * Room 4: Dungeon
 */

/** Door **/
//roomobj-4-126.dmp
      case 126:
		 switch (action){

		    case VER_Open:
    /*[0020]*/ if (!getState08(activeObject)) {                                     // Door Locked?
    /*[0023]*/   startScript(64);                                                   //  start Print "The door is locked"
    /*[0025]*/ }
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0026]*/ startScript(51);                                                     // start Dungeon: Close Entry Door
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


			case VER_Unlock:
	    	case VER_Use:
    /*[0029]*/ if (activeObject2 == 43) {                                           // Use Old Rusty Key with Door
    /*[002D]*/   startScript(4);                                                    // start Door: Open
    /*[002F]*/   setState08(122);                                                   // Open Door (Room8: Basement)
    /*[0031]*/ } else {                                                             // -
    /*[0034]*/   startScript(66);                                                   // start Print "I can't unlock the door with this."
    /*[0036]*/ }
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0037]*/ if (getState08(activeObject)) {                                      // Door Unlocked?
    /*[003A]*/   clearState08(126);                                                 //  Close Door
    /*[003C]*/   clearState08(122);                                                 //  Close Door (Room8: Basement)
    /*[003E]*/   loadRoomWithEgo(122,8);                                            //  Enter Basement at Door
    /*[0041]*/ }
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/** Outer Door **/
//roomobj-4-127.dmp
      case 127:
		 switch (action){

		    case VER_Open:
    /*[001E]*/ if (!getState04(activeObject)) {                                     // Paddlocks unLocked?
    /*[0021]*/   startScript(4);                                                    //  start Door: Open
    /*[0023]*/ } else {                                                             // -
    /*[0026]*/   startScript(64);                                                   //  start Print "The door is locked"
    /*[0028]*/ }
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0029]*/ if (getState08(activeObject)) {                                      // If door open
    /*[002C]*/   clearState08(activeObject);                                                    //  Close door
    /*[002D]*/   startSound(42);                                                    //  sound Steel Door
    /*[002F]*/ }
    /*[002F]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386


/** Top Padlock **/
//roomobj-4-128.dmp
      case 128:
		 switch (action){

			case VER_Unlock:		    
			case VER_Use:
    /*[0023]*/ if (activeObject2 == 108) {                                          // Use Glowing Key with Top Padlock
    /*[0027]*/   if (!getState08(activeObject)) {                                   //  Padlock locked?
    /*[002A]*/     setState08(activeObject);                                                    //   Unlock Padlock
    /*[002B]*/     startSound(12);                                                  //   sound Light Switch
    /*[002D]*/   }
    /*[002D]*/   if (getState08(129)) {                                             // Is Bottom Padlock unlocked
    /*[0031]*/     clearState04(127);                                               //  Yes, Unlock the Outer Door
    /*[0033]*/   }
    /*[0033]*/ } else {                                                             // -
    /*[0036]*/   startScript(66);                                                   //  start Print "I can't unlock the door with this."
    /*[0038]*/ }
    /*[0038]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Close:
 		case VER_Lock:
    /*[0039]*/ if (getState08(activeObject)) {                                      // Padlock Unlocked?
    /*[003C]*/   clearState08(activeObject);                                                    //   Lock Padlock
    /*[003D]*/   startSound(12);                                                    //   sound Light Switch
    /*[003F]*/ }
    /*[003F]*/ setState04(127);                                                     // Lock the Outer Door
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Bottom Padlock **/
//roomobj-4-129.dmp
      case 129:
		 switch (action){

			case VER_Unlock:
		    case VER_Use:
    /*[0026]*/ if (activeObject2 == 108) {                                          // Use Glowing Key with Top Padlock
    /*[002A]*/   if (!getState08(activeObject)) {                                   //  Padlock locked?
    /*[002D]*/     setState08(activeObject);                                                    //   Unlock Padlock
    /*[002E]*/     startSound(12);                                                  //   sound Light Switch
    /*[0030]*/   }
    /*[0030]*/   if (getState08(128)) {                                             // Is Top Padlock unlocked
    /*[0034]*/     clearState04(127);                                               //  Yes, Unlock the Outer Door
    /*[0036]*/   }
    /*[0036]*/ } else {                                                             // -
    /*[0039]*/   startScript(66);                                                   //  start Print "I can't unlock the door with this."
    /*[003B]*/ }
    /*[003B]*/ //stopObjectCode();                                                    // --
		break;


			case VER_Lock:
		    case VER_Close:
    /*[003C]*/ if (getState08(activeObject)) {                                      // Padlock Unlocked?
    /*[003F]*/   clearState08(activeObject);                                                    //   Lock Padlock
    /*[0040]*/   startSound(12);                                                    //   sound Light Switch
    /*[0042]*/ }
    /*[0042]*/ setState04(127);                                                     // Lock the Outer Door
    /*[0044]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Inner Door  **/
//roomobj-4-130.dmp
      case 130:
		 switch (action){

		case VER_Open:
		case VER_Unlock:
		case VER_Push:
		case VER_Pull:
	    case VER_Use:
    /*[002A]*/ startScript(40);                                                     // start Lab Entry Keypad Input
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Lock:
    /*[002D]*/ if (getState08(activeObject)) {                                      // If door is open
    /*[0030]*/   clearState08(activeObject);                                                    //  Close Door
    /*[0031]*/   setState04(activeObject);                                                      //  Door locked
    /*[0032]*/   clearState08(133);                                                 //  Close Door (Lab Entry)
    /*[0034]*/   startSound(42);                                                    //  sound Steel Door
    /*[0036]*/ }                                                                    // --
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0037]*/ if (getState08(activeObject)) {                                      // If door is open
    /*[003A]*/   putActorInRoom(14,0);                                              //  Green Tentacle Leaves
    /*[003D]*/   putActor(14,0,0);
    /*[0041]*/   putActorInRoom(9,30);                                              //  Dr. Fred Enters Lab: Zom-b-Matic
    /*[0044]*/   putActor(9,20,20);
    /*[0048]*/   if (Var[135] == 0) {                                               //  Purple chased out of lab == No
    /*[004D]*/     putActorInRoom(13,31);                                           //   Purple enters Lab: Entry
    /*[0050]*/     putActor(13,44,63);
    /*[0054]*/     startScript(112);                                                //   start Purple Tentacle: Check Actor X > 20; print "What are you doing here?"
    /*[0056]*/     loadScript(43);
    /*[0058]*/     lockScript(43);
    /*[005A]*/     loadSound(63);
    /*[005C]*/     lockSound(63);
    /*[005E]*/   }
    /*[005E]*/   cursorCommand( kModeNoNewKid ) ;                                    // Disable New Kid verb
    /*[0060]*/   startScript(7);                                                    // start Game: Meltdown Stop
    /*[0062]*/   stopScript(131);                                                   // stop Meteor Police: Timer until arrival
    /*[0064]*/   stopScript(138);                                                   // stop Cutscene: Dr. Fred Play Meteor Mess Trigger
    /*[0066]*/   stopScript(96);                                                    // stop Dr Fred: Play Meteor Mess
    /*[0068]*/   loadRoomWithEgo(133,31);                                           // Enter Lab: Entry
    /*[006B]*/ }
    /*[006B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/** Badge **/
//roomobj-4-193.dmp
      case 193:
		 switch (action){

		    case VER_PickUp:
    /*[001B]*/ pickupObject(0);                                                     // Pickup
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[001E]*/ printEgo("Meteor Police, badge number 714.");                        // Read
    /*[003C]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[003D]*/ if (VAR_ACTIVE_ACTOR == 13) {                                        // Give to Purple Tentacle?
    /*[0042]*/   startScript(154);                                                  // start Cutscene: Purple Tentacle reacts to police badge
    /*[0044]*/ }
    /*[0044]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/** Skeleton **/
//roomobj-4-340.dmp
      case 340:
		 switch (action){

		    case VER_WalkTo:
    /*[001C]*/ //stopObjectCode();                                                    // --
		break;


		case VER_WhatIs:
    /*[001D]*/ if (Var[101] == 0) {                                                 // What is, already spoke?
    /*[0022]*/   printEgo("I wonder if I know him.");
    /*[0036]*/   Var[101] = 1;                                                      //  Dungeon Skeleton 'Hovered Over' = Yes
    /*[0039]*/ }
    /*[0039]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Barred Window **/
//roomobj-4-341.dmp



/** Barred Window **/
//roomobj-4-343.dmp



/** Candle Holder **/
//roomobj-4-345.dmp



/** Loose Brick **/
//roomobj-4-446.dmp
      case 446:
		 switch (action){

		    case VER_Push:
    /*[001D]*/ startScript(132);                                                    // start Dungeon Door Opened via Loose Brick
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386



/**
 * Room 5: Library
 */


/** Door **/
//roomobj-5-102.dmp
      case 102:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(93);                                                      // Open Door (Room 3)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(93);                                                    // Close Door (Room 3)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   loadRoomWithEgo(93,3);                                             //  Enter Room Downstairs Lounge Room
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Phone **/
//roomobj-5-103.dmp
      case 103:
		 switch (action){

		    case VER_Use:
    /*[001B]*/ if (getState04(activeObject)) {                                      // If phone not repaired
    /*[001E]*/   startScript(28);                                                   // start Phone: Disconnect if Kid walks too far away
    /*[0020]*/   printEgo("It seems to be broken.");
    /*[0034]*/ } else {                                                             // -
    /*[0037]*/   startScript(27);                                                   // start Phone: Disconnect
    /*[0039]*/   startScript(24);                                                   // start Pin: Entry - Edna Phone Number
    /*[003B]*/ }
    /*[003B]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_PickUp:
    /*[003C]*/ startScript(28);                                                     // start Phone: Disconnect if Kid walks too far away
    /*[003E]*/ if (getState04(activeObject)) {                                      // If phone not repaired
    /*[0041]*/   printEgo("It seems to be broken.");                                //
    /*[0055]*/ } else {                                                             // -
    /*[0058]*/   startScript(28);                                                   //  start Phone: Disconnect if Kid walks too far away
    /*[005A]*/   startSound(21);                                                    //  sound
    /*[005C]*/ }
    /*[005C]*/ //stopObjectCode();                                                    // --
		break;


			case VER_Fix:  // FIXME: Check if goto removed its OK.       
    /*[005D]*/ if (getState04(activeObject)) {                                      // If phone not repaired
    /*[0060]*/   if (VAR_EGO == 7) {                                                //  If Jeff
    /*[0065]*/   } else {                                                           //
    /*[0068]*/ //  unless (VAR_EGO == 5) goto 00A6;                                 //  or Bernard
    /*[0068]*/     if (VAR_EGO != 5) printEgo("I don't know anything about electronics!"); //  or Bernard
    /*[006D]*/   }
    /*[006D]*/   if (activeObject2 == 119) {                                        //  And ActiveObject2 is Tools
    /*[0071]*/     clearState04(activeObject);                                                  //   Phone repaired
    /*[0072]*/     printEgo("That should do it.");
    /*[0083]*/   } else {                                                           // -
    /*[0086]*/     printEgo("I need some tools or something?!");
    /*[00A3]*/   }
    /*[00A3]*/ //goto 00CB;                                                         // --
    /*[00A6]*/ //printEgo("I don't know anything about electronics!");              //  else Other Kids
    /*[00CB]*/ }
    /*[00CB]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Cassette Tape **/
//roomobj-5-156.dmp
      case 156:
		 switch (action){

		    case VER_PickUp:
    /*[0023]*/ pickupObject(0);                                                     // Pickup Tape
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0026]*/ doSentence(11,255,254);                                              // Use Tape with _cmdObject2
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[002B]*/ if (VAR_ACTIVE_ACTOR == 14) {                                        // Give to Green Tentacle
    /*[0030]*/   if (VAR_ROOM == 20) {                                              //  if current room is Green Tentacle's
    /*[0035]*/     startScript(102);                                                //   start Green Tentacle: Accepts Tape
    /*[0037]*/   }
    /*[0037]*/ }
    /*[0037]*/ if (VAR_ACTIVE_ACTOR < 8) {                                          // Give to Kid
    /*[003C]*/   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Kid owns object
    /*[003F]*/ }
    /*[003F]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Loose Panel **/
//roomobj-5-236.dmp
      case 236:
		 switch (action){

		    case VER_Open:
    /*[0023]*/ setState08(activeObject);                                                        // Open Panel
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0025]*/ clearState08(activeObject);                                                      // Close Panel
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;


			case VER_Push:		    
			case VER_Pull:
    /*[0027]*/ if (getState08(activeObject)) {                                      // Is Panel Open
    /*[002A]*/   clearState08(activeObject);                                                    //  Close Panel
    /*[002B]*/ } else {                                                             // -
    /*[002E]*/   setState08(activeObject);                                                      //  Open Panel
    /*[002F]*/ }
    /*[002F]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Lamp **/
//roomobj-5-315.dmp
      case 315:
		 switch (action){

		case VER_TurnOn:
    /*[0018]*/ startSound(12);                                                      // sound Light Switch
    /*[001A]*/ setBitVar(VAR_ROOM,1,0);                                             // Room has light
    /*[001E]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0020]*/ Var[117] = 1;                                                        // Room light on
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0024]*/ startSound(12);                                                      // sound Light Switch
    /*[0026]*/ Var[117] = 0;                                                        // Room light off
    /*[0029]*/ if (Var[118] == 0) {
    /*[002E]*/   setBitVar(VAR_ROOM,1,1);                                           // Room loses light
    /*[0032]*/   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    /*[0034]*/ }
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Lamp **/
//roomobj-5-316.dmp
      case 316:
		 switch (action){

		case VER_TurnOn:
    /*[0018]*/ startSound(12);                                                      // sound Light Switch
    /*[001A]*/ setBitVar(VAR_ROOM,1,0);                                             // Room has light
    /*[001E]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0020]*/ Var[118] = 1;                                                        // Room light on
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0024]*/ startSound(12);                                                      // sound Light Switch
    /*[0026]*/ Var[118] = 0;                                                        // Room light off
    /*[0029]*/ if (Var[117] == 0) {
    /*[002E]*/   setBitVar(4,1,1);                                                  // Room loses light
    /*[0032]*/   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    /*[0034]*/ }
    /*[0034]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Staircase **/
//roomobj-5-318.dmp
      case 318:
		 switch (action){

		    case VER_WalkTo:
    /*[001F]*/ printEgo("Staircase out of order.");                                 // Walk To
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;


			case VER_Fix:
		    case VER_Use:
    /*[0036]*/ printEgo("I can't fix the stairs with that.");                       // Fix/Use
    /*[0053]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Chuck the plant **/
//roomobj-5-319.dmp



/** Chair **/
//roomobj-5-320.dmp



/** Sign **/
//roomobj-5-440.dmp
      case 440:
		 switch (action){

		    case VER_Read:
    /*[0018]*/ printEgo("Staircase out of order.");                                 // Read
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


			case VER_Fix:
    /*[002F]*/ if (activeObject2 == 119) {                                          // Use tools with Sign
    /*[0033]*/   printEgo("I'm not a carpenter.");
    /*[0046]*/ } else {                                                             // -
    /*[0049]*/   printEgo("That won't work.");
    /*[0059]*/ }
    /*[0059]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386


/**
 * Room 6: Pool Area
 */


/** Door **/
//roomobj-6-104.dmp
      case 104:
		 switch (action){

		    case VER_Open:
    /*[0020]*/ if (!getState04(activeObject)) {                                     // If door is unlocked
    /*[0023]*/   startScript(4);                                                    //  start Door: Open
    /*[0025]*/   setState08(92);                                                    //  Open Door (Storage room)
    /*[0027]*/ } else {                                                             // -
    /*[002A]*/   startScript(64);                                                   //  start Print "The door is locked"
    /*[002C]*/ }
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[002D]*/ startScript(5);                                                      // start Door: Close
    /*[002F]*/ clearState08(92);                                                    // Close Door (Storage room)
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Unlock:		    case VER_Use:
    /*[0032]*/ if (activeObject2 == 125) {                                          // if Use Silver Key with Door
    /*[0036]*/   clearState04(activeObject);                                                    //  Unlock Door
    /*[0037]*/   clearState04(92);                                                  //  Unlock Door (Storage room)
    /*[0039]*/   doSentence(1,104,0);                                               //  Execute Verb: "Open Door"
    /*[003D]*/ } else {                                                             // -
    /*[0040]*/   startScript(66);                                                   //  start Print "I can't unlock the door with this."
    /*[0042]*/ }
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Lock:
    /*[0043]*/ setState04(activeObject);                                                        // Lock Door
    /*[0044]*/ setState04(92);                                                      // Lock Door (Storage Room)
    /*[0046]*/ doSentence(2,104,0);                                                 // Execute Verb: "Close Door"
    /*[004A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[004B]*/ if (getState08(activeObject)) {                                      // Is Door Open
    /*[004E]*/   loadRoomWithEgo(92,36);                                            //  Enter Storage / Leading out to pool
    /*[0051]*/ }
    /*[0051]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Gate **/
//roomobj-6-105.dmp
      case 105:
		 switch (action){

		    case VER_WalkTo:
    /*[001E]*/ if (getState08(activeObject)) {
    /*[0021]*/   if (Var[136] == 1) {                                               // is Garage Destroyed?
    /*[0026]*/     loadRoomWithEgo(75,52);                                          //  Enter Garage Destroyed
    /*[0029]*/   } else {                                                           // -
    /*[002C]*/     loadRoomWithEgo(110,16);                                         //  Enter Garage
    /*[002F]*/   }
    /*[002F]*/ }
    /*[002F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Open:
    /*[0030]*/ startScript(4);                                                      // start Door: Open
    /*[0032]*/ setState08(110);                                                     // Open Gate (Garage)
    /*[0034]*/ setState08(75);                                                      // Open Gate (Destroyed Garage)
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;


			case VER_Close:
		    case VER_Push:
    /*[0037]*/ startScript(5);                                                      // start Door: Close
    /*[0039]*/ clearState08(110);                                                   // Open Gate (Garage)
    /*[003B]*/ clearState08(75);                                                    // Open Gate (Destroyed Garage)
    /*[003D]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Swimming Pool **/
//roomobj-6-106.dmp
      case 106:
		 switch (action){

		    case VER_WalkTo:
    /*[0021]*/ if (!getState08(activeObject)) {                                     // If Pool Full
    /*[0024]*/   printEgo("I don't want to get wet!");
    /*[0039]*/ } else {                                                             // -
    /*[003C]*/   printEgo("I'd better use the ladder.");
    /*[0054]*/   doSentence(13,139,0);                                              // Use Ladder Script
    /*[0058]*/ }
    /*[0058]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0059]*/ if (!getState08(activeObject)) {                                     // If Pool Full
    /*[005C]*/   if (activeObject2 == 90) {                                         //  if Sponge
    /*[0060]*/     Var[24] = 2;                                                     //   Spong Contents = Radioactive Water
    /*[0063]*/     startScript(75);                                                 //   start Sponge: Name
    /*[0065]*/   }
    /*[0065]*/   if (activeObject2 == 99) {                                         //  if Glass Jar
    /*[0069]*/     Var[22] = 2;                                                     //   Glass Jar Contents = Radioactive Water
    /*[006C]*/     startScript(74);                                                 //   start Glass Jar: Name
    /*[006E]*/   }
    /*[006E]*/ }
    /*[006E]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Radio **/
//roomobj-6-107.dmp
      case 107:
		 switch (action){

		case VER_WhatIs:
    /*[0017]*/ printEgo("I can't reach it.");                                       // Pickup
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Ladder **/
//roomobj-6-139.dmp
      case 139:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ loadRoomWithEgo(138,2);                                              // Enter Room 2, Bottom of Pool
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Ladder **/
//roomobj-6-272.dmp
      case 272:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ printEgo("I'M not going down there%/%it's full of water!");          // Walk To
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Pool Chair **/
//roomobj-6-323.dmp
      case 323:
		 switch (action){

		case VER_WhatIs:
    /*[001C]*/ printEgo("I can't reach it.");                                       // What Is
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Old Tree **/
//roomobj-6-324.dmp



/**
 * Room 7: Kitchen
 */


/** Old Batteries **/
//roomobj-7-100.dmp
      case 100:
		 switch (action){

		    case VER_PickUp:
    /*[0021]*/ pickupObject(0);                                                     // Pikcup
    /*[0023]*/ doSentence(13,56,0);                                                 // Walk To Refridgerator
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0028]*/ if (activeObject2 == 51) {                                           // Flashlight
    /*[002C]*/   Var[31] = 1;                                                       // Flashlight has Battery = Yes
    /*[002F]*/   Var[126] = 60;                                                     // Flashlight Battery Charge
    /*[0032]*/   setOwnerOf(100,0);                                                 // Remove Old Batteries
    /*[0035]*/ }
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386



      } // END switch (activeObject).
}

