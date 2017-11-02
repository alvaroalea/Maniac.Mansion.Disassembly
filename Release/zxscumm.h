// TODO FIX
#define bool int
#define FALSE 0


// SOUND MANAGEMENT
void stopSound(int n);
void startSound(int n);
void loadSound( int n);
void stopMusic(void);
void unlockSound(int n);

// SCRIPTS MANAGEMENT
bool isScriptRunning(int n);
void startScript(int n);
void stopScript(int n);
void unlockScript(int n);
void loadScript(int n);

// ACTORS
void putActorInRoom(int actor, int room);
void putActor(int actor, int x, int y);
void animateActor(int actor, int a, int b);
int  getActorRoom(int actor);
void setActorBitVar(int actor, int bit, bool var);
void loadCostume(int n);
void lockCostume(int n);

// OTHERS
void lights(int n);
void stopObjectCode(void); // Probably not needed
void setBitVar(int a, int b, int c);
bool getState08(int n);
void clearState08(int n);
void setState08(int n);
void setOwnerOf(int n,int m);
void pickupObject(int n);         
void printEgo(char *p);
void doSentence(int n, int m, int o);




