//setup the display settings
void display_setup(){
  delay(100);  // This delay is needed to let the display to initialize
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Initialize display with the I2C address of 0x3C
  display.clearDisplay();  // Clear the buffer
  display.setTextColor(WHITE);  // Set color of the text
  display.setRotation(0);  // Set orientation. Goes from 0, 1, 2 or 3
  display.setTextWrap(false);  
  display.dim(0);  //Set brightness (0 is maximun and 1 is a little dim)
  }

//sample name printing
void printing_name(){
  display.clearDisplay();
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(2.9);  // Set text size. We are using a custom font so you should always use the text size of 0
  display.setCursor(10, 35);  // (x,y)
  display.println("KINAD");
  display.display();
  display.clearDisplay();
  }

//sample line follow constant printing
void printing_line_follow_data(){
  display.clearDisplay();
  display.setFont(&FreeMono9pt7b);
  display.setTextSize(0);  // Set text size. We are using a custom font so you should always use the text size of 0

  // Print LINE FOLLOW DATA:
  display.setCursor(0, 10);  // (x,y)
  display.println("LINE FOLLOW");
  

  display.setCursor(0, 25);  // (x,y)
  display.println("BASE PWM");
  display.setCursor(90, 25);  // (x,y)
  display.println("200");

  display.setCursor(0, 40);  // (x,y)
  display.println("Kp");  
  display.setCursor(90, 40);  // (x,y)
  display.println("10");  
  
  display.setCursor(0, 55);  // (x,y)
  display.println("Kd");  
  display.setCursor(90, 55);  // (x,y)
  display.println("20");  
  
  display.display();
  delay(1500);
  display.clearDisplay();
}

//sample wall follow data printing
void printing_wall_follow_data(){
  // Print WALL FOLLOW DATA:
  display.setCursor(0, 10);  // (x,y)
  display.println("WALL FOLLOW");

  display.setCursor(0, 25);  // (x,y)
  display.println("BASE PWM");
  display.setCursor(90, 25);  // (x,y)
  display.println("200");

  display.setCursor(0, 40);  // (x,y)
  display.println("Kp");
  display.setCursor(90, 40);  // (x,y)
  display.println("20");

  display.setCursor(0, 55);  // (x,y)
  display.println("Kd");
  display.setCursor(90, 55);  // (x,y)
  display.println("40");

  display.display();
  delay(1500);
  display.clearDisplay();
  }
