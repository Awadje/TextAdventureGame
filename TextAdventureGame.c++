
using UnityEngine;
using UnityEngine.UI;
using System.Collections;


public class TextController : MonoBehaviour {

	public Text text;

	private enum States 	{cell, mirror, sheets_0, lock_0, cell_mirror, sheets_1,
				lock_1, corridor_0, stairs_0, stairs_1, floor, closet_door, corridor_1,
				corridor_2, in_closet, game_over};

	private States myState;

	// Use this for initialization
	void Start () {
		myState = States.cell;
	}

	// Update is called once per frame
	void Update () {
		print (myState);
		if 	(myState == States.cell) 		{cell();}
		else if (myState == States.sheets_0) 		{sheets_0();}
		else if (myState == States.sheets_1) 		{sheets_1();}
		else if (myState == States.lock_0) 		{lock_0();}
		else if (myState == States.lock_1) 		{lock_1();}
		else if (myState == States.mirror) 		{mirror();}
		else if (myState == States.cell_mirror) 	{cell_mirror();}
		else if (myState == States.corridor_0) 		{corridor_0();}
		else if (myState == States.stairs_0) 		{stairs_0();}
		else if (myState == States.stairs_1) 		{stairs_1();}
		else if (myState == States.floor) 		{floor();}
		else if (myState == States.closet_door) 	{closet_door();}
		else if (myState == States.corridor_1) 		{corridor_1();}
		else if (myState == States.corridor_2) 		{corridor_2();}
		else if (myState == States.in_closet) 		{in_closet();}
		else if (myState == States.game_over) 		{game_over();}

	}

	//First level of the game Cell
	#region state handler methods
	void cell(){
		text.text = 	"There are some diry sheets on the bed. Across the room there is a mirror. " +
				"Not very surprisingly the door is locked.\n\n" +
				"Press S to view Sheets, M to view Mirror and L to view Lock";
		if 	(Input.GetKeyDown(KeyCode.S))		{myState = States.sheets_0;}
		else if	(Input.GetKeyDown(KeyCode.L))		{myState = States.lock_0;}
		else if	(Input.GetKeyDown(KeyCode.M))		{myState = States.mirror;}
	}

	void sheets_0(){
		text.text = 	"You can't believe you sleep in those things. Looks like someone " +
				"mistakenly used this as toilet paper. YUK The smell!\n\n" +
				"Press R to Return to your cell";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.cell;}
	}

	void sheets_1(){
		text.text = 	"Mirror Mirror on the wall please give me the cleanest sheets of them all.\n\n" +
				"Sniff Sniff.. Well that didn't work..\n\n" +
				"Press R to Return to your cell";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.cell_mirror;}
	}

	void lock_0(){
		text.text = 	"You can't do anything with the lock from this side\n\n" +
				"Press R to Return to your cell";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.cell;}
	}

	void lock_1(){
		text.text = 	"You can see the dirty fingers on the number combination.\n\n" +
				"Press R to Return to your cell with the Mirror\n"+
				"Press O to try and Open the lock";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.cell_mirror;}
		else if (Input.GetKeyDown(KeyCode.O))		{myState = States.corridor_0;}
	}

	void mirror(){
		text.text = "	Looks like it can come off the wall\n\n" +
				"Press R to Return to your cell\n"+
				"Press T to Take the mirror off the wall";
		if 	(Input.GetKeyDown(KeyCode.T))		{myState = States.cell_mirror;}
		else if (Input.GetKeyDown(KeyCode.R))		{myState = States.cell;}
	}

	void cell_mirror(){
		text.text = 	"Still in my cell. Hmmm how can I use this mirror?\n\n" +
				"Press S to look at the Sheets through the mirror\n" +
				"Press L to look at the Lock through the mirror";
		if 	(Input.GetKeyDown(KeyCode.S))		{myState = States.sheets_1;}
		else if (Input.GetKeyDown(KeyCode.L))		{myState = States.lock_1;}
	}

	//Second level of the game Corridor 0
	void corridor_0(){
		text.text = 	"IT WORKED THE DOOR OPENED!!I got out of my cell in to the corridor what to do now?\n\n" +
				"Press S to go up the Stairs.\n" +
				"Press F to look at the floor\n" +
				"Press C to open the Closet door";
		if 	(Input.GetKeyDown(KeyCode.S))		{myState = States.stairs_0;}
		else if (Input.GetKeyDown(KeyCode.C))		{myState = States.closet_door;}
		else if (Input.GetKeyDown(KeyCode.F))		{myState = States.floor;}
	}

	void stairs_0(){
		text.text = 	"Nothing to see here\n\n" +
				"Press R to Return to the corridor";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.corridor_0;}
	}

	void floor(){
		text.text = 	"How convenient there is a hairclip on the floor. " +
				"One of the female guards must have dropped it.\n\n" +
				"Press R to Return to the corridor and leave the clip\n"+
				"Press P to Pick it up and use it to open the big door";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.corridor_0;}
		else if (Input.GetKeyDown(KeyCode.P))		{myState = States.corridor_1;}
	}

	void closet_door(){
		text.text = "	Dark, dusty and empty. Nothing to see here.\n\n" +
				"Press R to Return to the corridor";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.corridor_0;}
	}

	//Third level of the game Corridors 1 & 2
	void corridor_1(){
		text.text = 	"Always come in handy those hairclips. Looks like we are in a new corridor. Is that a guard?!\n\n" +
				"Press G to Take down the guard to move on\n" +
				"Press H to Hide in the closet and be a wuss";
		if 	(Input.GetKeyDown(KeyCode.G))		{myState = States.corridor_2;}
		else if (Input.GetKeyDown(KeyCode.H))		{myState = States.in_closet;}


	}

	void corridor_2(){
		text.text = 	"This looks like the way out!.\n\n" +
				"Press S to take the stairs outside to the courtyard\n"+
				"Press R to return to the corridor";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.game_over;}
		else if (Input.GetKeyDown(KeyCode.S))		{myState = States.stairs_1;}
	}

	void in_closet(){
		text.text = 	"It's dark in here\n\n" +
				"Press R to Return to the corridor";
		if 	(Input.GetKeyDown(KeyCode.R))		{myState = States.game_over;}
	}

	void game_over(){
		text.text = 	"You got caught a guard saw you and put you back in your stinky prison cell\n\n" +
				"Game Over\n\n" +
				"Press P to play again";
		if 	(Input.GetKeyDown(KeyCode.P))		{myState = States.cell;}
	}

	void stairs_1(){
		text.text = 	"At last freedom again!\n\n" +
				"Gratz on completing the game!\n\n" +
				"Press P to play again";
		if 	(Input.GetKeyDown(KeyCode.P))		{myState = States.cell;}
	}
	#endregion state handler methods
}
