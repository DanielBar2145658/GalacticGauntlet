# Galactic Gauntlet
### An out-of-this-world racing experience!

## Roles and responsibilities

**Devon Rogers** - 100861866

- **Roles**: Back-end Developer

- **Responsibilities**: Organize readme, Create video report, Keep the team on track

- **Percentage contribution**: 25%

**Daniel Barbier** - 100820942

- **Role**: Programmer

- **Responsibilities**: Programming, Implementing design patterns

- **Percentage contribution**: 40%

**Jacob Janowitz** - 100830985

- **Role**: Back-end Developer

- **Responsibilities**: Make pseudocode, Organize planning document 

- **Percentage contribution**: 35%

## Use of third-party resources
- FMOD was used to assist in managing audio assets. This is justified by the project being a racing game, which necessitates the use of adaptive audio, which is something that FMOD excels at.
- Audio assets, such as background music and menu sound effects, were created by non-GED members of the GDW team.
- The initial framework of the audio manament code was create by Tom, a member of the GDW team, as they have the most experience with FMOD. The justification is that FMOD can be confusing when you first start, and having somethin to work off of helps a ton.

## Explanations

### Singleton

**InputManager**

*Pseudocode*:
  
 - Function initialize():
  
   - call InitializeKeyMappings();
  
   - call SetupInputListeners();

- function InitializeKeyMappings():
  
  - Key bindings = {
  
  - “Accelerate” = A,
  
  - “Brake” = B,
  
  - “Turn” = left joystick,
  
  - “Drift” = right trigger,
  
  - “Use item” = left trigger
  
  - }

 - function SetupInputListeners():
  
   - create gamepad listener

*How it works*: the InputManager listens for the assigned button inputs from a connected controller, the manager will then convert these inputs into their assigned function. Our game benefits from this by being able to separate how inputs are processed from the character controller.

**EventSystem**

*Pseudocode*:
 - Function initialize()
   - eventListeners = {}

 - Function RegisterListener ():
   - If eventName not in eventListeners:
     - Create an empty list for the event if there are no listeners

 - Function UnregisterListener():
   - If eventName in eventListeners:
     - Remove the listener from the list
   - If no listeners left, clean up the event

 - Function BroadcastEvent():
   - If eventName in eventListeners:
     - Invoke the listener, pass event data

 - Function HandleEvent():
   - If eventName in eventListeners:
     - Send the event with data to listeners

*How it works*: the EventSystem assigns events to objects, keeping everything unified. Objects are able to register and unregister from events making them a listener, event data can be broadcasted to the listeners, and the listeners react to the events. This is helpful for our game because there will be lots of events happening inside our game, and having a manager will help streamline the process.

**AudioManager**

*Pseudocode*:
- Function initialize():
   - currentMusic = none
   - currentSFX = none
   - musicVolume = 1
   - SFXVolume = 1

- Function PlayMusic():
   - Set the current music dependant on the scene or tiggers
   - Loop = true
   - If currentMusic is set to none:
     - Stop playing music

- Function PlaySFX():
   - Play the given SFX when triggered
   - If currentSFX is set to none:
     - Stop playing SFX

*How it works*: the audioManager will load in and set its music and SFX to none, as of this time we do not want music or sounds to start as soon as the scene does. This can be changed as the scene progresses, the music and SFX are also given a default volume value of 1. This can also be changed when needed. The two functions will play music and sounds when triggered to, and when music has nothing to play, the manager will stop the audio. 

### Command

**ChangePlayerColor** (Customize Character)

*Pseudocode*:
- Function initialize():
   - targetObject = get the target object
   - targetMaterial = get the target objects material
   - If targetMaterial has a colour parameter:
     - currentColour = get colour from targetMaterial

- Function ChangeObjectColour():
  - If targetMaterial is valid and has colour parameter:
    - Set the colour value to a new one

- Function getTargetObject():
  - Return the object that will have its colour changed

*How it works*: the object that will have its color changed is returned and checked to see if it has a material. If the object passes the check, then the colour can be changed. This is helpful because in the game we plan to have a feature where the player can choose a colour. That way the player will know their colour before starting the race, making the gameplay more clear.

**InvertYAxis** (Customize controls)

*Pseudocode*: 
- Function invertYAxis():
  - store the current input for pitching the ship up
  - replace the input for pitching up with the input for pitching down
  - replace the input for pitching down with the store input

*How it works*: The function works by swapping the inputs for "Pitch Up" and "Pitch Down".

**RespawnPlayer** (undo/redo)

*Pseudocode*:

- Function initialize():
  - store a list of respawn points in RespawnPoints[]
  - set respawnIndex to 0

- Function UpdateRespawn():
  - If the player triggers a new respawn point:
    - Update respawnIndex to new value

- Function RespawnPlayer():
  - If the player triggers death plane:
    - Set the player location and rotation to stored respawn index value

*How it works*: the different respawn points have their own unique index value, as the player passes through the respawn points the index is updated to reflect this. If the player hits a death plane or any condition to be respawned, they will be brought back to the index value that is being stored.

### Factory

**SpawnItemBox**

*Pseudocode*: 

- Function initialize():
  - isActive = true

- Function spawnItemBox():
    - spawn a new item box
    - set isActive to true

*How it works*:  When spawnItemBox is called the item box is respawned and marked as active.

\# isActive is set to false down in the **Observer** section.

**CreateNPC**

- Function createNPC():
	- When the player presses the N key:
		- Create new vehicle instance
		- Attach AIController to new instance

*How it works*: When the player presses the N key, a new instance of the player’s vehicle is created. An instance of the AIController script is then attached to the new vehicle.

**ManageAudio**

*Pseudocode*:
- Function initialize():
  - call loadAudioSettings()

- Function loadAudioSettings():
  - musicVolume = 1.0
  - SFXVolume = 1.0
  - masterVolume = 1.0
 
- Function Update()
  - If musicVolume is changed:
    - Save new value to musicVolume
  - If SFXVolume is changed:
    - Save new value to SFXVolume
  - If masterVolume is changed:
    - Save new value to masterVolume

*How it works*: the volume for music, SFX and master volume are loaded. If the player changes the volume of any of the three, it will be saved.

### Observer

**SwapVehicleMode**

*Pseudocode*:

- Function initalize():
  - set vehicleController to the vehicle controller
  - set currentMode to “driving”

- Function onTriggerEnter():
  - call switchMode()

- Function switchMode():
  - If currentMode = “driving”
    - currentMode = “flying”
  - Else: 
    - currentMode = “driving”

*How it works*: the code will start the vehicle in driving mode and also get its controller, when the vehicle hits a trigger it will check to see what mode its in. if the vehicle is in driving mode, it will switch to flying mode. If the vehicle is not in flying mode when it hits a trigger, it will default back to driving mode. This is helpful because this will facilitate what mode the vehicle should be in when it hits a trigger.


**PlaySoundEffects**

*Pseudocode*: 

- Function Initialize():
  - initialize soundEffects{} as a dictionary to store the SFX

- Function LoadSFX():
  - load engine sound into Engine
  - load item pickup sound into Item
  - load crash sound in Crash
  - load boost sound in Boost
  - store Engine, Item, Crash, and Boost in soundEffects

- Function CallSFX(string Key):
  - play the sound effect with the given Key from soundEffects

*How it works*: sound effects are loaded and initialized into a dictionary. This dictionary is then loaded so that the audio manager can call on these sound effects. 

**GivePlayerItem**

*Pseudocode*:

- Function initialize():
  - store the list of possible items in array items[]

- Function HitItem():
  - If a player touches item box and isActive = true:
    - Assign a random item from the list items[] to the player
    - despawn the item box
    - set isActive to false
    - wait 5 seconds
    - call SpawnItemBox();

*How it works*: when the player collides with an item box, the player is assigned a random item, the item box is despawned, and SpawnItemBox is called after 5 seconds.

## Description
Galactic Gauntlet is a space-themed racing game with the main mechanic switching between land and air.
Traverse through different planets and space systems and be the first one to finish the track with a customizable ship. Race against others locally or play solo to set your own record!

## Interactive Media Scenario Description
The purpose of the scenario is to teach the player the controls of the game and get them accustomed to the game's feel.
The player is expected to complete three full laps of the track. The player controls their vehicle using a controller.
The bottom face button accelerates the vehicle, while the left joystick is used to steer the vehicle left/right.
When the player’s vehicle is in Flight mode, they can control its pitch by moving the joystick up/down.
