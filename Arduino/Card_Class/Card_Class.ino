// Card Class
class Card {
   // Private variables that can only be accessed within the class
   // Place private variables here.
      int suit, value;
  // Everything after "public" can be accesed outside of the class (i.e in "setup" or "loop")
  // Put a constructor here: What information is needed?
    // Create a function that returns area (use 3.14 for pi)
    // Create a function that allows the user to update the values
  public:
        Card (int, int);
        int a() {return suit, value ;}
};

// Definitions of functions declared above
Card::Card (int x, int y) {
   suit = x;
   value = y;
}

void setup() {
  // Instantiates the Circle class
  Card b (1,2);
  // Can only print after serial.begin()
  int a = b.a ();
  Serial.begin(9600);
  if (a) == 1;
    return ("H");
  if (a) == 2;
    return ("C");
  if (a) == 3;
    return ("S");
  if (a) == 4;
    return ("D");
  Serial.println (a);

  
  // Calls the area() function within the class

  // Prints area

  // Updates values

  // Prints new areas
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
