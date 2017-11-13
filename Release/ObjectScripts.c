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

/** Sealed Envelope **/
//roomobj-7-234.dmp
      case 234:
		 switch (action){

		    case VER_Open:
    /*[0026]*/ doSentence(1,201,0);                                                 // Open Sealed Envelope
    /*[002A]*/ doSentence(14,234,0);                                                // Pickup Sealed Envelope
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_PickUp:
    /*[002F]*/ clearState08(activeObject);
    /*[0030]*/ setState02(activeObject);
    /*[0031]*/ setOwnerOf(201,VAR_EGO);                                             // Kid owns Sealed Envelope
    /*[0034]*/ Var[66] -= 2;                                                        // Item in Microwave -= 2
    /*[0037]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0038]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[003C]*/ startScript(76);                                                     // Jar / Envelop: Name
    /*[003E]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Window **/
//roomobj-7-276.dmp



/** Very dull knives **/
//roomobj-7-277.dmp
      case 277:
		 switch (action){

		    case VER_PickUp:
    /*[0022]*/ printEgo("They're glued to the wall.");                              // Pickup
    /*[003A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Stove **/
//roomobj-7-279.dmp
      case 279:
		 switch (action){

		 	case VER_Use:
    /*[001F]*/ printEgo("I don't think that's a good idea.");                       // Use
    /*[003C]*/ //stopObjectCode();                                                    // --
		break;

			case VER_Open:
			case VER_Close:
			case VER_TurnOn:
			case VER_TurnOff:
    /*[003D]*/ printEgo("I'd rather use the microwave.");                           // Open/Close/Turn On/Turn Off
    /*[0058]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Blood **/
//roomobj-7-280.dmp
      case 280:
		 switch (action){

		case VER_WhatIs:
    /*[0017]*/ printEgo("Yuck!");                                                   // What Is
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Door **/
//roomobj-7-48.dmp
      case 48:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(35);                                                      // Open Door (Main Entry)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(35);                                                    // Close Door (Main Entry)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   loadRoomWithEgo(35,10);                                            //  Enter Main Entry
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Door **/
//roomobj-7-49.dmp
      case 49:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(62);                                                      // Open Door (Dining)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(62);                                                    // Close Door (Dining)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   loadRoomWithEgo(62,37);                                            // Enter Dining
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Jar of Water **/
//roomobj-7-50.dmp
      case 50:
		 switch (action){

		    case VER_PickUp:
    /*[002A]*/ VAR_RESULT = isScriptRunning(55);                                    // is Timer: 1 Minute running
    /*[002D]*/ if (VAR_RESULT == 1) {
    /*[0032]*/   printEgo("Ouch! It's still too hot!");
    /*[0049]*/ } else {                                                             // -
    /*[004C]*/   clearState08(activeObject);                                                    // Invisible Glass Jar
    /*[004D]*/   setState02(activeObject);                                                      // Lock Glass Jar
    /*[004E]*/   setOwnerOf(99,VAR_EGO);                                            // Pickup Glass Jar
    /*[0051]*/   Var[66] -= 4;                                                      // Item in Microwave -= 4
    /*[0054]*/ }
    /*[0054]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Flashlight **/
//roomobj-7-51.dmp
      case 51:
		 switch (action){

		    case VER_PickUp:
    /*[0028]*/ pickupObject(0);                                                     // Pickup Flashlight
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[002B]*/ if (Var[31] >= 1) {                                                  // if Flashlight has Battery
    /*[0030]*/   Var[12] = 1;                                                       //  Flashlight Status = On
    /*[0033]*/   startScript(77);                                                   //  start Flashnight: Name
    /*[0035]*/   if (Var[31] == 1) {                                                //  if Flashlight has Battery == Old Battery
    /*[003A]*/     startScript(145);                                                //   start Flashlight: Check
    /*[003C]*/   }
    /*[003C]*/ } else {                                                             // -
    /*[003F]*/   printEgo("It needs batteries.");
    /*[0052]*/ }
    /*[0052]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0053]*/ if (Var[31] >= 1) {                                                  // if Flashlight has Battery
    /*[0058]*/   Var[12] = 0;                                                       //  Flashlight Status = Off
    /*[005B]*/   startScript(77);                                                   //  start Flashnight: Name
    /*[005D]*/   stopScript(145);                                                   //  stop Flashlight: Check
    /*[005F]*/ }
    /*[005F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0060]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0064]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0065]*/ if (VAR_ACTIVE_ACTOR < 8) {                                          // Player Kid?
    /*[006A]*/   doSentence(5,51,0);                                                //  Turn Off Flashlight
    /*[006E]*/   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    //  Give to kid
    /*[0071]*/ }
    /*[0071]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Microwave Oven **/
//roomobj-7-52.dmp
      case 52:
		 switch (action){

		    case VER_Open:
    /*[0028]*/ if (!getState08(activeObject)) {                                     // If Microwave on
    /*[002B]*/   stopScript(11);                                                    //  stop Hamster: In Microwave
    /*[002D]*/   stopScript(53);                                                    //  stop Microwave
    /*[002F]*/   startScript(4);                                                    //  start Door: Open
    /*[0031]*/   if (getState08(54)) {                                              // if Exploded Hamster Microwaved
    /*[0035]*/     clearState02(54);
    /*[0037]*/   }
    /*[0037]*/   if (getState08(53)) {                                              // if Hamster Microwaved
    /*[003B]*/     clearState02(53);
    /*[003D]*/   }
    /*[003D]*/   if (getState08(50)) {                                              // if Jar of Water Microwaved
    /*[0041]*/     clearState02(50);
    /*[0043]*/     if (Var[22] == 4) {                                              // Glass Jar Contents == Microwaved Developer
    /*[0048]*/       printEgo("Argh! What a smell!!");
    /*[005B]*/     }
    /*[005B]*/     if (Var[22] == 2) {                                              // Glass Jar Contents == Radioactive Water
    /*[0060]*/       VAR_RESULT = isScriptRunning(55);
    /*[0063]*/       if (VAR_RESULT == 1) {                                         // if Timer: 1 Minute has not finished
    /*[0068]*/         Var[76] = 1;                                                 //  Death Method = Radioactive Steam
    /*[006B]*/         startScript(56);                                             //  Cutscene: Kid Dies
    /*[006D]*/       }
    /*[006D]*/     }
    /*[006D]*/   }
    /*[006D]*/   if (getState08(234)) {                                             // if Sealed Envelope Microwaved
    /*[0071]*/     clearState02(234);                                               //  Stamps Removed
    /*[0073]*/   }
    /*[0073]*/ }
    /*[0073]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0074]*/ startScript(5);                                                      // start Door: Close
    /*[0076]*/ setState02(54);                                                      // Exploded Hamster Microwaved
    /*[0078]*/ setState02(53);                                                      // Hamster microwaved
    /*[007A]*/ setState02(50);
    /*[007C]*/ setState02(234);
    /*[007E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[007F]*/ startScript(54);                                                     // start Microwave: Put item in
    /*[0081]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOn:
    /*[0082]*/ startScript(69);                                                     // start Microwave:
    /*[0084]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0085]*/ stopScript(11);                                                      // stop Hamster: In Microwave
    /*[0087]*/ stopScript(53);                                                      // stop Microwave
    /*[0089]*/ if (getState08(54)) {                                                // if Exploded Hamster Microwaved
    /*[008D]*/   printEgo("I think it's too late!");
    /*[00A1]*/ }
    /*[00A1]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Hamster **/
//roomobj-7-53.dmp
      case 53:
		 switch (action){

		    case VER_PickUp:
    /*[0019]*/ clearState08(activeObject);                                                      // Lock Hamster
    /*[001A]*/ setState02(activeObject);                                                        //
    /*[001B]*/ setOwnerOf(1,VAR_EGO);                                               // Kid owns hamster
    /*[001E]*/ Var[66] = 0;                                                         // Item in Microwave = Empty
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386



/** Exploded Hamster **/
//roomobj-7-54.dmp
      case 54:
		 switch (action){

		    case VER_PickUp:
    /*[0024]*/ if (VAR_EGO <= 2) {                                                  //  Syd/Razor
    /*[0029]*/   printEgo("Yum! Should I take white or dark meat?");
    /*[004A]*/ } else {                                                             // -
    /*[004D]*/   printEgo("How gross!");                                            //  Other Kids
    /*[0058]*/ }
    /*[0058]*/ pickupObject(0);                                                     // Pickup
    /*[005A]*/ clearState08(54);                                                    // Hide Exploded Hamster
    /*[005C]*/ setState02(54);
    /*[005E]*/ Var[66] = 0;                                                         // Item in Microwave = Empty
    /*[0061]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0062]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[0064]*/ if (VAR_ACTIVE_ACTOR == 11) {                                        // if Giving To Weird Ed
    /*[0069]*/   Var[76] = 3;                                                       //  Death Method = Ed Kills you
    /*[006C]*/   startScript(56);                                                   //  Cutscene: Kid Dies
    /*[006E]*/ }
    /*[006E]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386


/** Faucet **/
//roomobj-7-55.dmp
      case 55:
		 switch (action){

		case VER_TurnOn:
    /*[001C]*/ clearState08(activeObject);                                                      // Faucet is on
    /*[001D]*/ startSound(17);                                                      //
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0020]*/ setState08(activeObject);                                                        // Faucet is off
    /*[0021]*/ stopSound(17);
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0024]*/ if (!getState08(activeObject)) {                                     // if Faucet is on
    /*[0027]*/   startScript(73);                                                   //  start Facet: Fill Gar/Sponge with Water
    /*[0029]*/   startScript(76);                                                   //  start Jar / Envelop: Name
    /*[002B]*/ }
    /*[002B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Refridgerator **/
//roomobj-7-56.dmp
      case 56:
		 switch (action){

			case VER_Open:
		    case VER_Pull:
    /*[0024]*/ startScript(4);                                                      // start Door: Open
    /*[0026]*/ if (Var[128] == 0) {                                                 // has Fridge has been opened?
    /*[002B]*/   Var[128] = 1;                                                      //  Fridge has been opened = Yes
    /*[002E]*/   Var[127] = 2;                                                      //  Weird Ed Trigger = Cheese
    /*[0031]*/   startScript(82);                                                   //  start Weird Ed: Leave Room
    /*[0033]*/ }
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Close:
		case VER_Push:
    /*[0034]*/ startScript(5);                                                      // start Door: Close
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Cheese **/
//roomobj-7-57.dmp
      case 57:
		 switch (action){

		   case VER_PickUp:
    /*[001A]*/ pickupObject(0);                                                     // Pickup Cheese
    /*[001C]*/ doSentence(13,56,0);                                                 // Walk to Refridgerator
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0021]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Lettuce **/
//roomobj-7-58.dmp
      case 58:
		 switch (action){

		    case VER_PickUp:
    /*[001B]*/ pickupObject(0);                                                     // Pick object
    /*[001D]*/ doSentence(13,56,0);                                                 // Walk to Refridgerator
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0022]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Broken Bottles **/
//roomobj-7-59.dmp
      case 59:
		 switch (action){

		    case VER_PickUp:
    /*[002D]*/ pickupObject(0);                                                     // Pick object
    /*[002F]*/ doSentence(13,56,0);                                                 // Walk to Refridgerator
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0034]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Can of Pepsi **/
//roomobj-7-60.dmp
      case 60:
		 switch (action){

		    case VER_PickUp:
    /*[0024]*/ pickupObject(0);                                                     // Pick object
    /*[0026]*/ doSentence(13,56,0);                                                 // Walk to Refridgerator
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[002B]*/ printEgo("12 fluid ounces (354 ml)");                                // Read
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0042]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[0046]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0047]*/ if (VAR_ACTIVE_ACTOR == 19) {                                        // If give to Plant
    /*[004C]*/   startScript(48);                                                   //  start Plant: Give Pepsi
    /*[004E]*/ } else if (VAR_ACTIVE_ACTOR > 8) {                                   // -
    /*[0056]*/   print(VAR_ACTIVE_ACTOR,"No thanks, it makes me burp.");            //  Only kids take drink
    /*[0070]*/ } else {                                                             // -
    /*[0073]*/   startScript(99);                                                   //  start Give: Accept Item Check 2
    /*[0075]*/ }
    /*[0075]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Chainsaw **/
//roomobj-7-61.dmp
      case 61:
		 switch (action){

		    case VER_PickUp:
    /*[001E]*/ pickupObject(0);                                                     // Pick object
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;


			case VER_TurnOn:
		    case VER_Use:
    /*[0021]*/ printEgo("I think it's out of gas.");
    /*[0036]*/ if (VAR_EGO == 1) {                                                  // If kid is Syd
    /*[003B]*/   printEgo("Let's go find some gas!");
    /*[0050]*/ }
    /*[0050]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/**
 * Room 8: Basement
 */

 /** Stairs **/
//roomobj-8-121.dmp
      case 121:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ loadRoomWithEgo(36,10);                                              // Enter Main Entry
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Door **/
//roomobj-8-122.dmp
      case 122:
		 switch (action){

		    case VER_Open:
    /*[0020]*/ if (!getState08(activeObject)) {                                     // Is door locked
    /*[0023]*/   startScript(64);                                                   // start Print "The door is locked"
    /*[0025]*/ }
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


			case VER_Close:
			case VER_Lock:
    /*[0026]*/ startScript(51);                                                     // start Dungeon: Close Entry Door
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		case VER_Unlock:		    case VER_Use:
    /*[0029]*/ if (activeObject2 == 43) {                                           // Use Old Rusty Key with Door
    /*[002D]*/   startScript(4);                                                    //  start Door: Open
    /*[002F]*/   setState08(126);                                                   //  Open Door (Main Entry)
    /*[0031]*/ } else {                                                             // -
    /*[0034]*/   startScript(66);                                                   //  start Print "I can't unlock the door with this."
    /*[0036]*/ }
    /*[0036]*/ //stopObjectCode();                                                    // --
		break;

		    case VER_WalkTo:
    /*[0037]*/ if (getState08(activeObject)) {                                      // if door is open
    /*[003A]*/   doSentence(2,122,0);                                               //   Close Door
    /*[003E]*/   loadRoomWithEgo(126,4);                                            //   Enter Basement
    /*[0041]*/ }
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/** Fuse Box **/
//roomobj-8-123.dmp
      case 123:
		 switch (action){

		    case VER_Open:
    /*[001C]*/ setState08(activeObject);                                                        // Open Fuse Box
    /*[001D]*/ startSound(8);                                                       // Door Opening
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0020]*/ clearState08(activeObject);                                                      // Close Fuse Box
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Circuit Breaker **/
//roomobj-8-124.dmp
      case 124:
		 switch (action){

		case VER_TurnOn:
    /*[0028]*/ VAR_RESULT = isScriptRunning(138);
    /*[002B]*/ if (VAR_RESULT == 1) {                                               // if Cutscene: Dr. Fred Play Meteor Mess Trigger running
    /*[0030]*/   startSound(12);                                                    //  Sound Light Switch

    /*[0032]*/ } else if (getState08(activeObject)) {                               // - If Power Off
    /*[0038]*/   clearState08(activeObject);                                                    //  Power On
    /*[0039]*/   startSound(12);                                                    //  sound Light Switch
    /*[003B]*/   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status

    /*[003D]*/   if (!getState08(106)) {                                            //  if Swimming Pool is full
    /*[0041]*/     startScript(7);                                                  //   Game: Meltdown Stop
    /*[0043]*/   }
    /*[0043]*/ }
    /*[0043]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0044]*/ if (!getState08(activeObject)) {                                     // If Power On
    /*[0047]*/   stopScript(138);                                                   //  stop Cutscene: Dr. Fred Play Meteor Mess Trigger
    /*[0049]*/   setState08(activeObject);                                                      //  Power Off
    /*[004A]*/   startSound(12);                                                    //  sound Light Switch
    /*[004C]*/   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    /*[004E]*/   startScript(6);                                                    //  start Game: Meltdown Timer
    /*[0050]*/   stopScript(138);                                                   //  stop Cutscene: Dr. Fred Play Meteor Mess Trigger
    /*[0052]*/   Var[29] = 0;                                                       //  Radio = off
    /*[0055]*/   clearState08(207);                                                 //  Cassette Player = Off
    /*[0057]*/   clearState08(157);                                                 //  TV = Off
    /*[0059]*/   clearState08(158);                                                 //  Casette Recorder = Off
    /*[005B]*/   clearState08(131);                                                 //  Mondo Stereo = Off
    /*[005D]*/   stopScript(15);                                                    //  stop Cassette: Play, Break Windows/Free Key
    /*[005F]*/   clearState08(169);                                                 //  stop Video Fever
    /*[0061]*/   clearState08(170);                                                 //  stop Disco Crazy
    /*[0063]*/   clearState08(171);                                                 //  stop Alien Slime
    /*[0065]*/   clearState08(172);                                                 //  stop Die Enemy Die
    /*[0067]*/   clearState08(174);                                                 //  stop Kill Thrill
    /*[0069]*/   Var[28] = 0;                                                       //  Radio (Room 21) = Off
    /*[006C]*/ }
    /*[006C]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[006D]*/ clearState08(123);                                                   // Close Fuse Box
    /*[006F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[0070]*/ printEgo("MAIN POWER");                                              // Read
    /*[007B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Silvey Key **/
//roomobj-8-125.dmp
      case 125:
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





/** Light Switch **/
//roomobj-8-325.dmp
      case 325:
		 switch (action){

		case VER_TurnOn:
    /*[0020]*/ startSound(12);                                                      // sound Light Switch
    /*[0022]*/ setBitVar(VAR_ROOM,1,0);                                             // Light On
    /*[0026]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0029]*/ startSound(12);                                                      // sound Light Switch
    /*[002B]*/ setBitVar(VAR_ROOM,1,1);                                             // Light Off
    /*[002F]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0031]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Radioactive**/
//roomobj-8-337.dmp
      case 337:
		 switch (action){

		case VER_WhatIs:
    /*[0023]*/ printEgo("Yuck! I'm not touching that!");                            // What Is
    /*[003D]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Furnace **/
//roomobj-8-338.dmp
      case 338:
		 switch (action){

		    case VER_WalkTo:
    /*[001B]*/ //stopObjectCode();                                                    // -- Walk To
		break;

		case VER_WhatIs:
    /*[001C]*/ printEgo("It's too hot!");                                           // What Is
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Nuclear Reactor **/
//roomobj-8-339.dmp
      case 339:
		 switch (action){

		    case VER_WalkTo:
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0028]*/ printEgo("I don't want to start a melt down!");                      //
    /*[0045]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[0046]*/ printEgo("Made in Chernobyl");                                       //
    /*[0057]*/ //stopObjectCode();                                                    // --
		break;


		case VER_WhatIs:
    /*[0058]*/ printEgo("It's too hot!");                                           //
    /*[0065]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/**
 * Room 9: Attic (Above Nurse Edna's Room)
 */

 /** Hatch **/
//roomobj-9-196.dmp
      case 196:
		 switch (action){

			case VER_Open:
		    case VER_PickUp:
    /*[001F]*/ startScript(4);                                                      // start Door: Open
    /*[0021]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0022]*/ startScript(5);                                                      // start Door: Close
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Pull:
    /*[0025]*/ if (getState08(activeObject)) {                                      // If hatch is open
    /*[0028]*/   startScript(5);                                                    // start Door: Close
    /*[002A]*/ } else {                                                             // -
    /*[002D]*/   startScript(4);                                                    // start Door: Open
    /*[002F]*/ }
    /*[002F]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0030]*/ if (getState08(activeObject)) {                                      // If hatch is open
    /*[0033]*/   if (Var[109] == 0) {
    /*[0038]*/     if (Var[17] == 0) {                                              //  If Nurse Edna Disabled = No
    /*[003D]*/       putActorInRoom(10,19);                                         //   Put Nurse Edna in room
    /*[0040]*/       putActor(10,34,64);
    /*[0044]*/       animateActor(10,6,1);                                          //   Nurse Edna Face camera
    /*[0048]*/       startScript(33);                                               //   start Nurse Edna: Leave Room
    /*[004A]*/     }
    /*[004A]*/   }
    /*[004A]*/   loadRoomWithEgo(210,19);                                           //  Enter Nurse Edna's at Ladder
    /*[004D]*/ }
    /*[004D]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Painting **/
//roomobj-9-197.dmp
      case 197:
		 switch (action){

		    case VER_Open:
    /*[001E]*/ startScript(4);                                                      // start Door: Open
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0021]*/ startScript(5);                                                      // start Door: Close
    /*[0023]*/ clearState08(198);                                                   // Close Wall Safe
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Wall Safe **/
//roomobj-9-198.dmp
      case 198:
		 switch (action){

		    case VER_Use:
    /*[001F]*/ if (!getState08(activeObject)) {                                     // Is Closed
    /*[0022]*/   startScript(39);                                                   //  start Room9: Wallsafe Input
    /*[0024]*/ }
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0025]*/ startScript(5);                                                      // start Door: Close
    /*[0027]*/ clearState08(197);                                                   // Close Painting
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Quarter **/
//roomobj-9-200.dmp
      case 200:
		 switch (action){

		    case VER_Use:
    /*[0019]*/ doSentence(11,255,254);                                              // Use _cmdObject2 with _cmdObject
    /*[001D]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Sealed Envelope **/
//roomobj-9-201.dmp
      case 201:
		 switch (action){

		    case VER_PickUp:
    /*[0032]*/ pickupObject(0);                                                     // Pick object
    /*[0034]*/ pickupObject(200);                                                   // Pick Quarter
    /*[0036]*/ setOwnerOf(200,14);                                                  // Set Owner of Quarter to Green Tentacle
    /*[0039]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[003A]*/ startScript(81);                                                     // start Envelope: Use
    /*[003C]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Open:
    /*[003D]*/ if (!getState08(201)) {                                              // if Sealed Envelope closed
    /*[0041]*/   doSentence(1,201,0);                                               //  Open Sealed Envelope
    /*[0045]*/   doSentence(14,201,0);                                              //  Pickup Sealed Envelope
    /*[0049]*/ } else {                                                             // -
    /*[004C]*/   startScript(80);                                                   //  start Envelope: Open
    /*[004E]*/ }
    /*[004E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[004F]*/ if (Var[85] == 0) {                                                  // if Envelope: Addressed == No
    /*[0054]*/   printEgo("It's a blank envelope.");
    /*[0069]*/ } else {                                                             // -
    /*[006C]*/   printEgo("It's addressed to: 222 Skyscraper Way.");
    /*[008F]*/ }
    /*[008F]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Light Switch **/
//roomobj-9-293.dmp
      case 293:
		 switch (action){

		case VER_TurnOn:
    /*[001B]*/ startSound(12);                                                      // sound Light Switch
    /*[001D]*/ setBitVar(VAR_ROOM,1,0);                                             //
    /*[0021]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0024]*/ startSound(12);                                                      // sound Light Switch
    /*[0026]*/ setBitVar(VAR_ROOM,1,1);                                             // Light Off
    /*[002A]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[002C]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Pull:
    /*[002D]*/ VAR_RESULT = getBitVar(VAR_ROOM,1);
    /*[0031]*/ if (VAR_RESULT == 0) {                                               // Is light off
    /*[0036]*/   doSentence(5,37,0);                                                // Turn on Light Switch
    /*[003A]*/ } else {                                                             // -
    /*[003D]*/   doSentence(4,37,0);                                                // Turn off Light Switch
    /*[0041]*/ }
    /*[0041]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Scrawled Number **/
//roomobj-9-414.dmp
      case 414:
		 switch (action){

		    case VER_Read:
    /*[0021]*/ printEgo("It's too tiny to read!");                                  //
    /*[0035]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/**
 * Room 10: Main Entry
 */


/** Stairs **/
//roomobj-10-209.dmp
      case 209:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ loadRoomWithEgo(146,11);                                             // Enter Top of Main Entry
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386


/** Grandfather Clock **/
//roomobj-10-269.dmp
      case 269:
		 switch (action){

		    case VER_Read:
    /*[0023]*/ printEgo("It's the correct time.");
    /*[0038]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Vase **/
//roomobj-10-270.dmp



/** Vase **/
//roomobj-10-271.dmp



/** Front Door **/
//roomobj-10-321.dmp
      case 321:
		 switch (action){

		    case VER_Open:
    /*[0020]*/ doSentence(1,34,0);                                                  // Open Door
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0025]*/ doSentence(2,34,0);                                                  // Close Door
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[002A]*/ doSentence(13,34,0);                                                 // Walk to Door
    /*[002E]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Door **/
//roomobj-10-34.dmp
      case 34:
		 switch (action){

		    case VER_Open:
    /*[0020]*/ startScript(4);                                                      // start Door: Open
    /*[0022]*/ setState08(28);                                                      // Open Door (Outside Mansion)
    /*[0024]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[0025]*/ startScript(5);                                                      // start Door: Close
    /*[0027]*/ clearState08(28);                                                    // Close Door (Outside Mansion)
    /*[0029]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[002A]*/ if (getState08(activeObject)) {
    /*[002D]*/   loadRoomWithEgo(28,1);                                             // Enter Outside Mansion
    /*[0030]*/ }
    /*[0030]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Gargoyle **/
//roomobj-10-342.dmp
      case 342:
		 switch (action){

		case VER_Push:
		case VER_Pull:
    /*[001C]*/ startScript(144);                                                    // start Gargoyle: Open Basement Door
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Gargoyle **/
//roomobj-10-344.dmp



/** Door: Kitchen **/
//roomobj-10-35.dmp
      case 35:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(48);                                                      // Open Door (Kitchen)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(48);                                                    // Close Door (Kitchen)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door is open
    /*[0027]*/   VAR_RESULT = isScriptRunning(147);                                 //
    /*[002A]*/   if (VAR_RESULT == 1) {                                             // if is running Nurse Edna: In Kitchen Monitor
    /*[002F]*/     startScript(148);                                                //  Nurse Edna: In Kitchen
    /*[0031]*/     loadScript(30);
    /*[0033]*/     lockScript(30);
    /*[0035]*/   }
    /*[0035]*/   loadRoomWithEgo(48,7);                                             // Enter Kitchen at Door
    /*[0038]*/ }
    /*[0038]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Door: Basement **/
//roomobj-10-36.dmp
      case 36:
		 switch (action){

			case VER_Open:
			case VER_Close:
    /*[001A]*/ printEgo("There's no handle here!");                                 // Open/Close
    /*[0030]*/ //stopObjectCode();
		break;

		    case VER_WalkTo:
    /*[0031]*/ if (getState08(activeObject)) {                                      // If Door is open
    /*[0034]*/   loadRoomWithEgo(121,8);                                            //  Enter basement
    /*[0037]*/   startScript(149);                                                  //  start  -= Does Nothing =-
    /*[0039]*/ }
    /*[0039]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Door **/
//roomobj-10-37.dmp
      case 37:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(38);                                                      // Open Door (Downstairs Lounge Room)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(38);                                                    // Close Door (Downstairs Lounge Room)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door is open
    /*[0027]*/   loadRoomWithEgo(38,3);                                             //  Enter Downstairs Lounge Room
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/**
 * Room 11: Top of Main Entry
 */


/** Stairs **/
//roomobj-11-146.dmp
      case 146:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ loadRoomWithEgo(209,10);                                             // Enter Main Entry
    /*[001B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Door **/
//roomobj-11-147.dmp
      case 147:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(164);                                                     // Open Door (Portrait Painting)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(164);                                                   // Close Door (Portrait Painting)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door is open
    /*[0027]*/   loadRoomWithEgo(164,14);                                           //  Enter Portrait Painting
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Door **/
//roomobj-11-148.dmp
      case 148:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(152);                                                     // Open Door (Music)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(152);                                                   // Close Door (Music)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door is open
    /*[0027]*/   loadRoomWithEgo(152,17);                                           //  Enter Music
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Door **/
//roomobj-11-149.dmp
      case 149:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(160);                                                     // Open Door (Level 2 Main Hallway)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(160);                                                   // Close Door (Door (Level 2 Main Hallway)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // Is Door Open
    /*[0027]*/   loadRoomWithEgo(160,13);                                           //  Enter Level 2 Main Hallway
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Painting of Fred **/
//roomobj-11-150.dmp
      case 150:
		 switch (action){

			case VER_Open:
			case VER_Pull:
    /*[0024]*/ startScript(62);                                                     // start Print "Its firmly attached to the wall"
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Painting of Edna **/
//roomobj-11-151.dmp
      case 151:
		 switch (action){

		case VER_Open:	
		case VER_Pull:
    /*[0024]*/ startScript(62);                                                     // start Print "Its firmly attached to the wall"
    /*[0026]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386


/** Wall Lamp **/
//roomobj-11-354.dmp
      case 354:
		 switch (action){

		case VER_TurnOn:
    /*[001D]*/ startSound(12);                                                      // sound Light Switch
    /*[001F]*/ setBitVar(VAR_ROOM,1,0);                                             // Light On
    /*[0023]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0025]*/ Var[120] = 0;                                                        // Wall Lamp 354 On
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0029]*/ startSound(12);                                                      // sound Light Switch
    /*[002B]*/ Var[120] = 1;                                                        // Wall Lamp 354 off
    /*[002E]*/ if (Var[119] == 1) {                                                 // If Wall Lamp 355 Off
    /*[0033]*/   setBitVar(4,1,1);                                                  //  Light Off
    /*[0037]*/   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    /*[0039]*/ }
    /*[0039]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386




/** Wall Lamp **/
//roomobj-11-355.dmp
      case 355:
		 switch (action){

		case VER_TurnOn:
    /*[001D]*/ startSound(12);                                                      // sound Light Switch
    /*[001F]*/ setBitVar(VAR_ROOM,1,0);                                             // Light On
    /*[0023]*/ startScript(50);                                                     // start Room Lights: Check for flashlight / room light status
    /*[0025]*/ Var[119] = 0;                                                        // Wall Lamp 355 On
    /*[0028]*/ //stopObjectCode();                                                    // --
		break;


		case VER_TurnOff:
    /*[0029]*/ startSound(12);                                                      // sound Light Switch
    /*[002B]*/ Var[119] = 1;                                                        // Wall Lamp 355 Off
    /*[002E]*/ if (Var[120] == 1) {                                                 // If Wall Lamp 354 Off
    /*[0033]*/   setBitVar(VAR_ROOM,1,1);                                           //  Light Off
    /*[0037]*/   startScript(50);                                                   //  start Room Lights: Check for flashlight / room light status
    /*[0039]*/ }
    /*[0039]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386

/**
 * Room 12: Level 2 Stairs to Level 3
 */


/** Stairs **/
//roomobj-12-179.dmp
      case 179:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ Var[86] = 0;                                                         // Enter Level 2 Main Hallway From Level 2 Stairs to Level 3
    /*[001B]*/ cursorCommand( kMode_Normal );                                        // Cutscene Mode Normal
    /*[001D]*/ loadRoomWithEgo(161,13);                                             // Enter Level 2 Main Hallway
    /*[0020]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386


/** Stairs **/
//roomobj-12-180.dmp
      case 180:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ if (Var[84] == 0) {                                                  // if Weird Ed has been actived by stairs in room 12
    /*[001D]*/   Var[84] = 1;                                                       //  Weird Ed has been actived by stairs in room 12 = Yes
    /*[0020]*/   startScript(106);                                                  //  start Door Bell
    /*[0022]*/ }
    /*[0022]*/ loadRoomWithEgo(208,38);                                             // Enter Level 3 Hallway
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386



/** Door **/
//roomobj-12-181.dmp
      case 181:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(182);                                                     // Open Door (Level 2 Stairs to Level 3)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(182);                                                   // Close Door (Level 2 Stairs to Level 3)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door is open
    /*[0027]*/   loadRoomWithEgo(182,23);                                           //  Enter Darkroom
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386



/** Lowly plant **/
//roomobj-12-378.dmp



/** Window **/
//roomobj-12-379.dmp



/** Window **/
//roomobj-12-380.dmp



/** Window **/
//roomobj-12-381.dmp

/**
 * Room 13: Level 2 Main Hallway
 */


/** Door **/
//roomobj-13-160.dmp
      case 160:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(149);                                                     // Open Door (Top of Main Entry)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(149);                                                   // Close Door (Top of Main Entry)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If Door Open
    /*[0027]*/   loadRoomWithEgo(149,11);                                           //  Enter Top of Main Entry
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386



/** Stairs **/
//roomobj-13-161.dmp
      case 161:
		 switch (action){

		    case VER_WalkTo:
    /*[0018]*/ if (Var[86] == 1) {                                                  // if Kid is in Level 2 - Level 3 hallway == Yes
    /*[001D]*/   printEgo("I'm not going up there%/%that monster's got my fri!");
    /*[004D]*/   walkActorTo(VAR_EGO,78,69);                                        // Walk actor away
    /*[0051]*/ } else {                                                             // -
    /*[0054]*/   loadRoomWithEgo(179,12);                                           // Enter Level 2 Stairs to Level 3
    /*[0057]*/ }
    /*[0057]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386



/** Door **/
//roomobj-13-162.dmp
      case 162:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(175);                                                     // Open Door (Medical)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(175);                                                   // Close Door (Medical)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door is open
    /*[0027]*/   loadRoomWithEgo(175,22);                                           // Enter Medical
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Door **/
//roomobj-13-163.dmp
      case 163:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(168);                                                     // Open Door (Video Game)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(168);                                                   // Close Door (Video Game)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // if door open
    /*[0027]*/   loadRoomWithEgo(168,18);                                           //  Enter Video Game
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Statue **/
//roomobj-13-360.dmp
      case 360:
		 switch (action){

		case VER_Push:
		case VER_Pull:
		case VER_PickUp:
    /*[001E]*/ printEgo("It's too heavy to move.");                                 // Push/Pull
    /*[0033]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Read:
    /*[0034]*/ printEgo("Maybe there's a plaque somewhere.");                       // Read
    /*[0053]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Plaque on statue **/
//roomobj-13-361.dmp
      case 361:
		 switch (action){

		    case VER_Read:
    /*[0022]*/ printEgo("Si trouve, envoyez-le au Louvre,/poste paye.");            // Read "If found, s to the Louvre, postage paid."
    /*[004B]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386


/**
 * Room 14: Portrait Painting
 */


/** Door **/
//roomobj-14-164.dmp
      case 164:
		 switch (action){

		    case VER_Open:
    /*[001A]*/ startScript(4);                                                      // start Door: Open
    /*[001C]*/ setState08(147);                                                     // Open Door (Top of Main Entry)
    /*[001E]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Close:
    /*[001F]*/ startScript(5);                                                      // start Door: Close
    /*[0021]*/ clearState08(147);                                                   // Close Door (Top of Main Entry)
    /*[0023]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_WalkTo:
    /*[0024]*/ if (getState08(activeObject)) {                                      // If door is open
    /*[0027]*/   loadRoomWithEgo(147,11);                                           //  Enter Top of Main Entry
    /*[002A]*/ }
    /*[002A]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Bowl of wax fruit **/
//roomobj-14-165.dmp
      case 165:
		 switch (action){

		    case VER_PickUp:
    /*[0025]*/ pickupObject(0);                                                     // Pick object
    /*[0027]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0028]*/ Var[107] = 165;                                                      // Give Script: Object-ID = Bowl of Wax Fruit
    /*[002B]*/ startScript(98);                                                     // start Give: Accept Item Check
    /*[002D]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Paint Brush **/
//roomobj-14-166.dmp
      case 166:
		 switch (action){

		    case VER_PickUp:
    /*[001D]*/ pickupObject(0);                                                     // Pick object
    /*[001F]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Paint Brush **/
//roomobj-14-167.dmp
      case 167:
		 switch (action){

		    case VER_PickUp:
    /*[0023]*/ pickupObject(0);                                                     // Pick object
    /*[0025]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Use:
    /*[0026]*/ setOwnerOf(0,14);                                                    // Use Paintbrush, Set owner to Green Tentacle
    /*[0029]*/ if (activeObject2 == 68) {                                           // if object2 == Paint Blotch
    /*[002D]*/   setState08(68);                                                    //  Hide Paint Blotch
    /*[002F]*/   setState02(68);                                                    //  Hide Paint Blotch
    /*[0031]*/ } else {                                                             // -
    /*[0034]*/   printEgo("That sure was a waste.");
    /*[0048]*/ }
    /*[0048]*/ //stopObjectCode();                                                    // --
		break;


		    case VER_Give:
    /*[0049]*/ if (VAR_ACTIVE_ACTOR == 14) {                                        // Give to Green Tentacle
    /*[004E]*/   printEgo("Yech! No thanks.");
    /*[005E]*/ } else if (VAR_ACTIVE_ACTOR < 8) {
    /*[0066]*/   setOwnerOf(0,VAR_ACTIVE_ACTOR);                                    // Give to Kid
    /*[0069]*/ }
    /*[0069]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Easel **/
//roomobj-14-362.dmp



/** Unfinished Painting **/
//roomobj-14-363.dmp



/** Cafe **/
//roomobj-14-364.dmp



/** Dried Purple Slime **/
//roomobj-14-365.dmp
      case 265:
		 switch (action){

		case VER_WhatIs:
    /*[0024]*/ printEgo("I'M not going to touch that slime!");                      // What is
    /*[0042]*/ //stopObjectCode();                                                    // --
		break;
        }       // end switch_action 386
        break;  // end obj 386





/** Sketch **/
//roomobj-14-366.dmp













      } // END switch (activeObject).
}

