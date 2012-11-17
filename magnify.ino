/*
 * magnify.ino
 *
 * Two button interface to send commands for zooming in/out on a mac
 */
const int rightButton = 10;
const int leftButton = 11;

void setup() {
	Serial.begin(9600);
	pinMode(rightButton, INPUT_PULLUP);
	pinMode(leftButton, INPUT_PULLUP);
	delay(4000);
}//end setup

void loop() {
	if (digitalRead(rightButton) == HIGH) {
		delay(10);
	} else {
		// Zoom in with ALT + Command + =
		Keyboard.set_modifier( MODIFIERKEY_ALT | MODIFIERKEY_GUI );
		Keyboard.set_key1( KEY_EQUAL );
		Keyboard.send_now();

		// immediately send a cancel key so it doesn't think the button
		// is still pressed
		Keyboard.set_modifier(0);
		Keyboard.set_key1(0);
		Keyboard.send_now();
		delay(100);
	}//end else

	if (digitalRead(leftButton) == HIGH) {
		delay(10);
	} else {
		// Zoom out with ALT + Command + -
		Keyboard.set_modifier( MODIFIERKEY_ALT | MODIFIERKEY_GUI );
		Keyboard.set_key1( KEY_MINUS );
		Keyboard.send_now();

		// immediately send a cancel key so it doesn't think the button
		// is still pressed
		Keyboard.set_modifier(0);
		Keyboard.set_key1(0);
		Keyboard.send_now();
		delay(100);
	}//end else

	delay(10);
}//end loop
